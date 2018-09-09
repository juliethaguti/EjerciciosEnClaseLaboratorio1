#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "DataManager.h"
#include "Llamadas.h"
#include "Validaciones.h"
#include "string.h"

int dm_readAllLlamadaArchivo(ArrayList* pArrayLlamadasArchivo,char* nombreArchivo)
{

    int retorno=-1;
    FILE *pFile;
	Llamadas* auxLlamada;

    char var1[50],var2[50],var3[50], var4[50], var5[50],var6[500];

    pFile = fopen(nombreArchivo,"r");

	if(pFile!=NULL)
    {
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5,var6);
        do{
            if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5,var6) >0)
			{

				if( val_validarInt(var1)!=-1 && val_validarString(var2)!=-1 && val_validarEmail(var3)!=-1 &&
       val_validarUnsignedInt(var4) !=-1 && val_validarDescripcion(var5) != -1 && val_validarDescripcion(var6) != -1)
				{
                    auxLlamada= llamadas_new(atoi(var1), var2, var3,var4,var5,var6);
                    al_add(pArrayLlamadasArchivo, auxLlamada);
                    retorno = 1;
				}
			}
		}while(!feof(pFile));
        fclose(pFile);
	}
    return retorno;
}

int dm_saveClientes(ArrayList*nominaLlamadas)
{
    int i;
    int retorno=-1;
    char* auxDni;
    FILE* pFile=fopen("clientes.csv","w");
    void* pClientes=NULL;
    void* pLlamadas = NULL;

    if(pFile != NULL)
    {
		fprintf(pFile,"nombreCliente,dniCliente,email\n");
        for(i = 0; i < al_len(nominaLlamadas); i++)
        {
            pLlamadas = al_get(nominaLlamadas,i);
            auxDni = llamadas_getDniCliente(pLlamadas);
            fprintf(pFile,"\n%s,%s,%s\n", llamadas_getNombreCliente(pLlamadas),llamadas_getDniCliente(pLlamadas),llamadas_getEmailCliente(pLlamadas));
        }
        retorno=0;
    }
    fclose(pFile);
    return retorno;
}
