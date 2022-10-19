#include "Cola.h"
#include <memory.h>

//#define TDA_IMPLEMENTACION_ESTATICA
#ifdef TDA_IMPLEMENTACION_ESTATICA

void copiarDatoEnCola(Cola* pc, const void* elem, size_t tamElem);
void copiarDatoDeCola(Cola* pc, const void* elem, size_t tamElem);

void crearCola(Cola* pc)
{
    pc->fondo = pc->frente = pc->vecProd;
    pc->tamDisp = TAM;
}



bool encolar(Cola* pc, const void* elem, size_t tamElem)
{
    if(tamElem + sizeof(size_t) > pc->tamDisp)
        return false;

    copiarDatoEnCola(pc, &tamElem, sizeof(size_t));
    copiarDatoEnCola(pc, elem, tamElem);

    pc->tamDisp -= (sizeof(size_t) + tamElem);

    return true;
}



bool desencolar(Cola* pc, void* elem, size_t tamElem)
{
    if(pc->tamDisp == TAM)
        return false;

    size_t tamElemCola;

    copiarDatoDeCola(pc, &tamElemCola, sizeof(size_t));
    copiarDatoDeCola(pc, elem, min(tamElemCola, tamElem));

    pc->frente += tamElemCola - min(tamElemCola, tamElem);

    pc->tamDisp += tamElemCola + sizeof(size_t);

    return true;
}



bool verFrenteCola(const Cola* pc, void* elem, size_t tamElem)
{
    if(pc->tamDisp == TAM)
        return false;

    size_t tamElemCola;
    void* frente = pc->frente;

    copiarDatoDeCola((Cola*)pc, &tamElemCola, sizeof(size_t));
    copiarDatoDeCola((Cola*)pc, elem, min(tamElemCola, tamElem));

    ((Cola*)pc)->frente = frente;

    return true;
}



bool colaVacia(const Cola* pc)
{
    return pc->tamDisp == TAM;
}



bool colaLlena(const Cola* pc, size_t tamElem)
{
    return pc->tamDisp < (tamElem + sizeof(size_t));
}



void vaciarCola(Cola* pc)
{
    pc->fondo = pc->frente = pc->vecProd;
    pc->tamDisp = TAM;
}



void copiarDatoEnCola(Cola* pc, const void* elem, size_t tamElem)
{
    unsigned tamContDisp = (pc->frente <= pc->fondo)? ((void*)pc->vecProd + TAM) - pc->fondo: pc->frente - pc->fondo;
    unsigned tamACopiar = min(tamContDisp, tamElem);
    unsigned restoACopiar = tamElem - tamACopiar;

    memcpy(pc->fondo, elem, tamACopiar);

    if(restoACopiar)
        memcpy(pc->vecProd, elem + tamACopiar, restoACopiar);

    pc->fondo = pc->fondo + tamElem;
    if(pc->fondo > (void*)pc->vecProd + TAM)
        pc->fondo -= TAM;
}



void copiarDatoDeCola(Cola* pc, const void* elem, size_t tamElem)
{
    unsigned tamContDisp = pc->frente < pc->fondo? tamElem: min(tamElem, (void*)pc->vecProd + TAM - 1 - pc->frente);
    unsigned tamACopiar = tamElem - tamContDisp;

    memcpy((void*)elem, pc->frente, tamContDisp);
    if(tamACopiar > 0)
        memcpy((void*)elem + tamContDisp, pc->vecProd, tamACopiar);

    pc->frente = pc->frente + tamElem;
    if(pc->frente > (void*)pc->vecProd + TAM)
        pc->frente -= TAM;
}


#else

Nodo* crearNodo(const void* elem, size_t tamElem);
void destruirNodo(Nodo* nae, void* elem, size_t tamElem);


void crearCola(Cola* pc)
{
    pc->fondo = pc->frente = NULL;
}



bool encolar(Cola* pc, const void* elem, size_t tamElem)
{
    Nodo* nue = crearNodo(elem, tamElem);

    if(!nue)
        return false;

    if(pc->fondo)
       pc->fondo->sig = nue;
    else
        pc->frente = nue;

    pc->fondo = nue;

    return true;
}



bool desencolar(Cola* pc, void* elem, size_t tamElem)
{
    Nodo* nae;

    if(!pc->frente)
        return false;

    nae = pc->frente;
    pc->frente = nae->sig;

    if(!pc->frente)
        pc->fondo = NULL;

    destruirNodo(nae, elem, tamElem);

    return true;
}



bool verFrenteCola(const Cola* pc, void* elem, size_t tamElem)
{
    if(!pc->frente)
        return false;

    memcpy(elem, pc->frente->elem, min(tamElem, pc->frente->tamElem));

    return true;
}



bool colaVacia(const Cola* pc)
{
    return !pc->frente;
}



bool colaLlena(const Cola* pc, size_t tamElem)
{
    void* nue = malloc(sizeof(Nodo));
    void* elemNue = malloc(tamElem);

    free(elemNue);
    free(nue);

    if(!nue || !elemNue)
        return false;

    return true;
}



void vaciarCola(Cola* pc)
{
    Nodo* nae;

    while(pc->frente)
    {
        nae = pc->frente;
        pc->frente = nae->sig;

        if(!pc->frente)
            pc->fondo = NULL;

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


#endif // TDA_IMPLEMENTACION_ESTATICA
