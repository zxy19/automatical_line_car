#include "util.h"
#include "QCryptographicHash"
#include "consts.h"


QString util::getPasswordHash(QString pw){
    QByteArray ba;
    QCryptographicHash md(QCryptographicHash::Md5);
    ba.append(PASSWORD_SALT+pw+PASSWORD_SALT);
    md.addData(ba);
    return md.result().toHex();
}
