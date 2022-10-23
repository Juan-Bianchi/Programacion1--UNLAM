#ifndef COLA_H
#define COLA_H

#include "Pila.h"


typedef struct
{
    Nodo* frente;
    Nodo* fondo;
} Cola;


void crearCola(Cola* pc);
bool encolar(Cola* pc, const void* elem, size_t tamElem);
bool desencolar(Cola* pc, void* elem, size_t tamElem);
bool verFrenteCola(const Cola* pc, void* elem, size_t tamElem);
bool colaVacia(const Cola* pc);
bool colaLlena(const Cola* pc, size_t tamElem);
void vaciarCola(Cola* pc);


#endif // COLA_H
