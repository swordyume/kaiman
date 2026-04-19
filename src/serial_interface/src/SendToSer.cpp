//
// Created by lhb on 2026/4/19.
//

#include "SendToSer.h"
void SendToSer::SendAngle(float angle_deg) {
    uint8_t buf[5]={0};
    buf[0]=0x01;
    memcpy(buf+1,&angle_deg,sizeof(float));
    ser_.writeBytes(buf,sizeof(buf));

}
void SendToSer::SendFire() {
    uint8_t buf[1]={0x02};
    ser_.writeBytes(buf,sizeof(buf));
}