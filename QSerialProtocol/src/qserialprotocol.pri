!contains( included_modules, $$PWD ) {
    included_modules += $$PWD
    message( "Including $$PWD" )

    HEADERS += qserialprotocol.h

    mavlink {
        message( "mavlink protocol selected" )
        INCLUDEPATH += $$PWD
        HEADERS += protocol_mavlink.h
        CONFIG += serialprotocol_set
        DEFINES += SERIAL_PROTOCOL_MAVLINK
    }
    
    !serialprotocol_set {
        error( "No valid serial protocol set in config" )
    }

} else {
    message( "Skipping $$PWD: already included" )
}

HEADERS += \
    $$PWD/protocol_mavlink.h \
    $$PWD/qserialprotocol.h
