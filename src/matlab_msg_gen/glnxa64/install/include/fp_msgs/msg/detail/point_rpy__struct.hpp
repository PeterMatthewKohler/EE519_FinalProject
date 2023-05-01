// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from fp_msgs:msg/PointRPY.idl
// generated code does not contain a copyright notice

#ifndef FP_MSGS__MSG__DETAIL__POINT_RPY__STRUCT_HPP_
#define FP_MSGS__MSG__DETAIL__POINT_RPY__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'position'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__fp_msgs__msg__PointRPY __attribute__((deprecated))
#else
# define DEPRECATED__fp_msgs__msg__PointRPY __declspec(deprecated)
#endif

namespace fp_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct PointRPY_
{
  using Type = PointRPY_<ContainerAllocator>;

  explicit PointRPY_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : position(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->roll = 0.0;
      this->pitch = 0.0;
      this->yaw = 0.0;
    }
  }

  explicit PointRPY_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : position(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->roll = 0.0;
      this->pitch = 0.0;
      this->yaw = 0.0;
    }
  }

  // field types and members
  using _position_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _position_type position;
  using _roll_type =
    double;
  _roll_type roll;
  using _pitch_type =
    double;
  _pitch_type pitch;
  using _yaw_type =
    double;
  _yaw_type yaw;

  // setters for named parameter idiom
  Type & set__position(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->position = _arg;
    return *this;
  }
  Type & set__roll(
    const double & _arg)
  {
    this->roll = _arg;
    return *this;
  }
  Type & set__pitch(
    const double & _arg)
  {
    this->pitch = _arg;
    return *this;
  }
  Type & set__yaw(
    const double & _arg)
  {
    this->yaw = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    fp_msgs::msg::PointRPY_<ContainerAllocator> *;
  using ConstRawPtr =
    const fp_msgs::msg::PointRPY_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<fp_msgs::msg::PointRPY_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<fp_msgs::msg::PointRPY_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      fp_msgs::msg::PointRPY_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<fp_msgs::msg::PointRPY_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      fp_msgs::msg::PointRPY_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<fp_msgs::msg::PointRPY_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<fp_msgs::msg::PointRPY_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<fp_msgs::msg::PointRPY_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__fp_msgs__msg__PointRPY
    std::shared_ptr<fp_msgs::msg::PointRPY_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__fp_msgs__msg__PointRPY
    std::shared_ptr<fp_msgs::msg::PointRPY_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PointRPY_ & other) const
  {
    if (this->position != other.position) {
      return false;
    }
    if (this->roll != other.roll) {
      return false;
    }
    if (this->pitch != other.pitch) {
      return false;
    }
    if (this->yaw != other.yaw) {
      return false;
    }
    return true;
  }
  bool operator!=(const PointRPY_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PointRPY_

// alias to use template instance with default allocator
using PointRPY =
  fp_msgs::msg::PointRPY_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace fp_msgs

#endif  // FP_MSGS__MSG__DETAIL__POINT_RPY__STRUCT_HPP_
