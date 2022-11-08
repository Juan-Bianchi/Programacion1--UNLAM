#ifndef NODOA_H
#define NODOA_H

#include <stdlib.h>
#define min(a,b)    ((a)<(b)?(a):(b))

typedef struct sNodoA
{
    void* elem;
    size_t tamElem;
    struct sNodoA* hIzq;
    struct sNodoA* hDer;
} NodoA;


NodoA* crearNodoA(const void* elem, size_t tamElem);
void destruirNodoA(NodoA* nae, void* elem, size_t tamElem);

#endif // NODOA_H
