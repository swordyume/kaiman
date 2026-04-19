//
// Created by lhb on 2026/4/18.
//

#include "kalman.h"


void Kalman::Predict(float dt) {
    A_(0,1)=dt;
    A_(1,2)=dt;
    A_(0,2)=0.5*dt*dt;
    Q_<<0.1f*dt,0.0f,0.0f,
        0.0f,0.1f*dt,0.0f,
        0.0f,0.0f,0.25f*dt;
    x_=A_*x_;
    P_=A_*P_*A_.transpose()+Q_;
}
void Kalman::Update(float x) {
    Eigen::Matrix<float,1,1> Z;
    Z<<x;;
    Eigen::Matrix<float,3,1> K=P_*H_.transpose()*(H_*P_*H_.transpose()+R_).inverse();
    x_=x_+K*(Z-H_*x_);
    P_=(Eigen::Matrix3f::Identity()-K*H_)*P_;
}

float Kalman::PredictNextLocation(float delta_t) const {
    return x_(0)+x_(1)*delta_t+0.5f*x_(2)*delta_t*delta_t;
}
void Kalman::SetX(float x) {
    x_(0)=x;
}