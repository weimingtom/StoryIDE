#ifndef REGEX_H
#define REGEX_H

#include <QRegExp>

class Regex{
public:
    static const QRegExp autor;
    static const QRegExp titulo;
    static const QRegExp etiqueta;
    static const QRegExp saltoIncondicional;
    static const QRegExp saltoProbabilistico;
    static const QRegExp opcion;
    static const QRegExp bloqueProbabilistico;
    static const QRegExp comentarioCompilacion;
    static const QRegExp comentarioResaltado;
    static const QRegExp blancos;
};

#endif // REGEX_H
