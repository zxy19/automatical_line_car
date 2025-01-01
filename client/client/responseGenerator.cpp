#include "responseGenerator.h"
#include "QString"
QString responseGenerator::getResponseGenerally(Type type, QString title, QString data,int flag) {

    switch (type) {
    case Type::BINARY: {
        int len;
        char buffer[15];
        buffer[0] = 0x01;
        buffer[1] = 0x02;
        len = title.length();
        buffer[2] = (len >> 24) & (0xff);
        buffer[3] = (len >> 16) & (0xff);
        buffer[4] = (len >> 8) & (0xff);
        buffer[5] = (len) & (0xff);
        buffer[6] = 0;
        len = data.length();
        buffer[7] = (len >> 24) & (0xff);
        buffer[8] = (len >> 16) & (0xff);
        buffer[9] = (len >> 8) & (0xff);
        buffer[10] = (len) & (0xff);
        buffer[11] = 0;
        return QString::fromLatin1(buffer, 6) + title + QString::fromLatin1(buffer + 7, 4) + data;
    }
    case Type::CSV:
        return title + "," + data;
    case Type::STRING:
        return "DATA" + title + "\n" + data;
    case Type::HTTP: {
        QString response = "<html><head><title>" + title + "</title><meta charset=\"UTF-8\" /></head><body><h1>" + title + "</h1><p>" + data + "</p></body></html>";
        return "HTTP/1.1 200 OK\r\nContent-Type: "
               "text/html\r\nContent-length: " +
               QString::number(response.length()) + "\r\n\r\n" + response;
    }

    default:
        break;
    }
    return "";
}
