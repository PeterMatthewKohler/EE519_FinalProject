// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from fp_msgs:msg/PointRPY.idl
// generated code does not contain a copyright notice

#ifndef FP_MSGS__MSG__DETAIL__POINT_RPY__STRUCT_H_
#define FP_MSGS__MSG__DETAIL__POINT_RPY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'position'
#include "geometry_msgs/msg/detail/point__struct.h"

// Struct defined in msg/PointRPY in the package fp_msgs.
typedef struct fp_msgs__msg__PointRPY
{
  geometry_msgs__msg__Point position;
  double roll;
  double pitch;
  double yaw;
} fp_msgs__msg__PointRPY;

// Struct for a sequence of fp_msgs__msg__PointRPY.
typedef struct fp_msgs__msg__PointRPY__Sequence
{
  fp_msgs__msg__PointRPY * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} fp_msgs__msg__PointRPY__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FP_MSGS__MSG__DETAIL__POINT_RPY__STRUCT_H_
