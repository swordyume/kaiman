//
// Created by lhb on 2026/4/19.
//

#ifndef SERIAL_INTERFACE_SENDTOSER_H
#define SERIAL_INTERFACE_SENDTOSER_H

#include <std_msgs/msg/float32.hpp>
#include "rclcpp/rclcpp.hpp"

#include <serialib.h>
class SendToSer: public rclcpp::Node
{
public:
    SendToSer():Node("send_to_ser")
    {
        this->declare_parameter("serial_port", "/dev/pts/2");
        std::string port;//可改名称
        this->get_parameter("serial_port", port);
        if (ser_.openDevice(port.c_str(),115200)!=1) {
            RCLCPP_ERROR(this->get_logger(), "Cannot open serial port %sfor reading",port.c_str());
        }
        else {
            RCLCPP_INFO(this->get_logger(), "Opened serial port %sfor reading",port.c_str());
        }
        angle_sub_ = this->create_subscription<std_msgs::msg::Float32>("angle",10,[&]
            (std_msgs::msg::Float32::SharedPtr msg)->void
        {
            float angle=msg->data;
            SendAngle(-angle);

            std::this_thread::sleep_for(std::chrono::milliseconds(1));
            SendFire();
        });
    };
private:
    rclcpp::Subscription<std_msgs::msg::Float32>::SharedPtr angle_sub_;
    serialib ser_;//串口对象

    void SendAngle(float angle_deg);//发送转向数据
    void SendFire();//发送开火数据
};


#endif //SERIAL_INTERFACE_SENDTOSER_H
