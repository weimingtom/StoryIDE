#ifndef PARSER_H
#define PARSER_H

#include "escena.h"

#include <QRegExp>
#include <vector>
#include <QString>
#include <QStringList>
#include <iostream>
#include <map>
#include <utility>
#include <QList>

struct tempHistoria{
    QString texto;
};

class Parser{
private:
    QRegExp* etiqueta;
    QRegExp* saltoIncondicional;
    QRegExp* saltoProbabilistico;
    QRegExp* bloqueProbabilistico;
    QRegExp* autor;
    QRegExp* titulo;
    QRegExp* opcion;
    QRegExp* comentario;
    map <int,Escena*> escenas;
    QList <int> etiquetasSinDeclarar;
    Opcion* tmpOpcion;
    Salto*  tmpSalto;
    int lineCount;
    char estado;
    QString hTitulo;
    QString hAutor;
    QString buffer;
    int errorCount;
    int escenaActual;
public:
    Parser();
    map <int,Escena*> compilar(QString);
    void errores(QString token);
    void clear();
    void comprobarEtiquetas(int i);
};

#endif // PARSER_H
