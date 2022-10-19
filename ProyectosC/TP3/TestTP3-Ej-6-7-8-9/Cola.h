#ifndef COLA_H
#define COLA_H

#include <stdlib.h>
#include <stdbool.h>
#include "../../TP1/TP1-TipoFecha/Fecha.h"
#define min(a,b)    ((a)<(b)?(a):(b))


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


//#define TDA_IMPLEMENTACION_ESTATICA
#ifdef TDA_IMPLEMENTACION_ESTATICA

#define TAM 1000

typedef struct
{
    Producto vecProd[TAM];
    void* frente;
    void* fondo;
    size_t tamDisp;
} Cola;


#else

typedef struct sNodo
{
    void* elem;
    size_t tamElem;
    struct sNodo* sig;
} Nodo;


typedef struct
{
    Nodo* fondo;
    Nodo* frente;
} Cola;
#endif // TDA_IMPLEMENTACION_ESTATICA



void crearCola(Cola* pc);
bool encolar(Cola* pc, const void* elem, size_t tamElem);
bool desencolar(Cola* pc, void* elem, size_t tamElem);
bool verFrenteCola(const Cola* pc, void* elem, size_t tamElem);
bool colaVacia(const Cola* pc);
bool colaLlena(const Cola* pc, size_t tamElem);
void vaciarCola(Cola* pc);



#endif // COLA_H
