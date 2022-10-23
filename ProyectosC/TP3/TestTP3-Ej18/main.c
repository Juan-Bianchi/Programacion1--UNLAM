/*Ejercicio 18
Dado un archivo binario (tal como el <"datos"> antes indicado), proceda a ordenarlo valiéndose de dos pilas.*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Pila.h"


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

void procesarOdenamiento(Producto* prod, Pila* pp1, Pila* pp2);
void cargarPilaEnArchivo(FILE* arch, Pila* pp);
void mostrarTitulos();
void mostrarArchivo(FILE* arch);


int main(int argc, char* argv[])
{
    Pila pila1, pila2;
    FILE* arch, * temp;
    Producto prod, aux;

    system("chcp 1252 > NULL");
    arch = fopen(argv[1], argv[2]);
    temp = fopen(argv[4], argv[5]);
    if(!arch)
    {
        printf("El archivo '%s' no ha podido ser abierto en modo '%s', se procederá con el cierre del programa.\n", argv[1], argv[2]);
        return -1;
    }
    if(!temp)
    {
        printf("El archivo '%s' no ha podido ser abierto en modo '%s', se procederá con el cierre del programa.\n", argv[4], argv[5]);
        return -1;
    }

    mostrarTitulos();
    mostrarArchivo(arch);
    fseek(arch, 0L, SEEK_SET);

    crearPila(&pila1);
    crearPila(&pila2);
    puts("\n\nA continuación se procederá a el ordenamiento del archivo por código de producto utilizando dos pilas: \n");
    fread(&prod, sizeof(Producto), 1, arch);
    while(!feof(arch))
    {
        procesarOdenamiento(&prod, &pila1, &pila2);
        fread(&prod, sizeof(Producto), 1, arch);
    }
    while(feof(arch) && desapilar(&pila2, &prod, sizeof(Producto)))
        apilar(&pila1, &prod, sizeof(Producto));

    verTopePila(&pila1, &aux, sizeof(Producto));
    cargarPilaEnArchivo(temp, &pila1);
    fclose(arch);
    fclose(temp);

    rename(argv[4], argv[3]);
    remove(argv[4]);

    arch = fopen(argv[3], argv[2]);
    if(!arch)
    {
        printf("El archivo '%s' no ha podido ser abierto en modo '%s', se procederá con el cierre del programa.\n", argv[3], argv[2]);
        return -1;
    }
    mostrarTitulos();
    mostrarArchivo(arch);

    fclose(arch);

    return 0;
}



void procesarOdenamiento(Producto* prod, Pila* pp1, Pila* pp2)
{
    Producto prodP1;
    Producto prodP2;
    bool hayTop1, hayTop2, prodApilado = false;

    hayTop1 = verTopePila(pp1, &prodP1, sizeof(Producto));
    hayTop2 = verTopePila(pp2, &prodP2, sizeof(Producto));

    if(!hayTop1 && !hayTop2)
    {
        apilar(pp1, prod, sizeof(Producto));
        prodApilado = true;
    }

    while(hayTop1 && hayTop2 && !prodApilado)
    {
        if(strcmp(prod->cod, prodP1.cod) <= 0 && strcmp(prod->cod, prodP2.cod) <= 0)
        {
            apilar(pp1, prod, sizeof(Producto));
            prodApilado = true;
        }

        if(!prodApilado && strcmp(prod->cod, prodP1.cod) <= 0 && strcmp(prod->cod, prodP2.cod) > 0)
        {
            desapilar(pp2, &prodP2, sizeof(Producto));
            apilar(pp1, &prodP2, sizeof(Producto));
            apilar(pp1, prod, sizeof(Producto));
            prodApilado = true;
        }

        if(!prodApilado && strcmp(prod->cod, prodP1.cod) >= 0 && strcmp(prod->cod, prodP2.cod) > 0)
        {
            desapilar(pp1, &prodP1, sizeof(Producto));
            apilar(pp2, &prodP1, sizeof(Producto));
        }

        hayTop1 = verTopePila(pp1, &prodP1, sizeof(Producto));
        hayTop2 = verTopePila(pp2, &prodP2, sizeof(Producto));
    }

    while(hayTop1 && !prodApilado)
    {
        if(strcmp(prod->cod, prodP1.cod) > 0)
        {
            desapilar(pp1, &prodP1, sizeof(Producto));
            apilar(pp2, &prodP1, sizeof(Producto));
            hayTop1 = verTopePila(pp1, &prodP1, sizeof(Producto));
        }
        else
        {
            apilar(pp1, prod, sizeof(Producto));
            prodApilado = true;
        }
    }

    while(hayTop2 && !prodApilado)
    {
        if(strcmp(prod->cod, prodP2.cod) > 0)
        {
            apilar(pp1, prod, sizeof(Producto));
            prodApilado = true;
        }
    }

}



void cargarPilaEnArchivo(FILE* arch, Pila* pp)
{
    Producto prod;

    while(desapilar(pp, &prod, sizeof(Producto)))
        fwrite(&prod, sizeof(Producto), 1, arch);
}

void mostrarTitulos()
{
    printf("%-9s%19s%12s%14s%20s%18s%18s%11s\n", "Código", "Descripción", "Proveedor", "Fecha compra", "Fecha vencimiento", "Precio compra", "Precio venta", "Cantidad");
}


void mostrarArchivo(FILE* arch)
{
    Producto prod;

    fread(&prod, sizeof(Producto), 1, arch);
    while(!feof(arch))
    {
        printf("%-9s%19s%11s%7d/%2d/%-4d%12d/%2d/%-4d%17.2f%17.2f%8d un\n\n", prod.cod, prod.desc, prod.prov, prod.fechaCompra.dia, prod.fechaCompra.mes, prod.fechaCompra.anio, prod.fechaVenc.dia, prod.fechaVenc.mes, prod.fechaVenc.anio, prod.precComp, prod.precVent, prod.cant);
        fread(&prod, sizeof(Producto), 1, arch);
    }

}
