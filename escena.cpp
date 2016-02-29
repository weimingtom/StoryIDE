#include "escena.h"

Escena::Escena(){
    salto = NULL;
}

void Escena::addText(QString s){
    text.append(s+" ");
}

void Escena::addSalto(Salto *s){
    salto = s;
}

void Escena::addOpcion(Opcion* o){
    opciones.push_back(o);
}
