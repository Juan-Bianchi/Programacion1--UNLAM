#ifndef PALABRA_H
#define PALABRA_H

#include <stdbool.h>
#include <ctype.h>

#define es_letra(a)     (((a) >= 'A' && (a) <= 'Z') || ((a) >= 'a' && (a) <= 'z') || (a) == 'á' || (a) == 'é' || (a) == 'í' || (a) == 'ó' || (a) == 'ú' || (a) == 'ü' || (a) == 'ñ' || (a) == 'Á' || (a) == 'É' || (a) == 'Í' || (a) == 'Ó' || (a) == 'Ú' || (a) == 'Ü' || (a) == 'Ñ')
#define es_numero(x)    ( (x) >= '0' && (x) <= '9' )
#define es_alfanum(x)   ( ( (x) >= 'a' && (x) <= 'z') || ( (x) >= 'A' && (x) <= 'Z' ) ||  ((x) >= '0' && (x) <= '9') || (x) == 'á' || (x) == 'é' || (x) == 'í' || (x) == 'ó' || (x) == 'ú' || (x) == 'ü' || (x) == 'ñ' || (x) == 'Á' || (x) == 'É' || (x) == 'Í' || (x) == 'Ó' || (x) == 'Ú' || (x) == 'Ü' || (x) == 'Ñ')
#define es_vocal(x)     ( (x) == 'a' || (x) == 'e' || (x) == 'i' || (x) == 'o' || (x) == 'u' || (x) == 'A' || (x) == 'E' || (x) == 'I' || (x) == 'O' || (x) == 'U' || (x) == 'á' || (x) == 'é' || (x) == 'í' || (x) == 'ó' || (x) == 'ú' || (x) == 'ü' || (x) == 'Á' || (x) == 'É' || (x) == 'Í' || (x) == 'Ó' || (x) == 'Ú' || (x) == 'Ü')



typedef struct
{
    char* cursor;
    bool fSec;
} SecuenciaPalabras;


typedef struct
{
    char* ini;
    char* fin;
} Palabra;



void crearSecuenciaPalabras(SecuenciaPalabras* sec, char* cad);
bool leerPalabra(SecuenciaPalabras* sec, Palabra* pal);
void escribirPalabra(SecuenciaPalabras* sec, Palabra* pal);
void escribirPalabraPrimeraMayuscula(SecuenciaPalabras* sec, Palabra* pal);




#endif // PALABRA_H
