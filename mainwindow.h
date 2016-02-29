#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "texteditor.h"
#include "jugar.h"
#include "linketiqueta.h"
#include "historia.h"
#include "escena.h"

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
    QAction* abrir;
    QAction* guardar;
    QAction* guardarComo;
    QFileDialog* dialogoArchivo;
    QString path;
    QTabWidget* modos;
    Jugar*      juego;
    QDockWidget* dockLinks;
    QWidget* contenedorLinks;
    QScrollArea* scroll;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void addTag(LinkEtiqueta* tag);
private slots:
    void onGuardar();
    void onGuardarComo();
    void onAbrir();
    void onModificado();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
