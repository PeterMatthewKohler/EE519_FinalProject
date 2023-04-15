// ----------------------------------------------
/// @file   ekf_main.cpp
/// @author Peter (peter_kohler@gmail.com)
/// @brief  Node to perform state estimation of the robot 
/// using an Extended Kalman Filter
///
// -----------------------------------------------

#include <cstdio>
#include "state_estimation/ekf_node_impl.hpp"

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);

    rclcpp::NodeOptions options;
    rclcpp::spin(std::make_shared<state_estimation::EKFNode>());
    rclcpp::shutdown();
}