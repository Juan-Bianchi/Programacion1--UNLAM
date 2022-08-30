#ifndef RECURSIVAS_H
#define RECURSIVAS_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define es_numero(x)   ( (x) >= '0' && (x) <= '9' )


double factorial(int num);
int mostrarArray(char* linea);
int mostrarArrayEnOrdenInverso(char* linea, char* fin);
long sumaNumEnCadena(char* linea);
long imprimeInversoYSumaArrayInt(int* vec, int* fin);
long imprimeInversoYSumaParesDeArrayInt(int* vec, int* fin);
long imprimeInversoYSumaPosParesDeArrayInt(int* vec, int* fin);
int strlenRecursiva(char* cadena);
char* strchrRecursiva(char* cadena, char caract);
char* strrchrRecursiva(char* cadena, char* fin, char caract);


#endif // RECURSIVAS_H
