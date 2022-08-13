#ifndef MATRICES_H
#define MATRICES_H

#define CANTIDAD_FILAS 100
#define CANTIDAD_COLUMNAS 100
#define VERDADERO 1
#define FALSO 0
#define ERROR -1
#define TODO_OK 0

#include <stdio.h>

typedef struct
{
    float mat[CANTIDAD_FILAS][CANTIDAD_COLUMNAS];
    int cantF;
    int cantC;
} MatrizF;

typedef struct
{
    int mat[CANTIDAD_FILAS][CANTIDAD_COLUMNAS];
    int cantF;
    int cantC;
} MatrizI;

typedef struct
{
    int vec[CANTIDAD_FILAS];
    int cantElem;
} VectorI;


typedef int booleano;
int validaIntMayA(const int inf);
booleano estaDentroDelRango(const int num, const int inf, const int sup);
int validaIntEntre(const int inf, const int sup);

void crearMatriz(MatrizF* matr);
void crearMatrizInt(MatrizI* matr);
void cargarMatrizCuadOrdenNConNumCorrel(MatrizF* matr, const int orden);
void cargarMatrizEnteros(MatrizI* matr);
void cargarMatrizCuadEnteros(MatrizI* matr, const int orden);
void mostrarMatriz(MatrizF* matr);
void mostrarMatrizInt(MatrizI* matr);
double sumaElemEncimaDiagPrinc(MatrizF* matr, const int orden);
double sumaElemEncimaDiagSec(MatrizF* matr, const int orden);
double sumaElemEncimaEIncluidaDiagPrinc(MatrizF* matr, const int orden);
double sumaElemEncimaEIncluidaDiagSec(MatrizF* matr, const int orden);
double sumaElemDebajoDiagPrinc(MatrizF* matr, const int orden);
double sumaElemDebajoDiagSec(MatrizF* matr, const int orden);
double sumaElemDiagPrinc(MatrizF* matr, const int orden);
double sumaElemDiagSec(MatrizF* matr, const int orden);
booleano esMatrizDiagonal(MatrizI* matr, const int orden);
booleano esMatrizIdentidad(MatrizI* matr, const int orden);
booleano esMatrizSimetricaInt(MatrizI* matr, const int orden);
void trasponerMatrizIntCuadradaInSitu(MatrizI* matr, const int orden);
void crearMatrizTraspuestaInt(MatrizI* matrOrig, MatrizI* matrTras);
int matrizProductoEntreDosMatrInt(MatrizI* matr1, MatrizI* matr2, MatrizI* matrProd);
int verificaTablaPuntos(MatrizI* matr, const int orden);
void mostrarMatrizTablaInt(MatrizI* matr);
void sumaFilaDeMatrizEnVectInt(MatrizI* matr, VectorI* vect);


#endif // MATRICES_H
