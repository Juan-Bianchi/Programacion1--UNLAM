#ifndef ARBOL_H
#define ARBOL_H

#include<stdlib.h>
#include<stdbool.h>

#define TODO_OK 0
#define SIN_MEM 1
#define DUPLICADO 2

#define min(a,b)    ((a)<(b)?(a):(b))
#define max(a,b)    ((a)>(b)?(a):(b))

typedef struct sNodoA
{
    void* elem;
    size_t tamElem;
    struct sNodoA* hIzq;
    struct sNodoA* hDer;
} NodoA;

typedef NodoA* Arbol;

typedef void (*Actualizar)(void* actualizado, const void* actualizador);
typedef int (*Cmp)(const void* e1, const void* e2);
typedef void (*Accion)(void* elem, void* datosAccion);
typedef void (*MostrarElemArbol)(const void* elem, int nivel);
typedef void (*Mostrar)(const void* elem);


void crearArbol(Arbol* pa);
int vaciarArbol(Arbol* pa);
int insertarEnArbol(Arbol* pa, const void* elem, size_t tamElem, Cmp cmp, Actualizar actualizar);
bool buscarEnArbol(const Arbol* pa, void* elem, size_t tamElem, Cmp cmp);
bool eliminarDeArbol(Arbol* pa, void* elem, size_t tamElem, Cmp cmp);
void recorrerArbolPreorden(const Arbol* pa, Accion accion, void* datosAccion);
void recorrerArbolEnOrden(const Arbol* pa, Accion accion, void* datosAccion);
void recorrerArbolPosorden(const Arbol* pa, Accion accion, void* datosAccion);
int alturaArbol(const Arbol* pa);
int contarElemArbol(const Arbol* pa);
int contarHojasArbol(const Arbol* pa);
int contarElemArbolHastaNivel(const Arbol* pa, int nivel);
int podarArbol(Arbol* pa, int nivel);
bool esArbolCompleto(const Arbol* pa);
bool esArbolBalanceado(const Arbol* pa);
bool esArbolAVL(const Arbol* pa);
int cargarArbolDesdeArchivoOrdenado(Arbol* pa, const char* nombreArchivo, size_t tamReg, Cmp cmp, Actualizar actualizar);
void graficarArbol(const Arbol* pa, MostrarElemArbol mostrar);
void mostrarHojas(const Arbol* pa, Mostrar mostrar);
void mostrarNodosNoHojas(const Arbol* pa, Mostrar mostrar);



#endif // ARBOL_H
