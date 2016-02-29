#include "parser.h"

Parser::Parser(){
    autor = new QRegExp("#(\\w)+((\\s|\\w))*#");      //Cualquier conjunto de palabras encerrada en '#', la primera pegada a '#'
    titulo = new QRegExp("\\{(\\w)+((\\s|\\w))*\\}"); //Cualquier conjunto de palabras encerrada en '{}', la primera pegada a '{'
    etiqueta = new QRegExp("(<(\\d)+>)");               //Cualquier número encerrado en '<>'
    saltoIncondicional = new QRegExp("(@(\\d)+)");      //'@' seguido de cualquier número
    saltoProbabilistico = new QRegExp("(%(\\d)+)");     //'%' seguido de cualquier número
    opcion = new QRegExp("(\\~)");          //'~'
    comentario = new QRegExp("([\\/]{2})");
    bloqueProbabilistico = new QRegExp("\\(((\\d+)(\\s+))+@(\\d+)\\)");
    estado = 'A';
    lineCount = 1;
    hTitulo = "";
    hAutor = "";
    tmpSalto = NULL;
    tmpOpcion = NULL;
    errorCount = 0;
}

vector<Escena*> Parser::compilar(QString text){

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

                    if(estado == 'A' || estado == 'H' || estado == 'D' || estado == 'F' || estado == 'B'){
                        estado = 'A';
                        escenas.push_back(new Escena());
                        escenas.back()->addText(token.mid(token.indexOf(">")+1));
                        clear();
                        cout<<"Creada una escena"<<endl;
                    }else{
                        errores(token);
                    }

                }else if(saltoIncondicional->indexIn(token)!=-1){
                    if(escenas.size()>0){
                        if(estado == 'A'){
                            escenas.back()->addSalto(new SaltoIncondicional(token.mid(token.indexOf("@")+1).toInt()));
                            cout<<"Añadido salto "<<token.mid(token.indexOf("@")+1).toStdString()<<endl;
                            estado = 'B';
                        }else if(estado == 'C'){
                            tmpOpcion->salto = new SaltoIncondicional(token.mid(token.indexOf("@")+1).toInt());
                            escenas.back()->addOpcion(tmpOpcion);
                            clear();
                            cout<<"Añadido salto de opción "<<token.mid(token.indexOf("@")+1).toStdString()<<endl;
                            estado = 'D';
                        }else{
                            errores(token);
                        }
                    }else{
                        errores(token);
                    }

                }else if(opcion->indexIn(token)!=-1){
                    estado = 'C';
                    if(estado == 'A' || estado == 'D' || estado == 'C'){
                        cout<<"Añadida opción"<<endl;
                        tmpOpcion = new Opcion;
                        tmpOpcion->text = token.mid(token.indexOf("~")+1);
                        estado = 'C';
                    }else{
                        errores(token);
                    }

                }else{
                    if(estado == 'C')
                        tmpOpcion->text.append(token+" ");
                    else
                        escenas.back()->addText(token);
                }
            }
        }
        lineCount++;
    }
    if(errorCount>0)
        escenas.clear();
    return escenas;
}

void Parser::errores(QString token){
    cout<<"[!] Error en la línea "<<lineCount<<", no se esperaba "<<token.toStdString()<<". Estado "<<estado<<endl;
    errorCount++;
}

void Parser::clear(){
    tmpSalto = NULL;
    tmpOpcion = NULL;
}

