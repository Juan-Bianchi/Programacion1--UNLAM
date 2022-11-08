#ifndef TDA_PILA_H
#define TDA_PILA_H

#include<stdlib.h>

#ifdef TDA_PILA_IMPLEMENTACION_ESTATICA
    #include "../TDAPilaEstatica/PilaEstatica.h"
#endif // TDA_PILA_IMPLEMENTACION_ESTATICA

#ifdef TDA_PILA_IMPLEMENTACION_DINAMICA
    #include "../TDAPilaDinamica/PilaDinamica.h"
#endif // TDA_PILA_IMPLEMENTACION_ESTATICA*/

#ifdef TDA_PILA_CIRCULAR_IMPLEMENTACION_DINAMICA
    #include "../TDAPilaCircularDinamica/TDAPilaCircularDinamica.h"
#endif // TDA_PILA_CIRCULAR_IMPLEMENTACION_DINAMICA

void crearPila(Pila* pila);
bool apilar(Pila* pila, const void* elem, size_t tamElem);
bool desapilar(Pila* pila, void* elem, size_t tamElem);
bool verTopeDePila(const Pila* pila, void* elem, size_t tamElem);
bool pilaVacia(const Pila* pila);
bool pilaLlena(const Pila* pila, size_t tamElem);
void vaciarPila(Pila* pila);

#endif // TDA_PILA_H
