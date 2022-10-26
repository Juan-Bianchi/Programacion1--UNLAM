#ifndef LISTA_H
#define LISTA_H

#include <stdlib.h>
#include <stdbool.h>
#include "../../TP1/TP1-TipoFecha/Fecha.h"

#define SIN_MEM 1
#define TODO_OK 0
#define min(a,b)    ((a)<(b)?(a):(b))


typedef struct sNodo
{
    void* elem;
    size_t tamElem;
    struct sNodo* sig;
} Nodo;

typedef Nodo* Lista;

int typedef (*Cmp)(const void* elem1, const void* elem2);
void typedef (*Accion)(void* elem, void* datosAccion);

Nodo* crearNodo(const void* elem, size_t tamElem);
void destruirNodo(Nodo* nae, void* elem, size_t tamElem);


void crearLista(Lista* pl);
int insertarAlFinalListaDesord(Lista* pl, const void* elem, size_t tamElem);
bool eliminarDeListaDesord(Lista* pl, void* elem, size_t tamElem);
void ordenarListaInsercion(Lista* pl, Cmp cmp);







#endif // LISTA_H
