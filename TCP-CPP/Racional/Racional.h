#ifndef RACIONAL_H
#define RACIONAL_H

#include <iostream>

using namespace std;

class Racional
{
private:

    int numerador;
    int denominador;

    void racionalIrreducible(int& num, int& den);



public:

    Racional();
    Racional(int num, int den);

    Racional operator +(const Racional otroRac)const;
    Racional operator *(const Racional otroRac)const;

    double real()const;


    friend Racional operator +(int escalar, const Racional& racional);
    friend ostream& operator << (ostream& os, const Racional& racional);

};

#endif // RACIONAL_H
