#ifndef TDALISTA_H
#define TDALISTA_H

#include <stdbool.h>

#ifdef TDA_LISTA_IMPLEMENTACION_ESTATICA
    #include "../TDAListaEstatica/TDAListaEstatica.h"
#endif // TDA_LISTA_IMPLEMENTACION_ESTATICA

#ifdef TDA_LISTA_IMPLEMENTACION_DINAMICA
    #include "../TDAListaDinamica/TDAListaDinamica.h"
#endif // TDA_LISTA_IMPLEMENTACION_DINAMICA

#ifdef TDA_LISTA_DOBLE_IMPLEMENTACION_DINAMICA
    #include "../TDAListaDoblementeEnlazadaDinamica/TDAListaDoblementeEnlazadaDinamica.h"
#endif // TDA_LISTA_DOBLE_IMPLEMENTACION_DINAMICA

int typedef (*Cmp)(const void* e1, const void* e2);
void typedef (*Actualizar)(void* acutalizado, const void* actualizador);
void typedef (*Accion)(void* elem, void* datosAccion);
void typedef (*Mostrar)(void* elem);

void crearLista(Lista* pl);
int insertarEnListaOrd(Lista* pl, const void* elem, size_t tameElem, Cmp cmp, Actualizar actualizar);
bool eliminarDeListaOrd(Lista* pl, void* elem, size_t tamElem, Cmp cmp);
int insertarAlInicio(Lista* pl, const void* elem, size_t tamElem, Cmp cmp);
int insertarAlfinal(Lista* pl, const void* elem, size_t tamElem, Cmp cmp);
bool eliminarPrimerElem(Lista* pl, void* elem, size_t tamElem);
bool eliminarUltimoElem(Lista* pl, void* elem, size_t tamElem);
Lista* buscarMenorEnLista(Lista* pl, Cmp cmp);
void recorrerLista(Lista* pl, Accion accion, void* datosAccion);
void mostrarLista(Lista* pl, Mostrar mostrar);



void ordenarListaSeleccion(Lista* pl, Cmp cmp);
void ordenarListaInsercion(Lista* pl, Cmp cmp);


#endif // TDALISTA_H







