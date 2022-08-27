/*Ejercicio 14
Ingresar por teclado pares de cadenas de caracteres, finalizando el ingreso cuando ambas cadenas sean iguales (las que no deben procesarse).
Para cada par, cargar en un array bidimensional, ambas cadenas, respetando cargar primero la m�s peque�a y luego la mayor, si las longitudes
fueran iguales, el orden lo dar� la comparaci�n lexicogr�fica haciendo caso omiso de may�sculas y min�culas.
Escriba una funci�n que determine la comparaci�n solicitada invocando a versiones propias de las funciones de biblioteca est�ndar strlen y
strcmpi o strcasecmp (dado que esta no es una funci�n est�ndar en algunos compiladores tiene otro nombre).*/


#include <stdio.h>
#include <stdlib.h>

#include "../../Cadenas/Cadenas.h"

int main()
{
    char arrayDeCadenas[2][100];
    char cadena1[100], cadena2[100];

    puts("Ingrese la primera cadena: ");
    fgets(cadena1, 100, stdin);
    puts("Ingrese la segunda cadena: ");
    fgets(cadena2, 100, stdin);

    if(strlen_JUAN(cadena1) > strlen_JUAN(cadena2))
    {
        strcpy_JUAN(arrayDeCadenas[1],cadena2);
        strcpy_JUAN(arrayDeCadenas[2], cadena1);
    }

    if(strlen_JUAN(cadena1) < strlen_JUAN(cadena2))
    {
        strcpy_JUAN(arrayDeCadenas[2], cadena2);
        strcpy_JUAN(arrayDeCadenas[1], cadena1);
    }

    if(strlen_JUAN(cadena1) == strlen_JUAN(cadena2))
    {
        if(strcmpi_JUAN(cadena1, cadena2) >= 0)
        {
            strcpy_JUAN(arrayDeCadenas[1], cadena2);
            strcpy_JUAN(arrayDeCadenas[2], cadena1);
        }
        else
        {
            strcpy_JUAN(arrayDeCadenas[2], cadena2);
            strcpy_JUAN(arrayDeCadenas[1], cadena1);
        }
    }

    printf("La cadena menor es : '%s'\n", arrayDeCadenas[1]);
    printf("La cadena mayor es : '%s'\n", arrayDeCadenas[2]);

    return 0;
}
