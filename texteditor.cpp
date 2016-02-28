#include "texteditor.h"

TextEditor::TextEditor() : QPlainTextEdit(){

    paleta = new QPalette();

    paleta->setColor(QPalette::Base,QColor(QColor(69,65,68)));
    paleta->setColor(QPalette::Text,QColor("white"));
    this->setPalette(*paleta);

    Resaltador* a = new Resaltador(this->document());
}
