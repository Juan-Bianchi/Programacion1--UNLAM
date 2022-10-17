#ifndef TDACOLAESTATICA_H
#define TDACOLAESTATICA_H

#define TAM 256
#define min(a,b)    ((a)<(b)?(a):(b))

#include <stdlib.h>

typedef struct
{
    char vec[TAM];
    unsigned frente;
    unsigned fondo;
    size_t tamDisp;
} Cola;









#endif // TDACOLAESTATICA_H
