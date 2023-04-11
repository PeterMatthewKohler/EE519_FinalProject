#include "tf_utils.hpp"
#include <iostream>

Eigen::Matrix3f tf_utils::rotZ(float theta) {
    Eigen::Matrix3f rot;
    rot <<  cos(theta), -sin(theta),    0,
            sin(theta), cos(theta),     0,
            0,          0,              1;
    return rot;
}

Eigen::Matrix3f tf_utils::rotY(float theta) {
    Eigen::Matrix3f rot;
    rot <<  cos(theta),     0,              sin(theta),
            0,              1,              0,
            -sin(theta),    0,              cos(theta);
    return rot;    
}

Eigen::Matrix3f tf_utils::rotX(float theta) {
    Eigen::Matrix3f rot;
    rot <<  1,  0,          0,
            0,  cos(theta), -sin(theta),
            0,  sin(theta), cos(theta);
    return rot;
}

Eigen::Matrix3f tf_utils::rpy2Rot(float roll, float pitch, float yaw) {
    return rotZ(yaw)*rotY(pitch)*rotX(roll);
}

Eigen::Vector3f tf_utils::rot2EulerZYX(Eigen::Matrix3f Rotm) {
    // Positive square root seems to report the correct calculation 100%(?) of the time
    float roll, pitch, yaw;   // positive square root

    pitch = atan2(-Rotm(2,0), sqrt(pow(Rotm(2,1),2) + pow(Rotm(2,2),2)));
    if ((abs(pitch - (M_PI/2)) < 0.001 && pitch > 0) || (abs(pitch + (M_PI/2)) < 0.001 && pitch < 0)) {
        //if pitch = pi/2, we calculate sum of roll and yaw. We consider yaw = 0
        //and calculate value of roll for this singularity.
        yaw = 0;
        if (pitch > 0) {
            roll = atan2(Rotm(0,1), Rotm(1,1));
        }
        else {
            roll = -atan2(Rotm(0,1), Rotm(1,1));
        }
    }
    else {
        roll = atan2( (Rotm(2,1)/cos(pitch)), (Rotm(2,2)/cos(pitch)));
        yaw = atan2( (Rotm(1,0)/cos(pitch)), (Rotm(0,0)/cos(pitch)));
    }
    Eigen::Vector3f output;
    output << roll, pitch, yaw;
    return output;
}
