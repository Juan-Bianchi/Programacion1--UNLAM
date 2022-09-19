#include "Palabra.h"

void crearSecuenciaPalabras(SecuenciaPalabras* sec, char* cad)
{
    sec->cursor = cad;
    sec->fSec = false;
}



bool leerPalabra(SecuenciaPalabras* sec, Palabra* pal)
{
    char* act = sec->cursor;

    while(*act && !es_letra(*act))
        act ++;

    if(!*act)
    {
        sec->fSec = true;
        return false;
    }

    pal->ini = act;

    while(*act && es_letra(*act))
        act ++;

    pal->fin = act - 1;

    sec->cursor = act;

    return true;
}




void escribirPalabra(SecuenciaPalabras* sec, Palabra* pal)
{
    char* orig = pal->ini, * dest = sec->cursor;

    for(; orig <= pal->fin ; orig ++, dest ++)
        *dest = *orig;

    sec->cursor = dest;
}




void escribirPalabraPrimeraMayuscula(SecuenciaPalabras* sec, Palabra* pal)
{
    char* orig = pal->ini, * dest = sec->cursor;

    *dest = toupper(*orig);
    orig ++;
    dest ++;

    for(; orig <= pal->fin ; orig ++, dest ++)
        *dest = *orig;

    sec->cursor = dest;
}



void cerrarSecuenciaPalabras(SecuenciaPalabras* sec)
{
    *sec->cursor = '\0';
    sec->fSec = true;
}
