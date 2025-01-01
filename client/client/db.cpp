#include "db.h"
#include "util.h"
#include <QVariant>
QSqlDatabase db::database;
bool db::firstVisit=false;
bool db::init()
{
     database = QSqlDatabase::addDatabase("QSQLITE");
     database.setDatabaseName("datebase.db");
     if (!database.open()) {
         QMessageBox::critical(0, "无法打开数据库文件","无法打开数据库文件", QMessageBox::Cancel);
         return false;
     }
     QSqlQuery query;
     bool toInit = true;
     if(query.exec("SELECT * from users")){
        if(query.next()){
            toInit = false;
        }
     }
     if(!query.exec("SELECT `addr` from users")){
        toInit = true;
     }
     if(toInit){
         query.exec("DROP TABLE `users`");
         query.exec("CREATE TABLE users ( \n"
                    "id INTEGER PRIMARY KEY AUTOINCREMENT, \n"
                    "username VARCHAR(20) UNIQUE, \n"
                    "password VARCHAR(32), \n"
                    "addr VARCHAR(128) \n"
                    ")");
         firstVisit = true;
     }
     return true;
}
bool db::addUser(QString user,QString password){
    QSqlQuery query;
    QString pw = util::getPasswordHash(password);
    query.prepare("INSERT INTO users (`username`, `password`) VALUES (:username, :password)");
    query.bindValue(":username", user);
    query.bindValue(":password", pw);
    return query.exec();
}
bool db::checkUser(QString user,QString password){
    QSqlQuery query;
    QString pw = util::getPasswordHash(password);
    query.prepare("SELECT COUNT(*) FROM users WHERE username = :username AND password = :password");
    query.bindValue(":username", user);
    query.bindValue(":password", pw);
    if (query.exec() && query.next()) {
        int count = query.value(0).toInt();
        return count > 0;
    } else {
        return false;
    }
}
bool db::setAddr(QString user,QString data){
    QSqlQuery query;
    query.prepare("UPDATE users SET `addr`=:address WHERE `username`=:username");
    query.bindValue(":username", user);
    query.bindValue(":address", data);
    return query.exec();
}
QString db::getAddr(QString user){
    QSqlQuery query;
    query.prepare("SELECT `addr` FROM users WHERE `username`=:username");
    query.bindValue(":username", user);
    if (query.exec() && query.next()) {
        return query.value(0).toString();
    } else {
        return "";
    }
}

