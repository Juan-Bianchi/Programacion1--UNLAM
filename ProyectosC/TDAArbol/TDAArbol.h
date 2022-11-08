#ifndef TDAARBOL_H
#define TDAARBOL_H

#define TDA_ARBOL_IMPL_DINAMICA

#ifdef TDA_ARBOL_IMPL_DINAMICA
    #include "../TDAArbolImplDinamica/TDAArbolDinamico.h"

#endif // TDA_ARBOL_IMPL_DINAMICA



void crearArbol(Arbol* pa);
void vaciarArbol(Arbol* pa);
int insertarEnArbol(Arbol* pa, const void* elem, size_t tamElem, Cmp cmp, Actualizar actualizar);
bool buscarEnArbol(const Arbol* pa, void* elem, size_t tamElem, Cmp cmp);
bool eliminarDeArbol(Arbol* pa, void* elem, size_t tamElem, Cmp cmp);
void recorrerArbolPreorden(const Arbol* pa, Accion accion, void* datosAccion);
void recorrerArbolEnOrden(const Arbol* pa, Accion accion, void* datosAccion);
void recorrerArbolPosorden(const Arbol* pa, Accion accion, void* datosAccion);
int alturaArbol(const Arbol* pa);
int cantidadNodosArbol(const Arbol* pa);
int cantidadHojasArbol(const Arbol* pa);
int podarArbol(Arbol* pa, int nivel);
bool esArbolCompleto(const Arbol* pa);
bool esArbolBalanceado(const Arbol* pa);
bool esArbolAVL(const Arbol* pa);
int cargarArbolDesdeArchivoOrdenado(Arbol* pa, const char* nombreArchivo, size_t tamElem, Cmp cmp);



#endif // TDAARBOL_H
