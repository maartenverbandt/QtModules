!contains( included_modules, $$PWD ) {
    included_modules += $$PWD
    message( "Including $$PWD" )
    
    message($${PROTOCOL})
    !defined(PROTOCOL,var) {
        error( "No valid serial protocol set. Possible values are: mavlink" )
    }

    INCLUDEPATH += $$PWD/$${PROTOCOL} \
                   $$PWD
    HEADERS += $$PWD/$${PROTOCOL}/qserialprotocol.h\
               $$PWD/qdatanode.h \
               $$PWD/qheartbeatdetector.h
    SOURCES += $$PWD/$${PROTOCOL}/qserialprotocol.cpp\
               $$PWD/qdatanode.cpp \
               $$PWD/qheartbeatdetector.cpp

} else {
    message( "Skipping $$PWD: already included" )
}

HEADERS += \
    $$PWD/mavlink/qserialprotocol_typedefs.h
