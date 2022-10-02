#include <iostream>

#include "../Fecha/Fecha.h"
#include "../Fecha/fechainvalidaexception.h"


using namespace std;

int main()
{
    Fecha f1(1,1,1983), fSuma, f3;

    system("chcp 1252 > nul");

    fSuma = f1.sumarDias(180);


    cout << "Se imprimiran los dos dias: " << endl;
    int dia, mes, anio;
    fSuma.getDma(dia, mes, anio);
    cout << "fSuma: " << dia << "/" << mes << "/" << anio << endl;
    f1.getDma(dia, mes, anio);
    cout << "f1: " << dia << "/" << mes << "/" << anio << endl;

    cout << "Ahora se ingresara una fecha que posteriormente se imprimirá por pantalla: " << endl;
    cout << "A continuacion ingrese dd/mm/aaaa: ";
    cin >> f3;
    cout  << f3 << endl;

    int difDias = fSuma.diferenciaDias(&f1);
    cout << "La diferencia en días entre las dos fechas usando el método .diferenciaDias es: " << difDias << " dias" << endl;

    difDias = f1 - fSuma;
    cout << "La diferencia en días dando vuelta las fechas y usando la sobregarga del operador '-' es: " << difDias << " dias." << endl;

    f1 += 14490;
    cout << "Si sumo 14490 dia al 1/1/1983 usando sobrecarga del operador '+=' la fecha es: " << f1 << endl;
    f1 -= 14490;
    cout << "Ahora resto la misma cantidad de días usando la sobrecarga del operador '-=': " << f1 << endl;
    f1.incrementarDia();
    cout << "Incremento un día usando el metodo .incrementarDia: " << f1 << endl;

    Fecha fResta;
    try
    {
        fResta = f1 - 180;
        cout << "Si resto 180 días a f1 la fecha es: " << fResta << endl;
    }
    catch(const FechaInvalidaException& e)
    {
        std::cerr << e.getMensaje("El día no es válido. No pueden restarse esa cantidad de días.") << endl;
        return FECHA_INVALIDA;
    }




    return 0;
}
