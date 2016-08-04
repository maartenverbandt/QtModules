QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TARGET = QSimpleRobotConfig
CONFIG += console
CONFIG += app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    qsimplerobotconfig.cpp

include(../../src/qrobotconfigdialog.pri)

HEADERS += \
    qsimplerobotconfig.h
