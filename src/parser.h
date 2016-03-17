#ifndef PARSER_H
#define PARSER_H

#include "escena.h"
#include "historia.h"
#include "regex.h"

#include <QRegExp>
#include <vector>
#include <QString>
#include <QStringList>
#include <iostream>
#include <map>
#include <utility>
#include <QList>

enum{
    WARNING,
    ERROR,
    UNDEFINED
};

struct error{
    int tipo;
    int linea;
    QString text;
};


class Parser{
private:
    map <int,Escena*> escenas;
    QList <int> etiquetasSinDeclarar;
    Opcion* tmpOpcion;
    Salto*  tmpSalto;
    int lineCount;
    char estado;
    QString hTitulo;
    QString hAutor;
    QString buffer;
    int errorCount;
    int escenaActual;
    Historia* hResultado;
    vector<error*> logs;
public:
    Parser();
    Historia* compilar(QString);
    void errores(QString token);
    void clear();
    void comprobarEtiquetas(int i);
    void comprobarErroresFinales();
    void crearHistoria();
    vector<error*> getLogs();
};

#endif // PARSER_H
