#ifndef USERMANAGE_H
#define USERMANAGE_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
namespace Ui {
class UserManage;
}

class UserManage : public QWidget
{
    Q_OBJECT

public:
    explicit UserManage(QWidget *parent = 0);
    ~UserManage();

private slots:
    void on_btn_commit_clicked();

    void on_btn_rollback_clicked();

    void on_btn_addrow_clicked();

    void on_pushButton_2_clicked();

    void onDataChanged(const QModelIndex &index, const QModelIndex &bottomRight, const QVector<int> &roles);

private:
    Ui::UserManage *ui;
    QSqlTableModel *model;
};

#endif // USERMANAGE_H
