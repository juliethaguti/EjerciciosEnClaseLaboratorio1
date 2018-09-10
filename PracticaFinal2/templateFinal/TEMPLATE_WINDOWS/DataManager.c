#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "DataManager.h"
#include "Validaciones.h"
#include "LogEntry.h"
#include "Service.h"

int dm_saveAllWarnings(ArrayList* pArrayWarnings,ArrayList* pArrayService)
{
    int i;
    int retorno=-1;
    int idService;

    FILE* pFile=fopen("warnings.txt","w");
    void* pLogEntry = NULL;
    service* auxService;
    if(pFile!=NULL)
    {
        for(i=0;i<al_len(pArrayWarnings);i++)
        {
            pLogEntry = al_get(pArrayWarnings,i);
            idService = logEntry_getServiceId(pLogEntry);
            auxService = service_findById(pArrayService,idService);
            fprintf(pFile, "%s;%s;%s;%s;%s\n", logEntry_getDate(pLogEntry),logEntry_getTime(pLogEntry), service_getName(auxService), logEntry_getMsg(pLogEntry),service_getEmail(auxService));

            retorno=0;
        }

    }
    fclose(pFile);
    return retorno;
}

int dm_saveAllErrors(ArrayList* pArrayWarnings,ArrayList* pArrayService)
{
    int i;
    int retorno=-1;
    int idService;

    FILE* pFile=fopen("errors.txt","w");
    void* pLogEntry = NULL;
    service* auxService;
    if(pFile!=NULL)
    {
        for(i=0;i<al_len(pArrayWarnings);i++)
        {
            pLogEntry = al_get(pArrayWarnings,i);
            idService = logEntry_getServiceId(pLogEntry);
            auxService = service_findById(pArrayService,idService);
            fprintf(pFile, "%s;%s;%s;%s;%s\n", logEntry_getDate(pLogEntry),logEntry_getTime(pLogEntry), service_getName(auxService), logEntry_getMsg(pLogEntry),service_getEmail(auxService));

            retorno=0;
        }

    }
    fclose(pFile);
    return retorno;
}

int dm_readAllLog(ArrayList* pArrayLog)
{
    FILE *pFile;
    logEntry* log;
	int retorno=-1;
    char var1[50],var2[50],var3[50],var4[50],var5[50];
    pFile = fopen("log.txt","r");

	if(pFile!=NULL)
    {

        do{
            if(fscanf(pFile,"%[^;];%[^;];%[^;];%[^;];%[^\n]\n",var1,var2,var3,var4,var5) >0)
			{
				if(val_validarDate(var1)!=-1 && val_validarTime(var2)!=-1 && val_validarInt(var3)!=-1 && val_validarInt(var4)!=-1 && val_validarDescripcion(var5)!=-1)
				{
					log = logEntry_new(var1, var2, atoi(var3),atoi(var4), var5);
					al_add(pArrayLog,log);
					retorno=0;
				}
			}
		}while(!feof(pFile));
        fclose(pFile);
	}

    return retorno;
}


//service

int dm_readAllService(ArrayList* pArrayService)
{
    FILE *pFile;
	service* service;
	int retorno=-1;

    char var1[50],var2[50],var3[50];

    pFile = fopen("Service.txt","r");

	if(pFile!=NULL)
    {
        do{
            if(fscanf(pFile,"%[^;];%[^;];%[^\n]\n",var1,var2,var3) >0)
			{
				if(val_validarInt(var1)!=-1 && val_validarDescripcion(var2)!=-1 && val_validarEmail(var3)!=-1)
				{
					service = service_new(atoi(var1), var2, var3);
					al_add(pArrayService,service);
					retorno = var1;
				}
			}
		}while(!feof(pFile));
        fclose(pFile);
	}

    return retorno;
}
