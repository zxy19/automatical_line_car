#line 1 "C:\\Users\\18668\\Desktop\\automatical_line_car\\car\\Debug.h"
#ifndef DEBUG_H
#define DEBUG_H
#include <ESP8266WiFi.h>
#include <Stream.h>
extern int debugClientCount;
extern WiFiClient *clients;
extern int currentDbg;
Stream *getDebugStream();
#endif