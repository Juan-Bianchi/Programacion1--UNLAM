#include <iostream>
#include "../Figura/Cuadrado.h"
#include "../Figura/Circulo.h"


using namespace std;

void imprimirFigura(Figura& figura);

int main()
{
    Circulo circulo(5);
    Cuadrado cuadrado(4);

    system("chcp 1252 > null");

    imprimirFigura(circulo);
    imprimirFigura(cuadrado);


    return 0;
}


void imprimirFigura(Figura& figura)
{
    cout << "Área: " << figura.area() << endl;
    cout << "Perímetro: " << figura.perimetro() <<endl << endl;
}
