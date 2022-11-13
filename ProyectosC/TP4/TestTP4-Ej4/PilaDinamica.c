#include "PilaDinamica.h"
#include <memory.h>

Nodo* crearNodo(const void* elem, size_t tamElem);
void destruirNodo(Nodo* nae, void* elem, size_t tamElem);


void crearPila(Pila* pp)
{
    *pp = NULL;
}



bool apilar(Pila* pp, const void* elem, size_t tamElem)
{
    Nodo* nue = crearNodo(elem, tamElem);

    if(!nue)
        return false;

    if(!*pp)
        *pp = nue;

    else
        nue->sig = (*pp)->sig;

    (*pp)->sig = nue;

    return true;
}



bool desapilar(Pila* pp, void* elem, size_t tamElem)
{
    Nodo* nae;

    if(!*pp)
        return false;

    nae = (*pp)->sig;

    if(nae == nae->sig)
        *pp = NULL;
    else
        (*pp)->sig = nae->sig;

    destruirNodo(nae, elem, tamElem);

    return true;
}



bool verTopePila(const Pila* pp, void* elem, size_t tamElem)
{
    Nodo* nodo;

    if(!*pp)
        return false;

    nodo = (*pp)->sig;
    memcpy(elem, nodo->elem, min(tamElem, nodo->tamElem));

    return true;
}



bool pilaVacia(const Pila* pp)
{
    return !*pp;
}



bool pilaLlena(const Pila* pp, size_t tamElem)
{
    void* nodo = malloc(sizeof(Nodo));
    void* elem = malloc(tamElem);

    free(nodo);
    free(elem);

    return !nodo || !elem;
}



void vaciarPila(Pila* pp)
{
    Nodo* nae;

    while(*pp)
    {
        nae = (*pp)->sig;
        if(nae == nae->sig)
            *pp = NULL;
        else
            (*pp)->sig = nae->sig;

        free(nae->elem);
        free(nae);
    }
}



Nodo* crearNodo(const void* elem, size_t tamElem)
{
    Nodo* nue = (Nodo*) malloc(sizeof(Nodo));
    void* elemNodo = malloc(tamElem);

    if(!nue || !elemNodo)
    {
        free(nue);
        free(elemNodo);
        return NULL;
    }

    memcpy(elemNodo, elem, tamElem);
    nue->elem = elemNodo;
    nue->tamElem = tamElem;
    nue->sig = NULL;

    return nue;
}



void destruirNodo(Nodo* nae, void* elem, size_t tamElem)
{
    memcpy(elem, nae->elem, min(tamElem, nae->tamElem));
    free(nae->elem);
    free(nae);
}
