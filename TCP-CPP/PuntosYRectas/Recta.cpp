#include "Recta.h"
#include <math.h>

Recta::Recta()
{
    Punto punto1;
    Punto punto2;
}

Recta::Recta(const Punto& p1, const Punto& p2)
{
    punto1 = p1;
    punto2 = p2;
}


const Punto Recta::operator &&(const Recta& otraRecta)const
{
    Punto resultado;

    resultado.x = ( ( punto1.x * punto2.y - punto1.y * punto2.x)*(otraRecta.punto1.x - otraRecta.punto2.x) - (punto1.x - punto2.x)*(otraRecta.punto1.x * otraRecta.punto2.y - otraRecta.punto1.y * otraRecta.punto2.x) )/
                  ( ( punto1.x - punto2.x)*(otraRecta.punto1.y - otraRecta.punto2.y) - (punto1.y - punto2.y) * (otraRecta.punto1.x - otraRecta.punto2.x) );

    resultado.y = ( ( punto1.x * punto2.y - punto1.y * punto2.x)*(otraRecta.punto1.y - otraRecta.punto2.y) - (punto1.y - punto2.y)*(otraRecta.punto1.x * otraRecta.punto2.y - otraRecta.punto1.y * otraRecta.punto2.x) )/
                  ( ( punto1.x - punto2.x)*(otraRecta.punto1.y - otraRecta.punto2.y) - (punto1.y - punto2.y) * (otraRecta.punto1.x - otraRecta.punto2.x) );

    return resultado;
}



double Recta::operator -(const Punto& punto)const
{
    double resultado;

    resultado = (abs((punto2.y - punto1.y)*punto.x - (punto2.x - punto1.x)*punto.y + punto2.x * punto1.y - punto2.y * punto1.x)) /
                sqrt((punto2.y - punto1.y)*(punto2.y - punto1.y) + (punto2.x - punto1.x)*(punto2.x - punto1.x));

    return resultado;
}



ostream& operator << (ostream& os, const Recta& recta)
{
    os << "[ " << recta.punto1 << "; " << recta.punto2 << "] ";
    return os;
}
