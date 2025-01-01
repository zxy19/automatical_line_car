#include "usermanage.h"
#include "ui_usermanage.h"
#include "db.h"
#include "util.h"

UserManage::UserManage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserManage)
{
    ui->setupUi(this);
    model = new QSqlTableModel(this,db::database);
    model->setTable("users");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    ui->tableView->setModel(model);
    connect(model,&QSqlTableModel::dataChanged,this,&UserManage::onDataChanged);
}

UserManage::~UserManage()
{
    delete ui;
}

void UserManage::on_btn_commit_clicked()
{
    model->database().transaction(); //开始事务操作
     if (model->submitAll()) {
        model->database().commit(); //提交
     } else {
        model->database().rollback(); //回滚
        QMessageBox::warning(this, tr("tableModel"),tr("数据库错误: %1").arg(model->lastError().text()));
     }
}

void UserManage::on_btn_rollback_clicked()
{
    model->revertAll();
}

void UserManage::on_btn_addrow_clicked()
{
    int rowNum = model->rowCount(); //获得表的行数
    model->insertRow(rowNum); //添加一行
}

void UserManage::on_pushButton_2_clicked()
{
    int curRow = ui->tableView->currentIndex().row();
     model->removeRow(curRow);
     int ok = QMessageBox::warning(this,tr("删除当前行!"),tr("你确定删除当前行吗？"),QMessageBox::Yes,QMessageBox::No);
     if(ok == QMessageBox::No)
     {
        model->revertAll(); //如果不删除，则撤销
     }
     else {
         model->submitAll();
     } //否则提交，在数据库中删除该行
}

bool isInStack = false;
void UserManage::onDataChanged(const QModelIndex &index, const QModelIndex &bottomRight, const QVector<int> &roles)
{
    if(isInStack)return;
    isInStack = true;
    if(index.column() == 2){
        QString md5Pass = util::getPasswordHash(index.data().toString());
        model->setData(index,md5Pass);
    }
    isInStack = false;
}
