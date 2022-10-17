#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//#define TDA_PILA_IMPLEMENTACION_ESTATICA
#include "../TDAPila/TDAPila.h"


bool apilarCeros(Pila* pila, int cantCeros);
bool apilarNumero(Pila* pila, const char* num);
void desapilarNumero(Pila* pila, char* suma);
char* sumarNumeros(const char* numero1, const char* numero2);



// Sumar 9947389 57267

int main(int argc, char* argv[])
{

    system("chcp 1252 > 0");

    if(argc != 3)
    {
        printf("Error: debe ingresar dos números enteros como argumentos.\n");
        return 1;
    }

    char* suma = sumarNumeros(argv[1], argv[2]);

    printf("La suma entre %s y %s es : %s\n", argv[1], argv[2], suma);

    free(suma);


    return 0;
}


char* sumarNumeros(const char* num1, const char* num2)
{
    Pila pila1, pila2, pilaSuma;
    int difTam, cantCeros, dig1, dig2, digSum, digAc = 0, tamSuma, tamNum1, tamNum2;
    char dig1C, dig2C, digSumC;
    char* suma;

    crearPila(&pila1);
    crearPila(&pila2);
    crearPila(&pilaSuma);


    tamNum1 = strlen(num1);
    tamNum2 = strlen(num2);
    difTam = tamNum1 - tamNum2;
    tamSuma = tamNum1 - tamNum2>0? tamNum1: tamNum2;
    cantCeros = abs(difTam);

    if(difTam<0)
        apilarCeros(&pila1, cantCeros);
    if(difTam>0)
        apilarCeros(&pila2, cantCeros);

    apilarNumero(&pila1, num1);
    apilarNumero(&pila2, num2);

    while(!pilaVacia(&pila1))
    {
        if(!desapilar(&pila1, &dig1C, sizeof(char)))
            puts("No desapilo");

        desapilar(&pila2, &dig2C, sizeof(char));

        dig1 = dig1C - '0';
        dig2 = dig2C - '0';

        digSum = dig1 + dig2 + digAc;
        digAc = digSum / 10;
        digSum %= 10;

        digSumC = digSum + '0';
        apilar(&pilaSuma, &digSumC, sizeof(char));

    }

    if(digAc)
    {
        digSumC = '1';
        apilar(&pilaSuma, &digSumC, sizeof(char));
    }

    tamSuma += digAc;

    suma = (char*)malloc(tamSuma + 1);
    if(!suma)
    {
        puts("No se ha podido reservar memoria para la suma.");
        vaciarPila(&pilaSuma);
        return NULL;
    }

    desapilarNumero(&pilaSuma, suma);

    return suma;
}



bool apilarCeros(Pila* pila, int cantCeros)
{
    char cero = '0';
    int i =0;

    while(i<cantCeros)
    {
        if(!apilar(pila, &cero, sizeof(char)))
        {
            puts("Error: no se pudo apilar el elemento.");
            return false;
        }

        i ++;
    }

    return true;
}



bool apilarNumero(Pila* pila, const char* num)
{
    const char* pDig = num;

    while(*pDig)
    {
        if(!apilar(pila, pDig, sizeof(char)))
        {
            puts("Error: no se pudo apilar el elemento.");
            return false;
        }

        pDig ++;
    }

    return true;
}



void desapilarNumero(Pila* pila, char* suma)
{
    char* dig = suma;

    while(!pilaVacia(pila))
    {
        desapilar(pila, dig, sizeof(char));
        dig ++;
    }
    *dig = '\0';
}
