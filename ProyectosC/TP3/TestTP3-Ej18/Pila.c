#include "Pila.h"


void crearPila(Pila* pp)
{
    *pp = NULL;
}



bool apilar(Pila* pp, const void* elem, size_t tamElem)
{
    Nodo* nue = crearNodo(elem, tamElem);

    if(!nue)
        return false;

    nue->sig = *pp;
    *pp = nue;

    return true;
}



bool desapilar(Pila* pp, void* elem, size_t tamElem)
{
    Nodo* nae;

    if(!*pp)
        return false;

    nae = *pp;
    *pp = nae->sig;

    destruirNodo(nae, elem, tamElem);

    return true;
}



bool verTopePila(Pila* pp, void* elem, size_t tamElem)
{
    Nodo* tope = *pp;

    if(!*pp)
        return false;

    memcpy(elem, tope->elem, min(tamElem, tope->tamElem));

    return true;
}



bool pilaVacia(const Pila* pp)
{
    return !*pp;
}



bool pilaLlena(const Pila* pp, size_t tamElem)
{
    void* nodo = malloc(sizeof(Nodo));
    void* elemNod = malloc(tamElem);

    free(nodo);
    free(elemNod);

    return !nodo || !elemNod;
}



void vaciarPila(Pila* pp)
{
    Nodo* nae;

    while(*pp)
    {
        nae = *pp;
        *pp = nae->sig;

        free(nae->elem);
        free(nae);
    }
}
