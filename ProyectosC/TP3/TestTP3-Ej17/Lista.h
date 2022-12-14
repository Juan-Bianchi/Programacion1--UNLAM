#ifndef LISTA_H
#define LISTA_H

#include <stdlib.h>
#include <stdbool.h>
#include "../../TP1/TP1-TipoFecha/Fecha.h"

#define min(a,b)    ((a)<(b)?(a):(b))
#define TODO_OK 0
#define SIN_MEM 1


int typedef (*Cmp)(const void* elem1, const void* elem2);
void typedef (*Accion)(void* elem, void* datosAccion);
void typedef (*Mostrar)(const void* elem);

typedef struct sNodo
{
    void* elem;
    size_t tamElem;
    struct sNodo* sig;
} Nodo;

Nodo* crearNodo(const void* elem, size_t tamElem);
void destruirNodo(Nodo* nae, void* elem, size_t tamElem);

typedef Nodo* Lista;

void crearLista(Lista* pl);
int insertarElementoEnListaDesordConDup(Lista* pl, const void* elem, size_t tamElem);
void ordenarListaInsercion(Lista* pl, Cmp cmp);



#endif // LISTA_H
