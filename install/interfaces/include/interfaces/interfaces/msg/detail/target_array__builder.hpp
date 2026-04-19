// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:msg/TargetArray.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__TARGET_ARRAY__BUILDER_HPP_
#define INTERFACES__MSG__DETAIL__TARGET_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "interfaces/msg/detail/target_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace interfaces
{

namespace msg
{

namespace builder
{

class Init_TargetArray_targets
{
public:
  Init_TargetArray_targets()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interfaces::msg::TargetArray targets(::interfaces::msg::TargetArray::_targets_type arg)
  {
    msg_.targets = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::msg::TargetArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::msg::TargetArray>()
{
  return interfaces::msg::builder::Init_TargetArray_targets();
}

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__TARGET_ARRAY__BUILDER_HPP_
