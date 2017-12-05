QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

PROTOCOL = mavlink
INCLUDEPATH += $$PWD
DEFINES += QT_NO_PRINTER

HEADERS += \
    qrobotmainwindow.h \
    qaboutdialog.h

SOURCES += \
    main.cpp \
    qrobotmainwindow.cpp \
    qaboutdialog.cpp

include(../../src/qrobotoverview.pri)

FORMS += \
    qaboutdialog.ui
