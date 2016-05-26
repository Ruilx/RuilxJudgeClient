#-------------------------------------------------
#
# Project created by QtCreator 2016-05-13T23:36:21
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QMAKE_CXXFLAGS += --std=c++11

TARGET = RuilxJudgeClient
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    com/network.cpp \
    com/networkcommunication.cpp \
    config.cpp \
    inputhandle.cpp \
    outputhandle.cpp

HEADERS  += mainwindow.h \
    com/network.h \
    com/global.h \
    com/networkcommunication.h \
    config.h \
    inputhandle.h \
    outputhandle.h

DISTFILES += \
    config.ini
