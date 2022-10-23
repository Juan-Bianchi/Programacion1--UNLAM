#ifndef PILA_H
#define PILA_H

#include <stdlib.h>
#include <stdbool.h>
#include "../../TP1/TP1-TipoFecha/Fecha.h"
#include <memory.h>

#define min(a,b)   ((a)<(b)?(a):(b))

void typedef (*Mostrar)(const void* elem);


typedef struct sNodo
{
    void* elem;
    size_t tamElem;
    struct sNodo* sig;
} Nodo;

typedef Nodo* Pila;


void crearPila(Pila* pp);
bool apilar(Pila* pp, const void* elem, size_t tamElem);
bool desapilar(Pila* pp, void* elem, size_t tamElem);
bool verTopePila(Pila* pp, void* elem, size_t tamElem);
bool pilaVacia(Pila* pp);
bool pilaLlena(Pila* pp, size_t tamElem);
void vaciarPila(Pila* pp);


#endif // PILA_H
