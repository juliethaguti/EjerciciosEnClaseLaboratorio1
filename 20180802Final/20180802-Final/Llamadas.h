#include "ArrayList.h"

#ifndef _LLAMADAS_H
#define _LLAMADAS_H
typedef struct
{
        int idLlamada;
        char nombreCliente[50];
        char emailCliente[50];
        char dniCliente[50];
        char producto[50];
        char observaciones[500];
}Llamadas;
#endif// _LLAMADAS_H

Llamadas* llamadas_new(int idLlamada,char* nombreCliente,char* emailCliente,char* dniCliente,char* producto,char* observaciones);
void llamadas_delete(Llamadas* this);
int llamadas_setIdLlamada(Llamadas* this,int idLlamada);
int llamadas_setNombreCliente(Llamadas* this,char* nombreCliente);
int llamadas_setEmailCliente(Llamadas* this,char* emailCliente);
int llamadas_setDniCliente(Llamadas* this,char* dniCliente);
int llamadas_setProducto(Llamadas* this,char* producto);
int llamadas_setObservaciones(Llamadas* this,char* observaciones);
int llamadas_getIdLlamada(Llamadas* this);
char* llamadas_getNombreCliente(Llamadas* this);
char* llamadas_getEmailCliente(Llamadas* this);
char* llamadas_getDniCliente(Llamadas* this);
char* llamadas_getProducto(Llamadas* this);
char* llamadas_getObservaciones(Llamadas* this);
Llamadas* llamadas_findByIdLlamada(ArrayList* pArray,int idLlamada);
Llamadas* llamadas_findByNombreCliente(ArrayList* pArray,char* nombreCliente);
Llamadas* llamadas_findByEmailCliente(ArrayList* pArray,char* emailCliente);
Llamadas* llamadas_findByDniCliente(ArrayList* pArray,char* dniCliente);
Llamadas* llamadas_findByProducto(ArrayList* pArray,char* producto);
Llamadas* llamadas_findByObservaciones(ArrayList* pArray,char* observaciones);
int llamadas_compareByIdLlamada(void* pA ,void* pB);
int llamadas_compareByNombreCliente(void* pA ,void* pB);
int llamadas_compareByEmailCliente(void* pA ,void* pB);
int llamadas_compareByDniCliente(void* pA ,void* pB);
int llamadas_compareByProducto(void* pA ,void* pB);
int llamadas_compareByObservaciones(void* pA ,void* pB);
