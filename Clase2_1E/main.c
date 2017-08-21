#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int contador=0;
    int maximo;
    int minimo;
    int suma=0;
    char respuesta;
    float promedio;

    do{

        printf("\nIngresar numero:");
        scanf("%d",&numero);

        if(contador==0)
        {
            maximo=numero;
            minimo=numero;
        }
        else
        {
            if(numero>maximo)
            {
                maximo=numero;
            }
            if(numero<minimo)
            {
                minimo=numero;
            }
        }

        suma = numero + suma;
        contador++;
        fflush(stdin);
        printf("s para seguir agregando numeros");
        respuesta=getchar();

    }while(respuesta=='s');

    promedio=suma/contador;
    printf("\nPromedio:%.2f \nMaximo:%i \nMinimo:%i",promedio,maximo,minimo);

    return 0;
}
