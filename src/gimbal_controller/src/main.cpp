//
// Created by lhb on 2026/4/19.
//
#include "chooser.h"

#include "rclcpp/rclcpp.hpp"

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<Chooser>();
    rclcpp::spin(node);
    rclcpp::shutdown();

}