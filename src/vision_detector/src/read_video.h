//
// Created by lhb on 2026/4/18.
//

#ifndef VISION_DETECTOR_READ_VIDEO_H
#define VISION_DETECTOR_READ_VIDEO_H
#include "kalman.h"

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "cv_bridge/cv_bridge.h"

#include <interfaces/msg/target_array.hpp>
#include <opencv2/opencv.hpp>

struct Armour {
    int64_t id;
    cv::Point2f position;
    bool is_red;
    Kalman kf;
    rclcpp::Time last_t;
};

class ReadVideo : public rclcpp::Node
{
public:
    ReadVideo():Node("read_video")
    {
        pub_armours_ = this->create_publisher<interfaces::msg::TargetArray>("/active_armours", 10);
        image_sub_= this -> create_subscription<sensor_msgs::msg::Image>("/image_raw",10,[&]
        (sensor_msgs::msg::Image::SharedPtr msg) {

            //读取图像，识别装甲板，并给出装甲板中心坐标
            cv_ptr = cv_bridge::toCvShare(msg, sensor_msgs::image_encodings::BGR8);
            bgr_image_ = cv_ptr->image;
            cv::cvtColor(bgr_image_, hsv_image_, CV_BGR2HSV);
            bool gun_is_blue=GunColor(hsv_image_);
            cv::Mat red_mask = GetRedMask(hsv_image_);
            cv::Mat blue_mask = GetBlueMask(hsv_image_);
            //显示掩码效果
            // imshow("red_mask",red_mask);
            // imshow("blue_mask",blue_mask);
            std::vector<cv::Point2f> red_armours=GetArmours(red_mask,bgr_image_,cv::Scalar(255,0,0));
            std::vector<cv::Point2f> blue_armours=GetArmours(blue_mask,bgr_image_,cv::Scalar(0,0,255));
            //确定识别的装甲板目标，并用卡尔曼进行预测
            rclcpp::Time current_stamp = msg->header.stamp;
            float dt = 0.0f;
            if (last_image_stamp_.nanoseconds()!=0) dt = (current_stamp-last_image_stamp_).seconds();
            UpdateArmours(red_armours,blue_armours,dt,current_stamp);
            // for (auto& armour : active_armours_){
            //     if (armour.id==1){
            //         float x = armour.kf.GetAX();
            //         auto msg_x = std_msgs::msg::Float64();
            //         msg_x.data = x;
            //         pub_v_->publish(msg_x);
            //     }
            // }
            last_image_stamp_ = current_stamp;
            //预测装甲板0.8秒后的位置，以次验证卡尔曼是否有效
            // for (const auto& armour : active_armours_) {
            //     float t=0.8;
            //     cv::Point2f predict_position=PredictArmour(armour,t);
            //     cv::circle(bgr_image_,predict_position,25,cv::Scalar(0,255,0),3);
            // }
            //以此确定炮台位置
            // cv::circle(bgr_image_,ORIGINAL_POSITION,15,cv::Scalar(0,255,0),3);
            //确定要击打的目标并放在target_armours,将友方放在friend_armours
            interfaces::msg::TargetArray array_t;
            if (gun_is_blue) {
                for (auto& armour : active_armours_) {
                    if (!armour.is_red ) {
                        interfaces::msg::Target t=ArmousToMsg(armour,false);
                        array_t.targets.push_back(t);

                        // RCLCPP_INFO(this->get_logger(),"友方id%d,速度%.1f",armour.id,armour.kf.GetVX());
                    }
                    else {
                        interfaces::msg::Target t=ArmousToMsg(armour,true);
                        array_t.targets.push_back(t);
                        // RCLCPP_INFO(this->get_logger(),"%d敌方",armour.id);
                    }
                }
            }
            else {
                for (auto& armour : active_armours_) {
                    if (armour.is_red ) {
                        interfaces::msg::Target t=ArmousToMsg(armour,false);
                        array_t.targets.push_back(t);
                        // RCLCPP_INFO(this->get_logger(),"%d友方",armour.id);
                    }
                    else {
                        interfaces::msg::Target t=ArmousToMsg(armour,true);
                        array_t.targets.push_back(t);
                        // RCLCPP_INFO(this->get_logger(),"%d敌方",armour.id);
                    }
                }
            }
            pub_armours_->publish(array_t);
            // cv::imshow("装甲板识别",bgr_image_);
            // cv::waitKey(1);
        });
    }
private:
    rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr image_sub_;//订阅图像
    rclcpp::Publisher<interfaces::msg::TargetArray>::SharedPtr pub_armours_;
    cv_bridge::CvImageConstPtr cv_ptr;
    cv::Mat bgr_image_;
    cv::Mat hsv_image_;
    std::vector<Armour> active_armours_;//识别出来的装甲板
    rclcpp::Time last_image_stamp_;//上次时间戳

    bool GunColor(const cv::Mat& hsv_image) ;//检测炮台是否为蓝色
    cv::Mat GetRedMask(const cv::Mat& hsv_image);//获取红色掩码
    cv::Mat GetBlueMask(const cv::Mat& hsv_image);//获取蓝色掩码
    std::vector<cv::Point2f> GetArmours(const cv::Mat& mask,cv::Mat& image,cv::Scalar color);//获取装甲板中心点

    void UpdateArmours(const std::vector<cv::Point2f> &red_armours, const std::vector<cv::Point2f> &blue_armours,
                       float difference_t, const rclcpp::Time &stamp);//更新可识别装甲板，即active_armours
    interfaces::msg::Target ArmousToMsg(Armour armour,bool a);
};


#endif //VISION_DETECTOR_READ_VIDEO_H