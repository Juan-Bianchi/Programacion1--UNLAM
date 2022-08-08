#include "Matematica.h"
#include<stdio.h>
#include<math.h>

int calculaDivisoresRecurs(const int num, int div);
int sumaDeNumParesRecur(int num);



/*Ejercicio 1
El factorial de un número natural incluido el 0, se calcula de la siguiente manera:
1 si N = 0
N! = N. (N - 1)! si N > 0
o sea, N! = N. (N - 1). (N - 2). …. 3. 2. 1
Ejemplo: 5! = 5. 4. 3. 2. 1 = 120
Desarrollar una función para calcular el factorial de un entero.*/

double factorialIterado(const int num)
{
    double factorial = 1;
    int i;

    if(num>=2)
        for(i=num; i>=2; i--)
            factorial *= i;

    return factorial;
}



double factorialRecursiva(const int num)
{
    if(num<2)
        return 1;

    return num * factorialRecursiva(num-1);
}


/*Ejercicio 2
Dados dos números enteros m y n (m >= n y n>= 0), el número combinatorio se calcula de la siguiente manera:
C(m)(n) = m ! / (n! (m−n) !)
Desarrollar una función para calcular el combinatorio m sobre n.*/

double numeroCombinatorio(const int m, const int n)
{
    return factorialIterado(m) / ( factorialIterado(n) * factorialIterado(m-n) );
}


/*Ejercicio 3
Dado un número entero X y una tolerancia (TOL), puede obtenerse ex mediante la suma de los términos de la serie:
e^x = 1+( X^1/1)+( X^2/(1*2))+( X^3/ (1*2*3))+( X^4/ (1*2*3*4))+ .. ..
El proceso termina cuando se obtiene un término calculado que sea menor que la tolerancia TOL.
Desarrollar una función para calcular el ex, dados X y TOL.*/

double calculaPotenciaDeEConTOL(const int num, const double tol, Potencia potencia)
{
    int i=1;
    double potE= 1, termino;

    do
    {
        termino = potencia(&num, &i) / factorialIterado(i);
        potE += termino;
        i++;
    } while (termino>=tol);
    return potE;
}


double potenciaDeEConTOLRecurs(const int num, const double tol, const int pot, Potencia potencia)
{
    double termino;

    termino = potencia(&num, &pot) / factorialIterado(pot);
    if(termino < tol)
        return termino + 1;

    return termino + potenciaDeEConTOLRecurs(num, tol, pot+1, potencia);
}


/*Ejercicio 4
La raíz cuadrada de un número positivo A puede calcularse mediante un proceso iterativo que genera términos según la siguiente fórmula:
R1=1
Ri=1 /2( Ri−1+( A / Ri− 1)) + 0.5
El proceso de cálculo se da por terminado cuando la diferencia entre dos términos sucesivos es menor que una cota fijada de antemano.
Desarrollar una función para calcular la raíz cuadrada de X con una tolerancia TOL.*/

double raizCuadradaConTolItera(const int num, const double tol)
{
    double terminoAnt = 1.0, termino, raiz = 1.0, dif;

    termino = 1.0 / 2.0 * (terminoAnt + (num / terminoAnt - 1)) + 0.5;
    dif = fabs(termino - terminoAnt);
    while(dif >= tol)
    {
        terminoAnt = termino;
        termino = 1.0 / 2.0 * (terminoAnt + (num / terminoAnt - 1)) + 0.5;
        dif = fabs(termino - terminoAnt);
    }
    raiz = termino;

    return raiz;
}


double raizCuadradaConTolRecur(const int num, const double tol, const double terminoAnt)
{
    double termino;

    termino = 1.0 / 2.0 * ( terminoAnt + (num / terminoAnt - 1)) + 0.5;

    if(fabs(termino - terminoAnt) < tol)
        return termino;

    return raizCuadradaConTolRecur(num, tol, termino);
}


/*Ejercicio 5
En la serie de Fibonacci, cada término es la suma de los dos anteriores y los dos primeros términos son 1
Serie: 1 1 2 3 5 8 13 21 34 ...
Desarrollar una función para determinar si un entero pertenece a la serie de Fibonacci.*/

int estaEnLaSerieFibonacciItera(const int num)
{
    int n1 = 1, n2 = 1, aux;

    printf("%d - %d - ", n1, n2);
    while(n1 <= num && n2 <= num)
    {
        aux = n2;
        n2 = n1 + n2;
        n1 = aux;
        printf("%d - ", n2);
    }

    return n1 == num || n2 == num;
}

int estaEnLaSerieFibonacciRecur(const int num, int n1, int n2)
{
    int aux;

    printf("%d - ", n2);
    aux = n1;
    n1 = n1 + n2;
    n2 = aux;

    if(num==n1 || num==n2)
    {
        printf("%d ", n1);
        return 1;
    }

    if(num<n1 && num<n2)
    {
        printf("%d ", n2);
        return 0;
    }

    return(estaEnLaSerieFibonacciRecur(num, n1, n2));
}


/*Ejercicio 6
Dados X y una tolerancia TOL es posible calcular el seno (x) mediante la suma de los términos de la serie:
seno(x) = x - x^3 / 3! + x^5 / 5! - x^7 / 7! + x^9 / 9! -x^11 / 11! + ...
Este proceso continúa mientras el término calculado (en valor absoluto) sea mayor que la tolerancia.
Desarrollar una función que obtenga el seno de X con tolerancia TOL, utilizando dicha serie.*/

double senoConTolItera(const double num, const double tol, Potencia potencia)
{
    int i = 3, simbolo = 1;
    double termino, seno = num;

    simbolo *= -1;
    termino = simbolo * (potencia(&num, &i) / factorialIterado(i));

    while(fabs(termino)>tol)
    {
        seno += termino;
        i += 2;
        simbolo *= -1;
        termino = simbolo * (potencia(&num, &i) / factorialIterado(i));
    }

    return seno;
}

double senoConTolRecur(const double num, const double tol, const int pot, int signo, Potencia potencia)
{
    double termino;

    signo *= -1;
    termino = signo * (potencia(&num, &pot) / factorialRecursiva(pot));

    if(fabs(termino)<tol)
        return termino + num;

    return termino + senoConTolRecur(num, tol, pot + 2, signo, potencia);
}


/*Ejercicio 7
Un número natural es perfecto, deficiente o abundante según que la suma de sus divisores positivos menores que él sea igual, menor o mayor que
él. Por ejemplo:
Número   Divisores        positivos menores que él Suma de los divisores     Clasificación
  6       1, 2, 3                          6                                   PERFECTO
  10      1, 2, 5                          8                                  DEFICIENTE
  12    1, 2, 3, 4, 6                      16                                  ABUNDANTE
Desarrollar una función que determine si un número natural es perfecto, deficiente o abundante.*/


int perfectoDeficienteOAbundanteIter(const int num)
{
    int i=1, sumaDiv=0;

    while(i<=num/2)
    {
        if(num%i==0)
            sumaDiv += i;
        i++;
    }
    if(sumaDiv<num)
        return 0;
    if(sumaDiv==num)
        return 1;

    return 2;
}

int perfectoDeficienteOAbundanteRecur(const int num)
{
    int sumaDiv ;

    sumaDiv = calculaDivisoresRecurs(num, 1);
    if(sumaDiv<num)
        return 0;
    if(sumaDiv==num)
        return 1;

    return 2;
}


int calculaDivisoresRecurs(const int num, int div)
{
    if(num/2==div)
        return div;
    if(num/2<div)
        return 0;

    while(num%div!=0)
        div ++;

    return div + calculaDivisoresRecurs(num, div+1);
}



/*Ejercicio 8
Dados dos números naturales (incluido el cero), obtener su producto por sumas sucesivas.*/

long multPorSumasSucesivasIter(const int num1, const int num2)
{
    int i=1;
    long long result = 0;

    if(num2==0)
        return 0;
    while(i<=num2)
    {
        result += num1;
        i++;
    }

    return result;
}

long multPorSumasSucesivasRecur(const int num1, const int num2)
{
    if(num2==0)
        return 0;

    return num1 + multPorSumasSucesivasRecur(num1, num2-1);
}



/*Ejercicio 9
Dados dos números naturales A y B, desarrollar una función para obtener el cociente entero A/B y el resto. (A puede ser 0; B, no).*/

int cocienteYRestoNumNat(const int dividendo, const int divisor, int* cociente, int* resto)
{
    if(divisor==0)
        return -1;

    *cociente = dividendo / divisor;
    *resto = dividendo % divisor;

    return 0;
}


/*Ejercicio 10
Construir un programa que lea un número natural N y calcule la suma de los primeros N números naturales.*/

int sumaDeNNumNatItera(const int cant)
{
    int i, suma=0;

    for(i=1; i<=cant; i++)
        suma+=i;

    return suma;
}


int sumaDeNNumNatRecur(const int cant)
{
    if(cant==1)
        return 1;

    return cant + sumaDeNNumNatRecur(cant-1);
}


/*Ejercicio 11
Construir un programa que lea un número natural N y calcule la suma de los primeros N números pares.*/

int sumaDeNNumNatParesItera(const int cant)
{
    int i=2, cont=0, suma=0;

    while(cont<cant)
    {
        suma += i;
        i += 2;
        cont++;
    }

    return suma;
}


int sumaDeNNumNatParesRecur(const int cant, int par)
{
    if(cant==0)
        return 0;

    return par + sumaDeNNumNatParesRecur(cant-1, par+2);
}



/*Ejercicio 12
Construir un programa que lea un número natural N y calcule la suma de los números pares menores que N.*/

int sumaDeNParesMenoresANItera(const int num)
{
    int i, suma = 0;

    for(i=0; i<num; i+=2)
    {
        if(i%2==0)
            suma += i;
    }
    return suma;
}

int sumaDeNParesMenoresANRecur(int num)
{
    if(num%2!=0)
        num -= 1;
    else
        num -= 2;

    return sumaDeNumParesRecur(num);
}

int sumaDeNumParesRecur(int num)
{
    if(num==2)
        return num;
    if(num<2)
        return 0;

    return num + sumaDeNumParesRecur(num-2);
}


/*Ejercicio 13
Desarrollar una función que determine si un número natural es primo.*/

int esPrimo(const int num)
{
    int i = 2;

    while(i <= num / 2 && num % i != 0)
    {
        i ++;
    }

    if(num%i==0)
        return 1;
    else
        return 0;
}


/*Ejercicio 20
El método de multiplicación rusa de dos números naturales, consiste en lo siguiente:
Se divide sucesivamente por 2 (división entera) a uno de sus factores hasta obtener 1.
Paralelamente, se multiplica sucesivamente por 2 al otro factor.
La suma de éstos últimos números obtenidos que se correspondan con números impares obtenidos en las divisiones, es el producto buscado
(Se consideran los factores originales para la suma correspondiente).
Por ejemplo para: 35 x 8
35       8                       8, 16 y 256 se corresponden con impares (35, 17 y 1).
17      16                       8 + 16 +256 = 280
8       32
4       64
2       128
1       256
*/

long multRusaItera(int num1, int num2)
{
    int suma = 0;

    if(num1==1)
        return num2;

    num1 /= 2;

    while(num1 >= 1)
    {
        num2 *= 2;

        if(num1%2!=0)
            suma += num2;

        num1 /= 2;
    }
    return suma;
}

long multRusaRecur(int num1, int num2)
{
    if(num1==1)
        return 0;

    num1 /= 2;
    num2 *= 2;

    return (num1%2!=0)? num2 + multRusaRecur(num1, num2): multRusaRecur(num1, num2);
}


/*Ejercicio 21
Desarrollar una función para obtener la parte entera de un número real.*/

int parteEnteraDeNumReal(const float num)
{
    return (int)num;
}
