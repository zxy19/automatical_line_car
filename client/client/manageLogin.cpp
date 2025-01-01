#include "manageLogin.h"
#include "ui_manageLogin.h"
#include "db.h"
#include "varibles.h"
ManageLogin::ManageLogin(QWidget *parent,bool registerNewUser) :
    QDialog(parent),
    ui(new Ui::ManageLogin),
    isReg(registerNewUser)
{
    ui->setupUi(this);
    if(isReg){
        this->setWindowTitle("注册");
    }else{
        this->setWindowTitle("登录");
    }
}

ManageLogin::~ManageLogin()
{
    delete ui;
}

void ManageLogin::on_btn_ok_clicked()
{
    if(this->isReg){
        db::addUser(this->ui->ipt_account->text(),this->ui->ipt_password->text());
        username = this->ui->ipt_account->text();
        this->accept();
    }else{
        if(db::checkUser(this->ui->ipt_account->text(),this->ui->ipt_password->text())){
            username = this->ui->ipt_account->text();
            this->accept();
        }else{
            QMessageBox::information(this,"提示","用户名或密码错误");
        }
    }
}
