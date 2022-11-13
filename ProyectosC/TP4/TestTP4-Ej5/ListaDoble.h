#ifndef LISTADOBLE_H
#define LISTADOBLE_H

#include <stdlib.h>
#include <stdbool.h>
#include "../../TP1/TP1-TipoFecha/Fecha.h"

#define min(a,b)    ((a)<(b)?(a):(b))

#define TODO_OK 0
#define SIN_MEM 1
#define DUPLICADO 2

typedef struct sNodoD
{
    void* elem;
    size_t tamElem;
    struct sNodoD* sig;
    struct sNodoD* ant;
} NodoD;

typedef NodoD* Lista;

typedef int (*Cmp)(const void* e1, const void* e2);
typedef void (*Actualizar)(void* actualizado, const void* actualizador);
typedef void (*Accion)(void* elem, void* datosAccion);
typedef void (*Mostrar)(const void* elem);


void crearLista(Lista* pl);
int instertarElemEnListaOrd(Lista* pl, const void* elem, size_t tamElem, Cmp cmp, Actualizar actualizar);
int instertarElemEnListaOrdConDup(Lista* pl, const void* elem, size_t tamElem, Cmp cmp);
int insertarAlInicioLista(Lista* pl, const void* elem, size_t tamElem);
int insertarAlFinalLista(Lista* pl, const void* elem, size_t tamElem);
bool eliminarElemDeListaOrd(Lista* pl, void* elem, size_t tamElem, Cmp cmp);
bool buscarElementoEnListaOrd(Lista* pl, void* elem, size_t tamElem, Cmp cmp);
void vaciarLista(Lista* pl);


#endif // LISTADOBLE_H
