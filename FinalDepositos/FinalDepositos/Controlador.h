#include "Depositos.h"

void cont_init();
int cont_altaDepositos();
void cont_listarProductos(int deposito);
int cont_moverProductosDeDesposito(int depositoOrigen,int depositoDestino,int codigoProducto);
int cont_buscarProductoEnDeposito(ArrayList* listaDeposito,int codigoProducto);
int cont_descontarProducto(int codigoProducto, int cantidad);

