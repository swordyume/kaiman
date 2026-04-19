// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from interfaces:msg/Target.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__TARGET__TRAITS_HPP_
#define INTERFACES__MSG__DETAIL__TARGET__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "interfaces/msg/detail/target__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Target & msg,
  std::ostream & out)
{
  out << "{";
  // member: id
  {
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << ", ";
  }

  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: vx
  {
    out << "vx: ";
    rosidl_generator_traits::value_to_yaml(msg.vx, out);
    out << ", ";
  }

  // member: ax
  {
    out << "ax: ";
    rosidl_generator_traits::value_to_yaml(msg.ax, out);
    out << ", ";
  }

  // member: is_enemy
  {
    out << "is_enemy: ";
    rosidl_generator_traits::value_to_yaml(msg.is_enemy, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Target & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << "\n";
  }

  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: vx
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vx: ";
    rosidl_generator_traits::value_to_yaml(msg.vx, out);
    out << "\n";
  }

  // member: ax
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ax: ";
    rosidl_generator_traits::value_to_yaml(msg.ax, out);
    out << "\n";
  }

  // member: is_enemy
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_enemy: ";
    rosidl_generator_traits::value_to_yaml(msg.is_enemy, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Target & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace interfaces

namespace rosidl_generator_traits
{

[[deprecated("use interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const interfaces::msg::Target & msg,
  std::ostream & out, size_t indentation = 0)
{
  interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const interfaces::msg::Target & msg)
{
  return interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<interfaces::msg::Target>()
{
  return "interfaces::msg::Target";
}

template<>
inline const char * name<interfaces::msg::Target>()
{
  return "interfaces/msg/Target";
}

template<>
struct has_fixed_size<interfaces::msg::Target>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<interfaces::msg::Target>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<interfaces::msg::Target>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // INTERFACES__MSG__DETAIL__TARGET__TRAITS_HPP_
