#include "texteditor.h"

TextEditor::TextEditor(QWidget* parent, QMainWindow* mainw, QWidget* conten) : QPlainTextEdit(parent){

    areaNumero = new AreaNumeroLinea(this);
    connect(this, SIGNAL(blockCountChanged(int)), this, SLOT(updateAreaNumeroLineaWidth(int)));
    connect(this, SIGNAL(updateRequest(QRect,int)), this, SLOT(updateAreaNumeroLinea(QRect,int)));
    connect(this, SIGNAL(cursorPositionChanged()), this, SLOT(highlightCurrentLine()));

    setLineWrapMode(QPlainTextEdit::NoWrap);

    updateAreaNumeroLineaWidth(0);
    highlightCurrentLine();

    paleta = new QPalette();
    paleta->setColor(QPalette::Base,QColor(QColor(69,65,68)));
    paleta->setColor(QPalette::Text,QColor("white"));
    this->setPalette(*paleta);

    QFont font = this->font();
    font.setPointSize(11);
    this->setFont(font);

    Resaltador* a = new Resaltador(this->document());
    doc = document();

    etiqueta = etiqueta = new QRegExp("<(\\d)+>");               //Cualquier número encerrado en '<>'
    main = mainw;

    connect(this,SIGNAL(textChanged()),main,SLOT(onModificado()));
    connect(this,SIGNAL(textChanged()),this,SLOT(actualizarLinks()));

    nEtiquetas = 0;
    contenedor = conten;
}

int TextEditor::areaNumeroLineaWidth(){
    int digits = 1;
    int max = qMax(1, blockCount());
    while (max >= 10) {
        max /= 10;
        ++digits;
    }
    int space = 4 + fontMetrics().width(QLatin1Char('9')) * digits;
    return space+20;
}

void TextEditor::updateAreaNumeroLineaWidth(int a){
    setViewportMargins(areaNumeroLineaWidth(), 0, 0, 0);
}

void TextEditor::updateAreaNumeroLinea(const QRect &rect, int dy){
    if (dy)
        areaNumero->scroll(0, dy);
    else
        areaNumero->update(0, rect.y(), areaNumero->width(), rect.height());

    if (rect.contains(viewport()->rect()))
        updateAreaNumeroLineaWidth(0);
}

void TextEditor::resizeEvent(QResizeEvent *e){
    QPlainTextEdit::resizeEvent(e);

    QRect cr = contentsRect();
    areaNumero->setGeometry(QRect(cr.left(), cr.top(), areaNumeroLineaWidth(), cr.height()));
}

void TextEditor::highlightCurrentLine()
{
    QList<QTextEdit::ExtraSelection> extraSelections;

    if (!isReadOnly()) {
        QTextEdit::ExtraSelection selection;

        QColor lineColor = QColor(Qt::darkGray);

        selection.format.setBackground(lineColor);
        selection.format.setProperty(QTextFormat::FullWidthSelection, true);
        selection.cursor = textCursor();
        selection.cursor.clearSelection();
        extraSelections.append(selection);
    }

    setExtraSelections(extraSelections);
}

void TextEditor::areaNumeroLineaPaintEvent(QPaintEvent *event){
    QPainter painter(areaNumero);
    painter.fillRect(event->rect(), Qt::lightGray);
    QTextBlock block = firstVisibleBlock();
    int blockNumber = block.blockNumber();
    int top = (int) blockBoundingGeometry(block).translated(contentOffset()).top();
    int bottom = top + (int) blockBoundingRect(block).height();
    while (block.isValid() && top <= event->rect().bottom()) {
       if (block.isVisible() && bottom >= event->rect().top()) {
           QString number = QString::number(blockNumber + 1);
           painter.setPen(Qt::black);
           painter.drawText(0, top, areaNumero->width(), fontMetrics().height(),
                            Qt::AlignRight, number);
       }

       block = block.next();
       top = bottom;
       bottom = top + (int) blockBoundingRect(block).height();
       ++blockNumber;
    }
}

void TextEditor::actualizarLinks(){
    int pos = 0;
    vector <pair<int,int> > auxVec;                  //nº escena / linea
    while ((pos = etiqueta->indexIn(toPlainText(), pos)) != -1) {
        int linea = document()->find(etiqueta->cap(0)).blockNumber();
        auxVec.push_back(make_pair(etiqueta->cap(0).remove("<").remove(">").toInt(),linea));
        pos += etiqueta->matchedLength();
    }
    while(!contenedor->layout()->isEmpty()){
        QLayoutItem* aux = contenedor->layout()->takeAt(0);
        delete aux->widget();
    }
    for(int i = 0; i < auxVec.size (); i++){
        contenedor->layout()->addWidget(new LinkEtiqueta(this,auxVec[i].first,auxVec[i].second));
    }
    nEtiquetas = auxVec.size();
}

void TextEditor::setLinea(int ln){
    QTextCursor cursor( doc->findBlockByLineNumber(ln));
    setTextCursor(cursor);
}

void TextEditor::onInsertarEscena(){
    cout<<"Insertando escena"<<endl;
    this->insertPlainText("<" + QString::number(nEtiquetas) + "> ");
}

void TextEditor::onInsertarOpcion(){
    cout<<"Insertando opción"<<endl;
    this->insertPlainText("~ [Texto de la opción] @");
    QTextCursor cursor (doc->find("[Texto de la opción]"));
    this->setTextCursor(cursor);
}

void TextEditor::onInsertarSalto(){
    cout<<"Insertando salto"<<endl;
    this->insertPlainText("@");
}
