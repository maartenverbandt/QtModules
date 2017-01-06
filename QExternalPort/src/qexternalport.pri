!contains( included_modules, $$PWD ) {
    included_modules += $$PWD
    message( "Including $$PWD" )

    QT +=

    INCLUDEPATH += $$PWD

        HEADERS += \
            $$PWD/qcsvreader.h\
            $$PWD/qcsvreaderwidget.h \
            $$PWD/qdataportinterface.h \
            $$PWD/qgpiofileport.h \
            $$PWD/qgpioportinterface.h \
            $$PWD/qpositioncmdfileport.h \
            $$PWD/qpositioncmdportdialog.h \
            $$PWD/qpositioncmdportinterface.h \
            $$PWD/qexternalportdialog.h

        SOURCES += \
			$$PWD/qcsvreader.cpp \
			$$PWD/qcsvreaderwidget.cpp \
			$$PWD/qgpiofileport.cpp \
			$$PWD/qpositioncmdfileport.cpp \
			$$PWD/qpositioncmdportdialog.cpp \
            $$PWD/qexternalportdialog.cpp
                        

    FORMS += $$PWD/qcsvreaderwidget.ui

} else {
    message( "Skipping $$PWD: already included" )
}
