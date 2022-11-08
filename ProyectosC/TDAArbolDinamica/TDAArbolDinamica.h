#ifndef TDAARBOLDINAMICA_H
#define TDAARBOLDINAMICA_H

#include "../Nodo/NodoA.h"
#include <stdbool.h>
#define min(a,b)    ((a)<(b)?(a):(b))
#define TODO_OK 0
#define SIN_MEM 1
#define DUPLICADO 2


int typedef (*Cmp)(const void* e1, const void* e2);
void typedef (*Mostrar)(const void* elem);
void typedef (*Actualizar)(void* actualizado, const void* actualizador);
void typedef (*Accion)(void* elem, void* datosAccion);

typedef NodoA* Arbol;


#endif // TDAARBOLDINAMICA_H
