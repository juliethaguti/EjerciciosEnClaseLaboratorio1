#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#include "ArrayList.h"
#include "Vista.h"
#include "Controlador.h"
#include "Depositos.h"

static int idiomaVista;
static void opcionCargarDepositos();
static void opcionListarProductosDeDeposito();
static void opcionMoverProductosADeposito();
static void opcionDescontarProductosDeDeposito();

int vista_init (int idioma)
{
    idiomaVista = idioma;
    return 0;
}

int vista_mostrarMenu()
{
    char buffer[10];
    int option=0;

    while(option != 6)
    {
        //system("cls");
        val_getInt(buffer, MENU_PPAL_ES, MENU_PPAL_ERROR_ES,2,5);
        option = atoi(buffer);

        switch(option)
        {
            case 1:
                opcionCargarDepositos();
                break;
            case 2:
                opcionListarProductosDeDeposito();
                break;
            case 3:
                opcionMoverProductosADeposito();
                break;
            case 4:
                opcionDescontarProductosDeDeposito();
                break;
        }
    }

    return 0;
}

static void opcionCargarDepositos()
{
    cont_altaDepositos();
}

static void opcionListarProductosDeDeposito()
{
    char numeroDeposito[5];
    val_getInt(numeroDeposito,"Ingrese numero de deposito: ","Error",2,5);
    cont_listarProductos(atoi(numeroDeposito));
}

void vista_mostrarDeposito(ArrayList* listaDeposito)
{
    int i;
    Depositos* auxDeposito;

    for(i = 0; i < al_len(listaDeposito); i++)
    {
        auxDeposito = al_get(listaDeposito,i);

        printf("\nID PRODUCTO: %d PRODUCTO: %s CANTIDAD: %d ",depositos_getIdProducto(auxDeposito),depositos_getDescripcion(auxDeposito),depositos_getCantidad(auxDeposito));
    }
}

static void opcionMoverProductosADeposito()
{
    char depositoOrigen[10];
    char depositoDestino[10];
    char codigoProducto[10];

    val_getInt(depositoOrigen,"Ingrese numero de deposito de Origen","Error",2,10);
    val_getInt(depositoDestino,"Ingrese el numero de deposito de destino","Error",2,10);
    val_getInt(codigoProducto,"Ingrese el codigo de producto a trapasar","Error",2,10);
    cont_moverProductosDeDesposito(atoi(depositoOrigen),atoi(depositoDestino),atoi(codigoProducto));
}

static void opcionDescontarProductosDeDeposito()
{
    char codigoProducto[10];
    char cantidad[10];

    val_getInt(codigoProducto,"Ingrese el codigo de producto a descontar","Error",2,10);
    val_getInt(cantidad,"Ingrese la cantidad a descontar","Error",2,10);
    cont_descontarProducto(atoi(codigoProducto),atoi(cantidad));
}
