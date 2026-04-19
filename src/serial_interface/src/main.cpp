//
// Created by lhb on 2026/4/19.
//
#include "SendToSer.h"

#include "rclcpp/rclcpp.hpp"

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<SendToSer>();
    rclcpp::spin(node);
    rclcpp::shutdown();

}