#ifndef NODO_H
#define NODO_H

#include <stdlib.h>
#include <memory.h>

#define min(a,b)    ((a)<(b)?(a):(b))

typedef struct sNodo
{
    void* elem;
    size_t tamElem;
    struct sNodo* sig;
} Nodo;


Nodo* crearNodo(const void* elem, size_t tamElem);
void destruirNodo(Nodo* nae, void* elem, size_t tamElem);

#endif // NODO_H
