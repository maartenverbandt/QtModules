!contains( included_modules, $$PWD ) {
    included_modules += $$PWD
    message( "Including $$PWD" )

    QT += network

    INCLUDEPATH += $$PWD

    SOURCES +=  $$PWD/qgpiowidget.cpp \
                $$PWD/qthreadingwidget.cpp\
                $$PWD/qgeneraloutput.cpp \
                $$PWD/qgeneraloutputfloat.cpp \
                $$PWD/qgeneraloutputint.cpp

    HEADERS +=  $$PWD/qgpiowidget.h \
                $$PWD/qthreadingwidget.h\
                $$PWD/qgeneraloutput.h \
                $$PWD/qgeneraloutputfloat.h \
                $$PWD/qgeneraloutputint.h

    FORMS += $$PWD/qgpiowidget.ui

    DEFINES += QT_NO_PRINTER
    include(../../QCustomPlot/src/qcustomplot.pri)
} else {
    message( "Skipping $$PWD: already included" )
}
