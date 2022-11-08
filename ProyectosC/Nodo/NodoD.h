#ifndef NODOD_H
#define NODOD_H

#include <stdlib.h>
#include <memory.h>

#define min(a,b)    ((a)<(b)?(a):(b))

typedef struct sNodoD
{
    void* elem;
    size_t tamElem;
    struct sNodoD* ant;
    struct sNodoD* sig;
} NodoD;


NodoD* crearNodoD(const void* elem, size_t tamElem);
void destruirNodoD(NodoD* nae, void* elem, size_t tamElem);



#endif // NODOD_H
