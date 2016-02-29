#ifndef HISTORIA_H
#define HISTORIA_H

#include "escena.h"

#include <QRegExp>
#include <vector>
#include <QString>
#include <QStringList>
#include <iostream>

using namespace std;

struct tempHistoria{
    QString texto;
};

class Historia{
private:
    QRegExp* etiqueta;
    QRegExp* saltoIncondicional;
    QRegExp* saltoProbabilistico;
    QRegExp* bloqueProbabilistico;
    QRegExp* autor;
    QRegExp* titulo;
    QRegExp* opcion;
    QRegExp* comentario;

    QString  hTitulo;
    QString  hAutor;
    vector<Escena*> escenas;
public:
    Historia();
    QString parser(QString);
};

#endif // HISTORIA_H
