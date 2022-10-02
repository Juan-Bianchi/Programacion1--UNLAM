#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

#include "../TP2-Vectores/Vectores.h"

#define CAPACIDAD 100

int compInt(const void* elem1, const void* elem2);


int main()
{
    int vect[CAPACIDAD], cantElem, num;
    long suma;
    tProm prome;
    int* puntElem;

    puts("Ejercicio 3");
    printf("A continuacion se procedera a la carga de un array de enteros: \n");
    cantElem = cargaVectorInt(vect, CAPACIDAD, -99);
    printf("\n");
    mostrarVectInt(vect, cantElem);
    printf("Se presentara el calculo de la suma y promedio de los elementos del array de enteros usando un puntero a long para la suma y un float para el promedio: \n");
    promedVectInt(vect, &suma, cantElem);
    printf("\nSe presentara el calculo de la suma y promedio de los elementos del array de enteros usando una estructura 'tPromedio' que tiene como variables a suma y promedio: \n");
    promedEnEstructVectInt(vect, &prome, cantElem);


    puts("\nEjercicio 2");
    printf("Ingrese un numero entero para buscar al mismo en el array de int: ");
    fflush(stdin);
    scanf("%d", &num);
    fflush(stdin);
    puntElem = buscarElemEnVect(vect, &num, cantElem, sizeof(int), compInt);
    if(puntElem)
        printf("El numero %d se encuentra en la posicion de memoria %x\n\n", *puntElem, puntElem);
    else
        printf("El numero no fue encontrado\n\n");




    return 0;
}


int compInt(const void* elem1, const void* elem2)
{
    return *(int*)elem1 - *(int*)elem2;
}
