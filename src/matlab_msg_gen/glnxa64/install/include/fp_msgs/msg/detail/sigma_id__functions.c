// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from fp_msgs:msg/SigmaID.idl
// generated code does not contain a copyright notice
#include "fp_msgs/msg/detail/sigma_id__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


bool
fp_msgs__msg__SigmaID__init(fp_msgs__msg__SigmaID * msg)
{
  if (!msg) {
    return false;
  }
  // sigma
  // id
  return true;
}

void
fp_msgs__msg__SigmaID__fini(fp_msgs__msg__SigmaID * msg)
{
  if (!msg) {
    return;
  }
  // sigma
  // id
}

fp_msgs__msg__SigmaID *
fp_msgs__msg__SigmaID__create()
{
  fp_msgs__msg__SigmaID * msg = (fp_msgs__msg__SigmaID *)malloc(sizeof(fp_msgs__msg__SigmaID));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(fp_msgs__msg__SigmaID));
  bool success = fp_msgs__msg__SigmaID__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
fp_msgs__msg__SigmaID__destroy(fp_msgs__msg__SigmaID * msg)
{
  if (msg) {
    fp_msgs__msg__SigmaID__fini(msg);
  }
  free(msg);
}


bool
fp_msgs__msg__SigmaID__Sequence__init(fp_msgs__msg__SigmaID__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  fp_msgs__msg__SigmaID * data = NULL;
  if (size) {
    data = (fp_msgs__msg__SigmaID *)calloc(size, sizeof(fp_msgs__msg__SigmaID));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = fp_msgs__msg__SigmaID__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        fp_msgs__msg__SigmaID__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
fp_msgs__msg__SigmaID__Sequence__fini(fp_msgs__msg__SigmaID__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      fp_msgs__msg__SigmaID__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

fp_msgs__msg__SigmaID__Sequence *
fp_msgs__msg__SigmaID__Sequence__create(size_t size)
{
  fp_msgs__msg__SigmaID__Sequence * array = (fp_msgs__msg__SigmaID__Sequence *)malloc(sizeof(fp_msgs__msg__SigmaID__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = fp_msgs__msg__SigmaID__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
fp_msgs__msg__SigmaID__Sequence__destroy(fp_msgs__msg__SigmaID__Sequence * array)
{
  if (array) {
    fp_msgs__msg__SigmaID__Sequence__fini(array);
  }
  free(array);
}
