#ifndef LISTA_H
#define LISTA_H

#include <stdlib.h>
#include <stdbool.h>

#define TODO_OK 0
#define SIN_MEM 1
#define DUPLICADO 2
#define min(a,b)    ((a)<(b)?(a):(b))
#include "../../TP1/TP1-TipoFecha/Fecha.h"


typedef struct sNodo
{
    void* elem;
    size_t tamElem;
    struct sNodo* sig;
} Nodo;

typedef Nodo* Lista;
typedef int (*Cmp)(const void* elem1, const void* elem2);
typedef void (*Mostrar)(const void* elem);
typedef void (*Accion)(void* elem, void* datosAccion);

Nodo* crearNodo(const void* elem, size_t tamElem);
void destruirNodo(Nodo* nae, void* elem, size_t tamElem);


void crearLista(Lista* pl);
int insertarElementoEnListaOrd(Lista* pl, const void* elem, size_t tamElem, Cmp cmp);
int insertarElementoAlInicio(Lista* pl, const void* elem, size_t tamElem, Cmp cmp);
Nodo* buscarMenor(Lista* pl, Cmp cmp);
void ordenarListaInsercion(Lista* pl, Cmp cmp);
void mostrarLista(Lista* pl, Mostrar mostrar);
void recorrerLista(Lista* pl, Accion accion, void* datosAccion);


#endif // LISTA_H
