/*
 * ArrayPassenger.c
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


int initPassengers(ePassenger* list, int len)
{
    int rta = -1;
    if(list != NULL)
    {
        for(int i=0; i<len; i++)
        {
            list[i].isEmpty = TRUE;
        }
        rta = 0;
    }


    return rta;
}

int findFreeSpace(ePassenger* list, int len)
{
    int index = -1;

    if(list !=NULL)
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty == TRUE)
            {
                index = i;
                break;
            }
        }
    }


    return index;
}

int addPassenger(ePassenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, int statusFlight, char flycode[], eTypePassenger* listType, eStatusFlight* listStatus)
{
    int rta = -1;
    int index;


    index = findFreeSpace(list, len);

    if(index != -1 && list != NULL )
    {
        list[index].id = id;
        strcpy(list[index].name, name);
        strcpy(list[index].lastName, lastName);
        list[index].price = price;
        list[index].typePassenger = typePassenger;
        list[index].statusFlight = statusFlight;
        strcpy(list[index].flyCode, flycode);
        list[index].isEmpty = FALSE;
        printf("\tDatos cargados:\n");
        //printf("\n____%s: \n", list[index].flyCode);

        printUnPasajero(list[index], listType, listStatus);
        system("pause");
        rta = 0;
    }

return rta;
}

int findPassengerById(ePassenger* list, int len,int id)
{
    int index = -1;

    if(list !=NULL)
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty == FALSE && list[i].id == id)
            {
                index = i;
                break;
            }
        }
    }

    return index;
}



int ModificarPasajero(ePassenger* list, int len)
{
    int rta = -1;
    int index;
    int opcionId;
    int opcionModificar;
    if(list != NULL)
    {
        printf("\tIngrese id del pasajero para modificar: ");
        scanf("%d", &opcionId);
        index = findPassengerById(list, len, opcionId);
        if(index != -1)
        {
                printf("\t\tMenu-modificar: \n");
                printf("\t\t1. Nombre: \n");
                printf("\t\t2. Apellido: \n");
                printf("\t\t3. Precio: \n");
                printf("\t\t4. Tipo de pasajero: \n");
                printf("\t\t5. Estado de vuelo: \n");
                printf("\t\t6. Codigo de vuelo: \n");
                printf("\t\t7. Salir de sub-menu: \n");
            do
            {
            	opcionModificar = FuncionMenu("\t\tIngrese opcion a modificar: ", 1, 7);
                switch(opcionModificar)
                {
                case 1:
                    printf("\t\t\tIngrese nombre: ");
                    fflush(stdin);
                    scanf("%[^\n]", list[index].name);
                    break;
                case 2:
                    printf("\t\t\tIngrese apellido: ");
                    fflush(stdin);
                    scanf("%[^\n]", list[index].lastName);
                    break;
                case 3:
                    printf("\t\t\tIngrese precio: ");
                    scanf("%f", &list[index].price);
                    break;
                case 4:
                    printf("\t\t\tIngrese tipo de pasajero: ");
                    printf("\n\t\t\t\t1. Turista.\n\t\t\t\t2. Ejecutivo.\n\t\t\t\tSeleccione opcion: ");
                    scanf("%d", &list[index].typePassenger);
                    break;
                case 5:
                    printf("\t\t\tIngrese estado de vuelo: ");
                    printf("\n\t\t\t\t1. Activo. \n\t\t\t\t2. Demorado. \n\t\t\t\t3. Cancelado. \n\t\t\t\tSeleccione opcion: ");
                    scanf("%d", &list[index].statusFlight);
                    break;
                case 6:
                    printf("\t\t\tIngrese codigo de vuelo: ");
                    fflush(stdin);
                    scanf("%s", list[index].flyCode);
                    break;
                case 7:
                    printf("\t\t\tsalio del menu modificar. \n");
                    break;
                default:
                    printf("\t\t\topcion incorrecta: \n");
                    break;
                }
                rta = 0;

            }while(opcionModificar != 7);
        }
        else
        {
            printf("\tERROR en la busqueda del id. \n");
        }



    }

    return rta;
}

int removePassenger(ePassenger* list, int len, int id)
{
    int index = -1;
    char opcion;

    if(list != NULL)
    {
        index = findPassengerById(list, len, id);
        printf("\tConfirme baja de datos s/n:  ");
        fflush(stdin);
        scanf("%c", &opcion);
        opcion = tolower(opcion);

        while(opcion != 's' && opcion != 'n')
        {
        	printf("\tError, Confirme baja de datos s/n:  ");
			fflush(stdin);
			scanf("%c", &opcion);
			opcion = tolower(opcion);
        }

        if(index != -1 && opcion == 's')
        {

                for(int i=0; i<len; i++)
                {
                    if(id == list[i].id)
                    {
                        list[i].isEmpty = -1;
                        printf("\tDatos borrados. \n");
                        system("pause");
                    }
                }

        }
        else
        {
            printf("\t cancelacion de baja de datos.  \n");
            index = -1;
            system("pause");
        }
    }


    return index;
}

int sortPassengers1(ePassenger* list, int len, int order, eTypePassenger* listType, eStatusFlight* listStatus)  //Ordena el array de pasajeros por apellido y tipo de pasajero de manera ascendente o descendente.
{
    int i, j;

    ePassenger auxListpass;

    if(list != NULL && len > 0 && order == 1)
    {
        for(i=0; i<len - 1; i++)
        {
            for(j=i + 1; j<len; j++)
            {
                if((strcmp(list[i].lastName, list[j].lastName)>0 && list[i].typePassenger == list[j].typePassenger) || (list[i].typePassenger > list[j].typePassenger))
                {
                    auxListpass = list[i];
                    list[i] = list[j];
                    list[j] = auxListpass;
                }
            }

        }
    }
    else if(order == 0)
    {
        for(i=0; i<len - 1; i++)
        {
            for(j=i + 1; j<len; j++)
            {
                if((strcmp(list[i].lastName, list[j].lastName)<0 && list[i].typePassenger == list[j].typePassenger) || (list[i].typePassenger < list[j].typePassenger))
                {
                    auxListpass = list[i];
                    list[i] = list[j];
                    list[j] = auxListpass;
                }
            }

        }
    }

    printf("\t\t------------ Lista pasajeros por apellido y tipo de pasajero ---------------\n\n");
    printPassenger(list, len, listType, listStatus);   //1 list pass por apellido y tipo

    return 0;
}

int printPassenger(ePassenger* list, int length, eTypePassenger* listType, eStatusFlight* listStatus)
{
    int indexType;
    int indexStatus;

    printf("\tId          Nombre            Apellido        Precio      Codigo-vuelo       Tipo-pasajero        Estado-vuelo\n");
    printf("-----------------------------------------------------------------------------------------------------------------------------\n");
    for(int i=0; i<length; i++)
    {
        for(int j=0; j<2; j++)
            if(list[i].typePassenger == listType[j].typePassenger)
                indexType = j;

        for(int k=0; k<3; k++)
            if(list[i].statusFlight == listStatus[k].statusFlight)
            {
            	indexStatus = k;
            }


                if(list[i].isEmpty == FALSE)
                {

                    printf("\t%d        %-10s       %-10s      %.2f     %-10s          %-10s           %s\n"

                                                                                 , list[i].id
                                                                                 , list[i].name
                                                                                 , list[i].lastName
                                                                                 , list[i].price
                                                                                 , list[i].flyCode
                                                                                 , listType[indexType].description
                                                                                 , listStatus[indexStatus].description);

                }


    }
    printf("-----------------------------------------------------------------------------------------------------------------------------\n");

return 0;
}


int printUnPasajero(ePassenger list, eTypePassenger* listType, eStatusFlight* listStatus)
{
    int indexTipoPas;
    int indexEstadovue;


    indexEstadovue = list.statusFlight - 1;

    for(int i=0; i< 2; i++)
    {
        if(list.typePassenger == listType[i].typePassenger)
            indexTipoPas= i;
    }
    for(int i=0; i<3; i++)
    {
        if(list.statusFlight == listStatus[i].statusFlight)
            indexEstadovue = i;
    }

    printf("\tId          Nombre            Apellido        Precio      Codigo-vuelo       Tipo-pasajero       Estado-vuelo\n");
    printf("-----------------------------------------------------------------------------------------------------------------------------\n");
    printf("\t%d        %-10s       %-10s      %.2f       %s                %s                  %s\n"

                                                                         , list.id
                                                                         , list.name
                                                                         , list.lastName
                                                                         , list.price
                                                                         , list.flyCode
                                                                         , listType[indexTipoPas].description
                                                                         , listStatus[indexEstadovue].description);
    printf("-----------------------------------------------------------------------------------------------------------------------------\n");


    return 0;
}

int sortPassengersBycode(ePassenger* list, int len, int order, eTypePassenger* listType, eStatusFlight* listStatus)  //Ordena el array de pasajeros por código de vuelo y estado de vuelo de manera ascendente o descendente.
{
    int i, j;
    ePassenger auxListPass;

    if(list != NULL && len > 0)
    {
			if(order == 1)
			{
				for(i=0; i<len - 1; i++)
				{
					for(j=i + 1; j<len; j++)
					{
						if((strcmp(list[i].flyCode, list[j].flyCode)>0 && list[i].statusFlight == list[j].statusFlight) || (list[i].statusFlight > list[j].statusFlight))
						{
							auxListPass = list[i];
							list[i] = list[j];
							list[j] = auxListPass;
						}
					}
				}
			}
			else if(order == 0)
			{
				for(i=0; i<len - 1; i++)
				{
					for(j=i + 1; j<len; j++)
					{
						if((strcmp(list[i].flyCode, list[j].flyCode)<0 && list[i].statusFlight == list[j].statusFlight) || (list[i].statusFlight < list[j].statusFlight)) // @suppress("Suggested parenthesis around expression")
						{
							auxListPass = list[i];
							list[i] = list[j];
							list[j] = auxListPass;
						}
					}
				}
			}


			printf("\t\t------------ Lista pasajeros por codigo de vuelo y estado activo -----------\n\n");
			printPassenger(list, len, listType, listStatus);




    }
    else
    {
    	printf("\tError con el ordenamiento. \n");
    }


    return 0;
}

int TotalPromedioPrecios(ePassenger* list, int tam)
{
    float promedio;
    float total = 0;
    int i;
    int contadorI = 0;
    int cantPasajeros = 0;

    if(list != NULL && tam > 0)
    {
        for(i=0; i<tam; i++)
            if(list[i].isEmpty == FALSE)
            {
                total = total + list[i].price;
                contadorI++;
            }

        promedio = total/contadorI;

        for(i=0; i<tam; i++)
        {
        	if(list[i].price > promedio && list[i].isEmpty == FALSE)
        	{
                cantPasajeros ++;
        	}
        }


        printf("\n\t--  PRECIOS VUELO:  Total: %.2f     Promedio: %.2f    Cantidad de pasajeros mayor al promedio: %d  --\n\n", total, promedio, cantPasajeros);

    }


    return 0;
}
