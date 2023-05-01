// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from fp_msgs:msg/SigmaID.idl
// generated code does not contain a copyright notice
#include "fp_msgs/msg/detail/sigma_id__rosidl_typesupport_fastrtps_cpp.hpp"
#include "fp_msgs/msg/detail/sigma_id__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace fp_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_fp_msgs
cdr_serialize(
  const fp_msgs::msg::SigmaID & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: sigma
  cdr << ros_message.sigma;
  // Member: id
  cdr << ros_message.id;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_fp_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  fp_msgs::msg::SigmaID & ros_message)
{
  // Member: sigma
  cdr >> ros_message.sigma;

  // Member: id
  cdr >> ros_message.id;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_fp_msgs
get_serialized_size(
  const fp_msgs::msg::SigmaID & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: sigma
  {
    size_t item_size = sizeof(ros_message.sigma);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: id
  {
    size_t item_size = sizeof(ros_message.id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_fp_msgs
max_serialized_size_SigmaID(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: sigma
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: id
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static bool _SigmaID__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const fp_msgs::msg::SigmaID *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _SigmaID__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<fp_msgs::msg::SigmaID *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _SigmaID__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const fp_msgs::msg::SigmaID *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _SigmaID__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_SigmaID(full_bounded, 0);
}

static message_type_support_callbacks_t _SigmaID__callbacks = {
  "fp_msgs::msg",
  "SigmaID",
  _SigmaID__cdr_serialize,
  _SigmaID__cdr_deserialize,
  _SigmaID__get_serialized_size,
  _SigmaID__max_serialized_size
};

static rosidl_message_type_support_t _SigmaID__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_SigmaID__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace fp_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_fp_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<fp_msgs::msg::SigmaID>()
{
  return &fp_msgs::msg::typesupport_fastrtps_cpp::_SigmaID__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, fp_msgs, msg, SigmaID)() {
  return &fp_msgs::msg::typesupport_fastrtps_cpp::_SigmaID__handle;
}

#ifdef __cplusplus
}
#endif
