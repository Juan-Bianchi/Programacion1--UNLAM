#ifndef FECHA_H
#define FECHA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dia,
        mes,
        anio;
} tFecha;

void ingresarFechaValida(tFecha* fecha);
int esFechaValida(const tFecha* fecha);
void sumaUnDiaAFecha(const tFecha* fecha, tFecha* fechaModif);
void sumarNDiasAFecha(const tFecha* fecha, const int cantDias, tFecha* fechaModif);
void sumarNDiasAFechaInSitu(tFecha* fecha, const int cantDias);
void restarNDiasAFecha(const tFecha* fecha, const int cantDias, tFecha* fechaModif);
void restarNDiasAFechaInSitu(tFecha* fecha, const int cantDias);
int difDeDiasEntreDosFechas(const tFecha* fecha1, const tFecha* fecha2);
int diaDeLaSemanaDeFecha(const tFecha* fecha);


#endif // FECHA_H
