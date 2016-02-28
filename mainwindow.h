#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "texteditor.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QFileDialog>
#include <fstream>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    TextEditor textPanel;
    QMenuBar* barraMenu;
    QMenu* archivo;
    QAction* abrir;
    QAction* guardar;
    QAction* guardarComo;
    QFileDialog* dialogoArchivo;
    QString path;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void onGuardar();
    void onGuardarComo();
    void onAbrir();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
