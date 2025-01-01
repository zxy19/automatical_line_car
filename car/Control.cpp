#include "Control.h"
#include "DataStorage.h"
#include "Planner.h"
#include <cmath>

bool Control::GRAY_VALUE_LL = false;
bool Control::GRAY_VALUE_L = false;
bool Control::GRAY_VALUE_M = false;
bool Control::GRAY_VALUE_R = false;
bool Control::GRAY_VALUE_RR = false;

unsigned int Control::sonicSend = 0;
unsigned int Control::lastSonic = 0;
bool Control::sonicHigh = false;
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
    pinMode(MOTOR_R, OUTPUT);
    pinMode(SONIC_ECHO, INPUT);
    pinMode(SONIC_SEND, INPUT);
    data_storage::setData(data_storage::DATA_SONIC, 0xffff, false);

    Planner::init();
}
void Control::update(unsigned int time) {
    data_storage::setData(data_storage::DATA_SENSOR_0, GRAY_VALUE_LL = digitalRead(GRAY_LL), false);
    data_storage::setData(data_storage::DATA_SENSOR_1, GRAY_VALUE_L = digitalRead(GRAY_L), false);
    data_storage::setData(data_storage::DATA_SENSOR_2, GRAY_VALUE_M = digitalRead(GRAY_M), false);
    data_storage::setData(data_storage::DATA_SENSOR_3, GRAY_VALUE_R = digitalRead(GRAY_R), false);
    data_storage::setData(data_storage::DATA_SENSOR_4, GRAY_VALUE_RR = digitalRead(GRAY_RR), false);

    if (time - lastSonic > 500) {
        lastSonic = time;
        sonicHigh = true;
        digitalWrite(SONIC_SEND, HIGH);
    }
    if (sonicHigh && time - lastSonic >= 10) {
        sonicHigh = false;
        lastSonic = time;
        digitalWrite(SONIC_SEND, LOW);
    }

    if (digitalRead(SONIC_ECHO)) {
        data_storage::setData(data_storage::DATA_SONIC, (time - lastSonic) * 500 / 29.1, false);
    }

    Planner::updateNext(time);

    timeloop += (time - lastTime);
    digitalWrite(MOTOR_L_EN, timeloop < abs(motorLeft));
    digitalWrite(MOTOR_R_EN, timeloop < abs(motorRight));
    digitalWrite(MOTOR_L,motorLeft > 0);
    digitalWrite(MOTOR_R,motorRight > 0);
    digitalWrite(MOTOR_L_REVERSE,motorLeft < 0);
    digitalWrite(MOTOR_R_REVERSE,motorRight < 0);
    lastTime = time;
}

void Control::setMotor(int left, int right) {
    motorLeft = left;
    motorRight = right;
}

void Control::controlCommand(String _cmd) {
    if(_cmd == "start"){
        Planner::resume();
    }else if(_cmd == "reset"){
        Planner::reset();
    }else if(_cmd == "pause"){
        Planner::pause();
    }
}