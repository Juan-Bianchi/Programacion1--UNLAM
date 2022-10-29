#ifndef NODOA_H
#define NODOA_H


typedef struct sNodoA
{
    void* elem;
    size_t tamElem;
    struct sNodoA* hIzq;
    struct sNodoA* hDer;
} NodoA;

#endif // NODOA_H
