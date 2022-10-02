#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <math.h>
#include "../TP1-FuncionesMatematicas/Matematica.h"

double potenciaDouble (const void* elem, const void* pot);
int validaMayorAInt(const int inf);
double potenciaDouble1 (const void* elem, const void* pot);

int main(int argc, char* argv[])
{
    int factorial, num, cociente, resto;
    double tol;
    float nume;

    setlocale(LC_ALL, "spanish");

    puts("Ejercicio 1");
    factorial = atoi(argv[1]);
    printf("El factorial de %d usando iteración es %.0f\n", factorial, factorialIterado(factorial));
    printf("El factorial de %d usando recursividad es %.0f\n\n", factorial, factorialRecursiva(factorial));


    puts("Ejercicio 2");
    printf("El numero combinatorio de %d y %d es %.0f\n\n", atoi(argv[1]), atoi(argv[2]), numeroCombinatorio(atoi(argv[1]), atoi(argv[2])));

    tol = atof(argv[3]);
    puts("Ejercicio 3");
    printf("Usando la función exp() de math.h: e^%d = %f\n", atoi(argv[1]), exp(atoi(argv[1])));
    printf("Usando la formula dada con iteración con tolerancia de error menor a %.5f: e^%d =  %f\n", tol, atoi(argv[1]), calculaPotenciaDeEConTOL(atoi(argv[1]), tol, potenciaDouble));
    printf("Usando la formula dada con recursividad con tolerancia de error menor a %.5f: e^%d = %f\n\n", tol, atoi(argv[1]), potenciaDeEConTOLRecurs(atoi(argv[1]), tol, 1, potenciaDouble));

    puts("Ejercicio 4");
    printf("Usando la función sqrt() de math.h: raiz cuadrada de %d = %f\n", atoi(argv[4]), sqrt(atoi(argv[4])));
    printf("Usando la función dada con iteración y tolerancia de %f: raiz cuadrada de %d = %f\n", tol, atoi(argv[4]), raizCuadradaConTolItera(atoi(argv[4]), tol));
    printf("Usando la función dada con recursividad y tolerancia de %f: raiz cuadrada de %d = %f\n\n", tol, atoi(argv[4]), raizCuadradaConTolRecur((atoi(argv[4])), tol, 1));

    puts("Ejercicio 5");
    printf("Ingrese el número entero positivo que será buscado en la serie de Fibonacci: ");
    num = validaMayorAInt(0);
    (estaEnLaSerieFibonacciItera(num))? printf("\nUsando iteración puedo afirmar que el número %d se encuentra en la serie Fibonacci\n", num): printf("\nUsando iteración puedo afirmar que el número %d no se encuentra en la serie Fibonacci\n\n", num);
    (estaEnLaSerieFibonacciRecur(num, 1, 1))? printf("\nUsando iteración puedo afirmar que el número %d se encuentra en la serie Fibonacci\n\n", num): printf("\nUsando iteración puedo afirmar que el número %d no se encuentra en la serie Fibonacci\n\n", num);

    puts("Ejercicio 6");
    printf("Usando la función sin() de math.h: seno(%f) = %f\n", atof(argv[5]), sin(atof(argv[5])));
    printf("Usando la función dada con iteración y tolerancia de %f: seno(%f) = %f\n", tol, atof(argv[5]), senoConTolItera( atof(argv[5]) , tol, potenciaDouble1));
    printf("Usando la función dada con recursividad y tolerancia de %f: seno(%f) = %f\n\n", tol, atof(argv[5]), senoConTolRecur(atof(argv[5]), tol, 3, 1, potenciaDouble1));

    puts("Ejercicio 7");
    printf("Ingrese un número natural y se indicará si es Perfecto, Deficiente o Abundante: ");
    num = validaMayorAInt(0);
    puts("Usando iteración: ");
    if(perfectoDeficienteOAbundanteIter(num)==0)
        printf("El número %d es Deficiente\n", num);
    else
    {
        if(perfectoDeficienteOAbundanteIter(num)==1)
            printf("El número %d es Perfecto\n", num);
        else
            printf("El número %d es Abundante\n", num);
    }
    puts("Usando recursividad: ");
    if(perfectoDeficienteOAbundanteRecur(num)==0)
        printf("El número %d es Deficiente\n\n", num);
    else
    {
        if(perfectoDeficienteOAbundanteRecur(num)==1)
            printf("El número %d es Perfecto\n\n", num);
        else
            printf("El número %d es Abundante\n\n", num);
    }


    puts("Ejercicio 8");
    printf("El resultado de la multiplicación de %d por %d usando sumas sucesivas con iteración es %ld\n", atoi(argv[1]), atoi(argv[2]), multPorSumasSucesivasIter(atoi(argv[1]), atoi(argv[2])));
    printf("El resultado de la multiplicación de %d por %d usando sumas sucesivas con recursividad es %ld\n\n", atoi(argv[1]), atoi(argv[2]), multPorSumasSucesivasRecur(atoi(argv[1]), atoi(argv[2])));

    puts("Ejercicio 9");
    if(cocienteYRestoNumNat(atoi(argv[1]), atoi(argv[2]), &cociente, &resto)==0)
        printf("El cociente y el resto de la división entre %d y %d son respectivamente: %d y %d\n\n", atoi(argv[1]), atoi(argv[2]), cociente, resto);
    else
        printf("No se puede dividir por cero\n\n");

    puts("Ejercicio 10");
    printf("Ingrese un número natural y se realizará la suma de esos primeros N números naturales: ");
    num = validaMayorAInt(0);
    printf("La suma de los primeros %d números naturales usando iteración es %d\n", num, sumaDeNNumNatItera(num));
    printf("La suma de los primeros %d números naturales usando recursividad es %d\n\n", num, sumaDeNNumNatRecur(num));

    puts("Ejercicio 11");
    printf("Ingrese un número natural y se realizará la suma de esos primeros N números pares naturales: ");
    num = validaMayorAInt(0);
    printf("La suma de los primeros %d números pares naturales usando iteración es %d\n", num, sumaDeNNumNatParesItera(num));
    printf("La suma de los primeros %d números naturales usando recursividad es %d\n\n", num, sumaDeNNumNatParesRecur(num, 2));


    puts("Ejercicio 12");
    printf("Ingrese un número natural y se realizará la suma de los números pares menores al proporcionado: ");
    num = validaMayorAInt(0);
    printf("La suma de los números pares menores a %d usando iteración es %d\n", num, sumaDeNParesMenoresANItera(num));
    printf("La suma de los números pares menores a %d usando recursividad es %d\n\n", num, sumaDeNParesMenoresANRecur(num));


    puts("Ejercicio 13");
    printf("Ingrese un número natural para verificar si el mismo es primo: ");
    num = validaMayorAInt(0);
    if(esPrimo(num))
        printf("El número %d no es primo.\n\n", num);
    else
        printf("El número %d es primo.\n\n", num);


    puts("Ejercicio 20");
    printf("La multiplicación rusa entre %d y %d usando iteración es %ld\n", atoi(argv[1]), atoi(argv[2]), multRusaItera(atoi(argv[1]), atoi(argv[2])));
    printf("La multiplicación rusa entre %d y %d usando recursividad es %ld\n\n", atoi(argv[1]), atoi(argv[2]), multRusaRecur(atoi(argv[1]), atoi(argv[2])));


    puts("Ejercicio 21");
    printf("Ingrese un número real para obtener su parte entera: ");
    fflush(stdin);
    scanf("%f", &nume);
    fflush(stdin);
    printf("La parte entera de %f es %d\n\n", nume, parteEnteraDeNumReal(nume));


    return 0;
}

double potenciaDouble (const void* elem, const void* pot)
{
    int i;
    double res = 1;

    if(*(int*)pot==0)
        return res;
    else
    {
        for(i=0; i<*(int*)pot; i++)
            res *= *(int*)elem;
    }

    return res;
}

double potenciaDouble1 (const void* elem, const void* pot)
{
    int i;
    double res = 1;

    if(*(int*)pot==0)
        return res;
    else
    {
        for(i=0; i<*(int*)pot; i++)
            res *= *(double*)elem;
    }

    return res;
}

int validaMayorAInt(const int inf)
{
    int num;

    do
    {
        fflush(stdin);
        scanf("%d", &num);
        fflush(stdin);

        if(num<=inf)
            printf("El número ingresado no es válido. El mismo debe ser mayor a %d. Vuelva a ingresar: ", inf);
    } while(num<=inf);

    return num;
}
