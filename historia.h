#ifndef HISTORIA_H
#define HISTORIA_H

#include "escena.h"

#include <QRegExp>
#include <vector>
#include <QString>
#include <QStringList>
#include <iostream>

using namespace std;

class Historia{
private:
    QString  hTitulo;
    QString  hAutor;
    vector<Escena*> escenas;
public:
    Historia();
};

#endif // HISTORIA_H
