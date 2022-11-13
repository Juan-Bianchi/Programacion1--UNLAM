#include "ListaDoble.h"
#include <memory.h>

NodoD* crearNodoD(const void* elem, size_t tamElem);
void destruirNodoD(NodoD* nae, void* elem, size_t tamElem);


void crearLista(Lista* pl)
{
    *pl = NULL;
}



int instertarElemEnListaOrd(Lista* pl, const void* elem, size_t tamElem, Cmp cmp, Actualizar actualizar)
{
    NodoD* nue;
    NodoD* act = *pl, * ant = NULL, * sig = NULL;
    int comp;

    if(act)
    {
        while(act  && cmp(elem, act->elem) < 0)
            act = act->ant;

        while(act && cmp(elem, act->elem) > 0)
            act = act->sig;

        comp = cmp(elem, act->elem);

        if(comp == 0)
        {
            actualizar(act->elem, elem);
            *pl = act;
            return DUPLICADO;
        }

        if(comp < 0)
        {
            sig = act;
            ant = act->ant;
        }
        if(comp > 0)
        {
            ant = act;
            sig = act->sig;
        }
    }

    nue = crearNodoD(elem, tamElem);
    if(!nue)
        return SIN_MEM;

    nue->sig = sig;
    nue->ant = ant;

    if(ant)
        ant->sig = nue;
    if(sig)
        sig->ant = nue;

    *pl = nue;

    return true;
}



int instertarElemEnListaOrdConDup(Lista* pl, const void* elem, size_t tamElem, Cmp cmp)
{
    NodoD* nue, * act = *pl, * ant = NULL, * sig = NULL;
    int comp;

    if(act)
    {
        while(act->ant && cmp(elem, act->elem) < 0)
            act = act->ant;
        while(act->sig && cmp(elem, act->elem) > 0)
            act = act->sig;

        comp = cmp(elem, act->elem);

        if(comp <= 0)
        {
            sig = act;
            ant = act->ant;
        }
        else
        {
            ant = act;
            sig = act->sig;
        }
    }

    nue = crearNodoD(elem, tamElem);
    if(!nue)
        return SIN_MEM;

    nue->ant = ant;
    nue->sig = sig;

    if(ant)
        ant->sig = nue;
    if(sig)
        sig->ant = nue;

    *pl = nue;

    return TODO_OK;
}



int insertarAlInicioLista(Lista* pl, const void* elem, size_t tamElem)
{
    NodoD* act = *pl, * nue;

    if(act)
    {
        while(act->ant)
            act = act->ant;
    }

    nue = crearNodoD(elem, tamElem);
    if(!nue)
        return SIN_MEM;

    nue->sig = act;
    nue->ant = NULL;
    if(act)
        act->ant = nue;

    *pl = nue;

    return TODO_OK;
}




int insertarAlFinalLista(Lista* pl, const void* elem, size_t tamElem)
{
    NodoD* nue;
    NodoD* act = *pl;

    if(act)
    {
        while(act->sig)
            act = act->sig;
    }

    nue = crearNodoD(elem, tamElem);
    if(!nue)
        return SIN_MEM;

    nue->ant = act;
    nue->sig = NULL;
    if(act)
        act->sig = nue;

    *pl = nue;

    return TODO_OK;
}



bool eliminarElemDeListaOrd(Lista* pl, void* elem, size_t tamElem, Cmp cmp)
{
    NodoD* nae = *pl;

    if(!nae)
        return false;

    while(nae->ant && cmp(elem, nae->elem) < 0)
        nae = nae->ant;
    while(nae->sig && cmp(elem, nae->elem) > 0)
        nae = nae->sig;

    if(cmp(elem, nae->elem) != 0)
        return false;

    if(nae->ant)
        nae->ant->sig = nae->sig;
    if(nae->sig)
        nae->sig->ant = nae->ant;

    if(nae==*pl)
    {
        if(nae->sig)
            *pl = nae->sig;
        else
            *pl = nae->ant;
    }

    destruirNodoD(nae, elem, tamElem);

    return true;
}



bool buscarElementoEnListaOrd(Lista* pl, void* elem, size_t tamElem, Cmp cmp)
{
    NodoD* act = *pl;

    if(!act)
        return false;

    while(act->ant && cmp(elem, act->elem) < 0)
        act = act->ant;
    while(act->sig && cmp(elem, act->sig) > 0)
        act = act->sig;

    if(cmp(elem, act->elem) != 0)
        return false;

    memcpy(elem, act->elem, min(tamElem, act->tamElem));

    return true;
}



NodoD* crearNodoD(const void* elem, size_t tamElem)
{
    NodoD* nue = (NodoD*)malloc(sizeof(NodoD));
    void* elemNodo = malloc(tamElem);


    if(!nue || !elemNodo)
    {
        free(nue);
        free(elemNodo);
        return NULL;
    }

    memcpy(elemNodo, elem, tamElem);
    nue->elem = elemNodo;
    nue->tamElem = tamElem;
    nue->ant = NULL;
    nue->sig = NULL;

    return nue;
}



void destruirNodoD(NodoD* nae, void* elem, size_t tamElem)
{
    memcpy(elem, nae->elem, min(tamElem, nae->tamElem));
    free(nae->elem);
    free(nae);
}


void vaciarLista(Lista* pl)
{
    NodoD* nae = *pl;

    while(nae)
    {
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

        free(nae->elem);
        free(nae);

        nae = nae->sig;
    }

}
