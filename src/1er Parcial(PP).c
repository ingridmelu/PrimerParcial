/*
 ============================================================================
 Name        : 1er.c
 Author      : Romero Melany
 Version     : Division D
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "imputs.h"
#include "viviendas.h"
#include "censistas.h"
#define TAMVIVIENDAS 150

int main(void)
{
	setbuf(stdout, NULL);
	int opciones;
	int opcionesMenu;
	int validar;
	int bandera = 0;
	int buscarPosicion;
	int idABuscar;
	int removerVivienda;
	int contadorCensistas;

	int idVivienda = 20000;
	char auxCalle[25];
	int auxCantidadDePersonas;
	int auxCantidadDeHabitaciones;
	int auxTipoDeVivienda;
	int auxLegajoCensista;




	Vivienda listaViviendas[TAMVIVIENDAS];
	Vivienda auxVivienda;
	Censista listaCensista[3] = {{100,"ANA", 34 , "1203-2345"},
								{101, "JUAN", 24, "43015-4678"},
								{102, "SOL", 37, "5902-37487"}};

	inicializarListaViviendas(listaViviendas, TAMVIVIENDAS);

	do
	{
		printf("--------------------------------\n"
				"MENU DE OPCIONES\n"
			"------------------------------------\n"
			"1-Alta de vivienda\n"
			"2-Modicacion\n"
			"3-Baja vivienda\n"
			"4-ListarViviendas\n"
			"5-ListarCencista\n"
			"6-Salir\n");
		scanf("%d", &opciones);

		switch(opciones)
		{
			case 1:

				validar = cadenaValidada(auxCalle, "Ingrese calle: \n");

				if(validar == -1)
				{
					printf("Volviendo al menu\n");
					break;
				}

				validar = utn_getNumEntero(&auxCantidadDePersonas,"Ingrese la cantidad de personas: \n", "ERROR, ingrese la cantidad de personas: \n", 1, 40, 4);

				if(validar == -1)
				{
					printf("Volviendo al menu\n");
					break;
				}

				validar = utn_getNumEntero(&auxCantidadDeHabitaciones, "Ingrese la cantidad de habitaciones: \n", "ERROR, ingrese la cantidad de habitaciones: \n", 1,40, 4);

				if(validar == -1)
				{
					printf("Volviendo al menu\n");
					break;
				}

				validar = utn_getNumEntero(&auxTipoDeVivienda, "Ingrese el tipo de vivienda: 1.Casa - 2.Departamento - 3.Casilla - 4.Rancho \n", "ERROR, ingrese el tipo de vivienda: \n", 1,4,4);

				if(validar == -1)
				{
					printf("Volviendo al menu\n");
					break;
				}

				validar = utn_getNumEntero(&auxLegajoCensista, "Ingrese legajo del censista(100, 101, 102): \n", "ERROR, ingrese el legajo: \n", 100,102,4);

				if(validar == -1)
				{
					printf("Volviendo al menu\n");
					break;
				}

				idVivienda++;

				cargarListasViviendas(auxVivienda, listaViviendas, TAMVIVIENDAS, idVivienda, auxCalle , auxCantidadDePersonas, auxCantidadDeHabitaciones, auxTipoDeVivienda, auxLegajoCensista);

				printf("El id es: %d \n", idVivienda);
				bandera =1;
				break;
			case 2:
				if(bandera == 1)
				{
					pedirEntero(&idABuscar, "Ingresar ID de la vivienda que desea modificar: \n");
					buscarPosicion = encontarId(listaViviendas, TAMVIVIENDAS, idABuscar);

					if(buscarPosicion == -1)
					{
						printf("Ese id no existe\n");
					}
					else
					{
						do
						{
							printf("1-Ingrese la calle: \n"
								   "2-Ingrese la cantidad de personas: \n"
								   "3-Ingrese la cantidad de Habitaciones: \n"
								   "4-Ingrese el tipo de vivienda: 1.Casa - 2.Departamento - 3.Casilla - 4.Rancho\n"
									"5-Salir\n"
									"Ingrese la opcion deseada:\n");
							scanf("%d", &opcionesMenu);
							fflush(stdin);

							switch(opcionesMenu)
							{
							case 1:
								validar = cadenaValidada(listaViviendas[buscarPosicion].calle, "Ingrese calle: \n");

								if(validar == -1)
								{
									printf("Volviendo al menu\n");
									break;
								}

								break;

							case 2:
								validar = utn_getNumEntero(&listaViviendas[buscarPosicion].cantidadDePersonas,"Ingrese la cantidad de personas: \n", "ERROR, ingrese la cantidad de personas: \n", 1, 40, 4);

								if(validar == -1)
								{
									printf("Volviendo al menu\n");
									break;
								}
								break;

							case 3:
								validar = utn_getNumEntero(&listaViviendas[buscarPosicion].cantidadDeHabitaciones, "Ingrese la cantidad de habitaciones: \n", "ERROR, ingrese la cantidad de habitaciones: \n", 1,40, 4);

								if(validar == -1)
								{
									printf("Volviendo al menu\n");
									break;
								}

								break;

							case 4:
								validar = utn_getNumEntero(&listaViviendas[buscarPosicion].tipoDeVivienda, "Ingrese el tipo de vivienda: 1.Casa - 2.Departamento - 3.Casilla - 4.Rancho \n", "ERROR, ingrese el tipo de vivienda: \n", 1,4,4);

								if(validar == -1)
								{
									printf("Volviendo al menu\n");
									break;
								}

								break;
							case 5:
								printf("Salir \n");
								break;
							default:
								printf("Opcion invalida");
							}

						}while(opcionesMenu !=5 );
					}
				}
				else
				{
					printf("ERROR, primero ingrese la opcion 1");
				}
				break;
			case 3:
				if(bandera == 1)
				{

					pedirEntero(&idABuscar, "Ingresar ID de la vivienda que desea Borrar: \n");
					buscarPosicion = encontarId(listaViviendas, TAMVIVIENDAS, idABuscar);

					if(buscarPosicion == -1)
					{
						printf("Ese id no existe\n");
					}
					else
					{
						removerVivienda = eliminarVivienda(listaViviendas, TAMVIVIENDAS, buscarPosicion);
							if(removerVivienda == -1)
							{
								printf("Error, ese id no existe\n");
							}
							else
							{
								printf("Vivienda Eliminada\n");
							}
					}
				}
				break;
			case 4:
				if(bandera == 1)
				{
					mostrarListaViviendas(listaViviendas, TAMVIVIENDAS);
				}
				break;
			case 5:

				mostrarListaCensista(listaCensista, 3);

				break;
			case 6:
				printf("Salir \n");
				break;
			default:
				printf("Opcion invalida");
		}

	}while(opciones != 6);
return 0;
}
