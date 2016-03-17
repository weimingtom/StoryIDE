#include "historia.h"

Historia::Historia(QString titulop, QString autorp, map<int, Escena *> m){
    titulo = titulop;
    autor = autorp;
    escenas = m;
    current = m.at(0);
}

QString Historia::getText(){
    return current->getText();
}

ContenidoAMostrar Historia::getEscena(int i){
    ContenidoAMostrar c;
    if(i == -1){
        c.texto = current->getText();
        c.opciones = current->getOpciones();
    }else{
        current = escenas.at(current->getSalto(i));        
        c.texto = current->getText();
        c.opciones = current->getOpciones();
    }
    return c;
}
