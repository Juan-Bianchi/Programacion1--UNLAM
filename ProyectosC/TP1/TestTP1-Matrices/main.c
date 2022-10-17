#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../TP1-Matrices/Matrices.h"



int main(int argc, char* argv[])
{
    MatrizF matr;
    MatrizI matrDiag, matrTras, matrB, matrProd;
    VectorI vect;
    int orden, estado, i;
    double suma;



    crearMatriz(&matr);
    crearMatrizInt(&matrDiag);

    puts("Ejercicio 29");
    printf("Ingrese el orden de la matriz cuadrada para realizar las operaciones( mayor a cero y menor a %d): ", CANTIDAD_FILAS);
    orden = validaIntMayA(0);
    puts("Se creara una matriz con valores correlativos hasta llenarse: ");
    cargarMatrizCuadOrdenNConNumCorrel(&matr, orden);
    mostrarMatriz(&matr);
    suma = sumaElemEncimaDiagPrinc(&matr, orden);
    printf("La suma de los elementos sobre la diagonal principal de una matriz de orden %d es %f\n", orden, suma);
    suma = sumaElemEncimaDiagSec(&matr, orden);
    printf("La suma de los elementos sobre la diagonal secundaria de una matriz de orden %d es %f\n", orden, suma);
    suma = sumaElemEncimaEIncluidaDiagPrinc(&matr, orden);
    printf("La suma de los elementos sobre la diagonal principal incluyendo la misma de una matriz de orden %d es %f\n", orden, suma);
    suma = sumaElemEncimaEIncluidaDiagSec(&matr, orden);
    printf("La suma de los elementos sobre la diagonal secundaria incluyendo la misma de una matriz de orden %d es %f\n", orden, suma);
    suma = sumaElemDebajoDiagPrinc(&matr, orden);
    printf("La suma de los elementos bajo la diagonal principal de una matriz de orden %d es %f\n", orden, suma);
    suma = sumaElemDebajoDiagSec(&matr, orden);
    printf("La suma de los elementos bajo la diagonal secundaria de una matriz de orden %d es %f\n\n", orden, suma);


    puts("Ejercicio 30");
    suma = sumaElemDiagPrinc(&matr, orden);
    printf("La suma de los elementos de la diagonal principal de la matriz de orden %d es %f\n", orden, suma);
    suma = sumaElemDiagSec(&matr, orden);
    printf("La suma de los elementos de la diagonal secundaria de la matriz de orden %d es %f\n\n", orden, suma);


    puts("Ejercicio 31");
    puts("A continuacion se cargara una matriz de enteros: ");
    printf("Ingrese el orden de la matriz cuadrada para realizar las operaciones( mayor a cero y menor a %d): ", CANTIDAD_FILAS);
    orden = validaIntMayA(0);
    puts("A continuacion cargue la matriz cuadrada: ");
    cargarMatrizCuadEnteros(&matrDiag, orden);
    mostrarMatrizInt(&matrDiag);
    if(esMatrizDiagonal(&matrDiag, orden))
        printf("La matriz es diagonal\n\n");
    else
        printf("La matriz no es diagonal\n\n");


    puts("Ejercicio 32");
    if(esMatrizIdentidad(&matrDiag, orden))
        printf("La matriz es identidad\n\n");
    else
        printf("La matriz no es identidad\n\n");


    puts("Ejercicio 33");
    printf("Ingrese el orden de la matriz cuadrada para realizar las operaciones( mayor a cero y menor a %d): ", CANTIDAD_FILAS);
    orden = validaIntMayA(0);
    puts("A continuacion cargue la matriz cuadrada: ");
    cargarMatrizCuadEnteros(&matrDiag, orden);
    mostrarMatrizInt(&matrDiag);
    if(esMatrizSimetricaInt(&matrDiag, orden))
        printf("La matriz es simetrica\n\n");
    else
        printf("La matriz no es simetrica\n\n");


    puts("Ejercicio 34");
    puts("La matriz traspuesta in situ es: ");
    trasponerMatrizIntCuadradaInSitu(&matrDiag, orden);
    mostrarMatrizInt(&matrDiag);


    puts("\nEjercicio 35");
    puts("Se procedera a la carga de la matriz: ");
    cargarMatrizEnteros(&matrDiag);
    mostrarMatrizInt(&matrDiag);
    crearMatrizTraspuestaInt(&matrDiag, &matrTras);
    puts("La matriz traspuesta es: ");
    mostrarMatrizInt(&matrTras);

    puts("\nEjercicio 36");
    crearMatrizInt(&matrB);
    crearMatrizInt(&matrProd);
    printf("Cargue otra matriz para realizar el producto entre la anterior y esta nueva: \n");
    cargarMatrizEnteros(&matrB);
    mostrarMatrizInt(&matrB);
    estado = matrizProductoEntreDosMatrInt(&matrDiag, &matrB, &matrProd);
    if(estado == ERROR)
        printf("Las matrices no son compatibles para realizar una multiplicacion. Verifique la cantidad de filas y columnas de ambas.\n\n");
    else
    {
        printf("La matriz multiplicacion es: \n");
        mostrarMatrizInt(&matrProd);
    }


    puts("\nEjercicio 37");
    printf("Ingrese la cantidad de equipos que participan en el torneo: ");
    orden = validaIntMayA(1);
    printf("Ingrese la puntuacion recordando que cada elemento [i][j] representa la cantidad de puntos que obtuvo el equipo i frente al equipo j \nal fin de un torneo de futbol (partidos de ida y vuelta).\nEl sistema de puntuacion es: 3 puntos para el ganador del partido y ninguno para el perdedor; 1 punto para cada equipo en caso de empate: \n");
    cargarMatrizCuadEnteros(&matrDiag, orden);
    mostrarMatrizTablaInt(&matrDiag);
    if(verificaTablaPuntos(&matrDiag, orden)==0)
        printf("La tabla esta correctamente cargada\n\n");
    else
        printf("La carga no esta correctamente cargada\n\n");

    sumaFilaDeMatrizEnVectInt(&matrDiag, &vect);

    for(i=0; i < vect.cantElem; i++)
        printf("Equipo %3d%8d puntos\n", i+1, vect.vec[i]);

    return 0;
}
