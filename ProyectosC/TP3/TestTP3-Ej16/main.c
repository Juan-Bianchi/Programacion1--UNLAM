/*Ejercicio 16
Implemente un programa que le permita cargar el archivo <"datos"> en una Lista dinámica. En la información a cargar no se debe incluir el
nombre del proveedor.
Pruebe las siguientes alternativas:
a- Insertar los nuevos nodos al final de la lista, salvo que la clave ya estuviera cargada y la descripción coincide, con lo cual se acumula la
cantidad, se retiene la última fecha de compra y la fecha de vencimiento más vieja, el mayor precio de compra y de venta; si la descripción no
coincidiera, se genera un nuevo nodo. Eliminar todos los nodos cuya clave está más de una vez, mostrando su información por pantalla y grabándolos
en un archivo de texto <"errores2"> (tienen distinta descripción). Ordenar la lista resultante, y luego grabar esta información en un nuevo
archivo binario <"depurado">.
b- Insertar los nuevos nodos ordenados por clave y a igualdad de clave por descripción, salvo que esta clave compuesta coincida con lo que se
procede a acumular igual que antes. Eliminar todos los nodos cuya clave está más de una vez, mostrando su información por pantalla y grabándolos
en un archivo de texto < "errores2"> (tienen distinta descripción). Grabar esta información en un nuevo archivo <"depurado2">.*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


typedef struct
{
    char cod[7];
    char desc[15];
    tFecha fechaCompra;
    tFecha fechaVenc;
    int cant;
    float precComp;
    float precVent;
} ProductoDep;

void cargaArchivoALista(FILE* arch, Lista* pl, Producto* prod, ProductoDep* prodDep, FILE* archTxt);
int compararProd(const void* prod1, const void* prod2);
void guardarEnArchTxt(void* elem, void* file);
void sumarCantidadesEnDuplicados(Lista* pl, ProductoDep* prod, Cmp compararProd);
void eliminarDuplicadoErroneo(Lista* pl, Cmp cmp, Accion accion, void* datosAccion);
void listaADepurado(Lista* pl, FILE* archDep);
void mostrarArchivo(FILE* archBin);
void mostrarTitulos();

int main(int argc, char* argv[])
{
    system("chcp 1252 > 0");

    tFecha f1 = {01, 01, 2022};
    Producto vec[10] = {{"BC1102", "Rodillera", "BC", f1, {10, 01, 2022}, 150, 100.5, 500.5},
                        {"BC1201", "Muslera", "BC", f1, {01, 02, 2022}, 50, 150, 250.5},
                        {"BC1302", "Faja", "BC", f1, {20, 01, 2022}, 35, 100.5, 500.5},
                        {"BC1201", "Walker", "BC", f1, {01, 03, 2022}, 20, 1000, 1500.5},
                        {"BC1102", "Rodillera", "BC", f1, {10, 01, 2022}, 44, 330.5, 800},
                        {"BC1602", "Muñequera", "BC", f1, {01, 04, 2022}, 200, 110, 200.5},
                        {"BC1302", "Faja", "Gelform", f1, {20, 01, 2022}, 5, 250.5, 300.5},
                        {"BC1302", "Gemelera", "BC", f1, {01, 05, 2022}, 56, 350.5, 800},
                        {"BC1102", "Rodillera", "ABC", f1, {01, 05, 2022}, -22, 100.5, 109},
                        {"BC2017", "Remera", "Gelform", f1, {20, 01, 2022}, 7, 1100, 1600},
                       };
    FILE* arch, * archTxt, * archDep, * archDep2;
    Lista listaProd;
    Producto prod;
    ProductoDep prodDep;

    crearLista(&listaProd);

    arch = fopen(argv[1], argv[4]);
    if(!arch)
    {
        printf("Error al abrir el archivo '%s' en modo '%s'. Se cerrará el programa: ", argv[1], argv[4]);
        return -1;
    }

    fwrite(vec, sizeof(Producto), 10, arch);
    fclose(arch);

    puts("Se procederá a la lectura del archivo y su posterior procesamiento: \n");
    arch = fopen(argv[1], argv[5]);
    archTxt = fopen(argv[2], argv[6]);
    archDep = fopen(argv[3], argv[4]);
    archDep2 = fopen(argv[7], argv[4]);

    if(!arch || !archTxt || !archDep || !archDep2)
    {
        puts("Error al abrir el archivo. Se cerrará el programa: ");
        return -1;
    }

    cargaArchivoALista(arch, &listaProd, &prod, &prodDep, archTxt);
    eliminarDuplicadoErroneo(&listaProd, compararProd, guardarEnArchTxt, archTxt);

    listaADepurado(&listaProd, archDep);

    fclose(arch);
    fclose(archTxt);
    fclose(archDep);

    ordenarListaInsercion(&listaProd, compararProd);
    listaADepurado(&listaProd, archDep2);
    fclose(archDep2);


    archDep = fopen(argv[3], argv[5]);
    archDep2 = fopen(argv[7], argv[5]);

    if(!archDep || !archDep2)
    {
        puts("Error al abrir el archivo. Se cerrará el programa: ");
        return -1;
    }

    puts("\n\nSe mostrará el primer archivo depurado desordenado: \n");
    mostrarTitulos();
    mostrarArchivo(archDep);

    puts("\n\nSe mostrará el segundo archivo depurado ordenado: \n");
    mostrarTitulos();
    mostrarArchivo(archDep2);

    fclose(archDep);
    fclose(archDep2);

    return 0;
}



void cargaArchivoALista(FILE* arch, Lista* pl, Producto* prod, ProductoDep* prodDep, FILE* archTxt)
{
    fread(prod, sizeof(Producto), 1, arch);
    while(!feof(arch))
    {
        strcpy(prodDep->cod, prod->cod);
        strcpy(prodDep->desc, prod->desc);
        prodDep->fechaCompra = prod->fechaCompra;
        prodDep->fechaVenc = prod->fechaVenc;
        prodDep->precComp = prod->precComp;
        prodDep->precVent = prod->precVent;
        prodDep->cant = prod->cant;

        sumarCantidadesEnDuplicados(pl, prodDep, compararProd);
        fread(prod, sizeof(Producto), 1, arch);
    }
}


int compararProd(const void* prod1, const void* prod2)
{
    const ProductoDep* p1 = prod1;
    const ProductoDep* p2 = prod2;

    int compCod = strcmp(p1->cod, p2->cod);

    if(compCod==0)
        return strcmp(p1->desc, p2->desc);

    return compCod;
}



void guardarEnArchTxt(void* elem, void* file)
{
    char* formato = "%-9s%19s%7d/%2d/%-4d%12d/%2d/%-4d%17.2f%17.2f%8d un\n\n";
    ProductoDep* prod = elem;

    fprintf(file, formato, prod->cod, prod->desc, prod->fechaCompra.dia, prod->fechaCompra.mes, prod->fechaCompra.anio, prod->fechaVenc.dia, prod->fechaVenc.mes, prod->fechaVenc.anio, prod->precComp, prod->precVent, prod->cant);
}


void sumarCantidadesEnDuplicados(Lista* pl, ProductoDep* prod, Cmp compararProd)
{
    bool dupEncont = false;
    ProductoDep* p2;

    while(*pl)
    {
        if(compararProd(prod, (*pl)->elem) == 0)
        {
            p2 = (*pl)->elem;
            p2->cant += prod->cant;
            dupEncont = true;
        }
        pl = &(*pl)->sig;
    }
    if(!dupEncont)
        insertarAlFinalListaDesord(pl, prod, sizeof(ProductoDep));
}



void eliminarDuplicadoErroneo(Lista* pl, Cmp cmp, Accion guardarEnTxt, void* archTxt)
{
    bool dupElim;
    Lista* pRecor;
    ProductoDep* prod, * aux,  ij;
    Nodo* nae;

    while(*pl)
    {
        pRecor = &(*pl)->sig;
        prod = (*pl)->elem;
        while(*pRecor)
        {
            aux = (*pRecor)->elem;
            if(cmp(prod, (*pRecor)->elem) != 0 && strcmp(prod->cod, aux->cod) == 0)
            {
                fprintf(archTxt, "%-9s%19s%14s%20s%18s%18s%11s\n", "Código", "Descripción", "Fecha compra", "Fecha vencimiento", "Precio compra", "Precio venta", "Cantidad");
                guardarEnTxt(aux, archTxt);
                nae = *pRecor;
                *pRecor = nae->sig;

                destruirNodo(nae, &ij, sizeof(ProductoDep));
                dupElim = true;
            }
            pRecor = &(*pRecor)->sig;
        }
        if(dupElim)
        {
            guardarEnTxt(prod, archTxt);
            nae = *pl;
            *pl = nae->sig;
            destruirNodo(nae, &ij, sizeof(ProductoDep));
        }
        else
            pl = &(*pl)->sig;
        dupElim = false;

    }
}



void listaADepurado(Lista* pl, FILE* archDep)
{
    while(*pl)
    {
        fwrite((*pl)->elem, sizeof(ProductoDep), 1, archDep);
        pl = &(*pl)->sig;
    }
}



void mostrarArchivo(FILE* archBin)
{
    ProductoDep prod;

    fread(&prod, sizeof(ProductoDep), 1, archBin);
    while(!feof(archBin))
    {
        printf("%-9s%19s%7d/%2d/%-4d%12d/%2d/%-4d%17.2f%17.2f%8d un\n\n", prod.cod, prod.desc, prod.fechaCompra.dia, prod.fechaCompra.mes, prod.fechaCompra.anio, prod.fechaVenc.dia, prod.fechaVenc.mes, prod.fechaVenc.anio, prod.precComp, prod.precVent, prod.cant);
        fread(&prod, sizeof(ProductoDep), 1, archBin);
    }
}



void mostrarTitulos()
{
    printf("%-9s%19s%16s%20s%18s%18s%11s\n", "Código", "Descripción", "Fecha compra", "Fecha vencimiento", "Precio compra", "Precio venta", "Cantidad");
}
