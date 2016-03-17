#include "regex.h"

const QRegExp Regex::autor = QRegExp("(#(\\s*)(\\w)+((\\s|\\w))*#)");  //Cualquier conjunto de palabras encerrada en '#', la primera pegada a '#'
const QRegExp Regex::titulo = QRegExp("(\\{(\\s*)(\\w)+((\\s|\\w))*\\})");//Cualquier conjunto de palabras encerrada en '{}', la primera pegada a '{'
const QRegExp Regex::etiqueta = QRegExp("(<(\\d)+>)");               //Cualquier número encerrado en '<>'
const QRegExp Regex::saltoIncondicional = QRegExp ("(\\s*)(@(\\s)*(\\d)+)");      //'@' seguido de cualquier número
const QRegExp Regex::saltoProbabilistico= QRegExp ("(%(\\d)+)");     //'%' seguido de cualquier número
const QRegExp Regex::opcion = QRegExp("^(\\s*)(\\~)((\\s|\\w))*");          //'~'
const QRegExp Regex::bloqueProbabilistico = QRegExp("\\(((\\d+)(\\s+))+@(\\d+)\\)");
const QRegExp Regex::comentarioCompilacion = QRegExp("^(\\s*)//(.*)$");
const QRegExp Regex::comentarioResaltado = QRegExp("//(.*)$");
const QRegExp Regex::blancos = QRegExp("\\s*");
