#ifndef FORMVIEWER_H
#define FORMVIEWER_H

#include <QWidget>
#include <QStandardItemModel>
#include <uieventthread.hpp>

namespace Ui {
class FormViewer;
}

class FormViewer : public QWidget
{
    Q_OBJECT

public:
    ~FormViewer();
    explicit FormViewer(QWidget *parent = 0,QByteArray formData=QByteArray(""));
    void doSaveCSV();
    void doSaveExcel();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
    void set_progress(int p);
    void set_finish();
    void error_fail_open();
signals:
    void sig_set_progress(int p);
    void sig_set_finish();
    void sig_error_fail_open();
private:
    Ui::FormViewer *ui;
    QStandardItemModel model;
    UiEventThread<FormViewer,void (FormViewer::*)()> *saveExcel,*saveCSV;

    QString fileName;
};
#endif // FORMVIEWER_H
