#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "DataManager.h"
#include "Vista.h"
#include "LogEntry.h"
#include "Service.h"
#include "Informes.h"

static ArrayList* listaLog;
static ArrayList* listaService;
static ArrayList* warnings;
static ArrayList* errors;
static ArrayList* imprimeConsola;
static ArrayList* pListaMenoresATres;

void cont_init()
{
    listaLog = al_newArrayList();
    listaService = al_newArrayList();
    vista_init(VISTA_IDIOMA_ES);
    vista_mostrarMenu();
}

int cont_altaLog ()
{
    dm_readAllLog(listaLog);

    return 0;
}

int cont_procesarInformacion ()
{
    warnings = al_filter(listaLog,logEntry_filterLogEntry);
    errors = al_filter(listaLog,logEntry_filterLogEntryMayor);
    imprimeConsola = al_filter(listaLog,logEntry_filterLogEntry47);
    //vista_mostrarLog(warnings);
    dm_saveAllWarnings(warnings,listaService);
    dm_saveAllErrors(errors,listaService);
    vista_mostrar(imprimeConsola,listaService);


    return 0;
}

void cont_mostrarEstadisticas()
{
    int retorno;
    int cantidadFallosMenorATres;
    int cantidadFallosIgualATres;
    int cantidadFallosEntreCuatroYSiete;
    int cantidadFallosMayorASiete;

    retorno = info_servicioMasFallos(listaService,listaLog);
    vista_mostrarServicioMasFallos(listaService,retorno);
    pListaMenoresATres = al_filter(listaLog,logEntry_filterLogEntryMenorATres);
    cantidadFallosMenorATres = info_cantidadDeFallosPorGravedad(pListaMenoresATres);
    vista_mostrarCantidadDeFallosPorMenorATres(pListaMenoresATres,cantidadFallosMenorATres);
    cantidadFallosIgualATres = info_cantidadDeFallosPorGravedad(warnings);
    vista_mostrarCantidadDeFallosIgualATres(warnings,cantidadFallosIgualATres);
    cantidadFallosEntreCuatroYSiete = info_cantidadDeFallosPorGravedad(imprimeConsola);
    vista_mostrarCantidadDeFallosEntre4Y7(imprimeConsola,cantidadFallosEntreCuatroYSiete);
    cantidadFallosMayorASiete = info_cantidadDeFallosPorGravedad(errors);
    vista_mostrarCantidadDeFallosPorMayorASiete(errors,cantidadFallosMayorASiete);
}
int cont_modificarLog (int id, char* a,char* b,int c)
{

    return 0;
}

int cont_listarLog ()
{
    vista_mostrarLog(listaLog);
    return 0;
}

int cont_ordenarLog ()
{

    return 0;
}

//Service


int cont_altaService ()
{
    dm_readAllService(listaService);
    return 0;
}

int cont_bajaService (int id)
{


    return 0;
}


int cont_modificarService (int id, char* a,char* b,int c)
{

    return 0;
}

int cont_listarService ()
{
    vista_mostrarService(listaService);

    return 0;
}

int cont_ordenarService ()
{

    return 0;
}

