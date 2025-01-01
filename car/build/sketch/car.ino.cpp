#include <Arduino.h>
#line 1 "D:\\study\\automatical_line_car\\car\\car.ino"
// #define DEBUG
#include "Control.h"
#include "DataStorage.h"
#include "DataType.h"
#include "Debug.h"
#include "Utils.h"
#include "dataParser.h"
#include "responseGenerator.h"
#include <DNSServer.h>
#include <ESP8266WiFi.h>

#define SUB_SERIAL Serial1
#define DEV_SERIAL Serial

WiFiServer server(80);
DNSServer dnsServer;
int isWlanChecking = 0;
String storePass;
String wlanIp = "";
// 1:正在连接,2:已失败,3:成功
int wlanStatus = 0;

constexpr int maxClients = 10;
constexpr int storeDataSingle_last = 3;
constexpr int storeDataSingle_long = 3;
constexpr int maxStoreDataLen_last = storeDataSingle_last * 2400;
constexpr int maxStoreDataLen_long = storeDataSingle_long * 4320;
int persistLoopLast = 0, persistLoopLong = 0;
data_parser::Parser fromSUB_SERIAL, fromSerial2, wifi[maxClients];
bool isHttpClient[maxClients];
WiFiClient client[maxClients];

String currentData = "";

int debugClientCount = maxClients;
WiFiClient *clients = client;
int currentDbg = maxClients;

const String W_NET =
    "<!DOCTYPE html><html lang=\"en\"><head><meta charset=\"UTF-8\"/><meta name=\"viewport\"content=\"width=device-width, initial-scale=1.0\"/><title>Network "
    "configuration</title></"
    "head><body><style>input.value.changed{background-color:#ffe0b2}select,input{-webkit-appearance:none;-moz-appearance:none;appearance:none;outline:0;padding:10px "
    "8px;box-shadow:0 0 2px 0px#4c4c4c;border-radius:5px;border:gray 1px solid}select:focus,input:focus{box-shadow:0 0 2px 0px#2196f3}.btn{border:gray 1px solid;padding:6px 10px "
    "10px "
    "10px;border-radius:5px;background-color:#2196f3;color:white;text-decoration:none;margin:5px;cursor:pointer;display:inline-block}.btn:hover{background-color:#0277bd}</"
    "style><div id=\"i\"></div><div><b>SSID:</b><select id=\"s\"></select></div><div><b>pass:</b><input id=\"p\"/></div><div><a class=\"btn\"onclick=\"s()\"id=\"b\">Send</a><a "
    "class=\"btn\"onclick=\"c()\"id=\"c\">Scan</a></div><script>var _i=(n)=>document.getElementById(n);var i=(n)=>_i(n).value;var "
    "s=(e)=>{_i(\"b\").innerHTML=\"...\";l=false;fetch(\"/network\",{method:\"POST\",body:i(\"s\")+\":::\"+i(\"p\"),}).then(v)};var l=false;var "
    "v=()=>{fetch(\"/networkStatus\").then((d)=>d.text()).then((d)=>{if(d.indexOf(\"success\")!=-1){alert(\"ok\");location.href=\"/redirection.html\";l=true}else "
    "if(d.indexOf(\"fail\")!=-1){alert(\"fail\");l=true}}).finally(()=>{if(!l)setTimeout(v,1000);else _i(\"b\").innerHTML=\"Send\"})};var "
    "c=()=>{_i(\"c\").innerHTML=\"...\";fetch(\"/scan\").then((d)=>d.json()).then((d)=>(_i(\"s\").innerHTML=d.map((d)=>`<option "
    "value=\"${d}\">${d}</option>`))).finally(()=>(_i(\"c\").innerHTML=\"Scan\"))};var g=(n)=>{var r=window.location.search.substr(1).match(new "
    "RegExp(\"(^|&)\"+n+\"=([^&]*)(&|$)\"));if(r!=null)return unescape(r[2]);return "
    "null};if(g(\"ip\"))_i(\"i\").innerHTML=`${g(\"ip\")}\x3A\xE6\xA3\x80\xE6\xB5\x8B\xE5\x88\xB0\x49\x50\xE3\x80\x82\xE8\xAF\xB7\xE8\xBF\x9E\xE6\x8E\xA5\xE7\xBD\x91\xE7\xBB\x9C${"
    "g(\"ssid\")}\xE5\xB9\xB6\xE5\x88\xB7\xE6\x96\xB0\xE6\x9D\xA5\xE8\xAE\xBF\xE9\x97\xAE\xE7\xAE\xA1\xE7\x90\x86\xE9\xA1\xB5<a "
    "class='btn'onclick='location.reload()'>\xE7\x82\xB9\xE5\x87\xBB\xE9\x87\x8D\xE8\xBD\xBD</a>`;</script></body></html>";
#line 57 "D:\\study\\automatical_line_car\\car\\car.ino"
void responseAll(String query, String data);
#line 69 "D:\\study\\automatical_line_car\\car\\car.ino"
String getResponseFor(data_parser::Result result, Type sourceType, Stream *source);
#line 168 "D:\\study\\automatical_line_car\\car\\car.ino"
void startConnection(String ssid, String pass);
#line 174 "D:\\study\\automatical_line_car\\car\\car.ino"
void setup();
#line 206 "D:\\study\\automatical_line_car\\car\\car.ino"
void loop();
#line 57 "D:\\study\\automatical_line_car\\car\\car.ino"
void responseAll(String query, String data) {
    String temp;
    temp = responseGenerator::getResponseGenerally(Type::BINARY, query, data);
    for (int i = 0; i < 5; i++) {
        if (client[i].connected() && !isHttpClient[i]) {
            client[i].print(temp);
        }
    }
    SUB_SERIAL.print(temp);
    temp = responseGenerator::getResponseGenerally(Type::STRING, query, data);
    DEV_SERIAL.print(temp);
}
String getResponseFor(data_parser::Result result, Type sourceType, Stream *source) {
    String query = result.query;
    // getDebugStream()->printf("getResponseFor %s\r\n", query.c_str());
    if (query == "mb") {
        uint8_t data1 = result.data.charAt(0);
        for (int i = 0; i < 8; i++) {
            data_storage::setData(data_storage::DATA_SENSOR + i, (data1 >> i) & 0x01);
        }
        data_storage::setData(data_storage::DATA_SPEED_1, result.data.charAt(1));
        data_storage::setData(data_storage::DATA_SPEED_2, result.data.charAt(2));
        return "";
    }
    if (query.startsWith("/")) {
        query = query.substring(1);
    }

    if (query == "debug-rst" && result.type != Type::HTTP) {
        currentDbg = maxClients;
        return "";
    } else if (query.startsWith("get")) {
        auto [sType, baseI] = utils::getNext(query, "-", 4);
        auto [sId, _] = utils::getNext(query, "-", baseI);
        // getDebugStream()->printf("reading %s:%s\r\n", sType, sId);
        int baseDataIdx = utils::dataName2dataStartIdx(sType);
        if (baseDataIdx == -1)
            return responseGenerator::getResponseGenerally(sourceType, "Error", "No such data");

        int dataIdx = baseDataIdx + sId.toInt();
        return responseGenerator::getResponseGenerally(sourceType, sType + "-" + sId, String(data_storage::getData(dataIdx)), responseGenerator::RESPONSE_GENERATOR_FLAG_SIMPLE);
    } else if (query.startsWith("set")) {
        auto [sType, baseI] = utils::getNext(query, "-", 4);
        auto [sId, _] = utils::getNext(query, "-", baseI);
        int baseDataIdx = utils::dataName2dataStartIdx(sType);
        if (baseDataIdx == -1)
            return responseGenerator::getResponseGenerally(sourceType, "Error", "No such data");
        int dataIdx = baseDataIdx + sId.toInt();
        int value = result.data.toInt();
        data_storage::setData(dataIdx, value);
        return responseGenerator::getResponseGenerally(sourceType, "Done", "");
    } else if (query.startsWith("setonly")) {
        auto [sType, baseI] = utils::getNext(query, "-", 8);
        auto [sId, _] = utils::getNext(query, "-", baseI);
        int baseDataIdx = utils::dataName2dataStartIdx(sType);
        if (baseDataIdx == -1)
            return responseGenerator::getResponseGenerally(sourceType, "Error", "No such data");

        int dataIdx = baseDataIdx + sId.toInt();
        int value = result.data.toInt();
        data_storage::setData(dataIdx, value, false);
        return responseGenerator::getResponseGenerally(sourceType, "Done", "");
    } else if (query == "current") {
        String d = currentData;
        if (result.type == Type::HTTP) {
            return responseGenerator::getResponseGenerally(result.type, "current", utils::multiBytes2JSON(d, 0),
                                                           responseGenerator::RESPONSE_GENERATOR_FLAG_SIMPLE | responseGenerator::RESPONSE_GENERATOR_FLAG_NO_TITLE);
        }
        return responseGenerator::getResponseGenerally(result.type, "current", d);
    } else if (query.startsWith("command")) {
        Control::controlCommand(result.data);
        return responseGenerator::getResponseGenerally(result.type, "OK", "");
    } else if (query == "" && result.type == Type::HTTP) {
        return responseGenerator::getResponseGenerally(
            Type::HTTP, "",
            "<!DOCTYPE html><html lang=\"zh\"><head><meta charset=\"UTF-8\" /><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\" /><link rel=\"stylesheet\" "
            "href=\"https://xypp.cc/acar/index.css\"><title>DATA</title></head><body><div class=\"sensor-container\" id=\"sensors\"></div><div class=\"control-container\" "
            "id=\"controls\"></div><div class=\"value-container\" "
            "id=\"values\"></div><script src=\"https://xypp.cc/acar/index.js\"></script></body></html>",
            responseGenerator::RESPONSE_GENERATOR_FLAG_SIMPLE | responseGenerator::RESPONSE_GENERATOR_FLAG_NO_TITLE);
    } else if (query == "network") {
        int idx = result.data.indexOf(":::");
        if (idx != -1) {
            String ssid = result.data.substring(0, idx);
            String pass = result.data.substring(idx + 3);
            startConnection(ssid, pass);
            return responseGenerator::getResponseGenerally(sourceType, "Forming connection to", ssid + ":" + pass);
        }
        return responseGenerator::getResponseGenerally(sourceType, "No data passed", "");
    } else if (query == "networkStatus") {
        return responseGenerator::getResponseGenerally(sourceType, "status", wlanStatus == 0 ? "idle" : wlanStatus == 1 ? "connecting" : wlanStatus == 3 ? "success" : "fail");
    } else if (query.startsWith("net.html") && result.type == Type::HTTP) {
        return responseGenerator::getHttpBasic(W_NET.length()) + W_NET;
    } else if (query == "scan" && result.type == Type::HTTP) {
        int res = WiFi.scanNetworks();
        String ret = "[";
        for (int i = 0; i < res; i++) {
            ret += "\"" + WiFi.SSID(i) + "\"";
            if (i != res - 1) {
                ret += ",";
            }
        }
        ret += "]";
        return responseGenerator::getHttpBasic(ret.length()) + ret;
    } else if (result.type == Type::HTTP) {
        return responseGenerator::getResponseGenerally(Type::HTTP, "Redirecting",
                                                       "<script>location.href='http://jump.xypp.cc/net.html?ip=" + wlanIp + "&ssid=" + WiFi.SSID() + "';</script>");
    } else
        return responseGenerator::getResponseGenerally(sourceType, "ERROR", "Unknown query");
}

void startConnection(String ssid, String pass) {
    WiFi.begin(ssid, pass);
    isWlanChecking = 30;
    storePass = pass;
    wlanStatus = 1;
}
void setup() {
    delay(1000);
    DEV_SERIAL.begin(115200);
    SUB_SERIAL.begin(115200);
    data_storage::init();
    String wlan = "";
    WiFi.mode(WIFI_AP_STA);
    WiFi.softAP("TERMINAL_NETWORK_CONFIG");
    if (wlan.length() != 0) {
        int idx = wlan.indexOf(":::");
        if (idx != -1) {
            String ssid = wlan.substring(0, idx);
            String pass = wlan.substring(idx + 3);
            startConnection(ssid, pass);
        }
    }
    server.begin();
    WiFi.softAPIP().printTo(*getDebugStream());
    DEV_SERIAL.println();
    dnsServer.start(53, "*", WiFi.softAPIP());
    Control::init();
    data_storage::setData(data_storage::DATA_START, 0);
    delay(1000);
}
unsigned sepDatas = 0;
unsigned long last = 0;
int accurateTime = 0;
int timeLoop = 0;
int lastTime_l1000 = 0;
int lastTime_100 = 0;
int loopCount_60s = 0;
int loopCount_500ms = 0;
void loop() {
    dnsServer.processNextRequest();
    unsigned long now = millis();
    if (now > last && last != 0) {
        // Serial.printf("%d -> %d [acc=%d;timeLoop=%d,lastTimeL=%d]\n", last, now, accurateTime, timeLoop, lastTime_l1000);
        accurateTime += (now - last);
        if (accurateTime > 100) {
            timeLoop += accurateTime / 100;
            accurateTime %= 100;
            timeLoop %= 10000;
        }

        // 1000ms准确定时器部分
        if ((int)(timeLoop / 10) != lastTime_l1000) {
            // 如果计时器未完成：继续计时
            int tmp = data_storage::getData(data_storage::DATA_TIME);
            if (tmp > 0) {
                tmp -= ((timeLoop - lastTime_l1000 * 10 + 10000) % 10000) / 10;
                if (tmp < 0)
                    tmp = 0;
                data_storage::setData(data_storage::DATA_TIME, tmp);
                if (tmp == 0) {
                    data_storage::setData(data_storage::DATA_START, 1);
                }
            }

            loopCount_60s += ((timeLoop - lastTime_l1000 * 10 + 10000) % 10000) / 10;
            if (loopCount_60s >= 60) {
                loopCount_60s %= 60;
                // 60S
            }

            lastTime_l1000 = timeLoop / 10;

            if (isWlanChecking) {
                isWlanChecking--;
                if (WiFi.status() == WL_CONNECTED) {
                    // data_storage::putGeneralData("wlan", WiFi.SSID() + ":::" + storePass);
                    String IP = WiFi.localIP().toString();
                    getDebugStream()->println(":WLan connected" + IP);
                    wlanIp = IP;
                    wlanStatus = 3;
                    isWlanChecking = 0;
                } else if (WiFi.status() == WL_NO_SSID_AVAIL || WiFi.status() == WL_CONNECT_FAILED) {
                    getDebugStream()->println("WLan connect fail");
                    wlanStatus = 2;
                    isWlanChecking = 0;
                } else {
                    getDebugStream()->println("...");
                }

                if (!isWlanChecking) {
                    if (WiFi.status() != WL_CONNECTED) {
                        WiFi.disconnect();
                        getDebugStream()->println("WLan connect fail");
                        wlanStatus = 2;
                        // data_storage::putGeneralData("wlan", "");
                    }
                }
            }
        }

        // 100ms准确定时器部分
        if (timeLoop != lastTime_100) {
            lastTime_100 = timeLoop;
            // Data 100ms
            if ((++loopCount_500ms) >= 5) {
                loopCount_500ms = 0;
                // Data 500ms
            }
        }
    }
    last = now;

    while (SUB_SERIAL.available()) {
        fromSerial2.nextChar(SUB_SERIAL.read());
        if (fromSerial2.isOK()) {
            String result = getResponseFor(fromSerial2.getResult(), Type::BINARY, &SUB_SERIAL);
            if (result != "")
                DEV_SERIAL.print(result);
            fromSerial2.clear();
        }
    }
    while (DEV_SERIAL.available()) {
        fromSUB_SERIAL.nextChar(DEV_SERIAL.read());
        if (fromSUB_SERIAL.isOK()) {
            String result = getResponseFor(fromSUB_SERIAL.getResult(), Type::BINARY, &DEV_SERIAL);
            if (result != "")
                DEV_SERIAL.print(result);
            fromSUB_SERIAL.clear();
        }
    }
    if (server.hasClient()) {
        bool accepted = false;
        for (int i = 0; i < maxClients; i++) {
            if (!client[i].connected()) {
                client[i] = server.available();
                isHttpClient[i] = false;
                accepted = true;
                break;
            }
        }
        if (!accepted) {
            server.available().stop();
        }
    }
    for (int i = 0; i < maxClients; i++) {
        if (client[i].connected()) {
            while (client[i].available()) {
                wifi[i].nextChar(client[i].read());
                if (wifi[i].isOK()) {
                    if (wifi[i].getResult().type == Type::HTTP)
                        isHttpClient[i] = true;
                    else
                        isHttpClient[i] = false;

                    if (wifi[i].getResult().query == "debug") {
                        currentDbg = i;
                        wifi[i].clear();
                        continue;
                    }
                    String result = getResponseFor(wifi[i].getResult(), wifi[i].getResult().type, &client[i]);
                    if (result != "")
                        client[i].print(result);
                    wifi[i].clear();
                    if (isHttpClient[i]) {
                        client[i].stop();
                    }
                }
            }
        }
    }

    Control::update(now);
}
