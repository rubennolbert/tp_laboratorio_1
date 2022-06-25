/*
 * ArrayPassenger.h
 *
 *  Created on: 14 may. 2022
 *      Author: ruben
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

typedef struct
{
    int typePassenger;
    char description[51];

}eTypePassenger;

typedef struct
{
    int statusFlight;
    char description[51];

}eStatusFlight;

typedef struct
{
    int id;   //numero unico cuandos se usa, por mas que se borre o modifica, no lo manipula el usuario
    char name[51];
    char lastName[51];
    float price;
    char flyCode[10];   //
    int typePassenger;  //turista, primera clase
    int statusFlight;  // activo, demorado, cancelado
    int isEmpty;     //para saber si esta libre de datos o tiene basura, si es util para guardar

}ePassenger;


/**
 * \brief carga el vector estructura como espacio vacio
 * \param list vector struct
 * \param len
 * \return retorna -1 si basura en el vector o algun error en el inicio
 */
int initPassengers(ePassenger* list, int len);

/**
 * \brief busca espacio libre en el vector estructura para cargar datos
 * \param list
 * \param len
 * \return retorna -1 si no encontro espacio o hubo algun error o e indece del vector dsiponible
 */
int findFreeSpace(ePassenger* list, int len);


/**
 * \brief carga los datos en las variables del vector
 * \param list
 * \param len
 * \param id
 * \param name
 * \param lastName
 * \param price
 * \param typePassenger
 * \param statusFlight
 * \param flycode
 * \param listType
 * \param listStatus
 * \return retorna -1 si hay algun problema con el vector o si hubo error en la carga de datos
 */
int addPassenger(ePassenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, int statusFlight, char flycode[], eTypePassenger* listType, eStatusFlight* listStatus); //


/**
 * \brief busca el vector de estructura que coincida con el id seleccionado
 * \param list
 * \param len
 * \param id
 * \return -1 si hubo algun error o el indece del vector coincidente con el id elegido.
 */
int findPassengerById(ePassenger* list, int len,int id);


/**
 * \brief modifica los datos de una estructura previamente cargada
 * \param list
 * \param len
 * \return -1 si hubo alguno error en la modificacion o 0 si se modifico corretamente.
 */
int ModificarPasajero(ePassenger* list, int len);

/**
 * \brief elminina de manera logica los datos de un vector seleccionado
 * \param list
 * \param len
 * \param id
 * \return -1 si hubo un error en la baja o 0 si se realizo correctamente
 */
int removePassenger(ePassenger* list, int len, int id);

/**
 * \brief ordena de manera ascendente o descendente depende de la orden, los datos apellido y tipo de pasajero
 * \param list
 * \param len
 * \param order
 * \return 0
 */
int sortPassengers1(ePassenger* list, int len, int order, eTypePassenger* listType, eStatusFlight* listStatus); //Ordena el array de pasajeros por apellido y tipo de pasajero de manera ascendente o descendente.


/**
 * \brief muestra todos los datos del vector estrucutura pasajero
 * \param list
 * \param length
 * \param listType
 * \param listStatus
 * \return 0
 */
int printPassenger(ePassenger* list, int length,  eTypePassenger* listType, eStatusFlight* listStatus);


/**
 * \brief muestra los datos de una sola estructura
 * \param list
 * \param listType
 * \param listStatus
 * \return 0
 */
int printUnPasajero(ePassenger list, eTypePassenger* listType, eStatusFlight* listStatus);

/**
 * \brief ordena de manera ascendente o descendente depende de la orden, los datos codigo de vuelo y estado de vuelo
 * \param list
 * \param len
 * \param order
 * \return 0.
 */
int sortPassengersBycode(ePassenger* list, int len, int order, eTypePassenger* listType, eStatusFlight* listStatus); //Ordena el array de pasajeros por código de vuelo y estado de vuelo de manera ascendente o descendente.

/**
 * \brief calcula y muestra total, promedio y pasajero que supera el promedio de los precios ingresados
 * \param list
 * \param tam
 * \return 0
 */
int TotalPromedioPrecios(ePassenger* list, int tam);







#endif /* ARRAYPASSENGER_H_ */
