#include "Fecha.h"

#define MENOR -1
#define IGUAL 0
#define MAYOR 1

int esBisiesto(const int anio);
int cantDiasXMes(const int mes, const int anio);
int esMenorIgualOMayorFecha(const tFecha* fecha1, const tFecha* fecha2);

/*Ejercicio 14
Desarrollar una función que determine si una fecha es formalmente correcta.*/

int esFechaValida(const tFecha* fecha)
{
    return fecha->anio > 1601 && fecha->mes >= 1 && fecha->mes <= 12 && fecha->dia >= 1 && fecha->dia <= cantDiasXMes(fecha->mes, fecha->anio);
}

int esBisiesto(const int anio)
{
    return anio % 400 == 0 || ( anio % 4 == 0 && anio % 100 != 0);
}

int cantDiasXMes(const int mes, const int anio)
{
    const int cantDiasMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(mes==2)
        return cantDiasMes[mes-1] + esBisiesto(anio);

    return cantDiasMes[mes-1];
}


void ingresarFechaValida(tFecha* fecha)
{
    int esValido;

    do
    {
        printf("Ingrese una fecha para verificar si la misma es válida (dd/mm/aaaa): ");
        fflush(stdin);
        scanf("%d/%d/%d", &fecha->dia, &fecha->mes, &fecha->anio);
        fflush(stdin);
        esValido = esFechaValida(fecha);
        if(!esValido)
            printf("La fecha ingresada no es válida, vuelva a ingresar: ");
    } while(!esValido);
}


/*Ejercicio 15
Desarrollar una función que a partir de una fecha obtenga la correspondiente al día siguiente.*/


void sumaUnDiaAFecha(const tFecha* fecha, tFecha* fechaModif)
{
    fechaModif->dia = fecha->dia + 1;
    fechaModif->mes = fecha->mes;
    fechaModif->anio = fecha->anio;

    if(fechaModif->dia > cantDiasXMes(fecha->mes, fecha->anio))
    {
        fechaModif->dia = 1;
        fechaModif->anio = fecha->anio + fecha->mes / 12;
        if(fecha->mes==12)
            fechaModif->mes = 1;
        else
            fechaModif->mes = fecha->mes + 1;
    }
}

/*Ejercicio 16
Desarrollar una función que a partir de una fecha obtenga la que resulte de sumarle N días.*/

void sumarNDiasAFecha(const tFecha* fecha, const int cantDias, tFecha* fechaModif)
{
    fechaModif->dia = fecha->dia + cantDias;
    fechaModif->mes = fecha->mes;
    fechaModif->anio = fecha->anio;

    while(fechaModif->dia > cantDiasXMes(fechaModif->mes, fechaModif->anio))
    {
        fechaModif->dia -= cantDiasXMes(fechaModif->mes, fechaModif->anio);
        if(fechaModif->mes == 12)
        {
            fechaModif->mes = 1;
            fechaModif->anio ++;
        }
        else
            fechaModif->mes ++;
    }
}


void sumarNDiasAFechaInSitu(tFecha* fecha, const int cantDias)
{
    int cantD;

    fecha->dia += cantDias;

    cantD = cantDiasXMes(fecha->mes, fecha->anio);
    while(fecha->dia > cantD)
    {
        fecha->anio += fecha->mes / 12;

        if(fecha->mes == 12)
            fecha->mes = 1;
        else
            fecha->mes ++;

        fecha->dia -= cantD;

        cantD = cantDiasXMes(fecha->mes, fecha->anio);
    }
}



/*Ejercicio 17
Desarrollar una función que a partir de una fecha obtenga la que resulte de restarle N días.*/

void restarNDiasAFecha(const tFecha* fecha, const int cantDias, tFecha* fechaModif)
{
    fechaModif->dia = fecha->dia - cantDias;
    fechaModif->mes = fecha->mes;
    fechaModif->anio = fecha->anio;

    while(fechaModif->dia<1)
    {
        if(fechaModif->mes==1)
        {
            fechaModif->mes = 12;
            fechaModif->anio --;
        }
        else
            fechaModif->mes --;

        fechaModif->dia += cantDiasXMes(fechaModif->mes, fechaModif->anio);
    }
}



void restarNDiasAFechaInSitu(tFecha* fecha, const int cantDias)
{
    int cantD;

    fecha->dia -= cantDias;

    while(fecha->dia < 1)
    {
        if(fecha->mes == 1)
        {
            fecha->mes = 12;
            fecha->anio --;
        }
        else
            fecha->mes --;

        fecha->dia += cantDiasXMes(fecha->mes, fecha->anio);
    }
}



/*Ejercicio 18
Desarrollar una función que a partir de dos fechas obtenga la cantidad de días que hay entre ellas.*/

int difDeDiasEntreDosFechas(const tFecha* fecha1, const tFecha* fecha2)
{
    int dif = 0, mesMay, anioMay, mesMen, anioMen;

    if(esMenorIgualOMayorFecha(fecha1, fecha2) == IGUAL)
        return dif;

    dif = fecha2->dia - fecha1->dia;
    mesMay = fecha2->mes;
    anioMay = fecha2->anio;
    mesMen = fecha1->mes;
    anioMen = fecha2->anio;

    if(esMenorIgualOMayorFecha(fecha1, fecha2) == MAYOR)
    {
        dif = fecha1->dia - fecha2->dia;
        mesMay = fecha1->mes;
        anioMay = fecha1->anio;
        mesMen = fecha2->mes;
        anioMen = fecha2->anio;
    }

    while(anioMay>anioMen || mesMay>mesMen)
    {
        dif += cantDiasXMes(mesMen, anioMen);
        mesMen ++;
        if(mesMen>12)
        {
            mesMen = 1;
            anioMen ++;
        }
    }
    return dif;
}

int esMenorIgualOMayorFecha(const tFecha* fecha1, const tFecha* fecha2)
{
    if(fecha1->anio < fecha2->anio || (fecha1->anio == fecha2->anio && ( (fecha1->mes < fecha2->mes) || ( (fecha1->mes == fecha2->mes && fecha1->dia < fecha2->dia) ) ) ) )
        return MENOR;
    else
    {
        if(fecha1->anio == fecha2->anio && fecha1->mes == fecha2->mes && fecha1->dia == fecha2->dia)
            return IGUAL;
        else
            return MAYOR;
    }
}


/*Ejercicio 19
Desarrollar una función que a partir de una fecha devuelva un entero que representa el día de la semana que le corresponde
(0: Domingo; 1: lunes; 2: Martes;…etc.)*/

int diaDeLaSemanaDeFecha(const tFecha* fecha)
{
    tFecha fechaBase;
    long dif;

    fechaBase.anio = 1600;
    fechaBase.mes = 12;
    fechaBase.dia = 31;

    dif = difDeDiasEntreDosFechas(fecha, &fechaBase);

    return dif % 7;
}
