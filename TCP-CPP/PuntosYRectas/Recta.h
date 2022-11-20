#ifndef RECTA_H
#define RECTA_H

#include "Punto.h"
#include <iostream>


using namespace std;

class Recta : public Punto
{
    public:
        Recta();
        Recta(const Punto& p1, const Punto& p2);

        const Punto operator &&(const Recta& otraRecta)const;
        double operator -(const Punto& punto)const;

        friend ostream& operator << (ostream& os, const Recta& recta);


    private:
        Punto punto1;
        Punto punto2;
};

#endif // RECTA_H
