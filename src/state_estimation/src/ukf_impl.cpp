// ----------------------------------------------
/// @file   ukf_impl.cpp
/// @author Peter (peter_kohler@gmail.com)
/// @brief  Node to perform state estimation of the robot 
/// using an Unscented Kalman Filter
///
// -----------------------------------------------

#include "state_estimation/ukf_node_impl.hpp"

namespace state_estimation  // this should match the project name in CMakeLists
{
    UKFNode::UKFNode() : Node("UKFNode") {
        UKFNode::initialize();
        UKFNode::CreateSubscribers();
        UKFNode::CreatePublishers();
        timer_ = this->create_wall_timer(
            std::chrono::milliseconds(Ts_msec),
            std::bind(&UKFNode::unscentedKalmanFilter, this));
    }

    void UKFNode::CreateSubscribers()
    {
        sigmaIDSub_ = this->create_subscription<fp_msgs::msg::SigmaID>(
            "/SigmaID",
            10,
            std::bind(&UKFNode::SigmaIDCallback,
            this,
            std::placeholders::_1));

        jointStatesSub_ = this->create_subscription<sensor_msgs::msg::JointState>(
            "/joint_states_with_noise",
            10,
            std::bind(&UKFNode::JointStatesSubscriberCallback,
            this,
            std::placeholders::_1));
    }

    void UKFNode::CreatePublishers()
    {
        ukfStatePub_ = this->create_publisher<fp_msgs::msg::PointRPY>("/UKFState", 10);
    }

    void UKFNode::SigmaIDCallback(const fp_msgs::msg::SigmaID::SharedPtr msg)
    {
        sigmaID_.emplace(*msg);
    }

    void UKFNode::JointStatesSubscriberCallback(const sensor_msgs::msg::JointState::SharedPtr msg)
    {
        jointStates_.emplace(*msg);
    }

    void UKFNode::initialize()
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

        // Set initial state based on initialization params for UKF Launch file
        x_k_plus << -2.2, -0.55, 0.0; //Actual starting state: -2.0, -0.5, 0;
        
        for (int i = 0; i < 3; i++){
            Eigen::Matrix<float, 3, 1> temp = Eigen::MatrixXf::Zero(3,1);
            temp(i,0) = 1;
            e_vect.push_back(temp);
        }

        // Set initial state covariance matrix                           
        P_k_plus.setIdentity();
        P_k_plus *= 1e-1;
        // Set noise matrix Q based on params joint encoder sensors
        Q <<    0.001,    0,  0,    // 0.07
                0,  0.001,   0,
                0,  0,  2.178E-5; // 2.178E-5

        R = 0.05; // 0.1(?) giving very solid values in tests
    }

    void UKFNode::unscentedKalmanFilter()
    {
        // Only start running once we have gotten a set of input values
        if (jointStates_) {
            // Run a lock so our input and observation data can't be overwritten mid function call
            std::scoped_lock lock(m);   // Lock is removed as soon as the function execution is done

            // ---------------- Time Update (entering with x_k_plus and P_k_plus)
            // Perform the Cholsky decomposition
            Eigen::Matrix<float, 3, 3> M = P_k_plus.llt().matrixL();
            
            // Create the samples
            // Vector of sampling points
            std::vector<Eigen::Matrix<float, 3, 1>> x_samples;  // denoted x_(k+1)^i in the lecture notes
            x_k_minus.setZero(3,1);

            for (int i = 0; i < 6; i++){
                Eigen::Matrix<float, 3, 1> x_tilde;
                if (i <= 2){x_tilde = sqrt(3)*M*e_vect[i];}
                else {x_tilde = -sqrt(3)*M*e_vect[i-3];}
                Eigen::Matrix<float, 3, 1> x_i = x_k_plus + x_tilde;
                x_samples.push_back(x_k_plus + input_fx(x_i, *jointStates_)*Ts_sec);    // Euler Approximation
                // Perform the summation part in the same loop for efficiency
                x_k_minus += x_samples[i];
            }
            x_k_minus *= (1.0/6.0);     // x_(k+1)^(-) final value at this point

            // Calculate P_(k+1)^(-)
            P_k_minus.setZero(3,3);
            for (int i = 0; i < 6; i++){
                Eigen::Matrix<float, 3, 1> x_diff = x_samples[i] - x_k_minus;
                P_k_minus += x_diff*x_diff.transpose() + Q;
            }
            P_k_minus *= (1.0/6.0);

            // Wrap yaw angle to [-pi, pi]
            if (x_k_minus(2,0) > M_PI || x_k_minus(2,0) < M_PI){x_k_minus(2,0) = atan2(sin(x_k_minus(2,0)),cos(x_k_minus(2,0)));}
            // ---------------- Time Update End
            // ---------------- Measurement Update
            x_samples.clear();
            std::vector<float> y_i;
            float y_bar;
            if (!sigmaID_) {  // If we don't have an output measurement then we just set the estimated states and covariance to values calculated via our time update
                x_k_plus = x_k_minus;
                P_k_plus = P_k_minus;
            }
            else {
                Eigen::MatrixXf aruco_tf = tf_orig2AR[sigmaID_->id];
                // Cholsky factorization of new covariance P_k_minus
                M = P_k_minus.llt().matrixL();
                for (int i = 0; i < 6; i++){
                    Eigen::Matrix<float, 3, 1> x_tilde;
                    if (i <= 2){x_tilde = sqrt(3)*M*e_vect[i];}
                    else {x_tilde = -sqrt(3)*M*e_vect[i-3];}
                    Eigen::Matrix<float, 3, 1> x_i = x_k_minus + x_tilde;
                    x_samples.push_back(x_i);
                    y_i.push_back(output_gx(x_i, aruco_tf));
                    y_bar += y_i[i];
                }
                y_bar *= (1.0/6.0);
                // Calculate Pxy and Py
                Eigen::Matrix<float, 3, 1> Pxy = Eigen::MatrixXf::Zero(3,1);
                float Py;
                for (int i = 0; i < 6; i++){
                    float y_diff = y_i[i] - y_bar;
                    Eigen::Matrix<float, 3, 1> x_diff = x_samples[i] - x_k_minus;
                    Pxy += x_diff*y_diff;
                    Py += y_diff*y_diff + R;
                }
                Pxy *= (1.0/6.0);
                Py *= (1.0/6.0);
                // Obtain actual measurement
                Eigen::Matrix<float, 3, 1> K = Pxy*pow(Py,-1);
                x_k_plus = x_k_minus + K*(sigmaID_->sigma - y_bar);
                P_k_plus = P_k_minus - K*Pxy.transpose();
            }
            // reset the observation object
            sigmaID_.reset();

            // Publish our estimated state
            fp_msgs::msg::PointRPY state;
            state.position.x = x_k_plus(0,0);
            state.position.y = x_k_plus(1,0);
            state.yaw = x_k_plus(2,0);
            ukfStatePub_->publish(state);
        }
    }

    Eigen::Matrix<float, 3, 1> UKFNode::input_fx(Eigen::Matrix<float, 3, 1> x_k_plus, sensor_msgs::msg::JointState jointStates)
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

    float UKFNode::output_gx(Eigen::Matrix<float, 3, 1> x_k_minus, Eigen::MatrixXf aruco_loc)
    {
        return atan2( (x_k_minus(1,0) - aruco_loc(1,3)), (x_k_minus(0,0) - aruco_loc(0,3)) );
    }

}