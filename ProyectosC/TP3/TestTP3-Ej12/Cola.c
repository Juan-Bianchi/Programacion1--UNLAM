#include "Cola.h"




void crearCola(Cola* pc)
{
    pc->fondo = pc->frente = NULL;
}



bool encolar(Cola* pc, const void* elem, size_t tamElem)
{
    Nodo* nue = crearNodo(elem, tamElem);

    if(!nue)
        return false;

    if(pc->frente)
        pc->fondo->sig = nue;
    else
        pc->frente = nue;

    pc->fondo = nue;

    return true;
}



bool desencolar(Cola* pc, void* elem, size_t tamElem)
{
    Nodo* nae;

    if(!pc->frente)
        return false;

    nae = pc->frente;
    pc->frente = nae->sig;

    if(!pc->frente)
        pc->fondo = NULL;

    destruirNodo(nae, elem, tamElem);

    return true;
}



bool verFrenteCola(const Cola* pc, void* elem, size_t tamElem)
{
    Nodo* frente;

    if(!pc->frente)
        return false;

    frente = pc->frente;

    memcpy(elem, frente->elem, min(tamElem, frente->tamElem));

    return true;
}



bool colaVacia(const Cola* pc)
{
    return !pc->frente;
}



bool colaLlena(const Cola* pc, size_t tamElem)
{
    void* nodo = malloc(sizeof(Nodo));
    void* elemNod = malloc(tamElem);

    free(elemNod);
    free(nodo);

    return !nodo || !elemNod;
}



void vaciarCola(Cola* pc)
{
    Nodo* nae;
    Nodo* frente = pc->frente;

    while(frente)
    {
        nae = frente;
        frente = nae->sig;

        free(nae->elem);
        free(nae);
    }

    pc->frente = pc->fondo = NULL;
}
