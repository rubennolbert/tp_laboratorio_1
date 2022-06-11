/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char tipoPasajero[50];
	char codigoVuelo[50];
	char statusFlight[50];

}Passenger;

Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* idStr,char* nombreStr, char* apellidoStr, char* precioSr, char* flycodeStr, char* tipoPasajeroStr,char* estadoVueloStr);
int  Passenger_delete(Passenger* this);

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero);

int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo);
int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);



int BuscarMayorId(LinkedList* pArrayListPassenger);
int ShowPassenger(Passenger* this);
int ShowPassengers(LinkedList* this);
int SearchIdPassenger(LinkedList* pArrayListPassenger, int id);

int CompararPasajerId(void* a, void* b);
int CompararPasajeroNombre(void* a, void* b);
int CompararPasajeroApellido(void* a, void* b);
int CompararPasajerPrecio(void* a, void* b);
int CompararPasajeroTipoPas(void* a, void* b);
int CompararPasajeroCodigoVuelo(void* a, void* b);
int CompararPasajeroEstadoVuelo(void* a, void* b);



#endif /* PASSENGER_H_ */
