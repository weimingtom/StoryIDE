#-------------------------------------------------
#
# Project created by QtCreator 2016-02-28T15:59:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = StoryIDE
TEMPLATE = app
CONFIG += c++11 -03


SOURCES += src/main.cpp\
        src/mainwindow.cpp \
    	src/texteditor.cpp \
    	src/resaltador.cpp \
    	src/jugar.cpp \
    	src/historia.cpp \
    	src/escena.cpp \
    	src/salto.cpp \
    	src/linketiqueta.cpp \
    	src/parser.cpp \
    	src/panelcompilar.cpp \
    	src/regex.cpp

HEADERS  += src/mainwindow.h \
	src/texteditor.h \
    	src/resaltador.h \
    	src/jugar.h \
    	src/historia.h \
    	src/escena.h \
    	src/salto.h \
    	src/linketiqueta.h \
    	src/parser.h \
    	src/panelcompilar.h \
    	src/regex.h

FORMS    += mainwindow.ui
