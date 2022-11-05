#include "PersonaBuilder.h"
#include "PersonaException.h"

PersonaBuilder::PersonaBuilder()
: dni(0)
{}



PersonaBuilder& PersonaBuilder::setDni(unsigned dni)
{
    this->dni = Persona::validaDni(dni);

    return *this;
}



PersonaBuilder& PersonaBuilder::setApellido(const Cadena& apellido)
{
    this->apellido = Persona::validaApellido(apellido);
    return *this;
}



PersonaBuilder& PersonaBuilder::setNombre(const Cadena& nombre)
{
    this->nombre = Persona::validaNombre(nombre);
    return *this;
}



PersonaBuilder& PersonaBuilder::setFechaNacimiento(const Fecha& fechaNacimiento)
{
    this->fechaNacimiento = fechaNacimiento;
    return *this;
}



Persona PersonaBuilder::buildEstatica()
{
    return Persona(dni, apellido, nombre, fechaNacimiento);
}



Persona* PersonaBuilder::buildDinamica()
{
    return new Persona(dni, apellido, nombre, fechaNacimiento);
}
