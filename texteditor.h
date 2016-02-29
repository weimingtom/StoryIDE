#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include "resaltador.h"

#include <iostream>
#include <QPlainTextEdit>
#include <QWidget>
#include <QRegExp>
#include <QPalette>
#include <QMainWindow>
#include <QPainter>

using namespace std;

class AreaNumeroLinea;

class TextEditor : public QPlainTextEdit{
    Q_OBJECT
private:
    QPalette* paleta;
    AreaNumeroLinea*  areaNumero;
    QMainWindow* main;
public:
    explicit TextEditor(QWidget *parent = 0, QMainWindow* mainw = 0);
    void areaNumeroLineaPaintEvent(QPaintEvent *event);
    int areaNumeroLineaWidth();
protected:
    void resizeEvent(QResizeEvent *event) Q_DECL_OVERRIDE;
private slots:
    void updateAreaNumeroLineaWidth(int newBlockCount);
    void highlightCurrentLine();
    void updateAreaNumeroLinea(const QRect &, int);
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
