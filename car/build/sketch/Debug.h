#line 1 "D:\\study\\automatical_line_car\\car\\Debug.h"
#ifndef DEBUG_H
#define DEBUG_H
#include <ESP8266WiFi.h>
#include <Stream.h>
extern int debugClientCount;
extern WiFiClient *clients;
extern int currentDbg;
Stream *getDebugStream();
#endif