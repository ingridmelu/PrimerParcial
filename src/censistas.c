/*
 * censistas.c
 *
 *  Created on: 26 may 2022
 *      Author: Familia
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "viviendas.h"

int mostrarListaCensista(Censista listaCensista[], int numero)
{
	int i;
	printf("los censistas son: \n"
			"Legajo: \tNombre: \tEdad: \t\tTelefono:\n\n");
	for (i = 0; i < numero; i++)
	{
		printf("%d \t\t%s \t\t%d \t\t%s\n", listaCensista[i].legajoCensista, listaCensista[i].nombre,
				listaCensista[i].edad, listaCensista[i].telefono);
	}
	return 0;
}
int censistasConMasCensos(Censista* listaCensistas, Vivienda* listadoViviendas, int tamanio)
{
	int contadorJuan=0;
	int contadorSol=0;
	int contadorAna=0;


}

