#include "Cuadrado.h"

Cuadrado::Cuadrado(double lado)
{
    this->lado = lado;
}



double Cuadrado::area()const
{
    return lado * 4;
}



double Cuadrado::perimetro()const
{
    return lado * lado;
}
