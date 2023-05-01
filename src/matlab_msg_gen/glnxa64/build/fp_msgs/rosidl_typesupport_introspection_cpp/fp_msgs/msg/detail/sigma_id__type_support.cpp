// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from fp_msgs:msg/SigmaID.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "fp_msgs/msg/detail/sigma_id__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace fp_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void SigmaID_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) fp_msgs::msg::SigmaID(_init);
}

void SigmaID_fini_function(void * message_memory)
{
  auto typed_message = static_cast<fp_msgs::msg::SigmaID *>(message_memory);
  typed_message->~SigmaID();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember SigmaID_message_member_array[2] = {
  {
    "sigma",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fp_msgs::msg::SigmaID, sigma),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fp_msgs::msg::SigmaID, id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers SigmaID_message_members = {
  "fp_msgs::msg",  // message namespace
  "SigmaID",  // message name
  2,  // number of fields
  sizeof(fp_msgs::msg::SigmaID),
  SigmaID_message_member_array,  // message members
  SigmaID_init_function,  // function to initialize message memory (memory has to be allocated)
  SigmaID_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t SigmaID_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &SigmaID_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace fp_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<fp_msgs::msg::SigmaID>()
{
  return &::fp_msgs::msg::rosidl_typesupport_introspection_cpp::SigmaID_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, fp_msgs, msg, SigmaID)() {
  return &::fp_msgs::msg::rosidl_typesupport_introspection_cpp::SigmaID_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
