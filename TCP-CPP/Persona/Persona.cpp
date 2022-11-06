#include "Persona.h"
#include "PersonaException.h"
#include "../Cadena/Cadena.h"
#include <iostream>


using namespace std;

Persona::Persona()
:dni (0)
{}

Persona::Persona(unsigned dni, const Cadena& apellido, const Cadena& nombre, const Fecha& fechaNacimiento)
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
    char campo[501];

    is.getline(campo, 501, '\t');
    persona.dni = Persona::validaDni(Cadena((const char*)campo).toUnsigned());

    is.getline(campo, 501, '\t');
    persona.apellido = Persona::validaApellido(Cadena((const char*)campo));

    is.getline(campo, 501, '\t');
    persona.nombre = Persona::validaNombre(Cadena((const char*)campo));

    is.getline(campo, 501, '\t');
    persona.fechaNacimiento = (Cadena((const char*)campo).toFecha());

    return is;
}

