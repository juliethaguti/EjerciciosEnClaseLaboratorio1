#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#include "ArrayList.h"
#include "Vista.h"
#include "Controlador.h"
#include "Llamadas.h"

static int idiomaVista;
static void opcionAltaLlamada();
static void opcionImprimirLlamadas();
static void opcionMostrarEstadisticas();
static void opcionGenerarArchivoDeClientes();

int vista_init (int idioma)
{
    idiomaVista = idioma;
    return 0;
}

int vista_mostrarMenu()
{
    char buffer[10];
    int option=0;

    while(option != 5)
    {
        //system("cls");
        val_getInt(buffer, MENU_PPAL_ES, MENU_PPAL_ERROR_ES,2,5);
        option = atoi(buffer);

        switch(option)
        {
            case 1:
                opcionAltaLlamada();
                break;
            case 2:
                opcionImprimirLlamadas();
                break;
            case 3:
                opcionMostrarEstadisticas();
                break;
            case 4:
                opcionGenerarArchivoDeClientes();
                break;
        }
    }

    return 0;
}

static void opcionAltaLlamada()
{
    char nombreArchivo[10];
    val_getDescripcion(nombreArchivo,"Ingrese el nombre del archivo: ","Error",2,10);
    cont_altaLlamada(nombreArchivo);
}

static void opcionImprimirLlamadas()
{
    cont_listarLlamada();
}

void vista_mostrarLlamadas(ArrayList* pListaLlamada)
{
    int i;
    Llamadas* auxLlamada;

    //al_sort(pListaLlamada,llamadas_compareByIdLlamada,1);
    al_sort(pListaLlamada,llamadas_compareByDniCliente,1);
    //al_sort(pListaLlamada,llamadas_compareByProducto,1);

    for(i = 0; i < al_len(pListaLlamada); i++)
    {
        auxLlamada = al_get(pListaLlamada,i);

        printf("\nID LLAMADA: %d NOMBRE CLIENTE: %s EMAIL: %s DNI: %s \nPRODUCTO: %s OBSERVACIONES %s",
               llamadas_getIdLlamada(auxLlamada),llamadas_getNombreCliente(auxLlamada),llamadas_getEmailCliente(auxLlamada),
               llamadas_getDniCliente(auxLlamada),llamadas_getProducto(auxLlamada),llamadas_getObservaciones(auxLlamada));
    }
}

static void opcionMostrarEstadisticas()
{
    cont_informarEstadisticas();
}

void vista_mostraClientebyDni(ArrayList* pListaLlamada,char* dni)
{
    Llamadas* llamada;
    llamada = llamadas_findByDniCliente(pListaLlamada,dni);
    printf("\n\nEl Cliente mas intenso es: %s con dni %s",llamadas_getNombreCliente(llamada),dni);
}

void vista_mostrarProductoMasConsultado(char* producto)
{
    printf("\n\nEl producto mas consultado es : %s",producto);

}

static void opcionGenerarArchivoDeClientes()
{
    cont_generarArchivosDeClientes();
}
