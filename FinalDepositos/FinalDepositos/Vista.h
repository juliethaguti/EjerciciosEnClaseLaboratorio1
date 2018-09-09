#ifndef VISTA_H_INCLUDED
#define VISTA_H_INCLUDED

#endif // VISTA_H_INCLUDED

#define VISTA_IDIOMA_ES 0
#define VISTA_IDIOMA_EN 1

#define MENU_PPAL_ES "\n\n1. Carga dep�sitos\n2. Listar productos de dep�sito\n3.Mover productos a dep�sito\n4. Descontar productos de dep�sito\n5. Agregar productos a dep�sito\n6.Salir\n"
#define MENU_PPAL_ERROR_ES "\nOPCION INVALIDA\n"

int vista_init (int idioma);
int vista_mostrarMenu();
void vista_mostrarDeposito(ArrayList* listaDeposito);
