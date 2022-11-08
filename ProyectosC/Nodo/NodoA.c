#include "NodoA.h"
#include <memory.h>


NodoA* crearNodo(const void* elem, size_t tamElem)
{
    NodoA* nue = (NodoA*)malloc(sizeof(NodoA));
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
    nue->hIzq = NULL;
    nue->hDer = NULL;

    return nue;
}
