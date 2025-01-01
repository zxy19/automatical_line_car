#line 1 "C:\\Users\\18668\\Desktop\\automatical_line_car\\car\\Utils.cpp"
#include "Utils.h"
#include "DataStorage.h"
std::pair<String, int> utils::getNext(String str, String delimiter, int index) {
    if (index == str.length()) {
        return std::make_pair("", str.length());
    }
    int nxt = str.indexOf(delimiter, index);
    if (nxt == -1) {
        return std::make_pair(str.substring(index), str.length());
    }
    return std::make_pair(str.substring(index, nxt), nxt + 1);
}

int utils::dataName2dataStartIdx(String dataName) {
    if (dataName == "sensor") {
        return data_storage::DATA_SENSOR;
    } else if (dataName == "pid") {
        return data_storage::DATA_PID;
    } else if (dataName == "states") {
        return data_storage::DATA_START;
    } else if (dataName == "time") {
        return data_storage::DATA_TIME;
    } else if (dataName == "speed") {
        return data_storage::DATA_SPEED;
    }else if(dataName == "any") return 0;

    return -1;
}
String utils::multiBytes2JSON(String str, int pos) {
    String ret = "{\"s\":[";
    uint8_t data = (uint8_t)str.charAt(pos);
    for (int j = 0; j < 8; j++) {
        ret += (bitRead(data, j) ? "1" : "0");
        if (j != 7) {
            ret += ",";
        }
    }
    ret += "],\"l\":" + String(((int)str.charAt(pos + 1))) + ",\"r\":" + String(((int)str.charAt(pos + 2))) + "}";
    return ret;
}

String utils::fromBufferLen(char *buffer, int len) {
    char *tmpbuf = (char *)malloc(len + 1);
    memcpy(tmpbuf, buffer, len);
    tmpbuf[len] = 0;
    String ret(tmpbuf);
    free(tmpbuf);
    return ret;
}