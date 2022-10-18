#ifndef PILA_H
#define PILA_H

#define min(a,b)    ((a)<(b)?(a):(b))
#include "../../TP1/TP1-TipoFecha/Fecha.h"
#include <stdbool.h>
#include <memory.h>
#include <stdlib.h>

int typedef (*Cmp)(const void* elem1, const void* elem2);
void typedef (*Mostrar)(const void* elem);


typedef struct
{
    char cod[7];
    char desc[15];
    char prov[15];
    tFecha fechaCompra;
    tFecha fechaVenc;
    int cant;
    float precComp;
    float precVent;
} Producto;

//#define TDA_PILA_ESTATICA
#ifdef TDA_PILA_ESTATICA

    #define TAM 1000

    typedef struct
    {
        Producto vecElem[TAM];
        size_t tamElem;
        void* tope;
    } Pila;
#else

    typedef struct sNodo
    {
        void* elem;
        size_t tamElem;
        struct sNodo* sig;
    } Nodo;

    typedef Nodo* Pila;
#endif // TDA_PILA_ESTATICA


void crearPila(Pila* pp);
bool apilar(Pila* pp, const void* elem, size_t tamElem);
bool desapilar(Pila* pp, void* elem, size_t tamElem);
bool verTopePila(const Pila* pp, void* elem,size_t tamelem);
bool pilaLlena(const Pila* pp, size_t tamElem);
bool pilaVacia(const Pila* pp);
void vaciarPila(Pila* pp);


#endif // PILA_H
