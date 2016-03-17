#include "resaltador.h"

Resaltador::Resaltador(QTextDocument* parent) : QSyntaxHighlighter(parent){

    colorTitulo = QColor(255,198,130);
    colorAutor = QColor(247,93,35);
    colorComentario = QColor(187,33,21);
    colorEtiqueta = QColor(193,241,97);
    colorOpcion = QColor(141,230,247);
    colorSaltoIncondicional = QColor(243,71,57);

    Regla rule;
    formatoTitulo.setForeground(colorTitulo);
    formatoTitulo.setFontWeight(QFont::Bold);
    rule.pattern = Regex::titulo;
    rule.format = formatoTitulo;
    highlightingRules.append(rule);

    formatoComentario.setForeground(Qt::gray);
    formatoComentario.setFontItalic(true);
    rule.pattern = Regex::comentarioResaltado;
    rule.format = formatoComentario;
    highlightingRules.append(rule);

    formatoAutor.setForeground(colorAutor);
    formatoAutor.setFontWeight(QFont::Bold);
    rule.pattern = Regex::autor;
    rule.format = formatoAutor;
    highlightingRules.append(rule);

    formatoOpcion.setForeground(colorOpcion);
    formatoOpcion.setFontWeight(QFont::Bold);
    rule.pattern = Regex::opcion;
    rule.format = formatoOpcion;
    highlightingRules.append(rule);

    formatoSaltoIncondicional.setForeground(colorSaltoIncondicional);
    formatoSaltoIncondicional.setFontUnderline(true);
    rule.pattern = Regex::saltoIncondicional;
    rule.format = formatoSaltoIncondicional;
    highlightingRules.append(rule);

    formatoEtiqueta.setForeground(colorEtiqueta);
    formatoEtiqueta.setFontWeight(QFont::Bold);
    rule.pattern = Regex::etiqueta;
    rule.format = formatoEtiqueta;
    highlightingRules.append(rule);

    formatoSaltoProbabilistico.setForeground(Qt::magenta);
    formatoSaltoProbabilistico.setFontWeight(QFont::Bold);
    rule.pattern = Regex::saltoProbabilistico;
    rule.format = formatoSaltoProbabilistico;
    highlightingRules.append(rule);

    formatoBloqueProbabilistico.setForeground(Qt::magenta);
    formatoBloqueProbabilistico.setFontWeight(QFont::Bold);
    rule.pattern = Regex::bloqueProbabilistico;
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
