#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
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

    abrir->setShortcut(QKeySequence("Ctrl+o"));
    guardarComo->setShortcut(QKeySequence("Ctrl+s"));

    barraMenu->addMenu(archivo);
    archivo->addAction(abrir);
    archivo->addAction(guardar);
    archivo->addAction(guardarComo);

    guardar->setDisabled(true);

    connect(guardar,SIGNAL(triggered(bool)),this,SLOT(onGuardar()));
    connect(guardarComo,SIGNAL(triggered(bool)),this,SLOT(onGuardarComo()));
    connect(abrir,SIGNAL(triggered(bool)),this,SLOT(onAbrir()));





    linksDefiniciones = new QDockWidget("Escenas",this);

    contenedorLinks = new QWidget(linksDefiniciones);
    QBoxLayout* layContenedorLinks = new QBoxLayout(QBoxLayout::TopToBottom,contenedorLinks);
    layContenedorLinks->setSizeConstraint(QBoxLayout::SetFixedSize);
    contenedorLinks->setLayout(layContenedorLinks);


    scroll = new QScrollArea(linksDefiniciones);
    scroll->setWidget(contenedorLinks);
    scroll->setWidgetResizable(true);

    linksDefiniciones->setFeatures(QDockWidget::DockWidgetMovable);
    linksDefiniciones->setWidget(scroll);
    linksDefiniciones->layout()->setSizeConstraint(QBoxLayout::SetMinimumSize);

    modos = new QTabWidget (this);
    juego = new Jugar (modos);
    textPanel = new TextEditor (modos,this,contenedorLinks);
    modos->addTab (textPanel, "Editor");
    modos->addTab (juego, "Jugar");


    this->setMenuBar(barraMenu);
    this->setCentralWidget(modos);
    this->addDockWidget(Qt::LeftDockWidgetArea,linksDefiniciones,Qt::Vertical);
    this->setWindowTitle("StoryBot IDE [*]");
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::onAbrir(){
    dialogoArchivo->setAcceptMode(QFileDialog::AcceptOpen);
    QString ruta = dialogoArchivo->getOpenFileName(this);
    ifstream file;
    path = ruta;
    string buffer;
    file.open(ruta.toStdString().c_str());
    if(file.is_open()){
        getline (file, buffer, (char) file.eof());
        textPanel->document()->setPlainText(QString::fromStdString(buffer));
        file.close();
        guardar->setDisabled(false);
        this->setWindowModified(false);
        guardar->setShortcut(QKeySequence("Ctrl+s"));
        guardarComo->setShortcut(NULL);
    }else{
        cout<<"Error I/O";
    }
}

void MainWindow::onGuardar(){
    ofstream file;
    file.open(path.toStdString().c_str());
    if(file.is_open()){
        file<<textPanel->toPlainText().toStdString();
        file.close();
        this->setWindowModified(false);
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
        file<<textPanel->toPlainText().toStdString();
        file.close();
        guardar->setDisabled(false);
        path = ruta;
        this->setWindowModified(false);
        guardar->setShortcut(QKeySequence("Ctrl+s"));
        guardarComo->setShortcut(NULL);
    }else{
        cout<<"Error I/O";
    }
}

void MainWindow::onModificado(){
    this->setWindowModified(true);
}

void MainWindow::addTag(LinkEtiqueta *tag){
    contenedorLinks->layout()->addWidget(tag);
}
