/********************************************************************************
** Form generated from reading UI file 'usermanage.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERMANAGE_H
#define UI_USERMANAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserManage
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_2;
    QPushButton *btn_addrow;
    QPushButton *btn_rollback;
    QPushButton *btn_commit;

    void setupUi(QWidget *UserManage)
    {
        if (UserManage->objectName().isEmpty())
            UserManage->setObjectName(QStringLiteral("UserManage"));
        UserManage->resize(400, 300);
        verticalLayout = new QVBoxLayout(UserManage);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tableView = new QTableView(UserManage);
        tableView->setObjectName(QStringLiteral("tableView"));

        verticalLayout->addWidget(tableView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_2 = new QPushButton(UserManage);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        btn_addrow = new QPushButton(UserManage);
        btn_addrow->setObjectName(QStringLiteral("btn_addrow"));

        horizontalLayout->addWidget(btn_addrow);

        btn_rollback = new QPushButton(UserManage);
        btn_rollback->setObjectName(QStringLiteral("btn_rollback"));

        horizontalLayout->addWidget(btn_rollback);

        btn_commit = new QPushButton(UserManage);
        btn_commit->setObjectName(QStringLiteral("btn_commit"));

        horizontalLayout->addWidget(btn_commit);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(UserManage);

        QMetaObject::connectSlotsByName(UserManage);
    } // setupUi

    void retranslateUi(QWidget *UserManage)
    {
        UserManage->setWindowTitle(QApplication::translate("UserManage", "Form", 0));
        pushButton_2->setText(QApplication::translate("UserManage", "\345\210\240\351\231\244\345\275\223\345\211\215\350\241\214", 0));
        btn_addrow->setText(QApplication::translate("UserManage", "\346\267\273\345\212\240\344\270\200\350\241\214", 0));
        btn_rollback->setText(QApplication::translate("UserManage", "\345\233\236\346\273\232", 0));
        btn_commit->setText(QApplication::translate("UserManage", "\346\217\220\344\272\244", 0));
    } // retranslateUi

};

namespace Ui {
    class UserManage: public Ui_UserManage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERMANAGE_H
