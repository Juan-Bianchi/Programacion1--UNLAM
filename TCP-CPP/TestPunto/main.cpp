#include <iostream>
#include "../Punto/Punto.h"

using namespace std;

int main()
{

    system("chcp 1252");

    Punto p1;
    Punto p2(-1, 500);
    Punto p3(p2);

    p1.mostrar();
    p2.mostrar();
    p3.mostrar();

    cout << "A continuación ingrese las coordenadas X e Y separadas por una coma seguido por un espacio(x, y): ";
    cin >> p3;
    cout << "El punto ingresado es: " << p3 << endl;


    Punto p4;
    p4 = p1++;
    cout << "p4 = p1++: " <<endl;
    cout << "Muestro p4: " << p4 << endl;
    cout << "Muestro p1: " << p1 << endl << endl;
    Punto p5;
    p5 = ++p1;
    cout << "p5 = ++p1:" << endl;
    cout << "Muestro p5: " << p5 << endl;
    cout << "Muestro p1: " << p1 << endl << endl;
    bool sonIguales = p1 == p5;
    bool sonDistintos = p1 != p5;
    cout << "Se evaluará p1 == p5: " << sonIguales << endl;
    cout << "Se evaluará p1 != p5: " << sonDistintos << endl << endl;


    cout << "Muestro p2: " << p2 << endl;
    p2 += 10;
    cout << "p2 += 10: Muestro p2: " << p2 << endl;
    p2 -= 10;
    cout << "p2 -= 10: Muestro p2: " << p2 << endl;


    return 0;
}
