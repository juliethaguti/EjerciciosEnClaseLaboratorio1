
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "logEntry.h"

logEntry* logEntry_new(char* date,char* time,int serviceId,int gravedad,char* msg)
{
        logEntry* this = malloc(sizeof(logEntry));

        if(this != NULL)
        {

                logEntry_setDate(this,date);
                logEntry_setTime(this,time);
                logEntry_setServiceId(this,serviceId);
                logEntry_setGravedad(this,gravedad);
                logEntry_setMsg(this,msg);
        }
        return this;
}

void logEntry_delete(logEntry* this)
{
        free(this);
}

int logEntry_setDate(logEntry* this,char* date)
{
        strcpy(this->date,date);
        return 0;
}

int logEntry_setTime(logEntry* this,char* time)
{
        strcpy(this->time,time);
        return 0;
}

int logEntry_setServiceId(logEntry* this,int serviceId)
{
        this->serviceId = serviceId;
        return 0;
}

int logEntry_setGravedad(logEntry* this,int gravedad)
{
        this->gravedad = gravedad;
        return 0;
}

int logEntry_setMsg(logEntry* this,char* msg)
{
        strcpy(this->msg,msg);
        return 0;
}

char* logEntry_getDate(logEntry* this)
{
        return this->date;
}

char* logEntry_getTime(logEntry* this)
{
        return this->time;
}

int logEntry_getServiceId(logEntry* this)
{
        return this->serviceId;
}

int logEntry_getGravedad(logEntry* this)
{
        return this->gravedad;
}

char* logEntry_getMsg(logEntry* this)
{
        return this->msg;
}

logEntry* logEntry_findByDate(ArrayList* pArray,char* date)
{

        int i;
        logEntry* aux;
        logEntry* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(strcmp(date,logEntry_getDate(aux))==0)
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

logEntry* logEntry_findByTime(ArrayList* pArray,char* time)
{

        int i;
        logEntry* aux;
        logEntry* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(strcmp(time,logEntry_getTime(aux))==0)
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

logEntry* logEntry_findByServiceId(ArrayList* pArray,int serviceId)
{

        int i;
        logEntry* aux;
        logEntry* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(serviceId == logEntry_getServiceId(aux))
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

logEntry* logEntry_findByGravedad(ArrayList* pArray,int gravedad)
{

        int i;
        logEntry* aux;
        logEntry* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(gravedad == logEntry_getGravedad(aux))
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

logEntry* logEntry_findByMsg(ArrayList* pArray,char* msg)
{

        int i;
        logEntry* aux;
        logEntry* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(strcmp(msg,logEntry_getMsg(aux))==0)
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

int logEntry_compareByDate(void* pA ,void* pB)
{

        int retorno;

        retorno = strcmp(logEntry_getDate(pA),logEntry_getDate(pB));

        return retorno;
}

int logEntry_compareByTime(void* pA ,void* pB)
{

        int retorno;

        retorno = strcmp(logEntry_getTime(pA),logEntry_getTime(pB));

        return retorno;
}

int logEntry_compareByServiceId(void* pA ,void* pB)
{

        int retorno = 0;

        if(logEntry_getServiceId(pA) > logEntry_getServiceId(pB))
                retorno = 1;
        else if(logEntry_getServiceId(pA) < logEntry_getServiceId(pB))
                retorno = -1;

        return retorno;
}

int logEntry_compareByGravedad(void* pA ,void* pB)
{

        int retorno = 0;

        if(logEntry_getGravedad(pA) > logEntry_getGravedad(pB))
                retorno = 1;
        else if(logEntry_getGravedad(pA) < logEntry_getGravedad(pB))
                retorno = -1;

        return retorno;
}

int logEntry_compareByMsg(void* pA ,void* pB)
{

        int retorno;

        retorno = strcmp(logEntry_getMsg(pA),logEntry_getMsg(pB));

        return retorno;
}

int logEntry_filterLogEntry(void* item)
{
    //logEntry* auxLogEntry = (logEntry*)item;
    int retorno = 0;
    int gravedad;

    gravedad = logEntry_getGravedad((logEntry*)item);

    if(gravedad == 3 )
    {
        retorno = 1;
    }

    return retorno;
}

int logEntry_filterLogEntryMayor(void* item)
{
    int retorno = 0;
    logEntry* auxLogEntry = (logEntry*)item;

    if(7 < auxLogEntry->gravedad )
    {
        retorno = 1;
    }

    return retorno;
}

int logEntry_filterLogEntry47(void* item)
{
    int retorno = 0;
    logEntry* auxLogEntry = (logEntry*)item;


    if(3 < auxLogEntry->gravedad && auxLogEntry->gravedad <= 7)
    {
        retorno = 1;
    }

    return retorno;
}

int logEntry_filterLogEntryMenorATres(void* item)
{
    int retorno = 0;
    logEntry* auxLogEntry = (logEntry*)item;


    if(3 > auxLogEntry->gravedad)
    {
        retorno = 1;
    }

    return retorno;
}
