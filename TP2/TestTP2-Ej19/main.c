/*Ejercicio 19
Escriba una función:
- que le permita mostrar el contenido de un archivo binario de enteros cuyo nombre recibe por argumento. Cada registro se mostrará separado del
siguiente por un espacio en blanco.
- que le permita mostrar el contenido de un archivo de texto cuyo nombre recibe por argumento. Cada registro se mostrará separado del siguiente
por un espacio en blanco.
- que genere un archivo binario (<"archalea">) con 90 números al azar de tres cifras (función estándar rand de la biblioteca stdlib.h).
- que divida en tres nuevos archivos binarios (<"archal1">, <"archal2"> y <"archal3">) el archivo anterior, tomado los primeros 30 para el
primer archivo, los siguientes 30 para el segundo y los restantes para el tercero.
- que transforme en archivo de texto cada uno de los archivos del punto anterior (<"archal1.txt">, <"archal2.txt"> y <"archal3.txt">).
- que transforme los dígitos de cada número de los archivos del punto anterior en letras, generando los archivos de texto (<"archtex1.txt">,
<"archtex2.txt"> y <"archtex3.txt">) de modo que a los dígitos del '0' al '9' les correspondan los caracteres de la 'A' a la 'J' para el
primero, de la 'K' a la 'T' para el segundo y de la 'U' a la 'D' para el tercero. O sea:
                los dígitos se transforman      ejemplos
conversión           0 1 2 3 4 5 6 7 8 9       157 901 975
1ro                  A B C D E F G H I J       BFH JAB JHF
2do                  K L M N O P Q R S T       LPB TKL TRP
3ro                  U V W X Y Z A B C D       VZB DUV DBZ
- que lea los archivos del punto anterior, y haciendo uso de la función < qsort> los ordene en forma creciente (únicamente aquí es necesario
leer todo el archivo en un array). Se generan los archivos (<"archord1.txt">, <"archord2.txt"> y <"archord3.txt">).
-..que genere un único archivo ordenado a partir de los archivos del punto anterior, manteniendo el ordenamiento ascendente. Se genera el
archivo (<"archord.txt">).
Escriba un programa que haciendo uso de cada una de las funciones (desde la tercera hasta la última), genere un archivo binario con 90 números
al azar, lo separe en tres archivos, genere tres archivos de texto, etc.. Utilice las dos primeras funciones para visualizar el avance del
proceso. Antes de terminar el proceso, utilice una función de menú para consultar si se desean eliminar los archivos intermedios.
Resuelva las funciones extra necesarias para una mejor estructuración del programa.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#include "../../Cadenas/Cadenas.h"
#include "../TP2-FuncionesConArchivos/Archivos.h"


int comparar(const void *, const void *);
void mostrarArchivoBinDeInt(FILE* archBin);
void mostrarArchivoTxt(FILE* archTxt);
void generaArchBinDe90Int(FILE* archBin);
void divideArchBinEn3(FILE* archPrin, FILE* arch1, FILE* arch2, FILE* arch3);
void BinATxt(FILE* archBin, FILE* archTxt);
void numALet1(FILE* archNum, FILE* archLet);
void numALet2(FILE* archNum, FILE* archLet);
void numALet3(FILE* archNum, FILE* archLet);
void ordenaArchTxtConQsort(FILE* archTxtNum, FILE* archTxtOrd);
void unificaTxt(FILE* archUn, FILE* arch1, FILE* arch2, FILE* arch3);

int main(int argc, char* argv[])
{
    FILE* archalea, * archal1, * archal2, * archal3, * archal1Txt, * archal2Txt, * archal3Txt, * archtex1Txt, * archtex2Txt, * archtex3Txt, * archord1Txt, * archord2Txt, * archord3Txt, * archordTxt;
    bool abrio;

    archalea = fopen(argv[1], "w+b");
    archal1 = fopen(argv[2], "w+b");
    archal2 = fopen(argv[3], "w+b");
    archal3 = fopen(argv[4], "w+b");
    archal1Txt = fopen(argv[5], "w+");
    archal2Txt = fopen(argv[6], "w+");
    archal3Txt = fopen(argv[7], "w+");
    archtex1Txt = fopen(argv[8], "w+");
    archtex2Txt = fopen(argv[9], "w+");
    archtex3Txt = fopen(argv[10], "w+");
    archord1Txt = fopen(argv[11], "w+");
    archord2Txt = fopen(argv[12], "w+");
    archord3Txt = fopen(argv[13], "w+");
    archordTxt = fopen(argv[14], "w+");

    abrio = archivoAbiertoCorrectamente(archalea, argv[1], "wb") && archivoAbiertoCorrectamente(archal1, argv[2], "w+b") && archivoAbiertoCorrectamente(archal2, argv[3], "w+b") && archivoAbiertoCorrectamente(archal3, argv[4], "w+b") && archivoAbiertoCorrectamente(archal1Txt, argv[5], "w+") && archivoAbiertoCorrectamente(archal2Txt, argv[6], "w+") && archivoAbiertoCorrectamente(archal3Txt, argv[7], "w+") && archivoAbiertoCorrectamente(archtex1Txt, argv[8], "w+") && archivoAbiertoCorrectamente(archtex2Txt, argv[9], "w+") && archivoAbiertoCorrectamente(archtex3Txt, argv[10], "w+") && archivoAbiertoCorrectamente(archord1Txt, argv[11], "w+") && archivoAbiertoCorrectamente(archord2Txt, argv[12], "w+") && archivoAbiertoCorrectamente(archord3Txt, argv[13], "w+") && archivoAbiertoCorrectamente(archordTxt, argv[14], "w+");
    if(!abrio)
    {
        puts("Error al abrir uno de los archivos. El programa se cerrara.");
        return 1;
    }

    puts("Se generara un archivo con 90 enteros de 3 cifras al azar: ");
    generaArchBinDe90Int(archalea);
    fseek(archalea, 0L, SEEK_SET);
    mostrarArchivoBinDeInt(archalea);
    fseek(archalea, 0L, SEEK_SET);

    puts("\n\nSe generaran 3 archivos de 30 enteros cada uno a partir de los 90 anteriores: ");
    divideArchBinEn3(archalea, archal1, archal2, archal3);
    fseek(archal1, 0L, SEEK_SET);
    puts("\nArchivo binario 1: ");
    mostrarArchivoBinDeInt(archal1);
    fseek(archal2, 0L, SEEK_SET);
    puts("\n\nArchivo binario 2: ");
    mostrarArchivoBinDeInt(archal2);
    fseek(archal3, 0L, SEEK_SET);
    puts("\n\nArchivo binario 3: ");
    mostrarArchivoBinDeInt(archal3);

    puts("\n\n\nAhora se generaran 3 archivos de texto a partir de los tres binarios anteriores y luego se imprimiran: ");
    fseek(archal1, 0L, SEEK_SET);
    fseek(archal2, 0L, SEEK_SET);
    fseek(archal3, 0L, SEEK_SET);
    BinATxt(archal1, archal1Txt);
    BinATxt(archal2, archal2Txt);
    BinATxt(archal3, archal3Txt);
    fseek(archal1Txt, 0L, SEEK_SET);
    fseek(archal2Txt, 0L, SEEK_SET);
    fseek(archal3Txt, 0L, SEEK_SET);
    puts("\n\nArchivo de texto 1: ");
    mostrarArchivoTxt(archal1Txt);
    puts("\n\nArchivo de texto 2: ");
    mostrarArchivoTxt(archal2Txt);
    puts("\n\nArchivo de texto 3: ");
    mostrarArchivoTxt(archal3Txt);


    puts("\n\n\nAhora se generaran tres archivos de texto a partir de los anteriores que cambiaran a los numeros por letras: ");
    fseek(archal1Txt, 0L, SEEK_SET);
    fseek(archal2Txt, 0L, SEEK_SET);
    fseek(archal3Txt, 0L, SEEK_SET);
    numALet1(archal1Txt, archtex1Txt);
    numALet2(archal2Txt, archtex2Txt);
    numALet3(archal3Txt, archtex3Txt);
    fseek(archtex1Txt, 0L, SEEK_SET);
    fseek(archtex2Txt, 0L, SEEK_SET);
    fseek(archtex3Txt, 0L, SEEK_SET);
    puts("\n\nArchivo de letras 1: ");
    mostrarArchivoTxt(archtex1Txt);
    puts("\n\nArchivo de letras 2: ");
    mostrarArchivoTxt(archtex2Txt);
    puts("\n\nArchivo de letras 3: ");
    mostrarArchivoTxt(archtex3Txt);

    puts("\n\n\nA continuacion se ordenaran los tres archivos y luego se mostraran ordenados: ");
    fseek(archal1Txt, 0L, SEEK_SET);
    fseek(archal2Txt, 0L, SEEK_SET);
    fseek(archal3Txt, 0L, SEEK_SET);
    ordenaArchTxtConQsort(archal1Txt, archord1Txt);
    ordenaArchTxtConQsort(archal2Txt, archord2Txt);
    ordenaArchTxtConQsort(archal3Txt, archord3Txt);
    fseek(archord1Txt, 0L, SEEK_SET);
    fseek(archord2Txt, 0L, SEEK_SET);
    fseek(archord3Txt, 0L, SEEK_SET);
    puts("\n\nArchivo de ordenado 1: ");
    mostrarArchivoTxt(archord1Txt);
    puts("\n\nArchivo de ordenado 2: ");
    mostrarArchivoTxt(archord2Txt);
    puts("\n\nArchivo de ordenado 3: ");
    mostrarArchivoTxt(archord3Txt);


    puts("\n\n\nPor ultimo se unificaran y ordenaran los tres archivos de textos en un unico archivo de 90 registros: ");
    fseek(archord1Txt, 0L, SEEK_SET);
    fseek(archord2Txt, 0L, SEEK_SET);
    fseek(archord3Txt, 0L, SEEK_SET);
    unificaTxt(archordTxt, archord1Txt, archord2Txt, archord3Txt);
    fseek(archordTxt, 0L, SEEK_SET);
    puts("\n\nArchivo de ordenado unificado: ");
    mostrarArchivoTxt(archordTxt);

    return 0;
}


int comparar(const void* elem1, const void* elem2)
{
    return *(int*)elem1 - *(int*)elem2;
}



void mostrarArchivoBinDeInt(FILE* archBin)
{
    int num;

    fread(&num, sizeof(int), 1, archBin);
    while(!feof(archBin))
    {
        printf("%d ", num);
        fread(&num, sizeof(int), 1, archBin);
    }

}



void mostrarArchivoTxt(FILE* archTxt)
{
    char num[4];

    while(fscanf(archTxt, "%s", num) != EOF)
        printf("%s ", num);
}



void generaArchBinDe90Int(FILE* archBin)
{
    int i, num;

    for(i=0; i < 90; i++)
    {
        num = 100 + rand() % 900;
        fwrite(&num, sizeof(int), 1, archBin);
    }
}



void divideArchBinEn3(FILE* archPrin, FILE* arch1, FILE* arch2, FILE* arch3)
{
    int i, num;

    for(i=0; i < 30; i++)
    {
        fread(&num, sizeof(int), 1, archPrin);
        fwrite(&num, sizeof(int), 1, arch1);
    }

    for(i=0; i < 30; i++)
    {
        fread(&num, sizeof(int), 1, archPrin);
        fwrite(&num, sizeof(int), 1, arch2);
    }

    for(i=0; i < 30; i++)
    {
        fread(&num, sizeof(int), 1, archPrin);
        fwrite(&num, sizeof(int), 1, arch3);
    }
}



void BinATxt(FILE* archBin, FILE* archTxt)
{
    int cen, dec, un;
    int num;

    fread(&num, sizeof(int), 1, archBin);
    while(!feof(archBin))
    {
        cen = num / 100;
        dec = (num / 10) % 10;
        un = num % 10;

        fprintf(archTxt, "%d%d%d ", cen, dec, un);
        fread(&num, sizeof(int), 1, archBin);
    }
}



void numALet1(FILE* archNum, FILE* archLet)
{
    char vec[10]= {"ABCDEFGHIJ"}, num[4], let[4];
    int i, dig;

    while(fscanf(archNum, "%s", num) != EOF)
    {
        for(i=0; i < 4; i++)
        {
            dig = num[i] - 48;
            let[i] = vec[dig];
        }

        fprintf(archLet, "%s ", let);
    }
}



void numALet2(FILE* archNum, FILE* archLet)
{
    char vec[10]= {"KLMNOPQRST"}, num[4], let[3];
    int i, dig;

    while(fscanf(archNum, "%s", num) != EOF)
    {
        for(i=0; i < 4; i++)
        {
            dig = num[i] - 48;
            let[i] = vec[dig];
        }

        fprintf(archLet, "%s ", let);
    }
}



void numALet3(FILE* archNum, FILE* archLet)
{
    char vec[10]= {"UVWXYZABCD"}, num[4], let[3];
    int i, dig;

    while(fscanf(archNum, "%s", num) != EOF)
    {
        for(i=0; i < 4; i++)
        {
            dig = num[i] - 48;
            let[i] = vec[dig];
        }

        fprintf(archLet, "%s ", let);
    }
}



void ordenaArchTxtConQsort(FILE* archTxtNum, FILE* archTxtOrd)
{
    int vec[30], i = 0;

    while(fscanf(archTxtNum, "%d", &vec[i]) != EOF && i < 30)
        i++;

    qsort(vec, 30, sizeof(int), comparar);

    for(i=0; i < 30; i++)
        fprintf(archTxtOrd, "%d ", vec[i]);
}



void unificaTxt(FILE* archUn, FILE* arch1, FILE* arch2, FILE* arch3)
{
    int vec[90], i = 0;

    while(fscanf(arch1, "%d", &vec[i]) != EOF && i < 30)
        i++;

    while(fscanf(arch2, "%d", &vec[i]) != EOF && i < 60)
        i++;

    while(fscanf(arch3, "%d", &vec[i]) != EOF && i < 90)
        i++;

    qsort(vec, 90, sizeof(int), comparar);

    for(i=0; i < 90; i++)
        fprintf(archUn, "%d ", vec[i]);
}
