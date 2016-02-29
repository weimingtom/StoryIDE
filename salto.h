#ifndef SALTO_H
#define SALTO_H


class Salto{
public:
    Salto();
    virtual int const saltar() = 0;
};

class SaltoIncondicional : public Salto{
private:
    int tag;
public:
    SaltoIncondicional(int tagId);
    int const saltar();
};

class SaltoProbabilistico : public Salto{
public:
    SaltoProbabilistico();
    int const saltar();
};

#endif // SALTO_H
