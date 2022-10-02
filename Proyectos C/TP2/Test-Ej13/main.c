    /*Ejercicio 13
Se dispone de dos archivos binarios: <"empleados"> y <"estudiantes">.
Cada registro del primer archivo contiene los campos:
- <dni>, <apellido>, <nombre> y <sueldo>, en tanto que los del segundo:
- <dni>, <apellido>, <nombre> y <promedio>.
Ambos archivos están ordenados alfabéticamente por <apellido> / <nombre> /
<dni>. Ambos archivos deben ser leídos sólo una vez, y no deben ser almacenados en arrays. El sueldo es double y el promedio es float.
Escriba un programa que, leyendo ambos archivos, actualice el sueldo de aquellos empleados que tengan un registro de estudiante con un promedio
superior a 7, en un 7,28%.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../TP2-FuncionesConArchivos/Archivos.h"

#define LONG_CHAR 20

typedef struct
{
    int dni;
    char apellido[LONG_CHAR];
    char nombre[LONG_CHAR];
    double sueldo;
} Empleados;



typedef struct
{
    int dni;
    char apellido[LONG_CHAR];
    char nombre[LONG_CHAR];
    float prom;
} Estudiantes;


int cargarEmpleados(FILE* archEmp);
int cargarEstudiantes(FILE* archEst);
void exportarArchEstAExcel(FILE* arch, Estudiantes* est, const char* nombre, const char* formato);
void exportarArchEmpAExcel(FILE* arch, Empleados* empl, const char* nombre, const char* formato);


int main(int argc, char* argv[])
{
    FILE* archEmp, * archEst;
    Empleados empl;
    Estudiantes est;
    int nroRegEmp, nroRegEst;
    char* formatoEmp = "%s;%s;%d;%.2f\n";
    char* formatoEst = "%s;%s;%d;%.2f\n";

    archEmp = fopen(argv[1], argv[5]);
    archEst = fopen(argv[2], argv[5]);


    if(archivoAbiertoCorrectamente(archEmp, argv[1], argv[4]) && archivoAbiertoCorrectamente(archEst, argv[2], argv[3]))
    {
        puts("Se comenzara con la carga del archivo de empleados: ");
        nroRegEmp = cargarEmpleados(archEmp);                   ///genero ambos archivos
        printf("Se han cargado %d registros\n", nroRegEmp);
        puts("Se comenzara con la carga del archivo de estudiantes: ");
        nroRegEst = cargarEstudiantes(archEst);
        printf("Se han cargado %d registros\n", nroRegEst);

        fclose(archEmp);
        fclose(archEst);

        archEmp = fopen(argv[1], argv[4]);
        archEst = fopen(argv[2], argv[4]);

        exportarArchEmpAExcel(archEmp, &empl, argv[6], formatoEmp);
        exportarArchEstAExcel(archEst, &est, argv[7], formatoEst);


        printf("\n\nArchivo de empleados: \n");
        system("type empl.csv");
        printf("\n\nArchivo de estudiantes: \n");
        system("type est.csv");

        fseek(archEmp, 0L, SEEK_SET);
        fseek(archEst, 0L, SEEK_SET);


        fread(&est, sizeof(Estudiantes), 1, archEst);               ///comienzo comparacion
        fread(&empl, sizeof(Empleados), 1, archEmp);

        while(!feof(archEmp) && !feof(archEst))
        {
            while(!feof(archEmp) && !feof(archEst) && strcmp(est.apellido, empl.apellido) < 0)
                fread(&est, sizeof(Estudiantes), 1, archEst);

            if(strcmp(est.apellido, empl.apellido)==0)
            {
                while(!feof(archEmp) && !feof(archEst) && strcmp(est.nombre, empl.nombre) < 0)
                    fread(&est, sizeof(Estudiantes), 1, archEst);

                if(strcmp(est.nombre, empl.nombre)==0)
                {
                    while(!feof(archEmp) && !feof(archEst) && est.dni < empl.dni)
                        fread(&est, sizeof(Estudiantes), 1, archEst);

                    if(est.dni == empl.dni)
                    {
                        if(est.prom > 7)
                        {
                            empl.sueldo *= 1.0728;
                            fseek(archEmp, -(long)sizeof(Empleados), SEEK_CUR);
                            fwrite(&empl, sizeof(Empleados), 1, archEmp);
                            fseek(archEmp, 0L, SEEK_CUR);
                        }
                        fread(&empl, sizeof(Empleados), 1, archEmp);
                        fread(&est, sizeof(Estudiantes), 1, archEst);
                    }
                }

            }

            while(!feof(archEmp) && !feof(archEst) && strcmp(est.apellido, empl.apellido) > 0)
                fread(&empl, sizeof(Empleados), 1, archEmp);

            if(strcmp(est.apellido, empl.apellido)==0 && !feof(archEmp) && !feof(archEst))
            {
                while(!feof(archEmp) && !feof(archEst) && strcmp(est.nombre, empl.nombre) > 0)
                    fread(&empl, sizeof(Empleados), 1, archEmp);

                if(strcmp(est.nombre, empl.nombre)==0)
                {
                    while(!feof(archEmp) && !feof(archEst) && est.dni > empl.dni)
                        fread(&empl, sizeof(Empleados), 1, archEmp);

                    if(est.dni == empl.dni)
                    {
                        if(est.prom > 7)
                        {
                            empl.sueldo *= 1.0728;
                            fseek(archEmp, -(long)sizeof(Empleados), SEEK_CUR);
                            fwrite(&empl, sizeof(Empleados), 1, archEmp);
                            fseek(archEmp, 0L, SEEK_CUR);
                        }
                        fread(&empl, sizeof(Empleados), 1, archEmp);
                        fread(&est, sizeof(Estudiantes), 1, archEst);
                    }
                }
            }
        }

        if(feof(archEst) && !feof(archEmp))
        {
            while(!feof(archEmp) && strcmp(est.apellido, empl.apellido) > 0)
                fread(&empl, sizeof(Empleados), 1, archEmp);

            if(strcmp(est.apellido, empl.apellido)==0)
            {
                while(!feof(archEmp) && strcmp(est.nombre, empl.nombre) > 0)
                    fread(&empl, sizeof(Empleados), 1, archEmp);

                if(strcmp(est.nombre, empl.nombre)==0)
                {
                    while(!feof(archEmp) && est.dni > empl.dni)
                        fread(&empl, sizeof(Empleados), 1, archEmp);

                    if(est.dni == empl.dni)
                    {
                        if(est.prom > 7)
                        {
                            empl.sueldo *= 1.0728;
                            fseek(archEmp, -(long)sizeof(Empleados), SEEK_CUR);
                            fwrite(&empl, sizeof(Empleados), 1, archEmp);
                            fseek(archEmp, 0L, SEEK_CUR);
                        }
                        fread(&empl, sizeof(Empleados), 1, archEmp);
                    }
                }
            }
        }

        if(feof(archEmp) && !feof(archEst))
        {
            while(!feof(archEst) && strcmp(est.apellido, empl.apellido) < 0)
                fread(&est, sizeof(Estudiantes), 1, archEst);

            if(strcmp(est.apellido, empl.apellido)==0)
            {
                while(!feof(archEst) && strcmp(est.nombre, empl.nombre) < 0)
                    fread(&est, sizeof(Estudiantes), 1, archEst);

                if(strcmp(est.nombre, empl.nombre)==0)
                {
                    while(!feof(archEst) && est.dni < empl.dni)
                        fread(&est, sizeof(Estudiantes), 1, archEst);

                    if(est.dni == empl.dni)
                    {
                        if(est.prom > 7)
                        {
                            empl.sueldo *= 1.0728;
                            fseek(archEmp, -(long)sizeof(Empleados), SEEK_CUR);
                            fwrite(&empl, sizeof(Empleados), 1, archEmp);
                            fseek(archEmp, 0L, SEEK_CUR);
                        }
                        fread(&est, sizeof(Estudiantes), 1, archEst);
                    }
                }

            }
        }
        fclose(archEmp);
        fclose(archEst);

        archEmp = fopen(argv[1], argv[3]);

        exportarArchEmpAExcel(archEmp, &empl, argv[6], formatoEmp);


        printf("\n\nArchivo de empleados: \n");
        system("type empl.csv");
        printf("\n\nArchivo de estudiantes: \n");
        system("type est.csv");

        fclose(archEmp);
    }

    return 0;
}



/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int cargarEmpleados(FILE* archEmp)
{
    Empleados empl;
    char aux[100];
    char* condFin = "0";
    int cant=0;

    printf("Ingrese el apellido del empleado (0 para terminar): ");
    gets(aux);
    while(strcmp(aux, condFin) != 0)
    {
        fflush(stdin);
        strcpy(empl.apellido, aux);
        printf("Ingrese el nombre del empleado: ");
        gets(empl.nombre);
        printf("Ingrese el dni del empleado: ");
        fflush(stdin);
        scanf("%d", &empl.dni);
        printf("Ingrese el sueldo del empleado: ");
        fflush(stdin);
        scanf("%lf", &empl.sueldo);
        fflush(stdin);
        cant++;
        fwrite(&empl, sizeof(Empleados), 1, archEmp);
        printf("Ingrese el apellido del empleado (0 para terminar): ");
        gets(aux);
    }

    return cant;
}




int cargarEstudiantes(FILE* archEst)
{
    Estudiantes est;
    char aux[100];
    char* condFin = "0";
    int cant=0;

    printf("Ingrese el apellido del estudiante (0 para terminar): ");
    gets(aux);
    while(strcmp(aux, condFin) != 0)
    {
        fflush(stdin);
        strcpy(est.apellido, aux);
        printf("Ingrese el nombre del estudiante: ");
        gets(est.nombre);
        printf("Ingrese el dni del estudiante: ");
        fflush(stdin);
        scanf("%d", &est.dni);
        printf("Ingrese el promedio del estudiante: ");
        fflush(stdin);
        scanf("%f", &est.prom);
        fflush(stdin);
        cant++;
        fwrite(&est, sizeof(Estudiantes), 1, archEst);
        printf("Ingrese el apellido del estudiante (0 para terminar): ");
        gets(aux);
    }

    return cant;
}


void exportarArchEstAExcel(FILE* arch, Estudiantes* est, const char* nombre, const char* formato)

{
    FILE *archExcel;

    archExcel = fopen(nombre, "w");
    if(archExcel == NULL)
    {
        printf("El archivo '%s' no ha podido abrirse para escritura. Se abortara el programa.", nombre);
        exit(1);
    }

    fread(est, sizeof(Estudiantes),1, arch);
    while(!feof(arch))
    {
        fprintf(archExcel, formato, est->apellido, est->nombre, est->dni, est->prom);
        fread(est, sizeof(Estudiantes),1, arch);
    }
    fclose(archExcel);
}


void exportarArchEmpAExcel(FILE* arch, Empleados* empl, const char* nombre, const char* formato)

{
    FILE *archExcel;

    archExcel = fopen(nombre, "w");
    if(archExcel == NULL)
    {
        printf("El archivo '%s' no ha podido abrirse para escritura. Se abortara el programa.", nombre);
        exit(1);
    }

    fread(empl, sizeof(Empleados),1, arch);
    while(!feof(arch))
    {
        fprintf(archExcel, formato, empl->apellido, empl->nombre, empl->dni, empl->sueldo);
        fread(empl, sizeof(Empleados),1, arch);
    }
    fclose(archExcel);
}
