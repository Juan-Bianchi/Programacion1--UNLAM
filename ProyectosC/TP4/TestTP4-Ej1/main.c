/*Ejercicio 1
Valiéndose de las primitivas de Árbol vistas en clases, escriba un programa que permita cargar información en un árbol binario de
búsqueda. Esta información estará compuesta de: legajo, apellido-y-nombre y cargo (alfanuméricos de 10, 35 y 15 caracteres
respectivamente), fecha de alta y fecha de baja (la fecha de alta no puede faltar a diferencia de la de baja).
Valiéndose de un menú:
Pruebe las primitivas de CargarArbol en ambas versiones (recursiva e iterativa).
Implemente las funciones que recorren el árbol, mostrando la información de sus nodos en las tres formas de recorrido (EnOrden,
PreOrden y PosOrden).
Implemente la función que determina la altura del árbol. Implemente funciones que:
a- muestre los nodos hoja.
b- muestre los nodos no-hoja.
c- muestre los nodos que sólo tienen hijo por izquierda.
d- muestre los nodos que tienen hijo por izquierda.
e- determine si es un árbol semi balanceado (AVL).
f- determine si es un árbol balanceado.
g- elimine todos los nodos de un árbol.
h- 'pode' las ramas de un árbol de modo que no supere una altura determinada. i- 'pode' las ramas de un árbol de una altura determinada
o inferior.
Al terminar el programa, genere un archivo con la información del árbol, haciendo uso de una función que lo recorre en pre orden.*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CANT_VEC 15
#include "Arbol.h"
#include "../../TP1/TP1-TipoFecha/Fecha.h"


typedef struct
{
    char leg[10];
    char apYNom[35];
    char cargo[15];
    tFecha fechaAlta;
    tFecha fechaBaja;
} Empleado;


int compararEmpleado(const void* e1, const void* e2);
void grabarYMostrarArbolEnArch(void* elem, void* arch);
void mostrarElemArbol(const void* elem, int nivel);
void mostrarElemArbolPorNivel(const void* elem, int nivel);
void mostrarNodosConHijosPorIzq(const Arbol* pa, MostrarElemArbol mostrar);
void mostrarNodosConHijosSoloPorIzq(const Arbol* pa, MostrarElemArbol mostrar);


int main()
{
    Empleado vec[CANT_VEC] = {
                         {"10", "Perez Pablo", "Gerente", {1,1,2022}, {0,0,0}},
                         {"5", "Rullo Pablo", "Administrativo", {1,1,2022}, {0,0,0}},
                         {"20", "González Aníbal", "Operario", {1,1,2022}, {0,0,0}},
                         {"2", "Gordillo Alexis", "Operario", {1,1,2022}, {0,0,0}},
                         {"7", "Diana Victor", "Operario", {1,1,2022}, {0,0,0}},
                         {"15", "Castaño Cristian", "Operario", {1,1,2022}, {0,0,0}},
                         {"30", "Ocaranaza Marcos", "Operario", {1,1,2022}, {0,0,0}},
                         {"1", "Gori Adrián", "Operario", {1,1,2022}, {0,0,0}},
                         {"3", "Ardiles Rodrigo", "Operario", {1,1,2022}, {0,0,0}},
                         {"6", "Bianchi Juan", "Operario", {1,1,2022}, {0,0,0}},
                         {"8", "Menendez Javier", "Operario", {1,1,2022}, {0,0,0}},
                         {"12", "Di Guardia Sergio", "Operario", {1,1,2022}, {0,0,0}},
                         {"18", "Marianetti Sergio", "Operario", {1,1,2022}, {0,0,0}},
                         {"25", "Da Silva Rodrigo", "Operario", {1,1,2022}, {0,0,0}},
                         {"50", "Valor Pablo", "Operario", {1,1,2022}, {0,0,0}}
                        };

    Empleado empleado;
    Arbol arbol;

    system("chcp 1252 > NULL");

    crearArbol(&arbol);

    FILE* arch = fopen("Empleados.dat", "wb");
    if(!arch)
        return -1;

    fwrite(vec, sizeof(Empleado), CANT_VEC, arch);
    fclose(arch);


    arch = fopen("Empleados.dat", "rb");
    if(!arch)
        return -1;

    fread(&empleado, sizeof(Empleado), 1, arch);
    while(!feof(arch))
    {
        insertarEnArbol(&arbol, &empleado, sizeof(Empleado), compararEmpleado, NULL);
        fread(&empleado, sizeof(Empleado), 1, arch);
    }


    FILE* archPreorden = fopen("EmpleadosPre.dat", "wb");
    FILE* archPosorden = fopen("EmpleadosPos.dat", "wb");
    FILE* archEnorden = fopen("EmpleadosEnOrd.dat", "wb");

    if(!archEnorden || !archPosorden || !archPreorden)
        return -1;

    puts("Arbol recorrido, impreso y grabado en preorden: ");
    recorrerArbolPreorden(&arbol, grabarYMostrarArbolEnArch, archPreorden);

    puts("\n\nArbol recorrido, impreso y grabado en posorden: ");
    recorrerArbolPosorden(&arbol, grabarYMostrarArbolEnArch, archPosorden);

    puts("\n\nArbol recorrido, impreso y grabado en orden: ");
    recorrerArbolEnOrden(&arbol, grabarYMostrarArbolEnArch, archEnorden);

    puts("\n\n Se mostrará arbol: ");
    graficarArbol(&arbol, mostrarElemArbolPorNivel);

    int alt = alturaArbol(&arbol);
    printf("\n\nLa altura del arbol es: %d\n", alt);

    puts("\n\na) A continuación se mostrarán las hojas del Árbol: ");
    mostrarHojas(&arbol, mostrarElemArbol);

    puts("\n\n Se mostrará arbol: ");
    graficarArbol(&arbol, mostrarElemArbolPorNivel);
    puts("\n\nb) A continuación se mostrarán los nodos no hojas del Árbol: ");
    mostrarNodosNoHojas(&arbol, mostrarElemArbol);

    puts("\n\n Se mostrará arbol: ");
    graficarArbol(&arbol, mostrarElemArbolPorNivel);
    puts("\n\nc) A constinuación se mostrarán los nodos con hijos izquierdos: ");
    mostrarNodosConHijosPorIzq(&arbol, mostrarElemArbol);

    puts("\n\n Se mostrará arbol: ");
    graficarArbol(&arbol, mostrarElemArbolPorNivel);
    puts("\n\nd) A constinuación se mostrarán los nodos SOLO con hijos izquierdos: ");
    mostrarNodosConHijosSoloPorIzq(&arbol, mostrarElemArbol);

    puts("\n\ne) Se mostrará arbol para ver si es AVL: ");
    graficarArbol(&arbol, mostrarElemArbolPorNivel);
    if(esArbolAVL(&arbol))
        puts("\nEl Árbol es AVL!!");
    else
        puts("\nEl Árbol NO es AVL!!");


    puts("\n\nf) Se mostrará arbol para ver si es balanceado: ");
    graficarArbol(&arbol, mostrarElemArbolPorNivel);
    if(esArbolBalanceado(&arbol))
        puts("\nEl Árbol es Balanceado!!");
    else
        puts("\nEl Árbol NO es Balanceado!!");

    int niv;
    printf("\n\nh) Se elegirá un nivel para podar el Árbol (elija el nivel): ");
    fflush(stdin);
    scanf("%d", &niv);
    while(niv < 0 || niv > alt)
    {
        puts("La altura es incorrecta, vuelva a ingresar: ");
        fflush(stdin);
        scanf("%d", &niv);
    }
    podarArbol(&arbol, niv);
    puts("\nSe mostrará arbol: ");
    graficarArbol(&arbol, mostrarElemArbolPorNivel);

    puts("\n\ng) Se vaciará el Árbol: ");
    if(vaciarArbol(&arbol) == 0)
        graficarArbol(&arbol, mostrarElemArbolPorNivel);
    else
        puts("Árbol vacío!!!");


    return 0;
}



int compararEmpleado(const void* e1, const void* e2)
{
    const Empleado* emp1 = e1;
    const Empleado* emp2 = e2;

    return atoi(emp1->leg) - atoi(emp2->leg);
}


void grabarYMostrarArbolEnArch(void* elem, void* arch)
{
    Empleado* emp = elem;

    printf("%-12s%-38s%-18s%4d/%2d/%4d\n", emp->leg, emp->apYNom, emp->cargo, emp->fechaAlta.dia, emp->fechaAlta.mes, emp->fechaAlta.anio);
    fwrite(elem, sizeof(Empleado), 1, arch);
}


void mostrarElemArbol(const void* elem, int nivel)
{
    const Empleado* emp = elem;
    printf("%-12s%-38s%-18s%4d/%2d/%4d\n", emp->leg, emp->apYNom, emp->cargo, emp->fechaAlta.dia, emp->fechaAlta.mes, emp->fechaAlta.anio);
}


void mostrarElemArbolPorNivel(const void* elem, int nivel)
{
    const Empleado* emp = elem;

    for(int i = 0; i < nivel; i++)
        printf("    ");

    printf("%6s\n", emp->leg);
}


void mostrarNodosConHijosPorIzq(const Arbol* pa, MostrarElemArbol mostrar)
{
    if(!*pa)
        return;

    if((*pa)->hIzq)
        mostrar((*pa)->elem, 0);

    mostrarNodosConHijosPorIzq(&(*pa)->hIzq, mostrar);
    mostrarNodosConHijosPorIzq(&(*pa)->hDer, mostrar);
}



void mostrarNodosConHijosSoloPorIzq(const Arbol* pa, MostrarElemArbol mostrar)
{
     if(!*pa)
        return;

    if((*pa)->hIzq && !(*pa)->hDer)
        mostrar((*pa)->elem, 0);

    mostrarNodosConHijosSoloPorIzq(&(*pa)->hIzq, mostrar);
    mostrarNodosConHijosSoloPorIzq(&(*pa)->hDer, mostrar);
}
