!contains( included_modules, $$PWD ) {
    included_modules += $$PWD
    message( "Including $$PWD" )

    QT +=

    INCLUDEPATH += $$PWD \
                   /home/maarten/projects/Eigen \
                   /home/maarten/projects/Eigen/Eigen

    SOURCES +=  $$PWD/qimuwidget.cpp \
                        $$PWD/qimucalibrationwidget.cpp

    HEADERS +=  $$PWD/qimuwidget.h \
    			$$PWD/qimu_typedef.h \
                        $$PWD/qimucalibrationwidget.h \
                        $$PWD/qpolarplot.h

    FORMS +=    $$PWD/qimuwidget.ui \
                        $$PWD/qimucalibrationwidget.ui

    DEFINES += QT_NO_PRINTER

    include(../../QCustomPlot/src/qcustomplot.pri)
} else {
    message( "Skipping $$PWD: already included" )
}

HEADERS += \
    $$PWD/qrunningpolarplot.h

SOURCES += \
    $$PWD/qpolarplot.cpp \
    $$PWD/qrunningpolarplot.cpp
