//
// Created by lhb on 2026/4/19.
//

#ifndef GIMBAL_CONTROLLER_CHOOSER_H
#define GIMBAL_CONTROLLER_CHOOSER_H

#include <interfaces/msg/target_array.hpp>
#include <std_msgs/msg/float32.hpp>

#include <rclcpp/rclcpp.hpp>
#include <opencv2/opencv.hpp>
struct Armour
{
    float x;
    float y;
    float vx;
    float ax;
};
class Chooser:public rclcpp::Node
{
public:
    Chooser():Node("chooser")
    {
        pub_v_=this->create_publisher<std_msgs::msg::Float32>("angle", 10);
        target_sub=this->create_subscription<interfaces::msg::TargetArray>("/active_armours",10,[&]
        (interfaces::msg::TargetArray msg)->void
        {
            friend_armours.clear();
            target_armours.clear();
            for (size_t i=0;i<msg.targets.size();i++)
            {
                Armour armour;
                armour.x=msg.targets[i].x;
                armour.y=msg.targets[i].y;
                armour.vx=msg.targets[i].vx;
                armour.ax=msg.targets[i].ax;
                if (msg.targets[i].is_enemy==false)
                {
                    friend_armours.push_back(armour);
                }
                else
                {
                    target_armours.push_back(armour);
                }
            }
            //RCLCPP_INFO(this->get_logger(), "己方%d个",friend_armours.size());
            //RCLCPP_INFO(this->get_logger(), "敌方%d个",friend_armours.size());
            if (!target_armours.empty())
            {
                for (int i=0;i<target_armours.size()-1;i++){
                    for (int j=0;j<target_armours.size()-1;j++){
                        if (target_armours[j].y<target_armours[j+1].y){
                            Armour temp=target_armours[j];
                            target_armours[j]=target_armours[j+1];
                            target_armours[j+1]=temp;
                        }
                    }
                }

                Armour best_target = target_armours[0];


                int a=0;
                for (int j=0;j<target_armours.size();j++){
                    if (!CheckIsSafe(friend_armours,best_target)){
                        a=1;
                    }
                    else
                    {
                        break;
                    }
                }

                if (a==0)
                {
                    cv::Point2f target_point=TargetToPosition(best_target);

                    float target_angle = PositionToAngle(target_point);
                    auto msg_x=std_msgs::msg::Float32();
                    msg_x.data=target_angle;
                    pub_v_->publish(msg_x);
                    
                }
            }
        });
    };
private:
    rclcpp::Subscription<interfaces::msg::TargetArray>::SharedPtr target_sub;
    rclcpp::Publisher<std_msgs::msg::Float32>::SharedPtr pub_v_;
    std::vector<Armour> target_armours; //敌方装甲板
    std::vector<Armour> friend_armours; //友方装甲板
    cv::Point2f ORIGINAL_POSITION =cv::Point2f(576,611);//炮台位置
    const float v_ball=600.0;//小球速度

    bool CheckIsSafe(std::vector<Armour> friend_armours,const Armour target);//检测有没有友方装甲板挡路，是否应该击打目标
    float SolveImpactTime(const Armour target);   // 牛顿法求解命中时间
    cv::Point2f TargetToPosition(const Armour target);
    float PositionToAngle(cv::Point2f point);//获取炮台转向角度
};


#endif //GIMBAL_CONTROLLER_CHOOSER_H
