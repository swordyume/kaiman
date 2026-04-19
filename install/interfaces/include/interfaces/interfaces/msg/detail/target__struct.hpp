// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from interfaces:msg/Target.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__TARGET__STRUCT_HPP_
#define INTERFACES__MSG__DETAIL__TARGET__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__interfaces__msg__Target __attribute__((deprecated))
#else
# define DEPRECATED__interfaces__msg__Target __declspec(deprecated)
#endif

namespace interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Target_
{
  using Type = Target_<ContainerAllocator>;

  explicit Target_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0ll;
      this->x = 0.0f;
      this->y = 0.0f;
      this->vx = 0.0f;
      this->ax = 0.0f;
      this->is_enemy = false;
    }
  }

  explicit Target_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0ll;
      this->x = 0.0f;
      this->y = 0.0f;
      this->vx = 0.0f;
      this->ax = 0.0f;
      this->is_enemy = false;
    }
  }

  // field types and members
  using _id_type =
    int64_t;
  _id_type id;
  using _x_type =
    float;
  _x_type x;
  using _y_type =
    float;
  _y_type y;
  using _vx_type =
    float;
  _vx_type vx;
  using _ax_type =
    float;
  _ax_type ax;
  using _is_enemy_type =
    bool;
  _is_enemy_type is_enemy;

  // setters for named parameter idiom
  Type & set__id(
    const int64_t & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__x(
    const float & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const float & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__vx(
    const float & _arg)
  {
    this->vx = _arg;
    return *this;
  }
  Type & set__ax(
    const float & _arg)
  {
    this->ax = _arg;
    return *this;
  }
  Type & set__is_enemy(
    const bool & _arg)
  {
    this->is_enemy = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    interfaces::msg::Target_<ContainerAllocator> *;
  using ConstRawPtr =
    const interfaces::msg::Target_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interfaces::msg::Target_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interfaces::msg::Target_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::Target_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::Target_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::Target_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::Target_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interfaces::msg::Target_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interfaces::msg::Target_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interfaces__msg__Target
    std::shared_ptr<interfaces::msg::Target_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interfaces__msg__Target
    std::shared_ptr<interfaces::msg::Target_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Target_ & other) const
  {
    if (this->id != other.id) {
      return false;
    }
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->vx != other.vx) {
      return false;
    }
    if (this->ax != other.ax) {
      return false;
    }
    if (this->is_enemy != other.is_enemy) {
      return false;
    }
    return true;
  }
  bool operator!=(const Target_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Target_

// alias to use template instance with default allocator
using Target =
  interfaces::msg::Target_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__TARGET__STRUCT_HPP_
