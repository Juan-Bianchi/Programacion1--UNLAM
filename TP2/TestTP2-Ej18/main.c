/*Ejercicio 18
Ingrese hasta un máximo de 1000 caracteres (o hasta que se ingrese el carácter
'.'. Mostrar por pantalla el carácter inmediato posterior
(p. ej.: "a bgxj" ->"b!chyk"; "Zapato" -> "[bqbup"). Grabar en un archivo aquellas palabras con más de una determinada cantidad de letras que se
deben pedir al operador al comienzo del proceso.*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../Cadenas/Cadenas.h"

int main(int argc, char* argv[])
{
    char texto[1000], pal[1000];
    char* pTexto = texto, * pPal;
    int tamanio, largPal, contChar;
    FILE* arch;

    printf("Ingrese un texto. El mismo terminara cuando se ingrese el caracter '.' o cuando se llegue al caracter numero 1000 ingresado: ");
    fflush(stdin);
    scanf("%[^.]", texto);
    fflush(stdin);
    tamanio = strlen(texto);
    printf("A continuacion se procedera a imprir el caracter posterior de cada caracter ingresado en la cadena: \n");
    for(; pTexto <  texto + tamanio - 1; pTexto++)
        printf("%c", *pTexto + 1);

    printf("\n\nIngrese la cantidad de caracteres que se contaran para guardar las palabras en el archivo. Se tomara a palabras con mas caracteres que el ingresado: ");
    fflush(stdin);
    scanf("%d", &largPal);
    fflush(stdin);

    arch = fopen(argv[1], argv[2]);
    if(arch == NULL)
    {
        printf("El archivo '%s' no ha podido ser abierto en modo '%s'. Se cerrara el programa.\n,", argv[1], argv[2]);
        return 1;
    }

    pTexto = texto;
    while(*pTexto != '.' && pTexto <  texto + tamanio - 1)              ///comienzo a leer el texto
    {
        while(*pTexto != '.' && pTexto <  texto + tamanio - 1 && !es_alfanum(*pTexto))          ///si no es alfa numerico solo paso al siguiente caracter
            pTexto ++;

        contChar = 0;
        pPal = pal;                                                                      ///coloco al inicio el puntero de la palabra de la cual calculare la longitud
        while(*pTexto != '.' && pTexto <  texto + tamanio - 1 && es_alfanum(*pTexto))
        {
            *pPal = *pTexto;
            pTexto ++;
            pPal ++;
            contChar ++;                                                                ///cuento las letras de la palabra
        }
        *pPal = '\0';

        if(contChar > largPal)
            fprintf(arch, "%s\n", pal);                                                 ///si excede el largo lo copio en el archivo de texto
    }

    printf("A continuacion veremos el nuevo archivo generado con palabras de mas de %d caracteres: \n\n", largPal);
    fclose(arch);
    system("type Texto.txt");                                                           ///imprimo en pantalla el contenido completo del txt

    return 0;
}
