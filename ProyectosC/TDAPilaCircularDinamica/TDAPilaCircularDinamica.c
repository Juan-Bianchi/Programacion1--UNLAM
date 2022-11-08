#include "TDAPilaCircularDinamica.h"


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



bool verTopeDePila(const Pila* pp, void* elem, size_t tamElem)
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
