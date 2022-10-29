#ifndef TDAARBOL_H
#define TDAARBOL_H

#define TDA_ARBOL_IMPL_DINAMICA

#ifdef TDA_ARBOL_IMPL_DINAMICA
    #include "../TDAArbolImplDinamica/TDAArbolDinamico.h"

#endif // TDA_ARBOL_IMPL_DINAMICA


void crearArbol(Arbol* pa);
bool insertarEnArbol(Arbol* pa, const void* elem, size_t tamElem, Cmp cmp);


#endif // TDAARBOL_H
