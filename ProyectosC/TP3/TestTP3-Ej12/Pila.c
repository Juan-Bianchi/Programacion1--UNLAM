#include "Pila.h"
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
    Nodo* nodo;

    if(!*pp)
        return false;

    nodo = *pp;
    memcpy(elem, nodo->elem, min(tamElem, nodo->tamElem));

    return true;
}



bool pilaVacia(Pila* pp)
{
    return !*pp;
}



bool pilaLlena(Pila* pp, size_t tamElem)
{
    void* nue = malloc(sizeof(Nodo));
    void* elemNue = malloc(tamElem);

    free(nue);
    free(elemNue);

    return !nue || ! elemNue;
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



Nodo* crearNodo(const void* elem, size_t tamElem)
{
    Nodo* nue = (Nodo*)malloc(sizeof(Nodo));
    void* elemNue = malloc(tamElem);

    if(!nue || !elemNue)
    {
        free(elemNue);
        free(nue);
        return NULL;
    }

    memcpy(elemNue, elem, tamElem);
    nue->elem = elemNue;
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
