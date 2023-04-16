#include "arucoDetector.hpp"

class ArucoDetector : public rclcpp::Node {
private:
    const std::string OPENCV_WINDOW = "Image window";
    image_transport::Subscriber sub_;
    image_transport::Publisher pub_;
    rclcpp::Subscription<sensor_msgs::msg::CameraInfo>::SharedPtr camera_info_sub_;
    rclcpp::Publisher<fp_msgs::msg::SigmaID>::SharedPtr sigmaPub_;

    void imageCallback(const sensor_msgs::msg::Image::ConstSharedPtr &msg) {
        cv_bridge::CvImagePtr cv_ptr;
        try
        {
            cv_ptr = cv_bridge::toCvCopy(msg, msg->encoding);
        }
        catch (cv_bridge::Exception& e)
        {
            RCLCPP_ERROR(this->get_logger(), "cv_bridge exception: %s", e.what());
            return;
        }
        if (cameraInfoMsg_) {   // only run after we have the camera params from the camera_info topic
            // Attempt to detect aruco markers in image
            std::vector<int> markerIds;
            std::vector<std::vector<cv::Point2f>> markerCorners, rejectedCandidates;
            cv::Ptr<cv::aruco::DetectorParameters> parameters = cv::aruco::DetectorParameters::create();
            cv::aruco::detectMarkers(cv_ptr->image, dictionary, markerCorners, markerIds, parameters, rejectedCandidates);
            cv::Mat outputImage = cv_ptr->image.clone();

            if (markerIds.size() > 0) {
                std::vector<cv::Vec3d> rvecs, tvecs;

                cv::aruco::estimatePoseSingleMarkers(markerCorners, 0.25, cameraMatrix, distortionCoeffs, rvecs, tvecs);
                cv::aruco::drawDetectedMarkers(outputImage, markerCorners, markerIds);
                for (long unsigned int i = 0; i < rvecs.size(); ++i) {
                    auto rvec = rvecs[i];
                    auto tvec = tvecs[i];

                    cv::drawFrameAxes(outputImage, cameraMatrix, distortionCoeffs, rvec, tvec, 0.125);

                    if (markerIds[0] < 6 && markerIds[0] >= 0) {
                        cv::Mat rotMat(3, 3, CV_64F);
                        cv::Rodrigues(rvec, rotMat);
                        // Generate the Transformation matrix in Eigen
                        Eigen::MatrixXd rotMatEigen(3,3);
                        Eigen::MatrixXd translEigen(3,1);
                        cv::cv2eigen(rotMat, rotMatEigen);
                        cv::cv2eigen(tvec, translEigen);
                        Eigen::MatrixXd tf_camOptical2ARFrame(4,4);
                        tf_camOptical2ARFrame.setIdentity();    // Sets the bottom row to 0 0 0 1!
                        tf_camOptical2ARFrame.block<3,3>(0,0) = rotMatEigen;
                        tf_camOptical2ARFrame.block<3,1>(0,3) = translEigen;
                        tf_world2BaseFootprint = tf_orig2AR[markerIds[0]] * tf_camOptical2ARFrame.inverse() * tf_camOptical2BaseFootprint;
                        std::cout << "camOptical2ARFrame: \n" << tf_camOptical2ARFrame << "\n\n";
                        // Convert to RPY
                        //auto temp = tf_world2BaseFootprint.block<3,3>(0,0);
                        //Eigen::Matrix3f tfROT = temp.cast<float>();    // Cast to float
                        //Eigen::Vector3f rpy = tf_utils::rot2EulerZYX(tfROT);

                        // Publish observation (sigma value and ID seen)
                        // Only publish if robot is within 2.5 meters of aruco marker (seeing instability in sigma calculation at long distances)
                        if (sqrt( pow(tf_camOptical2ARFrame(0,3),2) + pow(tf_camOptical2ARFrame(1,3),2) + pow(tf_camOptical2ARFrame(2,3),2)) <= 2) {
                            fp_msgs::msg::SigmaID sigmaID;
                            sigmaID.sigma = atan2(  (tf_world2BaseFootprint(1,3) - tf_orig2AR[markerIds[0]](1,3)),     // Robot Y Coordinate - Aruco Marker Y Coordinate 
                                                    (tf_world2BaseFootprint(0,3) - tf_orig2AR[markerIds[0]](0,3)));    // Robot X Coordinate - Aruco Marker X Coordinate
                            sigmaID.id = markerIds[0];
                            sigmaPub_->publish(sigmaID);
                        }
                    }
                }
            }
            //cv::imshow(OPENCV_WINDOW, outputImage);
            //cv::waitKey(3);
            pub_.publish(cv_ptr->toImageMsg());
        }
    }

    void cameraInfoCallback(const sensor_msgs::msg::CameraInfo::SharedPtr msg) {
        if (!cameraInfoMsg_) {
            cameraInfoMsg_.emplace(*msg);
            cameraMatrix = (cv::Mat1d(3,3) <<   cameraInfoMsg_->k[0], 0, cameraInfoMsg_->k[2],
                                                0, cameraInfoMsg_->k[4], cameraInfoMsg_->k[5],
                                                0, 0, 1);
            distortionCoeffs = (cv::Mat1d(1,5) <<   cameraInfoMsg_->d[0],
                                                    cameraInfoMsg_->d[1],
                                                    cameraInfoMsg_->d[2],
                                                    cameraInfoMsg_->d[3],
                                                    cameraInfoMsg_->d[4]);
        }
    }

    void initialize() {
        Eigen::MatrixXd temp(4,4);
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

        tf_camOptical2CamRGB << 0, -1, 0, 0,
                                0, 0, -1, 0,
                                1, 0, 0, 0,
                                0, 0, 0, 1;

        tf_camRBG2CamLink <<    1, 0, 0, -0.005,
                                0, 1, 0, -0.018,
                                0, 0, 1, -0.013,
                                0, 0, 0, 1;
        
        tf_camLink2BaseLink <<  1, 0, 0, -0.064,
                                0, 1, 0, 0.065,
                                0, 0, 1, -0.094,
                                0, 0, 0, 1;

        tf_baseLink2BaseFootprint <<    1, 0, 0, 0,
                                        0, 1, 0, 0,
                                        0, 0, 1, -0.01,
                                        0, 0, 0, 1;

        tf_camOptical2BaseFootprint = tf_camOptical2CamRGB * tf_camRBG2CamLink * tf_camLink2BaseLink * tf_baseLink2BaseFootprint;
    }

public:
    ArucoDetector() : Node("aruco_detector") {
        ArucoDetector::initialize();
        // Open demo window that will show output image
        //cv::namedWindow(OPENCV_WINDOW);

        rmw_qos_profile_t custom_qos = rmw_qos_profile_default;
        pub_ = image_transport::create_publisher(this, "/camera/out_image", custom_qos);
        sub_ = image_transport::create_subscription(this, "/camera/image_raw",
                std::bind(&ArucoDetector::imageCallback, this, std::placeholders::_1), "raw", custom_qos);
        camera_info_sub_ = this->create_subscription<sensor_msgs::msg::CameraInfo>(
                                    "/camera/camera_info", 10, 
                                    std::bind(&ArucoDetector::cameraInfoCallback, 
                                    this, 
                                    std::placeholders::_1));

        sigmaPub_ = this->create_publisher<fp_msgs::msg::SigmaID>("/SigmaID", 10);

    }

    ~ArucoDetector()
    {
        cv::destroyWindow(OPENCV_WINDOW);
    }
};

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ArucoDetector>());
    rclcpp::shutdown();
    return 0;
}