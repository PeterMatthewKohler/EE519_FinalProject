// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from fp_msgs:msg/PointRPY.idl
// generated code does not contain a copyright notice

#ifndef FP_MSGS__MSG__DETAIL__POINT_RPY__BUILDER_HPP_
#define FP_MSGS__MSG__DETAIL__POINT_RPY__BUILDER_HPP_

#include "fp_msgs/msg/detail/point_rpy__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace fp_msgs
{

namespace msg
{

namespace builder
{

class Init_PointRPY_yaw
{
public:
  explicit Init_PointRPY_yaw(::fp_msgs::msg::PointRPY & msg)
  : msg_(msg)
  {}
  ::fp_msgs::msg::PointRPY yaw(::fp_msgs::msg::PointRPY::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return std::move(msg_);
  }

private:
  ::fp_msgs::msg::PointRPY msg_;
};

class Init_PointRPY_pitch
{
public:
  explicit Init_PointRPY_pitch(::fp_msgs::msg::PointRPY & msg)
  : msg_(msg)
  {}
  Init_PointRPY_yaw pitch(::fp_msgs::msg::PointRPY::_pitch_type arg)
  {
    msg_.pitch = std::move(arg);
    return Init_PointRPY_yaw(msg_);
  }

private:
  ::fp_msgs::msg::PointRPY msg_;
};

class Init_PointRPY_roll
{
public:
  explicit Init_PointRPY_roll(::fp_msgs::msg::PointRPY & msg)
  : msg_(msg)
  {}
  Init_PointRPY_pitch roll(::fp_msgs::msg::PointRPY::_roll_type arg)
  {
    msg_.roll = std::move(arg);
    return Init_PointRPY_pitch(msg_);
  }

private:
  ::fp_msgs::msg::PointRPY msg_;
};

class Init_PointRPY_position
{
public:
  Init_PointRPY_position()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PointRPY_roll position(::fp_msgs::msg::PointRPY::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_PointRPY_roll(msg_);
  }

private:
  ::fp_msgs::msg::PointRPY msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::fp_msgs::msg::PointRPY>()
{
  return fp_msgs::msg::builder::Init_PointRPY_position();
}

}  // namespace fp_msgs

#endif  // FP_MSGS__MSG__DETAIL__POINT_RPY__BUILDER_HPP_
