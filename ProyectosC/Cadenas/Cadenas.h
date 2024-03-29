#ifndef CADENAS_H
#define CADENAS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "Palabra.h"


#define VERDADERO 1
#define FALSO 0



typedef struct
{
    char letra;
    int cont;
} Ocurrencias;




int typedef (*Cmp)(const void* elem1, const void* elem2);

void* memchr_JUAN(const void* cadena, int caract, size_t cantCar);         //Localiza la primera aparici�n del car�cter c (convertido a unsigned char) en los primeros n caracteres (cada uno interpretado como un unsigned char) del objeto apuntado por s. La funci�n retorna un puntero al car�cter localizado, o un puntero nulo si el car�cter no apareci� en el objeto.
int memcmp_JUAN(const void* cad1, const void* cad2, size_t cantCar);       //Compara los primeros n caracteres del objeto apuntado por s1 (interpretado como unsigned char) con los primeros n caracteres del objeto apuntado por s2 (interpretado como unsigned char). La funci�n retorna un n�mero entero mayor, igual, o menor que cero, apropiadamente seg�n el objeto apuntado por s1 es mayor, igual, o menor que el objeto apuntado por s2.
void* memcpy_JUAN(void* cad1, const void* cad2, size_t cantCar);           //Copia los primeros n caracteres del objeto apuntado por s2 al objeto apuntado por s1. La funci�n retorna el valor de s1. Si al copiar un objeto al otro se superponen, entonces el comportamiento no est� definido.
void* memmove_JUAN(void* cad1, const void* cad2, size_t cantCar);          //Copia los primeros n caracteres del objeto apuntado por s2 al objeto apuntado por s1.Sin embargo, se asegura de que no est�n superpuestos. Por esta raz�n, copia los caracteres a un array/arreglo temporalmente. Despu�s vuelve a copiar del array temporal al objeto en cuesti�n. La funci�n retorna el valor de s1.
void* memset_JUAN(void* cad, int caract, size_t cantCar);                  //Copia el valor de c (convertido a unsigned char) en cada uno de los primeros n caracteres en el objeto apuntado por s. La funci�n retorna el valor de s1. Si la copia hace que los objetos se superpongan, entonces el comportamiento no est� definido.
char* strcat_JUAN(char* cad1, const char* cad2);                           //A�ade una copia de la cadena apuntada por s2 (incluyendo el car�cter nulo) al final de la cadena apuntada por s1. El car�cter inicial de s2 sobrescribe el car�cter nulo al final de s1.
char* strchr_JUAN(char* cad, int caract);                                  //Localiza la primera aparici�n de c (convertido a unsigned char) en la cadena apuntada por s (incluyendo el car�cter nulo). La funci�n retorna un puntero a partir del car�cter encontrado. Si no se ha encontrado el car�cter, c, entonces retorna un puntero null.
int strcmp_JUAN(const char* cad1, const char* cad2);                       //Compara la cadena apuntada por s1 con la cadena apuntada por s2. La funci�n retorna un n�mero entero mayor, igual, o menor que cero, apropiadamente seg�n la cadena apuntada por s1 es mayor, igual, o menor que la cadena apuntada por s2.
int strcmpi_JUAN(const char* cad1, const char* cad2);                      //Hace una comparacion sin signo(unsigned char)sin tener en cuenta mayusculas y minusculas(habitualmente declarada como macro.
char* strcpy_JUAN(char* cad1, const char* cad2);                           //Copia la cadena apuntada por s2 (incluyendo el car�cter nulo) a la cadena apuntada por s1. La funci�n retorna el valor de s1. Si al copiar una cadena a la otra se superponen, entonces el comportamiento no est� definido.
size_t strcspn_JUAN(const char* cad1, const char* cad2);                   //Cuenta el n�mero de caracteres de una subcadena inicial apuntada por s1 que no contenga ninguno de los caracteres en la cadena apuntada por s2. La funci�n retorna el n�mero de caracteres le�dos de la subcadena hasta que halla alguno de los caracteres de s2. El car�cter nulo no se cuenta.
char* strerror_JUAN(int errnum);                                           //Convierte el n�mero de error en errnum a un mensaje de error (una cadena de caracteres). La funci�n retorna la cadena de caracteres conteniendo el mensaje asociado con el n�mero de error. Esta conversi�n y el contenido del mensaje dependen de la implementaci�n. La cadena no ser� modificada por el programa, pero s� puede ser sobrescrito con otra llamada a la misma funci�n.
size_t strlen_JUAN(const char* cad);                                       //Calcula el n�mero de caracteres de la cadena apuntada por s. La funci�n retorna el n�mero de caracteres hasta el car�cter nulo, que no se incluye.
char* strncat_JUAN(char* cad1, const char* cad2, size_t cantCar);          //A�ade no m�s de n caracteres (un car�cter nulo y los dem�s caracteres siguientes no son a�adidos) de la cadena apuntada por s2 al final de la cadena apuntada por s1. El car�cter inicial de s2 sobrescribe el car�cter nulo al final de s1. El car�cter nulo siempre es a�adido al resultado. La funci�n retorna el valor de s1. Si la copia hace que los objetos se superpongan, entonces el comportamiento no est� definido.
int strncmp_JUAN(const char* cad1, const char* cad2, size_t cantCar);      //Compara no m�s de n caracteres (caracteres posteriores al car�cter nulo no se tienen en cuenta) de la cadena apuntada por s1 con la cadena apuntada por s2. La funci�n retorna un n�mero entero mayor, igual, o menor que cero, apropiadamente seg�n la cadena apuntada por s1 es mayor, igual, o menor que la cadena apuntada por s2.
char* strncpy_JUAN(char* cad1, const char* cad2, size_t cantCar);          //Copia no m�s de n caracteres (caracteres posteriores al car�cter nulo no son copiados) de la cadena apuntada por s2 a la cadena apuntada por s1. La funci�n retorna el valor de s1. Si al copiar una cadena a la otra se superponen, entonces el comportamiento no est� definido. Si el array/arreglo apuntado por s2 es una cadena que es m�s corta que n caracteres, entonces caracteres nulos son a�adidos a la copia en el array apuntado por s1.
char* strpbrk_JUAN(const char* cad1, const char* cad2);                    //Localiza la primera aparici�n de la cadena apuntada por s1 de cualquier car�cter de la cadena apuntada por s2. La funci�n retorna un puntero al car�cter, o un puntero nulo si ning�n car�cter de s2 apareci� en s1.
char* strrchr_JUAN(char* cad, int cantCar);                                //Localiza la �ltima aparici�n de c (convertido a unsigned char) en la cadena apuntada por s (incluyendo el car�cter nulo). La funci�n retorna un puntero a partir del car�cter encontrado. Si no se ha encontrado el car�cter, c, entonces retorna un puntero nulo.
size_t strspn_JUAN(const char* cad1, const char* cad2);                    //Calcula el n�mero de caracteres de una subcadena inicial apuntada por s1 que consiste en todos los caracteres formados en la cadena apuntada por s2. La funci�n retorna la longitud de esta subcadena.
int strstr_JUAN(const char* cad1, const char* cad2);                       //Localiza la primera aparici�n en la cadena apuntada por s1 de la secuencia de caracteres (excluyendo el car�cter nulo) en la cadena apuntada por s2. La funci�n retorna un puntero a la cadena encontrada, o un puntero nulo si no se encontr� la cadena. Si s2 apunta a una cadena de longitud cero, la funci�n retorna s1.


bool esUnPalindromo(char* cadena);
bool esUnPalindromoPan(char* pal);
bool esPalindromoPalabraPAN(const char* pal);
bool esPalindromoPalabraInsensitivePAN(const char* pal);
bool esAnagrama(char* cadena, char* cadena2);


char* normalizarATitulo(const char* textOrig, char* textoDest);



int contarOcurrenciasDePrimerPalabra(const char* texto, char* palabra);
int contarCantidadDePalabrasEnTexto(const char* texto);
int longitudDePalabraMasLargaEnTexto(const char* texto);

bool esNumeroCadena(char* cadena);
bool esCapicua(char* cadena);
bool esMultiploDeCinco(char* cadena);
bool esMultiploDeSeis(char* cadena);
bool esMultiploDeOnce(char* cadena);
bool esMayorAN(char* cadena, int n);
bool esShortInt(char* cadena);


#endif // CADENAS_H
