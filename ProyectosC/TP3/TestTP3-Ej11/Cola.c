#include "Cola.h"
#include <memory.h>


Nodo* crearNodo(const void* elem, size_t tamElem);
void destruirNodo(Nodo* nae, void* elem, size_t tamElem);



void crearCola(Cola* pc)
{
    pc->fondo = pc->frente = NULL;
}



bool encolar(Cola* pc, const void* elem, size_t tamElem)
{
    Nodo* nue = crearNodo(elem, tamElem);;

    if(!nue)
        return false;

    if(!pc->frente)
        pc->frente = nue;
    else
        pc->fondo->sig = nue;

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
    size_t tamElemFrent;

    if(!pc->frente)
        return false;

    tamElemFrent = pc->frente->tamElem;
    memcpy(elem, pc->frente->elem, min(tamElem, tamElemFrent));

    return true;
}



bool colaVacia(const Cola* pc)
{
    return !pc->frente;
}



bool colaLlena(const Cola* pc, size_t tamElem)
{
    void* nodo = malloc(sizeof(Nodo));
    void* elemN = malloc(tamElem);

    free(nodo);
    free(elemN);

    if(!nodo || !elemN)
        return false;

    return true;
}



void vaciarCola(Cola* pc)
{
    Nodo* nae;

    while(pc->frente)
    {
        nae = pc->frente;
        pc->frente = nae->sig;

        free(nae->elem);
        free(nae);
    }

    pc->fondo = NULL;
}



Nodo* crearNodo(const void* elem, size_t tamElem)
{
    Nodo* nue = (Nodo*)malloc(sizeof(Nodo));
    void* elemNue = malloc(tamElem);

    if(!nue || ! elemNue)
        return NULL;

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
