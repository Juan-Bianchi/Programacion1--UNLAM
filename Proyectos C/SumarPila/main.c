#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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

    printf("%s\n", suma);

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
        desapilar(&pila1, &dig1C, sizeof(char));
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
    int cero = 0, i =0;

    while(i<cantCeros && pilaLlena(pila, sizeof(char)))
    {
        if(!apilar(pila, &cero, sizeof(int)))
            puts("Error: no se pudo apilar el elemento.");

        i ++;
    }

    return i == cantCeros;
}



bool apilarNumero(Pila* pila, const char* num)
{
    const char* pDig = num;

    while(*pDig && !pilaLlena(pila, sizeof(char)))
    {
        if(!apilar(pila, num, sizeof(char)))
            puts("Error: no se pudo apilar el elemento.");

        pDig ++;
    }

    return !(*pDig);
}



void desapilarNumero(Pila* pila, char* suma)
{
    char* dig = suma;

    while(!pilaVacia(pila))
    {
        desapilar(pila, dig, sizeof(char));
        dig ++;
    }
    dig = '\0';
}
