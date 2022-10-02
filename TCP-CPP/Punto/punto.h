#ifndef PUNTO_H
#define PUNTO_H

#include <iostream>
#include <stdlib.h>

using namespace std;

class Punto
{
    public:
        Punto();
        Punto(int coordX);
        Punto(int coordX, int coordY);

        Punto(Punto& p);
        ~Punto();

        void mostrar()const;

        Punto& operator +=(Punto& p);
        Punto& operator +=(int desp);
        Punto& operator -=(Punto& p);
        Punto& operator -=(int desp);

        Punto& operator ++();
        Punto operator ++(int);
        Punto& operator --();
        Punto operator --(int);

        bool operator ==(Punto& p);
        bool operator !=(Punto& p);

        friend ostream& operator <<(ostream& os, Punto& p);
        friend istream& operator >>(istream& is, Punto& p);


    private:
        int coordX;
        int coordY;

        Punto* getDirMem();
};

#endif // PUNTO_H
