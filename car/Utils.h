#ifndef UTILS_H
#define UTILS_H

#include <Arduino.h>
#include <stdlib.h>
#include "DataParser.h"
namespace utils{
    String fromBufferLen(char *buffer, int len);
    std::pair<String, int> getNext(String str, String delimiter, int index);
    int dataName2dataStartIdx(String dataName);
    String multiBytes2JSON(String data,int index);
}

#endif