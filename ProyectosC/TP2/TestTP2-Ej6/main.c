#include <stdio.h>
#include <stdlib.h>

#define redondea_a_entero(a)        ( ((a) - (int)(a) < 0.5)? (int)(a): (int)(a) + 1 )
#define minimo(a,b)                 ( ((a) < (b))? (a): (b) )
#define swap_int(a,b)               ({ int aux = (a); \
                                      (a) = (b); \
                                      (b) = aux; })


int menorEntero(const int num1, const int num2);
void interCambiaEnteros(int* num1, int* num2);

int main()
{
    /*Ejercicio 6
    Escriba una macro que redondee un número real al entero más cercano.
    Escriba una función que devuelva el menor entre dos enteros que recibe por argumento.
    Escriba una macro que cumpla con el mismo cometido.
    Escriba una función que intercambie dos enteros que recibe por puntero.
    Escriba una macro multilínea que cumpla con el mismo cometido.*/

    float num1;
    int num1Ent, num2Ent, menor;

    puts("Ejercicio 6");
    printf("Ingrese un numero real: ");
    fflush(stdin);
    scanf("%f", &num1);
    fflush(stdin);

    num1Ent = redondea_a_entero(num1);
    printf("El numero real %f redondeado a entero usando una macro es %d\n\n", num1, num1Ent);

    printf("Ingrese otro numero entero: ");
    scanf("%d", &num2Ent);
    fflush(stdin);
    menor = menorEntero(num1Ent, num2Ent);
    printf("El menor entre %d y %d utilizando una funcion es %d\n\n", num1Ent, num2Ent, menor);

    printf("Ingrese otro numero entero: ");
    scanf("%d", &num1Ent);
    fflush(stdin);
    menor = minimo(num1Ent, num2Ent);
    printf("El menor entre %d y %d utilizando una macro es %d\n\n", num1Ent, num2Ent, menor);

    printf("Enteros antes del intercambio: 1) %d      2) %d\n", num1Ent, num2Ent);
    interCambiaEnteros(&num1Ent, &num2Ent);
    printf("Luego del intercambio usando una funcion: 1) %d      2) %d\n\n", num1Ent, num2Ent);
    swap_int(num1Ent, num2Ent);
    printf("Vuelvo a intercambiarlos esta vez usando una macro multilea: 1) %d      2) %d\n\n", num1Ent, num2Ent);


    return 0;
}


int menorEntero(const int num1, const int num2)
{
    return(num1 < num2)? num1: num2;
}

void interCambiaEnteros(int* num1, int* num2)
{
    int aux;

    aux = *num1;
    *num1 = *num2;
    *num2 = aux;
}
