#include "../TDAPila/TDAPila.h"

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



bool verTopeDePila(const Pila* pp, void* elem, size_t tamElem)
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



bool pilaVacia(const Pila* pp)
{
    return !(*pp);
}



bool pilaLlena(const Pila* pp, size_t tamElem)
{
    void* elem = malloc(tamElem);
    void* nodo = malloc(sizeof(Nodo));

    free(elem);
    free(nodo);

    if(!elem || !nodo)
        return false;

    return true;
}



void vaciarPila(Pila* pp)
{
    Nodo* nae;

    while(*pp)
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
    void* elemNue = malloc(tamElem);

    if(!nue || !elemNue)
    {
        free(nue);
        free(elemNue);
        return NULL;
    }

    memcpy(elemNue, elem, tamElem);
    nue->tamElem = tamElem;
    nue->elem = elemNue;
    nue->sig = NULL;

    return nue;
}



void destruirNodo(Nodo* nae, void* elem, size_t tamElem)
{
    void* elemADest = nae->elem;
    size_t tamElemDest = nae->tamElem;

    memcpy(elem, elemADest, min(tamElem, tamElemDest));
    free(elemADest);
    free(nae);
}
