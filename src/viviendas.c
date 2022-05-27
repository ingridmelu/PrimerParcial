/*
 * viviendas.c
 *
 *  Created on: 26 may 2022
 *      Author: Familia
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "viviendas.h"
#include "censistas.h"

int inicializarListaViviendas(Vivienda* listaViviendas, int tamanio)
{
	for(int i = 0; i<tamanio; i++)
	{
		listaViviendas[i].eliminado = -1;
		listaViviendas[i].idVivienda = -1;
	}
	return 0;
}
int cargarListasViviendas(Vivienda auxVivienda, Vivienda* listaViviendas, int tamanio, int idVivienda, char auxCalle[25],int auxCantidadDePersonas, int auxCantidadDeHabitaciones, int auxTipoDeVivienda,int auxLegajoCensista)
{
	for(int i = 0; i < tamanio; i++)
	{
		strcpy(auxVivienda.calle, auxCalle);
		auxVivienda.cantidadDePersonas = auxCantidadDePersonas;
		auxVivienda.cantidadDeHabitaciones = auxCantidadDeHabitaciones;
		auxVivienda.tipoDeVivienda = auxTipoDeVivienda;
		auxVivienda.legajoCensista = auxLegajoCensista;
		auxVivienda.eliminado = 0;
		auxVivienda.idVivienda = idVivienda;
	}
	for(int i = 0; i< tamanio; i++)
	{
		if(listaViviendas[i].eliminado == -1)
		{
			listaViviendas[i] = auxVivienda;
			break;//rompe el for de la linea 37
		}
	}
	return 0;
}
int encontarId(Vivienda* listaViviendas, int tamanio,int id)
{
	int posicionDevolver= -1;
	if(listaViviendas == NULL)
	{
		return -1;
	}
	for(int i = 0; i < tamanio; i++)
	{
		if(listaViviendas[i].idVivienda == id)
		{
			posicionDevolver = i;
		}
	}
	return posicionDevolver;
}
int eliminarVivienda(Vivienda* listaViviendas, int tamanio, int idVivienda)
{
	int retorno =0;

		if(listaViviendas == NULL)
		{
			return -1;
		}

		listaViviendas[idVivienda].idVivienda= -1;
		listaViviendas[idVivienda].eliminado= -1;

		return retorno;
}
int listaViviendas(Vivienda* listaViviendas, int len)
{
	int comparacion = 0;

	Vivienda listA;
	if(listaViviendas == NULL)
	{
		return -1;
	}
	for(int i = 0; i < len; i++)
	{
		for (int j = i+1; j < len; j++)
		{
			if (listaViviendas[j].eliminado != -1)
			{
				comparacion = strcmp(listaViviendas[i].calle, listaViviendas[j].calle);
				if(comparacion == 0)
				{
					if(listaViviendas[i].cantidadDePersonas > listaViviendas[j].cantidadDePersonas)
					{
						comparacion = 1;
					}
				}

				if (comparacion == 1)
				{
					comparacion = 0;

					listA = listaViviendas[i];
					listaViviendas[i] = listaViviendas[j];
					listaViviendas[j] = listA;

					j = i+1;
				}
			}
		}
	}
	return 0;
}

int mostrarListaViviendas(Vivienda listaViviendas[], int tamanio)
{
	int i;
	printf("La lista de las viviendas son: \n"
			"|Calle:\t|\t Cantidad de Personas:\t|\tCantidad de habitaciones:\t|\tTipo de vivienda:\t|\t Legajo: \t|\t id: \n\n");
	for (i = 0; i < tamanio; i++)
	{
		if(listaViviendas[i].idVivienda != -1)
		{
			if(listaViviendas[i].legajoCensista == 100)
			{
				printf("100, ANA, 34 , 1203-2345\n");
				printf("%s \t\t\t%d \t\t\t\t%d \t\t\t\t  %d \t\t\t\t %d \t\t\t%d\n", listaViviendas[i].calle, listaViviendas[i].cantidadDePersonas,
							listaViviendas[i].cantidadDeHabitaciones, listaViviendas[i].tipoDeVivienda, listaViviendas[i].legajoCensista, listaViviendas[i].idVivienda);
			}
			else if(listaViviendas[i].legajoCensista == 101)
			{
				printf("{101, JUAN, 24, 43015-4678\n");
				printf("%s \t\t\t%d \t\t\t\t%d \t\t\t\t  %d \t\t\t\t %d \t\t\t%d\n", listaViviendas[i].calle, listaViviendas[i].cantidadDePersonas,
							listaViviendas[i].cantidadDeHabitaciones, listaViviendas[i].tipoDeVivienda, listaViviendas[i].legajoCensista, listaViviendas[i].idVivienda);
			}
			else
			{
				printf("{102, SOL, 37, 5902-37487}\n");
				printf("%s \t\t\t%d \t\t\t\t%d \t\t\t\t  %d \t\t\t\t %d \t\t\t%d\n", listaViviendas[i].calle, listaViviendas[i].cantidadDePersonas,
							listaViviendas[i].cantidadDeHabitaciones, listaViviendas[i].tipoDeVivienda, listaViviendas[i].legajoCensista, listaViviendas[i].idVivienda);
			}
		}
	}
	return 0;
}


