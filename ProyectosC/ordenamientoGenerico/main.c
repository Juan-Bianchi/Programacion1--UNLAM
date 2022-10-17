#include <stdio.h>
#include <stdlib.h>
#include "ordenamientoGenerico.h"
#define TAM 200

typedef struct
{
    char cod[51];
    char desc[30];
    float precioUni;
    int stock;

} Producto;


void cargarProds(Producto* prods, int* ce, int tamVec);
int cmpProdCod(const void* prod1, const void* prod2);
void mostrarProd(const void* prod);
void mostrarVec(Producto* prods, int ce, MostrarElem mostrarProd);
int cmpProdStockPrecioUni(const void*, const void*);



int main()
{
    int ce = 0;
    Producto prods[TAM];

    system("chcp 1252 > NULL");

    puts("A continuación se procederá a la carga de los productos: ");
    cargarProds(prods, &ce, TAM);
    ordenarSeleccion(prods, ce, sizeof(Producto), cmpProdCod);
    mostrarVec(prods, ce, mostrarProd);

    return 0;
}


void cargarProds(Producto* prods, int* ce, int tamVec)
{
    char cod[51];
    char* condFin = "FIN";
    Producto* fin = prods + tamVec;

    printf("Ingrese el c�digo del producto ('FIN' para terminar): ");
    gets(cod);
    while(prods < fin && strcmp(cod, condFin) != 0)
    {
        strcpy(prods->cod, cod);
        printf("Ingrese la descripci�n del producto: ");
        gets(prods->desc);
        printf("Ingrese el precio unitario del producto: ");
        fflush(stdin);
        scanf("%f", &prods->precioUni);
        printf("Ingrese el stock del producto: ");
        scanf("%d", &prods->stock);
        fflush(stdin);
        prods ++;
        (*ce)++;
        printf("Ingrese el c�digo del producto ('FIN' para terminar): ");
        gets(cod);
    }
}


int cmpProdCod(const void* p1, const void* p2) //compara por codigo de producto
{
    const Producto* prod1=(const Producto*)p1; //puntero a producto lo asigno a puntero a producto real
    const Producto* prod2=(const Producto*)p2;

    return strcmp(prod1->cod, prod2->cod); //strcmp porque son dos cadenas

}


int cmpProdStockPrecioUni(const void* p1, const void* p2) //primero ordena por stock y si son iguales recien ahi por precio unit
{
    const Producto* prod1=(const Producto*)p1;
    const Producto* prod2=(const Producto*)p2;

    int comp=prod1->stock-prod2->stock;

    if(comp) //distinto de cero
        return comp;

    int precioUni1=prod1->precioUni*100; //se transforma en entero
    int precioUni2=prod2->precioUni*100;


    return precioUni1-precioUni2;

}



void mostrarProd(const void* prod)
{
    Producto p = *(Producto*) prod;

    printf("Codigo: %s\nDescripci�n: %s\nPrecio unitario: %.2f\nStock: %d\n\n", p.cod, p.desc, p.precioUni, p.stock);
}



void mostrarVec(Producto* prods, int ce, MostrarElem mostrarProd)
{
    Producto* actual = prods;
    Producto* fin = prods + ce;

    for(; actual < fin; actual ++)
        mostrarProd(actual);
}
