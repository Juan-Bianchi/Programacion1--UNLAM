#ifndef PILADINAMICA_H
#define PILADINAMICA_H


#include <stdlib.h>
#include <stdbool.h>
#define min(a,b)    ((a)<(b)?(a):(b))

typedef struct sNodo
{
    void* elem;
    size_t tamElem;
    struct sNodo* sig;
}Nodo;

typedef Nodo* Pila;


void crearPila(Pila* pp);
bool apilar(Pila* pp, const void* elem, size_t tamElem);
bool desapilar(Pila* pp, void* elem, size_t tamElem);
bool verTopePila(const Pila* pp, void* elem, size_t tamElem);
bool pilaVacia(const Pila* pp);
bool pilaLlena(const Pila* pp, size_t tamElem);
void vaciarPila(Pila* pp);



#endif // PILADINAMICA_H
