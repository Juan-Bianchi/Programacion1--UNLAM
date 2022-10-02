#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../TP2-Vectores/Vectores.h"
#include "../TP2-FuncionesConArchivos/Archivos.h"

#define CAPACIDAD 100


int estaDentroDelRango(const int num, const int inf, const int sup);
int validaIntEntre(const int inf, const int sup);
int mostrarMenuDeOpciones();


int main()
{
    float vect[CAPACIDAD], minimo, prom;
    FILE* arch;
    int cantElem, opcion;

    puts("Ejercicio 1");

    printf("A continuacion se procedera a la carga de un vector de numeros reales: \n");
    cantElem = cargaVectorFloat(vect, CAPACIDAD, -99.9);
    mostrarVectFloat(vect, cantElem);
    printf("\n\n");
    opcion = mostrarMenuDeOpciones();
    while(opcion != 4)
    {
        if(opcion==1)
        {
            buscarMinimoVectFloat(vect, &minimo, cantElem);
            printf("1- Buscar el minimo elemento: %.2f\n2- Calcular el promedio de los valores de las posiciones pares\n3- Mostrarlo en orden inverso\n4- Salir\n", minimo);
        }
        if(opcion==2)
        {
            prom = promedPosicParesVectFloat(vect, cantElem);
            printf("1- Buscar el minimo elemento\n2- Calcular el promedio de los valores de las posiciones pares : %.2f\n3- Mostrarlo en orden inverso\n4- Salir\n", prom);
        }
        if(opcion==3)
        {
            mostrarVectFloatOrdenInverso(vect, cantElem);
        }
        printf("\n\n");
        opcion = mostrarMenuDeOpciones();
    }
    arch = fopen("VectorATxt.txt", "w");
    vectFloatAArchTxt(arch, vect, cantElem);
    fclose(arch);

    return 0;
}


int estaDentroDelRango(const int num, const int inf, const int sup)
{
    return num >= inf && num <= sup;
}



int validaIntEntre(const int inf, const int sup)
{
    int num, esValido = 1;

    do
    {
        fflush(stdin);
        scanf("%d", &num);
        fflush(stdin);
        esValido = estaDentroDelRango(num, inf, sup);
        if(!esValido)
            printf("El valor ingresado no es valido. El mismo debe estar entre %d y %d. Vuelva a ingresar: ", inf, sup);
    } while(!esValido);

    return num;
}


int mostrarMenuDeOpciones()
{
    int opc;

    printf("1- Buscar el minimo elemento\n2- Calcular el promedio de los valores de las posiciones pares\n3- Mostrarlo en orden inverso\n4- Salir\n");

    printf("Elija entre las opciones poibles: ");

    opc = validaIntEntre(1,4);
    printf("\n\n");

    return opc;
}

