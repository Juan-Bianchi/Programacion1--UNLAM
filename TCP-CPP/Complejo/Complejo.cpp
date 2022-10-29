#include "Complejo.h"

Complejo::Complejo()
{
    this->real = 0;
    this->imaginario = 0;
}


Complejo::Complejo(double r, double i)
{
    this->real = r;
    this->imaginario = i;
}



Complejo::Complejo(Complejo& comp)
{
    this->real = comp.real;
    this->imaginario = comp.imaginario;
}




Complejo& Complejo::operator = (Complejo& comp)
{
    this->real = comp.real;
    this->imaginario = comp.imaginario;

    return *this;
}

Complejo Complejo::operator + (Complejo& comp)const
{
    Complejo complejo;

    complejo.real = this->real + comp.real;
    complejo.imaginario = this->imaginario + comp.imaginario;

    return complejo;
}



Complejo Complejo::operator - (Complejo& comp)const
{
    Complejo complejo;

    complejo.real = this->real - comp.real;
    complejo.imaginario = this->imaginario - comp.imaginario;

    return complejo;
}



Complejo Complejo::operator / (Complejo& comp)const
{
    Complejo complejo;

    complejo.real = ((this->real * comp.real + this->imaginario * comp.imaginario) / (comp.real * comp.real + comp.imaginario * comp.imaginario));
    complejo.imaginario = ((this->imaginario * comp.real + this->real * comp.imaginario) / (comp.real * comp.real + comp.imaginario * comp.imaginario));

    return complejo;
}



Complejo Complejo::operator * (Complejo& comp)const
{
    Complejo complejo;

    complejo.real = this->real * comp.real - this->imaginario * comp.imaginario;
    complejo.imaginario = this->real * comp.imaginario + this->imaginario * comp.real;

    return complejo;
}



Complejo& Complejo::operator += (Complejo& comp)
{
    this->real += comp.real;
    this->imaginario += comp.imaginario;

    return *this;
}



Complejo& Complejo::operator -= (Complejo& comp)
{
    this->real -= comp.real;
    this->imaginario -= comp.imaginario;

    return *this;
}



Complejo operator *(Complejo& comp, double num)
{
    Complejo complejo;

    complejo.real = num * comp.real;
    complejo.imaginario = num * comp.imaginario;

    return complejo;
}



ostream& operator <<(ostream& os, Complejo& comp)
{
    os << "( " << comp.real << ", " << comp.imaginario << ") ";

    return os;
}
