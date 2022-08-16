#include <stdio.h>
#include <stdlib.h>

#include "../../Cadenas/Cadenas.h"
#include "../TP2-FuncionesConArchivos/Archivos.h"


int main(int argc, char* argv[])
{

    char cadena[1000], palabra[1000];
    FILE* archTxt;
    booleano abiertoCorrec;
    int cantOcurr, cantPal, maxLong;

    puts("Ejercicio 7");
    printf("Se abrira el archivo %s para escritura.\n", argv[1]);
    archTxt = fopen(argv[1], argv[2]);
    abiertoCorrec = archivoAbiertoCorrectamente(archTxt, argv[1], argv[2]);
    if(!abiertoCorrec)
    {
        printf("El archivo no pudo ser abierto. Se cerrara el programa");
        exit(1);
    }


    puts("Ejercicio 8");
    printf("Ingrese el texto que desea que sea analizado: ");
    gets(cadena);
    cantOcurr = contarOcurrenciasDePrimerPalabra(cadena, palabra);
    cantPal = contarCantidadDePalabrasEnTexto(cadena);
    maxLong = longitudDePalabraMasLargaEnTexto(cadena);
    printf("La cantidad de veces que se repite la primera palabra ('%s') es %d\n\n", palabra, cantOcurr);
    printf("La cantidad de palabras hasta el caracter '.' o el fin del texto es %d\n\n", cantPal);
    printf("La palabra de longitud maxima tiene %d caracteres.\n\n", maxLong);

    fprintf(archTxt, "%s", cadena);

    fclose(archTxt);
    puts("Se abrira el archivo txt para ver su contenido.");
    system("type ArchivoTexto.txt");

    return 0;
}
