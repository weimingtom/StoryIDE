#include "jugar.h"

Jugar::Jugar(QWidget* parent, TextEditor* edit) : QWidget(parent),
    editor(edit)
    {
    QBoxLayout* lay = new QBoxLayout(QBoxLayout::TopToBottom,this);
    this->setLayout(lay);
    QWidget* botonesJuego = new QWidget(this);
    lay->addWidget(botonesJuego);
    QBoxLayout* layBotonesJuego = new QBoxLayout(QBoxLayout::LeftToRight,botonesJuego);
    QPushButton* botonPlay = new QPushButton("Play",botonesJuego);
    layBotonesJuego->addWidget(botonPlay);
    connect(botonPlay,SIGNAL(clicked(bool)),this,SLOT(compilar()));
}

void Jugar::compilar(){
    compilador = Parser();
    if(compilador.compilar((editor->toPlainText())).size()>0){
        cout<<"Todo ok"<<endl;
    }else{
        cout<<"Errores"<<endl;
    }
}
