#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include "../../Nodo/Nodo.h"
#include "../../TP1/TP1-TipoFecha/Fecha.h"
#include <stdbool.h>
#include <stdlib.h>


typedef Nodo* Pila;

void crearPila(Pila* pp);
bool apilar(Pila* pp, const void* elem, size_t tamElem);
bool desapilar(Pila* pp, void* elem, size_t tamElem);
bool verTopePila(Pila* pp, void* elem, size_t tamElem);
bool pilaVacia(const Pila* pp);
bool pilaLlena(const Pila* pp, size_t tamElem);
void vaciarPila(Pila* pp);



#endif // PILA_H_INCLUDED
