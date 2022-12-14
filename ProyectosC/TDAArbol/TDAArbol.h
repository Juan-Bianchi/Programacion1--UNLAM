#ifndef TDAARBOL_H
#define TDAARBOL_H

#define TDA_ARBOL_IMPL_DINAMICA

#ifdef TDA_ARBOL_IMPL_DINAMICA
    #include "../TDAArbolDinamica/TDAArbolDinamica.h"

#endif // TDA_ARBOL_IMPL_DINAMICA


void crearArbol(Arbol* pa);
int vaciarArbol(Arbol* pa);
int insertarEnArbol(Arbol* pa, const void* elem, size_t tamElem, Cmp cmp, Actualizar actualizar);
bool buscarEnArbol(const Arbol* pa, void* elem, size_t tamElem, Cmp cmp);
bool eliminarDeArbol(Arbol* pa, void* elem, size_t tamElem, Cmp cmp);
void recorrerArbolPreorden(const Arbol* pa, Accion accion, void* datosAccion);    /// RID
void recorrerArbolEnOrden(const Arbol* pa, Accion accion, void* datosAccion);     /// IRD
void recorrerArbolPosorden(const Arbol* pa, Accion accion, void* datosAccion);    /// IDR
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



#endif // TDAARBOL_H
