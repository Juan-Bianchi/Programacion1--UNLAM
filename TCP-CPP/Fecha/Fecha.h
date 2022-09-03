#ifndef FECHA_H
#define FECHA_H

//la fecha base es 01/01/1601
#define ANIO_BASE 1601
#define FECHA_INVALIDA 1

class Fecha
{
    private:
        int diaRel;

        static int cantDM[13];
        static int vecDiaAcum[13];
        static int vecDiaAcumBis[13];

        void dmaADiaRel(int dia, int mes, int anio);
        void diaRelADma(int* dia, int* mes, int* anio);
        inline static bool esBisiesto(int anio){return anio % 400 == 0 || (anio % 4 == 0 && anio % 100 != 0);};     //el inline no es necesario
        inline static int cantDiasDelMes(int mes, int anio);   //en este caso el inline es necesario porque la funcion se desarrolla en el .cpp
        static int diasDelAnio(int dia, int mes, int anio);
        static bool esFechaValida(int dia, int mes, int anio);
        static void diaDelAnioADiaMes(int diasAcum, int* dia, int* mes, int anio);

    public:
        Fecha();
        Fecha(int dia, int mes, int anio);

        Fecha sumarDias(int dias) const;
        Fecha restarDias(int dias);
        int diferenciaDias(const Fecha* fecha);
        int diaDeLaSemana()const;
        void incrementarDia();
        
};

#endif // FECHA_H
