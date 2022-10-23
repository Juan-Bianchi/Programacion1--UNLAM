#ifndef COLA_H
#define COLA_H

#include <stdlib.h>
#include <stdbool.h>

#define min(a,b)    ((a)<(b)?(a):(b))

typedef struct sNodo
{
    void* elem;
    size_t tamElem;
    struct sNodo* sig;
} Nodo;


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
