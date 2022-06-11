/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"



/**
 * \brief crea un nueva estructura de tipo puntero pasajero en memoria dinamica.
 * \param no recibe parametros.
 * \return un direccion de memoria de tipo estructura.
 */
Passenger* Passenger_new() //constructor
{
	Passenger* auxPassenger = (Passenger*)malloc(sizeof(Passenger));
	if(auxPassenger !=NULL)
	{
		auxPassenger->id = 0;
		strcpy(auxPassenger->nombre, " ");
		strcpy(auxPassenger->apellido, " ");
		auxPassenger->precio = 0;
		strcpy(auxPassenger->codigoVuelo, " ");
		strcpy(auxPassenger->tipoPasajero, " ");
		strcpy(auxPassenger->statusFlight, " ");
	}

	return auxPassenger;
}


/**
 * \brief crea un nueva estructura de tipo puntero pasajero en memoria dinamica. donde se le guardan los valores pasados por referencia
 * \param idStr
 * \param nombreStr
 * \param apellidoStr
 * \param precioSr
 * \param flycodeStr
 * \param tipoPasajeroStr
 * \param estadoVueloStr
 * \return un direccion de memoria de tipo estructura.
 */
Passenger* Passenger_newParametros(char* idStr,char* nombreStr, char* apellidoStr, char* precioSr, char* flycodeStr, char* tipoPasajeroStr,char* estadoVueloStr) //constructor parametrizado
{
	Passenger* newPassenger = Passenger_new();

	if(newPassenger !=NULL && idStr != NULL && nombreStr !=NULL && apellidoStr != NULL && precioSr!=NULL && flycodeStr!=NULL &&tipoPasajeroStr!=NULL && estadoVueloStr!=NULL)
	{
		if( 0 == (Passenger_setId(newPassenger, atoi(idStr))
				&& Passenger_setNombre(newPassenger, nombreStr)
				&& Passenger_setApellido(newPassenger, apellidoStr)
				&& Passenger_setPrecio(newPassenger, atof(precioSr))
				&& Passenger_setCodigoVuelo(newPassenger, flycodeStr)
				&& Passenger_setTipoPasajero(newPassenger, tipoPasajeroStr)
				&& Passenger_setEstadoVuelo(newPassenger, estadoVueloStr)	)	)
		{

			Passenger_delete(newPassenger);
			newPassenger = NULL;
		}

	}

	return newPassenger;
}


/**
 * \brief libera espacio de la direccion de la estructura tipo pasajero puntero en memoria dinamica
 * \param puntero a estructura
 * \return 1 si salio todo bien, 0 si todo lo contrarior
 */
int  Passenger_delete(Passenger* this)  //destructor
{
	int rta = 0;
	if(this != NULL)
	{
		free(this);
		rta = 1;
	}
	return rta;
}

/**
 * \brief carga en la estructura pasada como puntero el parametro id
 * \param puntero a estructura
 * \param numero entero
 * \return 1 si salio todo bien, 0 si todo lo contrarior
 */
int Passenger_setId(Passenger* this,int id)
{
	int rta = 0;

	if(this!=NULL && id>0)
	{
		this->id = id;
		rta = 1;
	}
	return rta;
}

/**
 * \brief devuelve de la estructura pasada como puntero a la direccion id
 * \param puntero a estructura
 * \param numero entero
 * \return 1 si salio todo bien, 0 si todo lo contrarior
 */
int Passenger_getId(Passenger* this,int* id)
{
	int rta = 0;
	if(this!=NULL && id!=NULL)
	{
		*id = this->id;
		rta = 1;
	}
	return rta;
}

/**
 * \brief carga en la estructura pasada como puntero el parametro nombre
 * \param puntero a estructura
 * \param puntero a cadena
 * \return 1 si salio todo bien, 0 si todo lo contrarior
 */
int Passenger_setNombre(Passenger* this,char* nombre)
{
	int rta = 0;
	if(this!=NULL && nombre!=NULL)
	{
		strcpy(this->nombre, nombre);
		rta = 1;
	}
	return rta;
}

/**
 * \brief devuelve de la estructura pasada como puntero a la direccion nombre
 * \param puntero a estructura
 * \param puntero a cadena
 * \return 1 si salio todo bien, 0 si todo lo contrarior
 */
int Passenger_getNombre(Passenger* this,char* nombre)
{
	int rta = 0;
	if(this!=NULL && nombre!=NULL)
	{
		strcpy(nombre, this->nombre);
		rta = 1;
	}
	return rta;
}

/**
 * \brief carga en la estructura pasada como puntero el parametro apellido
 * \param puntero a estructura
 * \param puntero a cadena
 * \return 1 si salio todo bien, 0 si todo lo contrarior
 */
int Passenger_setApellido(Passenger* this,char* apellido)
{
	int rta = 0;
	if(this!=NULL && apellido!=NULL)
	{
		strcpy(this->apellido, apellido);
		rta = 1;
	}
	return rta;
}


/**
 * \brief devuelve de la estructura pasada como puntero a la direccion apellido
 * \param puntero a estructura
 * \param puntero a cadena
 * \return 1 si salio todo bien, 0 si todo lo contrarior
 */
int Passenger_getApellido(Passenger* this,char* apellido)
{
	int rta = 0;
	if(this!=NULL && apellido!=NULL)
	{
		strcpy(apellido, this->apellido);
		rta = 1;
	}
	return rta;
}

/**
 * \brief carga en la estructura pasada como puntero el parametro puntero a cadena
 * \param puntero a estructura
 * \param puntero a cadena
 * \return 1 si salio todo bien, 0 si todo lo contrarior
 */
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int rta = 0;
	if(this!=NULL && codigoVuelo!=NULL)
	{
		strcpy(this->codigoVuelo, codigoVuelo);
		rta = 1;
	}
	return rta;
}

/**
 * \brief devuelve de la estructura pasada como puntero a la direccion codigo de vuelo
 * \param puntero a estructura
 * \param puntero a cadena
 * \return 1 si salio todo bien, 0 si todo lo contrarior
 */
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int rta = 0;
	if(this!=NULL && codigoVuelo!=NULL)
	{
		strcpy(codigoVuelo, this->codigoVuelo);
		rta = 1;
	}
	return rta;
}

/**
 * \brief carga en la estructura pasada como puntero el parametro puntero a cadena
 * \param puntero a estructura
 * \param puntero a cadena
 * \return 1 si salio todo bien, 0 si todo lo contrarior
 */
int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int rta = 0;
	if(this!=NULL && tipoPasajero!=NULL)
		{
			strcpy(this->tipoPasajero, tipoPasajero);
			rta = 1;
		}
	return rta;
}

/**
 * \brief devuelve de la estructura pasada como puntero a la direccion tipopasajero
 * \param puntero a estructura
 * \param puntero a cadena
 * \return 1 si salio todo bien, 0 si todo lo contrarior
 */
int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int rta = 0;
	if(this!=NULL && tipoPasajero!=NULL)
	{
		strcpy(tipoPasajero, this->tipoPasajero);
		rta = 1;
	}
	return rta;
}

/**
 * \brief carga en la estructura pasada como puntero el parametro puntero a cadena
 * \param puntero a estructura
 * \param puntero a cadena
 * \return 1 si salio todo bien, 0 si todo lo contrarior
 */
int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo)
{
	int rta = 0;
	if(this!=NULL && estadoVuelo!=NULL)
	{
		strcpy(this->statusFlight,estadoVuelo);
		rta = 1;
	}
	return rta;
}

/**
 * \brief devuelve de la estructura pasada como puntero a la direccion esadovuelo
 * \param puntero a estructura
 * \param puntero a cadena
 * \return 1 si salio todo bien, 0 si todo lo contrarior
 */
int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo)
{
	int rta = 0;
	if(this!=NULL && estadoVuelo!=NULL)
	{
		strcpy(estadoVuelo, this->statusFlight);
		rta = 1;
	}
	return rta;
}


/**
 * \brief carga en la estructura pasada como puntero el parametro precio
 * \param puntero a estructura
 * \param numero flotante
 * \return 1 si salio todo bien, 0 si todo lo contrarior
 */
int Passenger_setPrecio(Passenger* this,float precio)
{
	int rta = 0;
	if(this!=NULL && precio>0)
	{
		this->precio = precio;
		rta = 1;
	}
	return rta;
}

/**
 * \brief devuelve de la estructura pasada como puntero a la direccion precio
 * \param puntero a estructura
 * \param puntero a flotante
 * \return 1 si salio todo bien, 0 si todo lo contrarior
 */
int Passenger_getPrecio(Passenger* this,float* precio)
{
	int rta = 0;
	if(this!=NULL && precio!=NULL)
	{
		*precio = this->precio;
		rta = 1;
	}
	return rta;
}






/**
 * \brief recorre la lista de pasajeros y trae el id de mayor tamaño
 * \param lista linkedlist
 * \return 1 si salio todo bien, 0 si todo lo contrarior
 */
int BuscarMayorId(LinkedList* pArrayListPassenger)
{
    Passenger* auxPassenger = NULL;
    int mayor = 0;
    int id;
    int i;

    if(pArrayListPassenger != NULL)
    {
        for(i=0; i<ll_len(pArrayListPassenger); i++)
        {
        	auxPassenger = (Passenger*) ll_get(pArrayListPassenger, i);
            Passenger_getId(auxPassenger, &id);
            if( i==0 || id > mayor)
            {
                mayor = id;
            }
        }
    }
    return mayor;
}


/**
 * \brief muesta los datos de un solo pasajero
 * \param puntero de tipo estructura
 * \return 1 si salio todo bien, 0 si todo lo contrarior
 */
int ShowPassenger(Passenger* this)
{
	int rta = 0;
	int id;
	char nombre[51];
	char apellido[51];
	float precio;
	char codigoVuelo[51];
	char tipoPasajero[51];
	char estadoVuelo[51];

	if(this != NULL)
	{
		if(1==(Passenger_getId(this, &id) &&
			   Passenger_getNombre(this, nombre) &&
			   Passenger_getApellido(this, apellido) &&
			   Passenger_getPrecio(this, &precio) &&
			   Passenger_getCodigoVuelo(this, codigoVuelo) &&
			   Passenger_getTipoPasajero(this, tipoPasajero) &&
			   Passenger_getEstadoVuelo(this, estadoVuelo)))
		{
			printf("%d		%10s		%10s		%.2f		%10s		%10s		%10s\n", id, nombre, apellido, precio, codigoVuelo, tipoPasajero, estadoVuelo);
			rta = 1;
		}
	}
	return rta;
}


/**
 * \brief muesta los datos de todos pasajeros
 * \param puntero de tipo estructura
 * \return 1 si salio todo bien, 0 si todo lo contrarior
 */
int ShowPassengers(LinkedList* pArrayListPassenger)
{
	int rta = 0;
	int i;

	if(pArrayListPassenger != NULL)
	{
		printf("Id		     Nombre		 Apellido	        Precio			Codigo de vuelo		Tipo de pasajero	Estado de vuelo	\n");
		for(i=0; i<ll_len(pArrayListPassenger); i++)
		{
			ShowPassenger((Passenger*)ll_get(pArrayListPassenger, i));
		}
		rta = 1;
	}

	return rta;
}

/**
 * \brief buscan el id de un pasajero que pasamos por parametro
 * \param lista linkedlist
 * \param id como numero entero
 * \return el id encontrado o -1 si hubo un problema en la busqueda
 */
int SearchIdPassenger(LinkedList* pArrayListPassenger, int id)
{
	int index = -1;
	int i;
	int auxId;
	Passenger* auxPassenger = NULL;

	for(i=0; i<ll_len(pArrayListPassenger); i++)
	{
		auxPassenger = (Passenger*)ll_get(pArrayListPassenger, i);
		Passenger_getId(auxPassenger, &auxId);
		if(auxId == id)
		{
			index = i;
			break;
		}
	}
	return index;
}





/**
 * \brief compara el id de dos estructura
 * \param puntero generico
 * \param puntero generico
 * \return 1 si salio todo bien, 0 si todo lo contrarior
 */
int CompararPasajerId(void* a, void* b)
{
	int rta = 0;
	Passenger* auxPassengerA = NULL;
	Passenger* auxPassengerB = NULL;

	if(a != NULL && b != NULL)
	{
		auxPassengerA = (Passenger*)a;
		auxPassengerB = (Passenger*)b;

		if(auxPassengerA->id > auxPassengerB->id)
		{
			rta = 1;
		}
		else
		{
			if(auxPassengerA->id < auxPassengerB->id)
				rta = -1;
		}
	}

	return rta;
}

/**
 * \brief compara el bombre de dos estructura
 * \param puntero generico
 * \param puntero generico
 * \return 1 si es mayor, 0 si son iguales, -1 si es menor
 */
int CompararPasajeroNombre(void* a, void* b)
{
	int rta = 0;
	Passenger* auxPassengerA = NULL;
	Passenger* auxPassengerB = NULL;

	if(a != NULL && b != NULL)
	{
		auxPassengerA = (Passenger*)a;
		auxPassengerB = (Passenger*)b;

		rta = strcmp(auxPassengerA->nombre, auxPassengerB->nombre);
		//1 si es mayor
		//0 si son iguales
		//-1 si es menor
	}
	return rta;
}

/**
 * \brief compara el apellido de dos estructura
 * \param puntero generico
 * \param puntero generico
 * \return 1 si es mayor, 0 si son iguales, -1 si es menor
 */
int CompararPasajeroApellido(void* a, void* b)
{
	int rta = 0;
	Passenger* auxPassengerA = NULL;
	Passenger* auxPassengerB = NULL;

	if(a != NULL && b != NULL)
	{
		auxPassengerA = (Passenger*)a;
		auxPassengerB = (Passenger*)b;

		rta = strcmp(auxPassengerA->apellido, auxPassengerB->apellido);
		//1 si es mayor
		//0 si son iguales
		//-1 si es menor
	}
	return rta;
}


/**
 * \brief compara el precio de dos estructura
 * \param puntero generico
 * \param puntero generico
 * \return 1 si salio todo bien, 0 si todo lo contrarior
 */
int CompararPasajerPrecio(void* a, void* b)
{
	int rta = 0;
	Passenger* auxPassengerA = NULL;
	Passenger* auxPassengerB = NULL;

	if(a != NULL && b != NULL)
	{
		auxPassengerA = (Passenger*)a;
		auxPassengerB = (Passenger*)b;

		if(auxPassengerA->precio > auxPassengerB->precio)
		{
			rta = 1;
		}
		else
		{
			if(auxPassengerA->precio < auxPassengerB->precio)
				rta = -1;
		}
	}

	return rta;
}


/**
 * \brief compara el tipo de pasajero de dos estructura
 * \param puntero generico
 * \param puntero generico
 * \return 1 si es mayor, 0 si son iguales, -1 si es menor
 */
int CompararPasajeroTipoPas(void* a, void* b)
{
	int rta = 0;
	Passenger* auxPassengerA = NULL;
	Passenger* auxPassengerB = NULL;

	if(a != NULL && b != NULL)
	{
		auxPassengerA = (Passenger*)a;
		auxPassengerB = (Passenger*)b;

		rta = strcmp(auxPassengerA->tipoPasajero, auxPassengerB->tipoPasajero);
		//1 si es mayor
		//0 si son iguales
		//-1 si es menor
	}
	return rta;
}


/**
 * \brief compara el odigo de vuelo de dos estructura
 * \param puntero generico
 * \param puntero generico
 * \return 1 si es mayor, 0 si son iguales, -1 si es menor
 */
int CompararPasajeroCodigoVuelo(void* a, void* b)
{
	int rta = 0;
	Passenger* auxPassengerA = NULL;
	Passenger* auxPassengerB = NULL;

	if(a != NULL && b != NULL)
	{
		auxPassengerA = (Passenger*)a;
		auxPassengerB = (Passenger*)b;

		rta = strcmp(auxPassengerA->codigoVuelo, auxPassengerB->codigoVuelo);
		//1 si es mayor
		//0 si son iguales
		//-1 si es menor
	}
	return rta;
}


/**
 * \brief compara el estado de vuelo de dos estructura
 * \param puntero generico
 * \param puntero generico
 * \return 1 si es mayor, 0 si son iguales, -1 si es menor
 */
int CompararPasajeroEstadoVuelo(void* a, void* b)
{
	int rta = 0;
	Passenger* auxPassengerA = NULL;
	Passenger* auxPassengerB = NULL;

	if(a != NULL && b != NULL)
	{
		auxPassengerA = (Passenger*)a;
		auxPassengerB = (Passenger*)b;

		rta = strcmp(auxPassengerA->statusFlight, auxPassengerB->statusFlight);
		//1 si es mayor
		//0 si son iguales
		//-1 si es menor
	}
	return rta;
}
