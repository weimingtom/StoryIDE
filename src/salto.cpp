#include "salto.h"

Salto::Salto()
{

}

SaltoIncondicional::SaltoIncondicional(int tagId){
    tag = tagId;
}

int const SaltoIncondicional::saltar(){
    return tag;
}
