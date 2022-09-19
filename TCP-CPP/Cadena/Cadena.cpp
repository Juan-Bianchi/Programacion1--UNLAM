#include "Cadena.h"

Cadena::Cadena()
{
    this->cadenaC = new char[1];
    this->cadenaC[0] = '\0';
}



Cadena::Cadena(const char* cadenaC)
{
    this->cadenaC = new char[strlen(cadenaC) + 1];
    strcpy(this->cadenaC, cadenaC);
}



Cadena::Cadena(const Cadena& cadena)
{
    this->cadenaC = new char[strlen(cadena.cadenaC) + 1];
    strcpy(this->cadenaC, cadena.cadenaC);
}



Cadena::~Cadena()
{
    delete[] this->cadenaC;
}



Cadena& Cadena::operator =(const Cadena& cadena)
{
    if(this == &cadena)
        return *this;

    if(strlen(this->cadenaC) != strlen(cadena.cadenaC))
    {
        delete[] this->cadenaC;
        this->cadenaC = new char[strlen(cadena.cadenaC) + 1];
    }
    strcpy(this->cadenaC, cadena.cadenaC);

    return *this;
}


/*
Cadena& Cadena::operator +=(const Cadena& cadena)
{

}

*/

Cadena Cadena::operator +(const Cadena& cadena) const
{
    Cadena cadConcat;

    delete[] cadConcat.cadenaC;
    cadConcat.cadenaC = new char[strlen(this->cadenaC) + strlen(cadena.cadenaC) + 1];

    strcpy(cadConcat.cadenaC, this->cadenaC);
    strcat(cadConcat.cadenaC, cadena.cadenaC);

    return cadConcat;
}

/*

bool Cadena::operator ==(const Cadena& cadena) const
{

}



bool operator !=(const Cadena& cadena) const;
bool operator <(const Cadena& cadena) const;
bool operator <=(const Cadena& cadena) const;
bool operator >(const Cadena& cadena) const;
bool operator >=(const Cadena& cadena) const;
char& operator[](unsigned indice);
const char& operator[](unsigned indice) const;

const char* getCadena() const;
int getLongitud() const;*/


ostream& operator <<(ostream& os, const Cadena& cadena)
{
    os << cadena.cadenaC << endl;

    return os;
}



istream& operator >>(istream& is, Cadena& cadena);
