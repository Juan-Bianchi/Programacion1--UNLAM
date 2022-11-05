#ifndef PERSONAEXCEPTION_H
#define PERSONAEXCEPTION_H

#include "../Cadena/Cadena.h"


class PersonaException
{
    public:
        PersonaException(const Cadena& mensaje);

        const Cadena& getMensaje()const;


    private:
        Cadena mensaje;
};

#endif // PERSONAEXCEPTION_H
