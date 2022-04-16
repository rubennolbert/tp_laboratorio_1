/*
 * validar-mostrar.c
 *
 *  Created on: 16 abr. 2022
 *      Author: ruben
 */

#include <stdio.h>
#include <stdlib.h>
#include "validar-mostrar.h"


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



void MostrarMenu(char mensaje[])
{
    printf("-------------------------------------------------------\n");
    printf(mensaje);
    printf("-------------------------------------------------------\n");
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

