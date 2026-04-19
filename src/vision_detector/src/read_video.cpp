//
// Created by lhb on 2026/4/18.
//

#include "read_video.h"

#include "kalman.h"

bool ReadVideo::GunColor(const cv::Mat& hsv_image) {
    cv::Mat gun_mask;
    cv::inRange(hsv_image,cv::Scalar(100,120,70),cv::Scalar(130,255,255),gun_mask);
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(gun_mask,contours,cv::RETR_EXTERNAL,cv::CHAIN_APPROX_SIMPLE);
    for (const auto& contour : contours) {

        if(cv::contourArea(contour)>200)
        {
            // cv::RotatedRect rect=cv::minAreaRect(contour);
            // std::cout<<rect.center<<std::endl;
            return true;
        }
    }
    return false;
}
cv::Mat ReadVideo::GetRedMask(const cv::Mat& hsv_image) {
    cv::Mat mask1,mask2,mask;
    cv::inRange(hsv_image,cv::Scalar(0,120,70),cv::Scalar(10,255,255),mask1);
    cv::inRange(hsv_image,cv::Scalar(170,120,70),cv::Scalar(180,255,255),mask2);
    mask=mask1 | mask2;
    cv::Mat kernel1=cv::getStructuringElement(cv::MORPH_ELLIPSE,cv::Size(3,3));
    cv::dilate(mask,mask,kernel1);
    return mask;
}

cv::Mat ReadVideo::GetBlueMask(const cv::Mat& hsv_image) {
    cv::Mat mask;
    cv::inRange(hsv_image,cv::Scalar(100,120,70),cv::Scalar(130,255,255),mask);
    cv::Mat kernel1=cv::getStructuringElement(cv::MORPH_ELLIPSE,cv::Size(3,3));
    cv::dilate(mask,mask,kernel1);
    return mask;
}

std::vector<cv::Point2f> ReadVideo::GetArmours(const cv::Mat& mask,cv::Mat& image,cv::Scalar color) {
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(mask,contours,cv::RETR_EXTERNAL,cv::CHAIN_APPROX_SIMPLE);
    std::vector<cv::RotatedRect> lights;
    for (const auto& contour : contours) {


        cv::RotatedRect rect=cv::minAreaRect(contour);
        float width=rect.size.width;
        float height=rect.size.height;
        float ratio=height/width;
        if (ratio<2.0 || ratio>8.0) continue;
        lights.push_back(rect);
    }
    std::vector<cv::Point2f> armours;
    for (int i=0;i<lights.size();i++) {
        for (int j=i+1;j<lights.size();j++) {
            const cv::RotatedRect& left=lights[i];
            const cv::RotatedRect& right=lights[j];
            float y_difference=std::abs(left.center.y-right.center.y);

            if (y_difference>std::min(left.size.height,right.size.height)*0.5) continue;

            float distance=cv::norm(left.center-right.center);
            float average_height=(left.size.height+right.size.height)/2.0;
            float ratio=distance/average_height;
            if (ratio>4.0 || ratio<2.0) continue;
            cv::Point2f center=(left.center+right.center)/2.0;
            // std::cout<<center<<std::endl;
            armours.push_back(center);
            cv::circle(image,center,12,color);
        }
    }
    return armours;
}

int a=1;
void ReadVideo::UpdateArmours(const std::vector<cv::Point2f> &red_armours, const std::vector<cv::Point2f> &blue_armours,
                       float difference_t, const rclcpp::Time &stamp) {
    for (auto& armour : active_armours_) {
        if (difference_t>0.0f) {
            rclcpp::Time last_t=armour.last_t;
            armour.kf.Predict(difference_t);
        }
    }
    std::vector<Armour> current_armours;
    for (const auto& point : red_armours) {
        float init_vx =(point.x>512)?-200.0f:200.0f;
        current_armours.push_back({-1,point,true,Kalman(init_vx),stamp});
    }
    for (const auto& point : blue_armours) {
        float init_vx =(point.x>512)?-200.0f:200.0f;
        current_armours.push_back({-1,point,false,Kalman(init_vx),stamp});
    }
    for (size_t i=0;i<current_armours.size();i++) {
        auto& current_armour = current_armours[i];
        int is_match=-1;
        for (size_t j=0;j<active_armours_.size();j++) {
            auto& active_armours = active_armours_[j];
            if (active_armours.is_red!=current_armour.is_red) continue;
            float dy=std::abs(current_armour.position.y-active_armours.position.y);
            if (dy<1.0) is_match=j;
        }
        if (is_match!=-1) {
            auto& armours=active_armours_[is_match];
            armours.kf.Update(current_armour.position.x);
            armours.last_t=stamp;
            armours.position=cv::Point2f(armours.kf.GetX(),current_armour.position.y);
        }
        else {
            if (a==1)
            {
                current_armour.id=1;
                a=2;
            }
            else{current_armour.id=stamp.nanoseconds();}
            current_armour.kf.SetX(current_armour.position.x);
            active_armours_.push_back(current_armour);

        }
    }
    for (size_t i=0;i<active_armours_.size();i++) {
        auto& armour = active_armours_[i];
        if ((stamp-armour.last_t).seconds()>0.1) {
            active_armours_.erase(active_armours_.begin()+i);
        }
    }
}

interfaces::msg::Target ReadVideo::ArmousToMsg(Armour armour,bool a)
{
    interfaces::msg::Target t;
    t.id = armour.id;
    t.x=armour.kf.GetX();
    t.y=armour.position.y;
    t.vx=armour.kf.GetVX();
    t.ax=armour.kf.GetAX();
    t.is_enemy=a;
    return t;
}