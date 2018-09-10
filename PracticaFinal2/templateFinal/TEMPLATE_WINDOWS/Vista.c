#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#include "ArrayList.h"
#include "Vista.h"
#include "Controlador.h"
#include "LogEntry.h"
#include "Service.h"

static void opcionAltaLog();
static void opcionProcesarInformacion();
static void opcionBajaLog();
static void opcionModificacionLog();
static void opcionLeerLog();
static void opcionOrdenarLog();
static int idiomaVista;
static void opcionAltaService();
static void opcionLeerService();
static void opcionMostrarEstadisticas();

int vista_init (int idioma)
{
    idiomaVista = idioma;
    return 0;
}

int vista_mostrarMenu()
{
    char buffer[10];
    int option=0;

    while(option != 4)
    {
        //system("cls");
        val_getInt(buffer, MENU_PPAL_ES, MENU_PPAL_ERROR_ES,2,5);
        option = atoi(buffer);

        switch(option)
        {
            case 1:
                opcionAltaLog();
                opcionLeerLog();
                opcionAltaService();
                opcionLeerService();
                break;
            case 2:
               opcionProcesarInformacion();
                break;
            case 3:
                opcionMostrarEstadisticas();
                break;
            case 4:
                break;
        }
    }

    return 0;
}

void vista_mostrarLog(ArrayList* pListaLog)
{
    int i;
    logEntry* log;

    for(i = 0; i < al_len(pListaLog); i++)
    {
        log = al_get(pListaLog,i);

        if(log != NULL)
        {
            printf("\n\nFECHA: %s - HORA: %s - IDSERVICIO: %d - GRAVEDAD ERROR: %d - MENSAJE DE ERROR: %s",logEntry_getDate(log),logEntry_getTime(log),logEntry_getServiceId(log),logEntry_getGravedad(log),logEntry_getMsg(log));
        }
    }

}


void mostrarError(char * mensaje)
{

    printf("\nIMPRIMO ERROR\n");

}

static void opcionAltaLog()
{
        cont_altaLog();
}

static void opcionProcesarInformacion()
{
    cont_procesarInformacion();
}

static void opcionModificacionLog()
{
    char auxId[10];
    int id;
    char a[50];
    char b[50];
    char c[50];

    if((val_getUnsignedInt(auxId,"Id a dar de baja" , "Error",2,10)==0))
    {
        id = atoi(auxId);
        if(val_getString(a, "A? ", "Error",2,50) == 0 &&
           val_getString(b, "B? ", "Error",2,50) == 0 &&
           val_getInt(c, "C? ", "Error",2,50) == 0)
        {
            cont_modificarLog(id,a,b,atoi(c));
        }
    }


}

static void opcionLeerLog()
{
    cont_listarLog();
}

static void opcionOrdenarLog()
{
    cont_ordenarLog();
}

void vista_mostrar(ArrayList* pListaFiltrada, ArrayList* listaService)
{
    service* auxService;
    int i,idService;
    logEntry* AuxLog;

    for(i = 0; i < al_len(pListaFiltrada); i++)
    {
        AuxLog = al_get(pListaFiltrada,i);

            idService = logEntry_getServiceId(AuxLog);
            auxService = service_findById(listaService,idService);

             printf("\n\nFECHA: %s - HORA: %s - NOMBRE SERVICIO: %s - GRAVEDAD ERROR: %d - MENSAJE DE ERROR: %s",logEntry_getDate(AuxLog),
                    logEntry_getTime(AuxLog),service_getName(auxService),logEntry_getGravedad(AuxLog),logEntry_getMsg(AuxLog));
    }

}
static void opcionMostrarEstadisticas()
{
    cont_mostrarEstadisticas();
}


//service

void vista_mostrarService(ArrayList* pListaService)
{
    int i;
    service* service;

    for(i = 0; i < al_len(pListaService); i++)
    {
        service = al_get(pListaService,i);

        if(service != NULL)
        {
            printf("\n\nID: %d - NOMBRE: %s - EMAIL: %s ",service_getId(service),service_getName(service),service_getEmail(service));
        }
    }

}

static void opcionAltaService()
{
    cont_altaService();
}

static void opcionLeerService()
{
    cont_listarService();
}

void vista_mostrarServicioMasFallos(ArrayList* pListService,int idService)
{
    service* serv;
    serv = service_findById(pListService,idService);
    printf("\n\nEl servicio con mas fallos:");
    printf("\n\nID: %d - NOMBRE: %s - EMAIL: %s",idService,service_getName(serv),service_getEmail(serv));
}

void vista_mostrarCantidadDeFallosPorMenorATres(ArrayList* pList, int cantidadFallos)
{
    printf("\n\nCantidad de fallos para gravedad menor a tres: %d",cantidadFallos);
}

void vista_mostrarCantidadDeFallosIgualATres(ArrayList* pList, int cantidadFallos)
{
    printf("\n\nCantidad de fallos para gravedad igual a tres: %d",cantidadFallos);
}

void vista_mostrarCantidadDeFallosEntre4Y7(ArrayList* pList, int cantidadFallos)
{
    printf("\n\nCantidad de fallos para gravedad entre 4 y 7: %d",cantidadFallos);
}

void vista_mostrarCantidadDeFallosPorMayorASiete(ArrayList* pList, int cantidadFallos)
{
    printf("\n\nCantidad de fallos para gravedad mayor a siete: %d",cantidadFallos);
}
