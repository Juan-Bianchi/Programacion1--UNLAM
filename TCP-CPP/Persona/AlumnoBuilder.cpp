#include "AlumnoBuilder.h"


AlumnoBuilder::AlumnoBuilder()
: promedio(0), cantMatAprob(0)
{}



AlumnoBuilder& AlumnoBuilder::setCarrera(const Cadena& carrera)
{
    this->carrera = Alumno::validarCarrera(carrera);
    return *this;
}



AlumnoBuilder& AlumnoBuilder::setFechaIngreso(const Fecha& fechaIngreso)
{
    this->fechaIngreso = fechaIngreso;
    return *this;
}



AlumnoBuilder& AlumnoBuilder::setPromedio(double promedio)
{
    this->promedio = Alumno::validarPromedio(promedio);
    return *this;
}



AlumnoBuilder& AlumnoBuilder::setCantMatAprob(unsigned cantMatAprob)
{
    this->cantMatAprob = Alumno::validarCantMatAprob(cantMatAprob);
    return *this;
}



Alumno AlumnoBuilder::buildEstatica()
{
    return Alumno(dni, apellido, nombre, fechaIngreso, carrera, fechaIngreso, promedio, cantMatAprob);
}



Alumno* AlumnoBuilder::buildDinamica()
{
    return new Alumno(dni, apellido, nombre, fechaNacimiento, carrera, fechaIngreso, promedio, cantMatAprob);
}
