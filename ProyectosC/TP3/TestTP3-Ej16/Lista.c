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



int insertarAlFinalListaDesord(Lista* pl, const void* elem, size_t tamElem)
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



bool eliminarDeListaDesord(Lista* pl, void* elem, size_t tamElem)
{
    Nodo* nae;

    if(*pl)
        return false;

    nae = *pl;
    *pl = nae->sig;

    destruirNodo(nae, elem, tamElem);

    return true;
}


void ordenarListaInsercion(Lista* pl, Cmp cmp)
{
    Lista listOrd = NULL;
    Lista* pUltListOrd;
    Nodo* nodo;

    while(*pl)
    {
        nodo = *pl;
        *pl = nodo->sig;

        pUltListOrd = &listOrd;
        while(*pUltListOrd && cmp(nodo->elem, (*pUltListOrd)->elem) > 0)
            pUltListOrd = &(*pUltListOrd)->sig;

        nodo->sig = *pUltListOrd;
        *pUltListOrd = nodo;
    }
    *pl = listOrd;
}
