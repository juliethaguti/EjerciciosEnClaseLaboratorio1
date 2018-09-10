#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Service.h"
#include "LogEntry.h"
#include "Informes.h"

int info_servicioMasFallos(ArrayList* list, ArrayList * list2)
{
    int i ,j;
    service* service;
    int auxIdService;
    logEntry* log;
    int contador = 0;
    int recordMax = 0;
    int idRecordMax;

    for(i = 0;i < al_len(list);i++)
    {
         service = al_get(list,i);
         auxIdService = service_getId(service);

         for(j = 0; j < al_len(list2); j++)
         {
             log = al_get(list2,j);

             if(logEntry_getServiceId(log) == auxIdService)
             {
                 contador++;
             }
         }
         if(contador > recordMax)
         {
             recordMax = contador;
             idRecordMax = auxIdService;
         }
    }
    return idRecordMax;
}

int info_cantidadDeFallosPorGravedad(ArrayList* pList)
{
    int retorno;

    retorno = al_len(pList);
}
