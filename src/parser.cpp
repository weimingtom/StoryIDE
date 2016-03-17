#include "parser.h"

Parser::Parser()
    {
    estado = 'A';
    lineCount = 1;
    hTitulo = "";
    hAutor = "";
    tmpSalto = NULL;
    tmpOpcion = NULL;
    errorCount = 0;
    escenaActual = 0;
}

Historia* Parser::compilar(QString text){
    logs.clear();
    QStringList lineaLista = text.split("\n",QString::KeepEmptyParts);
    foreach (QString linea, lineaLista) {
        if(Regex::autor.indexIn(linea)!=-1){
            hTitulo = Regex::autor.cap(0).remove("#");
        }else if(Regex::titulo.indexIn(linea)!=-1){
            hAutor = Regex::titulo.cap(0).remove("{").remove("}");
        }else if(Regex::comentario.indexIn(linea)!=-1){
            cout<<Regex::comentario.cap(1).toStdString().c_str()<<endl;
        }else{
            QStringList tokenLista = linea.split(" ",QString::KeepEmptyParts);
            foreach (QString token, tokenLista) {
                if(Regex::etiqueta.indexIn(token)!=-1){

                    if(estado == 'A' || estado == 'H' || estado == 'D' || estado == 'F' || estado == 'B'){
                        estado = 'A';
                        escenaActual = token.mid(token.indexOf("<")+1,token.indexOf(">")-1).toInt();

                        if(escenas.find(escenaActual)==escenas.end()){
                            escenas.insert( pair<int,Escena*> (escenaActual,new Escena()) );
                            QString buff = token.mid(token.indexOf(">")+1);
                            if (!buff.isEmpty()) {
                                escenas.at(escenaActual)->addText(buff);
                            }
                            clear();
                            comprobarEtiquetas(escenaActual);
                        }else{
                            error* tmp = new error;
                            tmp->text = "La escena " + QString::number(escenaActual) + "se define dos veces";
                            tmp->tipo = ERROR;
                            tmp->linea = lineCount;
                            logs.push_back(tmp);
                        }
                    }else{
                        errores(token);
                    }

                }else if(Regex::saltoIncondicional.indexIn(token)!=-1){
                    if(escenas.size()>0){
                        int idSalto = token.mid(token.indexOf("@")+1).toInt();
                        comprobarEtiquetas(idSalto);
                        if(estado == 'A'){
                            escenas.at(escenaActual)->addSalto(new SaltoIncondicional(idSalto));
                            cout<<"Añadido salto "<<token.mid(token.indexOf("@")+1).toStdString()<<endl;
                            posiblesBucles.insert(pair<Escena*,short> (escenas.at(escenaActual),C_DESCONOCIDO));
                            estado = 'B';
                        }else if(estado == 'C'){
                            tmpOpcion->salto = new SaltoIncondicional(idSalto);
                            escenas.at(escenaActual)->addOpcion(tmpOpcion);
                            cout<<"Añadido salto de opción "<<token.mid(token.indexOf("@")+1).toStdString()<<endl;
                            clear();
                            estado = 'D';
                        }else{
                            errores(token);
                        }
                    }else{
                        errores(token);
                    }

                }else if(Regex::opcion.indexIn(token)!=-1){
                    //estado = 'C';
                    if(estado == 'A' || estado == 'D'){
                        tmpOpcion = new Opcion;
                        tmpOpcion->text = token.mid(token.indexOf("~")+1);
                        estado = 'C';
                    }else{
                        errores(token);
                    }

                }else{
                    if(estado == 'C'){
                        tmpOpcion->text.append(token+" ");
                    }else if (estado == 'A'){
                        if(escenas.size()>0){
                            escenas.at(escenaActual)->addText(token);
                        }
                    }else if (Regex::blancos.indexIn(token) != -1 && !token.isEmpty()){
                        error* tmp = new error;
                        tmp->text = "No se esperaba el símbolo " + token;
                        tmp->tipo = WARNING;
                        tmp->linea = lineCount;
                        logs.push_back(tmp);
                    }
                }
            }
        }
        lineCount++;
    }
    comprobarErroresFinales();
    for(pair<Escena*,short> E : posiblesBucles){
        comprobarBucles(E.first);
    }
    if(logs.size()>0)
        return NULL;
    else{
        crearHistoria();
        return hResultado;
    }
}

void Parser::errores(QString token){
    error* tmp = new error;
    tmp->text = "No se esperaba el elemento " + token;
    tmp->tipo = ERROR;
    tmp->linea = lineCount;
    logs.push_back(tmp);
}

void Parser::clear(){
    tmpSalto = NULL;
    tmpOpcion = NULL;
}

void Parser::comprobarEtiquetas(int i){
    if(escenas.find(i) == escenas.end()){
        etiquetasSinDeclarar.push_back(i);
    }else{
        etiquetasSinDeclarar.removeAll(i);
    }
}

void Parser::comprobarErroresFinales(){
    if((estado!= 'D' && estado!= 'A' && estado!= 'B')){
        error* tmp = new error;
        tmp->text = "Sentencia sin finalizar";
        tmp->tipo = ERROR;
        tmp->linea = lineCount;
        logs.push_back(tmp);
    }
    if(etiquetasSinDeclarar.size()>0){
        for(int tag : etiquetasSinDeclarar){
            error* tmp = new error;
            tmp->text = "La escena " + QString::number(tag) + " es referenciada pero no ha sido declarada";
            tmp->tipo = UNDEFINED;
            logs.push_back(tmp);
        }
    }
    if( escenas.find(0) == escenas.end()){
        error* tmp = new error;
        tmp->text = "Error, es necesario definir la escena 0";
        tmp->tipo = UNDEFINED;
        logs.push_back(tmp);
    }
    if(hTitulo.isEmpty()){
        error* tmp = new error;
        tmp->text = "No se ha definido un título";
        tmp->tipo = UNDEFINED;
        logs.push_back(tmp);
    }
    if(hAutor.isEmpty()){
        error* tmp = new error;
        tmp->text = "No se ha definido un autor";
        tmp->tipo = UNDEFINED;
        logs.push_back(tmp);
    }
}

void Parser::crearHistoria(){
    hResultado = new Historia(hTitulo,hAutor,escenas);
}

vector<error*> Parser::getLogs(){
    return logs;
}

short Parser::comprobarBucles(Escena* E){
    if(posiblesBucles.at(E) != C_VISITADO && posiblesBucles.at(E) != C_BUCLE){
        if(E->getSalto()==-1){
            posiblesBucles.at(E) = C_NO_GENERA;
            return C_NO_GENERA;
        }else{
            posiblesBucles.at(E) = C_VISITADO;
            short value = comprobarBucles(escenas.at(E->getSalto()));
            if(value == C_BUCLE){
                error* tmp = new error;
                tmp->text = "La escena " + QString::number(E->getSalto()) + " genera un bucle";
                tmp->tipo = UNDEFINED;
                logs.push_back(tmp);
            }
            posiblesBucles.at(E) = value;
            return value;
        }
    }else{
        return C_BUCLE;
    }
}

