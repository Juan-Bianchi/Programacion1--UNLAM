#ifndef TDALISTA_H
#define TDALISTA_H

#include <stdbool.h>

#ifdef TDA_LISTA_IMPLEMENTACION_ESTATICA
    #include "../TDAListaEstatica/TDAListaEstatica.h"
#else
    #include "../TDAListaDinamica/TDAListaDinamica.h"

#endif // TDA_LISTA_IMPLEMENTACION_ESTATICA


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







