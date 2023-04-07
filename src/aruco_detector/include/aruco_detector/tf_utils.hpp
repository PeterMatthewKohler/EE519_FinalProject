#include <Eigen/Dense>

// Takes in an angle theta(radians) and returns a full 3x3 rotation matrix revolved
// around the Z axis
Eigen::Matrix3f rotZ(float theta);
// Takes in an angle theta(radians) and returns a full 3x3 rotation matrix revolved
// around the Y axis
Eigen::Matrix3f rotY(float theta);
// Takes in an angle theta(radians) and returns a full 3x3 rotation matrix revolved
// around the X axis
Eigen::Matrix3F rotX(float theta);

/* Returns a rotation matrix corresponding to a roll,
* pitch, and yaw encoded rotation
*
* R = 3x3 rotation matrix output
* roll = input angle (rad)
* pitch = input angle (rad)
* yaw = input angle (rad) */
Eigen::Matrix3f rpy2Rot(float roll, float pitch, float yaw);
