#ifndef MATEMATICA_H
#define MATEMATICA_H

double typedef (*Potencia)(const void* elem, const void* pot);

double factorialIterado(const int num);
double factorialRecursiva(const int num);
double numeroCombinatorio(const int m, const int n);
double calculaPotenciaDeEConTOL(const int num, const double tol, Potencia potencia);
double potenciaDeEConTOLRecurs(const int num, const double tol, const int pot, Potencia potencia);
double raizCuadradaConTolItera(const int num, const double tol);
double raizCuadradaConTolRecur(const int num, const double tol, const double terminoAnt);
int estaEnLaSerieFibonacciItera(const int num);
int estaEnLaSerieFibonacciRecur(const int num, int n1, int n2);
double senoConTolItera(const double num, const double tol, Potencia potencia);
double senoConTolRecur(const double num, const double tol, const int pot, int signo, Potencia potencia);
int perfectoDeficienteOAbundanteIter(const int num);
int perfectoDeficienteOAbundanteRecur(const int num);
long multPorSumasSucesivasIter(const int num1, const int num2);
long multPorSumasSucesivasRecur(const int num1, const int num2);
int cocienteYRestoNumNat(const int dividendo, const int divisor, int* cociente, int* resto);
int sumaDeNNumNatItera(const int cant);
int sumaDeNNumNatRecur(const int cant);
int sumaDeNNumNatParesItera(const int cant);
int sumaDeNNumNatParesRecur(const int cant, int par);
int sumaDeNParesMenoresANItera(const int num);
int sumaDeNParesMenoresANRecur(int num);
int esPrimo(const int num);
long multRusaItera(int num1, int num2);
long multRusaRecur(int num1, int num2);
int parteEnteraDeNumReal(const float num);


#endif // MATEMATICA_H
