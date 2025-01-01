#ifndef CONTROL_H
#define CONTROL_H

#define GRAY_LL 10
#define GRAY_L 9
#define GRAY_M 8
#define GRAY_R 11
#define GRAY_RR 7

#define SONIC_SEND 5
#define SONIC_ECHO 4

#define MOTOR_L_EN 14
#define MOTOR_L 12
#define MOTOR_L_REVERSE 13
#define MOTOR_R 15
#define MOTOR_R_REVERSE 3
#define MOTOR_R_EN 1

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

extern int motorLeft;
extern int motorRight;

void controlCommand(String _cmd);
void init();
void update(unsigned int time);
void setMotor(int left, int right);
}; // namespace Control

#endif