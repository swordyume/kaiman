// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:msg/Target.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__TARGET__BUILDER_HPP_
#define INTERFACES__MSG__DETAIL__TARGET__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "interfaces/msg/detail/target__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace interfaces
{

namespace msg
{

namespace builder
{

class Init_Target_is_enemy
{
public:
  explicit Init_Target_is_enemy(::interfaces::msg::Target & msg)
  : msg_(msg)
  {}
  ::interfaces::msg::Target is_enemy(::interfaces::msg::Target::_is_enemy_type arg)
  {
    msg_.is_enemy = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::msg::Target msg_;
};

class Init_Target_ax
{
public:
  explicit Init_Target_ax(::interfaces::msg::Target & msg)
  : msg_(msg)
  {}
  Init_Target_is_enemy ax(::interfaces::msg::Target::_ax_type arg)
  {
    msg_.ax = std::move(arg);
    return Init_Target_is_enemy(msg_);
  }

private:
  ::interfaces::msg::Target msg_;
};

class Init_Target_vx
{
public:
  explicit Init_Target_vx(::interfaces::msg::Target & msg)
  : msg_(msg)
  {}
  Init_Target_ax vx(::interfaces::msg::Target::_vx_type arg)
  {
    msg_.vx = std::move(arg);
    return Init_Target_ax(msg_);
  }

private:
  ::interfaces::msg::Target msg_;
};

class Init_Target_y
{
public:
  explicit Init_Target_y(::interfaces::msg::Target & msg)
  : msg_(msg)
  {}
  Init_Target_vx y(::interfaces::msg::Target::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_Target_vx(msg_);
  }

private:
  ::interfaces::msg::Target msg_;
};

class Init_Target_x
{
public:
  explicit Init_Target_x(::interfaces::msg::Target & msg)
  : msg_(msg)
  {}
  Init_Target_y x(::interfaces::msg::Target::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Target_y(msg_);
  }

private:
  ::interfaces::msg::Target msg_;
};

class Init_Target_id
{
public:
  Init_Target_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Target_x id(::interfaces::msg::Target::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_Target_x(msg_);
  }

private:
  ::interfaces::msg::Target msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::msg::Target>()
{
  return interfaces::msg::builder::Init_Target_id();
}

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__TARGET__BUILDER_HPP_
