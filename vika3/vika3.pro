#-------------------------------------------------
#
# Project created by QtCreator 2015-12-10T10:03:12
#
#-------------------------------------------------

QT  += core gui
QT 	+= sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = vika3
TEMPLATE = app


SOURCES += main.cpp\
           data_types/pioneer.cpp \
           data_types/computer.cpp \
           services/pioneerservice.cpp \
           services/computerservice.cpp \
           data_layer/pioneerconnection.cpp \
           data_layer/computerconnection.cpp \
           data_layer/relationconnection.cpp \
           services/relationservice.cpp \
           data_types/relation.cpp \
           ui/mainwindow.cpp

HEADERS += \
           data_types/pioneer.h \
           data_types/computer.h \
           utilities/constants.h \
           services/pioneerservice.h \
           services/computerservice.h \
           data_layer/pioneerconnection.h \
           data_layer/computerconnection.h \
           data_layer/relationconnection.h \
           services/relationservice.h \
           data_types/relation.h \
           ui/mainwindow.h

FORMS    += mainwindow.ui
