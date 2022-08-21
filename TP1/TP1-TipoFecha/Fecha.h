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
void restarNDiasAFecha(const tFecha* fecha, const int cantDias, tFecha* fechaModif);
int difDeDiasEntreDosFechas(const tFecha* fecha1, const tFecha* fecha2);
int diaDeLaSemanaDeFecha(const tFecha* fecha);


#endif // FECHA_H
