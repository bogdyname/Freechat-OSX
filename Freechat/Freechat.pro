#---------------------------------
#Freechat (decentralized chat)
#Freechat via C++ & Qt, Debugger(Qt 5.12.1 GCC 64bit)
#Copyleft (C) 2019 Softwater, Inc.
#---------------------------------

QT       += core gui
QT       += network
QT       += gui
QT       += multimedia
QT       += multimediawidgets
QT       += svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Freechat
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++11
CONFIG += console
CONFIG += app_bundle
CONFIG += qt

SOURCES += \
        main.cpp \
        freechat.cpp \
        connection.cpp \
        userserver.cpp \
        userclient.cpp \
        datasave.cpp \
        username.cpp \
        usernametable.cpp \
        multimedia.cpp \
        peermanager.cpp \
        duinterface.cpp \
        videoviewer.cpp \
    pictureviewer.cpp

HEADERS += \
        freechat.h \
        connection.h \
        userserver.h \
        userclient.h \
        datasave.h \
        username.h \
        usernametable.h \
        multimedia.h \
        peermanager.h \
        duinterface.h \
        videoviewer.h \
    pictureviewer.h

FORMS += \
        freechat.ui \
        duinterface.ui \
        multimedia.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
