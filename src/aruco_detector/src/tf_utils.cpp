#include "tf_utils.hpp"

Eigen::Matrix3f rotZ(float theta) {
    Eigen::Matrix3f rot;
    rot <<  cos(theta), -sin(theta),    0,
            sin(theta), cos(theta),     0,
            0,          0,              1;
    return rot;
}

Eigen::Matrix3f rotY(float theta) {
    Eigen::Matrix3f rot;
    rot <<  cos(theta),     0,              sin(theta),
            0,              1,              0,
            -sin(theta),    0,              cos(theta);
    return rot;    
}

Eigen::Matrix3f rotZ(float theta) {
    Eigen::Matrix3f rot;
    rot <<  1,  0,          0,
            0,  cos(theta), -sin(theta),
            0,  sin(theta), cos(theta);
    return rot;
}

Eigen::Matrix3f rpy2Rot(float roll, float pitch, float yaw) {
    return rotZ(yaw)*rotY(pitch)*rotX(roll);
}