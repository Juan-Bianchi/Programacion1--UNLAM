#ifndef TDA_PILA_H
#define TDA_PILA_H

#include<stdlib.h>

typedef int Pila;

void crearPila(Pila* pila);
bool apilar(Pila* pila, const void* elem, size_t tamElem);
bool desapilar(Pila* pila, void* elem, size_t tamElem);
bool topeDePila(const Pila* pila, void* elem, size_t tamElem);
bool pilaVacia(const Pila* pila);
bool pilaLlena(const Pila* pila, size_t tamElem);
void vaciarPila(const Pila* pila);

#endif // TDA_PILA_H