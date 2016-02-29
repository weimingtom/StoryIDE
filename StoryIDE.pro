#-------------------------------------------------
#
# Project created by QtCreator 2016-02-28T15:59:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = StoryIDE
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    texteditor.cpp \
    resaltador.cpp \
    jugar.cpp \
    historia.cpp \
    escena.cpp \
    salto.cpp

HEADERS  += mainwindow.h \
    texteditor.h \
    resaltador.h \
    jugar.h \
    historia.h \
    escena.h \
    salto.h

FORMS    += mainwindow.ui
