#ifndef CADENA_H
#define CADENA_H

#include <iostream>
#include <string.h>
#include <queue>
#include <stdio.h>

using namespace std;


class Cadena
{
private:
    char* cadenaC;
    static int cantDigitos(int num);

public:
    Cadena();                               ///constructor por defecto
    Cadena(const char* cadenaC);            ///constructor que recibe cadena del tipo C
    Cadena(const char letra);               ///constructor que recibe letra
    Cadena(const int num);                  ///constructor que recibe un int

    Cadena(const Cadena& otra);             ///constructor de copia que recibe objeto cadena
    ~Cadena();                              ///destructor
    Cadena& operator =(const Cadena& otra);   ///sobrecarga de asignación

    Cadena& operator +=(const Cadena& cadena);

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
    friend Cadena operator +(const Cadena& cad1, const Cadena& cad2);           ///uno de los dos objetos tiene que ser de la clase cadena. Si uno lo es, tratará de convertir al otro, no importa de que lado del operador esté.

};



#endif // CADENA_H
