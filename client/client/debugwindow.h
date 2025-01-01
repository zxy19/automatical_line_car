#ifndef DEBUGWINDOW_H
#define DEBUGWINDOW_H

#include <QWidget>
#include <QTcpSocket>
namespace Ui {
class DebugWindow;
}

class DebugWindow : public QWidget
{
    Q_OBJECT

public:
    explicit DebugWindow(QWidget *parent = 0,QString target="");
    ~DebugWindow();

private:
    Ui::DebugWindow *ui;
    QTcpSocket *socket;
    void sendNetworkIfAvailable(QString query,QString data);
private slots:
    void connected();
    void disconnect();
    void readyread();
    void on_lineEdit_2_returnPressed();
    void on_lineEdit_returnPressed();
};

#endif // DEBUGWINDOW_H
