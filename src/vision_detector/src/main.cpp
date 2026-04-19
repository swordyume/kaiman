#include "rclcpp/rclcpp.hpp"
#include "read_video.h"
//
// Created by lhb on 2026/4/18.
//
int main(int argc,char* argv[])
{
    rclcpp::init(argc,argv);
    rclcpp::spin(std::make_shared<ReadVideo>());
    rclcpp::shutdown();
    return 0;
}