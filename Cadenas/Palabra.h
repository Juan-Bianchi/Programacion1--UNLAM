#ifndef PALABRA_H
#define PALABRA_H

#include <stdbool.h>
#include <ctype.h>

#define es_letra(a)     (((a) >= 'A' && (a) <= 'Z') || ((a) >= 'a' && (a) <= 'z') || (a) == '�' || (a) == '�' || (a) == '�' || (a) == '�' || (a) == '�' || (a) == '�' || (a) == '�' || (a) == '�' || (a) == '�' || (a) == '�' || (a) == '�' || (a) == '�' || (a) == '�' || (a) == '�')
#define es_numero(x)    ( (x) >= '0' && (x) <= '9' )
#define es_alfanum(x)   ( ( (x) >= 'a' && (x) <= 'z') || ( (x) >= 'A' && (x) <= 'Z' ) ||  ((x) >= '0' && (x) <= '9') || (x) == '�' || (x) == '�' || (x) == '�' || (x) == '�' || (x) == '�' || (x) == '�' || (x) == '�' || (x) == '�' || (x) == '�' || (x) == '�' || (x) == '�' || (x) == '�' || (x) == '�' || (x) == '�')
#define es_vocal(x)     ( (x) == 'a' || (x) == 'e' || (x) == 'i' || (x) == 'o' || (x) == 'u' || (x) == 'A' || (x) == 'E' || (x) == 'I' || (x) == 'O' || (x) == 'U' || (x) == '�' || (x) == '�' || (x) == '�' || (x) == '�' || (x) == '�' || (x) == '�' || (x) == '�' || (x) == '�' || (x) == '�' || (x) == '�' || (x) == '�' || (x) == '�')



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
