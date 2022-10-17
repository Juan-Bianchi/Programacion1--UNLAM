#ifndef TDACOLA_H
#define TDACOLA_H

#include <stdbool.h>

#ifdef TDA_COLA_IMPLEMENTACION_ESTATICA
    #include "../TDAColaEstatica/TDAColaEstatica.h"
#else
    #include "../TDAColaDinamica/TDAColaDinamica.h"
#endif // TDA_COLA_IMPLEMENTACION_ESTATICA

#include <stdlib.h>

void crearCola(Cola* pc);
bool encolar(Cola* pc, const void* elem, size_t tamElem);
bool desencolar(Cola* pc, void* elem, size_t tamElem);
bool verFrenteDeCola(const Cola* pc, void* elem, size_t tamElem);
bool colaVacia(const Cola* pc);
bool colaLlena(const Cola* pc, size_t tamElem);
void vaciarCola(Cola* pc);



#endif // TDACOLA_H
