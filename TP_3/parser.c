#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int rta = 0;
	Passenger* auxPassenger = NULL;
	char id[21];
	char name[51];
	char lastName[51];
	char price[21];
	char flycode[21];
	char typePassenger[21];
	char statusFlight[21];
	int cantDatos;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		while(feof(pFile) == 0) // !feof()
		{
			cantDatos = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, name, lastName, price, flycode, typePassenger, statusFlight);
			if(cantDatos==7)
			{
				auxPassenger = Passenger_newParametros(id, name, lastName, price, flycode, typePassenger, statusFlight);
				if(auxPassenger != NULL)
				{
					ll_add(pArrayListPassenger, auxPassenger);
					rta = 1;
				}
				else
				{
					Passenger_delete(auxPassenger);
					auxPassenger = NULL;
				}
			}
			else
			{
				printf("Error en lectura de datos del archivo.\n");
			}
		}
	}
    return rta;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int rta = 0;
	int cantDatos;

	Passenger* auxPassenger;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		while(0==feof(pFile)) // !feof()
		{
			auxPassenger = Passenger_new();
			if(auxPassenger != NULL)
			{
				cantDatos = fread(auxPassenger, sizeof(Passenger), 1, pFile);
				if(cantDatos == 1)
				{
						ll_add(pArrayListPassenger, auxPassenger);
 						rta = 1;
				}
			}
		}
	}

    return rta;
}
