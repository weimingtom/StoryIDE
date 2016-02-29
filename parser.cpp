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
    escenaActual = 0;
}

map<int,Escena*> Parser::compilar(QString text){

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
                        escenaActual = token.mid(token.indexOf("<")+1,token.indexOf(">")-1).toInt();

                        if(escenas.find(escenaActual)==escenas.end()){
                            escenas.insert( pair<int,Escena*> (escenaActual,new Escena()) );
                            escenas.at(escenaActual)->addText(token.mid(token.indexOf(">")+1));
                            clear();
                            cout<<"Creada una escena"<<endl;
                        }else{
                            cout<<"[!] Error, la escena "<<escenaActual<<" se define dos veces"<<endl;
                        }
                    }else{
                        errores(token);
                    }

                }else if(saltoIncondicional->indexIn(token)!=-1){
                    if(escenas.size()>0){
                        int idSalto = token.mid(token.indexOf("@")+1).toInt();
                        comprobarEtiquetas(idSalto);
                        if(estado == 'A'){
                            escenas.at(escenaActual)->addSalto(new SaltoIncondicional(idSalto));
                            cout<<"Añadido salto "<<token.mid(token.indexOf("@")+1).toStdString()<<endl;
                            estado = 'B';
                        }else if(estado == 'C'){
                            tmpOpcion->salto = new SaltoIncondicional(idSalto);
                            escenas.at(escenaActual)->addOpcion(tmpOpcion);
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
                    else{
                        if(escenas.size()>0)
                            escenas.at(escenaActual)->addText(token);
                    }
                }
            }
        }
        lineCount++;
    }
    if((estado!= 'D' && estado!= 'A' && estado!= 'B')){
        cout<<"[!] Error, sentencia sin finalizar en la linea "<<lineCount<<endl;
        errorCount++;
    }
    if(etiquetasSinDeclarar.size()>0){
        cout<<"[!] Error, saltos a escenas sin definir"<<endl;
        errorCount++;
    }
    if(!escenas.count(0)){
        cout<<"[!] Error, es necesario definir la escena 0"<<endl;
        errorCount++;
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

void Parser::comprobarEtiquetas(int i){
    if(escenas.count(i)==0){
        etiquetasSinDeclarar.push_back(i);
    }else if (escenas.count(i)==1){
        etiquetasSinDeclarar.removeAll(i);
    }
}

