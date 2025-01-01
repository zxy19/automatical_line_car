#include "debugwindow.h"
#include "ui_debugwindow.h"
#include "responseGenerator.h"

DebugWindow::DebugWindow(QWidget *parent,QString target) :
    QWidget(parent),
    ui(new Ui::DebugWindow)
{
    ui->setupUi(this);
    this->socket = new QTcpSocket(this);
    QStringList ipSeg = target.split(":");
    if(ipSeg.length()!=2){
        this->close();
        return;
    }
    QString address = ipSeg.at(0);
    int port = ipSeg.at(1).toInt();
    this->socket->connectToHost(address,port,QTcpSocket::ReadWrite);
    connect(socket,SIGNAL(connected()),this,SLOT(connected()));
    connect(socket,SIGNAL(disconnected()),this,SLOT(disconnect()));
}

DebugWindow::~DebugWindow()
{
    this->socket->close();
    delete ui;
}

void DebugWindow::connected(){
    connect(socket,SIGNAL(readyRead()),this,SLOT(readyread()));
    sendNetworkIfAvailable("debug","");
}
void DebugWindow::disconnect(){
    this->socket = 0;
    this->ui->textBrowser->append("\r\n\r\n===================\r\nDISCONNECTED!");
}

void DebugWindow::readyread(){
    QByteArray arr=this->socket->readAll();
    this->ui->textBrowser->append(QString::fromLatin1(arr.data(),arr.size()));
}
void DebugWindow::sendNetworkIfAvailable(QString query,QString data){
    if(!this->socket)return;
    QByteArray qb;
    qb.append(responseGenerator::getResponseGenerally(Type::STRING,query,data,0));
    socket->write(qb);
}

void DebugWindow::on_lineEdit_2_returnPressed()
{
    this->ui->lineEdit->focusWidget();
}

void DebugWindow::on_lineEdit_returnPressed()
{
    this->ui->textBrowser->append("\r\n>>query="+this->ui->lineEdit_2->text()+"\r\n>> data="+this->ui->lineEdit->text()+"\r\n");
    this->sendNetworkIfAvailable(this->ui->lineEdit_2->text(),this->ui->lineEdit->text());
    this->ui->lineEdit_2->setText("");
    this->ui->lineEdit->setText("");
    this->ui->lineEdit_2->focusWidget();
}
