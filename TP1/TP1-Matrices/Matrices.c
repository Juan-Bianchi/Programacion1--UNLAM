#include "Matrices.h"




int validaIntMayA(const int inf)
{
    int num;

    do
    {
        fflush(stdin);
        scanf("%d", &num);
        fflush(stdin);

        if(num<=inf)
            printf("El numero ingresado no es valido. El mismo debe ser mayor a %d. Vuelva a ingresar: ", inf);
    } while(num<=inf);

    return num;
}

booleano estaDentroDelRango(const int num, const int inf, const int sup)
{
    return num>=inf && num<=sup;
}



int validaIntEntre(const int inf, const int sup)
{
    int num;
    booleano esValido;

    do
    {
        fflush(stdin);
        scanf("%d", &num);
        fflush(stdin);
        esValido = estaDentroDelRango(num, inf, sup);
        if(!esValido)
            printf("El valor proporcionado no es valido. El mismo debe estar entre %d y %d. Vuelva a ingresar: ", inf, sup);
    } while(!esValido);

    return num;
}



void crearMatriz(MatrizF* matr)
{
    matr->cantC = 0;
    matr->cantF = 0;
}


void crearMatrizInt(MatrizI* matr)
{
    matr->cantC = 0;
    matr->cantF = 0;
}



void cargarMatrizCuadOrdenNConNumCorrel(MatrizF* matr, const int orden)
{
    int cont = 1, i, j;

    for(i=0; i < orden; i++)
    {
        for(j=0; j < orden; j++)
        {
            matr->mat[i][j] = cont ++;
        }
    }
    matr->cantC = orden;
    matr->cantF = orden;
}



void mostrarMatriz(MatrizF* matr)
{
    int i, j;

    for(i=0; i < matr->cantF; i++)
    {
        printf("|\t");
        for(j=0; j < matr->cantC; j++)
            printf("%8.2f", matr->mat[i][j]);
        printf("\t|\n");
    }
}



void mostrarMatrizInt(MatrizI* matr)
{
    int i, j;

    for(i=0; i < matr->cantF; i++)
    {
        printf("|");
        for(j=0; j < matr->cantC; j++)
            printf("%8d", matr->mat[i][j]);
        printf("        |\n");
    }
}



void cargarMatrizEnteros(MatrizI* matr)
{
    int  i, j;

    printf("Ingrese la cantidad de filas de la matriz (mayor a 0 y menor a %d): ", CANTIDAD_FILAS);
    matr->cantF = validaIntEntre(0, CANTIDAD_FILAS);
    printf("Ingrese la cantidad de columnas de la matriz (mayor a 0 y menor a %d): ", CANTIDAD_COLUMNAS);
    matr->cantC = validaIntEntre(0, CANTIDAD_COLUMNAS);

    for(i=0; i < matr->cantF; i++)
    {
        for(j=0; j < matr->cantC; j++)
        {
            printf("Ingrese el numero entero correspondiente a la posion [%d][%d]: ", i, j);
            fflush(stdin);
            scanf("%d", &matr->mat[i][j]);
            fflush(stdin);
        }
    }
}


void cargarMatrizCuadEnteros(MatrizI* matr, const int orden)
{
    int i, j;

    for(i=0; i < orden; i++)
    {
        for(j=0; j < orden; j++)
        {
            printf("Ingrese el numero entero correspondiente a la posion [%d][%d]: ", i, j);
            fflush(stdin);
            scanf("%d", &matr->mat[i][j]);
            fflush(stdin);
        }
    }
    matr->cantC = orden;
    matr->cantF = orden;
}



void sumaFilaDeMatrizEnVectInt(MatrizI* matr, VectorI* vect)
{
    int i, j;

    vect->cantElem = matr->cantF;

    for(i=0; i < vect->cantElem; i++)
        vect->vec[i] = 0;

    for(i=0; i < matr->cantF; i++)
        for(j=0; j < matr->cantC; j++)
            vect->vec[i] += matr->mat[i][j];
}



/*Ejercicio 29
Desarrollar una función para que, dada una matriz cuadrada de reales de orden N, obtenga la sumatoria de los elementos que están por encima de
la diagonal principal (excluida ésta). Lo mismo para la diagonal secundaria. Lo mismo incluyendo la diagonal. Lo mismo, con los que están por
debajo de la diagonal.*/

double sumaElemEncimaDiagPrinc(MatrizF* matr, const int orden)
{
    double suma = 0;
    int i, j;

    for(i=0; i < matr->cantF; i++)
    {
        for(j=i+1; j<orden; j++)
            suma += matr->mat[i][j];
    }

    return suma;
}



double sumaElemEncimaDiagSec(MatrizF* matr, const int orden)
{
    double suma = 0;
    int i, j;

    for(i=0; i < matr->cantF; i++)
    {
        for(j=0; j<orden-i-1; j++)
            suma += matr->mat[i][j];
    }

    return suma;
}



double sumaElemEncimaEIncluidaDiagPrinc(MatrizF* matr, const int orden)
{
    double suma = 0;
    int i, j;

    for(i=0; i < matr->cantF; i++)
    {
        for(j=i; j < orden; j++)
            suma += matr->mat[i][j];
    }

    return suma;
}



double sumaElemEncimaEIncluidaDiagSec(MatrizF* matr, const int orden)
{
    double suma = 0;
    int i, j;

    for(i=0; i < matr->cantF; i++)
    {
        for(j=0; j < orden - i; j++)
            suma += matr->mat[i][j];
    }

    return suma;
}



double sumaElemDebajoDiagPrinc(MatrizF* matr, const int orden)
{
    double suma = 0;
    int i, j;

    for(i=1; i < orden; i++)
    {
        for(j=0; j < i; j++)
            suma += matr->mat[i][j];
    }

    return suma;
}



double sumaElemDebajoDiagSec(MatrizF* matr, const int orden)
{
    double suma;
    int i, j;

    for(i=1; i < orden; i++)
    {
        for(j=orden - i; j < orden; j++)
            suma += matr->mat[i][j];
    }

    return suma;
}


/*Ejercicio 30
Desarrollar una función para que, dada una matriz cuadrada de enteros de orden N, obtenga la traza de la misma (sumatoria de los elementos de la
diagonal principal). Lo mismo, pero con la diagonal secundaria.*/

double sumaElemDiagPrinc(MatrizF* matr, const int orden)
{
    double suma = 0;
    int i;

    for(i=0; i < orden; i++)
        suma += matr->mat[i][i];

    return suma;
}



double sumaElemDiagSec(MatrizF* matr, const int orden)
{
    double suma = 0;
    int i;

    for(i=0; i < orden; i++)
        suma += matr->mat[i][orden - i - 1];

    return suma;
}



/*Ejercicio 31
Desarrollar una función que determine si una matriz cuadrada de enteros de orden N es matriz diagonal (ceros en todos sus elementos excepto en
la diagonal principal).*/

booleano esMatrizDiagonal(MatrizI* matr, const int orden)
{
    booleano esDiag = VERDADERO;
    int i = 0, j;

    while(esDiag && i < orden)
    {
        j = 0;
        while(esDiag && j < orden)
        {
            if(i != j && matr->mat[i][j] != 0)
                esDiag = FALSO;

            j++;
        }
        i++;
    }

    return esDiag;
}


/*Ejercicio 32
Desarrollar una función que determine si una matriz cuadrada de enteros de orden N es matriz identidad (matriz diagonal, con unos en la diagonal
principal y ceros en los restantes).*/

booleano esMatrizIdentidad(MatrizI* matr, const int orden)
{
    booleano esIden = VERDADERO;
    int i = 0, j;

    while(esIden && i < orden)
    {
        j = 0;
        while(esIden && j < orden)
        {
            if( (i != j && matr->mat[i][j] != 0) || (i == j && matr->mat[i][j] != 1) )
                esIden = FALSO;

            j++;
        }
        i++;
    }

    return esIden;
}



/*Ejercicio 33
Desarrollar una función que determine si una matriz cuadrada de enteros de orden N es simétrica.*/

booleano esMatrizSimetricaInt(MatrizI* matr, const int orden)
{
    int i=0, j;
    booleano esSimet = VERDADERO;

    while(esSimet && i < orden)
    {
        j = 0;
        while(esSimet && j < orden)
        {
            if(i != j && matr->mat[i][j] != matr->mat[j][i])
                esSimet = FALSO;

            j++;
        }
        i++;
    }

    return esSimet;
}



/*Ejercicio 34
Desarrollar una función para trasponer, in situ, una matriz cuadrada.*/

void trasponerMatrizIntCuadradaInSitu(MatrizI* matr, const int orden)
{
    int i, j, aux;

    for(i=0; i < orden; i++)
    {
        for(j=i+1; j < orden; j++)
        {
            aux = matr->mat[j][i];
            matr->mat[j][i] = matr->mat[i][j];
            matr->mat[i][j] = aux;
        }
    }
}



/*Ejercicio 35
Desarrollar una función para obtener la traspuesta de una matriz dada.*/

void crearMatrizTraspuestaInt(MatrizI* matrOrig, MatrizI* matrTras)
{
    int i, j;

    matrTras->cantF = matrOrig->cantC;
    matrTras->cantC = matrOrig->cantF;

    for(i=0; i < matrOrig->cantF; i++)
    {
        for(j=0; j < matrOrig->cantC; j++)
            matrTras->mat[j][i] = matrOrig->mat[i][j];
    }
}



/*Ejercicio 36
Desarrollar una función para obtener la matriz producto entre dos matrices de enteros.*/

int matrizProductoEntreDosMatrInt(MatrizI* matr1, MatrizI* matr2, MatrizI* matrProd)
{
    int i, j, k;

    if(matr1->cantC != matr2->cantF)
        return ERROR;

    matrProd->cantF = matr1->cantF;
    matrProd->cantC = matr2->cantC;

    for(i=0; i < matrProd->cantF; i++)
        for(j=0; j < matrProd->cantC; j++)
            matrProd->mat[i][j] = 0;


    for(k=0; k < matr2->cantC; k++)
    {
        for(i=0; i < matr1->cantF; i++)
        {
            for(j=0; j < matr1->cantC; j++)
            {
                matrProd->mat[i][k] += matr1->mat[i][j] * matr2->mat[j][k];
            }
        }
    }
    return TODO_OK;
}



/*Ejercicio 37
Se dispone de una matriz cuadrada de enteros de orden N, donde cada elemento [i][j] representa la cantidad de puntos que obtuvo el equipo i
frente al equipo j al fin de un torneo de fútbol (partidos de ida y vuelta) en el que participaron N equipos. El sistema de puntuación es: 3
puntos para el ganador del partido y ninguno para el perdedor; 1 punto para cada equipo en caso de empate.
Desarrollar una función que determine si la matriz está correctamente generada. Desarrollar una función que genere un arreglo de N elementos tal
que cada elemento V[k] contenga la cantidad de puntos obtenidos por el equipo k.*/

int verificaTablaPuntos(MatrizI* matr, const int orden)
{
    int i = 0, j;
    booleano estaOk = VERDADERO;

    while(estaOk && i < orden)
    {
        j = i + 1;
        while(estaOk && j < orden)
        {
            if((matr->mat[i][j] == 2 && matr->mat[j][i] != 2) || (matr->mat[i][j] == 3 && matr->mat[j][i] != 3) || (matr->mat[i][j] == 6 && matr->mat[j][i] != 0) || (matr->mat[i][j] == 0 && matr->mat[j][i] !=  6) || (matr->mat[i][j] == 4 && matr->mat[j][i] != 1) || (matr->mat[i][j] == 1 && matr->mat[j][i] != 4) )
                estaOk = FALSO;
            j++;
        }
        i++;
    }

    return (!estaOk)? ERROR: TODO_OK;
}


void mostrarMatrizTablaInt(MatrizI* matr)
{
    int i, j;

    printf("%18s","");

    for(j=0; j < matr->cantC; j++)
        printf("Eq%-3d   ", j + 1);

    printf("\n");

    for(i=0; i < matr->cantF; i++)
    {
        printf("Equipo %3d |", i + 1);
        for(j=0; j < matr->cantC; j++)
            printf("%8d", matr->mat[i][j]);
        printf("        |\n");
    }
}
