#-------------------------------------------------
#
# Project created by QtCreator 2015-08-02T10:08:43
#
#-------------------------------------------------

QT       += core gui opengl

LIBS += -lglut -lGLU

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtMagicCube
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mywidget.cpp

HEADERS  += mainwindow.h \
    mywidget.h

FORMS    += mainwindow.ui

OTHER_FILES +=
