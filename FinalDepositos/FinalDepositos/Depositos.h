#include "ArrayList.h"

#ifndef _DEPOSITOS_H
#define _DEPOSITOS_H
typedef struct
{
        int idProducto;
        char descripcion[50];
        int cantidad;
}Depositos;
#endif// _DEPOSITOS_H

Depositos* depositos_new(int idProducto,char* descripcion,int cantidad);
void depositos_delete(Depositos* this);
int depositos_setIdProducto(Depositos* this,int idProducto);
int depositos_setDescripcion(Depositos* this,char* descripcion);
int depositos_setCantidad(Depositos* this,int cantidad);
int depositos_getIdProducto(Depositos* this);
char* depositos_getDescripcion(Depositos* this);
int depositos_getCantidad(Depositos* this);
Depositos* depositos_findByIdProducto(ArrayList* pArray,int idProducto);
Depositos* depositos_findByDescripcion(ArrayList* pArray,char* descripcion);
Depositos* depositos_findByCantidad(ArrayList* pArray,int cantidad);
int depositos_compareByIdProducto(void* pA ,void* pB);
int depositos_compareByDescripcion(void* pA ,void* pB);
int depositos_compareByCantidad(void* pA ,void* pB);
