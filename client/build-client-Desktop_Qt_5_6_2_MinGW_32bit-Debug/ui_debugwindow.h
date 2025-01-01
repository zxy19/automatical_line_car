/********************************************************************************
** Form generated from reading UI file 'debugwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEBUGWINDOW_H
#define UI_DEBUGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DebugWindow
{
public:
    QVBoxLayout *verticalLayout;
    QTextBrowser *textBrowser;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *DebugWindow)
    {
        if (DebugWindow->objectName().isEmpty())
            DebugWindow->setObjectName(QStringLiteral("DebugWindow"));
        DebugWindow->resize(400, 300);
        verticalLayout = new QVBoxLayout(DebugWindow);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        textBrowser = new QTextBrowser(DebugWindow);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        verticalLayout->addWidget(textBrowser);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lineEdit = new QLineEdit(DebugWindow);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout->addWidget(lineEdit, 1, 1, 1, 1);

        lineEdit_2 = new QLineEdit(DebugWindow);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 0, 1, 1, 1);

        label = new QLabel(DebugWindow);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(DebugWindow);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(DebugWindow);

        QMetaObject::connectSlotsByName(DebugWindow);
    } // setupUi

    void retranslateUi(QWidget *DebugWindow)
    {
        DebugWindow->setWindowTitle(QApplication::translate("DebugWindow", "Form", 0));
        label->setText(QApplication::translate("DebugWindow", "Query", 0));
        label_2->setText(QApplication::translate("DebugWindow", "Data", 0));
    } // retranslateUi

};

namespace Ui {
    class DebugWindow: public Ui_DebugWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEBUGWINDOW_H
