#include "Cadena.h"
#include "../Fecha/Fecha.h"

Cadena::Cadena()
{
    this->cadenaC = new char[1];
    this->cadenaC[0] = '\0';
}



Cadena::Cadena(const char* cadenaC)
{
    this->cadenaC = new char[strlen(cadenaC) + 1];
    strcpy(this->cadenaC, cadenaC);
}



Cadena::Cadena(const char letra)
{
    this->cadenaC = new char[2];
    this->cadenaC[0] = letra;
    this->cadenaC[1] = '\0';
}



Cadena::Cadena(const int num)
{
    this->cadenaC = new char[cantDigitos(num) + (num < 0 ? 1: 0)];
    sprintf(this->cadenaC, "%d", num);
}



Cadena::Cadena(const Cadena& otra)
{
    this->cadenaC = new char[strlen(otra.cadenaC) + 1];
    strcpy(this->cadenaC, otra.cadenaC);
}



///constructor privado

Cadena::Cadena(char* cadenaC)
{
    this->cadenaC = cadenaC;
}



Cadena::~Cadena()
{
    delete[] this->cadenaC;
}



Cadena& Cadena::operator =(const Cadena& cadena)
{
    if(this == &cadena)
        return *this;

    if(strlen(this->cadenaC) != strlen(cadena.cadenaC))
    {
        delete[] this->cadenaC;
        this->cadenaC = new char[strlen(cadena.cadenaC) + 1];
    }
    strcpy(this->cadenaC, cadena.cadenaC);

    return *this;
}



Cadena& Cadena::operator +=(const Cadena& cadena)
{
   /* char cadOrig[strlen(this->cadenaC)];
    strcpy(cadOrig, this->cadenaC);
    delete [] this->cadenaC;

    this->cadenaC = new char[strlen(cadOrig) + strlen(cadena.cadenaC) + 1];
    strcpy(this->cadenaC, cadOrig);
    strcat(this->cadenaC, cadena.cadenaC);*/

    //////////////////////////////////
    char* cadenaC = new char[strlen(this->cadenaC) + strlen(cadena.cadenaC) + 1];

    strcpy(cadenaC, this->cadenaC);
    strcat(cadenaC, cadena.cadenaC);
    delete [] this->cadenaC;
    this->cadenaC = cadenaC;

    return *this;
}


bool Cadena::operator ==(const Cadena& otra) const
{
    return (strcmp(this->cadenaC, otra.cadenaC) == 0)? true: false;
}



bool Cadena::operator !=(const Cadena& otra) const
{
    return (strcmp(this->cadenaC, otra.cadenaC) != 0)? true: false;
}



bool Cadena::operator <(const Cadena& otra) const
{
    return (strcmp(this->cadenaC, otra.cadenaC) < 0)? true: false;
}



bool Cadena::operator <=(const Cadena& otra) const
{
    return (strcmp(this->cadenaC, otra.cadenaC) <= 0)? true: false;
}



bool Cadena::operator >(const Cadena& otra) const
{
    return (strcmp(this->cadenaC, otra.cadenaC) > 0)? true: false;
}



bool Cadena::operator >=(const Cadena& otra) const
{
    return (strcmp(this->cadenaC, otra.cadenaC) >= 0)? true: false;
}



char& Cadena::operator[](unsigned indice)
{
    return this->cadenaC[indice];
}


const char& Cadena::operator[](unsigned indice) const
{
    return this->cadenaC[indice];
}



const char* Cadena::getCadena() const
{
    return this->cadenaC;
}



int Cadena::getLongitud() const
{
    return strlen(this->cadenaC);
}



const Cadena Cadena::toUpperCase()const
{
    Cadena cadNormalizada(*this);
    char* posicion = cadNormalizada.cadenaC;

    while(*posicion)
    {
        if(*posicion >= 'a' && *posicion <= 'z')
            *posicion -= 32;
        if(*posicion == 'á')
            *posicion = 'Á';
        if(*posicion == 'é')
            *posicion = 'É';
        if(*posicion == 'í')
            *posicion = 'Í';
        if(*posicion == 'ó')
            *posicion = 'Ó';
        if(*posicion == 'ú')
            *posicion = 'Ú';
        if(*posicion == 'ñ')
            *posicion = 'Ñ';
        if(*posicion == 'ü')
            *posicion = 'Ü';

        posicion ++;
    }

    return cadNormalizada;
}



const Cadena Cadena::toLowerCase()const
{
    Cadena cadNormalizada(*this);
    char* posicion = cadNormalizada.cadenaC;

    while(*posicion)
    {
        if(*posicion >= 'A' && *posicion <= 'Z')
            *posicion += 32;
        if(*posicion == 'Á')
            *posicion = 'á';
        if(*posicion == 'É')
            *posicion = 'é';
        if(*posicion == 'Í')
            *posicion = 'í';
        if(*posicion == 'Ó')
            *posicion = 'ó';
        if(*posicion == 'Ú')
            *posicion = 'ú';
        if(*posicion == 'Ñ')
            *posicion = 'ñ';
        if(*posicion == 'Ü')
            *posicion = 'ü';

        posicion++;
    }

    return cadNormalizada;
}



const Cadena Cadena::firstCharToUpperCase()const
{
    Cadena cadNormalizada(*this);
    char* posicion = cadNormalizada.cadenaC;

    while(*posicion)
    {
        if( (posicion == cadenaC && es_letra(*posicion)) || (posicion != cadenaC && !es_letra(*(posicion-1)) && es_letra(*posicion)) )
        {
            if(*posicion >= 'a' && *posicion <= 'z')
                *posicion -= 32;
            if(*posicion == 'á')
                *posicion = 'Á';
            if(*posicion == 'é')
                *posicion = 'É';
            if(*posicion == 'í')
                *posicion = 'Í';
            if(*posicion == 'ó')
                *posicion = 'Ó';
            if(*posicion == 'ú')
                *posicion = 'Ú';
            if(*posicion == 'ñ')
                *posicion = 'Ñ';
            if(*posicion == 'ü')
                *posicion = 'Ü';
        }
        else
        {
            if(*posicion >= 'A' && *posicion <= 'Z')
                *posicion += 32;
            if(*posicion == 'Á')
                *posicion = 'á';
            if(*posicion == 'É')
                *posicion = 'é';
            if(*posicion == 'Í')
                *posicion = 'í';
            if(*posicion == 'Ó')
                *posicion = 'ó';
            if(*posicion == 'Ú')
                *posicion = 'ú';
            if(*posicion == 'Ñ')
                *posicion = 'ñ';
            if(*posicion == 'Ü')
                *posicion = 'ü';
        }

        posicion++;
    }
    return cadNormalizada;
}



vector<Cadena> Cadena::split(char separador)const
{
    vector<Cadena> campos;
    char* iniCampo = this->cadenaC;
    char* finCampo = strchr(iniCampo, separador);

    while(finCampo)
    {
        *finCampo = '\0';
        campos.push_back(Cadena((const char*) iniCampo));

        *finCampo = separador;
        iniCampo = finCampo + 1;
        finCampo = strchr(iniCampo, separador);
    }

    campos.push_back(Cadena((const char*) iniCampo));

    return campos;
}


unsigned Cadena::toUnsigned()const
{
    unsigned numero;
    sscanf(this->cadenaC, "%u", &numero);

    return numero;
}



int Cadena::toInt()const
{
    int num;

    sscanf(this->cadenaC, "%d", &num);
    return num;
}




Fecha Cadena::toFecha()const
{
    return Fecha(*this);
}



///METODOS STATIC///
int Cadena::cantDigitos(int num)
{
    int cont = 1;

    while((num /= 10) != 0)
        cont ++;

    return cont;
}


///METODOS FRIEND///
ostream& operator <<(ostream& os, const Cadena& cadena)
{

    os << cadena.cadenaC;

    return os;
}



istream& operator >>(istream& is, Cadena& cadena)
{
    queue<char> colaChars;
    char c;

    while((c = is.get()) != '\n' && c != EOF)
        colaChars.push(c);

    delete [] cadena.cadenaC;
    cadena.cadenaC = new char[colaChars.size() + 1];


    int i=0;
    while(!colaChars.empty())
    {
        cadena.cadenaC[i++] = colaChars.front();
        colaChars.pop();
    }

    cadena.cadenaC[i] = '\0';

    return is;
}



/* Version sin constructor privado
Cadena operator +(const Cadena& cad1, const Cadena& cad2)
{
    Cadena cadConcat;

    delete[] cadConcat.cadenaC;
    cadConcat.cadenaC = new char[strlen(cad1.cadenaC) + strlen(cad2.cadenaC) + 1];

    strcpy(cadConcat.cadenaC, cad1.cadenaC);
    strcat(cadConcat.cadenaC, cad2.cadenaC);

    return cadConcat;
}
*/

Cadena operator +(const Cadena& cad1, const Cadena& cad2)
{
    char* cadenaConcat = new char[strlen(cad1.cadenaC) + strlen(cad2.cadenaC) + 1];
    strcpy(cadenaConcat, cad1.cadenaC);
    strcat(cadenaConcat, cad2.cadenaC);

    return Cadena(cadenaConcat);
}
