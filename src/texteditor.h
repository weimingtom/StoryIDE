#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include "resaltador.h"
#include "linketiqueta.h"

#include <iostream>
#include <QPlainTextEdit>
#include <QWidget>
#include <QRegExp>
#include <QPalette>
#include <QMainWindow>
#include <QPainter>
#include <QTextCursor>
#include <QLayout>
#include <QTextDocument>
#include <utility>
#include <QFont>

using namespace std;

class MainWindow;
class AreaNumeroLinea;

class TextEditor : public QPlainTextEdit{
    Q_OBJECT
private:
    QPalette* paleta;
    AreaNumeroLinea*  areaNumero;
    QMainWindow* main;
    QRegExp* etiqueta;
    QWidget* contenedor;
    QTextDocument* doc;
    int nEtiquetas;
public:
    explicit TextEditor(QWidget *parent = 0, QMainWindow* mainw = 0, QWidget* contenedor = 0);
    void areaNumeroLineaPaintEvent(QPaintEvent *event);
    int areaNumeroLineaWidth();
    void setLinea(int l);
protected:
    void resizeEvent(QResizeEvent *event) Q_DECL_OVERRIDE;
private slots:
    void updateAreaNumeroLineaWidth(int newBlockCount);
    void highlightCurrentLine();
    void updateAreaNumeroLinea(const QRect &, int);
    void actualizarLinks();
    void onInsertarEscena();
    void onInsertarOpcion();
    void onInsertarSalto();
    void onInsertarTitulo();
    void onInsertarAutor();
};

class AreaNumeroLinea : public QWidget{
    Q_OBJECT
private:
    TextEditor *editor;

public:
    explicit AreaNumeroLinea(TextEditor* parent = 0) : QWidget(parent){
        editor = parent;
    }

    QSize sizeHint() const Q_DECL_OVERRIDE {
        return QSize(editor->areaNumeroLineaWidth(), 0);
    }
protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE {
        editor->areaNumeroLineaPaintEvent(event);
    }
};

#endif // TEXTEDITOR_H
