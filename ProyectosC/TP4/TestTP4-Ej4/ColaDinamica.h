#ifndef COLADINAMICA_H
#define COLADINAMICA_H

#include <stdlib.h>
#include <stdbool.h>

#define min(a,b)    ((a)<(b)?(a):(b))

typedef struct sNodo
{
    void* elem;
    size_t tamElem;
    struct sNodo* sig;
} Nodo;

typedef Nodo* Cola;


void crearCola(Cola* pc);
bool encolar(Cola* pc, const void* elem, size_t tamElem);
bool desencolar(Cola* pc, void* elem, size_t tamElem);
bool verFrenteCola(const Cola* pc, void* elem, size_t tamElem);
bool colaVacia(const Cola* pc);
bool colaLlena(const Cola* pc, size_t tamElem);
void vaciarCola(Cola* pc);

#endif // COLADINAMICA_H
