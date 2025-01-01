/********************************************************************************
** Form generated from reading UI file 'formviewer.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMVIEWER_H
#define UI_FORMVIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormViewer
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QProgressBar *progressBar;

    void setupUi(QWidget *FormViewer)
    {
        if (FormViewer->objectName().isEmpty())
            FormViewer->setObjectName(QStringLiteral("FormViewer"));
        FormViewer->resize(670, 475);
        verticalLayout = new QVBoxLayout(FormViewer);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tableView = new QTableView(FormViewer);
        tableView->setObjectName(QStringLiteral("tableView"));

        verticalLayout->addWidget(tableView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton = new QPushButton(FormViewer);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(FormViewer);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout);

        progressBar = new QProgressBar(FormViewer);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);

        verticalLayout->addWidget(progressBar);


        retranslateUi(FormViewer);

        QMetaObject::connectSlotsByName(FormViewer);
    } // setupUi

    void retranslateUi(QWidget *FormViewer)
    {
        FormViewer->setWindowTitle(QApplication::translate("FormViewer", "Form", 0));
        pushButton->setText(QApplication::translate("FormViewer", "\344\277\235\345\255\230Excel", 0));
        pushButton_2->setText(QApplication::translate("FormViewer", "\344\277\235\345\255\230CSV", 0));
    } // retranslateUi

};

namespace Ui {
    class FormViewer: public Ui_FormViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMVIEWER_H
