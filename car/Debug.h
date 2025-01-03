#ifndef DEBUG_H
#define DEBUG_H

// #define USB_DEBUG

#include <ESP8266WiFi.h>
#include <Stream.h>
class tmpBuf: public Stream{
    public:
        int available(){return 0;}
        int read(){return 0;}
        int peek(){return 0;}
        size_t write(const uint8_t buffer){return 0;}
};

extern tmpBuf _tmpBuf;
#ifdef USB_DEBUG
#define INITIAL_STREAM Serial
#else
#define INITIAL_STREAM _tmpBuf
#endif

extern int debugClientCount;
extern WiFiClient *clients;
extern int currentDbg;
Stream *getDebugStream();
#endif