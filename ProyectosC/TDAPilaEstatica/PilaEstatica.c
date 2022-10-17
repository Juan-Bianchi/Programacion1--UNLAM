#include "../TDAPila/TDAPila.h"


void crearPila(Pila* pila)
{
    pila->tope = 0;
}



bool apilar(Pila* pila, const void* elem, size_t tamElem)
{
    if(tamElem + sizeof(size_t) > TAM - pila->tope)
        return false;

    memcpy(pila->vPila + pila->tope, elem, tamElem);
    pila->tope += tamElem;
    //memcpy(pila->vPila + pila->tope, &tamElem, sizeof(tamElem));              //equivalente a la linea 19
    *(size_t*) (pila->vPila + pila->tope) = tamElem;
    pila->tope += sizeof(size_t);

    return true;
}



bool desapilar(Pila* pila, void* elem, size_t tamElem)
{
    size_t tamElemAp;

    if(pila->tope == 0)
        return false;

    pila->tope -= sizeof(size_t);
    tamElemAp = *(size_t*)(pila->vPila + pila->tope);

    pila->tope -= tamElemAp;
    memcpy(elem, pila->vPila + pila->tope, min(tamElem, tamElemAp));

    return true;
}



bool VerTopeDePila(const Pila* pila, void* elem, size_t tamElem)
{
    size_t tamElemAp;
    unsigned tope = pila->tope;

    if(pila->tope == 0)
        return false;

    tope -= sizeof(tamElem);
    tamElemAp = *(size_t*)(pila->vPila + tope);

    tope -= tamElemAp;
    memcpy(elem, pila->vPila + tope, min(tamElem, tamElemAp));

    return true;
}




bool pilaVacia(const Pila* pila)
{
    return pila->tope == 0;
}



bool pilaLlena(const Pila* pila, size_t tamElem)
{
    return tamElem + sizeof(size_t) > TAM - pila->tope;
}




void vaciarPila(Pila* pila)
{
    pila->tope = 0;
}
