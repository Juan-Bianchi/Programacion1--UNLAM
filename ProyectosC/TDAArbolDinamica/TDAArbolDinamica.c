#include "TDAArbolDinamica.h"
#include <memory.h>
#include <stdio.h>

#define TDA_ARBOL_IMPL_DINAMICA


void graficarArbolRec(const Arbol* pa, MostrarElemArbol mostrar, int nivel);
Arbol* mayorDeArbol(Arbol* pa);
Arbol* menorDeArbol(Arbol* pa);
Arbol* buscarNodo(Arbol* pa, void* elem, Cmp cmp);
void eliminarNodo(Arbol* pa);
int cargarArbolDesdeArchivoOrdRec(FILE* arch, Arbol* pa, size_t tamElem, Cmp cmp, int li, int ls, Actualizar actualizar);


void crearArbol(Arbol* pa)
{
    *pa = NULL;
}



int vaciarArbol(Arbol* pa)
{
    if(!*pa)
      return 0;

    int cne = 0;
    cne += vaciarArbol(&(*pa)->hIzq);
    cne += vaciarArbol(&(*pa)->hDer);

    free((*pa)->elem);
    free(*pa);
    *pa = NULL;

    return cne + 1;
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
        if(actualizar)
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

    memcpy(elem, (*pnae)->elem, min(tamElem, (*pnae)->tamElem));
    free((*pnae)->elem);

    eliminarNodo(pnae);

    return true;
}



void recorrerArbolPreorden(const Arbol* pa, Accion accion, void* datosAccion)                     ///RID
{
    if(!*pa)
        return;

    accion((*pa)->elem, datosAccion);
    recorrerArbolPreorden(&(*pa)->hIzq, accion, datosAccion);
    recorrerArbolPreorden(&(*pa)->hDer, accion, datosAccion);
}



void recorrerArbolEnOrden(const Arbol* pa, Accion accion, void* datosAccion)                      /// IRD
{
    if(!*pa)
      return;

    recorrerArbolEnOrden(&(*pa)->hIzq, accion, datosAccion);
    accion((*pa)->elem, datosAccion);
    recorrerArbolEnOrden(&(*pa)->hDer, accion, datosAccion);
}



void recorrerArbolPosorden(const Arbol* pa, Accion accion, void* datosAccion)                     ///IDR
{
    if(!*pa)
      return;

    recorrerArbolPosorden(&(*pa)->hIzq, accion, datosAccion);
    recorrerArbolPosorden(&(*pa)->hDer, accion, datosAccion);
    accion((*pa)->elem, datosAccion);
}




int alturaArbol(const Arbol* pa)
{
    if(!*pa)
        return 0;

    int hi = alturaArbol(&(*pa)->hIzq);
    int hd = alturaArbol(&(*pa)->hDer);

    return 1 + ((hi > hd)? hi: hd);
}



int contarElemArbol(const Arbol* pa)
{
    if(!*pa)
      return 0;

    return contarElemArbol(&(*pa)->hIzq) + contarElemArbol(&(*pa)->hDer) + 1;
}



int contarElemArbolHastaNivel(const Arbol* pa, int nivel)
{
    if(!*pa)
        return 0;

    if(nivel == 0)
        return 1;

    return 1 + contarElemArbolHastaNivel(&(*pa)->hIzq, nivel - 1) + contarElemArbolHastaNivel(&(*pa)->hDer, nivel - 1);
}



int contarHojasArbol(const Arbol* pa)
{
    if(!*pa)
      return 0;

    if(!(*pa)->hIzq && !(*pa)->hDer)
      return 1;

    return contarHojasArbol(&(*pa)->hIzq) + contarHojasArbol(&(*pa)->hDer);
}



int podarArbol(Arbol* pa, int nivel)
{
    if(*pa)
      return 0;

    if(nivel == 0)
      return vaciarArbol(pa);

    return podarArbol(&(*pa)->hIzq, nivel - 1) + podarArbol(&(*pa)->hDer, nivel - 1);
}



bool esArbolCompleto(const Arbol* pa)
{
    int altura = alturaArbol(pa);
    int cnc = (1 << altura) - 1;

    int cnr = contarElemArbol(pa);

    return cnc == cnr;
}



bool esArbolBalanceado(const Arbol* pa)
{
    int altura = alturaArbol(pa);

    if(altura < 2)
        return true;

    int cnc = (1 << (altura - 1))- 1;

    int cnr = contarElemArbolHastaNivel(pa, altura-1);

    return cnc == cnr;
}



bool esArbolAVL(const Arbol* pa)
{
    if(!*pa)
        return true;

    int hi = alturaArbol(&(*pa)->hIzq);
    int hd = alturaArbol(&(*pa)->hDer);

    if(abs(hi - hd) > 1)
        return false;

    return esArbolAVL(&(*pa)->hIzq) && esArbolAVL(&(*pa)->hDer);
}



int cargarArbolDesdeArchivoOrdenado(Arbol* pa, const char* nombreArchivo, size_t tamReg, Cmp cmp, Actualizar actualizar)
{
    FILE* arch = fopen(nombreArchivo, "rb");
    fseek(arch, 0L, SEEK_END);
    int cr = ftell(arch) / tamReg;

    int ret = cargarArbolDesdeArchivoOrdRec(arch, pa, tamReg, cmp, 0, cr-1, actualizar);

    return ret;
}



void graficarArbol(const Arbol* pa, MostrarElemArbol mostrar)
{
    graficarArbolRec(pa, mostrar, 0);
}


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

    Arbol* pnreempl = hi >= hd? mayorDeArbol(&(*pnae)->hIzq): menorDeArbol(&(*pnae)->hDer);

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



int cargarArbolDesdeArchivoOrdRec(FILE* arch, Arbol* pa, size_t tamElem, Cmp cmp, int li, int ls, Actualizar actualizar)
{
    void* elem = malloc(tamElem);

    if(li > ls)
      return TODO_OK;

    int m = (li + ls) / 2;

    fseek(arch, m * tamElem, SEEK_SET);
    fread(elem, tamElem, 1, arch);

    insertarEnArbol(pa, elem, tamElem, cmp, actualizar);
    free(elem);

    cargarArbolDesdeArchivoOrdRec(arch, pa, tamElem, cmp, li, m-1, actualizar);

    return cargarArbolDesdeArchivoOrdRec(arch, pa, tamElem, cmp, m+1, ls, actualizar);
}



void graficarArbolRec(const Arbol* pa, MostrarElemArbol mostrar, int nivel)
{
    if(!*pa)
        return;

    graficarArbolRec(&(*pa)->hDer, mostrar, nivel + 1);
    mostrar((*pa)->elem, nivel);
    graficarArbolRec(&(*pa)->hIzq, mostrar, nivel + 1);
}
