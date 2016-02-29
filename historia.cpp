#include "historia.h"

Historia::Historia(){
    autor = new QRegExp("#(\\w)+((\\s|\\w))*#");      //Cualquier conjunto de palabras encerrada en '#', la primera pegada a '#'
    titulo = new QRegExp("\\{(\\w)+((\\s|\\w))*\\}"); //Cualquier conjunto de palabras encerrada en '{}', la primera pegada a '{'
    etiqueta = new QRegExp("(<(\\d)+>)");               //Cualquier número encerrado en '<>'
    saltoIncondicional = new QRegExp("(@(\\d)+)");      //'@' seguido de cualquier número
    saltoProbabilistico = new QRegExp("(%(\\d)+)");     //'%' seguido de cualquier número
    opcion = new QRegExp("(\\~)");          //'~'
    comentario = new QRegExp("([\\/]{2})");
    bloqueProbabilistico = new QRegExp("\\(\\d\\,@(\\d)\\)");
}

QString Historia::parser(QString text){
    char estado = 'O';
    QString buffer;
    tempHistoria tmp;
    QStringList lineaLista = text.split("\n",QString::KeepEmptyParts);
    foreach (QString linea, lineaLista) {
        if(autor->indexIn(linea)!=-1){
            hTitulo = autor->cap(0).remove("#");
        }else if(titulo->indexIn(linea)!=-1){
            hAutor = titulo->cap(0).remove("{").remove("}");
        }else if(comentario->indexIn(linea)!=-1){
            cout<<comentario->cap(1).toStdString().c_str()<<endl;
        }else{
            QStringList tokenLista = linea.split(" ",QString::KeepEmptyParts);
            foreach (QString token, tokenLista) {

                if(etiqueta->indexIn(token)!=-1){
                    buffer.append(token.mid(token.indexOf(">")+1));
                    if(estado == 'O'){
                        estado = 'A';
                    }else if(estado == 'A'){
                        escenas.push_back(new Escena(buffer));
                    }else if(estado == 'H'){
                        escenas.push_back(new Escena(buffer));
                    }else if(estado == 'D'){
                        escenas.push_back(new Escena(buffer));
                    }else if(estado == 'F'){
                        escenas.push_back(new Escena(buffer));
                    }else if(estado == 'B'){
                        estado = 'A';
                        escenas.push_back(new Escena(buffer));
                    }else{
                        cout<<"Error <0>"<<endl;
                    }
                }else if(saltoIncondicional->indexIn(token)!=-1){
                    if(estado == 'A'){
                        estado = 'B';
                    }else if(estado == 'C'){
                        estado = 'D';
                    }else{
                        cout<<"Error @"<<endl;
                    }
                }else if(opcion->indexIn(token)!=-1){
                    estado = 'C';
                    if(estado == 'A'){

                    }else if(estado == 'D'){

                    }else if(estado == 'H'){

                    }else{
                        cout<<"Error ~";
                    }
                }else{
                    buffer.append(token+" ");
                }
            }
        }
    }
}
