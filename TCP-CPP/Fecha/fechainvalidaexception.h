#ifndef FECHAINVALIDAEXCEPTION_H
#define FECHAINVALIDAEXCEPTION_H

#include <string>

using namespace std;


class FechaInvalidaException
{
    public:
        FechaInvalidaException(string mens);                        //inicializador  == {this->mensaje = mens;};
        string getMensaje(string mens)const;

    private:
        string mensaje;
};


inline FechaInvalidaException::FechaInvalidaException(string mens):  mensaje(mens){};       //inicializador  == {this->mensaje = mens;};


inline string FechaInvalidaException::getMensaje(string mens)const {return mensaje;};

#endif // FECHAINVALIDAEXCEPTION_H
