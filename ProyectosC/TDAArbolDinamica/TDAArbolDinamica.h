#ifndef TDAARBOLDINAMICA_H
#define TDAARBOLDINAMICA_H

#include "../Nodo/NodoA.h"
#include <stdbool.h>
#define min(a,b)    ((a)<(b)?(a):(b))
#define TODO_OK 0
#define SIN_MEM 1
#define DUPLICADO 2


typedef int (*Cmp)(const void* e1, const void* e2);
typedef void (*Mostrar)(const void* elem);
typedef void (*Actualizar)(void* actualizado, const void* actualizador);
typedef void (*Accion)(void* elem, void* datosAccion);
typedef void (*MostrarElemArbol)(const void* elem, int nivel);

typedef NodoA* Arbol;


#endif // TDAARBOLDINAMICA_H
