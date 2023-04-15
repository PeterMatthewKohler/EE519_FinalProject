#include <stdlib.h>
#include <functional>
#include <optional>

#include "rclcpp/rclcpp.hpp"
#include "image_transport/image_transport.hpp"
#include <cv_bridge/cv_bridge.h>
#include "sensor_msgs/image_encodings.hpp"
#include "sensor_msgs/msg/camera_info.hpp"
#include "fp_msgs/msg/sigma_id.hpp"
#include <eigen3/Eigen/Dense>
#include <tf_utils.hpp>

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/aruco.hpp>
#include <opencv2/calib3d.hpp>
#include <opencv2/core/eigen.hpp>


cv::Ptr<cv::aruco::Dictionary> dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_ARUCO_ORIGINAL); // DICT_6X6_250

std::optional<sensor_msgs::msg::CameraInfo> cameraInfoMsg_;
cv::Mat cameraMatrix;
cv::Mat distortionCoeffs;
cv::Mat objectPoints = cv::Mat::ones(4,4, CV_64F);
cv::Mat imagePoints;

std::vector<Eigen::MatrixXd> tf_orig2AR;
Eigen::MatrixXd tf_camRBG2CamLink(4,4);
Eigen::MatrixXd tf_camLink2BaseLink(4,4);
Eigen::MatrixXd tf_camOptical2CamRGB(4,4);
Eigen::MatrixXd tf_baseLink2BaseFootprint(4,4);
Eigen::MatrixXd tf_world2BaseFootprint(4,4);
Eigen::MatrixXd tf_camOptical2BaseFootprint(4,4);
