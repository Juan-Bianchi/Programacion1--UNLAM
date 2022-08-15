#include "Vectores.h"



/*Ejercicio 1
Escriba una función que permita desplegar un menú de opciones, devolviendo una opción válida.
Escriba una función que reciba por argumento la dirección de comienzo de un array de float y la cantidad máxima de elementos a ingresar (no
utilice subíndices). La función permitirá terminar el ingreso con una condición fijada por el alumno y devolverá la cantidad de elementos
ingresados (puede ser cero).
Escriba una función que permita buscar el mínimo elemento de un array de float.
Escriba una función que determine el promedio de los elementos que se encuentran en las posiciones pares de un array de float.
Escriba una función que muestre los elementos de un array de float en orden inverso
Escriba una función que almacene en un archivo de texto los elementos de un array de float, a razón de un flotante por línea de texto.
Haciendo uso de las funciones anteriores, escriba un programa que al comenzar su ejecución permita el ingreso para un array de float, luego de
lo cual muestre un menú de opciones para:
1- Buscar el mínimo elemento,
2- Calcular el promedio de los valores de las posiciones pares, 3- Mostrarlo en orden inverso,
4- Salir.
y que antes de terminar la ejecución del programa grabe los elementos del array en un archivo de texto.
Consulte de qué modo puede hacer que el programa trabaje con otros tipos de datos (double, long double, int, unsigned, etc.), con mínimas
modificaciones.*/

int cargaVectorFloat(float* vect, const int capacidad, const float condFin)
{
    int cant = 0;
    float* pVec = vect;

    printf("Ingrese un numero real (%.2f para terminar): ", condFin);
    fflush(stdin);
    scanf("%f", pVec);
    fflush(stdin);

    while(pVec < vect + capacidad  && *pVec != condFin)
    {
        pVec ++;
        cant ++;

        printf("Ingrese un numero real(%.2f para terminar): ", condFin);
        scanf("%f", pVec);
        fflush(stdin);
    }

    return cant;
}



int buscarMinimoVectFloat(float* vect, float* minimo, const int cantElem)
{
    float* pVec = vect + 1;
    int pos = -1;

    if(cantElem)
    {
        *minimo = *vect;
        pos = 0;

        while(pVec < vect + cantElem)
        {
            if(*pVec < *minimo)
            {
                *minimo = *pVec;
                pos = pVec - vect;
            }
            pVec ++;
        }
    }
    return pos;
}



float promedPosicParesVectFloat(const float* vect, const int cantElem)
{
    float prom = 0;
    double suma = 0;
    const float* pVec = vect;
    int contPar = 0;

    while(pVec++ < vect + cantElem - 1)
        if( (pVec - vect) % 2 == 0 )
        {
            suma += *pVec;
            contPar ++;
        }

    if(contPar)
        prom = suma / contPar;

    return prom;
}



void mostrarVectFloat(float* vect, const int cantElem)
{
    float* pVec;

    printf("[");
    for(pVec = vect; pVec < vect + cantElem; pVec++)
        printf("%8.2f", *pVec);

    printf("    ]\n");
}



void mostrarVectFloatOrdenInverso(float* vect, const int cantElem)
{
    float* pVec;

    printf("[");
    for(pVec = vect + cantElem - 1; pVec >= vect ; pVec--)
        printf("%8.2f", *pVec);

    printf("     ]\n");
}



/*Ejercicio 2
Escriba una función que devuelva en qué dirección de memoria se encuentra un elemento dentro de un array. Si el elemento no se encuentra, debe
devolver NULL.*/

void* buscarElemEnVect(const void* vect, const void* elem, const int cantElem, size_t tamElem, Cmp cmp)
{
    const void* pVec = vect, * fin = vect + (cantElem-1) * tamElem;

    while(cmp(pVec, elem) != 0  &&  pVec <= fin)
        pVec += tamElem;

    return(cmp(pVec, elem) == 0)? (void*)pVec: NULL;
}

/*Ejercicio 3
Escriba una función que permita el ingreso de una cantidad variable de elementos en un array de enteros int.
Escriba una función que calcule la suma de todos los elementos almacenados en un array de enteros, y su promedio. El promedio (float) debe ser
devuelto por la función, y la suma debe ser también devuelta mediante un argumento extra (puntero a long) que recibe la función.
Escriba otra versión de la función anterior, pero devolviendo ambos valores calculados en una variable que responda a una estructura compuesta
de un miembro long y un miembro float.
a- escriba un main que utilice la primera y segunda función, y
b- otro main que utilice la primera y la tercera
En ambos casos, la suma y el promedio deben ser mostrados en la función
¿Tiene claro que la primera alternativa es mejor que la segunda porque no es necesario el uso de una estructura? En ciertos casos puede ser
mejor la segunda alternativa.*/

int cargaVectorInt(int* vect, const int capacidad, const int condFin)
{
    int* pVec = vect;
    int cant = 0;

    printf("Ingrese un numero entero (%d para terminar): ", condFin);
    fflush(stdin);
    scanf("%d", pVec);
    fflush(stdin);
    while(*pVec != condFin && pVec < vect + capacidad)
    {

        pVec++;
        cant++;
        printf("Ingrese un numero entero (%d para terminar): ", condFin);
        scanf("%d", pVec);
        fflush(stdin);
    }

    return cant;
}


float promedVectInt(int* vect, long* suma, const int cantElem)
{
    float prom = 0;
    int* pVec;

    *suma = 0;

    if(cantElem)
    {
        for(pVec = vect; pVec < vect + cantElem; pVec++)
        {
            *suma += *pVec;
        }
        prom = *suma / (float)cantElem;
    }

    printf("La suma de los elementos del vector es: %ld\nEl promedio de los elementos del vector es: %.2f\n", *suma, prom);

    return prom;
}



void promedEnEstructVectInt(int* vect, tProm* prom, const int cantElem)
{
    int* pVec;

    prom->prom = 0;
    prom->suma = 0;

    if(cantElem)
    {
        for(pVec = vect; pVec < vect + cantElem; pVec++)
        {
            prom->suma += *pVec;
        }
        prom->prom = prom->suma / (float)cantElem;
    }

    printf("La suma de los elementos del vector es: %ld\nEl promedio de los elementos del vector es: %.2f\n", prom->suma, prom->prom);
}



void mostrarVectInt(int* vect, const int cantElem)
{
    int* pVec;

    printf("[");
    for(pVec = vect; pVec < vect + cantElem; pVec++)
        printf("%6d", *pVec);

    printf("      ]\n");
}
