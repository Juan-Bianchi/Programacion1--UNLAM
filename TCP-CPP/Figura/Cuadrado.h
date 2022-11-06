#ifndef CUADRADO_H
#define CUADRADO_H

#include "Figura.h"


class Cuadrado : public Figura
{
    public:
        Cuadrado(double lado);
        double area()const override;
        double perimetro()const override;

    protected:

    private:
        double lado;
};

#endif // CUADRADO_H
