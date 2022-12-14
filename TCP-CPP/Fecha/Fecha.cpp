#include "Fecha.h"
#include "fechainvalidaexception.h"
#include "../Cadena/Cadena.h"


int Fecha::cantDM[13]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int Fecha::vecDiaAcum[14] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
int Fecha::vecDiaAcumBis[14] = {0, 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 365};



void Fecha::setDma(int dia, int mes, int anio)
{
    if(!esFechaValida(dia, mes, anio))
        throw FECHA_INVALIDA;

    int cantTotAnios = anio - ANIO_BASE;
    int diaTot = cantTotAnios * 365 + cantTotAnios / 4 - cantTotAnios / 100 + cantTotAnios / 400;
    this->diaRel = diaTot + diasDelAnio(dia, mes, anio);
}



void Fecha::getDma(int& dia, int& mes, int& anio) const
{
    int anioAcumTot = this->diaRel / 365;
    int diasAcumTot = anioAcumTot * 365 + anioAcumTot / 400 + anioAcumTot / 4 - anioAcumTot / 100;

    while (diasAcumTot >= this->diaRel)
    {
        anioAcumTot --;
        diasAcumTot = anioAcumTot * 365 + anioAcumTot / 400 + anioAcumTot / 4 - anioAcumTot / 100;
    }

    anio = anioAcumTot + ANIO_BASE;

    int diaDelAnio = this->diaRel - diasAcumTot;

    diaDelAnioADiaMes(diaDelAnio, dia, mes, anio);
}



int Fecha::diasDelAnio(int dia, int mes, int anio)
{
    return esBisiesto(anio) && mes >= 2? dia + vecDiaAcumBis[mes]: dia + vecDiaAcum[mes];
}




void Fecha::diaDelAnioADiaMes(int diasAcum, int& dia, int& mes, int anio)
{
    int* pVecDiaAcum = esBisiesto(anio)? vecDiaAcumBis: vecDiaAcum;
    int m=0;

    while(*pVecDiaAcum < diasAcum)
    {
        pVecDiaAcum ++;
        m++;
    }
    m --;
    pVecDiaAcum --;

    mes = m;
    dia = diasAcum - *pVecDiaAcum;
}


int Fecha::cantDiasDelMes(int mes, int anio)
{
    if(esBisiesto(anio) && mes == 2)
        return 29;

    return cantDM[mes];
}



bool Fecha::esFechaValida(int dia, int mes, int anio)
{
    if(anio > 1601)
    {
        if(mes >= 1 && mes <=12)
            if(dia <= cantDiasDelMes(mes, anio))
                return true;
    }
    return false;
}




Fecha::Fecha()
{
    this->diaRel = 1;
}



Fecha::Fecha(int dia, int mes, int anio)
{
    setDma(dia, mes, anio);
}


Fecha::Fecha(const Cadena& cad)
{
    int dia, mes, anio;

    vector<Cadena> campos = cad.split('/');

    dia = campos[0].toInt();
    mes = campos[1].toInt();
    anio = campos[2].toInt();

    setDma(dia, mes, anio);
}



Fecha Fecha::sumarDias(int dias) const
{
    Fecha fechaSuma;

    fechaSuma.diaRel = this->diaRel + dias;

    return fechaSuma;
}



Fecha Fecha::restarDias(int dias)
{
    Fecha fechaResta;

    fechaResta.diaRel = this->diaRel - dias;

    return fechaResta;
}



int Fecha::diferenciaDias(const Fecha* fecha)
{
    return this->diaRel - fecha->diaRel;
}



int Fecha::diaDeLaSemana()const
{
    return this->diaRel % 7;
}



void Fecha::incrementarDia()
{
    this->diaRel += 1;
}



Fecha Fecha::operator +(int dias) const
{
    Fecha f;

    f.diaRel += dias;

    return f;
}



Fecha& Fecha::operator += (int dias)
{
    this->diaRel += dias;

    return *this;
}



Fecha& Fecha::operator -= (int dias)
{
    this->diaRel -= dias;

    return *this;
}



Fecha Fecha::operator -(int dias)const
{
    Fecha f(*this);

    if(f.diaRel - dias < 1)
        throw FechaInvalidaException("La fecha no es valida.");

    f.diaRel -= dias;

    return f;
}



int Fecha::operator -(const Fecha& f2)const
{
    return this->diaRel - f2.diaRel;
}



Fecha& Fecha::operator ++()
{
    ++ this->diaRel;

    return *this;
}



Fecha Fecha::operator ++(int)
{
    Fecha fPre(*this);

    this->diaRel ++;

    return fPre;
}



Fecha& Fecha::operator --()
{
    -- this->diaRel;

    return *this;
}



Fecha Fecha::operator --(int)
{
    Fecha fPrev(*this);

    this->diaRel --;

    return fPrev;
}



ostream& operator << (ostream& os, const Fecha& fecha)
{
    int dia, mes, anio;

    fecha.getDma(dia, mes, anio);

    os << dia << "/" << mes << "/" << anio;

    return os;
}



istream& operator >>(istream& is, Fecha& fecha)
{
    int dia, mes, anio;
    char barra;

    cin >> dia >> barra >> mes >> barra >> anio;

    fecha.setDma(dia, mes, anio);

    return is;
}
