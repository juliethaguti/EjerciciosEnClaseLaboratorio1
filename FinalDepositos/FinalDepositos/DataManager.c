#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "DataManager.h"
#include "Validaciones.h"
#include "string.h"
#include "Depositos.h"

int dm_readAllDepositoUno(ArrayList* listaDepositoUno)
{

    int retorno=-1;
    FILE *pFile;
	Depositos* auxDeposito;

    char var1[50],var2[50],var3[50];

    pFile = fopen("dep0.csv","r");

	if(pFile!=NULL)
    {
		//fscanf(pFile,"%[^,],%[^,],%[^\n]\n",var1,var2,var3);
        do{
            if(fscanf(pFile,"%[^,],%[^,],%[^\n]\n",var1,var2,var3) >0)
			{
				if( val_validarInt(var1)!=-1 && val_validarString(var2)!=-1 && val_validarInt(var3)!=-1)
				{
                    auxDeposito = depositos_new(atoi(var1), var2, atoi(var3));
                    al_add(listaDepositoUno, auxDeposito);
                    retorno = 1;
				}
			}
		}while(!feof(pFile));
        fclose(pFile);
	}
    return retorno;
}

int dm_readAllDepositoDos(ArrayList* listaDepositoDos)
{

    int retorno=-1;
    FILE *pFile;
	Depositos* auxDepositos;

    char var1[50],var2[50],var3[50];

    pFile = fopen("dep1.csv","r");
printf("Llego");
	if(pFile!=NULL)
    {
		//fscanf(pFile,"%[^,],%[^,],%[^\n]\n",var1,var2,var3);
        do{
            if(fscanf(pFile,"%[^,],%[^,],%[^\n]\n",var1,var2,var3) >0)
			{
				if( val_validarInt(var1)!=-1 && val_validarString(var2)!=-1 && val_validarInt(var3)!=-1)
				{
                    auxDepositos = depositos_new(atoi(var1), var2, atoi(var3));
                    al_add(listaDepositoDos, auxDepositos);
                    retorno = 1;
				}
			}
		}while(!feof(pFile));
        fclose(pFile);
	}
    return retorno;
}
