#ifndef MERGE_H_INCLUDED
#define MERGE_H_INCLUDED

typedef struct
{
    char codigo[11];
    char descripcion[11];
    float precio;
    int stock;
} Producto;

typedef struct
{
    char cod[11];
    int mov;
} Movimiento;

typedef struct
{
    char codig[11];
    char desc[11];
} Idx;

int (*Cmp)(const void* elem1, const void* elem2);



#endif // MERGE_H_INCLUDED
