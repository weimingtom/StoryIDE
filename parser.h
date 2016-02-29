#ifndef PARSER_H
#define PARSER_H

#include "escena.h"

#include <QRegExp>
#include <vector>
#include <QString>
#include <QStringList>
#include <iostream>

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
    vector<Escena*> escenas;
    Opcion* tmpOpcion;
    Salto*  tmpSalto;
    int lineCount;
    char estado;
    QString hTitulo;
    QString hAutor;
    QString buffer;
    int errorCount;
public:
    Parser();
    vector<Escena*> compilar(QString);
    void errores(QString token);
    void clear();
};

#endif // PARSER_H
