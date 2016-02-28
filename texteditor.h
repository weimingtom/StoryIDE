#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <iostream>
#include <QPlainTextEdit>
#include <QWidget>
#include <QRegExp>
#include <QPalette>
#include <QTextCursor>
#include <QTextBlock>
#include <QTextBlockFormat>
#include <QSyntaxHighlighter>
#include "resaltador.h"

using namespace std;

class TextEditor : public QPlainTextEdit
{
    Q_OBJECT
private:
    QRegExp* etiqueta;
    QRegExp* saltoIncondicional;
    QRegExp* saltoProbabilistico;
    QRegExp* autor;
    QRegExp* titulo;
    QRegExp* opcion;
    QPalette* paleta;
public:
    TextEditor();
};

#endif // TEXTEDITOR_H
