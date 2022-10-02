#include "Archivos.h"

/*Ejercicio 1
Escriba una funci�n que permita desplegar un men� de opciones, devolviendo una opci�n v�lida.
Escriba una funci�n que reciba por argumento la direcci�n de comienzo de un array de float y la cantidad m�xima de elementos a ingresar (no
utilice sub�ndices). La funci�n permitir� terminar el ingreso con una condici�n fijada por el alumno y devolver� la cantidad de elementos
ingresados (puede ser cero).
Escriba una funci�n que permita buscar el m�nimo elemento de un array de float.
Escriba una funci�n que determine el promedio de los elementos que se encuentran en las posiciones pares de un array de float.
Escriba una funci�n que muestre los elementos de un array de float en orden inverso*/
///Escriba una funci�n que almacene en un archivo de texto los elementos de un array de float, a raz�n de un flotante por l�nea de texto.
/*Haciendo uso de las funciones anteriores, escriba un programa que al comenzar su ejecuci�n permita el ingreso para un array de float, luego de
lo cual muestre un men� de opciones para:
1- Buscar el m�nimo elemento,
2- Calcular el promedio de los valores de las posiciones pares, 3- Mostrarlo en orden inverso,
4- Salir.
y que antes de terminar la ejecuci�n del programa grabe los elementos del array en un archivo de texto.
Consulte de qu� modo puede hacer que el programa trabaje con otros tipos de datos (double, long double, int, unsigned, etc.), con m�nimas
modificaciones.*/

void vectFloatAArchTxt(FILE* arch, float* vect, const int cantElem)
{
    float* pVec;

    for(pVec=vect; pVec < vect + cantElem; pVec++)
        fprintf(arch, "%.2f\n", *pVec);
}



/*Ejercicio 7
Escriba una funci�n booleana que permita abrir un archivo, mostrando o no un mensaje de error por stdout, seg�n el valor de un argumento.
Escriba una macro multil�nea que cumpla con el mismo cometido.*/

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

