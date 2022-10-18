#include "Pila.h"

#ifdef TDA_PILA_ESTATICA

void crearPila(Pila* pp)
{
    pp->tope = NULL;
}



bool apilar(Pila* pp, const void* elem, size_t tamElem)
{
    if(!(pp->tope))
        pp->tope = pp->vecElem;

    if(tamElem + sizeof(tamElem) > TAM - (pp->tope - (void*)pp->vecElem))
        return false;

    memcpy(pp->tope, elem, tamElem);
    pp->tope += tamElem;
    *(size_t*)pp->tope = tamElem;
    pp->tope += sizeof(tamElem);

    return true;
}



bool desapilar(Pila* pp, void* elem, size_t tamElem)
{
    size_t tamElemAp;

    if(pp->tope == (void*)pp->vecElem)
        return false;

    pp->tope -= sizeof(size_t);
    tamElemAp = *(size_t*)pp->tope;
    pp->tope -= tamElemAp;
    memcpy(elem, pp->tope, min(tamElemAp, tamElem));

    return true;
}



bool verTopePila(const Pila* pp, void* elem, size_t tamElem)
{
    size_t tamElemAp;
    void* tope = pp->tope;

    if(!pp->tope)
        return false;

    ((Pila*)pp)->tope -= sizeof(size_t);
    tamElemAp = *(size_t*)pp->tope;
    ((Pila*)pp)->tope -= tamElemAp;
    memcpy(elem, pp->tope, min(tamElem, tamElemAp));

    ((Pila*)pp)->tope = tope;

    return true;
}



bool pilaLlena(const Pila* pp, size_t tamElem)
{
    return (pp->tope - (void*)pp->vecElem ==  TAM);
}



bool pilaVacia(const Pila* pp)
{
    return !pp->tope;
}



void vaciarPila(Pila* pp)
{
    pp->tope = NULL;
}


#else

Nodo* crearNodo(const void* elem, size_t tamElem);
void destruirNodo(Nodo* nae, void* elem, size_t tamElem);


void crearPila(Pila* pp)
{
    *pp = NULL;
}


bool apilar(Pila* pp, const void* elem, size_t tamElem)
{
    Nodo* nue = crearNodo(elem, tamElem);

    if(!nue)
        return false;

    nue->sig = *pp;
    *pp = nue;

    return true;
}



bool desapilar(Pila* pp, void* elem, size_t tamElem)
{
    Nodo* nae;

    if(!*pp)
        return false;

    nae = *pp;
    *pp = nae->sig;
    destruirNodo(nae, elem, tamElem);

    return true;
}



bool verTopePila(const Pila* pp, void* elem, size_t tamElem)
{
    void* elemTope;
    size_t tamElemTope;

    if(!*pp)
        return false;

    elemTope = (*pp)->elem;
    tamElemTope = (*pp)->tamElem;

    memcpy(elem, elemTope, min(tamElem, tamElemTope));

    return true;
}



bool pilaLlena(const Pila* pp, size_t tamElem)
{
    void* nodo = malloc(sizeof(Nodo));
    void* elemNodo = malloc(tamElem);

    free(nodo);
    free(elemNodo);

    if(!nodo || !elemNodo)
        return false;

    return true;
}



bool pilaVacia(const Pila* pp)
{
    return !*pp;
}



void vaciarPila(Pila* pp)
{
    Nodo* nae;

    while(!*pp)
    {
        nae = *pp;
        *pp = nae->sig;

        free(nae->elem);
        free(nae);
    }
}





Nodo* crearNodo(const void* elem, size_t tamElem)
{
    Nodo* nue = (Nodo*)malloc(sizeof(Nodo));
    void* nueElem = malloc(tamElem);

    if(!nue || !nueElem)
    {
        free(nue);
        free(nueElem);
        return NULL;
    }

    memcpy(nueElem, elem, tamElem);
    nue->elem = nueElem;
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

#endif
