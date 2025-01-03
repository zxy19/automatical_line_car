#include "Control.h"
#include "DataStorage.h"
#include "Planner.h"
#include "debug.h"
#include <cmath>

bool Control::GRAY_VALUE_LL = false;
bool Control::GRAY_VALUE_L = false;
bool Control::GRAY_VALUE_M = false;
bool Control::GRAY_VALUE_R = false;
bool Control::GRAY_VALUE_RR = false;

unsigned int Control::sonicSend = 0;
unsigned int Control::lastSonic = 0;
bool Control::sonicHigh = false;
bool Control::sonicWait = false;
unsigned int Control::lastTime = 0;
int Control::motorLeft = 0;
int Control::motorRight = 0;

unsigned char timeloop = 0;

void Control::init() {
    pinMode(GRAY_L, INPUT);
    pinMode(GRAY_LL, INPUT);
    pinMode(GRAY_M, INPUT);
    pinMode(GRAY_R, INPUT);
    pinMode(GRAY_RR, INPUT);
    pinMode(MOTOR_L, OUTPUT);
    pinMode(MOTOR_L_EN, OUTPUT);
    pinMode(MOTOR_R, OUTPUT);
    pinMode(MOTOR_R_EN, OUTPUT);
    pinMode(SONIC_ECHO, INPUT);
    pinMode(SONIC_SEND, OUTPUT);
    data_storage::setData(data_storage::DATA_SONIC, 0xffff, false);

    Planner::init();
}
void Control::update(unsigned int time) {
    data_storage::setData(data_storage::DATA_SENSOR_0, GRAY_VALUE_LL = digitalRead(GRAY_LL), false);
    data_storage::setData(data_storage::DATA_SENSOR_1, GRAY_VALUE_L = digitalRead(GRAY_L), false);
    data_storage::setData(data_storage::DATA_SENSOR_2, GRAY_VALUE_M = digitalRead(GRAY_M), false);
    data_storage::setData(data_storage::DATA_SENSOR_3, GRAY_VALUE_R = digitalRead(GRAY_R), false);
    data_storage::setData(data_storage::DATA_SENSOR_4, GRAY_VALUE_RR = digitalRead(GRAY_RR), false);

    if (time - lastSonic > 1000) {
        getDebugStream()->println("S_Sonic: " + String(time));
        lastSonic = time;
        sonicHigh = true;
        sonicWait = false;
        digitalWrite(SONIC_SEND, HIGH);
    }
    if (sonicHigh && time - lastSonic >= 10) {
        sonicHigh = false;
        lastSonic = time;
        sonicWait = true;
        digitalWrite(SONIC_SEND, LOW);
    }

    if (sonicWait && digitalRead(SONIC_ECHO)) {
        sonicWait = false;
        getDebugStream()->println("E_Sonic: " + String(time - lastSonic));
        data_storage::setData(data_storage::DATA_SONIC, (time - lastSonic) * 500 / 29.1, false);
    }

    Planner::updateNext(time);

    timeloop = (timeloop + time - lastTime) % 40;
    digitalWrite(MOTOR_L_EN, timeloop < abs(motorLeft));
    digitalWrite(MOTOR_R_EN, timeloop < abs(motorRight));
    digitalWrite(MOTOR_L, motorLeft > 0);
    digitalWrite(MOTOR_R, motorRight > 0);
#ifdef MOTOR_L_REVERSE
    digitalWrite(MOTOR_L_REVERSE, motorLeft < 0);
#endif
#ifdef MOTOR_R_REVERSE
    digitalWrite(MOTOR_R_REVERSE, motorRight < 0);
#endif
    lastTime = time;
}

void Control::setMotor(int left, int right) {
    motorLeft = left;
    motorRight = right;
    //getDebugStream()->println("S_Motor: " + String(left) + " " + String(right));
}

void Control::controlCommand(String _cmd) {
    getDebugStream()->println("S_MODE: " + _cmd);
    if (_cmd == "start") {
        Planner::resume();
    } else if (_cmd == "reset") {
        Planner::reset();
    } else if (_cmd == "pause") {
        Planner::pause();
    }
}