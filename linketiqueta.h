#ifndef LINKETIQUETA_H
#define LINKETIQUETA_H

#include "texteditor.h"
#include <QLabel>

class TextEditor;

class LinkEtiqueta : public QLabel{
    Q_OBJECT
private:
    int linea;
    TextEditor* padre;
public:
    LinkEtiqueta(TextEditor* parent, int id, int line);
signals:
    void clicked();
protected:
    void mousePressEvent(QMouseEvent* event);
private slots:
    void saltoALinea();
};

#endif // LINKETIQUETA_H
