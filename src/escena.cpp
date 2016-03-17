#include "escena.h"
#include <iostream>

using namespace std;

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
    return text;
}

vector<QString> Escena::getOpciones(){
    vector<QString> v;
    for(int i = 0; i < opciones.size(); i++){
        v.push_back(opciones[i]->text);
    }
    return v;
}

int Escena::getSalto(int i) {
    return opciones[i]->salto->saltar();
}
