#include "Lista.h"
#include <memory.h>

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



void crearLista(Lista* pl)
{
    *pl = NULL;
}



int insertarElementoEnListaDesordConDup(Lista* pl, const void* elem, size_t tamElem)
{
    Nodo* nue = crearNodo(elem, tamElem);

    if(!nue)
        return SIN_MEM;

    while(*pl)
        pl = &(*pl)->sig;

    nue->sig = *pl;
    *pl = nue;

    return TODO_OK;
}



void ordenarListaInsercion(Lista* pl, Cmp cmp)
{
    Lista listOrd = NULL;
    Lista* finLOrd;
    Nodo* nodo;

    while(*pl)
    {
        nodo = *pl;
        *pl = nodo->sig;

        finLOrd = &listOrd;
        while(*finLOrd && cmp(nodo->elem, (*finLOrd)->elem) > 0)
            finLOrd = &(*finLOrd)->sig;

        nodo->sig = *finLOrd;
        *finLOrd = nodo;
    }
    *pl = listOrd;
}
