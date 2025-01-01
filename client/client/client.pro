#-------------------------------------------------
#
# Project created by QtCreator 2024-05-19T23:36:03
#
#-------------------------------------------------

QT       += core gui sql network axcontainer

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = client
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    qcustomplot.cpp \
    db.cpp \
    util.cpp \
    consts.cpp \
    manageLogin.cpp \
    usermanage.cpp \
    DataParser.cpp \
    responseGenerator.cpp \
    formviewer.cpp \
    debugwindow.cpp

HEADERS  += widget.h \
    qcustomplot.h \
    db.h \
    util.h \
    consts.h \
    manageLogin.h \
    usermanage.h \
    responseGenerator.h \
    DataParser.h \
    DataType.h \
    formviewer.h \
    uieventthread.hpp \
    debugwindow.h \
    varibles.h

FORMS    += widget.ui \
    manageLogin.ui \
    usermanage.ui \
    formviewer.ui \
    debugwindow.ui
