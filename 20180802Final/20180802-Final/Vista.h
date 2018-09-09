#ifndef VISTA_H_INCLUDED
#define VISTA_H_INCLUDED

#endif // VISTA_H_INCLUDED

#define VISTA_IDIOMA_ES 0
#define VISTA_IDIOMA_EN 1

#define MENU_PPAL_ES "\n\n1. Carga de archivo\n2. Imprimir llamadas\n3.Imprimir estadisticas\n4. Cargar archivo de Clientes\n5. Salir\n"
#define MENU_PPAL_ERROR_ES "\nOPCION INVALIDA\n"

int vista_init (int idioma);
int vista_mostrarMenu();
void vista_mostrarLlamadas(ArrayList* pListaLlamada);
void vista_mostraClientebyDni(ArrayList* pListaLlamada,char* dni);
void vista_mostrarProductoMasConsultado(char* producto);
