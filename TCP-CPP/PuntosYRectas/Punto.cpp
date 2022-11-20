#include "Punto.h"

Punto::Punto()
:x(0), y(0)
{}


Punto::Punto(double x, double y)
: x(x), y(y)
{}



ostream& operator << (ostream& os, const Punto& punto)
{
    os << "(" << punto.x << ", " << punto.y << ") ";
    return os;
}
