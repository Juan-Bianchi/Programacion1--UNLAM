#include "Cadenas.h"

void* memchr_JUAN(const void* cadena, int caract, size_t cantCar)
{
    const char* pCad = (const char*)(cadena);

    while(pCad && cantCar && (char) caract != *pCad)
    {
        pCad ++;
        cantCar --;
    }

    if(!pCad)
        return NULL;

    return (void*) pCad;
}



int memcmp_JUAN(const void* cad1, const void* cad2, size_t cantCar)
{
    if(!cantCar || !cad1 || !cad2)
        return 0;

    while(cantCar && *(char*)cad1 == *(char*)cad2)
    {
        cantCar --;
        (char*)cad1 ++;
        (char*)cad2 ++;
    }

    return *(unsigned char*)cad1 - *(unsigned char*)cad2;
}


void* memcpy_JUAN(void* cad1, const void* cad2, size_t cantCar)
{
    void* dest = cad1;

    while(cantCar && cad1 && cad2)
    {
        *(char*)cad1 = *(const char*)cad2;
        (char*)cad1 ++;
        (const char*)cad2 ++;
        cantCar --;
    }

    return dest;
}


void* memmove_JUAN(void* cad1, const void* cad2, size_t cantCar)
{
    void* dest = cad1;

    if(cad1<=cad2)
    {
        while(cantCar)
        {
            *(char*)cad1 = *(char*)cad2;
            cantCar--;
            (char*)cad1 ++;
            (char*)cad2 ++;
        }
    }
    else
    {
        cad1 += cantCar - 1;
        cad2 += cantCar - 1;

        while(cantCar)
        {
            *(char*)cad1 = *(char*)cad2;
            (char*)cad1 --;
            (char*)cad2 --;
            cantCar --;
        }
    }
    return dest;
}


void* memset_JUAN(void* cad, int caract, size_t cantCar)
{
    unsigned char* pCad = cad;

    while(cantCar && pCad)
    {
        *pCad = (unsigned char) caract;
        pCad ++;
        cantCar --;
    }

    return cad;
}


char* strcat_JUAN(char* cad1, const char* cad2)
{
    char* destino = cad1;

    while(*cad1)
        cad1 ++;

    while(*cad2)
    {
        *cad1 = *cad2;
        cad2 ++;
        cad1 ++;
    }

    cad1 = '\0';

    return destino;
}



char* strchr_JUAN(char* cad, int caract)
{
    while(cad && *cad != (unsigned char)caract)
        cad ++;

    return(*cad == (unsigned char)caract)? cad: NULL;
}



int strcmp_JUAN(const char* cad1, const char* cad2)
{
    while(cad1 && cad2 && *cad1 == *cad2)
    {
        cad1 ++;
        cad2 ++;
    }
    if(!cad1 && cad2)
        return 1;
    if(cad1 && !cad2)
        return -1;
    return *cad1 - *cad2;
}



char* strcpy_JUAN(char* cad1, const char* cad2)
{
    char* dest = cad1;

    while(cad1 && cad2)
    {
        *cad1 = *cad2;
        cad1 ++;
        cad2 ++;
    }
    if(cad1)
        *cad1 = '\0';

    return dest;
}



size_t strcspn_JUAN(const char* cad1, const char* cad2)
{
    size_t cantCar = 0;

    while(cad1)
    {
        while(*cad1 != *cad2 && cad2)
            cad2 ++;
        if(*cad1==*cad2)
            cantCar ++;

        cad1 ++;
    }

    return cantCar;
}



size_t strlen_JUAN(const char* cad)
{
    size_t cantCar=0;

    while(*cad)
    {
        cantCar ++;
        cad ++;
    }

    return cantCar;
}



char* strncat_JUAN(char* cad1, const char* cad2, size_t cantCar)
{
    char* dest = cad1;

    while(*cad1)
        cad1 ++;

    while(cantCar && *cad2)
    {
        *cad1 = *cad2;
        cad1 ++;
        cad2 ++;
        cantCar --;
    }
    if(!*cad2)
        *cad1 = '\0';

    return dest;
}



int strncmp_JUAN(const char* cad1, const char* cad2, size_t cantCar)
{
    if(!cantCar)
        return 0;

    while(*cad1 && *cad2 && cantCar && *cad1 == *cad2)
    {
        cad1 ++;
        cad2 ++;
        cantCar --;
    }

    return *cad1 - *cad2;
}



char* strncpy_JUAN(char* cad1, const char* cad2, size_t cantCar)
{
    char* dest;

    if(!cantCar)
        return cad1;

    dest = cad1;

    while(cantCar && *cad2)
    {
        *cad1 = *cad2;
        cad1 ++;
        cad2 ++;
        cantCar --;
    }
    if(cantCar)
        *cad1 = '\n';

    return dest;
}



char* strpbrk_JUAN(const char* cad1, const char* cad2)
{
    while(*cad1 && *cad1 != *cad2)
    {
        while(*cad2 && *cad1 != *cad2)
            cad2 ++;

        if(*cad1 != *cad2)
            cad1 ++;
    }
    return (char*) cad1;
}



char* strrchr_JUAN(char* cad, int elem)
{
    char* inicio = cad;

    while(*cad)
        cad ++;

    while(cad > inicio && *cad != (char)elem)
        cad--;

    return(*cad == elem)?cad: NULL;
}



size_t strspn_JUAN(const char* cad1, const char* cad2)
{
    size_t cantCarac = 0;

    while(*cad1 && *cad2 && *cad1 == *cad2)
    {
        cad1 ++;
        cad2 ++;
        cantCarac ++;
    }

    return cantCarac;
}



char* strstr_JUAN(const char* cad1, const char* cad2)
{
    const char* dest = cad1;

    if(!*cad2)
        return (char*)cad1;

    while(*cad1 && *cad2 && *cad1 == *cad2)
    {
        cad1 ++;
        cad2 ++;
    }
    return (!*cad1 && !*cad2)? (char*)dest: NULL;
}


/*Ejercicio 8
Dado un array de char que contiene un texto compuesto por palabras que termina en '.' (o en su defecto en carácter nulo -'\0'-), escriba un
programa en que determine e informe:
a- cuál es la primera palabra y cuántas veces se repite en el texto
b- cuántas palabras tiene el texto
c- longitud de la palabra más larga*/

///considerare como palabra a toda combinacion con cualquier caracter, todas las palabras estaran separadas por un espacio vacio///

int contarOcurrenciasDePrimerPalabra(const char* texto, char* palabra)
{
    char* pPal = palabra;
    int cant = 0;

    while(*texto == ' ')
        texto ++;

    while(*texto != ' ' && *texto != '.' && *texto != '\0')
    {
        *pPal = *texto;
        texto ++;
        pPal ++;
    }

    if(pPal != palabra)
    {
        *pPal = '\0';
        cant ++;
    }

    while(*texto != '.' && *texto != '\0')
    {
        pPal = palabra;

        if(*(texto-1) == ' ')
        {
            while(*texto != '.' && *texto != '\0' && *texto == *pPal)
            {
                texto ++;
                pPal ++;
            }
            if(*pPal == '\0' && (*texto == ' ' || *texto == '.' || *texto == '\0'))
                cant ++;
        }
        texto ++;
    }

    return cant;
}




int contarCantidadDePalabrasEnTexto(const char* texto)
{
    int cant = 0;

    while(*texto != '.' && *texto != '\0')
    {
        while(*texto == ' ')
            texto ++;

        while(*texto != ' ' && *texto != '.' && *texto != '\0')
            texto ++;

        if(*(texto-1) != ' ' && *texto == ' ')
            cant ++;
    }
    if(*(texto-1) != ' ')
        cant ++;

    return cant;
}



int longitudDePalabraMasLargaEnTexto(const char* texto)
{
    int longitud, max=0;

    while(*texto != '.' && *texto != '\0')
    {
        longitud = 0;
        while(*texto != ' ' && *texto != '.' && *texto != '\0')
        {
            longitud ++;
            texto ++;
        }
        if(longitud > max)
            max = longitud;
        texto ++;
    }

    return max;
}

/*Ejercicio 10
Escriba una función que determine si una cadena de caracteres que representa a un número, es decir compuesta por los caracteres que
representan dígitos, recibida por argumento:
- es capicúa (es obvio),
- es múltiplo de 5 (el último dígito es 0 ó 5),
- es múltiplo de 6 (es par -termina en '0', '2', '4', '6', '8'-; y la suma de sus dígitos es múltiplo de 3),
- es múltiplo de 11 (la suma de los dígitos de posiciones pares, y la suma de los dígitos de posiciones impares es múltiplo de 11),
- es mayor que "100" (o cualquier otra cadena representando un número entero cualquiera, p. ej.: "-42").
Escriba una función que valide si todos los caracteres de una cadena representan un número dentro del intervalo de los: short int.*/




booleano esNumeroCadena(char* cadena)
{
    if(*cadena == '\0')
        return FALSO;

    while(*cadena >= '0' && *cadena <= '9')
        cadena ++;

    return *cadena == '\0';
}



booleano esCapicua(char* cadena)
{
    char* fin;

    if(!esNumeroCadena(cadena))
        return FALSO;

    fin = strchr(cadena, '\0');
    fin --;

    while(*cadena == *fin && cadena < fin)
    {
        cadena ++;
        fin --;
    }

    return cadena >= fin;
}




booleano esMultiploDeCinco(char* cadena)
{
    char* pUltDig = strchr(cadena, '\0') - 1;

    if(!esNumeroCadena(cadena))
        return FALSO;

    return *pUltDig % 5 == 0;
}



booleano esMultiploDeSeis(char* cadena)
{
    int suma = 0, num = 0;

    if(!esNumeroCadena(cadena))
        return FALSO;

    if(atoi(cadena) % 2 != 0)
        return FALSO;

    while(*cadena != '\0')
    {
        num = *cadena - 48;
        suma += num;
        cadena ++;
    }

    return suma % 3 == 0;
}



booleano esMultiploDeOnce(char* cadena)
{
    int i=0, sumaP = 0, sumaI = 0;

    if(!esNumeroCadena(cadena))
        return FALSO;

    while(*cadena != '\0')
    {
        if(i%2==0)
            sumaP += *cadena - 48;
        else
            sumaI += *cadena - 48;

        i ++;
        cadena ++;
    }

    return sumaI % 11 == 0 && sumaP % 11 == 0;
}



booleano esMayorAN(char* cadena, int n)
{
    if(!esNumeroCadena(cadena))
        return FALSO;

    return atoi(cadena) > n;
}



booleano esShortInt(char* cadena)
{
    if(!esNumeroCadena(cadena))
        return FALSO;

    return atoi(cadena) >= -32768 && atoi(cadena) <= 32768;
}



/*Ejercicio 11
Leyendo (sólo una vez) un archivo de texto como el del <ej.: 9> y utilizando las funciones del <ej.: 10>, y otras al efecto, determinar:
- cuántos son múltiplo de 5,
- cuántos son múltiplo de 6,
- cuántos son múltiplo de 11, y
- generar un archivo con los que sean mayores que "100" (o cualquier otro número recibido por argumento en la línea de comando)*/
