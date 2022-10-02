#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Merge.h"

#define CANT_PROD 16

bool abrirArchivo(FILE* arch, char* nombreArch, char* modoAp);
bool mostrarArchivo(char* nombreArch, char* modoAp);
void actualizarStockYAvanzarMov(Producto* prod, Movimiento* mov, FILE* archMovs);
void guardarProdYAvanzarProd(Producto* prod, FILE* archProd, FILE* archProdsTmp);
void cargarNuevoProdYAvanzarMov(FILE* archIndx, FILE* archMovs, Movimiento* mov, BaseDatosProd* basDat, Producto* prodNue, FILE* archProdsTmp);
bool actualizarArchivo(char* nombreArchProd, char* nombreArchMov, char* nombreArchIdx, char* nombreArchBasDat);


int main(int argc, char* argv[])
{
    Idx index[CANT_PROD] = {"00", "01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12", "13", "14", "15"};

    Producto arrProds[6] = {{"00", "Higo", 120.50, 100}, {"04", "Banana", 80.50, 100}, {"07", "Pera", 50.50, 50},
                            {"09", "Manzana", 70.50, 70}, {"10", "Arandano", 60.50, 30}, {"14", "Durazno", 90.50, 90}
                           };

    Movimiento arrMovs[11] = {{"01", 20}, {"07", 20}, {"07", -10}, {"08", 40}, {"10", 40}, {"10", 20}, {"11", 50}, {"12", 60},
                              {"12", -10}, {"15", 80}, {"15", 40}
                             };

    BaseDatosProd baseDatosProd[CANT_PROD] = {{"00", "Higo", 120.5}, {"01", "Kiwi", 100}, {"02", "Limon", 40.5}, {"03", "Damazco", 250.5}, {"04", "Banana", 100},
                                         {"05", "Pomelo", 200}, {"06", "Pelon", 205.5}, {"07", "Pera", 160}, {"08", "Uva", 300}, {"09", "Manzana", 150},
                                         {"10", "Arandano", 100}, {"11", "Mango", 230.5}, {"12", "Naranja", 100}, {"13", "Frutilla", 150}, {"14", "Durazno", 200},
                                         {"15", "Mandarina", 110.5}
                                        };

    FILE* archMovs, * archProd, * archIndx, * archBaseDat;

    system("chcp 1252");

    archIndx = fopen(argv[1], argv[4]);
    if(!abrirArchivo(archIndx, argv[1], argv[4]))
        return -1;

    archMovs = fopen(argv[2], argv[4]);
    if(!abrirArchivo(archMovs, argv[2], argv[4]))
        return -1;

    archProd = fopen(argv[3], argv[4]);
    if(!abrirArchivo(archProd, argv[3], argv[4]))
        return -1;

    archBaseDat = fopen(argv[5], argv[4]);
    if(!abrirArchivo(archBaseDat, argv[5], argv[4]))
        return -1;


    fwrite(index, sizeof(Idx), 16, archIndx);
    fwrite(arrProds, sizeof(Producto), 6, archProd);
    fwrite(arrMovs, sizeof(Movimiento), 11, archMovs);
    fwrite(baseDatosProd, sizeof(BaseDatosProd), 16, archBaseDat);

    fclose(archProd);
    fclose(archMovs);
    fclose(archIndx);
    fclose(archBaseDat);

    puts("Se procederá a el 'Merge' del archivo Productos actualizando con Movimientos, esto se realizará recorriendo los archivos solo una vez: ");

    mostrarArchivo(argv[3], "rb");

    if(!actualizarArchivo(argv[3], argv[2], argv[1], argv[5]))
        puts("El archivo no pudo ser actualizado!!!!");

    mostrarArchivo(argv[3], "rb");

    return 0;
}



bool abrirArchivo(FILE* arch, char* nombreArch, char* modoAp)
{
    if(!arch)
    {
        printf("El archivo '%s' no ha podido ser abierto en modo '%s'. Se cerrará el programa.", nombreArch, modoAp);
        return false;
    }

    return true;
}



bool actualizarArchivo(char* nombreArchProd, char* nombreArchMov, char* nombreArchIdx, char* nombreArchBasDat)
{
    FILE* archMovs, * archProd, * archIndx, * archProdsTmp, *archBasDat;
    BaseDatosProd basDat[16];
    Producto prod, prodNue;
    Movimiento mov;
    int comp;
    char* modoAp = "rb", *nomArchTemp = "Temporal.tmp", *modoEsc = "wb";


    archIndx = fopen(nombreArchIdx, modoAp);
    if(!abrirArchivo(archIndx, nombreArchIdx, modoAp))
        return false;

    archMovs = fopen(nombreArchMov, modoAp);
    if(!abrirArchivo(archMovs, nombreArchMov, modoAp))
        return false;

    archProd = fopen(nombreArchProd, modoAp);
    if(!abrirArchivo(archProd, nombreArchProd, modoAp))
        return false;

    archProdsTmp = fopen(nomArchTemp, modoEsc);
    if(!abrirArchivo(archProdsTmp, nomArchTemp, modoEsc))
        return false;

    archBasDat = fopen(nombreArchBasDat, modoAp);
    if(!abrirArchivo(archBasDat, nombreArchBasDat, modoAp))
        return false;


    fread(basDat, sizeof(BaseDatosProd), 16, archBasDat);
    fclose(archBasDat);

    fread(&prod, sizeof(Producto), 1, archProd);                                                                     ///algoritmo de merge
    fread(&mov, sizeof(Movimiento), 1, archMovs);
    while(!feof(archMovs) && !feof(archProd))
    {
        comp = strcmp(prod.codigo, mov.cod);
        if(comp==0)
            actualizarStockYAvanzarMov(&prod, &mov, archMovs);

        if(comp<0)
            guardarProdYAvanzarProd(&prod, archProd, archProdsTmp);

        if(comp>0)
            cargarNuevoProdYAvanzarMov(archIndx, archMovs, &mov, basDat, &prodNue, archProdsTmp);
    }

    while(!feof(archProd))
        guardarProdYAvanzarProd(&prod, archProd, archProdsTmp);

    while(!feof(archMovs))
        cargarNuevoProdYAvanzarMov(archIndx, archMovs, &mov, basDat, &prodNue, archProdsTmp);                       ///termina algoritmo de merge

    fclose(archMovs);
    fclose(archProd);
    fclose(archProdsTmp);
    fclose(archIndx);

    remove(nombreArchProd);                                                                                         ///elimino archivo original
    rename(nomArchTemp, nombreArchProd);                                                                            ///renombro el temporal con el nombre del original

    return true;
}

void actualizarStockYAvanzarMov(Producto* prod, Movimiento* mov, FILE* archMovs)
{
    prod->stock += mov->mov;
    fread(mov, sizeof(Movimiento), 1, archMovs);
}



void guardarProdYAvanzarProd(Producto* prod, FILE* archProd, FILE* archProdsTmp)
{
    fwrite(prod, sizeof(Producto), 1, archProdsTmp);
    fread(prod, sizeof(Producto), 1, archProd);
}



void cargarNuevoProdYAvanzarMov(FILE* archIndx, FILE* archMovs, Movimiento* mov, BaseDatosProd* basDat, Producto* prodNue, FILE* archProdsTmp)
{
    int i = 0;
    Idx elemInd;

    fread(elemInd, sizeof(Idx), 1, archIndx);                       ///realiza la busqueda en el archivo índice hasta que encuentra el código o se termina el archivo (índice no encontrado)
    while(!feof(archIndx) && strcmp(elemInd, mov->cod) < 0)
    {
        i++;
        fread(&elemInd, sizeof(Idx), 1, archIndx);
    }

    if(strcmp(elemInd, mov->cod) == 0)                              ///si encuentra el código copia la descripción y el precio desde la base de datos
    {
        strcpy(prodNue->descripcion, basDat[i].desc);
        prodNue->precio = basDat[i].precio;
    }
    else
        printf("El número de código '%s' no fue encontrado en el índice por lo que no podrá ser cargada la descripción ni el precio del elemento.\n", mov->cod);

    fseek(archIndx, 0L, SEEK_SET);                                 ///dejo el archivo del índice en el primer registro para una futura busqueda

    strcpy(prodNue->codigo, mov->cod);                             ///copio código y modifico stock desde el archivo Movimientos.dat
    prodNue->stock = mov->mov;

    fread(mov, sizeof(Movimiento), 1, archMovs);
    while(!feof(archMovs) && strcmp(mov->cod, prodNue->codigo) == 0)
    {
        prodNue->stock += mov->mov;
        fread(mov, sizeof(Movimiento), 1, archMovs);
    }

    fwrite(prodNue, sizeof(Producto), 1, archProdsTmp);
}


bool mostrarArchivo(char* nombreArch, char* modoAp)
{
    FILE* archProd;
    Producto prod;

    archProd = fopen(nombreArch, modoAp);
    if(!abrirArchivo(archProd, nombreArch, modoAp))
        return false;

    printf("%-11s%-15s%7s%7s\n", "Código", "Descripción", "Precio", "Stock");
    fread(&prod, sizeof(Producto), 1, archProd);
    while(!feof(archProd))
    {
        printf("%-11s%-15s%7.2f%7d\n", prod.codigo, prod.descripcion, prod.precio, prod.stock);
        fread(&prod, sizeof(Producto), 1, archProd);
    }
    fclose(archProd);
    printf("\n\n\n");

    return true;
}
