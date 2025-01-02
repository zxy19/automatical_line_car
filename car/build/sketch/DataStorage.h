#line 1 "D:\\study\\automatical_line_car\\car\\DataStorage.h"
#ifndef DATASTORAGE_H
#define DATASTORAGE_H
#include "EEPROM.h"
#include <Arduino.h>

namespace data_storage {
constexpr int DATA_VERSION = 4;
constexpr int MAX_DATA_SIZE = 32;
constexpr int DATA_SENSOR = 0;
constexpr int DATA_SENSOR_0 = 0;
constexpr int DATA_SENSOR_1 = 1;
constexpr int DATA_SENSOR_2 = 2;
constexpr int DATA_SENSOR_3 = 3;
constexpr int DATA_SENSOR_4 = 4;
constexpr int DATA_SONIC = 5;
constexpr int DATA_PID = 8;
constexpr int DATA_PID_P = 8;
constexpr int DATA_PID_I = 9;
constexpr int DATA_PID_D = 10;
constexpr int DATA_START = 11;
constexpr int DATA_TIME = 12;
constexpr int DATA_SPEED = 13;
constexpr int DATA_SPEED_0 = 13;
constexpr int DATA_SPEED_1 = 14;
constexpr int DATA_SPEED_2 = 15;

constexpr int DATA_DELAY_START = 16;
constexpr int DATA_PARAM_SONIC_THRESHOLD = 17;
constexpr int DATA_PARAM_OBS_T1 = 18;
constexpr int DATA_PARAM_OBS_T2 = 19;
constexpr int DATA_PARAM_OBS_T3 = 20;
constexpr int DATA_PARAM_OBS_T4 = 21;
constexpr int DATA_PARAM_CIRCLE_T = 22;

constexpr int DATA_STAGE = 31;
constexpr int DATA_PHASE = 30;
constexpr int DATA_PAUSE = 29;

extern int DATA[MAX_DATA_SIZE];
extern bool modified[MAX_DATA_SIZE];
int getData(int index);
void setData(int index, int value, bool persist = true);
void setDefaultIfZero(int index,int value);
void init();
void persist();
} // namespace data_storage
#endif