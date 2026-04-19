//
// Created by lhb on 2026/4/19.
//

#include "chooser.h"
float Chooser::SolveImpactTime(const Armour target)  {
    // 目标当前状态
    float x = target.x;
    float vx = target.vx;
    float ax = target.ax;
    float y = target.y;

    // 我方位置
    const float x0 = ORIGINAL_POSITION.x;
    const float y0 = ORIGINAL_POSITION.y;
    const float dy = y - y0;  // 纵向差值（恒定）

    // 牛顿法迭代
    const int max_iter = 20;
    const float epsilon = 1e-3f;   // 时间精度
    float t = 0.5f;                // 初始猜测（可设为 0.5 秒）

    for (int i = 0; i < max_iter; ++i) {
        // 计算 x_t 和 dx/dt
        float x_t = x + vx * t + 0.5f * ax * t * t;
        float dx_dt = vx + ax * t;   // dx/dt

        float dx = x_t - x0;
        float dist = std::hypot(dx, dy);
        if (dist < 1e-6f) break;     // 防止除零

        // f(t) = dist - v_bullet * t
        float f = dist - v_ball * t;
        // f'(t) = (dx * dx_dt) / dist - v_bullet
        float df = (dx * dx_dt) / dist - v_ball;

        if (std::fabs(df) < 1e-6f) break;

        float t_new = t - f / df;
        if (std::fabs(t_new - t) < epsilon) {
            t = t_new;
            break;
        }
        t = t_new;
    }

    // 限制 t 在合理范围内（避免负值或过大）
    t = std::max(0.01f, std::min(t, 3.0f));
    return t;
}
cv::Point2f Chooser::TargetToPosition(const Armour best_target)
{
    float t_hit = SolveImpactTime(best_target);
    float aim_x = best_target.x + best_target.vx * t_hit + 0.5f * best_target.ax * t_hit * t_hit;
    float aim_y = best_target.y;   // y 坐标不变
    cv::Point2f target_point(aim_x, aim_y);
    return target_point;
}
bool Chooser::CheckIsSafe(std::vector<Armour> friend_armours,const Armour best_target) {
    if (friend_armours.empty()) return true;
    float min_distance=65.0;
    for (auto target : friend_armours) {
        cv::Point2f aim=TargetToPosition(best_target);
        cv::Point2f obstacle=TargetToPosition(target);
        if (target.y<aim.y) continue;
        float dist=std::fabs((ORIGINAL_POSITION.x*(aim.y-obstacle.y)+aim.x*(obstacle.y-ORIGINAL_POSITION.y))/
            (aim.y-ORIGINAL_POSITION.y)-obstacle.x);
        if (dist<min_distance) {
            return false;
        }
    }
    return true;
}
float Chooser::PositionToAngle(cv::Point2f point) {
    float dx=point.x-ORIGINAL_POSITION.x;
    float dy=point.y-ORIGINAL_POSITION.y;
    float angle_rad=std::atan2(dy,dx);
    float angel_deg=angle_rad*180.0/M_PI;
    return angel_deg;
}