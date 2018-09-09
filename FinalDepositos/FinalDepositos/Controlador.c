#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "DataManager.h"
#include "Vista.h"
#include "Depositos.h"

static ArrayList* listaDepositoUno;
static ArrayList* listaDepositoDos;
static int cont_buscarProductosEnAlmacen(int codigoProducto);

void cont_init()
{
    listaDepositoUno = al_newArrayList();
    listaDepositoDos = al_newArrayList();
    vista_init(VISTA_IDIOMA_ES);
    vista_mostrarMenu();
}

int cont_altaDepositos()
{
    dm_readAllDepositoDos(listaDepositoDos);
    return dm_readAllDepositoUno(listaDepositoUno);
}

void cont_listarProductos(int deposito)
{
    if(deposito == 1)
    {
        vista_mostrarDeposito(listaDepositoUno);
    }
    else if (deposito == 2)
    {
        vista_mostrarDeposito(listaDepositoDos);
    }

}

int cont_moverProductosDeDesposito(int depositoOrigen,int depositoDestino,int codigoProducto)
{
    int retorno = -1;
    Depositos* elemento;
    if(depositoOrigen == 1)
    {
        retorno = cont_buscarProductoEnDeposito(listaDepositoUno, codigoProducto);
        if(!(retorno < 0))
        {
            elemento = al_pop(listaDepositoUno,retorno);
            al_add(listaDepositoDos,elemento);
        }
    }
    else if(depositoOrigen == 2)
    {
        retorno = cont_buscarProductoEnDeposito(listaDepositoDos,codigoProducto);
        if(!(retorno < 0))
        {
            elemento = al_pop(listaDepositoDos,retorno);
            al_add(listaDepositoUno,elemento);
        }
    }
    return retorno;
}

int cont_buscarProductoEnDeposito(ArrayList* listaDeposito,int codigoProducto)
{



    int i;
    int retorno = -1;
    Depositos* auxDeposito = NULL;
    int auxCodigoProducto;

    for(i = 0; i < al_len(listaDeposito); i++)
    {
        auxDeposito = al_get(listaDeposito,i);
        auxCodigoProducto = depositos_getIdProducto(auxDeposito);

        if(codigoProducto == auxCodigoProducto)
        {
            retorno = al_indexOf(listaDeposito,auxDeposito);
            break;
        }
    }
    return retorno;
}

int cont_descontarProducto(int codigoProducto, int cantidad)
{
    int deposito = -1;
    Depositos* auxDeposito;
    int cantidadTotalProducto;

    deposito = cont_buscarProductosEnAlmacen(codigoProducto);
    if(deposito == 1)
    {
        auxDeposito = depositos_findByIdProducto(listaDepositoUno,codigoProducto);
        cantidadTotalProducto = depositos_getCantidad(auxDeposito);
        cantidadTotalProducto = cantidadTotalProducto - cantidad;
        if(cantidadTotalProducto >= 0)
        {
            depositos_setCantidad(auxDeposito,cantidadTotalProducto);
        }
        else
        {
            printf("No hay suficiente producto para descontar");
        }
    }
    else if(deposito == 2)
    {
        auxDeposito = depositos_findByIdProducto(listaDepositoDos,codigoProducto);
        cantidadTotalProducto = depositos_getCantidad(auxDeposito);
        cantidadTotalProducto = cantidadTotalProducto - cantidad;
        if(cantidadTotalProducto >= 0)
        {
            depositos_setCantidad(auxDeposito,cantidadTotalProducto);
        }
        else
        {
            printf("No hay suficiente producto para descontar");
        }
    }
    return deposito;
}

int cont_buscarProductosEnAlmacen(int codigoProducto)
{
    int retorno = -1;
    int i,j;
    Depositos* auxDeposito;
    int auxCodigoProducto;
    int flag = 0;

    for(i = 0; i < al_len(listaDepositoUno); i++)
    {
        auxDeposito = al_get(listaDepositoUno,i);
        auxCodigoProducto = depositos_getIdProducto(auxDeposito);
        if(codigoProducto == auxCodigoProducto)
        {
            retorno = 1;
            flag = 1;
        }
    }
    if(flag == 0)
    {
        for(j = 0; j < al_len(listaDepositoDos); j++)
        {
            auxDeposito = al_get(listaDepositoDos,j);
            auxCodigoProducto = depositos_getIdProducto(auxDeposito);
            if(codigoProducto == auxCodigoProducto)
            {
                retorno = 2;
            }
        }
    }
    return retorno;
}
