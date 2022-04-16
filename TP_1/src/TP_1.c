/*
 ============================================================================
 Name        : TP_1.c
 Author      : ruben Nolberto lopez Division 1F
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

 - Trabajo practico 1, laboratorio 1. -

 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "validar-mostrar.h"
#include "carga-calcular.h"

int main(void)
{
	setbuf(stdout, NULL);
    int flagKm, flagPrecio, flagCalcular = 0;
    char iSeguir = 's';
    float km;
    float precioAerolineas, precioLatam;
    float precioDesAerolineas, precioDesLatam;
    float precioIntAero, precioIntLatam;
    double precioBtcAero, precioBtcLatam;
    float precioUnitAero, precioUnitLatam, precioDiferencia;

    MostrarMenu("1. ingrese kilometros.\n2. ingrese precio de vuelos.\n3. calcular todos los costos.\n4. Informe resultados.\n5. Carga forzada de datos.\n6. Salir.\n");

    do
    {
        switch(FuncionMenu("Seleccione una opcion: ", 1, 6))
        {
            case 1:
                if(flagKm == 1)
                {
                    system("cls");
                    MostrarMenu("1. ingrese kilometros.\n2. ingrese precio de vuelos.\n3. calcular todos los costos.\n4. Informe resultados.\n5. Carga forzada de datos.\n6. Salir.\n");
                }

                km = CargarKilometros();
                flagKm = 1;
                printf("-------------------------------------------------------\n");
            break;
            case 2:
                if(flagKm == 1)
                {
                    precioAerolineas = CargarPrecioVuelos("\tIngrese precio: Aerolineas = $ ");
                    precioLatam = CargarPrecioVuelos("\tIngrese precio: Latam = $ ");
                    flagPrecio = 1;
                    printf("-------------------------------------------------------\n");
                }
                else
                {
                    printf("Debe cargar los Kilometros: \n\n");
                }
            break;
            case 3:
                if(flagPrecio == 1)
                {
                    precioDesLatam = CalcularDescuento(precioLatam, 10);
                    precioIntLatam = CalcularInteres(precioLatam, 25);
                    precioBtcLatam = CalcularEquivalenciaBtc(precioLatam, 4611521.32);
                    precioUnitLatam = CalcularPrecioKm(precioLatam, km);

                    precioDesAerolineas = CalcularDescuento(precioAerolineas, 10);
                    precioIntAero = CalcularInteres(precioAerolineas, 25);
                    precioBtcAero = CalcularEquivalenciaBtc(precioAerolineas, 4611521.32);
                    precioUnitAero = CalcularPrecioKm(precioAerolineas, km);
                    precioDiferencia = CalcularDifPrecio(precioAerolineas, precioLatam);
                    printf("\t>>>> Calculo realizado! <<<<\n-------------------------------------------------------\n");

                    flagCalcular = 1;
                }
                else
                {
                    printf("Para calcular, debe cargar los Kilometros y precios: \n\n");
                }
            break;
            case 4:
                if(flagCalcular == 1)
                {
                    system("cls");
                    printf("KMs Ingresados: %.2f Km.\n\n", km);
                    printf("Aerolineas: $ %.2f\na) Precio con tarjeta de debito: $ %.2f\nb) Precio con tarjeta de credito: $ %.2f\nc) Precio pagando con Bitcoin:Btc %.12lf\ne) Precio Unitario: $ %.2f\n\n", precioAerolineas, precioDesAerolineas, precioIntAero, precioBtcAero, precioUnitAero);
                    printf("Latam: $ %.2f\na) Precio con tarjeta de debito: $ %.2f\nb) Precio con tarjeta de credito: $ %.2f\nc) Precio pagando con Bitcoin: Btc %.12lf\ne) Precio Unitario: $ %.2f\n", precioLatam, precioDesLatam, precioIntLatam, precioBtcLatam, precioUnitLatam);
                    printf("\nLa diferencia de precio es: $ %.2f\n\n", precioDiferencia);
                    printf("-------------------------------------------------------\n");
                    printf("1. Nueva carga de datos.\n6. Finalizar programa.\n\n");

                }
                else
                {
                    printf("Para ver los resultados, debe cargar los Kilometros y precios: \n\n");
                }
            break;
            case 5:
                system("cls");
                CargaForzada(7090, 162965, 159339);
                printf("-------------------------------------------------------\n");
                printf("1. Nueva carga de datos.\n6. Finalizar programa.\n\n");
                flagKm = 1;

            break;
            case 6:
                iSeguir = 'n';
            break;
        }

    }while(iSeguir == 's');

    printf("------ Gracias, vuelvas prontos! ------\n\n");
    system("pause");
    return 0;
}

