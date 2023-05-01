// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from fp_msgs:msg/SigmaID.idl
// generated code does not contain a copyright notice

#ifndef FP_MSGS__MSG__DETAIL__SIGMA_ID__TRAITS_HPP_
#define FP_MSGS__MSG__DETAIL__SIGMA_ID__TRAITS_HPP_

#include "fp_msgs/msg/detail/sigma_id__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<fp_msgs::msg::SigmaID>()
{
  return "fp_msgs::msg::SigmaID";
}

template<>
inline const char * name<fp_msgs::msg::SigmaID>()
{
  return "fp_msgs/msg/SigmaID";
}

template<>
struct has_fixed_size<fp_msgs::msg::SigmaID>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<fp_msgs::msg::SigmaID>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<fp_msgs::msg::SigmaID>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // FP_MSGS__MSG__DETAIL__SIGMA_ID__TRAITS_HPP_
