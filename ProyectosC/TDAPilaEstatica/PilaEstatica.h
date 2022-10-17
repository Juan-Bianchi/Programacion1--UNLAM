#ifndef PILAESTATICA_H
#define PILAESTATICA_H

#define TAM 1000
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define min(a,b)    ((a)<(b)? (a):(b))

typedef struct
 {
     char vPila[TAM];
     unsigned tope;
 } Pila;



#endif // PILAESTATICA_H
