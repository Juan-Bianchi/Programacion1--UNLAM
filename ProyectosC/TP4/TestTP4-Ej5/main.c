#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ListaDoble.h"

typedef struct
{
    char cod[7];
    char desc[15];
    char prov[15];
    tFecha fechaCompra;
    tFecha fechaVenc;
    int cant;
    float precComp;
    float precVent;
} Producto;

int compararProducto(const void* prod1, const void* prod2);
void mostrarProd(const void* prod);
void mostrarLista(Lista* pl, Mostrar mostrar);



int main()
{
    FILE* arch;
    Producto prod;
    Lista listaDoble, listaAlIni, listaAlFinal;

    system("chcp 1252 > 0");

    arch = fopen("datos.dat", "r");
    if(!arch)
    {
        puts("El archivo no pudo ser abierto.");
        return -1;
    }

    crearLista(&listaDoble);
    crearLista(&listaAlIni);
    crearLista(&listaAlFinal);

    fread(&prod, sizeof(Producto), 1, arch);

    while(!feof(arch))
    {
        instertarElemEnListaOrdConDup(&listaDoble, &prod, sizeof(Producto), compararProducto);
        insertarAlInicioLista(&listaAlIni, &prod, sizeof(Producto));
        insertarAlFinalLista(&listaAlFinal, &prod, sizeof(Producto));

        fread(&prod, sizeof(Producto), 1, arch);
    }
    puts("Lista ordenada: \n");
    printf("%-9s%19s%12s%14s%20s%18s%18s%11s\n", "Código", "Descripción", "Proveedor", "Fecha compra", "Fecha vencimiento", "Precio compra", "Precio venta", "Cantidad");
    mostrarLista(&listaDoble, mostrarProd);

    puts("\n\nLista con elemento insertados al inicio: \n");
    printf("%-9s%19s%12s%14s%20s%18s%18s%11s\n", "Código", "Descripción", "Proveedor", "Fecha compra", "Fecha vencimiento", "Precio compra", "Precio venta", "Cantidad");
    mostrarLista(&listaAlIni, mostrarProd);

    puts("\n\nLista con elementos insertados al final:\n");
    printf("%-9s%19s%12s%14s%20s%18s%18s%11s\n", "Código", "Descripción", "Proveedor", "Fecha compra", "Fecha vencimiento", "Precio compra", "Precio venta", "Cantidad");
    mostrarLista(&listaAlFinal, mostrarProd);

    printf("\n\nA continuación se procederá a eliminar un elemento, inserte el código: ");
    gets(prod.cod);

    eliminarElemDeListaOrd(&listaDoble, &prod, sizeof(Producto), compararProducto);
    printf("%-9s%19s%12s%14s%20s%18s%18s%11s\n", "Código", "Descripción", "Proveedor", "Fecha compra", "Fecha vencimiento", "Precio compra", "Precio venta", "Cantidad");
    mostrarLista(&listaDoble, mostrarProd);

    printf("\n\nAhora se procederá a buscar un elemento, inserte el código: ");
    gets(prod.cod);

    buscarElementoEnListaOrd(&listaDoble, &prod, sizeof(Producto), compararProducto);
    printf("%-9s%19s%12s%14s%20s%18s%18s%11s\n", "Código", "Descripción", "Proveedor", "Fecha compra", "Fecha vencimiento", "Precio compra", "Precio venta", "Cantidad");
    printf("%-9s%19s%11s%7d/%2d/%-4d%12d/%2d/%-4d%17.2f%17.2f%8d un\n\n", prod.cod, prod.desc, prod.prov, prod.fechaCompra.dia, prod.fechaCompra.mes, prod.fechaCompra.anio, prod.fechaVenc.dia, prod.fechaVenc.mes, prod.fechaVenc.anio, prod.precComp, prod.precVent, prod.cant);


    vaciarLista(&listaAlFinal);
    vaciarLista(&listaAlIni);
    vaciarLista(&listaDoble);

    mostrarLista(&listaDoble, mostrarProd);
    fclose(arch);


    return 0;
}


int compararProducto(const void* prod1, const void* prod2)
{
    const Producto* p1 = prod1;
    const Producto* p2 = prod2;

    return strcmp(p1->cod, p2->cod);
}


void mostrarProd(const void* prod)
{
    const Producto* p = prod;

    printf("%-9s%19s%11s%7d/%2d/%-4d%12d/%2d/%-4d%17.2f%17.2f%8d un\n", p->cod, p->desc, p->prov, p->fechaCompra.dia, p->fechaCompra.mes, p->fechaCompra.anio, p->fechaVenc.dia, p->fechaVenc.mes, p->fechaVenc.anio, p->precComp, p->precVent, p->cant);
}



void mostrarLista(Lista* pl, Mostrar mostrar)
{
    NodoD* act = *pl;

    if(act)
    {
        while(act->ant)
            act = act->ant;

        while(act)
        {
            mostrar(act->elem);
            act = act->sig;
        }
    }
    else
        puts("Pila vacía.");
}
