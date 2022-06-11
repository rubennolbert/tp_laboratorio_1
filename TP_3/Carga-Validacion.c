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
#include "Carga-Validacion.h"


void MostrarMenu(void)
{

    printf("-------------------------------------------------------\n");
	printf("************* TP 3 *************\n");
    printf("-------------------------------------------------------\n");
    printf("01. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n");
    printf("02. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).	\n");
    printf("03. Alta de pasajero\n");
    printf("04. Modificar datos de pasajero\n");
    printf("05. Baja de pasajero.\n");
    printf("06. Listar pasajeros.\n");
    printf("07. Ordenar pasajeros.\n");
    printf("08. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n");
    printf("09. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n");
    printf("10. Salir: \n");
    printf("-------------------------------------------------------\n\n");

}

void MostrarMenuModificacion(void)
{
	printf("\tMenu modificacion pasajero: \n");
	printf("\t1. Nombre: \n");
	printf("\t2. Apellido: \n");
	printf("\t3. Precio: \n");
	printf("\t4. Codigo de vuelo: \n");
	printf("\t5. Tipo de pasajero: \n");
	printf("\t6 Estado de vuelo: \n");
	printf("\t7. salir de sub-menu: \n");
}


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



void getString(char mensaje[],char cadena[])
{

    printf("%s",mensaje);
    fflush(stdin);
    scanf ("%s", cadena);
    while(0==esSoloLetras(cadena))
    {
    	printf("Ingrese letras. %s",mensaje);
		fflush(stdin);
		scanf ("%s", cadena);
    }
}

void getStringNumber(char mensaje[],char cadena[])
{

    printf("%s",mensaje);
    fflush(stdin);
    scanf ("%s", cadena);

}

int FuncConfirma(char mensaje[], char* letra, char MensajeError[])
{
	int rta = 0;
	char opcion;

	if(letra != NULL && mensaje != NULL && MensajeError != NULL)
	{


		printf("%s", mensaje);
	    fflush(stdin);
	    scanf("%c", &opcion);
	    opcion = toupper(opcion);

	    while(!(opcion == 'S' || opcion == 'N'))
	    {
	    	printf("%s", MensajeError);
	    	fflush(stdin);
			scanf("%c", &opcion);
			opcion = toupper(opcion);
	    }
	    *letra = opcion;
		rta = 1;
	}

	return rta;
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

int getIntRange(char mensaje[], int min, int max)
{
    int auxInt;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%d",&auxInt);
    while(0==ValidarNumero(auxInt, min, max))
    {
 		fflush(stdin);
		scanf("%d",&auxInt);
    }

    return auxInt;
}


void OpcionTipoPasajero(int tipoPasajeInt, char cadena[])
{
	switch(tipoPasajeInt)
	{
		case 1:
			strcpy(cadena, "FirstClass");
			break;
		case 2:
			strcpy(cadena, "ExecutiveClass");
			break;
		case 3:
			strcpy(cadena, "EconomyClass");
			break;
	}

	//1=FirstClass, 2=ExecutiveClass, 3=EconomyClass

}

void OpcionEstadoVuelo(int estadoVueloInt, char cadena[])
{
	switch(estadoVueloInt)
		{
			case 1:
				strcpy(cadena, "Aterrizado");
				break;
			case 2:
				strcpy(cadena, "En Horario");
				break;
			case 3:
				strcpy(cadena, "En Vuelo");
				break;
			case 4:
				strcpy(cadena, "Demorado");
				break;
		}
	// 1=Aterrizado, 2=En Horario, 3=En Vuelo, 4=Demorado
}


