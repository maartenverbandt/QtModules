QT       += core gui gamepad
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

PROTOCOL += mavlink
DEFINES += QT_NO_PRINTER
INCLUDEPATH += $$PWD

HEADERS += \

SOURCES += \
    main.cpp

include(../../src/qparameterwidget.pri)
