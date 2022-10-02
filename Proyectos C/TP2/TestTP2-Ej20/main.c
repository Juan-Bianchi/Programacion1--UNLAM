/*Ejercicio 20
Escriba una función recursiva que:
- calcule el factorial de un número entero.
- muestre el contenido de un array de char.
- ídem anterior, mostrando en orden inverso.
- ídem anterior, devolviendo la suma de los caracteres que representan dígitos.
- muestre el contenido de un array de enteros en orden inverso, devolviendo la suma de todos los elementos.
- ídem anterior, devolviendo la suma de los pares.
- Ídem anterior, devolviendo la suma de los que están en posiciones pares. Escriba versiones recursivas de las funciones de biblioteca <strlen>, <str-
chr> y <strrchr>.*/

#include "Recursivas.h"

int main()
{
    int num, tam;
    double fact;
    char linea[200], * pCaract, caract;
    long int suma;
    int vec[20], i = 0;


    printf("Ingrese el numero del cual calculara el factorial: ");
    fflush(stdin);
    scanf("%d", &num);
    fflush(stdin);
    fact = factorial(num);
    printf("El factorial de %d calculado con una funcion recursiva es %.0lf\n\n", num, fact);


    printf("Ingrese una cadena de caracteres: ");
    gets(linea);
    puts("\n\nSe mostra la cadena ingresada usando una funcion recursiva: ");
    mostrarArray(linea);

    puts("\n\nAhora se mostrara el array en orden inverso usando una funcion recursiva: ");
    mostrarArrayEnOrdenInverso(linea, strrchr(linea, '\0'));

    puts("\n\nA continuacion se sumaran todos los caracteres que representan numeros usando una funcion recursiva: ");
    suma = sumaNumEnCadena(linea);
    printf("La suma es %ld\n\n", suma);

    puts("A continuacion ingrese numeros enteros para un array que luego sera usado, como maximo pueden ser ingresado 20 elementos: ");
    printf("Ingrese un numero entero (-1 para terminar): ");
    fflush(stdin);
    scanf("%d", &num);
    fflush(stdin);
    while(num != -1 && i < 20)
    {
        vec[i] = num;
        i ++;
        printf("Ingrese un numero entero (-1 para terminar): ");
        fflush(stdin);
        scanf("%d", &num);
        fflush(stdin);
    }

    puts("\n\nA continuacion se mostrara la suma del array ingresado en orden inverso y se presentara el total de la suma utilizando una funcion recursiva: ");
    suma = imprimeInversoYSumaArrayInt(vec, vec+i-1);
    printf(" = %ld\n\n", suma);


    puts("Se mostrara la suma en orden inverso de los numeros pares del vector utilizando una funcion recursiva: ");
    suma = imprimeInversoYSumaParesDeArrayInt(vec, vec+i-1);
    printf(" = %ld\n\n", suma);


    puts("Ahora se mostraran en orden inverso y sumaran los numeros que estan en POSICIONES pares: ");
    suma = imprimeInversoYSumaPosParesDeArrayInt(vec, vec+i-1);
    printf(" = %ld\n\n", suma);


    puts("A continuacion se implementara una funcion simil a strlen con una version recursiva de la cadena ingresada en un principio: ");
    tam = strlenRecursiva(linea);
    mostrarArray(linea);
    printf("El tamanio de la cadena ingresada es %d\n\n", tam);


    puts("A continuacion se implementara una funcion simil a strchr con una version recursiva de la cadena ingresada en un principio: ");
    printf("Ingrese el caracter que sera buscado en la cadena: ");
    fflush(stdin);
    scanf("%c", &caract);
    fflush(stdin);
    pCaract = strchrRecursiva(linea, caract);
    if(pCaract)
        printf("El caracter %c se encuentra en la posicion %ld\n", *pCaract, (long int) (pCaract-linea+1));
    else
        printf("El caracter '%c' no ha sido encontrado.\n", caract);


    puts("A continuacion se implementara una funcion simil a strrchr con una version recursiva de la cadena ingresada en un principio: ");
    printf("Ingrese el caracter que sera buscado en la cadena: ");
    fflush(stdin);
    scanf("%c", &caract);
    fflush(stdin);
    pCaract = strrchrRecursiva(linea, linea + strlenRecursiva(linea), caract);
    if(pCaract)
        printf("El caracter %c se encuentra en la posicion %ld\n", *pCaract, (long int) (pCaract-linea+1));
    else
        printf("El caracter '%c' no ha sido encontrado.\n", caract);

    return 0;
}
