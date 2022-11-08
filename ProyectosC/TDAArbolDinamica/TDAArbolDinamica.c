#include "TDAArbolDinamica.h"
#include <memory.h>

#define TDA_ARBOL_IMPL_DINAMICA



Arbol* mayorDeArbol(Arbol* pa);
Arbol* menorDeArbol(Arbol* pa);
Arbol* buscarNodo(Arbol* pa, void* elem, Cmp cmp);
void eliminarNodo(Arbol* pa);


void crearArbol(Arbol* pa)
{
    *pa = NULL;
}



void vaciarArbol(Arbol* pa)
{

}



int insertarEnArbol(Arbol* pa, const void* elem, size_t tamElem, Cmp cmp, Actualizar actualizar)
{
    if(!*pa)
    {
        *pa = crearNodoA(elem, tamElem);
        if(!*pa)
            return SIN_MEM;

        return TODO_OK;
    }

    int comp = cmp(elem, (*pa)->elem);

    if(comp == 0)
    {
        actualizar((*pa)->elem, elem);
        return DUPLICADO;
    }

    return insertarEnArbol((comp < 0)? &(*pa)->hIzq: &(*pa)->hDer, elem, tamElem, cmp, actualizar);
}



bool buscarEnArbol(const Arbol* pa, void* elem, size_t tamElem, Cmp cmp)
{
    if(!*pa)
        return false;

    int comp = cmp(elem, (*pa)->elem);

    if(comp == 0)
    {
        memcpy(elem, (*pa)->elem, min(tamElem, (*pa)->tamElem));
        return true;
    }

    return buscarEnArbol((comp < 0)? &(*pa)->hIzq: &(*pa)->hDer, elem, tamElem, cmp);
}



bool eliminarDeArbol(Arbol* pa, void* elem, size_t tamElem, Cmp cmp)
{
    Arbol* pnae = buscarNodo(pa, elem, cmp);

    if(!pnae)
        return false;

    eliminarNodo(pnae);

    return true;
}



void recorrerArbolPreorden(const Arbol* pa, Accion accion, void* datosAccion);
void recorrerArbolEnOrden(const Arbol* pa, Accion accion, void* datosAccion);
void recorrerArbolPosorden(const Arbol* pa, Accion accion, void* datosAccion);




int alturaArbol(const Arbol* pa)
{
    if(!*pa)
        return 0;

    hi = alturaArbol(&(*pa)->hIzq);
    hd = alturaArbol(&(*pa)->hDer);

    return 1 + (hi > hd)? hi: hd;
}



int cantidadNodosArbol(const Arbol* pa);
int cantidadHojasArbol(const Arbol* pa);
int podarArbol(Arbol* pa, int nivel);
bool esArbolCompleto(const Arbol* pa);
bool esArbolBalanceado(const Arbol* pa);
bool esArbolAVL(const Arbol* pa);
int cargarArbolDesdeArchivoOrdenado(Arbol* pa, const char* nombreArchivo, size_t tamElem, Cmp cmp);



/////////////////FUNCIONES UTILITARIAS CON NODOS//////////////////////

Arbol* buscarNodo(Arbol* pa, void* elem, Cmp cmp)
{
    if(!*pa)
        return NULL;

    int comp = cmp(elem, (*pa)->elem);

    if(comp == 0)
        return pa;

    return buscarNodo(comp < 0? &(*pa)->hIzq: &(*pa)->hDer, elem, cmp);
}



void eliminarNodo(Arbol* pnae)
{
    if(!(*pnae)->hIzq && !(*pnae)->hDer)
    {
        free(*pnae);
        *pnae = NULL;
        return;
    }

    int hi = alturaArbol(&(*pnae)->hIzq);
    int hd = alturaArbol(&(*pnae)->hDer);

    Arbol* pnreempl = hi >= hd mayorDeArbol(&(*pnae)->hIzq): menorDeArbol(&(*pnae)->hDer);

    (*pnae)->elem = (*pnreempl)->elem;
    (*pnae)->tamElem = (*pnreempl)->tamElem;

    eliminarNodo(pnreempl);
}



Arbol* mayorDeArbol(Arbol* pa)
{
    return &(*pa)->hDer ? mayorDeArbol(&(*pa)->hDer): pa;
}



Arbol* menorDeArbol(Arbol* pa)
{
    return &(*pa)->hIzq ? menorDeArbol(&(*pa)->hIzq): pa;
}
