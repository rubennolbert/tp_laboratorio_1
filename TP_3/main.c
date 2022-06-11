#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "Carga-Validacion.h"

int main()
{
	setbuf(stdout, NULL);
    int option = 0;
    int flagArchvio = 0;
    int flagAlta = 0;
    int flagGuardar = 0;

    LinkedList* listaPasajeros = ll_newLinkedList();
    if(listaPasajeros == NULL)
    	printf("Error en la carga de linkedlist.\n");

    do{
        system("cls");
        MostrarMenu();
        switch(FuncionMenu("Selecione una opcion: ", 1, 10))
        {
            case 1:
                system("cls");
                if(0==controller_loadFromText("data.csv",listaPasajeros, &flagArchvio, &flagAlta))
                {
        			printf("Error en la carga de datos desde el archivo, o inexistencia del mismo. \n");
                }
                system("pause");
                break;
            case 2:
                system("cls");
            	if(0==controller_loadFromBinary("data.bin", listaPasajeros, &flagArchvio, &flagAlta))
				{
					printf("Error en la carga de datos desde el archivo binario, o inexistencia del mismo. \n");
				}
                system("pause");
             	break;
            case 3:
                system("cls");
            	if(0==controller_addPassenger(listaPasajeros, &flagArchvio, &flagAlta))
            	{
                	printf("Error en el alta de pasajero. \n");
            	}
                system("pause");
            	break;
            case 4:
                system("cls");
            	if(0==controller_editPassenger(listaPasajeros, &flagArchvio, &flagAlta))
            	{
                	printf("Error en el modificacion de pasajero. \n");
            	}
                system("pause");
            	break;
            case 5:
                system("cls");
            	if(0==controller_removePassenger(listaPasajeros, &flagArchvio, &flagAlta))
            	{
            		printf("Error en la baja de datos de pasajero. \n");
            	}
                system("pause");
            	break;
            case 6:
                system("cls");
            	if(0==controller_ListPassenger(listaPasajeros, &flagArchvio, &flagAlta))
            	{
            		printf("Error para lista pasajeros. \n");
            	}
                system("pause");
            	break;
            case 7:
                system("cls");
            	if(1==controller_sortPassenger(listaPasajeros, &flagArchvio, &flagAlta))
            	{
            		printf("Se realizo con exito el ordenamiento. \n");
            	}
            	else
            	{
            		printf("Error en el ordenamiento de pasajeros. \n");
            	}
                system("pause");
            	break;
            case 8:
            	if(1==controller_saveAsText("data.csv", listaPasajeros, &flagArchvio, &flagAlta, &flagGuardar))
            	{
            		printf("Se realizo con exito el guardado de datos en el archivo de texto. \n");
            	}
            	else
            	{
                	printf("Error en el guardado de datos. \n");
            	}
                system("pause");
            	break;
            case 9:
            	if(1==controller_saveAsBinary("data.bin", listaPasajeros, &flagArchvio, &flagAlta, &flagGuardar))
				{
					printf("Se realizo con exito el guardado de datos en el archivo binario. \n");
				}
				else
				{
					printf("Error en el guardado de datos. \n");
				}
                system("pause");
            	break;
            case 10:
            	if((flagGuardar == 0 && flagAlta == 0 && flagArchvio == 0) || flagGuardar == 1)
            	{
             		printf("usted salio del programa. \n");
					option = 10;
            	}
            	else
            	{
             		printf("Antes de salir deber guardar en archivo los datos cargados. \n");
             	}
                system("pause");
            	break;
        }
    }while(option != 10);
    ll_deleteLinkedList(listaPasajeros);
    return 0;
}



