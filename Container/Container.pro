QT -= gui
QT += widgets
QT += core
QT += network
QT += xml
RC_ICONS = box_icon.ico

CONFIG += c++17 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        box.cpp \
        clienttcp.cpp \
        container.cpp \
        containercaretaker.cpp \
        containercode.cpp \
        containerlist.cpp \
        containermomento.cpp \
        cylinder.cpp \
        factory.cpp \
        main.cpp \
        mainclient.cpp \
        pallet.cpp \
        palletlist.cpp \
        popupview.cpp \
        widget.cpp \
        writexml.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    box.h \
    clienttcp.h \
    container.h \
    containercaretaker.h \
    containercode.h \
    containerlist.h \
    containermomento.h \
    cylinder.h \
    factory.h \
    mainclient.h \
    pallet.h \
    palletlist.h \
    popupview.h \
    widget.h \
    writexml.h

RESOURCES += \
    html/html.qrc \
    images/images.qrc


