!contains( included_modules, $$PWD ) {
    included_modules += $$PWD
    message( "Including $$PWD" )

    QT +=

    INCLUDEPATH += $$PWD

        HEADERS += \
            $$PWD/qmapwidget.h\
            $$PWD/qpainterelement.h \
            $$PWD/qtrajectoryelement.h \
            $$PWD/qarrowelement.h \
            $$PWD/qmarkerelement.h \

        SOURCES += \
            $$PWD/qmapwidget.cpp\
            $$PWD/qpainterelement.cpp \
            $$PWD/qtrajectoryelement.cpp \
            $$PWD/qarrowelement.cpp \
            $$PWD/qmarkerelement.cpp \
                        

    FORMS += 

} else {
    message( "Skipping $$PWD: already included" )
}
