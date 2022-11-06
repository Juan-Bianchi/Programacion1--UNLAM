#include <iostream>
#include <fstream>
#include "../Persona/Persona.h"
#include "../Persona/PersonaBuilder.h"
#include "../Persona/PersonaException.h"
#include "../Persona/AlumnoBuilder.h"
#include "../Persona/AlumnoException.h"


using namespace std;

int main()
{
    system("chcp 1252 > nul");
//    PersonaBuilder personaBuilder;
//
//    try
//    {
//        personaBuilder
//                    .setDni(12345678)
//                    .setApellido("Gonz·lez")
//                    .setNombre("p…dRo")
//                    .setFechaNacimiento(Fecha(1,1,1983));
//    }
//    catch(PersonaException& e)
//    {
//        cerr << e.getMensaje() << endl;
//        return 1;
//    }
//
//
//    Persona gonzalesPedro = personaBuilder.buildEstatica();
//    //cout << gonzalesPedro.getApellido() << ", " << gonzalesPedro.getNombre() << endl;
//
//
//    Persona* gonzalesPedro1 = personaBuilder.buildDinamica();
//    //cout << gonzalesPedro1->getApellido() << ", " << gonzalesPedro1->getNombre() << endl;
//
//    ///escribo en archivo
//    fstream archivo("Personas.txt", ios::out);
//    archivo << *gonzalesPedro1 << endl;
//
//    delete gonzalesPedro1;
//
//    try
//    {
//        personaBuilder
//                    .setDni(12345678)
//                    .setApellido("zuÒiga")
//                    .setNombre("s·ul")
//                    .setFechaNacimiento(Fecha(1,10,1988));
//    }
//    catch(PersonaException& e)
//    {
//        cerr << e.getMensaje() << endl;
//        return 1;
//    }
//
//
//    Persona zunigaSaul = personaBuilder.buildEstatica();
//   // cout << zunigaSaul.getApellido() << ", " << zunigaSaul.getNombre() << endl;
//
//    archivo << zunigaSaul << endl;
//
//    archivo.close();
//
//
//    ///leo de archivo
//
//    fstream archLectura("Personas.txt", ios::in);
//
//    vector<Persona*>personas;
//
//
//    while(archLectura.peek() != EOF)
//    {
//        Persona* persona = new Persona();
//        archLectura >> *persona;
//        personas.push_back(persona);
//    }
//
//    for(Persona* pers : personas)
//    {
//        cout << pers->getApellido() << ", " << pers->getNombre() << ", " << pers->getFechaNac() << endl;
//        delete pers;
//    }
//
//    archLectura.close();

    AlumnoBuilder builder;

    try
    {
        builder
               .setDni(30475902)
               .setApellido("Araujo")
               .setNombre("Agustin")
               .setFechaNacimiento(Fecha(1,12,1983));

        builder.setCarrera("IngenierÌa en Inform·tica")
               .setFechaIngreso(Fecha(1,3,2020))
               .setPromedio(8.5)
               .setCantMatAprob(21);
    }

    catch(AlumnoException& e)
    {
        cerr << e.getMensaje() << endl;
        return 1;
    }

    Alumno* agustinAraujo = builder.buildDinamica();

    fstream archAlus("Alumnos.txt", ios::out);
    fstream archAlusBin("Alumnos.dat", ios::out | ios::binary);

    archAlus << *agustinAraujo << endl;

    agustinAraujo->setApellido("RodrÌguez");
    agustinAraujo->setNombre("puma");

    archAlus << *agustinAraujo << endl;

    agustinAraujo->setApellido("De Luca");
    agustinAraujo->setNombre("Mariana");

    archAlus << *agustinAraujo << endl;

    delete agustinAraujo;
    archAlus.close();



    fstream archLect("Alumnos.txt", ios::in);
    vector<Alumno*> vecAl;

    while(archLect.peek() != EOF)
    {
        Alumno* alumno = new Alumno();
        archLect >> *alumno;
        vecAl.push_back(alumno);
    }

    for(Alumno* alumnos : vecAl)
    {
        cout << *alumnos << endl;
        delete alumnos;
    }


    archLect.close();


    return 0;
}
