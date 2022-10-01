#include <iostream>
#include <stdlib.h>
#include <fstream>

#include "../Cadena/Cadena.h"

void funcionQueRecibeCopia(Cadena cCopia);


using namespace std;

int main()
{

    system("chcp 1252 > NULL");
    Cadena c1("Hola");
    Cadena c4(c1);
    Cadena c6 = "Hola mundo";
    Cadena c7;
    c7 = c1;
    funcionQueRecibeCopia(c7);
    Cadena c8;

    cout << "Ingrese una cadena: ";
    cin >> c8;
    cout << "La cadena ingresada es: " << c8 << endl;
    cout << "Ingrese otra cadena: ";
    cin >> c8;
    cout << "La nueva cadena ingresada es: " << c8 << endl;

    Cadena c9;

    fstream archivo("Archivo.txt", ios::in);
    fstream archivoSal("ArchivoSal.txt", ios::out);

    archivo >> c9;
    while(!archivo.eof())
    {
        cout << c9 << endl;
        archivoSal << c9 << endl;
        archivo >> c9;
    }
    archivo.close();
    archivoSal.close();


    return 0;
}


void funcionQueRecibeCopia(Cadena cCopia)
{
    cout << "Antes de concatenar: " << cCopia << endl;

    Cadena c2("Mundo");
    Cadena c3 = Cadena("Hola") + ' ' + c2 + "!!!" + ' ' + 123;

    cout << "Después de concatenar: "<< c3 << endl;
}
