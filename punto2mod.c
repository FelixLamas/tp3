#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void cargarNombres(char **listado, int cantN);
void mostarNombre(char **listado, int cantN);

int main(int argc, char const *argv[])
{
    char *listadoNombres;
    int cantNombres;
    printf("Coloque la cantidad de nombres que desea ingresar:");
    scanf("%d", &cantNombres);
    getchar();
    listadoNombres = (char *)malloc(sizeof(char) * cantNombres);
    cargarNombres(listadoNombres, cantNombres);
    mostarNombre(listadoNombres, cantNombres);
    free(listadoNombres);
    getchar();
    return 0;
}

void cargarNombres(char **listado, int cantN)
{
    char buff[20];
    for (int i = 0; i < cantN; i++)
    {
        printf("Ingrese el Nombre:");
        gets(buff);
        *(listado+i) = (char *)malloc(sizeof(char)* strlen(buff));
        strcpy(*(listado+i), buff);
    }    
}

void mostarNombre(char **listado, int cantN)
{
    for (int i = 0; i < cantN; i++)
    {
        printf("El nombre ingresado es %s\n", *(listado+i));
        free(*(listado+i));
    }
}