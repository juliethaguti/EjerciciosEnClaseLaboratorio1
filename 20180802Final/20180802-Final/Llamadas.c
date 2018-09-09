
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Llamadas.h"

Llamadas* llamadas_new(int idLlamada,char* nombreCliente,char* emailCliente,char* dniCliente,char* producto,char* observaciones)
{
        Llamadas* this = malloc(sizeof(Llamadas));

        if(this != NULL)
        {

                llamadas_setIdLlamada(this,idLlamada);
                llamadas_setNombreCliente(this,nombreCliente);
                llamadas_setEmailCliente(this,emailCliente);
                llamadas_setDniCliente(this,dniCliente);
                llamadas_setProducto(this,producto);
                llamadas_setObservaciones(this,observaciones);
        }
        return this;
}

void llamadas_delete(Llamadas* this)
{
        free(this);
}

int llamadas_setIdLlamada(Llamadas* this,int idLlamada)
{
        this->idLlamada = idLlamada;
        return 0;
}

int llamadas_setNombreCliente(Llamadas* this,char* nombreCliente)
{
        strcpy(this->nombreCliente,nombreCliente);
        return 0;
}

int llamadas_setEmailCliente(Llamadas* this,char* emailCliente)
{
        strcpy(this->emailCliente,emailCliente);
        return 0;
}

int llamadas_setDniCliente(Llamadas* this,char* dniCliente)
{
        strcpy(this->dniCliente,dniCliente);
        return 0;
}

int llamadas_setProducto(Llamadas* this,char* producto)
{
        strcpy(this->producto,producto);
        return 0;
}

int llamadas_setObservaciones(Llamadas* this,char* observaciones)
{
        strcpy(this->observaciones,observaciones);
        return 0;
}

int llamadas_getIdLlamada(Llamadas* this)
{
        return this->idLlamada;
}

char* llamadas_getNombreCliente(Llamadas* this)
{
        return this->nombreCliente;
}

char* llamadas_getEmailCliente(Llamadas* this)
{
        return this->emailCliente;
}

char* llamadas_getDniCliente(Llamadas* this)
{
        return this->dniCliente;
}

char* llamadas_getProducto(Llamadas* this)
{
        return this->producto;
}

char* llamadas_getObservaciones(Llamadas* this)
{
        return this->observaciones;
}

Llamadas* llamadas_findByIdLlamada(ArrayList* pArray,int idLlamada)
{

        int i;
        Llamadas* aux;
        Llamadas* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(idLlamada == llamadas_getIdLlamada(aux))
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

Llamadas* llamadas_findByNombreCliente(ArrayList* pArray,char* nombreCliente)
{

        int i;
        Llamadas* aux;
        Llamadas* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(strcmp(nombreCliente,llamadas_getNombreCliente(aux))==0)
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

Llamadas* llamadas_findByEmailCliente(ArrayList* pArray,char* emailCliente)
{

        int i;
        Llamadas* aux;
        Llamadas* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(strcmp(emailCliente,llamadas_getEmailCliente(aux))==0)
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

Llamadas* llamadas_findByDniCliente(ArrayList* pArray,char* dniCliente)
{

        int i;
        Llamadas* aux;
        Llamadas* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(strcmp(dniCliente,llamadas_getDniCliente(aux))==0)
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

Llamadas* llamadas_findByProducto(ArrayList* pArray,char* producto)
{

        int i;
        Llamadas* aux;
        Llamadas* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(strcmp(producto,llamadas_getProducto(aux))==0)
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

Llamadas* llamadas_findByObservaciones(ArrayList* pArray,char* observaciones)
{

        int i;
        Llamadas* aux;
        Llamadas* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(strcmp(observaciones,llamadas_getObservaciones(aux))==0)
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

int llamadas_compareByIdLlamada(void* pA ,void* pB)
{

        int retorno = 0;

        if(llamadas_getIdLlamada(pA) > llamadas_getIdLlamada(pB))
                retorno = 1;
        else if(llamadas_getIdLlamada(pA) < llamadas_getIdLlamada(pB))
                retorno = -1;

        return retorno;
}

int llamadas_compareByNombreCliente(void* pA ,void* pB)
{

        int retorno;

        retorno = strcmp(llamadas_getNombreCliente(pA),llamadas_getNombreCliente(pB));

        return retorno;
}

int llamadas_compareByEmailCliente(void* pA ,void* pB)
{

        int retorno;

        retorno = strcmp(llamadas_getEmailCliente(pA),llamadas_getEmailCliente(pB));

        return retorno;
}

int llamadas_compareByDniCliente(void* pA ,void* pB)
{

        int retorno;

        retorno = strcmp(llamadas_getDniCliente(pA),llamadas_getDniCliente(pB));

        return retorno;
}

int llamadas_compareByProducto(void* pA ,void* pB)
{

        int retorno;

        retorno = strcmp(llamadas_getProducto(pA),llamadas_getProducto(pB));

        return retorno;
}

int llamadas_compareByObservaciones(void* pA ,void* pB)
{

        int retorno;

        retorno = strcmp(llamadas_getObservaciones(pA),llamadas_getObservaciones(pB));

        return retorno;
}
