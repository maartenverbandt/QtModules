#-------------------------------------------------
#
# Project created by QtCreator 2016-02-18T09:02:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QMicroOSAnalyzer
TEMPLATE = app
# LIBS += -L/usr/local/lib/ -lmatio


SOURCES += main.cpp\
        qmicroosanalyzer.cpp \
    qgpiowidget.cpp \
    qthreadingwidget.cpp \
    qloggerdialog.cpp \
    ballbotdialog.cpp \
    ballbotconfigdialog.cpp

HEADERS  += qmicroosanalyzer.h \
    qgpiowidget.h \
    qthreadingwidget.h \
    qloggerdialog.h \
    ballbotdialog.h \
    ballbotconfigdialog.h

FORMS    += qmicroosanalyzer.ui \
    qgpiowidget.ui \
    qloggerdialog.ui \
    ballbotdialog.ui

include(../../QMavlinkConnection/src/qmavlinkconnection.pri)
include( ../../QRobotConfigDialog/src/qrobotconfigdialog.pri)
