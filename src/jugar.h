#ifndef JUGAR_H
#define JUGAR_H

#include "historia.h"
#include "texteditor.h"
#include "parser.h"

#include <QWidget>
#include <QGroupBox>
#include <QGridLayout>
#include <QPushButton>
#include <QBoxLayout>
#include <QIcon>
#include <QPlainTextEdit>
#include <QScrollArea>
#include <QFont>
#include <QLineEdit>
#include <map>

class BotonJuego;

class Jugar : public QWidget{
    Q_OBJECT
private:
    Parser compilador;
    QGridLayout* lay;
    QBoxLayout* layBotonesJuego;
    TextEditor*  editor;
    QPlainTextEdit*  textoEscena;
    Historia* historia;
public:
    Jugar(QWidget* parent, TextEditor* edit);
    void MostrarEscena (int i);
    void setEleccion(int i);
public slots:
    void compilar();
};

class BotonJuego : public QPushButton{
    Q_OBJECT
private:
   Jugar* padre_;
   int    num_;
public:
    BotonJuego(Jugar* padre, int num);
private slots:
    void clicado(bool);
};

#endif // JUGAR_H