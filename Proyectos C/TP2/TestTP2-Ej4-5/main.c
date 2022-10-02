#include <stdio.h>
#include <stdlib.h>

#include <string.h>

int main(int argc, char* argv[])
{
    int num1, num2, suma;
    float num3, num4, sumaF;
    long num5, num6, sumaL;
    char cadena1[100], cadena2[100], total[200];


    /*Ejercicio 4
    Existen funciones de conversión (atoi, itoa, atol, etc., declaradas en la biblioteca stdlib.h), que usted debería conocer y recordar.
    Escriba, compile y ejecute un programa en que haga uso de tales funciones de conversión.*/
    puts("Ejercicio 4");
    puts("A continuacion utilizare varios argumentos a main para probar funciones de la biblioteca stdlib.h: ");
    printf("Argumento 1: ");
    printf("%s\n", argv[1]);
    printf("Argumento 2: ");
    printf("%s\n", argv[2]);

    printf("\nSe utilizara la funcion atoi para transformar ambos argumentos en int y se realizara una suma: \n");
    num1 = atoi(argv[1]);
    num2 = atoi(argv[2]);
    suma = num1 + num2;
    printf("La suma entre %0d y %0d es %0d\n", num1, num2, suma);

    printf("\nSe utilizara la funcion atol para transformar ambos argumentos en long int y se realizara una suma: \n");
    num5 = atol(argv[1]);
    num6 = atol(argv[2]);
    sumaL = num5 + num6;
    printf("La suma entre %ld y %ld es %ld\n", num5, num6, sumaL);

    printf("\nSe utilizara la funcion atof para transformar ambos argumentos en float y se realizara una suma: \n");
    num3 = atof(argv[1]);
    num4 = atof(argv[2]);
    sumaF = num3 + num4;
    printf("La suma entre %f y %f es %f\n", num3, num4, sumaF);

    printf("\nSe utilizara la funcion abs para trasformar el numero entero generado por atoi a su valor absoluto: \n");
    printf("Numero entero: %d     Valor absoluto: %d\n", num2, abs(num2));

    printf("\nSe utilizara la funcion labs para trasformar el long generado por atol a su valor absoluto: \n");
    printf("Numero entero: %ld     Valor absoluto: %ld\n", num6, labs(num6));

    puts("\nUsare la funcion system para ver el la informacion de mi equipo, el directorio de archivos en la carpeta del proyecto y luego abrire el txt: ");
    system("SYSTEMINFO");
    system("tree");
    printf("\n");
    system("type VectorATxt.txt");
    printf("\n\n");

    /*Ejercicio 5
    En la biblioteca stdio.h hay dos funciones que permiten obtener idénticos (o similares) resultados, se trata de sscanf y sprintf.
    Escriba, compile y ejecute un programa en que utilice estas funciones.*/
    puts("Ejercicio 5");
    printf("Ingrese la secuencia de caracteres para la primer cadena: ");
    gets(cadena1);
    printf("Ingrese la secuencia de caracteres para la segunda cadena: ");
    gets(cadena2);

    printf("Se usara la funcion sscanf para copiar la primer cadena ENTERA a la cadena total, con la expresion regular [^\\0] :\n");
    sscanf(cadena1, "%[^\\0]", total);
    printf("%s\n", total);
    printf("Ahora se usara nuevamente la funcion sscanf para volver a copiar la primer cadena en la cadena total sin la expresion regular, observar que corta en el primer espacio leido: \n");
    sscanf(cadena1, "%s", total);
    printf("%s\n", total);
    printf("Por ultimo copiare la cadena 2 en la cadena total usando sprintf:\n");
    sprintf(total, "%s", cadena2);
    printf("%s", total);




    return 0;
}
