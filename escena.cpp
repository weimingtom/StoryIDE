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

QString Escena::getText(){
    for(int i = 0; i < opciones.size(); i++){
        text.append("\n").append(opciones[i]->text);
    }
    return text;
}
