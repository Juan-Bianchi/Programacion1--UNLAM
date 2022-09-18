#include "ordenamientoGenerico.h"

void intercambiar(void* elem1, void* elem2, size_t tamElem);


void ordenarSeleccion(void* v, int ce, size_t tamElem, Cmp cmp) //le puedo mandar cualquier cosa. Cmp como tipo de dato
{
    void* actual = v, * ultimo = v + (ce-1)*tamElem;
    void* min = v;

    for(;actual < ultimo; actual+=tamElem)
    {
        min = buscarMenor(actual, ultimo, tamElem, cmp);
        if(min != actual)
            intercambiar(actual, min, tamElem);
    }
}



void* buscarMenor(void* ini, void* fin, size_t tamElem, Cmp cmp)
{
    void* min = ini;
    void* actual = ini + tamElem;

    for(; actual < fin; actual+=tamElem)
    {
        if(cmp(actual, min) < 0)
            min = actual;
    }

    return min;
}




void intercambiar(void* elem1, void* elem2, size_t tamElem)
{
    char aux[tamElem];

    memcpy(aux, elem1, tamElem);
    memcpy(elem1, elem2, tamElem);
    memcpy(elem2, aux, tamElem);
}
