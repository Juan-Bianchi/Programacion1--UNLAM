#ifndef PILADINAMICA_H
#define PILADINAMICA_H

#include <stdlib.h>
#include <memory.h>
#include <stdbool.h>

#define min(a,b)    ((a)<(b)?(a):(b))

typedef struct sNodo
{
    void* elem;
    size_t tamElem;
    struct sNodo* sig;
} Nodo;

typedef Nodo* Pila;



#endif // PILADINAMICA_H
