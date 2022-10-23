/*
Ejercicio 12
Se dispone de un archivo como el generado en el [Ejercicio 4]. Se desea generar dos nuevos archivos: en <"datos1"> con los registros cuya clave
comience o termine con un carácter representativo de un dígito, pero en orden contrario al del archivo original, valiéndose de una Pila; y en
<"datos2"> en el mismo orden en que estaban grabados.
El proceso debe ser resuelto con una única lectura del archivo de entrada, mos- trando por pantalla cada registro leído, para luego a la vez que se
genera cada archivo de salida, mostrar qué se graba en cada uno.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Pila.h"
#include "Cola.h"
#define SE_PROCESA 1
#define es_numero(x)    ((x)>='0' && (x)<='9')


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


int estableceCondicionDeProcesamiento(Producto* prod);
void mostrarElem(const void* elem);
void mostrarElemApilado(Pila* pp, Mostrar mostrar);
void mostrarElemEncolado(Cola* pc, Mostrar mostrar);
void procesarArchivoApilado(Pila* pp, FILE* arch);
void procesarArchivoEncolado(Cola* pc, FILE* arch);



int main(int argc, char* argv[])
{
    system("chcp 1252 > 0");

    int cond;
    tFecha f1 = {01, 01, 2022};
    tFecha f2 = {17, 10, 2022};
    Producto vec[10] = {{"1BCBC2", "Rodillera", "BC", f1, f2, 150, 100.5, 500.5},
                        {"12BC01", "Muslera", "BC", f1, f2, 50, 150, 250.5},
                        {"13BC02", "Faja", "BC", f1, f2, 35, 100.5, 500.5},
                        {"1BCBC1", "Walker", "BC", f1, f2, 20, 1000, 1500.5},
                        {"1BCBC3", "Codera", "BC", f1, f2, 44, 330.5, 800},
                        {"16BC02", "Muñequera", "BC", f1, f2, 200, 110, 200.5},
                        {"14BC01", "Tobillera", "BC", f1, f2, 5, 250.5, 300.5},
                        {"1BCBC5", "Gemelera", "BC", f1, f2, 56, 350.5, 800},
                        {"20BC05", "Gel", "BC", f1, f2, 22, 100.5, 109},
                        {"2BCB17", "Remera", "BC", f1, f2, 7, 1100, 1600},
                       };
    FILE* arch, * arch1, * arch2;
    Pila pilaProd;
    Cola colaProd;
    Producto aux;

    crearCola(&colaProd);
    crearPila(&pilaProd);

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
    puts("Se lee del archivo original el siguiente producto: ");

    while(!feof(arch))
    {
        mostrarElem(&aux);
        cond = estableceCondicionDeProcesamiento(&aux);
        if(cond == SE_PROCESA)
        {
            apilar(&pilaProd, &aux, sizeof(Producto));
            //mostrarElemApilado(&pilaProd, mostrarElem);

            encolar(&colaProd, &aux, sizeof(Producto));
            //mostrarElemEncolado(&colaProd, mostrarElem);
        }
        puts("Se lee del archivo original el siguiente producto: ");
        fread(&aux, sizeof(Producto), 1, arch);
    }

    puts("\nA continuación se procederá a la grabación en los archivos según corresponda: \n");
    procesarArchivoApilado(&pilaProd, arch1);
    procesarArchivoEncolado(&colaProd, arch2);

    fclose(arch1);
    fclose(arch2);
    fclose(arch);

    return 0;
}


int estableceCondicionDeProcesamiento(Producto* prod)
{
    char* inicio = prod->cod;
    char* fin = strrchr(prod->cod, '\0');

    if( (es_numero(*inicio) && !es_numero(*(inicio+1))) || (es_numero(*fin-1) && !es_numero(*(fin-2))) )
        return SE_PROCESA;

    return -1;
}



void mostrarElem(const void* elem)
{
    printf("Código: %s\nDescripción: %s\nProveedor: %s\nFecha compra: %2d/%2d/%4d\nFecha vencimiento: %2d/%2d/%4d\nPrecio compra: $%.2f\nPrecio venta: $%.2f\nCantidad: %d un\n\n", ((Producto*)elem)->cod, ((Producto*)elem)->desc, ((Producto*)elem)->prov, ((Producto*)elem)->fechaCompra.dia, ((Producto*)elem)->fechaCompra.mes, ((Producto*)elem)->fechaCompra.anio, ((Producto*)elem)->fechaVenc.dia, ((Producto*)elem)->fechaVenc.mes, ((Producto*)elem)->fechaVenc.anio, ((Producto*)elem)->precComp, ((Producto*)elem)->precVent, ((Producto*)elem)->cant);
}



void mostrarElemApilado(Pila* pp, Mostrar mostrar)
{
    Producto prod;

    if(verTopePila(pp, &prod, sizeof(Producto)))
        mostrar(&prod);
    else
        puts("No se ha podido ver el tope de Pila.");
}



void mostrarElemEncolado(Cola* pc, Mostrar mostrar)
{
    Producto prod;

    if(verFrenteCola(pc, &prod, sizeof(Producto)))
        mostrar(&prod);
    else
        puts("No se ha podido ver el frente de la Cola.");
}



void procesarArchivoApilado(Pila* pp, FILE* arch)
{
    Producto prod;

    puts("\n\nElementos del archivo Apilado:");
    puts("------------------------------");
    while(*pp)
    {
        desapilar(pp, &prod, sizeof(Producto));
        fwrite(&prod, sizeof(Producto), 1, arch);
        mostrarElem(&prod);
    }
}



void procesarArchivoEncolado(Cola* pc, FILE* arch)
{
    Producto prod;

    puts("\n\nElementos del archivo Encolado:");
    puts("-------------------------------");

    while(pc->frente)
    {
        desencolar(pc, &prod, sizeof(Producto));
        fwrite(&prod, sizeof(Producto), 1, arch);
        mostrarElem(&prod);
    }
}
