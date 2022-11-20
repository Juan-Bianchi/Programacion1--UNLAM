#ifndef PUNTO_H
#define PUNTO_H

#include <iostream>

using namespace std;

class Punto
{
    public:
        Punto();
        Punto(double x, double y);

        friend ostream& operator << (ostream& os, const Punto& punto);

        friend class Recta;

    protected:

    private:
        double x;
        double y;

};

#endif // PUNTO_H
