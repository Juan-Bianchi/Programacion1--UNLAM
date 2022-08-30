#include "Recursivas.h"



double factorial(int num)
{
    if(num < 2)
        return 1;

    return num *= factorial(num-1);
}


int mostrarArray(char* linea)
{
    if(!*linea)
        return printf("\n");

    printf("%c", *linea);

    return mostrarArray(linea+1);
}


int mostrarArrayEnOrdenInverso(char* linea, char* fin)
{
    if(fin == linea)
        return printf("\n");

    printf("%c", *(fin-1));

    return mostrarArrayEnOrdenInverso(linea, fin-1);
}



long sumaNumEnCadena(char* linea)
{
    if(!*linea || *linea == '\n')
        return 0;

    return (es_numero(*linea))? (long int)(*linea - 48) + sumaNumEnCadena(linea+1): 0 + sumaNumEnCadena(linea+1);
}



long imprimeInversoYSumaArrayInt(int* vec, int* fin)
{
    if(fin == vec)
    {
        printf("%d", *fin);
        return *fin;
    }

    printf("%d + ", *fin);

    return *fin + imprimeInversoYSumaArrayInt(vec, fin-1);
}



long imprimeInversoYSumaParesDeArrayInt(int* vec, int* fin)
{
    if(fin == vec)
    {
        if(*fin % 2 == 0)
        {
            printf("%d", *fin);
            return *fin;
        }
        else
            return 0;
    }

    if(*fin % 2 == 0)
        printf("%d + ", *fin);

    return (*fin % 2 == 0)? *fin + imprimeInversoYSumaParesDeArrayInt(vec, fin-1): 0 + imprimeInversoYSumaParesDeArrayInt(vec, fin-1);
}



long imprimeInversoYSumaPosParesDeArrayInt(int* vec, int* fin)
{
    if(fin == vec)
    {
        if((fin - vec) % 2 == 0)
        {
            printf("%d", *fin);
            return *fin;
        }
        else
            return 0;
    }

    if((fin - vec)% 2 == 0)
        printf("%d + ", *fin);

    return ((fin - vec) % 2 == 0)? *fin + imprimeInversoYSumaPosParesDeArrayInt(vec, fin-1): 0 + imprimeInversoYSumaPosParesDeArrayInt(vec, fin-1);
}



int strlenRecursiva(char* cadena)
{
    if(!*cadena)
        return 0;

    return 1 + strlenRecursiva(cadena+1);
}



char* strchrRecursiva(char* cadena, char caract)
{
    if(!*cadena)
        return NULL;

    if(*cadena == caract)
        return cadena;

    return strchrRecursiva(cadena+1, caract);
}



char* strrchrRecursiva(char* cadena, char* fin, char caract)
{
    if(cadena == fin && *fin != caract)
        return NULL;

    if(*fin == caract)
        return fin;

    return strrchrRecursiva(cadena, fin-1, caract);
}
