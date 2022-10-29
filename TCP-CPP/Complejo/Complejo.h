#ifndef COMPLEJO_H
#define COMPLEJO_H

#include <iostream>


using namespace std;

class Complejo
{
    public:
        Complejo();
        Complejo(double r, double i);
        Complejo(Complejo& comp);

        Complejo& operator = (Complejo& comp);

        Complejo operator + (Complejo& comp)const;
        Complejo operator - (Complejo& comp)const;
        Complejo operator / (Complejo& comp)const;
        Complejo operator * (Complejo& comp)const;

        Complejo& operator += (Complejo& comp);
        Complejo& operator -= (Complejo& comp);


        friend Complejo operator *(Complejo& comp, double num);

        friend ostream& operator <<(ostream& os, Complejo& comp);

    private:
        double real;
        double imaginario;

};

#endif // COMPLEJO_H
