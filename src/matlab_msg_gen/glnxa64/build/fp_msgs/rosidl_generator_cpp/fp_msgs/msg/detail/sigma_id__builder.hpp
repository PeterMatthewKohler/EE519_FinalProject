// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from fp_msgs:msg/SigmaID.idl
// generated code does not contain a copyright notice

#ifndef FP_MSGS__MSG__DETAIL__SIGMA_ID__BUILDER_HPP_
#define FP_MSGS__MSG__DETAIL__SIGMA_ID__BUILDER_HPP_

#include "fp_msgs/msg/detail/sigma_id__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace fp_msgs
{

namespace msg
{

namespace builder
{

class Init_SigmaID_id
{
public:
  explicit Init_SigmaID_id(::fp_msgs::msg::SigmaID & msg)
  : msg_(msg)
  {}
  ::fp_msgs::msg::SigmaID id(::fp_msgs::msg::SigmaID::_id_type arg)
  {
    msg_.id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fp_msgs::msg::SigmaID msg_;
};

class Init_SigmaID_sigma
{
public:
  Init_SigmaID_sigma()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SigmaID_id sigma(::fp_msgs::msg::SigmaID::_sigma_type arg)
  {
    msg_.sigma = std::move(arg);
    return Init_SigmaID_id(msg_);
  }

private:
  ::fp_msgs::msg::SigmaID msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::fp_msgs::msg::SigmaID>()
{
  return fp_msgs::msg::builder::Init_SigmaID_sigma();
}

}  // namespace fp_msgs

#endif  // FP_MSGS__MSG__DETAIL__SIGMA_ID__BUILDER_HPP_
