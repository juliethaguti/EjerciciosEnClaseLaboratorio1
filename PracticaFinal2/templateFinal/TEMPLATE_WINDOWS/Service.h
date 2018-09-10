#include "ArrayList.h"
#ifndef SERVICE_H_INCLUDED
#define SERVICE_H_INCLUDED

typedef struct
{
        int id;
        char name[33];
        char email[65];
}service;

#endif // SERVICE_H_INCLUDED

service* service_new(int id,char* name,char* email);
void service_delete(service* this);
int service_setId(service* this,int id);
int service_setName(service* this,char* name);
int service_setEmail(service* this,char* email);
int service_getId(service* this);
char* service_getName(service* this);
char* service_getEmail(service* this);
service* service_findById(ArrayList* pArray,int id);
service* service_findByName(ArrayList* pArray,char* name);
service* service_findByEmail(ArrayList* pArray,char* email);
int service_compareById(void* pA ,void* pB);
int service_compareByName(void* pA ,void* pB);
int service_compareByEmail(void* pA ,void* pB);
