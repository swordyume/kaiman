// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from interfaces:msg/Target.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__TARGET__STRUCT_H_
#define INTERFACES__MSG__DETAIL__TARGET__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Target in the package interfaces.
typedef struct interfaces__msg__Target
{
  int64_t id;
  float x;
  float y;
  float vx;
  float ax;
  bool is_enemy;
} interfaces__msg__Target;

// Struct for a sequence of interfaces__msg__Target.
typedef struct interfaces__msg__Target__Sequence
{
  interfaces__msg__Target * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interfaces__msg__Target__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // INTERFACES__MSG__DETAIL__TARGET__STRUCT_H_
