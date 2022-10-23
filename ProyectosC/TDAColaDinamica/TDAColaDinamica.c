#include "TDAColaDinamica.h"
#include <memory.h>



Nodo* crearNodo(const void* elem, size_t tamElem);
void destruirNodo(Nodo* nae, void* elem, size_t tamElem);


void crearCola(Cola* pc)
{
    pc->frente = pc->fondo = NULL;
}



bool encolar(Cola* pc, const void* elem, size_t tamElem)
{
    Nodo* nue = crearNodo(elem, tamElem);

    if(!nue)
        return false;
    if(pc->fondo)
        pc->fondo->sig = nue;
    else
        pc->frente = nue;

    pc->fondo = nue;

    return true;
}



bool desencolar(Cola* pc, void* elem, size_t tamElem)
{
    Nodo* nae;

    if(!pc->fondo)
        return false;

    nae = pc->frente;
    pc->frente = nae->sig;

    if(!pc->frente)
        pc->fondo = NULL;

    destruirNodo(nae, elem, tamElem);

    return true;
}



bool verFrenteCola(const Cola* pc, const void* elem, size_t tamElem)
{
    Nodo* frente = pc->frente;

    if(!pc->frente)
        return false;

    memcpy((void*)elem, frente->elem, min(tamElem, frente->tamElem));
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

    free(nodo);
    free(elemNod);

    return (!nodo || !elemNod);
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



Nodo* crearNodo(const void* elem, size_t tamElem)
{
    Nodo* nue = (Nodo*)malloc(sizeof(Nodo));
    void* elemNue = malloc(tamElem);

    if(!nue || !elemNue)
    {
        free(nue);
        free(elemNue);
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
