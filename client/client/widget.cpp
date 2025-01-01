#include "widget.h"
#include "ui_widget.h"
#include "manageLogin.h"
#include "db.h"
#include "usermanage.h"
#include <QVector>
#include <QTimer>
#include "responseGenerator.h"
#include "DataType.h"
#include <qlogging.h>
#include "varibles.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ManageLogin loginer(this,db::firstVisit);
    if (loginer.exec() != QDialog::Accepted)
    {
        this->close();
        exit(0);
        return;
    }
    ui->setupUi(this);
    ui->plot->addGraph();
    ui->plot->graph()->setPen(QPen(Qt::black));
    ui->plot->graph()->setBrush(QBrush(QColor(0, 0, 255, 20)));
    ui->plot->addGraph();
    ui->plot->graph()->setPen(QPen(Qt::black));
    ui->plot->graph()->setBrush(QBrush(QColor(0,255,0, 20)));
    ui->plot->axisRect()->setupFullAxesBox(true);
    ui->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    ui->horizontalScrollBar->setRange(-500,500);
    ui->verticalScrollBar->setRange(-500,500);
    connect(ui->horizontalScrollBar, SIGNAL(valueChanged(int)), this,SLOT(horzScrollBarChanged(int)));
    connect(ui->verticalScrollBar, SIGNAL(valueChanged(int)), this,SLOT(vertScrollBarChanged(int)));
    connect(ui->plot->xAxis, SIGNAL(rangeChanged(QCPRange)), this,SLOT(xAxisChanged(QCPRange)));
    connect(ui->plot->yAxis, SIGNAL(rangeChanged(QCPRange)), this,SLOT(yAxisChanged(QCPRange)));
    ui->plot->xAxis->setRange(0,20,Qt::AlignCenter);
    ui->plot->yAxis->setRange(0,20,Qt::AlignCenter);
    bufferLen=0;
    this->parser.clear();
    this->socket = nullptr;
    for(int i=0;i<20;i++){
        this->dataL[i] = this->dataR[i] = 0;
    }

    this->sensors[0] = (ui->status_sensor0);
    this->sensors[1] = (ui->status_sensor1);
    this->sensors[2] = (ui->status_sensor2);
    this->sensors[3] = (ui->status_sensor3);
    this->sensors[4] = (ui->status_sensor4);
    this->sensors[5] = (ui->status_sensor5);
    this->sensors[6] = (ui->status_sensor6);
    this->sensors[7] = (ui->status_sensor7);
    currentSendCommand = 0;

    this->paintTimer = new QTimer(this);
    connect(this->paintTimer,SIGNAL(timeout()),this,SLOT(paintTimeout()));

    this->syncTimer = new QTimer(this);
    connect(this->syncTimer,SIGNAL(timeout()),this,SLOT(syncTimeout()));

    gettingHistoryData = gettingLongTermData = false;

    this->ui->ipt_address->setText(db::getAddr(username));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    if(managePage == nullptr)managePage = new UserManage();
    if(!managePage->isVisible())managePage->show();
}


void Widget::horzScrollBarChanged(int value)
{
    if (qAbs(ui->plot->xAxis->range().center()-value/100.0) > 0.01)
    {
        ui->plot->xAxis->setRange(value/100.0, ui->plot->xAxis->range().size(),Qt::AlignCenter);
        ui->plot->replot();
    }
}
void Widget::vertScrollBarChanged(int value)
{
    if (qAbs(ui->plot->yAxis->range().center()+value/100.0) > 0.01) {
        ui->plot->yAxis->setRange(-value/100.0, ui->plot->yAxis->range().size(),Qt::AlignCenter);
        ui->plot->replot();
    }
}
void Widget::xAxisChanged(QCPRange range)
{
    ui->horizontalScrollBar->setValue(qRound(range.center()*100.0));
    ui->horizontalScrollBar->setPageStep(qRound(range.size()*100.0));
}
void Widget::yAxisChanged(QCPRange range)
{
    ui->verticalScrollBar->setValue(qRound(-range.center()*100.0));
    ui->verticalScrollBar->setPageStep(qRound(range.size()*100.0));
}


void Widget::addDataL(float data){
    for(int i=0;i<19;i++)this->dataL[20-i-1] = this->dataL[20-i-2];
    this->dataL[0]=data;
}
void Widget::addDataR(float data){
    for(int i=0;i<19;i++)this->dataR[20-i-1] = this->dataR[20-i-2];
    this->dataR[0]=data;
}
void Widget::updateGraph(){
    QVector<double> temp(20),tempa(20),tempb(20);
    for(int i=0;i<20;i++){
        temp[i] = i;
        tempa[i]=this->dataL[i];
        tempb[i]=this->dataR[i];
    }
    this->ui->plot->graph(0)->setData(temp,tempa);
    this->ui->plot->graph(1)->setData(temp,tempb);
    this->ui->plot->xAxis->setLabel("time");
    this->ui->plot->yAxis->setLabel("speed");
    this->ui->plot->xAxis->setRange(0,20);
    this->ui->plot->yAxis->setRange(0,100);
    this->ui->plot->replot();
}

void Widget::connected(){
    connect(socket,SIGNAL(readyRead()),this,SLOT(readyread()));
    db::setAddr(username,this->ui->ipt_address->text());
    this->syncTimer->start(50);
    this->paintTimer->start(1000);
    this->ui->btn_connect->setText("断开");
    sendNetworkIfAvailable("historyShort","");
}
void Widget::disconnect(){
    this->socket = 0;
    this->syncTimer->stop();
    this->paintTimer->stop();
    this->ui->btn_connect->setText("连接");
}

void Widget::readyread(){
    QByteArray arr=this->socket->readAll();
    for(int i=0;i<arr.length();i++){
        parser.nextChar(arr.at(i));
        if(parser.isOK()){
            data_parser::Result result = parser.getResult();
            emit onDataEvent(result);
            parser.clear();
        }
    }
}
void Widget::onDataEvent(data_parser::Result result){

    QString query = QString(result.query);
    QString data = QString(result.data);
    if(query.startsWith("sensor-")){
        int id = query.split("-").at(1).toInt();
        if(id >= 0 && id <= 7){
            this->sensors[id]->setChecked(data == "1");
            this->sensors[id]->setEnabled(true);
        }
    }else if(query.startsWith("speed-")){
        int id = query.split("-").at(1).toInt();
        int value = data.toInt();
        QSpinBox *edit = nullptr;
        if(id == 0){
            edit = this->ui->status_speed_0;
        }else if(id == 1){
            edit = this->ui->status_speed_1;
        }else if(id == 2){
            edit = this->ui->status_speed_2;
        }
        if(edit == nullptr)return;
        if(id != 0){
            edit->setValue(value);
        }else if(edit != this->focusWidget()){
            edit->setValue(value);
        }
        edit->setEnabled(true);
        if(id == 1)this->addDataL(value);
        else if(id == 2)this->addDataR(value);
    }else if(query.startsWith("states")){
        this->ui->pushButton_2->setEnabled(true);
        if(data == "1"){
            this->ui->pushButton_2->setText("停止");
        }else{
            this->ui->pushButton_2->setText("启动");
        }
    }else if(query.startsWith("time")){
        if(this->focusWidget() == this->ui->status_timer)
            return;
        ui->status_timer->setValue(data.toInt());
        ui->status_timer->setEnabled(true);
    }else if(query.startsWith("pid")){
        int id = query.split("-").at(1).toInt();
        int value = data.toInt();
        QSpinBox *edit = nullptr;
        if(id == 0){
            edit = this->ui->status_pid_0;
        }else if(id == 1){
            edit = this->ui->status_pid_1;
        }else if(id == 2){
            edit = this->ui->status_pid_2;
        }
        if(edit == nullptr)return;
        if(edit != this->focusWidget()){
            edit->setValue(value);
        }
        edit->setEnabled(true);
    }else if(query == "current"){
        if(result.data.length() < 3)return;
        QString sensorStr = "";
        uint8_t d = result.data.at(0);
        for(int i=0;i<8;i++){
            sensors[i]->setChecked((d>>i)&0x01);
        }
        this->ui->status_speed_1->setValue((int)result.data.at(1));
        this->ui->status_speed_2->setValue((int)result.data.at(2));
        addListItem(result.data,0);
    }else if(query == "history"){
        if(gettingHistoryData){
            this->gettingHistoryData = false;
            showForm(result.data);
        }else{
            for(int i=0;i+2<data.length();i+=3){
                addListItem(result.data,i);
                addDataL((int)result.data.at(i+1));
                addDataR((int)result.data.at(i+2));
            }
        }
    }else if(query == "longTerm"){
        if(gettingLongTermData){
            this->gettingLongTermData = false;
            showForm(result.data);
        }
    }
}
void Widget::addListItem(QByteArray data,int i){
    QString sensorStr = "";
    uint8_t d = data.at(i);
    for(int i=0;i<8;i++){
        sensorStr += ((d>>i)&0x01)?"#":"_";
    }
    if(this->ui->listWidget->count() > 100)
        this->ui->listWidget->removeItemWidget(this->ui->listWidget->item(99));
    this->ui->listWidget->insertItem(0,"Speed["
                                  +QString::number((int)data.at(i+1))
                                  +","
                                  +QString::number((int)data.at(i+2))
                                  +"] Sensors["
                                  +sensorStr
                                  +"]");
}

void Widget::on_btn_connect_clicked()
{
    if(this->socket && this->socket->isOpen()){
        this->socket->close();
        this->ui->btn_connect->setText("连接");
        return;
    }
    this->socket = new QTcpSocket(this);
    QStringList ipSeg = this->ui->ipt_address->text().split(":");
    if(ipSeg.length()!=2)return;
    address = ipSeg.at(0);
    port = ipSeg.at(1).toInt();
    this->socket->connectToHost(address,port,QTcpSocket::ReadWrite);
    this->ui->btn_connect->setText("...");
    connect(socket,SIGNAL(connected()),this,SLOT(connected()));
    connect(socket,SIGNAL(disconnected()),this,SLOT(disconnect()));
}

void Widget::on_pushButton_2_clicked()
{
    if(ui->pushButton_2->text() == "启动"){
        this->sendNetworkIfAvailable("set-states-0","1");
    }else{
        this->sendNetworkIfAvailable("set-states-0","0");
    }
}

void Widget::sendNetworkIfAvailable(QString query,QString data){
    if(!this->socket)return;
    QByteArray qb;
    qb.append(responseGenerator::getResponseGenerally(Type::BINARY,query,data,0));
    socket->write(qb);
}
const QString sendCommands[]={
    "get-speed-0",
    "get-pid-0",
    "get-pid-1",
    "get-pid-2",
    "get-time-0",
    "get-states-0",
    "current"
};
void Widget::syncTimeout(){
    this->sendNetworkIfAvailable(sendCommands[this->currentSendCommand],"");
    currentSendCommand++;
    currentSendCommand%=7;
}
void Widget::paintTimeout(){
    this->addDataL(this->ui->status_speed_1->value());
    this->addDataR(this->ui->status_speed_2->value());
    this->updateGraph();
}


void Widget::on_status_timer_editingFinished()
{
    this->sendNetworkIfAvailable("set-time-0",QString::number(this->ui->status_timer->value()));
    this->ui->ipt_address->setFocus();
}

void Widget::on_status_speed_0_editingFinished()
{
    this->sendNetworkIfAvailable("set-speed-0",QString::number(this->ui->status_speed_0->value()));
    this->ui->ipt_address->setFocus();
}

void Widget::showForm(QByteArray ba){
    if(this->formViewer != nullptr){
        this->formViewer->close();
    }
    this->formViewer = new FormViewer(nullptr,ba);
    this->formViewer->show();
}

void Widget::on_pushButton_4_clicked()
{
    this->gettingHistoryData = true;
    this->sendNetworkIfAvailable("history","");
}

void Widget::on_pushButton_5_clicked()
{
    this->gettingLongTermData = true;
    this->sendNetworkIfAvailable("longTerm","");
}

void Widget::on_status_pid_0_editingFinished()
{
    this->sendNetworkIfAvailable("set-pid-0",QString::number(this->ui->status_pid_0->value()));
    this->ui->ipt_address->setFocus();
}

void Widget::on_status_pid_1_editingFinished()
{
    this->sendNetworkIfAvailable("set-pid-1",QString::number(this->ui->status_pid_1->value()));
    this->ui->ipt_address->setFocus();
}

void Widget::on_status_pid_2_editingFinished()
{
    this->sendNetworkIfAvailable("set-pid-2",QString::number(this->ui->status_pid_2->value()));
    this->ui->ipt_address->setFocus();
}

void Widget::on_pushButton_3_clicked()
{
    if(this->dbgWin != nullptr){
        this->dbgWin->close();
    }
    this->dbgWin = new DebugWindow(nullptr,this->ui->ipt_address->text());
    this->dbgWin->show();
}
