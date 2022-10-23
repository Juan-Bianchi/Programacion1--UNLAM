#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Cola.h"

typedef struct
{
    char nombre[30];
    int minDem;
    bool enFila;
} Persona;


int asignaDemora(int num);
int asignaArribo(int num);
Persona* arribaPersona(Persona* vecPer);


int main()
{
    int minArr, contColVac = 0, contColPer = 0;
    Persona vecPer[10] = {{"Pedro Lopez", 0, false},
                          {"Pablo Pérez", 0, false},
                          {"Aníbal González", 0, false},
                          {"Lucas Romero", 0, false},
                          {"Leandro Fernandéz", 0, false},
                          {"Juan Insaurralde", 0, false},
                          {"Sergio Barreto", 0, false},
                          {"Iván Marcone", 0, false},
                          {"Alan Soñora", 0, false},
                          {"Leandro Benegas", 0, false}
                         };
    Persona* primero, * ultimo;
    Cola colaCajero;

    system("chcp 1252 > NULL");

    crearCola(&colaCajero);
    puts("Se procederá a la simulación de la cola de espera de un cajero automático: \n");

    primero = arribaPersona(vecPer);
    encolar(&colaCajero, primero, sizeof(Persona));
    primero->enFila = true;
    primero->minDem = rand() % 3;
    primero->minDem = asignaDemora(primero->minDem);
    srand(3);
    minArr = rand() % 3;
    minArr = asignaArribo(minArr);
    contColPer ++;
    printf("Ha arrivado %s a la cola. Actualmente hay %d personas en la misma.\n", primero->nombre, contColPer);

    while(contColVac < 5)
    {
        if(!minArr)
        {
            if(contColPer < 10)
            {
                ultimo = arribaPersona(vecPer);
                contColPer ++;
                printf("Ha arrivado %s a la cola. Actualmente hay %d personas en la misma.\n", ultimo->nombre, contColPer);
                encolar(&colaCajero, ultimo, sizeof(Persona));
                ultimo->minDem = rand() % 3;
                ultimo->minDem = asignaDemora(ultimo->minDem);
                ultimo->enFila = true;
                if(contColPer == 1)
                    primero = ultimo;
                minArr = rand() % 3;
                minArr = asignaArribo(minArr);
            }
            else
                puts("Se terminaron los minutos hasta el nuevo arribo pero no hay más personas disponibles para que arriven a la cola.");
        }
        else
        {
            minArr --;
            printf("Faltan %d minutos para un nuevo arrivo.\n", minArr);
        }



        if(primero->minDem)
        {
            primero->minDem--;
            printf("A %s le quedan %d minutos de demora\n", primero->nombre, primero->minDem);
        }
        else
        {
            if(desencolar(&colaCajero, primero, sizeof(Persona)))
            {
                primero->enFila = false;
                contColPer --;
                if(verFrenteCola(&colaCajero, primero, sizeof(Persona)))
                    printf("%s ha ingresado al cajero; empieza a correr su tiempo de demora en el mismo.\n", primero->nombre);
                else
                {
                    contColVac ++;
                    printf("La cola ha quedado vacia. Se incrementa el contador a %d.\n\n", contColVac);
                }
            }
        }
    }
    return 0;
}




int asignaDemora(int num)
{
    if(num == 0)
        return 1;
    if(num == 1)
        return 3;
    return 5;
}


int asignaArribo(int num)
{
    if(num == 0)
        return 1;
    if(num == 1)
        return 5;
    return 9;
}


Persona* arribaPersona(Persona* vecPer)
{
    Persona* pers = vecPer + rand() % 10;

    while(pers->enFila == true)
        pers = vecPer + rand() % 10;

    return pers;
}
