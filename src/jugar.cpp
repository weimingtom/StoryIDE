#include "jugar.h"

Jugar::Jugar(QWidget* parent, TextEditor* edit) : QWidget(parent),
    editor(edit)
    {
    QBoxLayout* lay = new QBoxLayout(QBoxLayout::TopToBottom,this);
    this->setLayout(lay);
    QLineEdit* irAEscena = new QLineEdit("Ir a la escena...",this);

    textoEscena = new QPlainTextEdit();
    QFont font = textoEscena->font();
    font.setPointSize(30);
    textoEscena->setFont(font);
    textoEscena->setReadOnly(true);



    lay->addWidget(irAEscena);
    lay->addWidget(textoEscena);

    QWidget* botonesJuego = new QWidget(this);
    lay->addWidget(botonesJuego);
    layBotonesJuego = new QBoxLayout(QBoxLayout::LeftToRight,botonesJuego);
    QIcon a = QIcon::fromTheme("media-playback-start");
}

void Jugar::compilar(){
    compilador = Parser();
    historia = compilador.compilar((editor->toPlainText()));
    if(historia!=NULL){
        MostrarEscena(-1);
    }else{
        cout<<"Errores"<<endl;
    }
}

void Jugar::MostrarEscena(int i){
    ContenidoAMostrar c = historia->getEscena(i);
    QString buff = c.texto + "\n\n";
    QLayoutItem *child;
    while ((child = layBotonesJuego->takeAt(0)) != 0) {
        delete child;
    }
    for (int i = 0; i < c.opciones.size(); i++){
        buff.append(QString::number(i) + ".- " + c.opciones[i] + "\n");
        BotonJuego* aux = new BotonJuego (this,i);
        layBotonesJuego->addWidget(aux);
    }
    textoEscena->document()->setPlainText(buff);
}

BotonJuego::BotonJuego (Jugar* padre, int num) : QPushButton(padre){
    padre_ = padre;
    this->setText(QString::number(num));
    num_ = num;
    connect(this,SIGNAL(clicked(bool)),this,SLOT(clicado(bool)));
}

void BotonJuego::clicado(bool b){
    padre_->MostrarEscena(num_);
}
