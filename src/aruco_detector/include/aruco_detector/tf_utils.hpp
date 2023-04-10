#pragma once

#include <eigen3/Eigen/Dense>
#include <math.h>

namespace tf_utils 
{
// Takes in an angle theta(radians) and returns a full 3x3 rotation matrix revolved
// around the Z axis
Eigen::Matrix3f rotZ(float theta);
// Takes in an angle theta(radians) and returns a full 3x3 rotation matrix revolved
// around the Y axis
Eigen::Matrix3f rotY(float theta);
// Takes in an angle theta(radians) and returns a full 3x3 rotation matrix revolved
// around the X axis
Eigen::Matrix3f rotX(float theta);

/* Returns a rotation matrix corresponding to a roll,
* pitch, and yaw encoded rotation
*
* R = 3x3 rotation matrix output
* roll = input angle (rad)
* pitch = input angle (rad)
* yaw = input angle (rad) */
Eigen::Matrix3f rpy2Rot(float roll, float pitch, float yaw);


/* Returns a vector containing the roll, pitch, and yaw 
   values pertaining to the euler ZYX convention (which is 
   identical to the roll pitch yaw (RPY convention)
   Rotm = input 3x3 rotation matrix
   */
Eigen::Vector3f rot2EulerZYX(Eigen::Matrix3f Rotm);
}