#ifndef TRIANGULO_H
#define TRIANGULO_H

#include "Figura.h"


class Triangulo : public Figura
{
    public:
        Triangulo(double base, double altura);

        double area()const override;
        double perimetro()const override;

    protected:

    private:
        double base;
        double altura;
};

#endif // TRIANGULO_H
