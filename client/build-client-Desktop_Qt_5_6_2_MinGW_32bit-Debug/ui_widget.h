/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLineEdit *ipt_address;
    QPushButton *btn_connect;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_2;
    QSpinBox *status_pid_0;
    QCheckBox *status_sensor3;
    QCheckBox *status_sensor0;
    QSpinBox *status_speed_1;
    QCheckBox *status_sensor4;
    QCheckBox *status_sensor2;
    QLabel *label_2;
    QCheckBox *status_sensor6;
    QSpinBox *status_speed_0;
    QSpinBox *status_speed_2;
    QCheckBox *status_sensor1;
    QCheckBox *status_sensor5;
    QLabel *label_6;
    QSpinBox *status_timer;
    QCheckBox *status_sensor7;
    QLabel *label_8;
    QPushButton *pushButton_2;
    QSpinBox *status_pid_1;
    QSpinBox *status_pid_2;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_3;
    QListWidget *listWidget;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QCustomPlot *plot;
    QScrollBar *verticalScrollBar;
    QScrollBar *horizontalScrollBar;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(746, 434);
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        groupBox_3 = new QGroupBox(Widget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout_2 = new QVBoxLayout(groupBox_3);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(groupBox_3);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        ipt_address = new QLineEdit(groupBox_3);
        ipt_address->setObjectName(QStringLiteral("ipt_address"));

        verticalLayout_2->addWidget(ipt_address);

        btn_connect = new QPushButton(groupBox_3);
        btn_connect->setObjectName(QStringLiteral("btn_connect"));

        verticalLayout_2->addWidget(btn_connect);


        horizontalLayout_4->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(Widget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        gridLayout_2 = new QGridLayout(groupBox_4);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        status_pid_0 = new QSpinBox(groupBox_4);
        status_pid_0->setObjectName(QStringLiteral("status_pid_0"));
        status_pid_0->setEnabled(false);
        status_pid_0->setMaximum(1000);

        gridLayout_2->addWidget(status_pid_0, 3, 1, 1, 1);

        status_sensor3 = new QCheckBox(groupBox_4);
        status_sensor3->setObjectName(QStringLiteral("status_sensor3"));

        gridLayout_2->addWidget(status_sensor3, 0, 3, 1, 1);

        status_sensor0 = new QCheckBox(groupBox_4);
        status_sensor0->setObjectName(QStringLiteral("status_sensor0"));

        gridLayout_2->addWidget(status_sensor0, 0, 0, 1, 1);

        status_speed_1 = new QSpinBox(groupBox_4);
        status_speed_1->setObjectName(QStringLiteral("status_speed_1"));
        status_speed_1->setEnabled(false);
        status_speed_1->setMaximum(1000);

        gridLayout_2->addWidget(status_speed_1, 2, 1, 1, 1);

        status_sensor4 = new QCheckBox(groupBox_4);
        status_sensor4->setObjectName(QStringLiteral("status_sensor4"));

        gridLayout_2->addWidget(status_sensor4, 0, 4, 1, 1);

        status_sensor2 = new QCheckBox(groupBox_4);
        status_sensor2->setObjectName(QStringLiteral("status_sensor2"));

        gridLayout_2->addWidget(status_sensor2, 0, 2, 1, 1);

        label_2 = new QLabel(groupBox_4);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 2, 0, 1, 1);

        status_sensor6 = new QCheckBox(groupBox_4);
        status_sensor6->setObjectName(QStringLiteral("status_sensor6"));

        gridLayout_2->addWidget(status_sensor6, 1, 2, 1, 1);

        status_speed_0 = new QSpinBox(groupBox_4);
        status_speed_0->setObjectName(QStringLiteral("status_speed_0"));
        status_speed_0->setEnabled(false);
        status_speed_0->setMaximum(1000);

        gridLayout_2->addWidget(status_speed_0, 2, 4, 1, 1);

        status_speed_2 = new QSpinBox(groupBox_4);
        status_speed_2->setObjectName(QStringLiteral("status_speed_2"));
        status_speed_2->setEnabled(false);
        status_speed_2->setMaximum(1000);

        gridLayout_2->addWidget(status_speed_2, 2, 2, 1, 1);

        status_sensor1 = new QCheckBox(groupBox_4);
        status_sensor1->setObjectName(QStringLiteral("status_sensor1"));

        gridLayout_2->addWidget(status_sensor1, 0, 1, 1, 1);

        status_sensor5 = new QCheckBox(groupBox_4);
        status_sensor5->setObjectName(QStringLiteral("status_sensor5"));

        gridLayout_2->addWidget(status_sensor5, 1, 1, 1, 1);

        label_6 = new QLabel(groupBox_4);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_2->addWidget(label_6, 4, 3, 1, 1);

        status_timer = new QSpinBox(groupBox_4);
        status_timer->setObjectName(QStringLiteral("status_timer"));
        status_timer->setEnabled(false);
        status_timer->setMaximum(1000000);

        gridLayout_2->addWidget(status_timer, 4, 4, 1, 1);

        status_sensor7 = new QCheckBox(groupBox_4);
        status_sensor7->setObjectName(QStringLiteral("status_sensor7"));

        gridLayout_2->addWidget(status_sensor7, 1, 3, 1, 1);

        label_8 = new QLabel(groupBox_4);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_2->addWidget(label_8, 2, 3, 1, 1);

        pushButton_2 = new QPushButton(groupBox_4);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setEnabled(false);

        gridLayout_2->addWidget(pushButton_2, 4, 0, 1, 1);

        status_pid_1 = new QSpinBox(groupBox_4);
        status_pid_1->setObjectName(QStringLiteral("status_pid_1"));
        status_pid_1->setEnabled(false);
        status_pid_1->setMaximum(1000);

        gridLayout_2->addWidget(status_pid_1, 3, 2, 1, 1);

        status_pid_2 = new QSpinBox(groupBox_4);
        status_pid_2->setObjectName(QStringLiteral("status_pid_2"));
        status_pid_2->setEnabled(false);
        status_pid_2->setMaximum(1000);

        gridLayout_2->addWidget(status_pid_2, 3, 3, 1, 1);

        label_3 = new QLabel(groupBox_4);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 3, 0, 1, 1);


        horizontalLayout_4->addWidget(groupBox_4);

        horizontalLayout_4->setStretch(0, 3);
        horizontalLayout_4->setStretch(1, 9);

        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        groupBox_2 = new QGroupBox(Widget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        horizontalLayout_3 = new QHBoxLayout(groupBox_2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        listWidget = new QListWidget(groupBox_2);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        horizontalLayout_3->addWidget(listWidget);


        horizontalLayout_2->addWidget(groupBox_2);

        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        plot = new QCustomPlot(groupBox);
        plot->setObjectName(QStringLiteral("plot"));

        gridLayout->addWidget(plot, 0, 0, 1, 1);

        verticalScrollBar = new QScrollBar(groupBox);
        verticalScrollBar->setObjectName(QStringLiteral("verticalScrollBar"));
        verticalScrollBar->setOrientation(Qt::Vertical);

        gridLayout->addWidget(verticalScrollBar, 0, 1, 1, 1);

        horizontalScrollBar = new QScrollBar(groupBox);
        horizontalScrollBar->setObjectName(QStringLiteral("horizontalScrollBar"));
        horizontalScrollBar->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalScrollBar, 1, 0, 1, 1);


        horizontalLayout_2->addWidget(groupBox);

        horizontalLayout_2->setStretch(0, 3);
        horizontalLayout_2->setStretch(1, 6);

        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_3 = new QPushButton(Widget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(Widget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        horizontalLayout->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(Widget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        horizontalLayout->addWidget(pushButton_5);

        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        groupBox_3->setTitle(QApplication::translate("Widget", "\350\277\236\346\216\245", 0));
        label->setText(QApplication::translate("Widget", "\350\277\236\346\216\245\345\210\260\346\234\215\345\212\241\345\231\250", 0));
        btn_connect->setText(QApplication::translate("Widget", "\350\277\236\346\216\245", 0));
        groupBox_4->setTitle(QApplication::translate("Widget", "\347\212\266\346\200\201", 0));
        status_sensor3->setText(QApplication::translate("Widget", "\347\201\260\345\272\2464", 0));
        status_sensor0->setText(QApplication::translate("Widget", "\347\201\260\345\272\2461", 0));
        status_sensor4->setText(QApplication::translate("Widget", "\347\201\260\345\272\2465", 0));
        status_sensor2->setText(QApplication::translate("Widget", "\347\201\260\345\272\2463", 0));
        label_2->setText(QApplication::translate("Widget", "\351\200\237\345\272\246\345\267\246/\351\200\237\345\272\246\345\217\263", 0));
        status_sensor6->setText(QApplication::translate("Widget", "\344\272\272\344\275\2232", 0));
        status_sensor1->setText(QApplication::translate("Widget", "\347\201\260\345\272\2462", 0));
        status_sensor5->setText(QApplication::translate("Widget", "\344\272\272\344\275\2231", 0));
        label_6->setText(QApplication::translate("Widget", "\345\256\232\346\227\266\345\231\250", 0));
        status_sensor7->setText(QApplication::translate("Widget", "\344\272\272\344\275\2233", 0));
        label_8->setText(QApplication::translate("Widget", "\350\256\276\347\275\256\351\200\237\345\272\246", 0));
        pushButton_2->setText(QApplication::translate("Widget", "\345\220\257\345\212\250", 0));
        label_3->setText(QApplication::translate("Widget", "PID", 0));
        groupBox_2->setTitle(QApplication::translate("Widget", "\346\225\260\346\215\256", 0));
        groupBox->setTitle(QApplication::translate("Widget", "\345\233\276\350\241\250", 0));
        pushButton_3->setText(QApplication::translate("Widget", "\350\260\203\350\257\225", 0));
        pushButton_4->setText(QApplication::translate("Widget", "\346\237\245\347\234\213\344\270\200\345\260\217\346\227\266\346\225\260\346\215\256\350\241\250", 0));
        pushButton_5->setText(QApplication::translate("Widget", "\346\237\245\347\234\213\344\270\211\346\227\245\346\225\260\346\215\256\350\241\250", 0));
        pushButton->setText(QApplication::translate("Widget", "\347\224\250\346\210\267\347\256\241\347\220\206\351\241\265\351\235\242", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
