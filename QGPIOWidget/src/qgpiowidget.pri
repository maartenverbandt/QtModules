!contains( included_modules, $$PWD ) {
    included_modules += $$PWD
    message( "Including $$PWD" )

    INCLUDEPATH += $$PWD

    SOURCES +=  $$PWD/qgpiowidget.cpp \
				$$PWD/qthreadingwidget.cpp
    HEADERS +=  $$PWD/qgpiowidget.h \
				$$PWD/qthreadingwidget.h
    FORMS += $$PWD/qgpiowidget.ui

    include(../../QCustomPlot/src/qcustomplot.pri)
} else {
    message( "Skipping $$PWD: already included" )
}
