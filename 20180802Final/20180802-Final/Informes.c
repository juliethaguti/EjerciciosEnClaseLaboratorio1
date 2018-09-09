#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Informes.h"
#include "Llamadas.h"

char* info_clientesConMasLlamados(ArrayList* pListaLlamados)
{
    int i,j;
    int contador = 0;
    int recordMax = 0;
    Llamadas* auxLlamada;
    Llamadas* auxLlamada2;
    char* auxDni;
    char* auxDni2;
    char* retorno;

    for(i = 0; i < al_len(pListaLlamados); i++)
    {
        auxLlamada = al_get(pListaLlamados,i);
        auxDni = llamadas_getDniCliente(auxLlamada);

        for(j = 0;j < al_len(pListaLlamados); j++)
        {
            auxLlamada2 = al_get(pListaLlamados,j);
            auxDni2 = llamadas_getDniCliente(auxLlamada2);
            if(!(llamadas_compareByDniCliente(auxDni2,auxDni)))
            {
                contador++;
            }
        }
        if(contador > recordMax)
        {
            recordMax = contador;
            contador = 0;
            retorno = auxDni;
        }
        else
        {
            contador = 0;
        }
    }
    return retorno;
}

char* info_productoMasConsultado(ArrayList* pListaLlamados)
{
    int i,j;
    int contador = 0;
    int recordMax = 0;
    Llamadas* auxLlamada;
    Llamadas* auxLlamada2;
    char* auxProducto;
    char* auxProducto2;
    char* retorno;

    for(i = 0; i < al_len(pListaLlamados); i++)
    {
        auxLlamada = al_get(pListaLlamados,i);
        auxProducto = llamadas_getProducto(auxLlamada);

        for(j = 0;j < al_len(pListaLlamados); j++)
        {
            auxLlamada2 = al_get(pListaLlamados,j);
            auxProducto2 = llamadas_getProducto(auxLlamada2);

            if((llamadas_compareByProducto(auxProducto2,auxProducto)) != 0)
            {
                contador++;
            }
        }
        if(contador > recordMax)
        {
            recordMax = contador;
            contador = 0;
            retorno = auxProducto;
        }
        else
        {
            contador = 0;
        }
    }
    return retorno;
}
