/*
 * carga-calcular.c
 *
 *  Created on: 16 abr. 2022
 *      Author: ruben
 */
#include <stdio.h>
#include <stdlib.h>
#include "validar-mostrar.h"
#include "carga-calcular.h"

float CargarKilometros(void)
{
    float kilometros;

    printf("\tIngrese los kilometros: km = ");
    fflush(stdin);
    scanf("%f", &kilometros);

    while(kilometros < 1 )
    {
        printf("Error, Ingrese los kilometros a calcular: ");
        fflush(stdin);
        scanf("%f", &kilometros);
    }

    return kilometros;

}


float CargarPrecioVuelos(char mensaje[])
{
    float precio;

    printf("%s", mensaje);
    fflush(stdin);
    scanf("%f", &precio);
   while(precio < 1 )
   {
        printf("Error, ingrese nuevamente: ");
        fflush(stdin);
        scanf("%f", &precio);
   }

    return precio;
}

float CalcularDescuento(float precio, float descuento)
{
    float resultado;

    resultado = precio - (descuento*precio/100);

    return resultado;
}

float CalcularInteres(float precio, float interes)
{
    float resultado;

    resultado = precio + (interes*precio/100);

    return resultado;
}


double CalcularEquivalenciaBtc(float precio, double ValorBtc_x1)
{
    double resultado;

    resultado = precio/ValorBtc_x1;

    return resultado;
}


float CalcularPrecioKm(float precio, float km)
{
    float resultado;

    resultado = precio/km;

    return resultado;


}


float CalcularDifPrecio(float precioVuelo_1, float precioVuelo_2)
{
    float resultado;
    int uno = 1;

    if(precioVuelo_1<precioVuelo_2)
        uno = -1;

    resultado = (precioVuelo_1 - precioVuelo_2)*uno;

    return resultado;

}








void CargaForzada(float km, float precio_Aero, float precio_Latam)
{

    float precioDesAerolineas, precioDesLatam;
    float precioIntAero, precioIntLatam;
    double precioBtcAero, precioBtcLatam;
    float precioUnitAero, precioUnitLatam, precioDiferencia;

    precioDesLatam = CalcularDescuento(precio_Latam, 10);
    precioIntLatam = CalcularInteres(precio_Latam, 25);
    precioBtcLatam = CalcularEquivalenciaBtc(precio_Latam, 4611521.32);
    precioUnitLatam = CalcularPrecioKm(precio_Latam, km);

    precioDesAerolineas = CalcularDescuento(precio_Aero, 10);
    precioIntAero = CalcularInteres(precio_Aero, 25);
    precioBtcAero = CalcularEquivalenciaBtc(precio_Aero, 4611521.32);
    precioUnitAero = CalcularPrecioKm(precio_Aero, km);

    precioDiferencia = CalcularDifPrecio(precio_Aero, precio_Latam);

    printf("KMs Ingresados: %.2f Km.\n\n", km);
    printf("Aerolineas: $ %.2f\na) Precio con tarjeta de debito: $ %.2f\nb) Precio con tarjeta de credito: $ %.2f\nc) Precio pagando con Bitcoin: Btc %.12lf\ne) Precio Unitario: $ %.2f\n\n", precio_Aero, precioDesAerolineas, precioIntAero, precioBtcAero, precioUnitAero);
    printf("Latam: $ %.2f\na) Precio con tarjeta de debito: $ %.2f\nb) Precio con tarjeta de credito: $ %.2f\nc) Precio pagando con Bitcoin: Btc %.12lf\ne) Precio Unitario: $ %.2f\n", precio_Latam, precioDesLatam, precioIntLatam, precioBtcLatam, precioUnitLatam);
    printf("\nLa diferencia de precio es: $ %.2f\n\n", precioDiferencia);


}

