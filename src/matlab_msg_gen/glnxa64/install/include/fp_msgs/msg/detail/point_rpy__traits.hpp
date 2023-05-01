// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from fp_msgs:msg/PointRPY.idl
// generated code does not contain a copyright notice

#ifndef FP_MSGS__MSG__DETAIL__POINT_RPY__TRAITS_HPP_
#define FP_MSGS__MSG__DETAIL__POINT_RPY__TRAITS_HPP_

#include "fp_msgs/msg/detail/point_rpy__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'position'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<fp_msgs::msg::PointRPY>()
{
  return "fp_msgs::msg::PointRPY";
}

template<>
inline const char * name<fp_msgs::msg::PointRPY>()
{
  return "fp_msgs/msg/PointRPY";
}

template<>
struct has_fixed_size<fp_msgs::msg::PointRPY>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Point>::value> {};

template<>
struct has_bounded_size<fp_msgs::msg::PointRPY>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Point>::value> {};

template<>
struct is_message<fp_msgs::msg::PointRPY>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // FP_MSGS__MSG__DETAIL__POINT_RPY__TRAITS_HPP_
