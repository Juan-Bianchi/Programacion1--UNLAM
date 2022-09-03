#include <iostream>

#include "../Fecha/Fecha.h"

using namespace std;

int main()
{
    Fecha f1(1,1,1983), fSuma;

    fSuma = f1.sumarDias(180);


    cout << "Se imprimiran los dos dias: " << endl;
    int dia, mes, anio;
    fSuma.getDma(&dia, &mes, &anio);
    cout << "fSuma: " << dia << "/" << mes << "/" << anio << endl;
    f1.getDma(&dia, &mes, &anio);
    cout << "f1: " << dia << "/" << mes << "/" << anio << endl;

    int difDias = fSuma.diferenciaDias(&f1);
    cout << "La diferencia en dias entre las dos fechas usando el metodo .diferenciaDias es: " << difDias << " dias" << endl;

    difDias = f1 - fSuma;
    cout << "La diferencia en dias dando vuelta las fechas y usando la sobregarga del operador '-' es: " << difDias << " dias." << endl;

    f1 += 14490;
    f1.getDma(&dia, &mes, &anio);
    cout << "Si sumo 14490 dia al 1/1/1983 usando sobrecarga del operador '+=' la fecha es: " << dia << "/" << mes << "/" << anio << endl;
    f1 -= 14490;
    f1.getDma(&dia, &mes, &anio);
    cout << "Ahora resto la misma cantidad de dias usando la sobrecarga del operador '-=': " << dia << "/" << mes << "/" << anio << endl;
    f1.incrementarDia();
    f1.getDma(&dia, &mes, &anio);
    cout << "Incremento un dia usando el metodo .incrementarDia: " << dia << "/" << mes << "/" << anio << endl;




    return 0;
}
