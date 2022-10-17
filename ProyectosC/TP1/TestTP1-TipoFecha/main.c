#include <stdio.h>
#include <stdlib.h>
#include "../TP1-TipoFecha/Fecha.h"
#include <string.h>
#include <locale.h>

typedef int booleano;
int validaIntMayA(const int inf);

int main()
{
    tFecha fecha, fechaModif;
    booleano esValido;
    int cantD, dia;


    setlocale(LC_ALL, "spanish");
    puts("Ejercicio 14");
    printf("Se ingresara una fecha para ver si la misma es valia.\n");
    ingresarFechaValida(&fecha);
    printf("La fecha %02d/%02d/%04d es válida.\n\n", fecha.dia, fecha.mes, fecha.anio);

    puts("Ejercicio 15");
    sumaUnDiaAFecha(&fecha, &fechaModif);
    printf("El día siguiente a la fecha proporcionada es %02d/%02d/%04d\n\n", fechaModif.dia, fechaModif.mes, fechaModif.anio);

    puts("Ejercicio 16");
    printf("Ingrese la cantidad de días a sumar a la fecha ingresada en el ejercicio 14: ");
    cantD = validaIntMayA(-1);
    sumarNDiasAFecha(&fecha, cantD, &fechaModif);
    printf("La nueva fecha, luego de sumar %d días a la misma es: %02d/%02d/%04d\n\n", cantD, fechaModif.dia, fechaModif.mes, fechaModif.anio);

    puts("Ejercicio 17");
    printf("Ingrese la cantidad de días a restar a la fecha ingresada en el ejercicio 14: ");
    cantD = validaIntMayA(-1);
    restarNDiasAFecha(&fecha, cantD, &fechaModif);
    printf("La nueva fecha, luego de restar %d días a la misma es: %02d/%02d/%04d\n\n", cantD, fechaModif.dia, fechaModif.mes, fechaModif.anio);

    puts("Ejercicio 18");
    cantD = difDeDiasEntreDosFechas(&fecha, &fechaModif);
    printf("La diferencia de días entre %02d/%02d/%04d y %02d/%02d/%04d es %d\n\n", fecha.dia, fecha.mes, fecha.anio, fechaModif.dia, fechaModif.mes, fechaModif.anio, cantD);

    puts("Ejercicio 19");
    dia = diaDeLaSemanaDeFecha(&fecha);
    switch (dia)
    {
    case 0:
        puts("El día de la semana es Domingo.");
        break;

    case 1:
        puts("El día de la semana es Lunes.");
        break;

    case 2:
        puts("El día de la semana es Martes.");
        break;

    case 3:
        puts("El día de la semana es Miércoles.");
        break;

    case 4:
        puts("El día de la semana es Jueves.");
        break;

    case 5:
        puts("El día de la semana es Viernes.");
        break;

    case 6:
        puts("El día de la semana es Sábado.");
        break;
    }

    return 0;
}



int validaIntMayA(const int inf)
{
    int num;

    do
    {
        fflush(stdin);
        scanf("%d", &num);
        fflush(stdin);
        if(num<=inf)
            printf("El número ingresado no es válido, el mismo debe ser mayor a %d. Vuelva a ingresar: ", inf);
    } while(num<=inf);

    return num;
}
