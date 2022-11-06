#include "AlumnoException.h"

AlumnoException::AlumnoException(const Cadena& mensaje)
:mensaje(mensaje)
{}


const Cadena& AlumnoException::getMensaje()const
{
    return this->mensaje;
}



