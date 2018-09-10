#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "service.h"

service* service_new(int id,char* name,char* email)
{
        service* this = malloc(sizeof(service));

        if(this != NULL)
        {

                service_setId(this,id);
                service_setName(this,name);
                service_setEmail(this,email);
        }
        return this;
}

void service_delete(service* this)
{
        free(this);
}

int service_setId(service* this,int id)
{
        this->id = id;
        return 0;
}

int service_setName(service* this,char* name)
{
        strcpy(this->name,name);
        return 0;
}

int service_setEmail(service* this,char* email)
{
        strcpy(this->email,email);
        return 0;
}

int service_getId(service* this)
{
        return this->id;
}

char* service_getName(service* this)
{
        return this->name;
}

char* service_getEmail(service* this)
{
        return this->email;
}

service* service_findById(ArrayList* pArray,int id)
{

        int i;
        service* aux;
        service* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(id == service_getId(aux))
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

service* service_findByName(ArrayList* pArray,char* name)
{

        int i;
        service* aux;
        service* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(strcmp(name,service_getName(aux))==0)
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

service* service_findByEmail(ArrayList* pArray,char* email)
{

        int i;
        service* aux;
        service* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(strcmp(email,service_getEmail(aux))==0)
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

int service_compareById(void* pA ,void* pB)
{

        int retorno = 0;

        if(service_getId(pA) > service_getId(pB))
                retorno = 1;
        else if(service_getId(pA) < service_getId(pB))
                retorno = -1;

        return retorno;
}

int service_compareByName(void* pA ,void* pB)
{

        int retorno;

        retorno = strcmp(service_getName(pA),service_getName(pB));

        return retorno;
}

int service_compareByEmail(void* pA ,void* pB)
{

        int retorno;

        retorno = strcmp(service_getEmail(pA),service_getEmail(pB));

        return retorno;
}
