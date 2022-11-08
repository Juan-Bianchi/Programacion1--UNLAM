#include "ColaDinamicaCircular.h"


void crearCola(Cola* pc)
{
    *pc = NULL;
}



bool encolar(Cola* pc, const void* elem, size_t tamElem)
{
    Nodo* nue = crearNodo(elem, tamElem);

    if(!nue)
        return false;

    if(!*pc)
        nue->sig = nue;
    else
    {
        nue->sig = (*pc)->sig;
        (*pc)->sig = nue;
    }

    *pc = nue;

    return true;
}




bool desencolar(Cola* pc, void* elem, size_t tamElem)
{
    Nodo* nae;

    if(!*pc)
        return false;

    nae = (*pc)->sig;

    if(nae == nae->sig)
        *pc = NULL;
    else
        (*pc)->sig = nae->sig;

    destruirNodo(nae, elem, tamElem);

    return true;
}



bool verFrenteDeCola(const Cola* pc, void* elem, size_t tamElem)
{
    Nodo* nodo;

    if(!*pc)
        return false;

    nodo = (*pc)->sig;
    memcpy(elem, nodo->elem, min(tamElem, nodo->tamElem));

    return true;
}



bool colaVacia(const Cola* pc)
{
    return !*pc;
}



bool colaLlena(const Cola* pc, size_t tamElem)
{
    void* nodo = malloc(sizeof(Nodo));
    void* elem = malloc(tamElem);

    free(nodo);
    free(elem);

    return !nodo || !elem;
}



void vaciarCola(Cola* pc)
{
    Nodo* nae;

    while(*pc)
    {
        nae = (*pc)->sig;

        if(nae == nae->sig)
            *pc = NULL;
        else
            (*pc)->sig = nae->sig;

        free(nae->elem);
        free(nae);
    }
}
