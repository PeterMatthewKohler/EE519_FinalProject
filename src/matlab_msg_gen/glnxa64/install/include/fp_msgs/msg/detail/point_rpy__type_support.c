// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from fp_msgs:msg/PointRPY.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "fp_msgs/msg/detail/point_rpy__rosidl_typesupport_introspection_c.h"
#include "fp_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "fp_msgs/msg/detail/point_rpy__functions.h"
#include "fp_msgs/msg/detail/point_rpy__struct.h"


// Include directives for member types
// Member `position`
#include "geometry_msgs/msg/point.h"
// Member `position`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void PointRPY__rosidl_typesupport_introspection_c__PointRPY_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  fp_msgs__msg__PointRPY__init(message_memory);
}

void PointRPY__rosidl_typesupport_introspection_c__PointRPY_fini_function(void * message_memory)
{
  fp_msgs__msg__PointRPY__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember PointRPY__rosidl_typesupport_introspection_c__PointRPY_message_member_array[4] = {
  {
    "position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fp_msgs__msg__PointRPY, position),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "roll",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fp_msgs__msg__PointRPY, roll),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pitch",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fp_msgs__msg__PointRPY, pitch),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "yaw",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(fp_msgs__msg__PointRPY, yaw),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers PointRPY__rosidl_typesupport_introspection_c__PointRPY_message_members = {
  "fp_msgs__msg",  // message namespace
  "PointRPY",  // message name
  4,  // number of fields
  sizeof(fp_msgs__msg__PointRPY),
  PointRPY__rosidl_typesupport_introspection_c__PointRPY_message_member_array,  // message members
  PointRPY__rosidl_typesupport_introspection_c__PointRPY_init_function,  // function to initialize message memory (memory has to be allocated)
  PointRPY__rosidl_typesupport_introspection_c__PointRPY_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t PointRPY__rosidl_typesupport_introspection_c__PointRPY_message_type_support_handle = {
  0,
  &PointRPY__rosidl_typesupport_introspection_c__PointRPY_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_fp_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, fp_msgs, msg, PointRPY)() {
  PointRPY__rosidl_typesupport_introspection_c__PointRPY_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  if (!PointRPY__rosidl_typesupport_introspection_c__PointRPY_message_type_support_handle.typesupport_identifier) {
    PointRPY__rosidl_typesupport_introspection_c__PointRPY_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &PointRPY__rosidl_typesupport_introspection_c__PointRPY_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
