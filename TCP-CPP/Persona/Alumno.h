#ifndef ALUMNO_H
#define ALUMNO_H

#include "Persona.h"


class Alumno : public Persona
{
    public:
        Alumno();

        inline void setCarrera(const Cadena& carrera) {this->carrera = this->validarCarrera(carrera);} ;
        inline void setFechaIngreso(const Fecha& fechaIngreso) {this->fechaIngreso = fechaIngreso;} ;
        inline void setPromedio(double promedio) {this->promedio = this->validarPromedio(promedio);} ;
        inline void setCantMatAprob(unsigned cantMatAprob) {this->cantMatAprob = this->validarCantMatAprob(cantMatAprob);} ;

        const Cadena& getCarrera() {return carrera; } ;
        const Fecha& getFechaIngreso() {return fechaIngreso; };
        double getPromedio() {return promedio; };
        unsigned getCantMatAprob() {return cantMatAprob; };

        friend ostream& operator <<(ostream& os, const Alumno& alumno);
        friend istream& operator >>(istream& is, Alumno& alumno);

        friend class AlumnoBuilder;


    protected:
        Alumno(unsigned dni, const Cadena& apellido, const Cadena& nombre, const Fecha& fechaNacimiento, const Cadena& carrera, const Fecha& fechaIngreso, double promedio, unsigned cantMatAprob);


    private:
        Cadena carrera;
        Fecha fechaIngreso;
        double promedio;
        unsigned cantMatAprob;

        static const Cadena validarCarrera(const Cadena& cadena);
        static double validarPromedio(double promedio);
        static unsigned validarCantMatAprob(unsigned cantMatAprob);
};

#endif // ALUMNO_H
