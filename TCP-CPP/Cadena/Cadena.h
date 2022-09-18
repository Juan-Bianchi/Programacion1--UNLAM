#ifndef CADENA_H
#define CADENA_H

#include <iostream>
#include <string.h>

using namespace std;


class Cadena
{
private:
    char* cadenaC;

public:
    Cadena();                               ///constructor por defecto
    Cadena(const char* cadenaC);            ///constructor que recibe cadena del tipo C


    Cadena(const Cadena& cadena);           ///constructor de copia que recibe objeto cadena
    ~Cadena();                              ///destructor
    Cadena& operator =(const Cadena& cadena);   ///sobrecarga de asignación

    Cadena& operator +=(const Cadena& cadena);
    Cadena operator +(const Cadena& cadena) const;
    bool operator ==(const Cadena& Cadena) const;
    bool operator !=(const Cadena& cadena) const;
    bool operator <(const Cadena& cadena) const;
    bool operator <=(const Cadena& cadena) const;
    bool operator >(const Cadena& cadena) const;
    bool operator >=(const Cadena& cadena) const;
    char& operator[](unsigned indice);
    const char& operator[](unsigned indice) const;

    const char* getCadena() const;
    int getLongitud() const;

    friend ostream& operator <<(ostream& os, const Cadena& cadena);
    friend istream& operator >>(istream& is, Cadena& cadena);

};




#endif // CADENA_H
