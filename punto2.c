#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TAM 5

void cargarNombres(char **p);

int main(int argc, char const *argv[])
{
    char *p[TAM];
    cargarNombres(p);
    getchar();
    return 0;
}

void cargarNombres(char **p)
{
    char buff[20];
    for (int i = 0; i < TAM; i++)
    {
        printf("Ingrese el Nombre:");
        gets(buff);
        *(p+i) = (char *)malloc(sizeof(char)* strlen(buff));
        strcpy(*(p+i), buff);
    }
    
    for (int i = 0; i < TAM; i++)
    {
        printf("El nombre ingresado es %s\n", *(p+i));
    }
    
}