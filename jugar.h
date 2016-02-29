#ifndef JUGAR_H
#define JUGAR_H

#include "historia.h"
#include "texteditor.h"
#include "parser.h"

#include <QWidget>
#include <QGroupBox>
#include <QGridLayout>
#include <QPushButton>
#include <QBoxLayout>

class Jugar : public QWidget{
    Q_OBJECT
private:
    Parser compilador;
    QGridLayout* lay;
    TextEditor*  editor;
public:
    Jugar(QWidget* parent, TextEditor* edit);
private slots:
    void compilar();
};

#endif // JUGAR_H
