#ifndef ESCENA_H
#define ESCENA_H

#include "salto.h"

#include <QString>
#include <vector>

using namespace std;

struct Opcion{
    QString text;
    Salto*  salto;
};

class Escena{
private:
    QString text;
    Salto*  salto;
    vector <Opcion*> opciones;
public:
    Escena();
    Escena(QString text);
    Escena(QString text, Salto* salto);
    Escena(QString text, vector<Opcion*> v);
};

#endif // ESCENA_H
