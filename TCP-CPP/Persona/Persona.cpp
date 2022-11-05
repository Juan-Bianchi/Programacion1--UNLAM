#include "Persona.h"
#include "PersonaException.h"
#include "../Cadena/Cadena.h"
#include <iostream>


using namespace std;

Persona::Persona()
:dni (0)
{}

Persona::Persona(unsigned dni, Cadena& apellido, Cadena& nombre, Fecha& fechaNacimiento)
:dni(dni), apellido(apellido), nombre(nombre), fechaNacimiento(fechaNacimiento)
{}


unsigned Persona::validaDni(unsigned dni)
{
    if(dni < 10000000)
        throw PersonaException("El DNI debe tener mas de 6 digitos.");

    return dni;
}


const Cadena Persona::validaApellido(const Cadena& apellido)
{
    return apellido.toUpperCase();
}



const Cadena Persona::validaNombre(const Cadena& nombre)
{
    return nombre.firstCharToUpperCase();
}



ostream& operator <<(ostream& os, Persona& persona)
{
    return os << persona.dni << "\t" << persona.apellido << "\t" << persona.nombre << "\t" << persona.fechaNacimiento;
}


istream& operator >>(istream& is, Persona& persona)
{
    Cadena linea;

    is >> linea;

    vector<Cadena> campos = linea.split('\t');

    persona.dni = Persona::validaDni(campos[0].toUnsigned());
    persona.apellido = Persona::validaApellido(campos[1]);
    persona.nombre = Persona::validaNombre(campos[2]);
    persona.fechaNacimiento = campos[3].toFecha();

    return is;
}

