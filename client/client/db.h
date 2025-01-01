#ifndef DB_H
#define DB_H
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
namespace db{
    extern QSqlDatabase database;
    extern bool firstVisit;
    bool init();
    bool addUser(QString user,QString password);
    bool checkUser(QString user,QString password);
    bool setAddr(QString user,QString data);
    QString getAddr(QString user);
}
#endif // DB_H
