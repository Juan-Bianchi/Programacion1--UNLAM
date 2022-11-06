#include "Triangulo.h"
#include <math.h>

Triangulo::Triangulo(double base, double altura)
: base(base), altura(altura)
{}


double Triangulo::area()const
{
    return base * altura / 2;
}

