#include "escena.h"

Escena::Escena(){

}

Escena::Escena(QString texto){
    text = texto;
    salto = NULL;
}

Escena::Escena(QString texto, Salto* jump){
    text = texto;
    salto = jump;
}


Escena::Escena(QString texto, vector<Opcion*> v){
    text = texto;
    salto = NULL;
    opciones = v;
}
