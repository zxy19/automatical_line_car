#ifndef CONTROL_H
#define CONTROL_H

#define GRAY_LL 13
#define GRAY_L 12
#define GRAY_M 14
#define GRAY_R 27
#define GRAY_RR 26

#define SONIC_SEND 33
#define SONIC_ECHO 32

#define MOTOR_L 34
#define MOTOR_R 35
#include <Arduino.h>
namespace Control {
extern bool GRAY_VALUE_LL;
extern bool GRAY_VALUE_L;
extern bool GRAY_VALUE_M;
extern bool GRAY_VALUE_R;
extern bool GRAY_VALUE_RR;
extern unsigned int sonicSend;
extern unsigned int lastSonic;
extern bool sonicHigh;
extern unsigned int lastTime;

extern unsigned char motorLeft;
extern unsigned char motorRight;

void controlCommand(String _cmd);
void init();
void update(unsigned int time);
void setMotor(unsigned char left, unsigned char right);
}; // namespace Control

#endif