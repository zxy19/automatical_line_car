#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "qcustomplot.h"
#include "DataParser.h"
#include "DataType.h"
#include <QtNetwork/QTcpSocket>
#include <QCheckBox>
#include "usermanage.h"
#include "formviewer.h"
#include "debugwindow.h"
#include <QByteArray>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_pushButton_clicked();
    void horzScrollBarChanged(int value);
    void vertScrollBarChanged(int value);
    void xAxisChanged(QCPRange range);
    void yAxisChanged(QCPRange range);
    void connected();
    void disconnect();
    void readyread();
    void syncTimeout();
    void paintTimeout();
    void on_btn_connect_clicked();
    void onDataEvent(data_parser::Result result);
    void on_pushButton_2_clicked();
    void sendNetworkIfAvailable(QString query,QString data);
    void on_status_timer_editingFinished();
    void on_status_speed_0_editingFinished();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_status_pid_0_editingFinished();

    void on_status_pid_1_editingFinished();

    void on_status_pid_2_editingFinished();

    void on_pushButton_3_clicked();

private:
    Ui::Widget *ui;

    UserManage *managePage=nullptr;
    FormViewer *formViewer=nullptr;
    DebugWindow *dbgWin = nullptr;
    double number;
    QString address;
    int port;
    QTcpSocket *socket;
    double dataL[20],dataR[20];
    char buffer[100];
    int bufferLen;
    int timerId;
    data_parser::Parser parser;
    QCheckBox *sensors[8];
    int currentSendCommand;
    QTimer *syncTimer,*paintTimer;
    bool gettingHistoryData,gettingLongTermData;

    void addDataL(float data);
    void addDataR(float data);
    void updateGraph();
    void showForm(QByteArray ba);
    void addListItem(QByteArray data,int i);
};

#endif // WIDGET_H
