#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"

#define MAX_INPUT_BUFFER 4096

/** \brief fgets con modificacion por \0 y LF
 *
 * \param buffer con dato a ingresar
 * \param limite de caracteres que puede tener el dato
 * \param puntero a archivo
 * \return VOID
 *
 */
void myFgets(char* buffer, int limite ,FILE* archivo)
{
    int i=0;
    fgets(buffer, limite ,archivo);
    buffer[limite-1] = '\0';
    while(buffer[i] != '\0')
    {
        if(buffer[i] == 10)//10 -> LF
        {
            buffer[i] = '\0';
            break;
        }
        i++;
    }
}

/** \brief Toma un dato a ingresar de tipo string
 *
 * \param destino a donde se guarda el string
 * \param mensaje a imprimir al usuario
 * \param mensaje de error a imprimir al usuario en caso de que haya un problema
 * \param numero de intentos para que trate de ingresar de nuevo
 * \param limite de caracteres que puede tener el string
 * \return -1 error, 0 OK
 *
 */

int val_getString(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ;intentos>0;intentos--)
        {

            myFgets(buffer, limite ,stdin);

            if(val_validarString(buffer) == -1)
            {
                printf(mensajeError);
                continue;
            }
            else
            {
                strncpy(destino,buffer,limite);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Toma un dato a ingresar como char de tipo int
 *
 * \param destino a donde se guarda el string
 * \param mensaje a imprimir al usuario
 * \param mensaje de error a imprimir al usuario en caso de que haya un problema
 * \param numero de intentos para que trate de ingresar de nuevo
 * \param limite de caracteres que puede tener el string
 * \return -1 error, 0 OK
 *
 */

int val_getInt(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ;intentos>0;intentos--)
        {

            myFgets(buffer, limite ,stdin);

            if(val_validarInt(buffer) == -1)
            {
                printf(mensajeError);
                continue;
            }
            else
            {
                strncpy(destino,buffer,limite);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Revisa que el string ingresado no tenga caracteres invalidos
 *
 * \param buffer conteniendo el string
 * \return -1 error, 0 OK
 *
 */

int val_validarString(char* buffer)
{
    int i=0;
    int retorno = 0;
    while(buffer[i] != '\0')
    {
        if((buffer[i] < 'a' || buffer[i] > 'z') && (buffer[i] < 'A' || buffer[i] > 'Z'))
        {
            retorno = -1;
            break;
        }
        i++;
    }
    return retorno;
}

/** \brief Revisa que el string sean solo numeros
 *
 * \param buffer conteniendo el int como string
 * \return -1 error, 0 OK
 *
 */

int val_validarInt(char* buffer)
{
    int i=0;
    int retorno = 0;

    while(buffer[i] != '\0')
    {
        if(buffer[i] < '0' || buffer[i] > '9')
        {
            retorno = -1;
            break;
        }
        i++;
    }
    return retorno;
}

/** \brief Toma un dato a ingresar como char de tipo UnsignedInt
 *
 * \param destino a donde se guarda el string
 * \param mensaje a imprimir al usuario
 * \param mensaje de error a imprimir al usuario en caso de que haya un problema
 * \param numero de intentos para que trate de ingresar de nuevo
 * \param limite de caracteres que puede tener el string
 * \return -1 error, 0 OK
 *
 */

int val_getUnsignedInt(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ;intentos>0;intentos--)
        {

            myFgets(buffer, limite ,stdin);

            if(val_validarUnsignedInt(buffer) == -1)
            {
                printf(mensajeError);
                continue;
            }
            else
            {
                strncpy(destino,buffer,limite);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Revisa que el string sean solo numeros con o sin signos
 *
 * \param buffer conteniendo el int como string
 * \return -1 error, 0 OK
 *
 */

int val_validarUnsignedInt(char* buffer)
{
    int i=0;
    int retorno = 0;
    int flagPunto = 0;
    while(buffer[i] != '\0')
    {
        if(buffer[i] < '0' || buffer[i] > '9' )
        {
            retorno = -1;
            break;
        }
        else
        {
            if(buffer[i] == '-' && i != 0)
            {
                retorno = -1;
                break;
            }
            else if(buffer[i] == '.')
            {
                flagPunto++;
                if(flagPunto > 1)
                {
                    retorno = -1;
                    break;
                }
            }
        }
        i++;
    }
    return retorno;
}


int val_validarFloat(char* buffer)
{
    int i=0;
    int retorno = 0;
    int flagPunto = 0;

    while(buffer[i] != '\0')
    {
        if((buffer[i] < '0' || buffer[i] > '9') && buffer[i] != '.' && buffer[i] != '-' )
        {
            retorno = -1;
            break;
        }
        else
        {
            if(buffer[i] == '-' && i != 0)
            {
                retorno = -1;
                break;
            }
            else if(buffer[i] == '.')
            {
                flagPunto++;
                if(flagPunto > 1)
                {
                    retorno = -1;
                    break;
                }
            }
        }
                    i++;
    }
                    return retorno;
}

int val_getFloat(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ; intentos > 0; intentos--)
        {
            myFgets(buffer, limite ,stdin);

                if(val_validarFloat(buffer) == -1)
                {
                    if(intentos == 1)
                    {
                        printf("\nERROR!!! INTENTOS AGOTADOS!!!\n");
                        break;
                    }
                    else
                    {
                        printf(mensajeError);
                        continue;
                    }
                }
            else
            {
                strncpy(destino,buffer,limite);
                retorno = 0;
                break;
            }
        }
    }
                return retorno;
}

/** \brief Revisa que el string ingresado no tenga caracteres invalidos
 *
 * \param buffer conteniendo el string
 * \return -1 error, 0 OK
 *
 */
int val_validarEmail(char* buffer)
{
    int i=0;
    int retorno = 0;
    int cantidadArroba=0;

    while(buffer[i] != '\0')
    {
        if(buffer[i] == ' ' || (buffer[i] == '@' && cantidadArroba < 0))
        {
            retorno = -1;
            break;
        }
        if (buffer[i] == '@' && cantidadArroba == 0)
        {
            cantidadArroba++;
            i++;
            continue;
        }
        i++;
    }
    return retorno;
}

/** \brief Toma un dato a ingresar de tipo string
 *
 * \param destino a donde se guarda el string
 * \param mensaje a imprimir al usuario
 * \param mensaje de error a imprimir al usuario en caso de que haya un problema
 * \param numero de intentos para que trate de ingresar de nuevo
 * \param limite de caracteres que puede tener el string
 * \return -1 error, 0 OK
 *
 */
int val_getEmail(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ;intentos>0;intentos--)
        {
            myFgets(buffer, limite ,stdin);

            if(val_validarEmail(buffer) == -1)
            {
                printf(mensajeError);
                continue;
            }
            else
            {
                strncpy(destino,buffer,limite);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Revisa que el string ingresado no tenga caracteres invalidos
 *
 * \param buffer conteniendo el string
 * \return -1 error, 0 OK
 *
 */
int val_validarDate(char str[])
{
   int i=0;
   int cantidadBarras=0;
   while(str[i] != '\0')
   {
       if (str[i] == '/' && cantidadBarras < 3)
       {
           cantidadBarras++;
           i++;
           continue;
       }
       if(str[i] < '0' || str[i] > '9')
           return -1;
       i++;
   }
   return 0;
}

/** \brief Toma un dato a ingresar de tipo string
 *
 * \param destino a donde se guarda el string
 * \param mensaje a imprimir al usuario
 * \param mensaje de error a imprimir al usuario en caso de que haya un problema
 * \param numero de intentos para que trate de ingresar de nuevo
 * \param limite de caracteres que puede tener el string
 * \return -1 error, 0 OK
 *
 */
int val_getDate(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ;intentos>0;intentos--)
        {
            myFgets(buffer, limite ,stdin);

            if(val_validarDate(buffer) == -1)
            {
                printf(mensajeError);
                continue;
            }
            else
            {
                strncpy(destino,buffer,limite);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}


/** \brief Toma un dato a ingresar de tipo string
 *
 * \param destino a donde se guarda el string
 * \param mensaje a imprimir al usuario
 * \param mensaje de error a imprimir al usuario en caso de que haya un problema
 * \param numero de intentos para que trate de ingresar de nuevo
 * \param limite de caracteres que puede tener el string
 * \return -1 error, 0 OK
 *
 */
int val_getTime(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ;intentos>0;intentos--)
        {
            myFgets(buffer, limite ,stdin);

            if(val_validarTime(buffer) == -1)
            {
                printf(mensajeError);
                continue;
            }
            else
            {
                strncpy(destino,buffer,limite);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}


/** \brief Revisa que el string ingresado no tenga caracteres invalidos
 *
 * \param buffer conteniendo el string
 * \return -1 error, 0 OK
 *
 */
int val_validarTime(char str[])
{
   int i=0;
   int cantidadDosPuntos=0;
   while(str[i] != '\0')
   {
       if (str[i] == ':' && cantidadDosPuntos == 0)
       {
           cantidadDosPuntos++;
           i++;
           continue;
       }
       if(str[i] < '0' || str[i] > '9')
           return -1;
       i++;
   }
   return 0;
}

/** \brief val_getDescripcion pide al usuario un dato de tipo string y valida su contenido
 *
 * \param destino donde se guargara el dato pedido
 * \param mensaje el mensaje a imprimirle al usuario para que sepa que ingresar
 * \param mensajeError el mensaje a imprimmirle al usuario en caso de error
 * \param intentos la cantidad de veces que el usuario puede volver a reingresar el dato en caso de equivocarse
 * \param limite la cantidad maxima de caracteres de destino
 * \return -1 si hubo algun error, 0 si no hubo errores
 *
 */

int val_getDescripcion(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ;intentos>0;intentos--)
        {

            myFgets(buffer, limite ,stdin);

            if(val_validarDescripcion(buffer) == -1)
            {
                printf(mensajeError);
                continue;
            }
            else
            {
                strncpy(destino,buffer,limite);
                retorno = 0;
                break;
            }
        }

    }
    return retorno;
}


/** \brief val_validarDescripcion valida que el string contenga solo caracteres alfabeticos y signos de puntuacion
 *
 * \param buffer el string a validar
 * \return -1 si hubo algun error, 0 si no hubo errores
 *
 */

int val_validarDescripcion(char* buffer)
{
    int i=0;
    int retorno = 0;

    if(buffer[0]== '\0')
        retorno=-1;

    while(buffer[i] != '\0')
    {
        if((buffer[i] < '0' || buffer[i] > '9') && buffer[i] != '.' && buffer[i] != '-'  && buffer[i] != '_'
           && buffer[i] != ' '  && (buffer[i] < 'a' || buffer[i] > 'z') && (buffer[i] < 'A' || buffer[i] > 'Z') && buffer[i] != '"'
           && buffer[i] != ','&& buffer[i] != ';')
        {
            retorno = -1;
            break;
        }
        i++;
    }

    return retorno;
}
