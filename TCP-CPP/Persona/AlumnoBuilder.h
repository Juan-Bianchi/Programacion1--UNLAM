#ifndef ALUMNOBUILDER_H
#define ALUMNOBUILDER_H

#include "Alumno.h"
#include "PersonaBuilder.h"


class AlumnoBuilder : public PersonaBuilder
{
    public:
        AlumnoBuilder();

        AlumnoBuilder& setCarrera(const Cadena& carrera);
        AlumnoBuilder& setFechaIngreso(const Fecha& fechaIngreso);
        AlumnoBuilder& setPromedio(double promedio);
        AlumnoBuilder& setCantMatAprob(unsigned cantMatAprob);

        Alumno buildEstatica();
        Alumno* buildDinamica();

    protected:

    private:
        Cadena carrera;
        Fecha fechaIngreso;
        double promedio;
        unsigned cantMatAprob;
};

#endif // ALUMNOBUILDER_H
