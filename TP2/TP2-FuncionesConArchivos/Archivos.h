#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include <stdio.h>

#define verdadero 1
#define falso 0

typedef int booleano;

void vectFloatAArchTxt(FILE* arch, float* vect, const int cantElem);
booleano archivoAbiertoCorrectamente(FILE* arch, char* nombre, char* modoApert);


#endif // ARCHIVOS_H
