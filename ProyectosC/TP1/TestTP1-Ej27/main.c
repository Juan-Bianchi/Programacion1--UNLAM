#include <stdio.h>
#include <stdlib.h>

#include "../../Cadenas/Cadenas.h"

int main()
{
    char texto [500] = {"Dabale arroz a la zorra el abad"};
    booleano esPalindromo;

    esPalindromo = esUnPalindromo(texto);

    if(esPalindromo)
        printf("'%s' es un palindromo\n", texto);
    else
        printf("'%s' no es un palindromo\n", texto);

    return 0;
}
