#ifndef PERSONABUILDER_H
#define PERSONABUILDER_H

#include "../Cadena/Cadena.h"
#include "../Fecha/Fecha.h"
#include "Persona.h"


class PersonaBuilder
{
    public:
        PersonaBuilder();

        PersonaBuilder& setDni(unsigned dni);
        PersonaBuilder& setApellido(const Cadena& apellido);
        PersonaBuilder& setNombre(const Cadena& nombre);
        PersonaBuilder& setFechaNacimiento(const Fecha& fechaNacimiento);

        Persona buildEstatica();
        Persona* buildDinamica();

        friend ostream& operator <<(ostream& os, Persona& persona);

    protected:
        unsigned dni;
        Cadena apellido;
        Cadena nombre;
        Fecha fechaNacimiento;
};

#endif // PERSONABUILDER_H
