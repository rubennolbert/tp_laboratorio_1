/*
 * Carga-Validacion.h
 *
 *  Created on: 14 may. 2022
 *      Author: ruben
 */

#ifndef CARGA_VALIDACION_H_
#define CARGA_VALIDACION_H_

/**
 * \brief muestra un menu de opcino para seleccionar.
 * no se le pasapara por parametros nada y devuelve vacio.
 */
void MostrarMenu(void);

/**
 * \brief muestra un menu de opcino para seleccionar.
 * no se le pasapara por parametros nada y devuelve vacio.
 */
void MostrarMenuModificacion(void);



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
 * \brief muestra y devuelve como entero las opcions de un menu
 * \param mensaje
 * \param min
 * \param max
 * \return un numero entero con la opcion
 */
int FuncionMenu(char mensaje[], int min, int max);




/**
 * \brief carga una cadena
 * \param mensaje
 * \param cadena
 * \return devuelve la cadena por referncia
 */
void getString(char mensaje[],char cadena[]);

/**
 * \brief carga una cadena alfanumerico
 * \param mensaje
 * \param cadena
 * \return vacio.
 */
void getStringNumber(char mensaje[],char cadena[]);


/**
 * \brief permite seleccionar entre si o no, validando dicho caracter
 * \param mensaje
 * \param letra
 * \param MensajeError
 * \return 1 si todo salio bien, 0 si hubo un problema
 */
int FuncConfirma(char mensaje[], char* letra, char MensajeError[]);

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

/**
 * \brief  carga un intero dentro de un rango determinado
 * \param mensaje
 * \param min numero entero
 * \param max numero entero
 * \return 1 si salio todo bien, 0 para todo lo contrario
 */
int getIntRange(char mensaje[], int min, int max);


/**
 * \brief permite seleccionar y cagar en cadena tipo de pasajero.
 * \param tipoPasajero como numero
 * \param cadena
 * \return vacio
 */
void OpcionTipoPasajero(int tipoPasajeInt, char cadena[]);

/**
 * \brief permite seleccionar y cagar en cadena estado de vuelo.
 * \param stado de vuelo como numero
 * \param cadena
 * \return vacio
 */
void OpcionEstadoVuelo(int estadoVueloInt, char cadena[]);



#endif /* CARGA_VALIDACION_H_ */
