#ifndef VISTA_H_INCLUDED
#define VISTA_H_INCLUDED

#endif // VISTA_H_INCLUDED

#define VISTA_IDIOMA_ES 0
#define VISTA_IDIOMA_EN 1

#define MENU_PPAL_ES "\n\n1. Leer Log \n2. Procesar informacion\n3.Mostrar estadisticas\n4. Salir \n"
#define MENU_PPAL_ERROR_ES "\nOPCION INVALIDA\n"




int vista_init (int idioma);
int vista_mostrarMenu();
void vista_mostrarLog(ArrayList* pListaLog);
void mostrarError(char * mensaje);
void vista_mostrar(ArrayList* pListaFiltrada, ArrayList* listaService);
void vista_mostrarService(ArrayList* pListaService);
void vista_mostrarServicioMasFallos(ArrayList* pListService,int idService);
void vista_mostrarCantidadDeFallosPorMenorATres(ArrayList* pList, int cantidadFallos);
void vista_mostrarCantidadDeFallosIgualATres(ArrayList* pList, int cantidadFallos);
void vista_mostrarCantidadDeFallosEntre4Y7(ArrayList* pList, int cantidadFallos);
void vista_mostrarCantidadDeFallosPorMayorASiete(ArrayList* pList, int cantidadFallos);


