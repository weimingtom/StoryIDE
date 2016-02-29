#ifndef JUGAR_H
#define JUGAR_H

#include "historia.h"

#include <QWidget>
#include <QGroupBox>
#include <QGridLayout>

class Jugar : public QWidget{
private:
    QGridLayout* lay;
public:
    Jugar(QWidget* parent);
};

#endif // JUGAR_H
