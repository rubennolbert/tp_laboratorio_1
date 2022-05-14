/*
 ============================================================================
 Name        : TP_2.c
 Author      : ruben lopez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/* TP 2    Alumno: Lópes Rubén Nolberto  Division: 1E   */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayPassenger.h"
#include "Carga-Validacion.h"

#define TRUE 1
#define FALSE 0
#define TAM_TIPOPAS 2
#define TAM_ESTADOVUE 3
#define TAM 2000

int main()
{
	setbuf(stdout, NULL);

    ePassenger listaPassenger[TAM];
    eTypePassenger listaTipoPasajero[TAM_TIPOPAS] = {{1, "Turista"},{2, "Ejecutivo"}};
    eStatusFlight ListaEstadoVuelo[TAM_ESTADOVUE] = {{1, "Activo"},{2, "Demorado"},{3, "Cancelado"}};

    char opcion = 'S';
    int contadorID = 10000;
    int contadorOperacion = 0;
    int r1, r2;
    int opcionId;
    char nombre[51];
    char apellido[51];
    float precio;
    int tipoPasajero;
    int estadoVuelo;
    char codigoVuelo[21];
    int i1, i2;

    MostrarMenu();
    initPassengers(listaPassenger, TAM);

    do
    {
        switch(FuncionMenu("Seleccione una opcion: ", 1, 6))
        {
            case 1: //ALTAS
                r1 = findFreeSpace(listaPassenger, TAM);
                if(r1 == -1)
                {
                    printf("\tno hay espacio. \n");
                }
                else
                {
                    getString("\tIngrese Nombre: ", nombre);
                    i1 = esSoloLetras(nombre);
                    while(i1 == 0){
                        getString("\tError, Ingrese Nombre: ", nombre);
                        i1 = esSoloLetras(nombre);
                    }

                    getString("\tIngrese Apellido: ", apellido);
                    i2 = esSoloLetras(apellido);
                    while(i2 == 0){
                        getString("\tError, Ingrese Apellido: ", apellido);
                        i2 = esSoloLetras(apellido);
                    }
                    precio = getFloat("\tIngrese Precio vuelo: ");

                    tipoPasajero = getInt("\tIngrese tipo de pasajero: \n\t\t1. Turista.\n\t\t2. Ejecutivo.\n\t\tSeleccione opcion: ");
                    while(0==ValidarNumero(tipoPasajero, 1, 2))
                        tipoPasajero = getInt("\tIngrese tipo de pasajero: \n");


                    estadoVuelo = getInt("\tIngrese estado de vuelo: \n\t\t1. Activo. \n\t\t2. Demorado. \n\t\t3. Cancelado. \n\t\tSeleccione opcion: ");
                    while(0==ValidarNumero(estadoVuelo, 1, 3))
                        estadoVuelo = getInt("\tIngrese estado de vuelo: \n");


                    getString("\tIngrese codigo de vuelo: ", codigoVuelo);

                    contadorID ++;
                    contadorOperacion ++;
                    r2 = addPassenger(listaPassenger, TAM, contadorID, nombre, apellido, precio, tipoPasajero, estadoVuelo, codigoVuelo, listaTipoPasajero, ListaEstadoVuelo);
                    if(r2 == -1)
                        printf("Error, en la carga de vector datos: \n");
                }
                break;
            case 2: //MODIFICAR
                if(contadorOperacion > 0)
                {
                    ModificarPasajero(listaPassenger, TAM);
                }
                else
                {
                    printf("\tERROR, para modificar primero debe dar de alta los datos del pasajero.\n\n");
                }
                break;
            case 3: //BAJA
                if(contadorOperacion > 0)
                {
                    printf("\tIngrese id del pasajero a dar de baja: ");
                    scanf("%d", &opcionId);
                    removePassenger(listaPassenger, TAM, opcionId);
                    contadorOperacion --;
                }
                else
                {
                    printf("\tERROR, para dar de baja primero debe dar de alta los datos del pasajero.\n\n");
                }
                break;
            case 4: //INFORMAR
                 if(contadorOperacion > 0)
                {
                    sortPassengers1(listaPassenger, TAM, 1);
                    printPassenger(listaPassenger, TAM, listaTipoPasajero, ListaEstadoVuelo);   //1 list pass por apellido y tipo
                    TotalPromedioPrecios(listaPassenger, TAM); //2. total y promedio y cant de pass superan el promedio
                    sortPassengersBycode(listaPassenger, TAM, 1);
                    printPassenger(listaPassenger, TAM, listaTipoPasajero, ListaEstadoVuelo); //3. list pass por code estados activos
                }
                else
                {
                    printf("\tERROR, para informar primero debe dar de alta los datos del pasajero.\n\n");
                }
                break;
            case 5:
                HardcodeoPasajeros(listaPassenger);
                printPassenger(listaPassenger, TAM, listaTipoPasajero, ListaEstadoVuelo);
                break;
            case 6: //SALIR
                printf("--------- Gracias Muchas! ------");
                opcion = 'N';
                break;
            }

    }while(opcion == 'S');

    system("pause");
    return 0;
}












