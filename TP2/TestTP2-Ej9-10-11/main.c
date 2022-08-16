#include <stdio.h>
#include <stdlib.h>

#include "../../Cadenas/Cadenas.h"
#include "../TP2-FuncionesConArchivos/Archivos.h"


int main(int argc, char* argv[])
{
    int cantNum, cantReng, i, contador=0, contMult5 = 0, contMult11 = 0, contMult6 = 0;
    booleano unaPalCarg = FALSO, sietePalCarg = FALSO, aperturaCorrecta;
    short int num;
    FILE* archTxt, * archTxt2;
    char numero[10];

    /*Ejercicio 9
    Escriba un programa que genere un archivo de texto ("datos.txt") a partir del ingreso por teclado de n�meros enteros, de modo que en cada
    l�nea de texto haya una cantidad variable de cadenas de caracteres que representen tales n�meros. En el archivo debe haber como m�nimo la
    representaci�n de un entero y como m�ximo de siete. La separaci�n entre estas cadenas que representan n�meros debe ser de al menos un
    car�cter espacio (' ') o a lo sumo cinco, de modo que queden alineados por la derecha al leer el contenido del archivo con un procesador de
    texto como el �Notepad� o �Bloc de Notas�.
    Ingrese los enteros con una variable short int (note que el rango de las mismas pertenece al intervalo [-32768, 32767]). Vea e interprete qu�
    sucede cuando ingresa n�meros fuera de ese rango.
    Note que:
    - los caracteres de separaci�n s�lo est�n entre n�meros,
    - la primera l�nea se ha indicado para visualizar la alineaci�n de los n�meros,
    - en el archivo debe haber al menos una l�nea con un n�mero y otra con siete, Utilice el generador de n�meros pseudo aleatorios para
    determinar cu�ntos n�meros se almacenan por l�nea de texto, y adem�s para que determine cu�ntas l�neas se almacenar�n una vez cumplida la
    condici�n de una l�nea con un n�mero y otra con siete.*/

    puts("Ejercicio 9");
    printf("A continuacion se procedera a la carga de numeros en un archivo siendo como minimo un numero y como maximo siete numeros cargados en el mismo renglon.\n");
    printf("La cantidad de numeros por linea sera determinada por la funcion rand(), una vez que se haya cargado un renglon con siete numeros y otro con uno, la funcion rand determinara cuantas lineas mas se almacenaran luego de esto: ");

    archTxt = fopen(argv[1], argv[2]);
    aperturaCorrecta = archivoAbiertoCorrectamente(archTxt, argv[1], argv[2]);
    if(aperturaCorrecta)
    {
       while(!unaPalCarg || !sietePalCarg)
        {
            cantNum = rand() % 7 + 1;
            printf("Se ingresaran %d numeros en esta linea\n", cantNum);
            for(i=0; i < cantNum; i++)
            {
                printf("Ingrese un numero entero (entre -32768 y 32768): ");
                fflush(stdin);
                scanf("%hd", &num);
                fflush(stdin);
                if(i < cantNum-1)
                    fprintf(archTxt, "%7d ", num);
                else
                    fprintf(archTxt, "%7d\n", num);
            }
            if(cantNum == 1)
                unaPalCarg = VERDADERO;
            if(cantNum == 7)
                sietePalCarg = VERDADERO;
        }

        cantReng = rand() % 7 + 1;
        printf("\nYa hay un renglo con 7 numeros y otro con 1 numero. Se agregaran %d renglones y se cerrara el archivo\n\n", cantReng);

        while(contador < cantReng)
        {
            cantNum = rand() % 7 + 1;
            printf("Se ingresaran %d numeros en esta linea: \n", cantNum);
            for(i=0; i < cantNum; i++)
            {
                printf("Ingrese un numero entero (entre -32768 y 32768): ");
                fflush(stdin);
                scanf("%hd", &num);
                fflush(stdin);

                if(i < cantNum-1)
                    fprintf(archTxt, "%7d ", num);
                else
                    fprintf(archTxt, "%7d\n", num);
            }
            contador ++;
        }
        fclose(archTxt);
    }

    /*Ejercicio 10
    Escriba una funci�n que determine si una cadena de caracteres que representa a un n�mero, es decir compuesta por los caracteres que
    representan d�gitos, recibida por argumento:
    - es capic�a (es obvio),
    - es m�ltiplo de 5 (el �ltimo d�gito es 0 � 5),
    - es m�ltiplo de 6 (es par -termina en '0', '2', '4', '6', '8'-; y la suma de sus d�gitos es m�ltiplo de 3),
    - es m�ltiplo de 11 (la suma de los d�gitos de posiciones pares, y la suma de los d�gitos de posiciones impares es m�ltiplo de 11),
    - es mayor que "100" (o cualquier otra cadena representando un n�mero entero cualquiera, p. ej.: "-42").
    Escriba una funci�n que valide si todos los caracteres de una cadena representan un n�mero dentro del intervalo de los: short int.
    Ejercicio 11
    Leyendo (s�lo una vez) un archivo de texto como el del <ej.: 9> y utilizando las funciones del <ej.: 10>, y otras al efecto, determinar:
    - cu�ntos son m�ltiplo de 5,
    - cu�ntos son m�ltiplo de 6,
    - cu�ntos son m�ltiplo de 11, y
    - generar un archivo con los que sean mayores que "100" (o cualquier otro n�mero recibido por argumento en la l�nea de comando)*/

    puts("Ejercicio 10 y 11");
    printf("Se abrira el arhivo %s nuevamente esta vez en modo lectura para realizar diferentes operaciones: \n", argv[1]);
    archTxt = fopen(argv[1], argv[3]);
    archTxt2 = fopen(argv[4],argv[2]);
    aperturaCorrecta = archivoAbiertoCorrectamente(archTxt, argv[1], argv[3]) && archivoAbiertoCorrectamente(archTxt2, argv[4], argv[2]);

    if(aperturaCorrecta)
    {
        printf("\n\n");
        system("type datos.txt");
        printf("\n\n");

        printf("Ingrese el numero entero con el cual se comparan los numeros del archivo .txt abierto: ");
        fflush(stdin);
        scanf("%d", &cantNum);
        fflush(stdin);

        while(fscanf(archTxt, "%s", numero) != EOF)
        {
            if(esMultiploDeCinco(numero))
                contMult5 ++;
            if(esMultiploDeSeis(numero))
                contMult6 ++;
            if(esMultiploDeOnce(numero))
                contMult11 ++;
            if(esMayorAN(numero, cantNum))
                fprintf(archTxt2, "%6s\n", numero);
        }
        fclose(archTxt2);
        fclose(archTxt);


        printf("El archivo generado con los numeros mayores a %d es: \n", cantNum);
        system("type mayorA.txt");
    }

    return 0;
}
