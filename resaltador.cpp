#include "resaltador.h"

Resaltador::Resaltador(QTextDocument* parent) : QSyntaxHighlighter(parent){
    autor = new QRegExp("(#(\\w)+((\\s|\\w))*#)");      //Cualquier conjunto de palabras encerrada en '#', la primera pegada a '#'
    titulo = new QRegExp("(\\{(\\w)+((\\s|\\w))*\\})"); //Cualquier conjunto de palabras encerrada en '{}', la primera pegada a '{'
    etiqueta = new QRegExp("(<(\\d)+>)");               //Cualquier número encerrado en '<>'
    saltoIncondicional = new QRegExp("(@(\\d)+)");      //'@' seguido de cualquier número
    saltoProbabilistico = new QRegExp("(%(\\d)+)");     //'%' seguido de cualquier número
    opcion = new QRegExp("(\\~)((\\s|\\w))*");          //'~'
    comentario = new QRegExp();
    bloqueProbabilistico = new QRegExp("\\(((\\d+)(\\s+))+@(\\d+)\\)");

    Regla rule;
    formatoTitulo.setForeground(Qt::blue);
    formatoTitulo.setFontWeight(QFont::Bold);
    rule.pattern = *titulo;
    rule.format = formatoTitulo;
    highlightingRules.append(rule);

    formatoAutor.setForeground(Qt::red);
    formatoAutor.setFontWeight(QFont::Bold);
    rule.pattern = *autor;
    rule.format = formatoAutor;
    highlightingRules.append(rule);

    formatoOpcion.setForeground(Qt::green);
    formatoOpcion.setFontWeight(QFont::Bold);
    rule.pattern = *opcion;
    rule.format = formatoOpcion;
    highlightingRules.append(rule);

    formatoSaltoIncondicional.setForeground(Qt::yellow);
    formatoSaltoIncondicional.setFontItalic(true);
    rule.pattern = *saltoIncondicional;
    rule.format = formatoSaltoIncondicional;
    highlightingRules.append(rule);

    formatoEtiqueta.setForeground(Qt::cyan);
    formatoEtiqueta.setFontWeight(QFont::Bold);
    rule.pattern = *etiqueta;
    rule.format = formatoEtiqueta;
    highlightingRules.append(rule);

    formatoSaltoProbabilistico.setForeground(Qt::magenta);
    formatoSaltoProbabilistico.setFontWeight(QFont::Bold);
    rule.pattern = *saltoProbabilistico;
    rule.format = formatoSaltoProbabilistico;
    highlightingRules.append(rule);

    formatoBloqueProbabilistico.setForeground(Qt::magenta);
    formatoBloqueProbabilistico.setFontWeight(QFont::Bold);
    rule.pattern = *bloqueProbabilistico;
    rule.format = formatoBloqueProbabilistico;
    highlightingRules.append(rule);

}

void Resaltador::highlightBlock(const QString &text){
    foreach (const Regla &rule, highlightingRules) {
        QRegExp expression(rule.pattern);
        int index = expression.indexIn(text);
        while (index >= 0) {
            int length = expression.matchedLength();
            setFormat(index, length, rule.format);
            index = expression.indexIn(text, index + length);
        }
    }
    setCurrentBlockState(0);
}
