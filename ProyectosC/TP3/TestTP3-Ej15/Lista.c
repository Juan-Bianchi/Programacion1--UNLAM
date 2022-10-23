#include "Lista.h"
#include <memory.h>


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
    memcpy(nae->elem, elem, min(tamElem, nae->tamElem));
    free(nae->elem);
    free(nae);
}



void crearLista(Lista* pl)
{
    *pl = NULL;
}



int insertarElementoEnListaOrd(Lista* pl, const void* elem, size_t tamElem, Cmp cmp)
{
    Nodo* nue;

    while(*pl && cmp(elem, (*pl)->elem) > 0)
        pl = &(*pl)->sig;

    if(*pl && cmp(elem, (*pl)->elem) == 0)
        return DUPLICADO;

    nue = crearNodo(elem, tamElem);
    if(!nue)
        return SIN_MEM;

    nue->sig = *pl;
    *pl = nue;

    return TODO_OK;
}



int insertarElementoAlInicio(Lista* pl, const void* elem, size_t tamElem, Cmp cmp)
{
    Nodo* nue;
    Lista* pIni = pl;

    while(*pl && cmp(elem, (*pl)->elem) != 0)
        pl = &(*pl)->sig;

    if(*pl && cmp(elem, (*pl)->elem) == 0)
        return DUPLICADO;

    nue = crearNodo(elem, tamElem);
    if(!nue)
        return SIN_MEM;

    pl = pIni;

    nue->sig = *pl;
    *pl = nue;

    return TODO_OK;
}



Nodo* buscarMenor(Lista* pl, Cmp cmp)
{
    Nodo* pMen = *pl;

    pl = &(*pl)->sig;

    while(*pl)
    {
        if(cmp(pMen->elem, (*pl)->elem) > 0)
            pMen = *pl;

        pl = &(*pl)->sig;
    }

    return pMen;
}



void ordenarListaInsercion(Lista* pl, Cmp cmp)
{
    Lista listOrd;
    Lista* pListOrd;
    Nodo* nodo;

    while(*pl)
    {
        nodo = *pl;
        *pl = nodo->sig;

        pListOrd = &listOrd;
        while(*pListOrd && cmp(nodo->elem, (*pListOrd)->elem) > 0)
            pListOrd = &(*pListOrd)->sig;

        nodo->sig = *pListOrd;
        *pListOrd = nodo;
    }
    *pl = listOrd;
}



void mostrarLista(Lista* pl, Mostrar mostrar)
{
    while(*pl)
    {
        mostrar((*pl)->elem);
        pl = &(*pl)->sig;
    }
}


void recorrerLista(Lista* pl, Accion accion, void* datosAccion)
{
    while(*pl)
    {
        accion((*pl)->elem, datosAccion);
        pl = &(*pl)->sig;
    }
}
