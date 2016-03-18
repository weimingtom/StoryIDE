#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "texteditor.h"
#include "jugar.h"
#include "linketiqueta.h"
#include "historia.h"
#include "escena.h"
#include "panelcompilar.h"
#include "parser.h"

#include <QScrollArea>
#include <QLabel>
#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QFileDialog>
#include <fstream>
#include <QTabWidget>
#include <QGroupBox>
#include <QDockWidget>
#include <QBoxLayout>
#include <QPushButton>
#include <QIcon>
#include <QToolBar>
#include <QTableView>
#include <QTableWidget>
#include <QStyle>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    TextEditor* textPanel;
    QMenuBar* barraMenu;
    QMenu* archivo;
    QMenu* ver;
    QAction* abrir;
    QAction* guardar;
    QAction* guardarComo;
    QAction* verPanelErrores;
    QAction* verPanelEscenas;
    QAction* compilar;
    QAction* jugar;
    QFileDialog* dialogoArchivo;
    QString path;
    QTabWidget* modos;
    Jugar*      juego;
    PanelCompilar* compilerPanel;
    QDockWidget* dockLinks;
    QDockWidget* dockCompile;
    QWidget* contenedorLinks;
    QScrollArea* scroll;
    QIcon iconAbrir;
    QIcon iconGuardar;
    QIcon iconGuardarComo;
    QTableWidget* tablaErrores;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void addTag(LinkEtiqueta* tag);
    void setLogs(vector<error*> v);
private slots:
    void onGuardar();
    void onGuardarComo();
    void onAbrir();
    void onModificado();
    void onJugar();
    void onCompilar();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
