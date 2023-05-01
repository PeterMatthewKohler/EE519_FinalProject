// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from fp_msgs:msg/PointRPY.idl
// generated code does not contain a copyright notice

#ifndef FP_MSGS__MSG__DETAIL__POINT_RPY__FUNCTIONS_H_
#define FP_MSGS__MSG__DETAIL__POINT_RPY__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "fp_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "fp_msgs/msg/detail/point_rpy__struct.h"

/// Initialize msg/PointRPY message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * fp_msgs__msg__PointRPY
 * )) before or use
 * fp_msgs__msg__PointRPY__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_fp_msgs
bool
fp_msgs__msg__PointRPY__init(fp_msgs__msg__PointRPY * msg);

/// Finalize msg/PointRPY message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_fp_msgs
void
fp_msgs__msg__PointRPY__fini(fp_msgs__msg__PointRPY * msg);

/// Create msg/PointRPY message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * fp_msgs__msg__PointRPY__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_fp_msgs
fp_msgs__msg__PointRPY *
fp_msgs__msg__PointRPY__create();

/// Destroy msg/PointRPY message.
/**
 * It calls
 * fp_msgs__msg__PointRPY__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_fp_msgs
void
fp_msgs__msg__PointRPY__destroy(fp_msgs__msg__PointRPY * msg);


/// Initialize array of msg/PointRPY messages.
/**
 * It allocates the memory for the number of elements and calls
 * fp_msgs__msg__PointRPY__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_fp_msgs
bool
fp_msgs__msg__PointRPY__Sequence__init(fp_msgs__msg__PointRPY__Sequence * array, size_t size);

/// Finalize array of msg/PointRPY messages.
/**
 * It calls
 * fp_msgs__msg__PointRPY__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_fp_msgs
void
fp_msgs__msg__PointRPY__Sequence__fini(fp_msgs__msg__PointRPY__Sequence * array);

/// Create array of msg/PointRPY messages.
/**
 * It allocates the memory for the array and calls
 * fp_msgs__msg__PointRPY__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_fp_msgs
fp_msgs__msg__PointRPY__Sequence *
fp_msgs__msg__PointRPY__Sequence__create(size_t size);

/// Destroy array of msg/PointRPY messages.
/**
 * It calls
 * fp_msgs__msg__PointRPY__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_fp_msgs
void
fp_msgs__msg__PointRPY__Sequence__destroy(fp_msgs__msg__PointRPY__Sequence * array);

#ifdef __cplusplus
}
#endif

#endif  // FP_MSGS__MSG__DETAIL__POINT_RPY__FUNCTIONS_H_
