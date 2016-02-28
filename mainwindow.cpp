#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    dialogoArchivo = new QFileDialog(this);
    dialogoArchivo->setNameFilter("*.stry");

    barraMenu = new QMenuBar(this);
    archivo = new QMenu("Archivo",this);
    abrir = new QAction("Abrir",this);
    guardar = new QAction("Guardar",this);
    guardarComo = new QAction("Guardar como",this);

    barraMenu->addMenu(archivo);
    archivo->addAction(abrir);
    archivo->addAction(guardar);
    archivo->addAction(guardarComo);

    guardar->setDisabled(true);

    connect(guardar,SIGNAL(triggered(bool)),this,SLOT(onAbrir()));
    connect(guardarComo,SIGNAL(triggered(bool)),this,SLOT(onGuardarComo()));
    connect(abrir,SIGNAL(triggered(bool)),this,SLOT(onAbrir()));

    this->setMenuBar(barraMenu);
    this->setCentralWidget(&textPanel);
    this->setWindowTitle("StoryBot IDE");


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onAbrir(){
    dialogoArchivo->setAcceptMode(QFileDialog::AcceptOpen);
    QString ruta = dialogoArchivo->getOpenFileName(this);
    ifstream file;
    string buffer;
    file.open(ruta.toStdString().c_str());
    if(file.is_open()){
        getline (file, buffer, (char) file.eof());
        textPanel.document()->setPlainText(QString::fromStdString(buffer));
        file.close();
    }else{
        cout<<"Error I/O";
    }
}

void MainWindow::onGuardar(){
    ofstream file;
    file.open(path.toStdString().c_str());
    if(file.is_open()){
        file<<textPanel.toPlainText().toStdString();
        file.close();
    }else{
        cout<<"Error I/O";
    }
}

void MainWindow::onGuardarComo(){
    dialogoArchivo->setAcceptMode(QFileDialog::AcceptSave);
    QString ruta = dialogoArchivo->getSaveFileName(this);
    if(!ruta.contains(".stry")){
        ruta.append(".stry");
    }
    ofstream file;
    file.open(ruta.toStdString().c_str());
    if(file.is_open()){
        file<<textPanel.toPlainText().toStdString();
        file.close();
        guardar->setDisabled(false);
        path = ruta;
    }else{
        cout<<"Error I/O";
    }
}
