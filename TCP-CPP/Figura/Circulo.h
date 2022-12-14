#ifndef CIRCULO_H
#define CIRCULO_H

#include "Figura.h"

#define PI 3.14159265358979323846


class Circulo : public Figura
{
    public:
        Circulo(double radio);

        double area()const override;
        double perimetro()const override;

    private:
        double radio;
};

#endif // CIRCULO_H
