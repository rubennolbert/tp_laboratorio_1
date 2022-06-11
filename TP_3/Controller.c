#include <stdio.h>
#include <stdlib.h>
#include  <string.h>
#include  <ctype.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "Carga-Validacion.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger, int* flagA, int* flagB)
{
	int rta = 0;
	int cant;

	if(*flagA == 0 )
	{
		if(pArrayListPassenger != NULL && path != NULL)
		{

			FILE* pArchivo;
			pArchivo = fopen(path, "r");
			if(pArchivo != NULL)
			{
				cant = parser_PassengerFromText(pArchivo, pArrayListPassenger);
				if(cant == 1)
					rta = 1;

            	printf("Exito en la carga datos. \n");
			}
			else
			{
				printf("Error con el archivo. \n");
			}
			fclose(pArchivo);
		}
		*flagA = 1;
	}
	else
	{
 		printf("Carga de datos a partir de archivo, ya a sido realizada.\n");

	}
    return rta;

}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger, int* flagA, int* flagB)
{
	int rta = 0;
	int cant;
	if(*flagA == 0 )
	{
		if(pArrayListPassenger != NULL && path != NULL)
		{
			FILE* pArchivo = NULL;
			pArchivo = fopen(path, "rb");

			if(pArchivo != NULL)
			{

				cant = parser_PassengerFromBinary(pArchivo, pArrayListPassenger);
				if(cant == 1)
					rta = 1;

            	printf("Exito en la carga. \n");

			}
			else
			{
				printf("Error con el archivo. \n");
			}
			fclose(pArchivo);
		}
 		*flagA = 1;
	}
	else
	{
 		printf("Carga de datos a partir de archivo, ya a sido realizada.\n");

	}
	return rta;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger, int* flagA, int* flagB)
{
	int rta = 0;
	int id = 1000;
 	char nombre[51];
	char apellido[51];
	float precio;
	char codigoVuelo[51];
	int tipoPasajero;  // 1=FirstClass, 2=ExecutiveClass, 3=EconomyClass
	int estadoVuelo;   // 1=Aterrizado, 2=En Horario, 3=En Vuelo, 4=Demorado
	char tipoPasajeroChar[51];
	char estadoVueloChar[51];

	Passenger* auxPassenger = NULL;

	if(pArrayListPassenger != NULL)
	{
		auxPassenger = Passenger_new();

		id = BuscarMayorId(pArrayListPassenger);  //GIANNI NOS HABIA DICHO AL CONSULTAR A MARINA POR EL ID,
												  //QUE DEBIAMOS LEVANTAR UN ARCHIVO CON EL NUMERO 1001 E INICIAR
												  //SIEMPRE EL ID CON ESE NUMERO INDEPENDIENTE SI SE DIO DE ALTA EL ARCHIVO CON LOS 1000 DATOS,
												  //YO TENIA ESTA FUNCION PARA BUSCAR EL MAYOR ID Y DECIDI EMPLEARLO PARA CARGAR EL ID CON LO ANTES MENCIONADO.
		if(*flagA == 0 && id == 0)
		{
			id = 1001;
		}
		else
		{
			id = id + 1;
		}

		printf("\tPasajero ID: %d\n", id);
		getString("\t\nIngrese nombre: ", nombre);
		getString("\t\nIngrese apellido: ", apellido);
		precio = getFloat("\t\nIngrese precio: ");
		getStringNumber("\t\nIngrese Codigo de vuelo: ", codigoVuelo);
		tipoPasajero = getIntRange("\t\nIngrese Tipo de pasajero: \n\t\t1. FirstClass.\n\t\t2. ExecutivesClass. \n\t\t3. EconomyClass. \n\t\t", 1, 3);
		OpcionTipoPasajero(tipoPasajero, tipoPasajeroChar);
		estadoVuelo = getIntRange("\t\nIngrese estado de vuelo: \n\t\t1. Aterrizado. \n\t\t2. En horario. \n\t\t3. En vuelo. \n\t\t4. Demorado. \n\t\t", 1, 4);
		OpcionEstadoVuelo(estadoVuelo, estadoVueloChar);

		if(1==(Passenger_setId(auxPassenger, id) &&
			   Passenger_setNombre(auxPassenger, nombre) &&
			   Passenger_setApellido(auxPassenger, apellido) &&
			   Passenger_setPrecio(auxPassenger, precio) &&
			   Passenger_setCodigoVuelo(auxPassenger, codigoVuelo) &&
			   Passenger_setTipoPasajero(auxPassenger, tipoPasajeroChar) &&
			   Passenger_setEstadoVuelo(auxPassenger, estadoVueloChar)))
		{
			ll_add(pArrayListPassenger, auxPassenger);
			rta = 1;
			*flagB = 1;
        	printf("Se realizo con exito el alta de pasajero. \n");
		}
		else
		{
			Passenger_delete(auxPassenger);
		}
	}
    return rta;
}


/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger, int* flagA, int* flagB)   //falta validar en el switch
{

	int rta = 0;
	Passenger* auxPassenger = NULL;
	int id;
	char nombre[51];
	char apellido[51];
	float precio;
	char codigoVuelo[51];
	int tipoPasajero;  // 1=FirstClass, 2=ExecutiveClass, 3=EconomyClass
	int estadoVuelo;   // 1=Aterrizado, 2=En Horario, 3=En Vuelo, 4=Demorado
	char tipoPasajeroChar[51];
	char estadoVueloChar[51];
	int index;
	int option = 0;

	if(*flagA == 1 || *flagB == 1)
	{

 		ShowPassengers(pArrayListPassenger); //muestro la lista de pasajeros para seleccionar

			if(pArrayListPassenger != NULL)
			{
				printf("\nIngrese el ID del pasajero a modificar: ");
				scanf("%d", &id);

				index = SearchIdPassenger(pArrayListPassenger, id);

				if(index == -1)
				{
					printf("No existe pasajero con el id solcitadi: \n");
				}
				else
				{
					auxPassenger = ll_get(pArrayListPassenger, index);
					ShowPassenger(auxPassenger);

					MostrarMenuModificacion();
					do
					{
						switch(FuncionMenu("\tIngrese opcion: ", 1, 7))
						{
							case 1:
								getString("\n\t\tIngrese nombre: ", nombre);
								Passenger_setNombre(auxPassenger, nombre);
								break;
							case 2:
								getString("\n\t\tIngrese apellido: ", apellido);
								Passenger_setApellido(auxPassenger, apellido);
								break;
							case 3:
								precio = getFloat("\n\t\tIngrese preco: ");
								Passenger_setPrecio(auxPassenger, precio);
								break;
							case 4:
								getString("\n\t\tIngrese codigo de vuelo: ", codigoVuelo);
								Passenger_setCodigoVuelo(auxPassenger, codigoVuelo);
								break;
							case 5:
								tipoPasajero = getIntRange("\n\t\tIngrese Tipo de pasajero: \n\t\t\t1. FirstClass.\n\t\t\t2. ExecutivesClass. \n\t\t\t3. EconomyClass. ", 1,3);
								OpcionTipoPasajero(tipoPasajero, tipoPasajeroChar);
								break;
							case 6:
								estadoVuelo = getIntRange("\n\t\tIngrese estado de vuelo: \n\t\t\t1. Aterrizado. \n\t\t\t2. En horario. \n\t\t\t3. En vuelo. \n\t\t\t4. Demorado. ", 1, 4);
								OpcionEstadoVuelo(estadoVuelo, estadoVueloChar);
								break;
							case 7:
								option = 7;
								ShowPassenger(auxPassenger);
							break;
						}
					}while(option != 7);
            		printf("Se realizo con exito la modificacion de pasajero. \n");

					rta = 1;
				}
			}
	}
	else
	{
		printf("Error, para modificar debe dar de alta datos. \n");
	}
    return rta;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger, int* flagA, int* flagB)
{
	int rta = 0;
	int id;
	int index;
	char confirma;

	if(*flagA == 1 || *flagB == 1)
	{
		Passenger* auxPassenger = NULL;

		ShowPassengers(pArrayListPassenger);

		if(pArrayListPassenger != NULL)
		{
			printf("\tIngrese Id: ");
			scanf("%d", &id);

			index = SearchIdPassenger(pArrayListPassenger, id);
			if(-1 == index)
			{
				printf("\tNo se encontro el pasajero. \n");
			}
			else
			{
				auxPassenger = (Passenger*)ll_get(pArrayListPassenger, index);
				ShowPassenger(auxPassenger);
				/*
				printf("\tDesea confirmar la baja de los datos? S/N: ");
			    fflush(stdin);
				scanf("%c", &confirma);
				if(confirma == 'S' || confir)
				confirma = toupper(confirma);
				*/

				FuncConfirma("\tDesea confirmar la baja de los datos? S/N: ", &confirma, "\t\nError, ingrese nuevamente.\n");
				if(confirma == 'S')
				{
					ll_remove(pArrayListPassenger, index); //retorna 0 si funciono correctamente
					printf("Se realizo la baja con exito. \n");
					rta = 1;
				}
				else
				{
					printf("\t\nNo borra los datos. \n");
				}

			}
		}
	}
	else
	{
		printf("Error, para eliminar datos primero debe dar de alta. \n");
	}

    return rta;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger, int* flagA, int* flagB)
{
	int rta = 0;
	//Passenger* auxPassenger = NULL;

	if(*flagA == 1 || *flagB == 1)
	{
		if(pArrayListPassenger !=NULL)
		{
			printf("\t*** Lista de pasajeros ***\n");
			ShowPassengers(pArrayListPassenger);
			rta = 1;
		}
	}
	else
	{
		printf("Error, para listar datos primero debe dar de alta. \n");
	}


    return rta;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger, int* flagA, int* flagB)
{
	int rta = 0;
 	int order;
 	int opcion;

	if(*flagA == 1 || *flagB == 1)
	{
		if(pArrayListPassenger != NULL)
		{
			printf("\t1. Ordenar por id. \n");
			printf("\t2. Ordenar por nombre. \n");
			printf("\t3. Ordenar por apellido. \n");
			printf("\t4. Ordenar por precio. \n");
			printf("\t5. Ordenar por tipo de pasajero. \n");
			printf("\t6. Ordenar por codigo de vuelo. \n");
			printf("\t7. Ordenar por estado de vuelo. \n");
			printf("\t8. Salir. \n");
			opcion = FuncionMenu("\tIngrese opcion: ", 1, 8);
			if(opcion != 8)
			{
				printf("\t\t0. Orden descendente. \n");
				printf("\t\t1. Orden ascendente. \n");
				order = FuncionMenu("\t\tIngrese orden: ", 0, 1);
 			}

			switch(opcion)
			{
				case 1:
					printf("\tEsto puede tardar unos minutos...\n");
					if(ll_sort(pArrayListPassenger, CompararPasajerId, order) == 0)
					{
						rta = 1;
					}
					else
					{
						printf("Error en el ordenamiento ID. \n");
					}
				break;
				case 2:
					printf("\tEsto puede tardar unos minutos...\n");
					if(0==ll_sort(pArrayListPassenger, CompararPasajeroNombre, order))
					{
						rta = 1;
					}
					else
					{
						printf("Error en el ordenamiento Nombre. \n");
					}
				break;
				case 3:
					printf("\tEsto puede tardar unos minutos...\n");
					if(0==ll_sort(pArrayListPassenger, CompararPasajeroApellido, order))
					{
						rta = 1;
					}
					else
					{
						printf("Error en el ordenamiento Apellido. \n");
					}
				break;
				case 4:
					printf("\tEsto puede tardar unos minutos...\n");
					if(0==ll_sort(pArrayListPassenger, CompararPasajerPrecio, order))
					{
						rta = 1;
					}
					else
					{
						printf("Error en el ordenamiento Precio. \n");
					}
				break;
				case 5:
					printf("\tEsto puede tardar unos minutos...\n");
					if(0==ll_sort(pArrayListPassenger, CompararPasajeroTipoPas, order))
					{
						rta = 1;
					}
					else
					{
						printf("Error en el ordenamiento Tipo pasajero. \n");
					}
				break;
				case 6:
					printf("\tEsto puede tardar unos minutos...\n");
					if(0==ll_sort(pArrayListPassenger, CompararPasajeroCodigoVuelo, order))
					{
						rta = 1;
					}
					else
					{
						printf("Error en el ordenamiento Codigo de vuelo. \n");
					}
				break;
				case 7:
					printf("\tEsto puede tardar unos minutos...\n");
					if(0==ll_sort(pArrayListPassenger, CompararPasajeroEstadoVuelo, order))
					{
						rta = 1;
					}
					else
					{
						printf("Error en el ordenamiento Estado de vuelo. \n");
					}
				break;
				case 8:
					printf("\tsalio del sub-menu.\n");
					break;
			}

		}
		else
		{
			printf("\t\tError en el ordenamiento. \n");
		}
	}
	else
	{
		printf("Error, para ordenar datos primero debe dar de alta. \n");
	}

    return rta;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger, int* flagA, int* flagB, int* flagC)
{
	int rta = 0;
	Passenger* auxPassenger = NULL;
	FILE* pArchivo;
	int id;
	char nombre[51];
	char apellido[51];
	float precio;
	char codigoVuelo[51];
	char tipoPasajero[51];  // 1=FirstClass, 2=ExecutiveClass, 3=EconomyClass
	char estadoVuelo[51];   // 1=Aterrizado, 2=En Horario, 3=En Vuelo, 4=Demorado

	if(*flagA == 1 || *flagB == 1)
	{
		if(path != NULL && pArrayListPassenger != NULL)
		{
			pArchivo = fopen(path, "w");
			if(pArchivo != NULL)
			{
				fprintf(pArchivo, "id, name, lastname, price, flycode, typepassenger, statusfly\n");
				for(int i=0; i<ll_len(pArrayListPassenger); i++)
				{
					auxPassenger = ll_get(pArrayListPassenger, i);

					if(1==(Passenger_getId(auxPassenger, &id) &&
						   Passenger_getNombre(auxPassenger, nombre) &&
						   Passenger_getApellido(auxPassenger, apellido) &&
						   Passenger_getPrecio(auxPassenger, &precio) &&
						   Passenger_getCodigoVuelo(auxPassenger, codigoVuelo) &&
						   Passenger_getTipoPasajero(auxPassenger, tipoPasajero) &&
						   Passenger_getEstadoVuelo(auxPassenger, estadoVuelo)))
					{
						fprintf(pArchivo, "%d, %s, %s, %f, %s, %s, %s\n", id, nombre, apellido, precio, codigoVuelo, tipoPasajero, estadoVuelo);
						rta = 1;
						*flagC = 1;
					}
				}
				printf("Exito en el guardado:\n");
			}
			else
			{
				printf("No se pudo abrir el archivo. \n");
			}
			fclose(pArchivo);
		}
	}
	else
	{
		printf("Error, para guardar datos en archivo de texto primero debe dar de alta. \n");
	}



    return rta;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger, int* flagA, int* flagB, int* flagC)
{
	int rta = 0;
	FILE* pArchivoBin;
	Passenger* auxPassenger = NULL;

	if(*flagA == 1 || *flagB == 1)
	{
		if(path != NULL && pArrayListPassenger != NULL)
		{
			pArchivoBin = fopen(path, "wb");
			if(pArchivoBin != NULL)
			{
				for(int i=0; i<ll_len(pArrayListPassenger); i++)
				{
					auxPassenger = ll_get(pArrayListPassenger, i);
					if(auxPassenger != NULL)
					{
						fwrite(auxPassenger, sizeof(Passenger), 1, pArchivoBin);
						rta = 1;
						*flagC = 1;

					}
				}
			}
			else
			{
				printf("Error en la apertura del archivo. \n");
			}
			fclose(pArchivoBin);
		}
		else
		{
			printf("Error, no se encontro el archivo. \n");
		}
	}
	else
	{
		printf("Error, para guardar datos en archivo binario primero debe dar de alta. \n");
	}

    return rta;
}

