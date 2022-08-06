#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../TP1-Vectores/Vectores.h"

int validaIntMayA(const int inf);


int main(int argc, char* argv[])
{
    Vector vect;
    int i, pos, num;

    crearVector(&vect);
    for(i=0; i<CAPACIDAD_VECTOR - 5; i++)
       vect.vec[i] = i + 1;

    vect.cantElem = i;

    puts("Ejercicio 22");
    printf("Proporcione la posicion en la que se ingresara el numero %d (mayor a 0): ", atoi(argv[1]));
    pos = validaIntMayA(0);
    while(pos>CAPACIDAD_VECTOR)
    {
        printf("La posicion porporcionada es mayor a la cantidad de elementos del vector. Vuelva a intentarlo: ");
        pos = validaIntMayA(0);
    }

    insertarVectorEnPosicion(&vect, pos, atoi(argv[1]));
    puts("Elemento insertado en vector usando subindices: ");
    mostrarVector(&vect);
    printf("Proporcione la posicion en la que se ingresara el numero %d (mayor a 0): ", atoi(argv[1]));
    pos = validaIntMayA(0);
    while(pos>CAPACIDAD_VECTOR)
    {
        printf("La posicion porporcionada es mayor a la cantidad de elementos del vector. Vuelva a intentarlo: ");
        pos = validaIntMayA(0);
    }
    insertarVectorEnPosicionAritPunt(&vect, pos, atoi(argv[1]));
    puts("Elemento insertado en vector usando aritmetica de punteros: ");
    mostrarVectorAritPunt(&vect);


    puts("Ejercicio 23");
    ordenaVectInsercionAscend(&vect);
    puts("Vector ordenado usando insercion: ");
    mostrarVector(&vect);
    printf("Ingrese un numero entero que sera insertado en orden en el arreglo de enteros usando subindices: ");
    fflush(stdin);
    scanf("%d", &num);
    fflush(stdin);
    insertarElemEnVectOrdenado(&vect, num);
    puts("Elemento insertado en orden usando subindices: ");
    mostrarVector(&vect);
    printf("Ingrese un numero entero que sera insertado en orden en el arreglo de enteros usando aritmetica de punteros: ");
    fflush(stdin);
    scanf("%d", &num);
    fflush(stdin);
    insertarElemEnVectOrdenado(&vect, num);
    puts("Elemento insertado en orden usando aritmetica de punteros: ");
    mostrarVector(&vect);


    puts("Ejercicio 24");
    printf("Ingrese la posicion del elemento que se eliminara del arreglo de enteros usando subindices: ");
    pos = validaIntMayA(0);
    num = eliminarElemEnPos(&vect, pos);
    if(num == ERROR)
        printf("La posicion porporcionada es mayor a la cantidad de elementos del vector.\n\n");
    else
        printf("El elemento eliminado es %d\n\n", num);
    mostrarVector(&vect);
    printf("Ingrese la posicion del elemento que se eliminara del arreglo de enteros usando aritmetica de punteros: ");
    pos = validaIntMayA(0);
    num = eliminarElemEnPosAritPunt(&vect, pos);
    if(num == ERROR)
        printf("La posicion porporcionada es mayor a la cantidad de elementos del vector.\n\n");
    else
        printf("El elemento eliminado es %d\n\n", num);
    mostrarVectorAritPunt(&vect);


    puts("\nEjercicio 25");
    printf("Ingrese un numero entero, el mismo se buscara en el arreglo de enteros y se eliminara su primera aparicion utilizando subindices: ");
    fflush(stdin);
    scanf("%d", &num);
    fflush(stdin);
    if(eliminarPrimeraAparicion(&vect, num) != ERROR)
    {
        printf("Se ha eliminado el elemento.\n");
        mostrarVector(&vect);
    }
    else
        printf("El numero ingresado no se encuentra en el arreglo de enteros.\n");
    printf("Ingrese un numero entero, el mismo se buscara en el arreglo de enteros y se eliminara su primera aparicion utilizando aritmetica de punteros: ");
    fflush(stdin);
    scanf("%d", &num);
    fflush(stdin);
    if(eliminarPrimeraAparicionAritPunt(&vect, num) != ERROR)
    {
        printf("Se ha eliminado el elemento.\n");
        mostrarVectorAritPunt(&vect);
    }
    else
        printf("El numero ingresado no se encuentra en el arreglo de enteros.\n");


    puts("\nEjercicio 26");
    printf("Ingrese un numero entero, el mismo se buscara en el arreglo de enteros y se eliminaran todas sus apariciones utilizando subindices: ");
    fflush(stdin);
    scanf("%d", &num);
    fflush(stdin);
    if(eliminarTodasLasApariciones(&vect, num) != ERROR)
    {
        printf("Se ha eliminado el elemento.\n");
        mostrarVector(&vect);
    }
    else
        printf("El numero ingresado no se encuentra en el arreglo de enteros.\n");
    printf("Ingrese un numero entero, el mismo se buscara en el arreglo de enteros y se eliminaran todas sus apariciones utilizando aritmetica de punteros: ");
    fflush(stdin);
    scanf("%d", &num);
    fflush(stdin);
    if(eliminarTodasLasAparicionesAritPunt(&vect, num) != ERROR)
    {
        printf("Se ha eliminado el elemento.\n");
        mostrarVectorAritPunt(&vect);
    }
    else
        printf("El numero ingresado no se encuentra en el arreglo de enteros.\n");


    return 0;
}


int validaIntMayA(const int inf)
{
    int num;

    do
    {
        fflush(stdin);
        scanf("%d", &num);
        fflush(stdin);
        if(num<=inf)
            printf("El numero ingresado no es valido. El mismo debe ser mayor a %d. Vuelva a ingresar: ", inf);
    } while(num<=inf);

    return num;
}
