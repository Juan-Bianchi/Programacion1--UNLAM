/*Ejercicio 17
Implemente y pruebe las siguientes funciones de listas en versiones para listas ordenadas/no-ordenadas:
Función iterativa (buscar_cla) que busque por una clave en una lista y recupere la información del nodo con esa clave, devolviendo un indicador
de éxito/fracaso en su cometido, y eliminando o no el nodo encontrado, según lo indique un argumento extra.
Ídem, recursiva.
Función iterativa (contar_cla) que busque y devuelva la cantidad de veces que encontró la clave, y eliminando o no los nodos encontrados, según lo
indique un argumento extra.
Ídem, recursiva.
Función iterativa (buscar_cla_n) que busque por una clave en una lista y recupere la información de la ocurrencia n de la clave indicada.
Ídem, recursiva.*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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



void mostrarTitulos();
void mostrarMenu();
int validaIntEntre(const int inf, const int sup);
char validaChar(const char letra1, const char letra2);
void cargarProd(void* pl, void* prod);
void mostrarProd(const void* prod);
int compararClave(const void* cod, const void* prod2);
bool buscarClaOrd(Lista* pl, const Producto* clave, Cmp compProd, const bool condicion, Accion cargProd, void* prod);
bool buscarClaDesord(Lista* pl, const Producto* clave, Cmp compProd, const bool condicion, Accion cargProd, void* prod);
int contarClaOrd(Lista* pl, const Producto* clave, Cmp compProd, const bool condicion);
int contarClaDesord(Lista* pl, const Producto* clave, Cmp compProd, const bool condicion);
bool buscarClaNOrd(Lista* pl, const Producto* clave, unsigned ocurr, Cmp compProd, Accion cargProd, void* prod);
bool buscarClaNDes(Lista* pl, const Producto* clave, unsigned ocurr, Cmp compProd, Accion cargProd, void* prod);

void mostrarLista(const Lista* pl, Mostrar mostrarPr);

bool buscarClaOrdRecur(Lista* pl, const Producto* clave, Cmp compProd, const bool condicion, Accion cargProd, void* prod);
bool buscarClaDesordRecur(Lista* pl, const Producto* clave, Cmp compProd, const bool condicion, Accion cargProd, void* prod);
int contarClaOrdRecur(Lista* pl, const Producto* clave, Cmp compProd, const bool condicion);
int contarClaDesordRecur(Lista* pl, const Producto* clave, Cmp compProd, const bool condicion);
bool buscarClaNOrdRecur(Lista* pl, const Producto* clave, unsigned ocurr, Cmp compProd, Accion cargProd, void* prod);
bool buscarClaNDesRecur(Lista* pl, const Producto* clave, unsigned ocurr, Cmp compProd, Accion cargProd, void* prod);


int main()
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

    Lista lista, listaOrd;
    int opc;
    unsigned cantOcurr;
    bool condicion;
    char funcion, borrar;
    Producto prod, prodAux;

    crearLista(&lista);
    crearLista(&listaOrd);

    for(int i=0; i<10; i++)
    {
        insertarElementoEnListaDesordConDup(&lista, &vec[i], sizeof(Producto));
        insertarElementoEnListaDesordConDup(&listaOrd, &vec[i], sizeof(Producto));
    }

    ordenarListaInsercion(&listaOrd, compararClave);

    puts("A continuación se mostran las listas sin ordenar y otra ordenada:\n\n");
    mostrarTitulos();
    mostrarLista(&lista, mostrarProd);
    puts("\n");

    mostrarTitulos();
    mostrarLista(&listaOrd, mostrarProd);
    puts("\n");

    mostrarMenu();
    opc = validaIntEntre(1, 7);
    puts("\n");
    while(opc != 7)
    {
        condicion = false;
        cantOcurr = 0;
        printf("Ingrese la clave del producto: ");
        gets(prodAux.cod);
        printf("Ingrese 'I' si quiere utilizar la versión iterativa de la función o 'R' si quiere usar la versión recursiva: ");
        funcion = validaChar('I', 'R');
        if(opc == 1)
        {
            printf("Indique si desea borrar el elemento encontrado de la lista ('S' o 'N'): ");
            borrar = validaChar('S', 'N');
            if(borrar == 'S')
                condicion = true;

            if(funcion == 'I')
                buscarClaOrd(&listaOrd, &prodAux, compararClave, condicion, cargarProd, &prod);
            else
                buscarClaOrdRecur(&listaOrd, &prodAux, compararClave, condicion, cargarProd, &prod);

            if(condicion)
                puts("Elemento eliminado: ");
            else
                puts("Elemento recuperado: ");
            mostrarProd(&prod);
            puts("\n");
            mostrarTitulos();
            mostrarLista(&listaOrd, mostrarProd);
            puts("\n");
        }
        if(opc==2)
        {
            printf("Indique si desea borrar el elemento encontrado de la lista ('S' o 'N'): ");
            borrar = validaChar('S', 'N');
            if(borrar == 'S')
                condicion = true;

            if(funcion == 'I')
                buscarClaDesord(&lista, &prodAux, compararClave, condicion, cargarProd, &prod);
            else
                buscarClaDesordRecur(&lista, &prodAux, compararClave, condicion, cargarProd, &prod);

            if(condicion)
                puts("Elemento eliminado: ");
            else
                puts("Elemento recuperado: ");
            mostrarProd(&prod);
            puts("\n");
            mostrarTitulos();
            mostrarLista(&lista, mostrarProd);
            puts("\n");
        }
        if(opc==3)
        {
            printf("Indique si desea borrar el elemento encontrado de la lista ('S' o 'N'): ");
            borrar = validaChar('S', 'N');
            if(borrar == 'S')
                condicion = true;

            if(funcion == 'I')
                cantOcurr = contarClaOrd(&listaOrd, &prodAux, compararClave, condicion);
            else
                cantOcurr = contarClaOrdRecur(&listaOrd, &prodAux, compararClave, condicion);

            printf("La cantidad de ocurrencias del producto '%s' es %u\n\n", prodAux.cod, cantOcurr);
            puts("\n");
            mostrarTitulos();
            mostrarLista(&listaOrd, mostrarProd);
            puts("\n");
        }
        if(opc==4)
        {
            printf("Indique si desea borrar el elemento encontrado de la lista ('S' o 'N'): ");
            borrar = validaChar('S', 'N');
            if(borrar == 'S')
                condicion = true;

            if(funcion == 'I')
                cantOcurr = contarClaDesord(&lista, &prodAux, compararClave, condicion);
            else
                cantOcurr = contarClaDesordRecur(&lista, &prodAux, compararClave, condicion);

            printf("La cantidad de ocurrencias del producto '%s' es %u\n\n", prodAux.cod, cantOcurr);
            puts("\n");
            mostrarTitulos();
            mostrarLista(&lista, mostrarProd);
            puts("\n");
        }
        if(opc==5)
        {
            printf("Indique que número de ocurrencia desea recuperar (mayor a 0): ");
            fflush(stdin);
            scanf("%u", &cantOcurr);
            fflush(stdin);
            if(funcion == 'I')
                buscarClaNOrd(&listaOrd, &prodAux, cantOcurr, compararClave, cargarProd, &prod);
            else
                buscarClaNOrdRecur(&listaOrd, &prodAux, cantOcurr, compararClave, cargarProd, &prod);
            puts("\n");
            puts("Elemento recuperado: ");
            mostrarProd(&prod);
        }
        if(opc==6)
        {
            printf("Indique que número de ocurrencia desea recuperar (mayor a 0): ");
            fflush(stdin);
            scanf("%u", &cantOcurr);
            fflush(stdin);
            if(funcion == 'I')
                buscarClaNDes(&lista, &prodAux, cantOcurr, compararClave, cargarProd, &prod);
            else
                buscarClaNDesRecur(&lista, &prodAux, cantOcurr, compararClave, cargarProd, &prod);
            puts("\n");
            puts("Elemento recuperado: ");
            mostrarProd(&prod);
        }

        mostrarMenu();
        opc = validaIntEntre(1, 7);
        puts("\n");
    }


    return 0;
}



void mostrarProd(const void* prod)
{
    const Producto* pr = prod;

    printf("%-9s%19s%11s%7d/%2d/%-4d%12d/%2d/%-4d%17.2f%17.2f%8d un\n\n", pr->cod, pr->desc, pr->prov, pr->fechaCompra.dia, pr->fechaCompra.mes, pr->fechaCompra.anio, pr->fechaVenc.dia, pr->fechaVenc.mes, pr->fechaVenc.anio, pr->precComp, pr->precVent, pr->cant);
}



void cargarProd(void* nodo, void* prod)
{
    Nodo* nodProd = nodo;
    memcpy(prod, nodProd->elem, sizeof(Producto));
}


int compararClave(const void* prod1, const void* prod2)
{
    const Producto* p1 = prod1;
    const Producto* p2 = prod2;

    return strcmp(p1->cod, p2->cod);
}



bool buscarClaOrd(Lista* pl, const Producto* clave, Cmp compClav, const bool eliminar, Accion cargProd, void* prod)
{
    Nodo* nae;

    while(*pl && compClav(clave, (*pl)->elem) > 0)
        pl = &(*pl)->sig;

    if(!*pl || compClav(clave, (*pl)->elem) < 0)
        return false;

    if(eliminar)
    {
        nae = *pl;
        *pl = nae->sig;
        destruirNodo(nae, prod, sizeof(Producto));
    }
    else
    {
        nae = *pl;
        cargProd(*pl, prod);
    }


    return true;
}



bool buscarClaDesord(Lista* pl, const Producto* clave, Cmp compClav, const bool eliminar, Accion cargProd, void* prod)
{
    Nodo* nae;

    while(*pl && compClav(clave, (*pl)->elem) != 0)
        pl = &(*pl)->sig;

    if(!*pl)
        return false;

    if(eliminar)
    {
        nae = *pl;
        *pl = nae->sig;
        destruirNodo(nae, prod, sizeof(Producto));
    }
    else
        cargProd(*pl, prod);

    return true;
}



int contarClaOrd(Lista* pl, const Producto* clave, Cmp compClav, const bool eliminar)
{
    Nodo* nae;
    int cont = 0;

    while(*pl && compClav(clave, (*pl)->elem) > 0)
        pl = &(*pl)->sig;

    while(compClav(clave, (*pl)->elem) == 0)
    {
        cont ++;
        if(eliminar)
        {
            nae = *pl;
            *pl = nae->sig;
            free(nae->elem);
            free(nae);
        }
        else
            pl = &(*pl)->sig;
    }

    return cont;
}



int contarClaDesord(Lista* pl, const Producto* clave, Cmp compClav, const bool eliminar)
{
    Nodo* nae;
    int cont = 0;

    while(*pl)
    {
        if(compClav(clave, (*pl)->elem) == 0)
        {
            cont ++;
            if(eliminar)
            {
                nae = *pl;
                *pl = nae->sig;
                free(nae->elem);
                free(nae);
            }
        }
        else
            pl = &(*pl)->sig;
    }

    return cont;
}



bool buscarClaNOrd(Lista* pl, const Producto* clave, unsigned ocurr, Cmp compClav, Accion cargProd, void* prod)
{
    int cont = 0;

    while(*pl && compClav(clave, (*pl)->elem) >= 0)
    {
        if(compClav(clave, (*pl)->elem) == 0)
        {
            cont ++;
            if(cont == ocurr)
            {
                cargProd(*pl, prod);
                return true;
            }
        }
        pl = &(*pl)->sig;
    }
    return false;
}



bool buscarClaNDes(Lista* pl, const Producto* clave, unsigned ocurr, Cmp compClav, Accion cargProd, void* prod)
{
    int cont = 0;

    while(*pl)
    {
        if(compClav(clave, (*pl)->elem) == 0)
        {
            cont ++;
            if(cont == ocurr)
            {
                cargProd(*pl, prod);
                return true;
            }
        }
        pl = &(*pl)->sig;
    }
    return false;
}



void mostrarTitulos()
{
    printf("%-9s%19s%12s%14s%20s%18s%18s%11s\n", "Código", "Descripción", "Proveedor", "Fecha compra", "Fecha vencimiento", "Precio compra", "Precio venta", "Cantidad");
}



void mostrarLista(const Lista* pl, Mostrar mostProd)
{
    while(*pl)
    {
        mostProd((*pl)->elem);
        pl = &(*pl)->sig;
    }
}



void mostrarMenu()
{
    printf("           1-Buscar elemento en lista ordenada.\n\
           2-Buscar elemento en lista desordenada.\n\
           3-Devolver cantidad de veces que se encuentra una clave en lista ordenada.\n\
           4-Devolver cantidad de veces que se encuentra una clave en lista desordenada\n\
           5-Buscar 'n' ocurrencia de una clave en lista ordenada.\n\
           6-Buscar 'n' ocurrencia de una clave en lista desordenada.\n\
           7-Salir.\n\
           Escriba el número de la opción: ");
}


int validaIntEntre(const int inf, const int sup)
{
    int num;

    fflush(stdin);
    scanf("%d", &num);
    fflush(stdin);
    while(num < inf || num > sup)
    {
        printf("El valor ingresado es erroneo, por favor vuelva a ingresar (entre %d y %d): ", inf, sup);
        scanf("%d", &num);
        fflush(stdin);
    }

    return num;
}



char validaChar(const char letra1, const char letra2)
{
    char letra;

    fflush(stdin);
    scanf("%c", &letra);
    letra = toupper(letra);
    while(letra != letra1 && letra != letra2)
    {
        fflush(stdin);
        printf("El caracter ingresado es erroneo, por favor vuelva a ingresar ( '%c' o '%c'): ", letra1, letra2);
        scanf("%c", &letra);
        letra = toupper(letra);
    }

    return letra;
}



bool buscarClaOrdRecur(Lista* pl, const Producto* clave, Cmp compClav, const bool eliminar, Accion cargProd, void* prod)
{
    Nodo* nae;

    if(!*pl || compClav(clave, (*pl)->elem) < 0)
        return false;

    if(compClav(clave, (*pl)->elem) == 0 && eliminar)
    {
        nae = *pl;
        *pl = nae->sig;
        destruirNodo(nae, prod, sizeof(Producto));
        return true;
    }
    if(compClav(clave, (*pl)->elem) == 0 && !eliminar)
    {
        cargProd(*pl, prod);
        return true;
    }

    return buscarClaOrdRecur(&(*pl)->sig, clave, compClav, eliminar, cargProd, prod);
}



bool buscarClaDesordRecur(Lista* pl, const Producto* clave, Cmp compProd, const bool eliminar, Accion cargProd, void* prod)
{
    Nodo* nae;

    if(!*pl)
        return false;

    if(compProd(clave, (*pl)->elem) == 0 && eliminar)
    {
        nae = *pl;
        *pl = nae->sig;
        destruirNodo(nae, prod, sizeof(Producto));
        return true;
    }
    if(compProd(clave, (*pl)->elem) == 0 && !eliminar)
    {
        cargProd(*pl, prod);
        return true;
    }

    return buscarClaDesordRecur(&(*pl)->sig, clave, compProd, eliminar, cargProd, prod);
}



int contarClaOrdRecur(Lista* pl, const Producto* clave, Cmp compClav, const bool eliminar)
{
    Nodo* nae;

    if(!*pl || compClav(clave, (*pl)->elem) < 0)
        return 0;

    if(*pl && compClav(clave, (*pl)->elem) == 0)
    {
        if(eliminar)
        {
            nae = *pl;
            *pl = nae->sig;
            free(nae->elem);
            free(nae);
            return 1 + contarClaDesordRecur(pl, clave, compClav, eliminar);
        }
        else
            return 1 + contarClaDesordRecur(&(*pl)->sig, clave, compClav, eliminar);
    }

    return 0 + contarClaOrdRecur(&(*pl)->sig, clave, compClav, eliminar);
}



int contarClaDesordRecur(Lista* pl, const Producto* clave, Cmp compClav, const bool eliminar)
{
    Nodo* nae;

    if(!*pl)
        return 0;

    if(*pl && compClav(clave, (*pl)->elem) == 0)
    {
        if(eliminar)
        {
            nae = *pl;
            *pl = nae->sig;
            free(nae->elem);
            free(nae);
            return 1 + contarClaDesordRecur(pl, clave, compClav, eliminar);
        }
        else
            return 1 + contarClaDesordRecur(&(*pl)->sig, clave, compClav, eliminar);
    }

    return 0 + contarClaDesordRecur(&(*pl)->sig, clave, compClav, eliminar);
}



bool buscarClaNOrdRecur(Lista* pl, const Producto* clave, unsigned ocurr, Cmp compClav, Accion cargProd, void* prod)
{

    if(!*pl || compClav(clave, (*pl)->elem) < 0)
        return false;

    if(*pl && compClav(clave, (*pl)->elem) == 0)
    {
        ocurr --;
        if(ocurr == 0)
        {
            cargProd(*pl, prod);
            return true;
        }
    }
    return buscarClaNOrdRecur(&(*pl)->sig, clave, ocurr, compClav, cargProd, prod);
}



bool buscarClaNDesRecur(Lista* pl, const Producto* clave, unsigned ocurr, Cmp compClav, Accion cargProd, void* prod)
{
    if(!*pl)
        return false;

    if(*pl && compClav(clave, (*pl)->elem) == 0)
    {
        ocurr --;
        if(ocurr == 0)
        {
            cargProd(*pl, prod);
            return true;
        }
    }

    return buscarClaNDesRecur(&(*pl)->sig, clave, ocurr, compClav, cargProd, prod);
}
