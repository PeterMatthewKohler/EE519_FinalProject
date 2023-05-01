// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from fp_msgs:msg/SigmaID.idl
// generated code does not contain a copyright notice

#ifndef FP_MSGS__MSG__DETAIL__SIGMA_ID__STRUCT_HPP_
#define FP_MSGS__MSG__DETAIL__SIGMA_ID__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__fp_msgs__msg__SigmaID __attribute__((deprecated))
#else
# define DEPRECATED__fp_msgs__msg__SigmaID __declspec(deprecated)
#endif

namespace fp_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SigmaID_
{
  using Type = SigmaID_<ContainerAllocator>;

  explicit SigmaID_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->sigma = 0.0;
      this->id = 0;
    }
  }

  explicit SigmaID_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->sigma = 0.0;
      this->id = 0;
    }
  }

  // field types and members
  using _sigma_type =
    double;
  _sigma_type sigma;
  using _id_type =
    int8_t;
  _id_type id;

  // setters for named parameter idiom
  Type & set__sigma(
    const double & _arg)
  {
    this->sigma = _arg;
    return *this;
  }
  Type & set__id(
    const int8_t & _arg)
  {
    this->id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    fp_msgs::msg::SigmaID_<ContainerAllocator> *;
  using ConstRawPtr =
    const fp_msgs::msg::SigmaID_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<fp_msgs::msg::SigmaID_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<fp_msgs::msg::SigmaID_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      fp_msgs::msg::SigmaID_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<fp_msgs::msg::SigmaID_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      fp_msgs::msg::SigmaID_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<fp_msgs::msg::SigmaID_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<fp_msgs::msg::SigmaID_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<fp_msgs::msg::SigmaID_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__fp_msgs__msg__SigmaID
    std::shared_ptr<fp_msgs::msg::SigmaID_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__fp_msgs__msg__SigmaID
    std::shared_ptr<fp_msgs::msg::SigmaID_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SigmaID_ & other) const
  {
    if (this->sigma != other.sigma) {
      return false;
    }
    if (this->id != other.id) {
      return false;
    }
    return true;
  }
  bool operator!=(const SigmaID_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SigmaID_

// alias to use template instance with default allocator
using SigmaID =
  fp_msgs::msg::SigmaID_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace fp_msgs

#endif  // FP_MSGS__MSG__DETAIL__SIGMA_ID__STRUCT_HPP_
