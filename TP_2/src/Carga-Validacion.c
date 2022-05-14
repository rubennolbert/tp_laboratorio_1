/*
 * Carga-Validacion.c
 *
 *  Created on: 14 may. 2022
 *      Author: ruben
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayPassenger.h"
#include "Carga-Validacion.h"

#define TRUE 1
#define FALSE 0
#define TAM_TIPOPAS 2
#define TAM_ESTADOVUE 3
#define TAM 2000


int ValidarNumero(int num, int limiteMin, int limiteMax)
{
    int respuesta = 1;

    if(num < limiteMin || num > limiteMax /*|| ValidarCaracter(num)*/)
    {
        printf("Error, ingrese un numero dentro de los parametros %d - %d\n", limiteMin, limiteMax);
        respuesta   = 0;
    }
     return respuesta;
}

int ValidarNumMayorCero(int num)
{
    int rta = 1;
    if(num<=0)
    {
        printf("\tERROR, ingrese un numero positivo. \n");
        rta = 0;
    }

    return rta;
}

int esSoloLetras(char cadena[])
{
   int i=0;
   while(cadena[i] != '\0')
   {
       if((cadena[i] != ' ') && (cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}


void MostrarMenu(void)
{
    printf("-------------------------------------------------------\n");
    printf("1. Altas: \n");
    printf("2. Modificar: \n");
    printf("3. Baja: \n");
    printf("4. Informar: \n");
    printf("5. Carga Forzada: \n");
    printf("6. Salir: \n");
    printf("-------------------------------------------------------\n\n");
}

int FuncionMenu(char mensaje[], int min, int max)
{
    int opcion;

    printf(mensaje);
    fflush(stdin);
    scanf("%d", &opcion);
    while(0 == ValidarNumero(opcion, min, max))
    {
        fflush(stdin);
        scanf("%d", &opcion);
    }
    printf("\n");

    return opcion;
}

void HardcodeoPasajeros(ePassenger* list)
{
    ePassenger auxList[10]= {
                                {10001,"Ruben","Lopez", 1522.52, "6000a", 1, 1, FALSE}
                                ,{10002,"walter","Rivero", 1896, "6000b", 2, 2, FALSE}
                                ,{10003,"Mario","Alfonso", 1466.50, "6000c", 1, 3, FALSE}
                                ,{10004,"Valerio","Gonzalez", 1755.25, "6000d", 1, 2, FALSE}
                                ,{10005,"Matias","Pertutti", 1005.63, "6000e", 1, 1, FALSE}
                                ,{10006,"Jorge","Hernadez", 1999.99, "6000f", 2, 1, FALSE}
                                ,{10007,"Lucas","Fernadez", 1544, "6000g", 1, 1, FALSE}
                                ,{10008,"Xavier","Perez", 1875, "6000h", 1, 3, FALSE}
                                ,{10009,"Ariel","Garcia", 1633.99, "6000i", 1, 2, FALSE}
                                ,{10010,"Hector","Zapata", 1465.25, "6000j", 1, 1, FALSE}

                 };

    for(int i=0; i<10; i++)
    {
        list[i] = auxList[i];
    }

}

void getString(char mensaje[],char cadena[])
{

    printf("%s",mensaje);
    fflush(stdin);
    scanf ("%s", cadena);
}
float getFloat(char mensaje[])
{
    float auxFloat;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%f",&auxFloat);
    while(0==ValidarNumMayorCero(auxFloat))
    {
        printf("%s",mensaje);
        fflush(stdin);
        scanf("%f",&auxFloat);
    }
    return auxFloat;
}
int getInt(char mensaje[])
{
    int auxInt;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%d",&auxInt);

    return auxInt;
}


