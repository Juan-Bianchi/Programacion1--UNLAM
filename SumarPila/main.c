#include <stdio.h>
#include <stdlib.h>



// Sumar 9947389 57267

int main(int argc, char* argv[])
{

    system("chcp 1252 > 0");

    if(argc != 3)
    {
        printf("Error: debe ingresar dos números enteros como argumentos.\n");
        return 1;
    }

    char* suma = sumarNumeros(argv[1], argv[2], suma);


    return 0;
}


char* sumarNumeros(const char* num1, const char* num2)
{

}
