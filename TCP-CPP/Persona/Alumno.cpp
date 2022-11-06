#include "Alumno.h"
#include "AlumnoException.h"
#include <iostream>
#include <stdlib.h>


Alumno::Alumno()
: promedio(0), cantMatAprob(0)
{}

Alumno::Alumno(unsigned dni, const Cadena& apellido, const Cadena& nombre, const Fecha& fechaNacimiento, const Cadena& carrera, const Fecha& fechaIngreso, double promedio, unsigned cantMatAp)
: Persona(dni, apellido, nombre, fechaNacimiento), carrera(carrera), fechaIngreso(fechaIngreso), promedio(promedio), cantMatAprob(cantMatAp)
{}


const Cadena Alumno::validarCarrera(const Cadena& cadena)
{
    return cadena.firstCharToUpperCase();
}


double Alumno::validarPromedio(double promedio)
{
    if(promedio < 1 && promedio > 10)
        throw AlumnoException("El promedio debe ser entre 1 y 10.");

    return promedio;
}



unsigned Alumno::validarCantMatAprob(unsigned cantMatAprob)
{
    if(cantMatAprob < 0)
        throw AlumnoException("La cantidad de materias aprobadas no puede ser un número negativo.");

    return cantMatAprob;
}



ostream& operator <<(ostream& os, const Alumno& alumno)
{
    os << (Persona&)alumno << "\t" << alumno.carrera << "\t" << alumno.fechaIngreso << "\t" << alumno.promedio << "\t" << alumno.cantMatAprob ;
    return os;
}



istream& operator >>(istream& is, Alumno& alumno)
{
    is >> (Persona&)alumno;

    char campo[501];

    is.getline(campo, 501, '\t');
    alumno.carrera = Alumno::validarCarrera(Cadena((const char*)campo));

    is.getline(campo, 501, '\t');
    alumno.fechaIngreso = (Cadena ((const char*)campo).toFecha());

    is.getline(campo, 501, '\t');
    alumno.promedio = Alumno::validarPromedio(atof(campo));

    is.getline(campo, 501);
    alumno.cantMatAprob = Alumno::validarCantMatAprob( (Cadena ((const char*)campo).toUnsigned() ) );

    return is;
}
