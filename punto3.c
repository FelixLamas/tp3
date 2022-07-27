/*
Considere la siguiente situación: En una distribuidora necesita implementar la carga de
productos de sus preventistas, los cuales recolectan los productos que sus clientes van
necesitando. El sistema que se utiliza en la empresa es desarrollado por equipos de
programadores donde cada equipo se encarga de una tarea específica. Usted forma parte del
equipo de programación que se encargará de hacer el módulo para los preventistas:
Tareas:
Cada preventista puede visitar hasta 5 clientes, los cuales por cuestiones operativas solo
puede pedir hasta 10 productos
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct Producto {
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    int PrecioUnitario; // entre 10 - 100
}Producto;
typedef struct Cliente {
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos //El tamaño de este arreglo depende de la variable CantidadProductosAPedir
} Cliente;

int ControlCantClientes(void);
void CargarClientes(Cliente *arreglo,int Cant, char **tipoP);
void mostrarPedidoCliente(Cliente *arregloC, int cantc);
int costoTotalProducto(Producto prod);
int main(int argc, char const *argv[])
{
    char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
    int CantClientes; //cantidad de clientes
    CantClientes = ControlCantClientes();//funcion que controla cantidad de clientes
    Cliente *arregloCliente;
    arregloCliente = (Cliente *)malloc(sizeof(Cliente)* CantClientes);
    CargarClientes(arregloCliente, CantClientes, TiposProductos);
    mostrarPedidoCliente(arregloCliente, CantClientes);
    free(arregloCliente);
    return 0;
}

int ControlCantClientes(void)
{
    int num;
    printf("Ingrese la cantidad de clientes, recuerde que no puede ser mayor a 5:");
    scanf("%d", &num);
    if (num>=1 && num<=5) // bloque que controla el intervalo de clientes
    {
        return num;
    }
    else
    {
        return ControlCantClientes();
    }    
}

void CargarClientes(Cliente *arreglo,int Cant, char **tipoP)
{
    char buff[100], buffP[12];
    int cantProd = 0;
    srand(time(NULL));
    for (int i = 0; i < Cant; i++)
    {
        arreglo[i].ClienteID = i + 1;
        printf("Ingrese el nombre y apellido del cliente");
        scanf("%s", buff);
        arreglo[i].NombreCliente = (char *)malloc(sizeof(char)*strlen(buff));
        strcpy(arreglo[i].NombreCliente, buff);
        arreglo[i].CantidadProductosAPedir = 1 + rand() % 5;
        cantProd = arreglo[i].CantidadProductosAPedir;
        arreglo[i].Productos = (Producto *)malloc(sizeof(Producto) * cantProd);
        for (int j = 0; j < cantProd; j++)
        {
            arreglo[i].Productos[j].ProductoID = (j + 1);
            arreglo[i].Productos[j].Cantidad = 1 + rand() % 10;
            strcpy(buffP, *(tipoP + (rand() % 4)));
            arreglo[i].Productos[j].TipoProducto =(char*) malloc(sizeof(char)* strlen(buffP));
            strcpy(arreglo[i].Productos[j].TipoProducto, buffP);
            arreglo[i].Productos[j].PrecioUnitario = 10 + rand() % 90;
        }
        
    }    
}


void mostrarPedidoCliente(Cliente *arregloC, int cantc)
{
    int total;
    for (int i = 0; i < cantc; i++)
    {
        total = 0;
        printf("Id del cliente: %d\n", arregloC[i].ClienteID);
        printf("El nombre del cliente: %s\n", arregloC[i].NombreCliente);
        printf("Cantidad de productos %d\n", arregloC[i].CantidadProductosAPedir);
        for (int j = 0; j < arregloC[i].CantidadProductosAPedir; j++)
        {
            printf("id del producto:%d\n", arregloC[i].Productos[j].ProductoID);
            printf("cantidad del producto:%d\n", arregloC[i].Productos[j].Cantidad);
            printf("Tipo de producto: %s\n", arregloC[i].Productos[j].TipoProducto);
            printf("precio unitario del producto:%d\n", arregloC[i].Productos[j].PrecioUnitario);
            total = total + costoTotalProducto(arregloC[i].Productos[j]);
            free(arregloC[i].Productos[j].TipoProducto);
        }
        printf("El costo total de los productos es:%d\n", total);
        free(arregloC[i].NombreCliente);
    }
    
}

int costoTotalProducto(Producto prod)
{
    return prod.Cantidad * prod.PrecioUnitario;
}