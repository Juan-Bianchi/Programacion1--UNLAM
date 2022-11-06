#ifndef FECHA_H
#define FECHA_H

//la fecha base es 01/01/1601
#define ANIO_BASE 1601
#define FECHA_INVALIDA 1

#include <iostream>

class Cadena;

using namespace std;


class Fecha
{
    private:
        int diaRel;

        static int cantDM[13];
        static int vecDiaAcum[14];
        static int vecDiaAcumBis[14];


        inline static bool esBisiesto(int anio){return anio % 400 == 0 || (anio % 4 == 0 && anio % 100 != 0);};     //el inline no es necesario
        inline static int cantDiasDelMes(int mes, int anio);   //en este caso el inline es necesario porque la funcion se desarrolla en el .cpp
        static int diasDelAnio(int dia, int mes, int anio);
        static bool esFechaValida(int dia, int mes, int anio);
        static void diaDelAnioADiaMes(int diasAcum, int& dia, int& mes, int anio);

    public:
        Fecha();
        Fecha(int dia, int mes, int anio);
        Fecha(const Cadena& cad);

        Fecha sumarDias(int dias) const;
        Fecha restarDias(int dias);
        int diferenciaDias(const Fecha* fecha);
        int diaDeLaSemana()const;
        void incrementarDia();
        void getDma(int& dia, int& mes, int& anio)const;
        void setDma(int dia, int mes, int anio);

        static Fecha& getHoy();

        Fecha operator +(int dias) const;
        Fecha& operator += (int dias);
        Fecha& operator -= (int dias);
        Fecha operator -(int dias)const;
        int operator -(const Fecha& f2)const;
        Fecha& operator ++();                             //Preincremento
        Fecha operator ++(int);                           //Posincremento
        Fecha& operator --();                             //Predecremento
        Fecha operator --(int);                           //Posdecremento

        friend ostream& operator <<(ostream& os, const Fecha& fecha);
        friend istream& operator >>(istream& is, Fecha& fecha);

};


#endif // FECHA_H
