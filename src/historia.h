#ifndef HISTORIA_H
#define HISTORIA_H

#include "escena.h"

#include <QRegExp>
#include <vector>
#include <QString>
#include <QStringList>
#include <iostream>
#include <map>

using namespace std;

struct ContenidoAMostrar {
    QString texto;
    vector <QString> opciones;
};

class Historia{
private:
    QString  titulo;
    QString  autor;
    map <int,Escena*> escenas;
    Escena* current;
public:
    Historia(QString titulop, QString autorp, map<int,Escena*> m);
    QString getText();
    ContenidoAMostrar getEscena(int i);
};

#endif // HISTORIA_H
