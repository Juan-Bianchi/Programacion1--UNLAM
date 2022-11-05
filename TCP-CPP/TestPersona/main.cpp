#include <iostream>
#include <fstream>
#include "../Persona/Persona.h"
#include "../Persona/PersonaBuilder.h"
#include "../Persona/PersonaException.h"


using namespace std;

int main()
{
    system("chcp 1252 > nul");
    PersonaBuilder personaBuilder;

    try
    {
        personaBuilder
                    .setDni(12345678)
                    .setApellido("Gonz·lez")
                    .setNombre("p…dRo")
                    .setFechaNacimiento(Fecha(1,1,1983));
    }
    catch(PersonaException& e)
    {
        cerr << e.getMensaje() << endl;
        return 1;
    }


    Persona gonzalesPedro = personaBuilder.buildEstatica();
    //cout << gonzalesPedro.getApellido() << ", " << gonzalesPedro.getNombre() << endl;


    Persona* gonzalesPedro1 = personaBuilder.buildDinamica();
    //cout << gonzalesPedro1->getApellido() << ", " << gonzalesPedro1->getNombre() << endl;

    ///escribo en archivo
    fstream archivo("Personas.txt", ios::out);
    archivo << *gonzalesPedro1 << endl;

    delete gonzalesPedro1;

    try
    {
        personaBuilder
                    .setDni(12345678)
                    .setApellido("zuÒiga")
                    .setNombre("s·ul")
                    .setFechaNacimiento(Fecha(1,10,1988));
    }
    catch(PersonaException& e)
    {
        cerr << e.getMensaje() << endl;
        return 1;
    }


    Persona zunigaSaul = personaBuilder.buildEstatica();
   // cout << zunigaSaul.getApellido() << ", " << zunigaSaul.getNombre() << endl;

    archivo << zunigaSaul << endl;

    archivo.close();


    ///leo de archivo

    fstream archLectura("Personas.txt", ios::in);

    vector<Persona*>personas;


    while(archLectura.peek() != EOF)
    {
        Persona* persona = new Persona();
        archLectura >> *persona;
        personas.push_back(persona);
    }

    for(Persona* pers : personas)
    {
        cout << pers->getApellido() << ", " << pers->getNombre() << ", " << pers->getFecha() << endl;
        delete pers;
    }

    return 0;
}
