#include "jugar.h"

Jugar::Jugar(QWidget* parent, TextEditor* edit) : QWidget(parent),
    editor(edit)
    {
    QBoxLayout* lay = new QBoxLayout(QBoxLayout::TopToBottom,this);
    this->setLayout(lay);

    fallando = false;
    cabecera = new QLabel();

    irAEscena = new QLineEdit("Ir a la escena...",this);
    irAEscena->setEnabled(false);
    connect(irAEscena,SIGNAL(returnPressed()),this,SLOT(onIrAEscena()));

    textoEscena = new QPlainTextEdit();
    QFont font = textoEscena->font();
    font.setPointSize(20);
    textoEscena->setFont(font);
    textoEscena->setReadOnly(true);

    cabecera->setFont(font);

    lay->addWidget(irAEscena);
    lay->addWidget(cabecera);
    lay->addWidget(textoEscena);

    QWidget* botonesJuego = new QWidget(this);
    lay->addWidget(botonesJuego);
    layBotonesJuego = new QBoxLayout(QBoxLayout::LeftToRight,botonesJuego);
    QIcon a = QIcon::fromTheme("media-playback-start");
}

void Jugar::compilar(){
    compilador = Parser();
    irAEscena->setEnabled(true);
    historia = compilador.compilar((editor->toPlainText()));
    if(historia!=NULL){
        cabecera->setText(historia->getCabecera());
        fallando = false;
        MostrarEscena(-1);
    }else{
        cout<<"Errores"<<endl;
        fallando = true;
    }
}

void Jugar::MostrarEscena(int k){
    ContenidoAMostrar c = historia->getEscena(k);
    QString buff = c.texto + "\n\n";
    QLayoutItem *child;
    while ((child = layBotonesJuego->takeAt(0)) != 0) {
        child->widget()->setVisible(false);
        delete child->widget();
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

void Jugar::onIrAEscena() {
    cout<<"El número es "<<irAEscena->text().toInt()<<endl;
    if(!fallando && historia->setEscena(irAEscena->text().toInt())){
         irAEscena->setStyleSheet("color: dark-gray");
         MostrarEscena(-1);
    }else{
        irAEscena->setStyleSheet("color: red");
        cout<<"La escena no exite"<<endl;
    }
}
