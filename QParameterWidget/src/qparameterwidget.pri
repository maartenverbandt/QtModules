!contains( included_modules, $$PWD ) {
    included_modules += $$PWD
    message( "Including $$PWD" )

include(../../QSerialProtocol/src/qserialprotocol.pri)

    QT += 

    INCLUDEPATH += $$PWD \

        HEADERS += \

        SOURCES += \
                        

    FORMS += \

} else {
    message( "Skipping $$PWD: already included" )
}

HEADERS += \
    $$PWD/qdatanode.h \
    $$PWD/qparametermanager.h \
    $$PWD/qparameter.h \
    $$PWD/qintegerparameter.h \
    $$PWD/qfloatparameter.h \
    $$PWD/qstringparameter.h \
    $$PWD/qparametertablewidget.h

SOURCES += \
    $$PWD/qdatanode.cpp \
    $$PWD/qparametermanager.cpp \
    $$PWD/qparameter.cpp \
    $$PWD/qintegerparameter.cpp \
    $$PWD/qfloatparameter.cpp \
    $$PWD/qstringparameter.cpp \
    $$PWD/qparametertablewidget.cpp
