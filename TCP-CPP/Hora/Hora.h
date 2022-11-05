#ifndef HORA_H
#define HORA_H

#include <iostream>

using namespace std;

class Hora
{
    public:
        inline Hora(): segRel(1){};
        Hora(int seg, int minut, int horas);
        inline Hora(Hora& hor): segRel(hor.segRel){};


        void setHoraRelativa(int seg, int minut, int horas);
        void getHoraRelativa(int& seg, int& minut, int& horas);

        inline Hora& operator ++(){++ this->segRel; return *this;};
        Hora operator  ++(int);
        Hora& operator --();
        Hora operator --(int);
        Hora& operator += (int seg);
        Hora& operator += (Hora& otraHora);
        Hora& operator -= (int seg);
        Hora& operator -= (Hora& otraHora);
        inline bool operator == (Hora& otraHora)const{return this->segRel == otraHora.segRel;};
        inline bool operator != (Hora& otraHora)const{return this->segRel != otraHora.segRel;};
        inline bool operator < (Hora& otraHora)const{return this->segRel < otraHora.segRel;};
        inline bool operator > (Hora& otraHora)const{return this->segRel > otraHora.segRel;};
        inline bool operator <= (Hora& otraHora)const{return this->segRel <= otraHora.segRel;};
        inline bool operator >= (Hora& otraHora)const{return this->segRel >= otraHora.segRel;};

        friend ostream& operator << (ostream& os, Hora& hora);

    private:
        int segRel;
};

#endif // HORA_H
