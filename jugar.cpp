#include "jugar.h"

Jugar::Jugar(QWidget* parent, TextEditor* edit) : QWidget(parent),
    editor(edit)
    {
    QBoxLayout* lay = new QBoxLayout(QBoxLayout::TopToBottom,this);
    this->setLayout(lay);
    QLineEdit* irAEscena = new QLineEdit("Ir a la escena...",this);

    textoEscena = new QLabel("");
    QFont font = textoEscena->font();
    font.setPointSize(30);
    textoEscena->setFont(font);

    textoEscena->setScaledContents(true);
    QScrollArea* scroll = new QScrollArea(this);
    scroll->setWidget(textoEscena);

    lay->addWidget(irAEscena);
    lay->addWidget(scroll);

    QWidget* botonesJuego = new QWidget(this);
    lay->addWidget(botonesJuego);
    QBoxLayout* layBotonesJuego = new QBoxLayout(QBoxLayout::LeftToRight,botonesJuego);
    QIcon a = QIcon::fromTheme("media-playback-start");
    QPushButton* botonPlay = new QPushButton(a,"Play",botonesJuego);
    layBotonesJuego->addWidget(botonPlay);
    connect(botonPlay,SIGNAL(clicked(bool)),this,SLOT(compilar()));
}

void Jugar::compilar(){
    compilador = Parser();
    if(compilador.compilar((editor->toPlainText())).size()>0){
        cout<<"Todo ok"<<endl;
        //cout<<(compilador.compilar((editor->toPlainText())).at(0)->getText()).toStdString()<<endl;
    }else{
        cout<<"Errores"<<endl;
    }
}
