/*Ejercicio 16
Leyendo el texto del archivo del ejercicio anterior, informar la cantidad de palabras que cumplen con cada una de las siguientes condiciones:
- están formadas por una sola letra,
- están formadas por una cantidad par de letras,
- comienzan con 'n',
- comienzan con un prefijo (o subcadena) determinado ingresado por el operador
- tienen más de tres vocales,
- comienzan y terminan con vocales,
- contienen dígitos,
- sólo están formadas por dígitos,
- son palíndromos.*/

///asumo que una palabra esta formada por letras y numeros///

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../../Cadenas/Cadenas.h"


int tieneUnaSolaLetra(char* cadena);
int estaFormadaPorCantidadParDeLetras(char* cadena);
int comienzaConN(char* cadena);
int comienzaCon(char* cadena, char* buscado);
int tieneMasDeTresVocales(char* cadena);
int comienzaYTerminaConVocales(char* cadena);
int contieneDigitos(char* cadena);
int soloFormadaPorDigitos(char* cadena);
int esPalindromo(char* cadena);


int main(int argc, char* argv[])
{
    FILE* archTxt;
    char linea[1000], letra, * pFinLin;
    int contUnaLet = 0, contPar = 0, contN = 0, cont = 0, contTresVoc = 0, contComIniVoc = 0, contSoloDig = 0, contDig = 0, contPal = 0;

    archTxt = fopen(argv[1], argv[2]);
    if(archTxt == NULL)
    {
        printf("Error al abrir el archivo '%s' en modo '%s'. Se cerrara el programa.\n", argv[1], argv[2]);
        return 1;
    }

    printf("Ingrese una letra y se contara la cantidad de palabras que tienen a la misma: ");
    fflush(stdin);
    scanf("%c", &letra);
    fflush(stdin);

    putchar('\n');
    system("type ArchivoTexto.txt");
    putchar('\n');

    while(fgets(linea, 1000, archTxt))
    {
        pFinLin = strrchr(linea, '\n');
        if(pFinLin)
            *pFinLin = '\0';

        contUnaLet += tieneUnaSolaLetra(linea);
        contPar += estaFormadaPorCantidadParDeLetras(linea);
        contN += comienzaConN(linea);
        cont += comienzaCon(linea, &letra);
        contTresVoc += tieneMasDeTresVocales(linea);
        contComIniVoc += comienzaYTerminaConVocales(linea);
        contDig += contieneDigitos(linea);
        contSoloDig += soloFormadaPorDigitos(linea);
        contPal += esPalindromo(linea);
    }

    printf("La cantidad de palabras con una sola letra es %d\n", contUnaLet);
    printf("La cantidad de palabras con cantidad par de letras es %d\n", contPar);
    printf("La cantidad de palabas que empiezan con 'n' son %d\n", contN);
    printf("La cantidad de palabras que empiezan con la letra '%c' es %d\n", letra, cont);
    printf("La cantidad de palabras que tienen mas de 3 vocales es %d\n", contTresVoc);
    printf("La cantidad de palabras que comienzan y terminan con vocales es %d\n", contComIniVoc);
    printf("La cantidad de palabras que tienen digitos es %d\n", contDig);
    printf("La cantidad de palbras que estan formadas solo por digitos es %d\n", contSoloDig);
    printf("La cantidad de palabras que son palindromos es %d\n", contPal);

    fclose(archTxt);

    return 0;
}



int tieneUnaSolaLetra(char* cadena)
{
    int cant= 0, cantL;

    while(*cadena)
    {
        cantL = 0;
        while(*cadena && es_alfanum(*cadena))
        {
            if(es_letra(*cadena))
                cantL ++;
            cadena ++;
        }

        if(cantL == 1)
            cant ++;

        while(*cadena && !es_alfanum(*cadena))
            cadena ++;
    }

    return cant;
}



int estaFormadaPorCantidadParDeLetras(char* cadena)
{
    int contC, contPal = 0;

    while(*cadena)
    {
        contC = 0;
        while(*cadena && es_alfanum(*cadena))
        {
            if(es_letra(*cadena))
                contC ++;
            cadena ++;
        }

        if(contC % 2 == 0 && contC !=0)
            contPal ++;

        while(*cadena && !es_alfanum(*cadena))
            cadena ++;
    }
    return contPal;
}



int comienzaConN(char* cadena)
{
    int cont = 0;
    char* pInicio = cadena;

    while(*cadena)
    {
        if(cadena == pInicio && toupper(*cadena) == 'N')
            cont ++;
        else
            if(!es_alfanum(*(cadena-1)) && toupper(*cadena) == 'N')
                cont++;

        cadena ++;
    }

    return cont;
}



int comienzaCon(char* cadena, char* buscado)
{
    int cont = 0;
    char* pInicio = cadena;

    while(*cadena)
    {
        if(cadena == pInicio && toupper(*cadena) == toupper(*buscado))
            cont ++;
        else
            if(!es_alfanum(*(cadena-1)) && toupper(*cadena) == toupper(*buscado))
                cont++;

        cadena ++;
    }

    return cont;
}



int tieneMasDeTresVocales(char* cadena)
{
    int cont = 0, contV;

    while(*cadena)
    {
        while(*cadena && !es_alfanum(*cadena))
            cadena ++;

        contV = 0;
        while(*cadena && es_alfanum(*cadena))
        {
            if(es_vocal(*cadena))
                contV ++;

            cadena ++;
        }
        if(contV > 3)
            cont ++;
    }

    return cont;
}



int comienzaYTerminaConVocales(char* cadena)
{
    int cont = 0;
    bool empCVoc;
    char* pIni = cadena;

    while(*cadena)
    {
        while(*cadena && !es_alfanum(*cadena))
            cadena ++;

        empCVoc = false;
        while(*cadena && es_alfanum(*cadena))
        {
            if(es_vocal(*cadena) && (!es_alfanum(*(cadena-1)) || cadena == pIni))
                empCVoc = true;

            cadena ++;
        }
        if(es_vocal(*(cadena-1)) && empCVoc)
            cont ++;
    }

    return cont;
}



int contieneDigitos(char* cadena)
{
    int cont = 0;
    bool tieneDig;

    while(*cadena)
    {
        while(*cadena && !es_alfanum(*cadena))
            cadena ++;

        tieneDig = false;
        while(*cadena && es_alfanum(*cadena))
        {
            if(es_numero(*cadena))
                tieneDig = true;

            cadena ++;
        }
        if(tieneDig)
            cont ++;
    }

    return cont;
}



int soloFormadaPorDigitos(char* cadena)
{
    int cont = 0;
    bool esSoloN;

    while(*cadena)
    {
        while(*cadena && !es_alfanum(*cadena))
            cadena ++;

        if(es_alfanum(*cadena))
            esSoloN = true;
        while(*cadena && es_alfanum(*cadena))
        {
            if(!es_numero(*cadena))
                esSoloN = false;

            cadena ++;
        }
        if(esSoloN)
            cont ++;
    }

    return cont;
}



int esPalindromo(char* cadena)
{
    int cont = 0, contLet;
    char* pIn = strrchr(cadena, '\0'), * pFin = strrchr(cadena, '\0');

    while(pFin > cadena)
    {
        while(pFin > cadena && !es_alfanum(*pFin))
        {
            pIn --;
            pFin --;
        }
        *(pFin+1) = '\0';

        while(pIn > cadena && es_alfanum(*pIn))
            pIn --;

        if(pIn > cadena && !es_alfanum(*pIn))
            pIn ++;

        contLet = 0;
        while(pIn < pFin && *pIn == *pFin)
        {
            pIn ++;
            pFin --;
            contLet ++;
        }
        if(pIn >= pFin && contLet > 0)
            cont ++;

        while(pIn > cadena && es_alfanum(*pIn))
            pIn --;
        while(pFin > cadena && es_alfanum(*pFin))
            pFin --;

        *(pFin+1) = '\0';
    }
    return cont;
}
