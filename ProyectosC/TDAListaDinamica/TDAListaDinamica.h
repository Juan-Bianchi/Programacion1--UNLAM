#ifndef TDALISTADINAMICA_H
#define TDALISTADINAMICA_H

#define TODO_OK 0
#define DUPLICADO 1
#define SIN_MEM 2

#include <stdlib.h>
#include <stdbool.h>
#define min(a,b)    ((a)<(b)?(a):(b))
#include "../Nodo/Nodo.h"


typedef Nodo* Lista;

int typedef (*Cmp)(const void* elem1, const void* elem2);
int typedef (*Actualizar)(void* orig, const void* nue);
void typedef (*Mostrar)(const void* elem);
void typedef (*Accion)(void* elem, void* datosAccion);






#endif // TDALISTADINAMICA_H
