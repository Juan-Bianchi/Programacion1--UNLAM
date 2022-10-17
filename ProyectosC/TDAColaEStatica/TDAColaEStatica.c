#define TDA_COLA_IMPLEMENTACION_ESTATICA
#include <memory.h>
#include "../TDACola/TDACola.h"


void copiarDatoEnCola(Cola* pc, const void* dato, size_t tamDato);
void copiarDatoEnElem(Cola* pc, void* dato, size_t tamDato);


void crearCola(Cola* pc)
{
    pc->fondo = 0;
    pc->frente = 0;
    pc->tamDisp = TAM;
}



bool encolar(Cola* pc, const void* elem, size_t tamElem)
{
    if(pc->tamDisp < tamElem + sizeof(size_t))
        return false;

    copiarDatoEnCola(pc, &tamElem, sizeof(size_t));
    copiarDatoEnCola(pc, elem, tamElem);

    pc->tamDisp -= (tamElem + sizeof(size_t));

    return true;
}



bool desencolar(Cola* pc, void* elem, size_t tamElem)
{
    size_t tamElemEncolado;

    if(pc->tamDisp == TAM)
        return false;

    copiarDatoEnElem(pc, &tamElemEncolado, sizeof(size_t));
    copiarDatoEnElem(pc, elem, min(tamElem, tamElemEncolado));

    pc->frente += tamElemEncolado - min(tamElemEncolado, tamElem);

    pc->tamDisp += tamElemEncolado + sizeof(size_t);

    return true;
}



bool verFrenteDeCola(const Cola* pc, void* elem, size_t tamElem)
{
    size_t tamElemEncolado;
    unsigned frente;

    if(pc->tamDisp == TAM)
        return false;

    frente = pc->frente;

    copiarDatoEnElem((Cola*)pc, &tamElemEncolado, sizeof(size_t));
    copiarDatoEnElem((Cola*)pc, elem, min(tamElem, tamElemEncolado));

    ((Cola*)pc)->frente = frente;

    return true;
}



bool colaVacia(const Cola* pc)
{
    return pc->tamDisp == TAM;
}



bool colaLlena(const Cola* pc, size_t tamElem)
{
    return pc->tamDisp < tamElem + sizeof(size_t);
}



void vaciarCola(Cola* pc)
{
    pc->fondo = 0;
    pc->frente = 0;
    pc->tamDisp = TAM;
}



void copiarDatoEnCola(Cola* pc, const void* dato, size_t tamDato)
{
    unsigned tamDispContiguo = (pc->fondo >= pc->frente)? TAM - pc->fondo: pc->frente - pc->fondo;
    unsigned tamACopiar = min(tamDispContiguo, tamDato);
    unsigned restoACopiar = tamDato - tamACopiar;

    memcpy(pc->vec + pc->fondo, dato, tamACopiar);
    if(restoACopiar > 0)
        memcpy(pc->vec, dato + tamACopiar, restoACopiar);

    pc->fondo = (pc->fondo + tamDato) % TAM;
}


void copiarDatoEnElem(Cola* pc, void* dato, size_t tamDato)
{
    unsigned tamDatoContiguo = (pc->fondo < pc->frente)? min(tamDato, TAM - pc->frente): tamDato;
    unsigned tamACopiar = tamDato - tamDatoContiguo;

    memcpy((void*)dato, pc->vec + pc->frente, tamDatoContiguo);
    if(tamACopiar > 0)
        memcpy((void*)dato + tamDatoContiguo, pc->vec, tamACopiar);

    pc->frente = (pc->frente + tamDato) % TAM;
}
