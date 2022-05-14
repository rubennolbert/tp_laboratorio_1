/*
 * Carga-Validacion.h
 *
 *  Created on: 14 may. 2022
 *      Author: ruben
 */

#ifndef CARGA_VALIDACION_H_
#define CARGA_VALIDACION_H_


/**
 * \brief  limita a un numero dentro de un rago especificado
 * \param num
 * \param limiteMin
 * \param limiteMax
 * \return 1 si esta dentro de ese rango o 0 si no.
 */
int ValidarNumero(int num, int limiteMin, int limiteMax);

/**
 * \brief limita a numero dentro de un limite inferior
 * \param num
 * \return 1 si esta dentro de ese rango o 0 si no.
 */
int ValidarNumMayorCero(int num);

/**
 * \brief valida una cadena de caracteres
 * \param cadena
 * \return 1 si es una cadena, 0 si no lo es.
 */
int esSoloLetras(char cadena[]);


/**
 * \brief muestra un menu selectivo
 * \param vacio
 * \return vacio
 */
void MostrarMenu(void);

/**
 * \brief muestra y devuelve como entero las opcions de un menu
 * \param mensaje
 * \param min
 * \param max
 * \return un numero entero con la opcion
 */
int FuncionMenu(char mensaje[], int min, int max);


/**
 * \brief carga el vector estructura pasajero con un maximo de 10
 * \param list estructura pasajero
 * \return vacio
 */
void HardcodeoPasajeros(ePassenger* list);

/**
 * \brief carga una cadena
 * \param mensaje
 * \param cadena
 * \return devuelve la cadena por referncia
 */
void getString(char mensaje[],char cadena[]);

/**
 * \brief carga un numero flotante
 * \param mensaje
 * \return el numero cargado
 */
float getFloat(char mensaje[]);

/**
 * \brief carga un numero entero
 * \param mensaje
 * \return dicho entero cargado
 */
int getInt(char mensaje[]);



#endif /* CARGA_VALIDACION_H_ */
