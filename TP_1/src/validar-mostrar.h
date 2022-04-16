/*
 * validar-mostrar.h
 *
 *  Created on: 16 abr. 2022
 *      Author: ruben
 */



#ifndef VALIDAR_MOSTRAR_H_
#define VALIDAR_MOSTRAR_H_


/**
 * \brief permite ingresar un numero entero y validar dentro de un rango específico.
 * 		  devuelvo otro entero confirmando por verdaero o falso.
 * \param num = entero a ingresar.
 * \param min = entero minimo que limita el rango.
 * \param max = entero maximo que limita el rango.
 * \return 1 si esta dentro del rango ó 0 si no lo esta.
 */
int ValidarNumero(int num, int limiteMin, int limiteMax);

/**
 * \brief muestra un mesanje de menu, ingresado por paramentro.
 * \param cadena de caracter = mensaje especifico.
 * \return sin retorno.
 */
void MostrarMenu(char mensaje[]);

/**
 * \brief valida y devuelve un entero seleccionado, ingresando un mensaje específico.
 * \param  char mensaje = mesaje a mostrar.
 * \param int min = entero minimo que limita el rango.
 * \param int max = entero maximo que limita el rango.
 * \return entero seleccionado.
 */
int FuncionMenu(char mensaje[], int min, int max);




#endif /* VALIDAR_MOSTRAR_H_ */
