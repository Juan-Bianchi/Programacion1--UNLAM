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

