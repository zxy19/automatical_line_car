#ifndef MANAGELogin_H
#define MANAGELogin_H

#include <QDialog>

namespace Ui {
class ManageLogin;
}

class ManageLogin : public QDialog
{
    Q_OBJECT

public:
    explicit ManageLogin(QWidget *parent = 0,bool registerNewUser = false);
    ~ManageLogin();

private slots:
    void on_btn_ok_clicked();

private:
    Ui::ManageLogin *ui;
    bool isReg;
};

#endif // MANAGELogin_H
