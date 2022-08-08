#ifndef VECTORES_H
#define VECTORES_H

#define CAPACIDAD_VECTOR 10
#define NO_ENCONTRADO -1
#define TODO_OK 0
#define ERROR -123456
#define SIN_MEMORIA 2
#define DUPLICADO 3
#define VERDADERO 1
#define FALSO 0

#include <stdio.h>

typedef struct
{
    int vec[CAPACIDAD_VECTOR];
    int cantElem;
} Vector;

typedef int booleano;

//////////////////////////////////////////FUNCIONES TP 1/////////////////////////////////////////////////////

int insertarVectorEnPosicion(Vector* vectr, const int pos, const int elem);
int insertarVectorEnPosicionAritPunt(Vector* vectr, const int pos, const int elem);
int insertarElemEnVectOrdenado(Vector* vect, const int elem);
int insertarElemEnVectOrdenadoAritPunt(Vector* vect, const int elem);
int eliminarElemEnPos(Vector* vect, const int pos);
int eliminarElemEnPosAritPunt(Vector* vect, const int pos);
int eliminarPrimeraAparicion(Vector* vect, const int elem);
int eliminarPrimeraAparicionAritPunt(Vector* vect, const int elem);
int eliminarTodasLasApariciones(Vector* vect, const int elem);
int eliminarTodasLasAparicionesAritPunt(Vector* vect, const int elem);


/////////////////////////////////////////FUNCIONES VARIAS CON VECTORES/////////////////////////////////////////

void crearVector(Vector *vect);

int insertarEnVectorOrdSinDup(Vector* vect, const int elem);
int insertarEnVectorOrdConDup(Vector* vect, const int elem);
int insertarEnVecAlInicioSinDup(Vector *vect, const int elem);
int insertarEnVecAlInicioConDup(Vector* vect, const int elem);
int insertarEnVecAlInicioSinDupAritPunt(Vector* vect, const int elem);
int insertarEnVecAlInicioConDupAritPunt(Vector* vect, const int elem);
int insertarEnVecAlFinalSinDup(Vector* vect, const int elem);
int insertarEnVecAlFinalConDup(Vector* vect, const int elem);
int insertarEnVecAlFinalSinDupAritPunt(Vector* vect, const int elem);
int insertarEnVecAlFinalConDupAritPunt(Vector* vect, const int elem);

int buscarEnVecDesordenadoSinDup(const Vector *vect, const int elem);
int buscarEnVecDesordenadoConDup(const Vector* vect, Vector* vectPos, const int elem);
int buscarEnVecDesordenadoSinDupAritPunt(const Vector* vect, const int elem);
int buscarEnVecDesordenadoConDupAritPunt(const Vector* vect, Vector* vectPos, const int elem);
int buscarEnVecOrdenadoSinDup(const Vector* vect, const int elem);
int buscarEnVecOrdenadoConDup(const Vector* vect, Vector* vectPos, const int elem);
int buscarEnVecOrdenadoSinDupAritPunt(const Vector* vect, const int elem);
int buscarEnVecOrdenadoConDupAritPunt(const Vector* vect, Vector* vectPos, const int elem);
int buscarMenor(const Vector* vect);
int buscarMenorAritPunt(const Vector* vect);
int buscarMayor(const Vector* vect);
int buscarMayorAritPunt(const Vector* vect);

int eliminarDeVecUltElem(Vector* vect);
int eliminarDeVecUltElemAritPunt(Vector* vect);
int eliminarDeVecPrimerElem(Vector* vect);
int eliminarDeVecPrimerElemAritPunt(Vector* vect);

void vaciarVector(Vector* vect);
void ordenarVectorBurbujeoAscendente(Vector* vect);
void ordenarVectorBurbujeoDescendente(Vector* vect);
void ordenarVectorSeleccionAscen(Vector* vect);
void ordenarVectorSeleccionDescen(Vector* vect);
void ordenaVectInsercionAscend(Vector* vect);
void ordenaVectInsercionDescend(Vector* vect);

void mostrarVector(const Vector* vect);
void mostrarVectorAritPunt(const Vector* vect);




#endif // VECTORES_H
