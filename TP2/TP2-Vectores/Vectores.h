#ifndef VECTORES_H
#define VECTORES_H

#include <stdio.h>

int typedef (*Cmp)(const void* elem1, const void* elem2);

typedef struct
{
    long suma;
    float prom;
} tProm;


int cargaVectorFloat(float* vect, const int capacidad, const float condFin);
int buscarMinimoVectFloat(float* vect, float* minimo, const int cantElem);
float promedPosicParesVectFloat(const float* vect, const int cantElem);
void mostrarVectFloat(float* vect, const int cantElem);
void mostrarVectFloatOrdenInverso(float* vect, const int cantElem);
void mostrarVectInt(int* vect, const int cantElem);
void* buscarElemEnVect(const void* vect, const void* elem, const int cantElem, size_t tamElem, Cmp cmp);
int cargaVectorInt(int* vect, const int capacidad, const int condFin);
float promedVectInt(int* vect, long* suma, const int cantElem);
void promedEnEstructVectInt(int* vect, tProm* prom, const int cantElem);



#endif // VECTORES_H
