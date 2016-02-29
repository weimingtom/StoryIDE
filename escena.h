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
    void addText(QString );
    void addSalto(Salto* salto);
    void addOpcion(Opcion* o);
};

#endif // ESCENA_H
