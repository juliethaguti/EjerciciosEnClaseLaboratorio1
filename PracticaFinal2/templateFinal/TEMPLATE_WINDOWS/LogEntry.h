#include "ArrayList.h"

#ifndef LOGENTRY_H_INCLUDED
#define LOGENTRY_H_INCLUDED

typedef struct
{
        char date[11];
        char time[6];
        int serviceId;
        int gravedad;
        char msg[65];
}logEntry;

#endif // LOGENTRY_H_INCLUDED


logEntry* logEntry_new(char* date,char* time,int serviceId,int gravedad,char* msg);
void logEntry_delete(logEntry* this);
int logEntry_setDate(logEntry* this,char* date);
int logEntry_setTime(logEntry* this,char* time);
int logEntry_setServiceId(logEntry* this,int serviceId);
int logEntry_setGravedad(logEntry* this,int gravedad);
int logEntry_setMsg(logEntry* this,char* msg);
char* logEntry_getDate(logEntry* this);
char* logEntry_getTime(logEntry* this);
int logEntry_getServiceId(logEntry* this);
int logEntry_getGravedad(logEntry* this);
char* logEntry_getMsg(logEntry* this);
logEntry* logEntry_findByDate(ArrayList* pArray,char* date);
logEntry* logEntry_findByTime(ArrayList* pArray,char* time);
logEntry* logEntry_findByServiceId(ArrayList* pArray,int serviceId);
logEntry* logEntry_findByGravedad(ArrayList* pArray,int gravedad);
logEntry* logEntry_findByMsg(ArrayList* pArray,char* msg);
int logEntry_compareByDate(void* pA ,void* pB);
int logEntry_compareByTime(void* pA ,void* pB);
int logEntry_compareByServiceId(void* pA ,void* pB);
int logEntry_compareByGravedad(void* pA ,void* pB);
int logEntry_compareByMsg(void* pA ,void* pB);
int logEntry_filterLogEntry(void* item);
int logEntry_filterLogEntryMayor(void* item);
int logEntry_filterLogEntry47(void* item);
int logEntry_filterLogEntryMenorATres(void* item);
