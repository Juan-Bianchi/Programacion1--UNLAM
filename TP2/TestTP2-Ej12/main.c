#include <stdio.h>
#include <stdlib.h>

#include "../../Cadenas/Cadenas.h"
#define CANT_ALUM 100
#define CANT_LET 40
#define CANT_COL_NOT 7


int validaIntEntre(const int inf, const int sup);
int cargarAlumnos(char nombres[][40], float notas[][7], const int cantF, const int colNom, const int colNot);
void calcularPromedio(float notas[][7], const int fila, const int cantCol);
void promPorEvaluac(float notas[][7], const int cantF, const int cantCol);
void promGeneral(float notas[][7], const int cantF, const int cantCol);
void imprimirListadoEnArch(FILE* archTxt, char nombres[][40], const float notas[][7], const int cantF, const int colNot);


int main(int arg, char* argv[])
{
    char nombres[CANT_ALUM][CANT_LET];
    float notas[CANT_ALUM][CANT_COL_NOT];
    int cant, i , j;
    FILE* archTxt;

    /*Ejercicio 12
    Escriba un programa que le permita ingresar en arrays bidimensionales los apellidos y nombres de alumnos y las seis calificaciones obtenidas
    en cada parcial. Haga uso de una función que resuelva el ingreso, y devuelva cuántos se cargaron. Se garantiza que la cantidad de alumnos es
    menor que 100.
    El array para las calificaciones tendrá una fila y una columna extra, en las que se calculará, haciendo uso de funciones al efecto:
    - el promedio de calificaciones de cada alumno, que se acumula en la columna extra que le corresponde a cada alumno. Esta función debe ser
    invocada repetidamente con la dirección de cada fila del array.
    - el promedio general de los alumnos para cada evaluación, y el promedio general.
    Al terminar el programa debe generar una salida impresa (en archivo de texto),
    que debería verse así.
    Note que:
    - debe numerar las líneas de detalle,
    - debe colocar un título indicativo, subrayarlo, y dejando un renglón en blanco (vacío), comenzar el listado de alumnos (hasta 21 por
    página),
    - la numeración es consecutiva en las distintas páginas,
    - los campos impresos deben quedar encolumnados,
    - los promedios deben informarse en la última hoja,
    - la primera línea se ha indicado para visualizar la alineación de los campos.*/

    puts("Ejercicio 12");
    archTxt = fopen(argv[1], argv[2]);
    if(archTxt == NULL)
    {
        printf("El archivo %s no a podido ser abierto en modo %s. Se saldra del programa.\n", argv[1], argv[2]);
        exit(1);
    }

    cant = cargarAlumnos(nombres, notas, CANT_ALUM, CANT_LET, CANT_COL_NOT);

    for(i=0; i<cant; i++)
    {
        for(j=0; j<CANT_COL_NOT; j++)
            calcularPromedio(notas, i, CANT_COL_NOT);
    }
    promPorEvaluac(notas, cant, CANT_COL_NOT);
    promGeneral(notas, cant, CANT_COL_NOT);

    imprimirListadoEnArch(archTxt, nombres, notas, cant, CANT_COL_NOT);

    fclose(archTxt);

    system("type NotasAlumnos.txt");

    return 0;
}

int validaIntEntre(const int inf, const int sup)
{
    int num;

    fflush(stdin);
    scanf("%d", &num);
    fflush(stdin);
    while(num<inf ||B num>sup)
    {
        printf("El numero %d no es correcto. El mismo debe estar entre %d y %d. Vuelva a ingresar: ", num, inf, sup);
        fflush(stdin);
        scanf("%d", &num);
        fflush(stdin);
    }

    return num;
}


int cargarAlumnos(char nombres[][40], float notas[][7], const int cantF, const int colNom, const int colNot)
{
    int cant = 0, j;
    char aux[colNom];
    char* pAux;
    char cero[] = {"0"};

    printf("Ingrese el nombre del alumno (0 para terminar): ");
    fgets(aux, 40, stdin);
    pAux = strrchr(aux, '\n');
    if(pAux)
        *pAux = '\0';
    while(strcmp(aux, cero) != 0 && cant < cantF-1)
    {
        strcpy(nombres[cant], aux);
        for(j=0; j<colNot-1; j++)
        {
            printf("Ingrese la nota del parcial numero %d (entre 1 y 10): ", j+1);
            notas[cant][j] = validaIntEntre(1,10);
        }

        cant++;
        printf("Ingrese el nombre del alumno (0 para terminar): ");
        fgets(aux, 40, stdin);
        pAux = strrchr(aux, '\n');
        if(pAux)
            *pAux = '\0';
    }
    sprintf(nombres[cant], "%s", "Totales:");
    cant++;

    return cant;
}



void calcularPromedio(float notas[][7], const int fila, const int cantCol)
{
    float suma = 0;
    int j;

    for(j=0; j<cantCol-1; j++)
        suma += notas[fila][j];

    if(suma)
        notas[fila][j] = suma / (cantCol-1);
    else
        notas[fila][j] = 0;

}



void promPorEvaluac(float notas[][7], const int cantF, const int cantCol)
{
    int i,j;
    float suma;

    for(j=0; j<cantCol-1; j++)
    {
        suma = 0;
        for(i=0; i<cantF-1; i++)
            suma += notas[i][j];

        if(suma)
            notas[i][j] = suma / (cantF-1);
        else
            notas[i][j] = 0;
    }
}



void promGeneral(float notas[][7], const int cantF, const int cantCol)
{
    int j;
    float suma = 0;

    for(j=0; j<cantCol-1; j++)
       suma += notas[cantF-1][j];

    if(suma)
        notas[cantF-1][j] = suma / (cantCol-1);
    else
        notas[cantF-1][j] = 0;
}



void imprimirListadoEnArch(FILE* archTxt, char nombres[][40], const float notas[][7], const int cantF, const int colNot)
{
    int i, j;

    for(i=0; i < cantF; i++)
    {
        if(i % 21 == 0)
            fprintf(archTxt, "   %-40s %5s %5s %5s %5s %5s %5s - %5s\n   %40s %5s %5s %5s %5s %5s %5s - %5s\n\n", "Apellido/s, Nombre/s", "P. 1", "P. 2", "P. 3", "P. 4", "P. 5", "P. 6", "Prome", "========================================", "=====", "=====", "=====", "=====", "=====", "=====", "=====");

        if(i == cantF-1)
            fprintf(archTxt, "   %-40s ", nombres[i]);
        else
            fprintf(archTxt, "%2d %-40s ", i+1, nombres[i]);

        for(j=0; j < colNot-1; j++)
            fprintf(archTxt, "%5.2f ", notas[i][j]);

        fprintf(archTxt, "  %5.2f\n", notas[i][j]);
    }

    fprintf(archTxt, "\n\n");
}

