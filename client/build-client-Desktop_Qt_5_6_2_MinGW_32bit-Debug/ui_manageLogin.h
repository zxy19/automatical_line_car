/********************************************************************************
** Form generated from reading UI file 'manageLogin.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGELOGIN_H
#define UI_MANAGELOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ManageLogin
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLineEdit *ipt_account;
    QLabel *label_2;
    QLineEdit *ipt_password;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btn_ok;
    QPushButton *btn_close;

    void setupUi(QDialog *ManageLogin)
    {
        if (ManageLogin->objectName().isEmpty())
            ManageLogin->setObjectName(QStringLiteral("ManageLogin"));
        ManageLogin->resize(400, 300);
        verticalLayout = new QVBoxLayout(ManageLogin);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(ManageLogin);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        ipt_account = new QLineEdit(ManageLogin);
        ipt_account->setObjectName(QStringLiteral("ipt_account"));

        verticalLayout_2->addWidget(ipt_account);

        label_2 = new QLabel(ManageLogin);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        ipt_password = new QLineEdit(ManageLogin);
        ipt_password->setObjectName(QStringLiteral("ipt_password"));
        ipt_password->setEchoMode(QLineEdit::Password);

        verticalLayout_2->addWidget(ipt_password);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        btn_ok = new QPushButton(ManageLogin);
        btn_ok->setObjectName(QStringLiteral("btn_ok"));

        horizontalLayout_2->addWidget(btn_ok);

        btn_close = new QPushButton(ManageLogin);
        btn_close->setObjectName(QStringLiteral("btn_close"));

        horizontalLayout_2->addWidget(btn_close);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(ManageLogin);

        QMetaObject::connectSlotsByName(ManageLogin);
    } // setupUi

    void retranslateUi(QDialog *ManageLogin)
    {
        ManageLogin->setWindowTitle(QApplication::translate("ManageLogin", "Dialog", 0));
        label->setText(QApplication::translate("ManageLogin", "\350\264\246\345\217\267", 0));
        label_2->setText(QApplication::translate("ManageLogin", "\345\257\206\347\240\201", 0));
        ipt_password->setInputMask(QString());
        btn_ok->setText(QApplication::translate("ManageLogin", "OK", 0));
        btn_close->setText(QApplication::translate("ManageLogin", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class ManageLogin: public Ui_ManageLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGELOGIN_H
