#ifndef PERSONA_H
#define PERSONA_H

#include "../Cadena/Cadena.h"
#include "../Fecha/Fecha.h"




class Persona
{
    public:

        Persona();

        void setDni(unsigned dni) {this->dni = validaDni(dni);} ;
        void setApellido(const Cadena& apellido) {this->apellido = validaApellido(apellido);} ;
        void setNombre(const Cadena& nombre) {this->nombre = validaNombre(nombre);} ;
        void setFecha(const Fecha& fechaNacimiento) {this->fechaNacimiento = fechaNacimiento;} ;

        const unsigned getDni() {return dni;};
        const Cadena& getApellido() {return apellido;} ;
        const Cadena& getNombre() {return nombre;} ;
        const Fecha& getFechaNac() {return fechaNacimiento;} ;

        friend ostream& operator <<(ostream& os, Persona& persona);
        friend istream& operator >>(istream& is, Persona& persona);

        friend class PersonaBuilder;

    private:

        unsigned dni;
        Cadena apellido;
        Cadena nombre;
        Fecha fechaNacimiento;

        static unsigned validaDni(unsigned dni);
        static const Cadena validaApellido(const Cadena& apellido);
        static const Cadena validaNombre(const Cadena& nombre);


    protected:

        Persona(unsigned dni, const Cadena& apellido, const Cadena& nombre, const Fecha& fechaNacimiento);
};

#endif // PERSONA_H
