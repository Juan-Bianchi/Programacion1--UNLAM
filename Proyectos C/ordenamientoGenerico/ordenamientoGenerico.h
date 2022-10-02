#ifndef ORDENAMIENTOGENERICO_H_INCLUDED
#define ORDENAMIENTOGENERICO_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef int(*Cmp)(const void* elem1, const void* elem2); //parametros y valor de retorno de puntero a funcion
typedef void (*MostrarElem)(const void* elem);

void ordenarSeleccion(void* v, int ce, size_t tamElem, Cmp cmp);
void* buscarMenor(void* ini, void* fin, size_t tamElem, Cmp cmp);


#endif // ORDENAMIENTOGENERICO_H_INCLUDED
