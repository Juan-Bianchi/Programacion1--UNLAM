#include "TDAListaDoblementeEnlazadaDinamica.h"
#include "../TDALista/TDALista.h"
#include <stdbool.h>
#define TDA_LISTA_DOBLE_IMPLEMENTACION_DINAMICA

void crearLista(Lista* pl)
{
    *pl = NULL;
}



int insertarEnListaOrd(Lista* pl, const void* elem, size_t tameElem, Cmp cmp, Actualizar actualizar)
{
    NodoD* nue;
    NodoD* actual = *pl;
    NodoD* ant = NULL;
    NodoD* sig = NULL;
    int comp;

    if(actual)
    {
        while(actual->ant && cmp(elem, actual->elem) < 0)
            actual = actual->ant;

        while(actual->sig && cmp(elem, actual->elem) > 0)
            actual = actual->sig;

        comp = cmp(elem, actual->elem);

        if(comp == 0)
        {
            actualizar(actual->elem, elem);
            *pl = actual;
            return DUPLICADO;
        }

        if(comp < 0)
        {
            sig = actual;
            ant = actual->ant;
        }

        if(comp > 0)
        {
            ant = actual;
            sig = actual->sig;
        }
    }

    nue = crearNodoD(elem, tameElem);
    if(!nue)
        return SIN_MEM;

    nue->sig = sig;
    nue->ant = ant;

    if(ant)
        ant->sig = nue;
    if(sig)
        sig->ant = nue;

    *pl = nue;

    return TODO_OK;
}



bool eliminarDeListaOrd(Lista* pl, void* elem, size_t tamElem, Cmp cmp)
{
    NodoD* nae = *pl;

    if(!nae)
        return false;

    while(nae->ant && cmp(elem, nae->elem) < 0)
            nae = nae->ant;

    while(nae->sig && cmp(elem, nae->elem) > 0)
        nae = nae->sig;

    if(!nae || cmp(elem, nae->elem) != 0)
        return false;

    if(nae->ant)
        nae->ant->sig = nae->sig;
    if(nae->sig)
        nae->sig->ant = nae->ant;

    if(nae == *pl)
    {
        if(nae->sig)
            *pl = nae->sig;
        else
            *pl = nae->ant;
    }

    destruirNodoD(nae, elem, tamElem);

    return true;
}



int insertarAlInicio(Lista* pl, const void* elem, size_t tamElem, Cmp cmp)
{
    NodoD* nue = crearNodoD(elem, tamElem);
    NodoD* act = *pl;

    if(!nue)
        return SIN_MEM;

    if(act)
    {
        while(act->ant)
            act = act->ant;
    }
    nue->sig = act;
    if(act)
        act->ant = nue;

    *pl = nue;

    return TODO_OK;
}



int insertarAlfinal(Lista* pl, const void* elem, size_t tamElem, Cmp cmp)
{
    NodoD* nue = crearNodoD(elem, tamElem);
    NodoD* act = *pl;

    if(act)
    {
        while(act->sig)
            act = act->sig;
    }
    nue->ant = act;
    if(act)
        act->sig = nue;

    *pl = act;

    return TODO_OK;
}




bool eliminarPrimerElem(Lista* pl, void* elem, size_t tamElem)
{
    NodoD* nae = *pl;

    if(!nae)
        return false;

    while(nae->ant)
        nae = nae->ant;

    if(nae->sig)
        nae->sig->ant = nae->ant;

    if(nae == *pl)
    {
        if(nae->sig)
            *pl = nae->sig;
        else
            *pl = nae->ant;
    }

    destruirNodoD(nae, elem, tamElem);

    return true;
}



bool eliminarUltimoElem(Lista* pl, void* elem, size_t tamElem)
{
    NodoD* nae = *pl;

    if(!nae)
        return false;

    while(nae->sig)
        nae = nae->sig;

    if(nae->ant)
        nae->ant->sig = nae->sig;

    if(nae == *pl && nae->ant)
        *pl = nae->ant;
    else
        *pl = nae->sig;

    destruirNodoD(nae, elem, tamElem);

    return true;
}



Lista* buscarMenorEnLista(Lista* pl, Cmp cmp)
{
    Lista* pMen = pl;
    NodoD* act = *pl;

    if(!act)
        return NULL;

    *pMen = act;

    while(act->ant)
    {
        if(cmp(*pMen, act->elem) < 0)
            *pMen = act;

        act = act->ant;
    }

    act = *pl;

    while(act->sig)
    {
        if(cmp(*pMen, act->elem) < 0)
            *pMen = act;

        act = act->sig;
    }

    return pMen;
}



void recorrerLista(Lista* pl, Accion accion, void* datosAccion)
{
    NodoD* nodo = *pl;

    if(nodo)
    {
        accion(nodo->elem, datosAccion);

        while(nodo->ant)
        {
            nodo = nodo->ant;
            accion(nodo->elem, datosAccion);
        }
        nodo = *pl;
        while(nodo->sig)
        {
            nodo = nodo->sig;
            accion(nodo->elem, datosAccion);
        }
    }
}




void mostrarLista(Lista* pl, Mostrar mostrar)
{
    NodoD* nodo = *pl;

    if(nodo)
    {
        while(nodo->ant)
            nodo = nodo->ant;

        mostrar(nodo->elem);

        while(nodo->sig)
        {
            nodo = nodo->sig;
            mostrar(nodo->elem);
        }
    }
}



void ordenarListaInsercion(Lista* pl, Cmp cmp)
{
    Lista listOrd = NULL;
    NodoD* nodoOrig = *pl;
    NodoD* actual = listOrd;
    NodoD* ant = NULL;
    NodoD* sig = NULL;
    int comp;

    while(nodoOrig)
    {
        if(nodoOrig->ant)
        {
            nodoOrig = nodoOrig->ant;
            if(nodoOrig->ant)
                nodoOrig->ant->elem = nodoOrig->sig;
            if(nodoOrig->sig)
                nodoOrig->sig->ant = nodoOrig->ant;

            if(nodoOrig == *pl)
            {
                if(nodoOrig->ant)
                    *pl = nodoOrig->ant;
                else
                    *pl = nodoOrig->sig;
            }
        }
        else
        {
            if(nodoOrig->ant)
                nodoOrig->ant->elem = nodoOrig->sig;
            if(nodoOrig->sig)
                nodoOrig->sig->ant = nodoOrig->ant;

            if(nodoOrig == *pl)
            {
                if(nodoOrig->sig)
                    *pl = nodoOrig->sig;
                else
                    *pl = nodoOrig->ant;
            }
        }

        actual = listOrd;

        if(actual)
        {
            while(actual->ant && cmp(nodoOrig->elem, actual->elem) < 0)
                actual = actual->ant;

            while(actual->sig && cmp(nodoOrig->elem, actual->elem) > 0)
                actual = actual->sig;

            comp = cmp(nodoOrig->elem, actual->elem);

            if(comp < 0)
            {
                sig = actual;
                ant = actual->ant;
            }

            if(comp > 0)
            {
                ant = actual;
                sig = actual->sig;
            }
        }

        nodoOrig->sig = sig;
        nodoOrig->ant = ant;

        if(ant)
            ant->sig = nodoOrig;
        if(sig)
            sig->ant = nodoOrig;

        listOrd = nodoOrig;
    }
}
