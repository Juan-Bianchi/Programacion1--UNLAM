#include "Cadenas.h"


char toSinTilde(char letra);
bool esLetra(char letra);
char* saltarBlancos(char* izq);
char* saltarBlancosR(char* der, char* izq);



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


int strcmpi_JUAN(const char* cad1, const char* cad2)
{
    char l1, l2;

    l1 = *cad1;
    l2 = *cad2;

    if(l1 >= 'a' && l1 <= 'z')
        l1 -= 32;
    if(l2 >= 'a' && l2 <= 'z')
        l2 -= 32;

    while(l1 != '\0' && l2 != '\0' && l1 == l2)
    {
        cad1++;
        cad2++;

        l1 = *cad1;
        l2 = *cad2;

        if(l1 >= 'a' && l1 <= 'z')
            l1 -= 32;
        if(l2 >= 'a' && l2 <= 'z')
            l2 -= 32;
    }

    if(l1 == '\0' && l2 != '\0')
        return -1;

    if(l1 != '\0' && l2 == '\0')
        return 1;

    return l1 - l2;


}



char* strcpy_JUAN(char* cad1, const char* cad2)
{
    char* dest = cad1;

    while(*cad2 && *cad2 != '\n')
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



int strstr_JUAN(const char* cad1, const char* cad2)
{
    const char* pCad2 = cad2, * inicio = cad1;
    int cont, pos;
    bool encontrado = false;

    while(*cad1 && *pCad2 && !encontrado)
    {
        pCad2 = cad2;
        cont = 0;
        while(*cad1 == *pCad2)
        {
            cad1 ++;
            pCad2 ++;
            cont ++;
            pos++;
        }
        if(strlen_JUAN(cad2) == cont)
        {
            pos = cad1 - inicio - cont;
            encontrado = VERDADERO;
        }
        cad1++;
    }

    return (encontrado)? pos: -1;
}



/*Ejercicio 27
Desarrollar una funciÛn que determine si una cadena de caracteres es un palÌndromo.*/


bool esUnPalindromo(char* cadena)
{
    char* pFinal = strrchr(cadena, '\0');
    bool esPal = true, tieneLetra = false;

    while(cadena < pFinal && esPal)
    {
        while(!es_letra(*cadena) && !es_letra(*pFinal) && cadena < pFinal && esPal)
        {
            cadena++;
            pFinal--;
        }
        while(!es_letra(*cadena) && es_letra(*pFinal) && cadena < pFinal && esPal)
        {
            cadena++;
            tieneLetra = VERDADERO;
        }
        while(es_letra(*cadena) && !es_letra(*pFinal) && cadena < pFinal && esPal)
        {
            pFinal--;
            tieneLetra = VERDADERO;
        }
        while(es_letra(*cadena) && es_letra(*pFinal) && cadena < pFinal && esPal)
        {
            tieneLetra = VERDADERO;

            if(toupper(*cadena) != toupper(*pFinal))
                esPal = FALSO;

            cadena++;
            pFinal--;
        }
    }

    return tieneLetra && cadena >= pFinal;
}



bool esUnPalindromoPan(char* pal)
{
    char* izq = pal;
    char* der = pal + strlen(pal) - 1;

    izq = saltarBlancos(izq);
    der = saltarBlancosR(der, izq);

    while(izq < der && tolower(toSinTilde(*izq)) == tolower(toSinTilde(*der)))
    {
        izq ++;
        izq = saltarBlancos(izq);
        der --;
        der = saltarBlancosR(der, izq);
    }

    return izq >= der;
}






bool esPalindromoPalabraPAN(const char* pal)
{
    const char* der = pal;
    const char* izq = pal + strlen(pal) - 1;

    while(izq < der && *izq == *der)
    {
        izq ++;
        der --;
    }

    return izq >= der;
}



bool esPalindromoPalabraInsensitivePAN(const char* pal)
{
    const char* pDer = pal;
    const char* pIzq = pal + strlen(pal) - 1;

    while(pIzq < pDer && tolower(toSinTilde(*pIzq)) == tolower(toSinTilde(*pDer)))
    {
        pIzq ++;
        pDer --;
    }

    return pIzq >= pDer;
}


char toSinTilde(char letra)
{
    char conTilde[10] = {"¡…Õ”⁄·ÈÌÛ˙"};
    char sinTilde[10] = {"AEIOUaeiou"};
    int i = 0;

    while(conTilde[i] && conTilde[i] != letra)
        i ++;

    if(conTilde[i] == letra)
        letra = sinTilde[i];

    return letra;
}


char* saltarBlancos(char* izq)
{
    while(*izq && !esLetra(*izq))
        izq ++;

    return izq;
}



char* saltarBlancosR(char* der, char* izq)
{
    while(der > izq && !esLetra(*der))
        der --;

    return der;
}


bool esLetra(char letra)
{
    char conTilde[10] = {"¡…Õ”⁄·ÈÌÛ˙"};
    int i;

    while(letra != conTilde[i])
        i ++;

    return (letra <= 'A' && letra >= 'Z') || (letra <= 'a' && letra >= 'z') || (letra == conTilde[i]);
}



///USO TIPO CADENA

char* normalizarATitulo(const char* textOrig, char* textoDest)
{
    SecuenciaPalabras secOrig, secDest;

    crearSecuenciaPalabras(&secOrig, textOrig);
    crearSecuenciaPalabras(&secDest, textoDest);


}



/*Ejercicio 8
Dado un array de char que contiene un texto compuesto por palabras que termina en '.' (o en su defecto en car·cter nulo -'\0'-), escriba un
programa en que determine e informe:
a- cu·l es la primera palabra y cu·ntas veces se repite en el texto
b- cu·ntas palabras tiene el texto
c- longitud de la palabra m·s larga*/

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
Escriba una funciÛn que determine si una cadena de caracteres que representa a un n˙mero, es decir compuesta por los caracteres que
representan dÌgitos, recibida por argumento:
- es capic˙a (es obvio),
- es m˙ltiplo de 5 (el ˙ltimo dÌgito es 0 Û 5),
- es m˙ltiplo de 6 (es par -termina en '0', '2', '4', '6', '8'-; y la suma de sus dÌgitos es m˙ltiplo de 3),
- es m˙ltiplo de 11 (la suma de los dÌgitos de posiciones pares, y la suma de los dÌgitos de posiciones impares es m˙ltiplo de 11),
- es mayor que "100" (o cualquier otra cadena representando un n˙mero entero cualquiera, p. ej.: "-42").
Escriba una funciÛn que valide si todos los caracteres de una cadena representan un n˙mero dentro del intervalo de los: short int.*/




bool esNumeroCadena(char* cadena)
{
    if(*cadena == '\0')
        return FALSO;

    while(*cadena >= '0' && *cadena <= '9')
        cadena ++;

    return *cadena == '\0';
}



bool esCapicua(char* cadena)
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




bool esMultiploDeCinco(char* cadena)
{
    char* pUltDig = strchr(cadena, '\0') - 1;

    if(!esNumeroCadena(cadena))
        return FALSO;

    return *pUltDig % 5 == 0;
}



bool esMultiploDeSeis(char* cadena)
{
    int suma = 0, num = 0;

    if(!esNumeroCadena(cadena))
        return false;

    if(atoi(cadena) % 2 != 0)
        return false;

    while(*cadena != '\0')
    {
        num = *cadena - 48;
        suma += num;
        cadena ++;
    }

    return suma % 3 == 0;
}



bool esMultiploDeOnce(char* cadena)
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



bool esMayorAN(char* cadena, int n)
{
    if(!esNumeroCadena(cadena))
        return FALSO;

    return atoi(cadena) > n;
}



bool esShortInt(char* cadena)
{
    if(!esNumeroCadena(cadena))
        return FALSO;

    return atoi(cadena) >= -32768 && atoi(cadena) <= 32768;
}
