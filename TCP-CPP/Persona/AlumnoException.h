#ifndef ALUMNOEXCEPTION_H
#define ALUMNOEXCEPTION_H

#include "../Cadena/Cadena.h"

class AlumnoException
{
    public:
        AlumnoException(const Cadena& mensaje);
        const Cadena& getMensaje()const;

    private:
        Cadena mensaje;
};

#endif // ALUMNOEXCEPTION_H
