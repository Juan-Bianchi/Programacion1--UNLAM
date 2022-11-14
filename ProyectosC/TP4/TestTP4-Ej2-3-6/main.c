/*Ejercicio 2
Valiéndose de un árbol en el que sólo almacena la clave y el número de registro que le corresponde en el archivo, escriba un programa que intente
abrir un archivo, y si lo puede abrir, haga la carga del árbol. La información a tratar es la del ejercicio anterior.
A continuación, haciendo uso de un menú, que permita:
a- agregar nuevos registros de información (siempre que la clave no exista en el árbol), agregando el registro al final del archivo y su clave y
número de registro en el árbol.
b- que permita ingresar la clave, para buscarla en el árbol y con el número de registro muestre la información del archivo.
c- que, recorriendo el árbol, muestre la información de los registros del archivo en orden.
d- ídem en preorden.
e- ídem en posorden.
f- ídem [b-], pero para asignar la fecha de baja.
Al terminar el programa, debe generar un nuevo archivo ordenado por la clave.*/



#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define CANT_VEC 15

#include "Arbol.h"
#include "../../TP1/TP1-TipoFecha/Fecha.h"


typedef struct
{
    char leg[10];
    unsigned long nroReg;
} Indice;

typedef struct
{
    char leg[10];
    char apYNom[35];
    char cargo[15];
    tFecha fechaAlta;
    tFecha fechaBaja;
} Empleado;

void mostrarEmpleado(const Empleado* emp);
void leerArchivoUsandoIndice(void* elem, void* archComp);
void grabarEnArchivoUsandoIndice(void* elem, void* archComp);
int compararIndices(const void* i1, const void* i2);
void mostrarElemArchiv(const void* reg, int nivel);
void mostrarMenu();
void procesarOpciones(Arbol* pa, char* nombreArchInd, char* nombreArchCompleto, Cmp cmp);
int grabarArchivoOrdenado(Arbol* pa, const char* nombreArchComp);


int main()
{
    Indice vec1[CANT_VEC] = {
                             {"1", 7}, {"2", 3}, {"3", 8}, {"5", 1}, {"6", 9}, {"7", 4},
                             {"8", 10}, {"10", 0}, {"12", 11}, {"15", 5}, {"18", 12}, {"20", 2},
                             {"25", 13}, {"30", 6}, {"50", 14}
                            };

    Arbol arbolIdx;
    Empleado empleado;

    system("chcp 1252 >NULL");

    FILE* arch = fopen("Indice.idx", "wb");
    if(!arch)
        return SIN_MEM;

    fwrite(vec1, sizeof(Indice), CANT_VEC, arch);
    fclose(arch);

    crearArbol(&arbolIdx);
    cargarArbolDesdeArchivoOrdenado(&arbolIdx, "Indice.idx", sizeof(Indice), compararIndices, NULL);
    puts("Se mostrará el Árbol cargado del archivo índice: ");
    graficarArbol(&arbolIdx, mostrarElemArchiv);

    mostrarMenu();
    procesarOpciones(&arbolIdx, "Indice.idx", "Empleados.dat", compararIndices);

    grabarArchivoOrdenado(&arbolIdx, "Empleados.dat");


    arch = fopen("EmpleadosOrd.dat", "rb");
    fread(&empleado, sizeof(Empleado), 1, arch);
    while(!feof(arch))
    {
        printf("%-12s%-38s%-18s%4d/%2d/%4d%4d/%2d/%4d\n", empleado.leg, empleado.apYNom, empleado.cargo, empleado.fechaAlta.dia, empleado.fechaAlta.mes, empleado.fechaAlta.anio, empleado.fechaBaja.dia, empleado.fechaBaja.mes, empleado.fechaBaja.anio);
        fread(&empleado, sizeof(Empleado), 1, arch);
    }



    return 0;
}


void mostrarEmpleado(const Empleado* emp)
{
    printf("%-12s%-38s%-18s%4d/%2d/%4d\n", emp->leg, emp->apYNom, emp->cargo, emp->fechaAlta.dia, emp->fechaAlta.mes, emp->fechaAlta.anio);
}



int compararIndices(const void* i1, const void* i2)
{
    const Indice* ind1 = i1;
    const Indice* ind2 = i2;

    return atoi(ind1->leg) - atoi(ind2->leg);
}


void mostrarElemArchiv(const void* reg, int nivel)
{
    const Indice* ind = reg;

    for(int i = 0; i < nivel; i++)
        printf("    ");

    printf("%4s\n", ind->leg);
}


void mostrarMenu()
{
    printf("\n\na- Agregar un nuevo registro.\nb- Buscar por Clave.\nc- Recorrer Archivo en orden.\nd- Recorrer Archivo en preorden.\ne- Recorrer archivo en posorden.\nf- Asignar fecha de baja.\ng- Salir.\nElija su opción: ");
}


void leerArchivoUsandoIndice(void* elem, void* archComp)
{
    Indice* indice = elem;
    Empleado empleado;

    fseek(archComp, indice->nroReg * sizeof(Empleado), SEEK_SET);
    fread(&empleado, sizeof(Empleado), 1, archComp);
    mostrarEmpleado(&empleado);
}

void grabarEnArchivoUsandoIndice(void* elem, void* archComp)
{
    Indice* indice = elem;
    Empleado empleado;
    FILE* archOrd = fopen("EmpleadosOrd.dat", "ab");

    fseek(archComp, indice->nroReg * sizeof(Empleado), SEEK_SET);
    fread(&empleado, sizeof(Empleado), 1, archComp);
    fwrite(&empleado, sizeof(Empleado), 1, archOrd);

    fclose(archOrd);
}



void procesarOpciones(Arbol* pa, char* nombreArchInd, char* nombreArchCompleto, Cmp cmp)
{
    char opcion;
    Empleado empleado;
    Indice indice;

    FILE* archInd = fopen(nombreArchInd, "r+b");
    FILE* archComp = fopen(nombreArchCompleto, "r+b");

    fflush(stdin);
    scanf("%c", &opcion);
    fflush(stdin);
    opcion = tolower(opcion);
    while(opcion != 'g')
    {
        switch(opcion)
        {
        case 'a':
            {
                printf("Ingrese número de legajo (no puede ser repetido): ");
                fflush(stdin);
                gets(indice.leg);
                while(buscarEnArbol(pa, &indice, sizeof(Indice), compararIndices))
                {
                    printf("El legajo ya existe. Para ingresar un nuevo empleado el legajo debe ser único. Vuelva a ingresar: ");
                    fflush(stdin);
                    gets(indice.leg);
                }
                fseek(archInd, 0L, SEEK_END);
                indice.nroReg = (ftell(archInd) / sizeof(indice));

                insertarEnArbol(pa, &indice, sizeof(indice), compararIndices, NULL);

                strcpy(empleado.leg, indice.leg);
                printf("\nIngrese nombre y apellido: ");
                fflush(stdin);
                gets(empleado.apYNom);
                printf("\nIngrese cargo en la empresa: ");
                fflush(stdin);
                gets(empleado.cargo);
                printf("Ingrese fecha de alta(dd/mm/aaaa): ");
                fflush(stdin);
                scanf("%d/%d/%d", &empleado.fechaAlta.dia, &empleado.fechaAlta.mes, &empleado.fechaAlta.anio);
                while(!esFechaValida(&empleado.fechaAlta))
                {
                    printf("\nLa fecha ingresada no es válida. Vuelva a ingresar: ");
                    fflush(stdin);
                    scanf("%d/%d/%d", &empleado.fechaAlta.dia, &empleado.fechaAlta.mes, &empleado.fechaAlta.anio);
                }
                fseek(archComp, 0L, SEEK_END);
                fwrite(&empleado, sizeof(Empleado), 1, archComp);

                break;
            }
        case 'b':
            {
                printf("Ingrese el número de legajo para mostar el registro: ");
                fflush(stdin);
                gets(indice.leg);
                if(buscarEnArbol(pa, &indice, sizeof(Indice), cmp))
                {
                    fseek(archComp, indice.nroReg * sizeof(Empleado), SEEK_SET);
                    fread(&empleado, sizeof(Empleado), 1, archComp);
                    mostrarEmpleado(&empleado);
                }
                else
                    puts("El legajo no fue encontrado.");

                break;
            }
        case 'c':
            {
                puts("Se recorrerá el archivo en orden: ");
                recorrerArbolEnOrden(pa, leerArchivoUsandoIndice, archComp);

                break;
            }
        case 'd':
            {
                puts("Se recorrerá el archivo en preorden: ");
                recorrerArbolPreorden(pa, leerArchivoUsandoIndice, archComp);

                break;
            }
        case 'e':
            {
                puts("Se recorrerá el archivo en posorden: ");
                recorrerArbolPosorden(pa, leerArchivoUsandoIndice, archComp);

                break;
            }
        case 'f':
            {
                printf("Ingrese el número de legajo para asignar fecha de baja: ");
                fflush(stdin);
                gets(indice.leg);
                if(buscarEnArbol(pa, &indice, sizeof(Indice), cmp))
                {
                    fseek(archComp, indice.nroReg * sizeof(Empleado), SEEK_SET);
                    fread(&empleado, sizeof(Empleado), 1, archComp);
                    fseek(archComp, indice.nroReg * sizeof(Empleado), SEEK_SET);
                    printf("Ingrese fecha de baja(dd/mm/aaaa): ");
                    fflush(stdin);
                    scanf("%d/%d/%d", &empleado.fechaBaja.dia, &empleado.fechaBaja.mes, &empleado.fechaBaja.anio);
                    while(!esFechaValida(&empleado.fechaBaja))
                    {
                        printf("\nLa fecha ingresada no es válida. Vuelva a ingresar: ");
                        fflush(stdin);
                        scanf("%d/%d/%d", &empleado.fechaBaja.dia, &empleado.fechaBaja.mes, &empleado.fechaBaja.anio);
                    }
                    fwrite(&empleado, sizeof(Empleado), 1, archComp);
                }
                else
                    puts("El legajo no fue encontrado.");

                break;
            }

        default:
            puts("La opción elegida es invalida!!!");
        }

        mostrarMenu();
        fflush(stdin);
        scanf("%c", &opcion);
        fflush(stdin);
        opcion = tolower(opcion);
    }
    fclose(archComp);
    fclose(archInd);
}



int grabarArchivoOrdenado(Arbol* pa, const char* nombreArchComp)
{
    FILE* arch = fopen(nombreArchComp, "rb");

    if(!arch)
        return SIN_MEM;

    recorrerArbolEnOrden(pa, grabarEnArchivoUsandoIndice, arch);

    fclose(arch);
    return TODO_OK;
}
