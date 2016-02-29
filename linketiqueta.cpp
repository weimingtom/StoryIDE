#include "linketiqueta.h"

LinkEtiqueta::LinkEtiqueta(TextEditor* parent, int id, int line) : QLabel(parent){
    setText(QString("Escena ") + QString::number(id));
    linea = line;
    padre = parent;
    connect(this,SIGNAL(clicked()),this,SLOT(saltoALinea()));
}

void LinkEtiqueta::mousePressEvent(QMouseEvent* event){
    emit clicked();
}

void LinkEtiqueta::saltoALinea(){
    padre->setLinea(linea);
}
