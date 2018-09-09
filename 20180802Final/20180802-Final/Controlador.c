#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "DataManager.h"
#include "Vista.h"
#include "Llamadas.h"
#include "Informes.h"

static ArrayList* listaLlamada;
static ArrayList* listaClientes;


void cont_init()
{
    listaLlamada = al_newArrayList();
    //listaService = al_newArrayList();
    vista_init(VISTA_IDIOMA_ES);
    vista_mostrarMenu();
}

int cont_altaLlamada(char* nombreArchivo)
{
    return dm_readAllLlamadaArchivo(listaLlamada,nombreArchivo);
}

void cont_listarLlamada()
{
    vista_mostrarLlamadas(listaLlamada);
}

void  cont_informarEstadisticas()
{
    char* auxDni;
    char* auxProducto;
    auxDni = info_clientesConMasLlamados(listaLlamada);
    vista_mostraClientebyDni(listaLlamada,auxDni);
    auxProducto = info_productoMasConsultado(listaLlamada);
    vista_mostrarProductoMasConsultado(auxProducto);
}

void cont_generarArchivosDeClientes()
{
    int i,j;
    Llamadas *auxLlamada;
    Llamadas *auxLlamada2;
    listaClientes = al_clone(listaLlamada);
    char* auxDni;
    char* auxDni2;

    for(i = 0; i < (al_len(listaClientes)-1); i++)
    {
        auxLlamada = al_get(listaClientes,i);
        auxDni = llamadas_getDniCliente(auxLlamada);

        for(j = i + 1;j < al_len(listaClientes); j++)
        {
            auxLlamada2 = al_get(listaClientes,j);
            auxDni2 = llamadas_getDniCliente(auxLlamada2);

            if((strcmp(auxDni2,auxDni)) == 0)
            {
                al_remove(listaClientes,al_indexOf(listaClientes,auxLlamada2));
            }
        }
    }
    dm_saveClientes(listaClientes);
}
