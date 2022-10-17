/*Ejercicio 15
Escriba un programa que genere un archivo de texto de varias líneas, y en cada línea una o varias palabras (se considera palabra, cualquier
carácter que no responde a lo indicado por la función de biblioteca isspace, ni es coma, ni punto, ni ... (use su criterio). La separación entre
palabras puede ser de uno o varios de estos caracteres. La primera palabra en una línea de texto puede estar precedida por más de uno de estos
caracteres de separación, y lo mismo puede suceder después de la última palabra.
Escriba otro programa que agregue nuevas líneas de texto al archivo creado por el programa.
Escriba un programa que haciendo uso de su propia versión de strstr, busque en todo el archivo la subcadena recibida en la línea de comando
(cualquiera sea esta), e informe en qué línea y en qué posición dentro de la línea la encuentra. Puede no encontrarla, encontrarla una única
vez, o varias veces en la misma o distintas líneas del archivo.*/

///el criterio utilizado para decir que una sucesion de caracteres es una palabra es que la misma esta formada por letras y numeros///

#include <stdio.h>
#include <stdlib.h>

#include "../../Cadenas/cadenas.h"


int main(int argc, char* argv[])
{
    FILE* archTxt;
    char* condFin = "Cerrar texto\n", * pLinea;
    char linea[1000];
    int posicion, nroLinea = 1;
    booleano encontrado = FALSO;


    archTxt = fopen(argv[1], argv[2]);
    if(archTxt == NULL)
    {
        printf("No se ha podido abrir el archivo '%s' en el modo '%s'. Se cerrara el programa.\n", argv[1], argv[2]);
        exit(1);
    }

    puts("A continuacion se procerdera a la carga de cadenas (para terminar ingrese 'Cerrar texto'): ");
    printf("Ingrese una linea (para terminar ingrese 'Cerrar texto'): ");
    fgets(linea, 1000, stdin);
    while(strcmp(linea, condFin)!=0)
    {
        fprintf(archTxt, "%s", linea);
        printf("Ingrese una linea (para terminar ingrese 'Cerrar texto'): ");
        fgets(linea, 1000, stdin);
    }

    fclose(archTxt);

    puts("El archivo se ha cerrado satistfactoriamente. A continuacion se mostrara su contenido:");
    system("type ArchivoTexto.txt");




    puts("\n\nSe procedera a la reapertura del archivo para agregar algunas lineas al mismo.");
    archTxt = fopen(argv[1], argv[3]);
    if(archTxt == NULL)
    {
        printf("No se ha podido abrir el archivo '%s' en el modo '%s'. Se cerrara el programa.\n", argv[1], argv[3]);
        exit(1);
    }

    puts("\nA continuacion se procerdera a agregar cadenas (para terminar ingrese 'Cerrar texto'): ");
    printf("Ingrese una linea (para terminar ingrese 'Cerrar texto'): ");
    fgets(linea, 1000, stdin);
    while(strcmp(linea, condFin)!=0)
    {
        fprintf(archTxt, "%s", linea);
        printf("Ingrese una linea (para terminar ingrese 'Cerrar texto'): ");
        fgets(linea, 1000, stdin);
    }

    fclose(archTxt);

    puts("El archivo se ha cerrado satistfactoriamente. A continuacion se mostrara su contenido:");
    system("type ArchivoTexto.txt");


    printf("\n\nPor ultimo se buscara la siguiente cadena que ha sido enviada como argumento a main: '%s'\n", argv[5]);
    archTxt = fopen(argv[1], argv[4]);
    if(archTxt == NULL)
    {
        printf("No se ha podido abrir el archivo '%s' en el modo '%s'. Se cerrara el programa.\n", argv[1], argv[4]);
        exit(1);
    }

    while(fgets(linea, 1000, archTxt))
    {
        posicion = strstr_JUAN(linea, argv[5]);
        while(posicion != -1)
        {
            pLinea = linea + posicion + strlen(argv[5]);
            printf("La cadena '%s' ha sido encontrada en la linea %d en la posicion %d.\n", argv[5], nroLinea, posicion);
            posicion = strstr_JUAN(pLinea, argv[5]);
            encontrado = VERDADERO;
        }
        nroLinea ++;
    }
    if(!encontrado)
        printf("La cadena '%s' no ha sido encontrada\n\n", argv[5]);

    return 0;
}
