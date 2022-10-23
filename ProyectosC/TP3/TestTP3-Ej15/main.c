#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../TP1/TP1-TipoFecha/Fecha.h"
#include "Lista.h"


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

int comparaProd(const void* prod1, const void* prod2);
void mostrarTitulos();
void mostrarProducto(const void* prod);
void guardarEnArch(void* pl, void* arch);


int main(int argc, char* argv[])
{
    system("chcp 1252 > 0");

    tFecha f1 = {01, 01, 2022};
    Producto vec[10] = {{"1BCBC2", "Rodillera", "BC", f1, {10, 01, 2022}, 150, 100.5, 500.5},
                        {"12BC01", "Muslera", "BC", f1, {01, 02, 2022}, 50, 150, 250.5},
                        {"13BC02", "Faja", "BC", f1, {20, 01, 2022}, 35, 100.5, 500.5},
                        {"1BCBC1", "Walker", "BC", f1, {01, 03, 2022}, 20, 1000, 1500.5},
                        {"1BCBC3", "Codera", "BC", f1, {10, 01, 2022}, 44, 330.5, 800},
                        {"16BC02", "Muñequera", "BC", f1, {01, 04, 2022}, 200, 110, 200.5},
                        {"14BC01", "Tobillera", "Gelform", f1, {20, 01, 2022}, 5, 250.5, 300.5},
                        {"1BCBC5", "Gemelera", "BC", f1, {01, 05, 2022}, 56, 350.5, 800},
                        {"20BC05", "Gel", "ABC", f1, {01, 05, 2022}, 22, 100.5, 109},
                        {"2BCB17", "Remera", "Gelform", f1, {20, 01, 2022}, 7, 1100, 1600},
                       };
    FILE* arch, * arch1, * arch2;
    Lista lista1Prod;
    Lista lista2Prod;
    Producto aux;

    crearLista(&lista1Prod);
    crearLista(&lista2Prod);

    arch = fopen(argv[1], argv[2]);
    if(!arch)
    {
        printf("Error al abrir el archivo '%s' en modo '%s'. Se cerrará el programa: ", argv[1], argv[2]);
        return -1;
    }

    fwrite(vec, sizeof(Producto), 10, arch);
    fclose(arch);

    puts("Se procederá a la lectura del archivo y su posterior procesamiento: \n");
    arch = fopen(argv[1], argv[3]);
    arch1 = fopen(argv[4], argv[2]);
    arch2 = fopen(argv[5], argv[2]);

    if(!arch)
    {
        puts("Error al abrir el archivo. Se cerrará el programa: ");
        return -1;
    }

    fread(&aux, sizeof(Producto), 1, arch);
    while(!feof(arch))
    {
        insertarElementoEnListaOrd(&lista1Prod, &aux, sizeof(Producto), comparaProd);
        insertarElementoAlInicio(&lista2Prod, &aux, sizeof(Producto), comparaProd);
        fread(&aux, sizeof(Producto), 1, arch);
    }

    puts("A continuación se procederá a imprimir ambas listas; la primera será la que se inserta ordenada y la siguiente es la que inserta los elementos al inicio de la misma: \n\n");
    mostrarTitulos();
    mostrarLista(&lista1Prod, mostrarProducto);
    puts("\n");
    mostrarTitulos();
    mostrarLista(&lista2Prod, mostrarProducto);

    puts("\n\nAhora se ordenará la lista desordenada usando el algoritmo de inserción y luego se imprimirá: \n");
    ordenarListaInsercion(&lista2Prod, comparaProd);
    mostrarTitulos();
    mostrarLista(&lista2Prod, mostrarProducto);

    recorrerLista(&lista1Prod, guardarEnArch, arch1);
    recorrerLista(&lista2Prod, guardarEnArch, arch2);

    fclose(arch1);
    fclose(arch2);
    fclose(arch);

    return 0;
}


int comparaProd(const void* prod1, const void* prod2)
{
    const tFecha* fp1 = &((Producto*)prod1)->fechaVenc;
    const tFecha* fp2 = &((Producto*)prod2)->fechaVenc;
    int dif = esMenorIgualOMayorFecha(fp1, fp2);

    if(dif!=0)
        return dif;

    dif = strcmp(((Producto*)prod1)->prov, ((Producto*)prod2)->prov);
    return (dif!=0)? dif: strcmp(((Producto*)prod1)->cod, ((Producto*)prod2)->cod);
}



void mostrarTitulos()
{
     printf("%-9s%19s%12s%14s%20s%18s%18s%11s\n", "Código", "Descripción", "Proveedor", "Fecha compra", "Fecha vencimiento", "Precio compra", "Precio venta", "Cantidad");
}



void mostrarProducto(const void* elem)
{
     printf("%-9s%19s%11s%7d/%2d/%4d%12d/%2d/%4d$%17.2f$%17.2f%8d un\n\n", ((Producto*)elem)->cod, ((Producto*)elem)->desc, ((Producto*)elem)->prov, ((Producto*)elem)->fechaCompra.dia, ((Producto*)elem)->fechaCompra.mes, ((Producto*)elem)->fechaCompra.anio, ((Producto*)elem)->fechaVenc.dia, ((Producto*)elem)->fechaVenc.mes, ((Producto*)elem)->fechaVenc.anio, ((Producto*)elem)->precComp, ((Producto*)elem)->precVent, ((Producto*)elem)->cant);
}



void guardarEnArch(void* pl, void* arch)
{
    fwrite(pl, sizeof(Producto), 1, (FILE*)arch);
}

