#include "Punto.h"
#include <iostream>



Punto* Punto::getDirMem()
{
    return this;
}


Punto::Punto()
{
    this->coordX = 511;
    this->coordY = 383;
}


Punto::Punto(int coordX, int coordY)
{
    this->coordX = coordX;

    while(coordX<0)
        this->coordX = 1024 + coordX;

    while(coordX>1023)
        this->coordX = coordX - 1024;

    this->coordY = coordY;

    while(coordY<0)
        this->coordY = 767 + coordY;

    while(coordY>767)
        this->coordY = coordY - 768;
}



Punto::Punto(int coordX)
{
    this->coordX = coordX;

    while(coordX<0)
        this->coordX = 1024 + coordX;

    while(coordX>1023)
        this->coordX = coordX - 1024;

    if(coordX == 0)
        this->coordY = 0;
    else
        this->coordY = coordX * 767 / 1023;
}



Punto::Punto(Punto& p)
{
    this->coordX = p.coordX;
    this->coordY = p.coordY;
}


Punto::~Punto()
{
    //system("chcp 1252 > NULL");
    //cout << "Se destruyó el punto " << "(" << this->coordX << ", " << this->coordY << ")" << " en la posición de memoria "<< this->getDirMem()<<endl;
}

void Punto::mostrar() const
{
    cout << "(" << this->coordX << ", " << this->coordY << ")" << endl;
}


Punto& Punto::operator +=(Punto& p)
{
    this->coordX += p.coordX;
    this->coordY += p.coordY;

    while(this->coordX > 1023)
        this->coordX = this->coordX - 1024;

    while(this->coordY > 767)
        this->coordY = this->coordY - 768;

    return *this;
}



Punto& Punto::operator +=(int desp)
{
    this->coordX += desp;
    this->coordY += desp;

    while(this->coordX > 1023)
        this->coordX = this->coordX - 1024;

    while(this->coordY > 767)
        this->coordY = this->coordY - 768;

    return *this;
}



Punto& Punto::operator -=(Punto& p)
{
    this->coordX -= p.coordX;
    this->coordY -= p.coordY;

    while(this->coordX < 0)
        this->coordX = 1024 + this->coordX;

    while(this->coordY < 0)
        this->coordY = 768 + this->coordY;

    return *this;
}



Punto& Punto::operator -=(int desp)
{
    this->coordX -= desp;
    this->coordY -= desp;

    while(this->coordX < 0)
        this->coordX = 1024 + this->coordX;

    while(this->coordY < 0)
        this->coordY = 768 + this->coordY;

    return *this;
}



Punto& Punto::operator ++()
{
    ++ this->coordX;
    ++ this->coordY;

    if(this->coordX > 1023)
        this->coordX = this->coordX - 1024;

    if(this->coordY > 767)
        this->coordY = this->coordY - 768;

    return *this;
}



Punto Punto::operator ++(int)
{
    Punto p = *this;

    this->coordX ++;
    this->coordY ++;

    if(this->coordX > 1023)
        this->coordX = this->coordX - 1024;

    if(this->coordY > 767)
        this->coordY = this->coordY - 768;

    return p;
}



Punto& Punto::operator --()
{
    -- this->coordX;
    -- this->coordY;

    if(this->coordX < 0)
        this->coordX = 1024 + this->coordX;

    if(this->coordY < 0)
        this->coordY = 767 + this->coordY;

    return *this;
}



Punto Punto::operator --(int)
{
    Punto p = *this;

    this->coordX --;
    this->coordY --;

    if(this->coordX < 0)
        this->coordX = 1024 + this->coordX;

    if(this->coordY < 0)
        this->coordY = 767 + this->coordY;

    return p;
}



bool Punto::operator ==(Punto& p)
{
    return this->coordX == p.coordX && this->coordY == p.coordY;
}



bool Punto::operator !=(Punto& p)
{
    return this->coordX != p.coordX || this->coordY != p.coordY;
}



ostream& operator <<(ostream& os, Punto& p)
{
    os << "(" << p.coordX << ", " << p.coordY << ")";

    return os;
}



istream& operator >>(istream& is, Punto& p)
{
    char coma;

    cin >> p.coordX >> coma >> p.coordY;

    return is;
}
