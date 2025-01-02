#ifndef CONTROL_H
#define CONTROL_H

#define GRAY_LL 5
#define GRAY_L 4
#define GRAY_M 14
#define GRAY_R 12
#define GRAY_RR 13

#define SONIC_SEND 16
#define SONIC_ECHO 1

#define MOTOR_L_EN 0
#define MOTOR_L 2
// #define MOTOR_L_REVERSE 13
#define MOTOR_R 8

// #define MOTOR_R_REVERSE 3
#define MOTOR_R_EN 9

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