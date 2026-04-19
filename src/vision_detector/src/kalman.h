//
// Created by lhb on 2026/4/18.
//

#ifndef VISION_DETECTOR_KALMAN_H
#define VISION_DETECTOR_KALMAN_H


#include <Eigen/Dense>
class Kalman {
public:
    explicit Kalman(float vx) {
        x_ = Eigen::Vector3f::Zero();
        x_(1)=vx;
        A_=Eigen::Matrix3f::Identity();
        H_=Eigen::Matrix<float,1,3>::Zero();
        H_(0,0)=1.0f;

        R_=Eigen::Matrix<float,1,1>::Identity()*0.02f;
        P_=Eigen::Matrix3f::Zero();
        P_(0,0)=1.0f;
        P_(1,1)=1111.0f;
        P_(2,2)=100.0f;
    }

    float GetX() const {return x_(0);}
    float GetVX()const {return x_(1);}
    float GetAX() const {return x_(2);}
    void Predict(float difference_t);
    void Update(float x);
    float PredictNextLocation(float delta_t) const;
    void SetX(float x);
private:
    Eigen::Vector3f x_; //状态向量
    Eigen::Matrix3f A_; //状态转移矩阵
    Eigen::Matrix<float, 1, 3> H_; //观测矩阵
    Eigen::Matrix3f Q_; //过程噪声协方差
    Eigen::Matrix<float, 1, 1> R_; //测量噪声协方差
    Eigen::Matrix3f P_; //误差协方差

};


#endif //VISION_DETECTOR_KALMAN_H