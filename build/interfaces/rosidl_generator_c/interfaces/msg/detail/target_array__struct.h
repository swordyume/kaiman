// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from interfaces:msg/TargetArray.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__TARGET_ARRAY__STRUCT_H_
#define INTERFACES__MSG__DETAIL__TARGET_ARRAY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'targets'
#include "interfaces/msg/detail/target__struct.h"

/// Struct defined in msg/TargetArray in the package interfaces.
typedef struct interfaces__msg__TargetArray
{
  interfaces__msg__Target__Sequence targets;
} interfaces__msg__TargetArray;

// Struct for a sequence of interfaces__msg__TargetArray.
typedef struct interfaces__msg__TargetArray__Sequence
{
  interfaces__msg__TargetArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interfaces__msg__TargetArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // INTERFACES__MSG__DETAIL__TARGET_ARRAY__STRUCT_H_
