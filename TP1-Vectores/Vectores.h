#ifndef VECTORES_H
#define VECTORES_H

#define CAPACIDAD_VECTOR 10
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
/*int insertarEnVecAlInicioSinDup(Vector *vector, int elem);      ///
int insertarEnVecAlInicioConDup(Vector *vector, int elem);        ///
int insertarEnVecAlInicioConDupAritPunt(Vector *vector, int elem);   ///
int insertarEnVecAlFinal(Vector *vector, int elem);   ///
int insertarEnVecEnPosicion(Vector *vector, int elem, int pos);    ///
int buscarEnVecDesordenadoConDupAritPunt(const Vector *vector, int elem, int *dirDesde);    ///
int buscarEnVecOrdenado(const Vector *vector, int elem);    ///
int buscarEnVecDesordenado(const Vector *vector, int elem);  ///
int buscarEnVecDesordenadoApariciones(const Vector *vector, VectorApariciones *vecA, int elem);   ///
int buscarEnVecDesordenadoAparicionesAritPunt(const Vector *vector, VectorApariciones *vectAp, int elem, int desde);   ///
int buscarMenor(const Vector *vector);
int buscarMayor(const Vector *vector);
booleano eliminarDeVecAlFinal(Vector *vector);    ///
booleano eliminarDeVecEnPosicion(Vector *vector, int elem, int pos);   ///
booleano eliminarDeVectorOrdPorValor(Vector *vector, int elem);    ///
booleano eliminarDeVectorDesordPorValor(Vector *vector, int elem); ///
booleano eliminarDeVectorDesordPorValorAritPunt(Vector *vector, int elem, int *Dirdesde);   ///
booleano eliminarDeVecAparicionesValorAritPunt(Vector *vector, int elem);    ///
void vaciarVector(Vector *vector);   ///
void ordenarVectorBurbujeoAscendente(Vector *vector);   ///
void ordenarVectorBurbujeoDescendente(Vector *Vector);  ///
void ordenarVectorSeleccionAscen(Vector *vector);   ///
void ordenarVectorSeleccionDescen(Vector *vector);  ///
void ordenarVectorInsercionDescen(Vector *vector);*/

void mostrarVector(const Vector* vect);
void mostrarVectorAritPunt(const Vector* vect);

void ordenaVectInsercionAscend(Vector* vect);


#endif // VECTORES_H
