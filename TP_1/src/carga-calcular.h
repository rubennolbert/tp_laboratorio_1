/*
 * carga-calcular.h
 *
 *  Created on: 16 abr. 2022
 *      Author: ruben
 */




#ifndef CARGA_CALCULAR_H_
#define CARGA_CALCULAR_H_

/**
 * \brief pide y carga datos flotante de kilometros, devolviendo dicho dato validado.
 * \param no pide ningun parametro.
 * \return kilometro como numero flotante.
 */
float CargarKilometros(void);

/**
 * \brief pide y carga datos flotante de precio, devolviendo dicho dato validado
 * \param mensaje = ingresa un mesaje a mostrar.
 * \return precio como numero flotante.
 */
float CargarPrecioVuelos(char mensaje[]);

/**
 * \brief calcula el descuento de un precio ingresado, pudiendo establecer el numero descuento
 * \param precio como dato flotante.
 * \param descuento como numero flotante
 * \return precio total con el descuento realizado.
 */
float CalcularDescuento(float precio, float descuento);

/**
 * \brief calcula el interes de un precio ingresado, pudiendo establecer el numero interes.
 * \param precio com dato flotante
 * \param interes como numero flotante
 * \return precio total con el interes realizado.
 */
float CalcularInteres(float precio, float interes);

/**
 * \brief calcula la equivalencia monetaria, ingresando el precio y valor de la moneda a equiparar.
 * \param precio total
 * \param ValorBtc_x1 = valor por 1 de la moneda del precio.
 * \return el valor equivalente.
 */
double CalcularEquivalenciaBtc(float precio, double ValorBtc_x1);

/**
 * \brief  calcula el precio por cada kilometro.
 * \param precio total.
 * \param km total.
 * \return precio por cada km.
 */
float CalcularPrecioKm(float precio, float km);

/**
 * \brief calcula la diferencia de precio entre dos numeros ingresados
 * \param precioVuelo_1 = primero precio ingresado.
 * \param precioVuelo_2 = segundo precio ingresado.
 * \return devuelve la diferencia como numero flotante.
 */
float CalcularDifPrecio(float precioVuelo_1, float precioVuelo_2);

/**
 * \brief permite calcular y mostrar las operaciones de descuento, interes, equivalenia bitcoin,
 * 		  precio unitario km y diferencia entre dos precios.
 * \param kilometros
 * \param precio_Aero  = primero precio.
 * \param precio_Latam = segundo precio.
 * \return sin retorno.
 */
void CargaForzada(float km, float precio_Aero, float precio_Latam);

#endif /* CARGA_CALCULAR_H_ */
