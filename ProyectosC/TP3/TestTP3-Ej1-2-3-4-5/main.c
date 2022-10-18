#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define TDA_PILA_ESTATICA
#include "Pila.h"

int comparaEntero(const void* elem1, const void* elem2);
int comparaFloat(const void* elem1, const void* elem2);
bool cargaArchivoEnPila(Pila* pp, FILE* arch);
void mostrarMenu();
int validaIntEntre(const int inf, const int sup, Cmp cmp);
float validaFloatMayorA(float inf, Cmp cmp);
int validaIntMayA(const int inf, Cmp cmp);
void mostrarProd(const void* elem);
int realizarAcciones(Pila* pp);
bool cargarPilaEnArch(Pila* pp, FILE* arch);
void mostrarArchivo(FILE* arch);


int main(int argc, char* argv[])
{
    system("chcp 1252 > 0");
    tFecha f1 = {01, 01, 2022};
    tFecha f2 = {17, 10, 2022};
    Producto vec[10] = {{"BC1102", "Rodillera", "BC", f1, f2, 150, 100.5, 500.5},
                        {"BC1201", "Muslera", "BC", f1, f2, 50, 150, 250.5},
                        {"BC1302", "Faja", "BC", f1, f2, 35, 100.5, 500.5},
                        {"BC1451", "Walker", "BC", f1, f2, 20, 1000, 1500.5},
                        {"BC1502", "Codera", "BC", f1, f2, 44, 330.5, 800},
                        {"BC1602", "Muñequera", "BC", f1, f2, 200, 110, 200.5},
                        {"BC1401", "Tobillera", "BC", f1, f2, 5, 250.5, 300.5},
                        {"BC1853", "Gemelera", "BC", f1, f2, 56, 350.5, 800},
                        {"BC2005", "Gel", "BC", f1, f2, 22, 100.5, 109},
                        {"BC2017", "Remera", "BC", f1, f2, 7, 1100, 1600},
    };
    FILE* arch;
    Pila pilaProd;


    arch = fopen(argv[1], argv[2]);
    if(!arch)
    {
        printf("Error al abrir el archivo '%s' en modo '%s'. Se cerrará el programa: ", argv[1], argv[2]);
        return -1;
    }

    crearPila(&pilaProd);
    fwrite(vec, sizeof(Producto), 10, arch);
    if(!cargaArchivoEnPila(&pilaProd, arch))
    {
        puts("La pila no ha podido ser cargada desde el archivo. Se procederá al cierre del programa.");
        return -1;
    }
    puts("Se cargó positivamente el archivo en la pila. A continuación se procederá a realizar modificaciones: \n");
    fseek(arch, 0L, SEEK_SET);

    mostrarMenu();
    realizarAcciones(&pilaProd);


    if(!cargarPilaEnArch(&pilaProd, arch))
    {
        puts("No se ha podido cargar la pila en el archivo. Se eliminará el archivo ya que esta vacío.");
        fclose(arch);
        remove(argv[1]);
        return -1;
    }

    fseek(arch, 0L, SEEK_SET);
    mostrarArchivo(arch);
    fclose(arch);


    return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool cargaArchivoEnPila(Pila* pp, FILE* arch)
{
    Producto prod;
    short int cont = 0;

    fseek(arch, 0L, SEEK_SET);
    fread(&prod, sizeof(Producto), 1, arch);
    while(!feof(arch) && apilar(pp, &prod, sizeof(Producto)))
    {
        printf("Producto %d cargado.\n", ++cont);
        fread(&prod, sizeof(Producto), 1, arch);
    }
    if(!feof(arch))
        return false;

    return true;
}



void mostrarMenu()
{
    printf("1- Cargar información.\n2- Ver Tope de Pila.\n3- Desapilar.\n4- Salir del Menú.\n\nIngrese su opción: ");
}



int realizarAcciones(Pila* pp)
{
    int cod;
    Producto prod;

    cod = validaIntEntre(1, 4, comparaEntero);
    while(cod != 4)
    {
        if(cod == 1)
        {
            printf("Ingrese el código del producto (hasta 6 caract): ");
            gets(prod.cod);
            printf("Ingrese la descripción del producto (hasta 14 caract): ");
            gets(prod.desc);
            printf("Ingrese el proveedor del producto (hasta 14 caract): ");
            gets(prod.prov);
            printf("Ingrese la fecha de compra de la mercaderia (dd/mm/aaaa): ");
            fflush(stdin);
            scanf("%d/%d/%d", &prod.fechaCompra.dia, &prod.fechaCompra.mes, &prod.fechaCompra.anio);
            fflush(stdin);
            while(!esFechaValida((const tFecha*)&prod.fechaCompra))
            {
                printf("La fecha ingresada no es válida, vuelva a ingresarla (dd/mm/aaaa): ");
                scanf("%d/%d/%d", &prod.fechaCompra.dia, &prod.fechaCompra.mes, &prod.fechaCompra.anio);
                fflush(stdin);
            }
            printf("Ingrese la fecha de venta de la mercaderia (dd/mm/aaaa): ");
            fflush(stdin);
            scanf("%d/%d/%d", &prod.fechaVenc.dia, &prod.fechaVenc.mes, &prod.fechaVenc.anio);
            fflush(stdin);
            while(!esFechaValida((const tFecha*)&prod.fechaVenc))
            {
                printf("La fecha ingresada no es válida, vuelva a ingresarla (dd/mm/aaaa): ");
                scanf("%d/%d/%d", &prod.fechaVenc.dia, &prod.fechaVenc.mes, &prod.fechaVenc.anio);
                fflush(stdin);
            }
            printf("Ingrese el precio de compra (mayor a 0): ");
            prod.precComp = validaFloatMayorA(0, comparaFloat);
            printf("Ingrese el precio de venta (mayor a 0): ");
            prod.precVent = validaFloatMayorA(0, comparaFloat);
            printf("Ingrese stock (mayor a -1): ");
            prod.cant = validaIntMayA(-1, comparaEntero);

            apilar(pp, &prod, sizeof(Producto));
            puts("Producto apilado: ");
            mostrarProd(&prod);
        }

        if(cod == 2)
        {
            if(!verTopePila(pp, &prod, sizeof(Producto)))
                puts("No se pudo ver el tope de la pila.");
            puts("El tope de la pila es el siguiente: ");
            mostrarProd(&prod);
        }

        if(cod == 3)
        {
            if(!desapilar(pp, &prod, sizeof(Producto)))
                puts("No se pudo desapilar el elemento.");
            puts("El elemento desapilado es: ");
            mostrarProd(&prod);
        }

        mostrarMenu();
        cod = validaIntEntre(1, 4, comparaEntero);
    }
    return cod;
}



bool cargarPilaEnArch(Pila* pp, FILE* arch)
{
    Producto prod;

    if(pilaVacia(pp))
        return false;

    while(desapilar(pp, &prod, sizeof(Producto)))
        fwrite(&prod, sizeof(Producto), 1, arch);

    return true;
}



void mostrarArchivo(FILE* arch)
{
    Producto prod;
    unsigned cont = 0;

    fread(&prod, sizeof(Producto), 1, arch);
    while(!feof(arch))
    {
        printf("Producto %d: \n", ++cont);
        mostrarProd(&prod);
        fread(&prod, sizeof(Producto), 1, arch);
    }
}


int comparaEntero(const void* elem1, const void* elem2)
{
    return *(const int*)elem1 - *(const int*)elem2;
}



int comparaFloat(const void* elem1, const void* elem2)
{
    float compara = *(const float*)elem1 - *(const float*)elem2;

    if(compara == 0)
        return 0;
    if(compara < 0)
        return -1;

    return 1;
}


float validaFloatMayorA(float inf, Cmp cmp)
{
    float num;

    fflush(stdin);
    scanf("%f", &num);
    fflush(stdin);
    while(cmp(&num, &inf) < 0)
    {
        printf("El número ingresado es erroneo, vuelva a ingresar: ");
        scanf("%f", &num);
        fflush(stdin);
    }

    return num;
}


int validaIntMayA(const int inf, Cmp cmp)
{
    int num;

    fflush(stdin);
    scanf("%d", &num);
    fflush(stdin);
    while(cmp(&num, &inf) < 0)
    {
        printf("El número ingresado es erroneo, vuelva a ingresar: ");
        scanf("%d", &num);
        fflush(stdin);
    }

    return num;
}


int validaIntEntre(const int inf, const int sup, Cmp cmp)
{
    int num;

    fflush(stdin);
    scanf("%d", &num);
    fflush(stdin);
    while(cmp(&num, &inf) < 0 || cmp(&num, &sup) > 0)
    {
        printf("El número ingresado es erroneo, vuelva a ingresar: ");
        scanf("%d", &num);
        fflush(stdin);
    }

    return num;
}


void mostrarProd(const void* elem)
{
    printf("Código: %s\nDescripción: %s\nProveedor: %s\nFecha compra: %2d/%2d/%4d\nFecha venta: %2d/%2d/%4d\nPrecio compra: $%.2f\nPrecio venta: $%.2f\nCantidad: %d un\n\n", ((Producto*)elem)->cod, ((Producto*)elem)->desc, ((Producto*)elem)->prov, ((Producto*)elem)->fechaCompra.dia, ((Producto*)elem)->fechaCompra.mes, ((Producto*)elem)->fechaCompra.anio, ((Producto*)elem)->fechaVenc.dia, ((Producto*)elem)->fechaVenc.mes, ((Producto*)elem)->fechaVenc.anio, ((Producto*)elem)->precComp, ((Producto*)elem)->precVent, ((Producto*)elem)->cant);
}
