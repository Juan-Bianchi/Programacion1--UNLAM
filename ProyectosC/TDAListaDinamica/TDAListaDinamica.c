#include "TDAListaDinamica.h"
#include <memory.h>

Nodo* crearNodo(const void* elem, size_t tamElem);
void destruirNodo(Nodo* nae, void* elem, size_t tamElem);

void crearLista(Lista* pl)
{
    *pl = NULL;
}



int insertarEnListaOrd(Lista* pl, const void* elem, size_t tamElem, Cmp cmp, Actualizar actualizar)
{
    Nodo* nue;

    while(*pl && cmp(elem, (*pl)->elem) > 0)
        pl = &(*pl)->sig;

    if(*pl && cmp(elem, (*pl)->elem) == 0)
    {
        actualizar((*pl)->elem, elem);
        return DUPLICADO;
    }

    nue = crearNodo(elem, tamElem);
    if(!nue)
        return SIN_MEM;

    nue->sig = *pl;
    *pl = nue;

    return TODO_OK;
}



bool eliminarDeListaOrd(Lista* pl, void* elem, size_t tamElem, Cmp cmp)
{
    Nodo* nae;

    while(*pl && cmp(elem, (*pl)->elem) > 0)
        pl = &(*pl)->sig;

    if(!*pl || cmp(elem, (*pl)->elem) < 0)
        return false;

    nae = *pl;
    *pl = nae->sig;

    destruirNodo(nae, elem, tamElem);

    return true;
}


int insertarAlInicio(Lista* pl, const void* elem, size_t tamElem, Cmp cmp)
{
    Lista* pIni = pl;

    while(*pl && cmp(elem, (*pl)->elem) != 0)
        pl = &(*pl)->sig;

    if(*pl && cmp(elem, (*pl)->elem) == 0)
        return DUPLICADO;

    Nodo* nue = crearNodo(elem, tamElem);

    if(!nue)
        return SIN_MEM;

    pl = pIni;

    nue->sig = *pl;
    *pl = nue;

    return TODO_OK;
}



int insertarAlfinal(Lista* pl, const void* elem, size_t tamElem, Cmp cmp)
{
    Nodo* nue;

    while(*pl && cmp(elem, (*pl)->elem) != 0)
        pl = &(*pl)->sig;

    if(cmp(elem, (*pl)->elem) == 0)
        return DUPLICADO;

    nue = crearNodo(elem, tamElem);
    if(!nue)
        return SIN_MEM;

    nue->sig = *pl;
    *pl = nue;

    return TODO_OK;
}



bool eliminarPrimerElem(Lista* pl, void* elem, size_t tamElem)
{
    Nodo* nae;

    if(!*pl)
        return false;

    nae = *pl;
    *pl = nae->sig;

    destruirNodo(nae, elem, tamElem);

    return true;
}



bool eliminarUltimoElem(Lista* pl, void* elem, size_t tamElem)
{
    Nodo* nae;

    if(!*pl)
        return false;

    while(!(*pl)->sig)
        pl = &(*pl)->sig;

    nae = *pl;
    *pl = nae->sig;

    destruirNodo(nae, elem, tamElem);

    return true;
}


Lista* buscarMenorEnLista(Lista* pl, Cmp cmp)
{
    Lista* posMenor = pl;

    while(*pl)
    {
        if(cmp((*posMenor)->elem, (*pl)->elem) > 0)
            posMenor = pl;

        pl = &(*pl)->sig;
    }

    return posMenor;
}


void recorrerLista(Lista* pl, Accion accion, void* datosAccion)
{
    while(*pl)
    {
        accion(pl, datosAccion);
        pl = &(*pl)->sig;
    }
}



void mostrarLista(Lista* pl, Mostrar mostrar)
{
    while(*pl)
    {
        mostrar((*pl)->elem);
        pl = &(*pl)->sig;
    }
}



void ordenarListaSeleccion(Lista* pl, Cmp cmp)
{
    Lista listaOrd;
    Lista* ultListOrd = &listaOrd;
    Lista* posMen;
    Nodo* nodo;

    while(*pl)
    {
        posMen = buscarMenorEnLista(pl, cmp);
        nodo = *posMen;
        *posMen = nodo->sig;

        nodo->sig = *ultListOrd;
        *ultListOrd = nodo;
    }
    *pl = listaOrd;
}



void ordenarListaInsercion(Lista* pl, Cmp cmp)
{
    Lista listOrd;
    Lista* ultListOrd;
    Nodo* nodo;

    while(*pl)
    {
        nodo = *pl;
        *pl = nodo->sig;

        ultListOrd = &listOrd;
        while(*ultListOrd && cmp(nodo->elem, (*ultListOrd)->elem) > 0)
            ultListOrd = &(*ultListOrd)->sig;

        nodo->sig = *ultListOrd;
        *ultListOrd = nodo;
    }
    *pl = listOrd;
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
