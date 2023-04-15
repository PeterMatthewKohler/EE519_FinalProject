// ----------------------------------------------
/// @file   ekf_node_impl.hpp
/// @author Peter (peter_kohler@gmail.com)
/// @brief  Node to perform state estimation of the robot 
/// using an Extended Kalman Filter
///
// -----------------------------------------------

#pragma once

#include <string>
#include <chrono>
#include <thread>
#include <cmath>
#include "rclcpp/rclcpp.hpp"
#include <eigen3/Eigen/Dense>

#include "fp_msgs/msg/sigma_id.hpp"
#include "fp_msgs/msg/point_rpy.hpp"
#include "sensor_msgs/msg/joint_state.hpp"

namespace state_estimation
{

class EKFNode : public rclcpp::Node{
public:
    //! @brief Constructor for the EKFNode
    EKFNode(); 

private:
    // ================================
    // ------------- ROS --------------
    // ================================

    //! @brief The subscriber to the /SigmaID topic
    rclcpp::Subscription<fp_msgs::msg::SigmaID>::SharedPtr sigmaIDSub_;

    //! @brief The subscriber to the Joint Encoder topic
    rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr jointStatesSub_;

    //! @brief The publisher that publishes the estimated state from the EKF
    rclcpp::Publisher<fp_msgs::msg::PointRPY>::SharedPtr ekfStatePub_;

    //! @brief Timer for Executing EKF time and measurement update periodically
    rclcpp::TimerBase::SharedPtr timer_;

    // ================================
    // ---------- Functions -----------
    // ================================

    //! @brief Utility function for declaring all subscribers this node has
    void CreateSubscribers();

    //! @brief Utility function for declaring all publishers this node has
    void CreatePublishers();

    //! @brief The callback function for the sigmaID subscriber
    void SigmaIDCallback(const fp_msgs::msg::SigmaID::SharedPtr msg);

    //! @brief The callback function for the joint states with noise subscriber
    /// Contains 1 string (name) and 3 vectors (position, velocity, and effort)
    /// 1st entry in vectors corresponds to left wheel, 2nd is the right wheel
    void JointStatesSubscriberCallback(const sensor_msgs::msg::JointState::SharedPtr msg);

    //! @brief The function run to initalize a bunch of node variables
    void initialize();

    //! @brief The Extended Kalman Filter Function
    /// Performs the time update and measurement update
    void extendedKalmanFilter();

    //! @brief The input function 'f(x_k, u_k)'
    Eigen::Matrix<float, 3, 1> input_fx(Eigen::Matrix<float, 3, 1> x_k_plus, sensor_msgs::msg::JointState jointStates);

    //! @brief The gradient of the input function 'f(x_k, u_k)' 
    Eigen::Matrix<float, 3, 3> input_fx_gradient(Eigen::Matrix<float, 3, 1> x_k_plus, sensor_msgs::msg::JointState jointStates);

    //! @brief The output observation function 'g(x_k)'
    float output_gx(Eigen::Matrix<float, 3, 1> x_k_minus, Eigen::MatrixXf aruco_loc);

    //! @brief The gradient of the output observation function 'g(x_k)'
    Eigen::Matrix<float, 1, 3> output_gx_gradient(Eigen::Matrix<float, 3, 1> x_k_plus, Eigen::MatrixXf aruco_loc);

    // ================================
    // ------------ Data --------------
    // ================================

    //! @brief Timestep of EKF
    int Ts_msec = 50;
    float Ts_sec = Ts_msec*0.001;

    //! @brief Wheel separation of waffle robot (meters)
    float b = 0.287;

    //! @brief  Mutex to protect observation (sigma) and joint_states(vl and vr) from being overwritten
    ///         during kalman filter calculations
    std::mutex m;

    //! @brief  A vector containing all of the transforms from world origin (0,0,0) to each individual aruco marker
    ///         The vector index corresponds to the Marker ID number.
    std::vector<Eigen::MatrixXf> tf_orig2AR;

    //! @brief Object containing most recent observation from aruco_detector node
    std::optional<fp_msgs::msg::SigmaID> sigmaID_;

    //! @brief Object containing the most recent joint encoder data from the simulation
    std::optional<sensor_msgs::msg::JointState> jointStates_;

    //! @brief Objects containing the state estimates and estimated covariances
    Eigen::Matrix<float, 3, 1> x_k_minus;
    Eigen::Matrix<float, 3, 1> x_k_plus;
    Eigen::Matrix<float, 3, 3> P_k_minus;
    Eigen::Matrix<float, 3, 3> P_k_plus;

    //! @brief The Kalman Gain values
    Eigen::Matrix<float, 3, 1> K;

    Eigen::Matrix<float, 3, 3> Q;   // Matrix containing variances of sensors
    float R;                        // Variance of output(sigma) measurement

    const double pi = std::acos(-1);

};
}