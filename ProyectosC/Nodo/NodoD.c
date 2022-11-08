#include "NodoD.h"
#include <memory.h>


NodoD* crearNodoD(const void* elem, size_t tamElem)
{
    NodoD* nue = (NodoD*)malloc(sizeof(NodoD));
    void* elemNodoD = malloc(tamElem);

    if(!nue || !elemNodoD)
    {
        free(elemNodoD);
        free(nue);
        return NULL;
    }

    memcpy(elemNodoD, elem, tamElem);
    nue->elem = elemNodoD;
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
