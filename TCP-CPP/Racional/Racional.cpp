#include "Racional.h"


Racional::Racional()
: numerador(0), denominador(1)
{}


Racional::Racional(int num, int den)
{
    this->racionalIrreducible(num, den);

    this->numerador = num;
    this->denominador = den;
}


void Racional::racionalIrreducible(int& num, int& den)
{
    int divisor = 2;

    while (divisor <= num && divisor <= den)
    {
        int restNum = num % divisor;
        int restDen = den % divisor;

        if((restDen == 0) && (restNum == 0))
        {
            num /= divisor;
            den /= divisor;
        }
        else
            divisor ++;
    }
}



Racional Racional::operator +(const Racional otroRac)const
{
    Racional resultado;

    if(this->denominador == otroRac.denominador)
    {
        resultado.denominador = this->denominador;
        resultado.numerador = this->numerador + otroRac.numerador;
    }
    else
    {
        resultado.denominador = this->denominador * otroRac.denominador;
        resultado.numerador = this->numerador * otroRac.denominador + otroRac.numerador * this->denominador;
    }

    resultado.racionalIrreducible(resultado.numerador, resultado.denominador);

    return resultado;
}



Racional Racional::operator *(const Racional otroRac)const
{
    Racional resultado;

    resultado.numerador = this->numerador * otroRac.numerador;
    resultado.denominador = this->denominador * otroRac.denominador;

    resultado.racionalIrreducible(resultado.numerador, resultado.denominador);

    return resultado;
}



Racional operator +(int escalar, const Racional& racional)
{
    Racional resultado;

    resultado.denominador = racional.denominador;
    resultado.numerador = escalar * racional.denominador + racional.numerador;

    resultado.racionalIrreducible(resultado.numerador, resultado.denominador);

    return resultado;
}



double Racional::real()const
{
    double resultado = (double)this->numerador / this->denominador;

    return resultado;
}


ostream& operator << (ostream& os, const Racional& racional)
{
     os << "( " << racional.numerador << " / " << racional.denominador << " )";
     return os;
}
