// ----------------------------------------------
/// @file   ekf_main.cpp
/// @author Peter (peter_kohler@gmail.com)
/// @brief  Node to perform state estimation of the robot 
/// using an Extended Kalman Filter
///
// -----------------------------------------------

#include "state_estimation/ekf_node_impl.hpp"

namespace state_estimation  // this should match the project name in CMakeLists
{
    EKFNode::EKFNode() : Node("EKFNode") {
        EKFNode::initialize();
        EKFNode::CreateSubscribers();
        EKFNode::CreatePublishers();
        timer_ = this->create_wall_timer(
            std::chrono::milliseconds(Ts_msec),
            std::bind(&EKFNode::extendedKalmanFilter, this));
    }

    void EKFNode::CreateSubscribers()
    {
        sigmaIDSub_ = this->create_subscription<fp_msgs::msg::SigmaID>(
            "/SigmaID",
            10,
            std::bind(&EKFNode::SigmaIDCallback,
            this,
            std::placeholders::_1));

        jointStatesSub_ = this->create_subscription<sensor_msgs::msg::JointState>(
            "/joint_states_with_noise",
            10,
            std::bind(&EKFNode::JointStatesSubscriberCallback,
            this,
            std::placeholders::_1));
    }

    void EKFNode::CreatePublishers()
    {
        ekfStatePub_ = this->create_publisher<fp_msgs::msg::PointRPY>("/EKFState", 10);
    }

    void EKFNode::SigmaIDCallback(const fp_msgs::msg::SigmaID::SharedPtr msg)
    {
        sigmaID_.emplace(*msg);
        //RCLCPP_INFO(this->get_logger(), "Message received:\nsigma: %f, ID: %i", sigmaID_->sigma, sigmaID_->id);
    }

    void EKFNode::JointStatesSubscriberCallback(const sensor_msgs::msg::JointState::SharedPtr msg)
    {
        jointStates_.emplace(*msg);
    }

    void EKFNode::initialize()
    {
        Eigen::MatrixXf temp(4,4);
        // Origin to Aruco_0
        temp <<      1.0000,    0.0008,   -0.0008,  0,
                    -0.0008,   -0.0000,   -1.0000,  2.5350,
                    -0.0008,    1.0000,   0.0000,   0.250,
                    0,          0,          0,      1;
        tf_orig2AR.push_back(temp);
        // Origin to Aruco_1
        temp <<              0.5009,    0.0000,   -0.8655,  2.2250,
                            -0.8655,   -0.0000,   -0.5009,  1.2000,
                            -0.0000,    1.0000,    0.0000,  0.2500,
                            0,          0,         0,       1;
        tf_orig2AR.push_back(temp);
        // Origin to Aruco_2
        temp <<         -0.4949,   -0.0004,   -0.8689, 2.2,
                        -0.8689,    0.0007,    0.4949, -1.25,
                        0.0004,    1.0000,   -0.0007,  0.25,
                        0,          0,          0,      1;
        tf_orig2AR.push_back(temp);
        // Origin to Aruco_3
        temp <<     -1.0000,    0.0008,   -0.0008,  0,
                    -0.0008,    0.0000,    1.0000,  -2.53500,
                    0.0008,    1.0000,    0.0000,   0.25,
                    0,          0,          0,      1;
        tf_orig2AR.push_back(temp);
        // Origin to Aruco_4
        temp <<         -0.5155,   -0.0007,    0.8569,  -2.3500,
                        0.8569,   -0.0004,    0.5155,   -1,
                        0.0000,    1.0000,    0.0008,   0.25,
                        0,          0,          0,      1;
        tf_orig2AR.push_back(temp);
        // Origin to Aruco_5
        temp <<         0.5048,     0.0000,    0.8632,  -2.3500,
                        0.8632,     0.0000,   -0.5048,  1.0000,
                        -0.0000,    1.0000,    0.0000,  0.2500,
                        0,          0,         0,       1;
        tf_orig2AR.push_back(temp);

        // Set initial state based on initialization params for EKF Launch file
        x_k_plus << -2.0, -0.5, 0;
        // Set initial state covariance matrix                           
        P_k_plus.setIdentity();
        P_k_plus *= 1e-1;
        // Set noise matrix Q based on params joint encoder sensors
        Q <<    pow(0.01,2),    0,  0,
                0,  pow(0.01, 2),   0,
                0,  0,  pow(0.01, 2);

        R = 0.285; // 0.285 giving very solid values in testing
    }

    void EKFNode::extendedKalmanFilter()
    {
        // Only start running once we have gotten a set of input values
        if (jointStates_) {
            // Run a lock so our input and observation data can't be overwritten mid function call
            std::scoped_lock lock(m);   // Lock is removed as soon as the function execution is done
            
            // Time Update (entering with x_k_plus and P_k_plus)
            Eigen::Matrix<float, 3, 3> Phi_k = Eigen::MatrixXf::Identity(3,3) + input_fx_gradient(x_k_plus, *jointStates_)*Ts_sec;

            x_k_minus = x_k_plus + input_fx(x_k_plus, *jointStates_)*Ts_sec;
            // Wrap yaw angle to [-pi, pi]
            if (x_k_minus(2,0) > M_PI || x_k_minus(2,0) < M_PI){x_k_minus(2,0) = atan2(sin(x_k_minus(2,0)),cos(x_k_minus(2,0)));}

            P_k_minus = Phi_k*P_k_plus*Phi_k.transpose() + Q;

            // Measurement Update
            if (!sigmaID_) {  // If we don't have an output measurement then we just set the estimated states and covariance to values calculated via dead reckoning
                x_k_plus = x_k_minus;
                P_k_plus = P_k_minus;
            }
            else {
                Eigen::MatrixXf aruco_tf = tf_orig2AR[sigmaID_->id];
                Eigen::Matrix<float, 1, 3> C_k = output_gx_gradient(x_k_minus, aruco_tf);
                K = P_k_minus*C_k.transpose()*(1 / (C_k*P_k_minus*C_k.transpose() + R));
                x_k_plus = x_k_minus + K*(sigmaID_->sigma - output_gx(x_k_minus, aruco_tf));
                P_k_plus = (Eigen::MatrixXf::Identity(3,3) - K*C_k)*P_k_minus;
            }
            // reset the observation object
            sigmaID_.reset();

            // Publish our estimated state
            fp_msgs::msg::PointRPY state;
            state.position.x = x_k_plus(0,0);
            state.position.y = x_k_plus(1,0);
            state.yaw = x_k_plus(2,0);
            ekfStatePub_->publish(state);
        }
    }

    Eigen::Matrix<float, 3, 1> EKFNode::input_fx(Eigen::Matrix<float, 3, 1> x_k_plus, sensor_msgs::msg::JointState jointStates)
    {
        float vl = jointStates.velocity[0]*0.033;   // Wheel radius is 33mm
        float vr = jointStates.velocity[1]*0.033;
        // We are using the approximation x_(k+1) = x_k + f_c(x_k, u_k)*Ts
        Eigen::Matrix<float, 3, 1> output;
        // x
        output(0,0) = (cos(x_k_plus(2,0))*(vl + vr)/2);
        // y
        output(1,0) = (sin(x_k_plus(2,0))*(vl + vr)/2);
        // Yaw
        output(2,0) = (vr - vl)/b;

        return output;
    }

    Eigen::Matrix<float, 3, 3> EKFNode::input_fx_gradient(Eigen::Matrix<float, 3, 1> x_k_plus, sensor_msgs::msg::JointState jointStates)
    {
        float vl = jointStates.velocity[0]*0.033;   // Wheel radius is 33mm
        float vr = jointStates.velocity[1]*0.033;
        // We are using the approximation gradient of f_x = I + grad_f_x_continuous*Ts
        Eigen::Matrix<float, 3, 3> output = Eigen::MatrixXf::Zero(3,3);
        output(0,2) = (-sin(x_k_plus(2,0))*(vl + vr)/2);
        output(1,2) = (cos(x_k_plus(2,0))*(vl + vr)/2);

        return output;
    }

    float EKFNode::output_gx(Eigen::Matrix<float, 3, 1> x_k_minus, Eigen::MatrixXf aruco_loc)
    {
        return atan2( (x_k_minus(1,0) - aruco_loc(1,3)), (x_k_minus(0,0) - aruco_loc(0,3)) );
    }

    Eigen::Matrix<float, 1, 3> EKFNode::output_gx_gradient(Eigen::Matrix<float, 3, 1> x_k_plus, Eigen::MatrixXf aruco_loc)
    {
        Eigen::Matrix<float, 1, 3> output = Eigen::MatrixXf::Zero(1,3);
        output(0,0) = (aruco_loc(1,3) - x_k_plus(1,0)) / ( pow((x_k_plus(0,0) - aruco_loc(0,3)),2) + pow((x_k_plus(1,0) - aruco_loc(1,3)),2) );
        output(0,1) = (x_k_plus(0,0) - aruco_loc(0,3)) / ( pow((x_k_plus(0,0) - aruco_loc(0,3)),2) + pow((x_k_plus(1,0) - aruco_loc(1,3)),2) );

        return output;
    }

}