#include "Vectores.h"

void desplazarPosVecALaDer(Vector* vect, const int pos);
void desplazarPosVecALaDerAritPunt(Vector* vect, const int pos);
void desplazarPosVecALaIzq(Vector* vect, const int pos);
void desplazarPosVecALaIzqAritPunt(Vector* vect, const int pos);



/*Ejercicio 22
Desarrollar una función que inserte un elemento en un arreglo de enteros, dada la posición de inserción.*/

int insertarVectorEnPosicion(Vector* vectr, const int pos, const int elem)
{
    if(vectr->cantElem  >= CAPACIDAD_VECTOR)
        return SIN_MEMORIA;

    desplazarPosVecALaDer(vectr, pos);

    if(vectr->cantElem + 1 < pos)
        vectr->vec[vectr->cantElem] = elem;
    else
        vectr->vec[pos-1] = elem;

    vectr->cantElem ++;

    return TODO_OK;
}

int insertarVectorEnPosicionAritPunt(Vector* vectr, const int pos, const int elem)
{
    if(vectr->cantElem  >= CAPACIDAD_VECTOR)
        return SIN_MEMORIA;

    desplazarPosVecALaDerAritPunt(vectr, pos);

    if(vectr->cantElem + 1 < pos)
        *(vectr->vec + vectr->cantElem ) = elem;
    else
        *(vectr->vec + pos - 1) = elem;

    vectr->cantElem ++;

    return TODO_OK;
}


void desplazarPosVecALaDer(Vector* vect, const int pos)
{
    int i;

    for(i = vect->cantElem - 1; i >= pos-1; i--)
        vect->vec[i+1] = vect->vec[i];

}

void desplazarPosVecALaDerAritPunt(Vector* vect, const int pos)
{
    int* pVec;

    for(pVec = vect->vec + vect->cantElem - 1; pVec >= vect->vec + pos -1; pVec --)
        *(pVec+1) = *pVec;
}



/*Ejercicio 23
Desarrollar una función que inserte un elemento en un arreglo de enteros, ordenado en forma ascendente, de forma de no alterar el orden.*/

int insertarElemEnVectOrdenado(Vector* vect, const int elem)
{
    int i=0;

    if(vect->cantElem >= CAPACIDAD_VECTOR)
        return SIN_MEMORIA;

    while(i<vect->cantElem && elem>vect->vec[i])
        i++;

    desplazarPosVecALaDer(vect, i);

    vect->vec[i] = elem;
    vect->cantElem ++;

    return TODO_OK;
}

int insertarElemEnVectOrdenadoAritPunt(Vector* vect, const int elem)
{
    int* pVec = vect->vec, pos = 0;

    if(vect->cantElem >= CAPACIDAD_VECTOR)
        return SIN_MEMORIA;

    while(pVec < vect->vec + vect->cantElem && elem <= *(pVec))
    {
        pVec ++;
        pos ++;
    }

    desplazarPosVecALaDerAritPunt(vect, pos);

    *(pVec) = elem;
    vect->cantElem ++;

    return TODO_OK;
}


/*Ejercicio 24
Desarrollar una función que elimine el elemento que ocupa una determinada posición de un arreglo de enteros.*/

int eliminarElemEnPos(Vector* vect, const int pos)
{
    int nae;

    if(pos > vect->cantElem)
        return ERROR;

    nae = vect->vec[pos-1];
    desplazarPosVecALaIzq(vect, pos);
    vect->cantElem --;

    return nae;
}


void desplazarPosVecALaIzq(Vector* vect, const int pos)
{
    int i;

    for(i = pos-1; i < vect->cantElem-1; i++)
        vect->vec[i] = vect->vec[i+1];
}



int eliminarElemEnPosAritPunt(Vector* vect, const int pos)
{
    int nae;

    if(pos > vect->cantElem)
        return ERROR;

    nae = *(vect->vec + pos - 1);
    desplazarPosVecALaIzqAritPunt(vect, pos);
    vect->cantElem --;

    return nae;
}

void desplazarPosVecALaIzqAritPunt(Vector* vect, const int pos)
{
    int* pVec;

    for(pVec = vect->vec + pos - 1; pVec < vect->vec + vect->cantElem -1; pVec ++)
        *pVec = *(pVec+1);
}


/*Ejercicio 25
Desarrollar una función que elimine la primera aparición de un elemento determinado de un arreglo de enteros.*/

int eliminarPrimeraAparicion(Vector* vect, const int elem)
{
    int i = 0;

    while(vect->vec[i] != elem && i<vect->cantElem)
        i++;

    if(i == vect->cantElem - 1)
        return ERROR;

    desplazarPosVecALaIzq(vect, i+1);
    vect->cantElem --;

    return TODO_OK;
}


int eliminarPrimeraAparicionAritPunt(Vector* vect, const int elem)
{
    int* pVec = vect->vec, pos=1;

    while(*pVec != elem && pVec < vect->vec + vect->cantElem)
    {
        pVec ++;
        pos ++;
    }

    if(pVec == vect->vec + vect->cantElem)
        return ERROR;

    desplazarPosVecALaIzqAritPunt(vect, pos);
    vect->cantElem --;

    return TODO_OK;
}


/*Ejercicio 26
Desarrollar una función que elimine todas las apariciones de un determinado elemento de un arreglo de enteros.*/

int eliminarTodasLasApariciones(Vector* vect, const int elem)
{
    int i=0;
    booleano elemEncontrado = FALSO;

    while(i < vect->cantElem)
    {
        if(vect->vec[i] == elem)
        {
            desplazarPosVecALaIzq(vect, i+1);
            vect->cantElem --;
            elemEncontrado = VERDADERO;
        }
        else
            i ++;
    }
    if(!elemEncontrado)
        return ERROR;

    return TODO_OK;
}


int eliminarTodasLasAparicionesAritPunt(Vector* vect, const int elem)
{
    booleano elemEncontrado = FALSO;
    int* pVec = vect->vec, pos = 0;

    while(pVec < vect->vec + vect->cantElem)
    {
        if(*pVec == elem)
        {
            desplazarPosVecALaIzqAritPunt(vect, pos);
            vect->cantElem --;
            elemEncontrado = VERDADERO;
        }
        else
        {
            pVec ++;
            pos ++;
        }
    }

    if(!elemEncontrado)
        return ERROR;

    return TODO_OK;
}

/////////////////////////////////////////FUNCIONES VARIAS CON VECTORES/////////////////////////////////////////

void mostrarVector(const Vector* vect)
{
    int i;

    printf("[  ");
    for(i=0; i<vect->cantElem; i++)
        printf("%d  ", vect->vec[i]);
    printf("]\n");
}


void mostrarVectorAritPunt(const Vector* vect)
{
    const int* pVec;

    printf("[  ");
    for(pVec = vect->vec; pVec < vect->vec + vect->cantElem; pVec++)
        printf("%d  ", *(pVec));

    printf("]\n");
}


void ordenaVectInsercionAscend(Vector* vect)
{
    int i, j, elemIns;

    for(i=1; i<vect->cantElem; i++)
    {
        elemIns = vect->vec[i];
        j = i - 1;
        while(elemIns<vect->vec[j] && j>=0)
        {
            vect->vec[j+1] = vect->vec[j];
            j--;
        }
        vect->vec[j+1] = elemIns;
    }
}


void crearVector(Vector *vect)
{
    vect->cantElem = 0;
}


int insertarEnVectorOrdSinDup(Vector* vect, const int elem)
{
    int i=0;

    if(vect->cantElem >= CAPACIDAD_VECTOR)                      //arreglo lleno
        return SIN_MEMORIA;

    while(elem < vect->vec[i] && i<vect->cantElem)
        i++;

    if(elem == vect->vec[i])                                    //ya ha sido insertado el elemento, no se admiten duplicados
        return DUPLICADO;

    desplazarPosVecALaDer(vect, i + 1);                         //desplazo el resto de los elementos para insertar ordenado
    vect->vec[i] = elem;
    vect->cantElem ++;                                          //aumento la cantidad de elementos del arreglo

    return TODO_OK;
}


int insertarEnVectorOrdConDup(Vector* vect, const int elem)
{
    int i=0;

    if(vect->cantElem > CAPACIDAD_VECTOR)
        return SIN_MEMORIA;

    while(vect->vec[i] < elem && i < vect->cantElem)
        i++;

    desplazarPosVecALaDer(vect, i+1);
    vect->vec[i] = elem;
    vect->cantElem ++;

    return TODO_OK;
}



int insertarEnVecAlInicioSinDup(Vector* vect, const int elem)
{
    int i = 0;

    if(vect->cantElem >= CAPACIDAD_VECTOR)
        return SIN_MEMORIA;

    while(vect->vec[i] != elem && i < vect->cantElem)
        i++;

    if(vect->vec[i] == elem)
        return DUPLICADO;

    desplazarPosVecALaDer(vect, 1);
    vect->vec[0] = elem;
    vect->cantElem ++;

    return TODO_OK;
}


int insertarEnVecAlInicioConDup(Vector* vect, const int elem)
{
    if(vect->cantElem >= CAPACIDAD_VECTOR)
        return SIN_MEMORIA;

    desplazarPosVecALaDer(vect, 1);
    vect->vec[0] = elem;
    vect->cantElem ++;

    return TODO_OK;
}


int insertarEnVecAlInicioConDupAritPunt(Vector* vect, const int elem)
{
    if(vect->cantElem >= CAPACIDAD_VECTOR)
        return SIN_MEMORIA;

    desplazarPosVecALaDerAritPunt(vect, 1);
    *(vect->vec) = elem;
    vect->cantElem ++;

    return TODO_OK;
}


int insertarEnVecAlFinalSinDup(Vector* vect, const int elem)
{
    int i=0;

    if(vect->cantElem >= CAPACIDAD_VECTOR)
        return SIN_MEMORIA;

    while(vect->vec[i] != elem && i < vect->cantElem)
        i ++;

    if(vect->vec[i] == elem)
        return DUPLICADO;

    vect->vec[vect->cantElem] = elem;
    vect->cantElem ++;

    return TODO_OK;
}



int insertarEnVecAlFinalSinDupAritPunt(Vector* vect, const int elem)
{
    int* pVec = vect->vec, pos=1;

    if(vect->cantElem >= CAPACIDAD_VECTOR)
        return SIN_MEMORIA;

    while(*pVec != elem && pVec < vect->vec + vect->cantElem)
    {
        pVec ++;
        pos ++;
    }

    if(*pVec == elem)
        return DUPLICADO;

    desplazarPosVecALaDerAritPunt(vect, pos);
    *(vect->vec + pos - 1) = elem;
    vect->cantElem ++;

    return TODO_OK;
}



int insertarEnVecAlFinalConDup(Vector* vect, const int elem)
{
    if(vect->cantElem >= CAPACIDAD_VECTOR)
        return SIN_MEMORIA;

    vect->vec[vect->cantElem] = elem;
    vect->cantElem ++;

    return TODO_OK;
}


int insertarEnVecAlFinalConDupAritPunt(Vector* vect, const int elem)
{
    if(vect->cantElem >= CAPACIDAD_VECTOR)
        return SIN_MEMORIA;

    *(vect->vec + vect->cantElem) = elem;
    vect->cantElem ++;

    return TODO_OK;
}


int buscarEnVecDesordenadoSinDup(const Vector* vect, const int elem)
{
    int i=0;

    while(vect->vec[i] != elem && i < vect->cantElem)
        i ++;

    return (vect->vec[i] == elem)? i+1: NO_ENCONTRADO;
}


int buscarEnVecDesordenadoConDup(const Vector* vect, Vector* vectPos, const int elem)
{
    int i=0, j=0;
    booleano elemEncontrado = FALSO;

    while(i < vect->cantElem)
    {
        if(vect->vec[i] == elem)
        {
            vectPos->vec[j] = i+1;
            vectPos->cantElem ++;
            j ++;
            elemEncontrado = VERDADERO;
        }
        i ++;
    }
    return (!elemEncontrado)? NO_ENCONTRADO: TODO_OK;
}


int buscarEnVecDesordenadoSinDupAritPunt(const Vector* vect, const int elem)
{
    const int* pVec = vect->vec;
    int pos=1;

    while(*pVec != elem && pVec < vect->vec + vect->cantElem)
    {
        pVec ++;
        pos ++;
    }

    return (*pVec==elem)? pos: NO_ENCONTRADO;
}


int buscarEnVecDesordenadoConDupAritPunt(const Vector* vect, Vector* vectPos, const int elem)
{
    const int* pVec = vect->vec;
    int* pVecPos = vectPos->vec;
    int pos=1;
    booleano elemEncontrado = FALSO;

    while(pVec < vect->vec + vect->cantElem)
    {
        if(*pVec == elem)
        {
            *(pVecPos) = pos;
            pVecPos ++;
            vectPos->cantElem ++;
            elemEncontrado = VERDADERO;
        }
        pos ++;
        pVec ++;
    }

    return (!elemEncontrado)? NO_ENCONTRADO: TODO_OK;
}



int buscarEnVecOrdenadoSinDup(const Vector* vect, const int elem)
{
    int i=0;

    while(vect->vec[i] <= elem && i < vect->cantElem)
        i ++;

    return (vect->vec[i] == elem)? i+1: NO_ENCONTRADO;
}


int buscarEnVecOrdenadoConDup(const Vector* vect, Vector* vectPos, const int elem)
{
    int i=0, j=0;
    booleano elemEncontrado = FALSO;

    while(vect->vec[i] <= elem && i < vect->cantElem)
    {
        if(vect->vec[i] == elem)
        {
            vectPos->vec[j] = i + 1;
            vectPos->cantElem ++;
            j ++;
            elemEncontrado = VERDADERO;
        }
        i ++;
    }
    return (!elemEncontrado)? NO_ENCONTRADO: TODO_OK;
}


int buscarEnVecOrdenadoSinDupAritPunt(const Vector* vect, const int elem)
{
    const int* pVec = vect->vec;
    int pos=1;

    while(*pVec <= elem && pVec < vect->vec + vect->cantElem)
    {
        pVec ++;
        pos ++;
    }

    return (*pVec == elem)? pos: NO_ENCONTRADO;
}


int buscarEnVecOrdenadoConDupAritPunt(const Vector* vect, Vector* vectPos, const int elem)
{
    const int* pVec = vect->vec;
    int* pVecPos = vectPos->vec;
    int pos = 1;
    booleano elemEncontrado = FALSO;

    while(*pVec <= elem && pVec < vect->vec + vect->cantElem)
    {
        if(*pVec == elem)
        {
            *pVecPos = pos;
            pVecPos ++;
            pos ++;
            elemEncontrado = VERDADERO;
        }
        pVec ++;
    }
    return (elemEncontrado)? TODO_OK: NO_ENCONTRADO;
}


int buscarMenor(const Vector* vect)
{
    int i, menor = vect->vec[0];

    if(vect->cantElem == 0)
        return ERROR;

    for(i=1; i<vect->cantElem; i++)
    {
        if(menor > vect->vec[i])
            menor = vect->vec[i];
    }

    return menor;
}


int buscarMenorAritPunt(const Vector* vect)
{
    const int* pVec = vect->vec;
    int menor = *pVec;

    if(vect->cantElem == 0)
        return ERROR;

    for(pVec = vect->vec + 1; pVec < vect->vec + vect->cantElem; pVec++)
    {
        if(menor > *pVec)
            menor = *pVec;
    }

    return menor;
}


int buscarMayor(const Vector* vect)
{
    int i, mayor = vect->vec[0];

    if(vect->cantElem == 0)
        return ERROR;

    for(i=1; i < vect->cantElem; i++)
    {
        if(mayor < vect->vec[i])
            mayor = vect->vec[i];
    }

    return mayor;
}


int buscarMayorAritPunt(const Vector* vect)
{
    const int* pVec = vect->vec;
    int mayor = *pVec;

    if(vect->cantElem == 0)
        return ERROR;

    for(pVec = vect->vec + 1 ; pVec < vect->vec + vect->cantElem; pVec++)
    {
        if(mayor < *pVec)
            mayor = *pVec;
    }

    return mayor;
}



/*booleano eliminarDeVecAlFinal(Vector *vector);    ///
booleano eliminarDeVecEnPosicion(Vector *vector, int elem, int pos);   ///
booleano eliminarDeVectorOrdPorValor(Vector *vector, int elem);    ///
booleano eliminarDeVectorDesordPorValor(Vector *vector, int elem); ///
booleano eliminarDeVectorDesordPorValorAritPunt(Vector *vector, int elem, int *Dirdesde);   ///
booleano eliminarDeVecAparicionesValorAritPunt(Vector *vector, int elem);    ///
void vaciarVector(Vector *vector);   ///
void ordenarVectorBurbujeoAscendente(Vector *vector);   ///
void ordenarVectorBurbujeoDescendente(Vector *Vector);  ///
void ordenarVectorSeleccionAscen(Vector *vector);   ///
void ordenarVectorSeleccionDescen(Vector *vector);  ///
void ordenarVectorInsercionDescen(Vector *vector);
*/
