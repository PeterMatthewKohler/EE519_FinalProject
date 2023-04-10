#include "tf_utils.hpp"

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
    float roll_p, pitch_p, yaw_p;   // positive square root
    float roll_n, pitch_n, yaw_n;   // negative square root
    // Check for singularity when pitch = PI/2
    pitch_p = atan2(-Rotm(6), sqrt(pow(Rotm(0),2) + pow(Rotm(3),2)));
    pitch_n = atan2(-Rotm(6), sqrt(pow(Rotm(0),2) + pow(Rotm(3),2)));

    if ((abs(pitch_p - (M_PI/2)) < 0.001 && pitch_p > 0) || (abs(pitch_p + (M_PI/2)) < 0.001 && pitch_p < 0)) {
        pitch_n = pitch_p;
        //if pitch = pi/2, we calculate sum of roll and yaw. We consider yaw = 0
        //and calculate value of roll for this singularity.
        yaw_p = 0;
        yaw_n = 0;
        if (pitch_p > 0) {
            roll_p = atan2(Rotm(0,1), Rotm(1,1));
            roll_n = roll_p;
        }
        else {
            roll_p = -atan2(Rotm(0,1), Rotm(1,1));
            roll_n = roll_p;
        }
    }
    else {
        roll_p = atan2( (Rotm(2,1)/cos(pitch_p)), (Rotm(2,2)/cos(pitch_p)));
        yaw_p = atan2( (Rotm(1,0)/cos(pitch_p)), (Rotm(0,0)/cos(pitch_p)));

        roll_n = atan2( (Rotm(2,1)/cos(pitch_n)), (Rotm(2,2)/cos(pitch_n)));
        yaw_n = atan2( (Rotm(1,0)/cos(pitch_n)), (Rotm(0,0)/cos(pitch_n)));
    }
    float roll, pitch, yaw;
    // Pick the one whose roll is closer to 0 (IDK HOW TO PICK BETWEEN THE TWO OTHERWISE)
    if (abs(roll_p) > abs(roll_n)) {
        roll = roll_n;
        pitch = pitch_n;
        yaw = yaw_n;
    }
    else{
        roll = roll_p;
        pitch = pitch_p;
        yaw = yaw_p;
    }
    Eigen::Vector3f output;
    output << roll, pitch, yaw;
    return output;

}
