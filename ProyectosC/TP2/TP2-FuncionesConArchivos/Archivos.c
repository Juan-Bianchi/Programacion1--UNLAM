#include "Archivos.h"

/*Ejercicio 1
Escriba una función que permita desplegar un menú de opciones, devolviendo una opción válida.
Escriba una función que reciba por argumento la dirección de comienzo de un array de float y la cantidad máxima de elementos a ingresar (no
utilice subíndices). La función permitirá terminar el ingreso con una condición fijada por el alumno y devolverá la cantidad de elementos
ingresados (puede ser cero).
Escriba una función que permita buscar el mínimo elemento de un array de float.
Escriba una función que determine el promedio de los elementos que se encuentran en las posiciones pares de un array de float.
Escriba una función que muestre los elementos de un array de float en orden inverso*/
///Escriba una función que almacene en un archivo de texto los elementos de un array de float, a razón de un flotante por línea de texto.
/*Haciendo uso de las funciones anteriores, escriba un programa que al comenzar su ejecución permita el ingreso para un array de float, luego de
lo cual muestre un menú de opciones para:
1- Buscar el mínimo elemento,
2- Calcular el promedio de los valores de las posiciones pares, 3- Mostrarlo en orden inverso,
4- Salir.
y que antes de terminar la ejecución del programa grabe los elementos del array en un archivo de texto.
Consulte de qué modo puede hacer que el programa trabaje con otros tipos de datos (double, long double, int, unsigned, etc.), con mínimas
modificaciones.*/

void vectFloatAArchTxt(FILE* arch, float* vect, const int cantElem)
{
    float* pVec;

    for(pVec=vect; pVec < vect + cantElem; pVec++)
        fprintf(arch, "%.2f\n", *pVec);
}



/*Ejercicio 7
Escriba una función booleana que permita abrir un archivo, mostrando o no un mensaje de error por stdout, según el valor de un argumento.
Escriba una macro multilínea que cumpla con el mismo cometido.*/

booleano archivoAbiertoCorrectamente(FILE* arch, char* nombre, char* modoApert)
{
    if(arch == NULL)
    {
        printf("El archivo '%s' no ha podido abrirse en el modo '%s'. Verifique el error.\n", nombre, modoApert);
        return falso;
    }

    return verdadero;

}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

