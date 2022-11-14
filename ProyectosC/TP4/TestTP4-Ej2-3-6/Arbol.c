#include "Arbol.h"
#include <memory.h>
#include <stdio.h>


Arbol* mayorArbol(Arbol* pa);
Arbol* menorArbol(Arbol* pa);
NodoA* crearNodoA(const void* elem, size_t tamElem);
Arbol* buscarNodoA(Arbol* pa, void* elem, Cmp cmp);
void eliminarNodoA(Arbol* pa);
int cargarArbolDesdeArchivoOrdenadoRec(FILE* arch, Arbol* pa, size_t tamReg, Cmp cmp, int li, int ls, Actualizar actualizar);
void graficarArbolRec(const Arbol* pa, MostrarElemArbol mostrar, int nivel);


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
        if(!pa)
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
    Arbol* pnae = buscarNodoA(pa, elem, cmp);
    if(!pnae)
        return false;

    memcpy(elem, (*pnae)->elem, min(tamElem, (*pnae)->tamElem));
    free((*pnae)->elem);

    eliminarNodoA(pnae);

    return true;
}



void recorrerArbolPreorden(const Arbol* pa, Accion accion, void* datosAccion)
{
    if(!*pa)
        return;

    accion((*pa)->elem, datosAccion);
    recorrerArbolPreorden(&(*pa)->hIzq, accion, datosAccion);
    recorrerArbolPreorden(&(*pa)->hDer, accion, datosAccion);
}



void recorrerArbolEnOrden(const Arbol* pa, Accion accion, void* datosAccion)
{
    if(!*pa)
        return;

    recorrerArbolEnOrden(&(*pa)->hIzq, accion, datosAccion);
    accion((*pa)->elem, datosAccion);
    recorrerArbolEnOrden(&(*pa)->hDer, accion, datosAccion);
}



void recorrerArbolPosorden(const Arbol* pa, Accion accion, void* datosAccion)
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

    return max(hi, hd) + 1;
}



int contarElemArbol(const Arbol* pa)
{
    if(!*pa)
        return 0;

    return 1 + contarElemArbol(&(*pa)->hIzq) + contarElemArbol(&(*pa)->hDer);
}



int contarHojasArbol(const Arbol* pa)
{
    if(!*pa)
        return 0;

    if(!(*pa)->hIzq && !(*pa)->hDer)
        return 1;

    return contarHojasArbol(&(*pa)->hIzq) + contarHojasArbol(&(*pa)->hDer);
}



int contarElemArbolHastaNivel(const Arbol* pa, int nivel)
{
    if(!*pa)
        return 0;

    if(nivel == 0)
        return 1;

    return 1 + contarElemArbolHastaNivel(&(*pa)->hIzq, nivel - 1) + contarElemArbolHastaNivel(&(*pa)->hDer, nivel - 1);
}




int podarArbol(Arbol* pa, int nivel)
{
    if(!*pa)
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

    int cnc = (1 << (altura - 1)) - 1;

    int cnr = contarElemArbolHastaNivel(pa, altura - 2);

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
    if(!arch)
        return SIN_MEM;

    fseek(arch, 0L, SEEK_END);
    int cantReg = ftell(arch) / tamReg;

    int ret = cargarArbolDesdeArchivoOrdenadoRec(arch, pa, tamReg, cmp, 0, cantReg-1, actualizar);

    return ret;
}



void graficarArbol(const Arbol* pa, MostrarElemArbol mostrar)
{
    graficarArbolRec(pa, mostrar, 0);
}



void mostrarHojas(const Arbol* pa, Mostrar mostrar)
{
    if(!*pa)
        return;

    if(!(*pa)->hIzq && !(*pa)->hDer)
        mostrar((*pa)->elem);

    mostrarHojas(&(*pa)->hIzq, mostrar);
    mostrarHojas(&(*pa)->hDer, mostrar);
}



void mostrarNodosNoHojas(const Arbol* pa, Mostrar mostrar)
{
    if(!*pa)
        return;

    if((*pa)->hIzq && (*pa)->hDer)
        mostrar((*pa)->elem);

    mostrarNodosNoHojas(&(*pa)->hIzq, mostrar);
    mostrarNodosNoHojas(&(*pa)->hDer, mostrar);
}




/////////////////////////////////////////////////////////////////////////////////////////////////////

NodoA* crearNodoA(const void* elem, size_t tamElem)
{
    NodoA* nue = (NodoA*)malloc(sizeof(NodoA));
    void* elemNue = malloc(tamElem);

    if(!nue || !elemNue)
    {
        free(nue);
        free(elemNue);
        return NULL;
    }

    memcpy(elemNue, elem, tamElem);
    nue->elem = elemNue;
    nue->tamElem = tamElem;
    nue->hIzq = NULL;
    nue->hDer = NULL;

    return nue;
}


Arbol* buscarNodoA(Arbol* pa, void* elem, Cmp cmp)
{
    if(!*pa)
        return NULL;

    int comp = cmp(elem, (*pa)->elem);
    if(comp == 0)
        return pa;

    return buscarNodoA((comp < 0)? &(*pa)->hIzq: &(*pa)->hDer, elem, cmp);
}


void eliminarNodoA(Arbol* pnae)
{
    if(!(*pnae)->hIzq && !(*pnae)->hDer)
    {
        free(*pnae);
        *pnae = NULL;

        return;
    }

    int hi = alturaArbol(&(*pnae)->hIzq);
    int hd = alturaArbol(&(*pnae)->hDer);

    Arbol* pnreempl = (hi > hd)? mayorArbol(&(*pnae)->hIzq): menorArbol(&(*pnae)->hDer);

    (*pnae)->elem = (*pnreempl)->elem;
    (*pnae)->tamElem = (*pnreempl)->tamElem;

    eliminarNodoA(pnreempl);
}


Arbol* mayorArbol(Arbol* pa)
{
    if(!(*pa)->hDer)
        return pa;

    return mayorArbol(&(*pa)->hDer);
}



Arbol* menorArbol(Arbol* pa)
{
    if(!(*pa)->hIzq)
        return pa;

    return menorArbol(&(*pa)->hIzq);
}



int cargarArbolDesdeArchivoOrdenadoRec(FILE* arch, Arbol* pa, size_t tamReg, Cmp cmp, int li, int ls, Actualizar actualizar)
{
    void* elem = malloc(tamReg);
    if(!elem)
        return SIN_MEM;

    if(li > ls)
        return TODO_OK;

    int m = (li + ls) / 2;

    fseek(arch, tamReg * m, SEEK_SET);
    fread(elem, tamReg, 1, arch);
    insertarEnArbol(pa, elem, tamReg, cmp, actualizar);

    free(elem);

    return cargarArbolDesdeArchivoOrdenadoRec(arch, pa, tamReg, cmp, li, m-1, actualizar) +
           cargarArbolDesdeArchivoOrdenadoRec(arch, pa, tamReg, cmp, m+1, ls, actualizar);
}


void graficarArbolRec(const Arbol* pa, MostrarElemArbol mostrar, int nivel)
{
    if(!*pa)
        return;

    graficarArbolRec(&(*pa)->hDer, mostrar, nivel + 1);
    mostrar((*pa)->elem, nivel);
    graficarArbolRec(&(*pa)->hIzq, mostrar, nivel + 1);
}
