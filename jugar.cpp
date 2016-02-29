#include "jugar.h"

Jugar::Jugar(QWidget* parent) : QWidget(parent){
    lay = new QGridLayout();
    //lay->addWidget();
    Historia* a = new Historia();
    a->parser("#Daniel Darias# \n{Historia}\n <0>Blabla @1 asdasd asd ");
}
