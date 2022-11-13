#include <stdio.h>
#include <stdlib.h>
#define CANT_VEC 14
#define CANT_VEC2 15
#define CANT_VEC3 10


#define TDA_ARBOL_IMPL_DINAMICA

#include "../Nodo/NodoA.h"
#include "../TDAArbol/TDAArbol.h"


int compararEntero(const void* e1, const void* e2);
void mostrarInt(const void* ar, int nivel);


int main()
{
    int vec1 [CANT_VEC] = {10, 5, 20, 2, 7,/* 15,*/ 30, 1, 3, 6, 8, 12, 18, 25, 50};
    int vecAVL [CANT_VEC2] = {10, 5, 2, 1, 7,/* 6, */8, 9, 20, 15, 12, 18, 30, 25, 50, 100};
    int vecBalanc [CANT_VEC3] = {10, 5, 20, 2, 7, 15,/* 30, */1, 3, 8, 12/*, 25*/};

    Arbol aCompl, aAVL, aBalanceado;

    system("chcp 1252 > null");


    /// ARBOL COMPLETO
    crearArbol(&aCompl);

    for(int i=0; i < CANT_VEC; i++)
        insertarEnArbol(&aCompl, &vec1[i], sizeof(int), compararEntero, NULL);

    graficarArbol(&aCompl, mostrarInt);

    if(esArbolCompleto(&aCompl))
        puts("El árbol impreso es completo!!\n");
    else
        puts("El árbol impreso no es completo!!\n");


    ///ARBOL AVL
    crearArbol(&aAVL);
    for(int i=0; i < CANT_VEC2; i++)
        insertarEnArbol(&aAVL, &vecAVL[i], sizeof(int), compararEntero, NULL);

    graficarArbol(&aAVL, mostrarInt);

    if(esArbolAVL(&aAVL))
        puts("El árbol impreso es AVL!!\n");
    else
        puts("El árbol impreso no es AVL!!\n");


    ///ARBOL BALANCEADO
    crearArbol(&aBalanceado);
    for(int i=0; i < CANT_VEC3; i++)
        insertarEnArbol(&aBalanceado, &vecBalanc[i], sizeof(int), compararEntero, NULL);

    graficarArbol(&aBalanceado, mostrarInt);

    if(esArbolAVL(&aBalanceado))
        puts("El árbol impreso es Balanceado!!\n");
    else
        puts("El árbol impreso no es Balanceado!!\n");






    int vec[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Arbol arbolOrdenado;
    FILE* arch;
    arch = fopen("VectorOrdenado.dat", "wb");
    if(!arch)
        return -1;

    for(int i = 0; i < 10; i++)
        fwrite(&vec[i], sizeof(int), 1, arch);

    fclose(arch);

    crearArbol(&arbolOrdenado);
    cargarArbolDesdeArchivoOrdenado(&arbolOrdenado, "VectorOrdenado.dat", sizeof(int), compararEntero, NULL);
    graficarArbol(&arbolOrdenado, mostrarInt);

    return 0;
}



int compararEntero(const void* e1, const void* e2)
{
    const int* ent1 = e1;
    const int* ent2 = e2;

    return *ent1 - *ent2;
}


void mostrarInt(const void* ar, int nivel)
{
    for(int i=0; i < nivel; i++)
        printf("    ");

    printf("%6d\n", *(const int*)ar);
}
