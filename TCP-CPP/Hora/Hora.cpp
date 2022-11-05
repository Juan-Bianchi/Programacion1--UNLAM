#include "Hora.h"


Hora::Hora(int seg, int minut, int horas)
{
    setHoraRelativa(seg, minut, horas);
}



void Hora::setHoraRelativa(int seg, int minut, int horas)
{
    this->segRel = horas * 3600 + minut * 60 + seg;

}


void Hora::getHoraRelativa(int& seg, int& minut, int& horas)
{
    int minutosTotales = this->segRel / 60;
    minut = minutosTotales % 60;
    seg = this->segRel % 60;
    horas = minutosTotales / 60;
}



Hora Hora::operator  ++(int)
{
    Hora hor(*this);

    this->segRel ++;

    return hor;
}



Hora& Hora::operator --()
{
    -- this->segRel;

    return (*this);
}



Hora Hora::operator --(int)
{
    Hora hor(*this);

    this->segRel --;

    return hor;
}



Hora& Hora::operator += (int seg)
{
    this->segRel += seg;

    return *this;
}



Hora& Hora::operator += (Hora& otraHora)
{
    this->segRel += otraHora.segRel;

    return *this;
}



Hora& Hora::operator -= (int seg)
{
    this->segRel -= seg;

    return *this;
}



Hora& Hora::operator -= (Hora& otraHora)
{
    this->segRel -= otraHora.segRel;

    return *this;
}



ostream& operator << (ostream& os, Hora& hora)
{
    int hor, minuto, segundo;

    hora.getHoraRelativa(segundo, minuto, hor);

    os << hora << " : " << minuto << " : " << segundo << endl;

    return os;
}
