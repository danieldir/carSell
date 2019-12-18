TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
#CONFIG -= qt
QT+= core gui sql
SOURCES += main.cpp \
    dbconnector.cpp

HEADERS += \
    dbconnector.h
