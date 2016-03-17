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
    ver = new QMenu("Ver",this);

    iconAbrir = QIcon::fromTheme("document-open");
    iconGuardar = QIcon::fromTheme("document-save");
    iconGuardarComo = QIcon::fromTheme("document-save-as");

    abrir = new QAction(iconAbrir,"Abrir",this);
    guardar = new QAction(iconGuardar,"Guardar",this);
    guardarComo = new QAction(iconGuardarComo,"Guardar como",this);
    compilar = new QAction(QIcon::fromTheme("system-run"),"Compilar",this);
    jugar = new QAction(QIcon::fromTheme("media-playback-start"),"Jugar",this);

    verPanelErrores = new QAction("Panel de errores",this);
    verPanelErrores->setCheckable(true);
    verPanelErrores->setChecked(true);
    verPanelEscenas = new QAction("Panel de escenas",this);
    verPanelEscenas->setCheckable(true);
    verPanelEscenas->setChecked(true);

    abrir->setShortcut(QKeySequence("Ctrl+o"));
    guardarComo->setShortcut(QKeySequence("Ctrl+s"));
    compilar->setShortcut(QKeySequence("Ctrl+b"));
    jugar->setShortcut(QKeySequence("Ctrl+r"));

    barraMenu->addMenu(archivo);
    archivo->addAction(abrir);
    archivo->addAction(guardar);
    archivo->addAction(guardarComo);

    barraMenu->addMenu(ver);
    ver->addAction(verPanelErrores);
    ver->addAction(verPanelEscenas);

    guardar->setDisabled(true);

    connect(guardar,SIGNAL(triggered(bool)),this,SLOT(onGuardar()));
    connect(guardarComo,SIGNAL(triggered(bool)),this,SLOT(onGuardarComo()));
    connect(abrir,SIGNAL(triggered(bool)),this,SLOT(onAbrir()));
    connect(jugar,SIGNAL(triggered(bool)),this,SLOT(onJugar()));
    connect(compilar,SIGNAL(triggered(bool)),this,SLOT(onCompilar()));


    QToolBar * Ribbon = new QToolBar(this);
    Ribbon->addAction(abrir);
    Ribbon->addAction(guardar);
    Ribbon->addSeparator();
    Ribbon->addAction(compilar);
    Ribbon->addAction(jugar);

    dockLinks = new QDockWidget("Escenas",this);
    dockCompile = new QDockWidget("Errores",this);

    contenedorLinks = new QWidget(dockLinks);

    tablaErrores = new QTableWidget(dockCompile);
    tablaErrores->horizontalHeader()->setStretchLastSection(true);
    tablaErrores->setEditTriggers(QTableWidget::NoEditTriggers);


    dockCompile->setWidget(tablaErrores);

    QBoxLayout* layContenedorLinks = new QBoxLayout(QBoxLayout::TopToBottom,contenedorLinks);
    layContenedorLinks->setSizeConstraint(QBoxLayout::SetFixedSize);
    contenedorLinks->setLayout(layContenedorLinks);

    scroll = new QScrollArea(dockLinks);
    scroll->setWidget(contenedorLinks);
    scroll->setWidgetResizable(true);

    dockLinks->setFeatures(QDockWidget::DockWidgetMovable);
    dockLinks->setWidget(scroll);
    dockLinks->layout()->setSizeConstraint(QBoxLayout::SetMinimumSize);

    dockCompile->setFeatures(QDockWidget::NoDockWidgetFeatures);

    modos = new QTabWidget (this);
    textPanel = new TextEditor (modos,this,contenedorLinks);
    juego = new Jugar (modos,textPanel);
    compilerPanel = new PanelCompilar(modos);
    modos->addTab (textPanel, "Editor");
    modos->addTab (compilerPanel, "Compilador");
    modos->addTab (juego, "Juego");

    connect(verPanelErrores,SIGNAL(triggered(bool)),dockCompile,SLOT(setVisible(bool)));
    connect(verPanelEscenas,SIGNAL(triggered(bool)),dockLinks,SLOT(setVisible(bool)));

    this->setMenuBar(barraMenu);
    this->setCentralWidget(modos);
    this->addDockWidget(Qt::BottomDockWidgetArea,dockCompile,Qt::Horizontal);
    this->addDockWidget(Qt::LeftDockWidgetArea,dockLinks,Qt::Vertical);
    this->addToolBar(Ribbon);
    this->setWindowTitle("StoryBot IDE [*]");
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::onAbrir(){
    tablaErrores->clear();
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
        this->setWindowTitle(ruta + " - StoryBot IDE [*]");
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

void MainWindow::onJugar(){
    modos->setCurrentIndex(2);
    juego->compilar();
}

void MainWindow::onCompilar(){
    juego->compilar();
    Parser analizador = Parser();
    analizador.compilar(textPanel->toPlainText());
    setLogs(analizador.getLogs());
}

void MainWindow::setLogs(vector<error*> v){
    tablaErrores->clear();
    tablaErrores->setRowCount(v.size());
    tablaErrores->setColumnCount(2);
    tablaErrores->setHorizontalHeaderItem(1, new QTableWidgetItem("Errores"));
    tablaErrores->setHorizontalHeaderItem(0, new QTableWidgetItem("Línea"));
    for (int i=0;i<v.size();i++){        
        if (v[i]->tipo != UNDEFINED ){
            tablaErrores->setItem(i,0,new QTableWidgetItem( QString::number(v[i]->linea) ));
        }
        tablaErrores->setItem(i,1,new QTableWidgetItem( v[i]->text ));
    }
}


