#include "Circulo.h"

Circulo::Circulo(double radio)
: radio(radio)
{}



double Circulo::area()const
{
    return radio * radio * PI;
}


double Circulo::perimetro()const
{
    return radio * PI * 2;
}
