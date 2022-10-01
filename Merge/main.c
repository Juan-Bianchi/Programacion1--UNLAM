#include <stdio.h>
#include <stdlib.h>

#include "Merge.h"

#define CANT_PROD 15

int main(int argc, char* argv[])
{
    Idx index[CANT_PROD] = {{"00", "Higo"}, {"01", "Kiwi"}, {"02", "Limon"}, {"03", "Damazco"}, {"04", "Banana"}, {"05", "Pomelo"},
                            {"06", "Pelon"}, {"07", "Pera"}, {"08", "Uva"}, {"09", "Manzana"}, {"10", "Arandano"}, {"11", "Mango"},
                            {"12", "Naranja"}, {"13", "Frutilla"}, {"14", "Durazno"}, {"15", "Mandarina"}};
    Producto prod, arrProds[6] = {{"00", "Higo", 120.50, 100}, {"04", "Banana", 80.50, 100}, {"07", "Pera", 50.50, 50},
                                          {"09", "Manzana", 70.50, 70}, {"10", "Arandano", 60.50, 30}, {"14", "Durazno", 90.50, 90}};
    Movimiento mov, arrMovs[11] = {{"01", 20}, {"07", 20}, {"07", -10}, {"08", 40}, {"10", 40}, {"10", 20}, {"11", 50}, {"12", 60},
                                    {"12", -10}, {"15", 80}, {"15", 40}};
    int comp, cantCargados;
    FILE* archMovs, * archProd, * archProdsTmp, * archIndx;

    archIndx = fopen(argv[1], argv[7]);
    if(!archIndx)
    {
        printf("El archivo '%s' no ha podido ser abierto en modo '%s'. Se cerrará el programa.", argv[1], argv[7]);
        return -1;
    }

    archMovs = fopen(argv[2], argv[7]);
    if(!archMovs)
    {
        printf("El archivo '%s' no ha podido ser abierto en modo '%s'. Se cerrará el programa.", argv[2], argv[7]);
        return -1;
    }

    archProd = fopen(argv[3], argv[7]);
    if(!archProd)
    {
        printf("El archivo '%s' no ha podido ser abierto en modo '%s'. Se cerrará el programa.", argv[3], argv[7]);
        return -1;
    }

    archProdsTmp = fopen(argv[8], argv[7]);
    if(!archProdsTmp)
    {
        printf("El archivo '%s' no ha podido ser abierto en modo '%s'. Se cerrará el programa.", argv[8], argv[7]);
        return -1;
    }


    fwrite(&index, sizeof(Idx), 15, archIndx);
    fwrite(&arrProds, sizeof(Producto), 6, archProd);
    fwrite(&arrMovs, sizeof(Movimiento), 11, archMovs);

    fseek(archProd, 0L, SEEK_SET);
    fseek(archMovs, 0L, SEEK_SET);



    return 0;
}
