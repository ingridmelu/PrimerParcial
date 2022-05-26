/*
 * viviendas.h
 *
 *  Created on: 26 may 2022
 *      Author: Familia
 */

#ifndef VIVIENDAS_H_
#define VIVIENDAS_H_
struct
{
	int idVivienda;
	char calle[25];
	int cantidadDePersonas;
	int cantidadDeHabitaciones;
	int tipoDeVivienda;
	int legajoCensista;
	int eliminado;
}typedef Vivienda;

int inicializarListaViviendas(Vivienda* listaViviendas, int tamanio);
int cargarListasViviendas(Vivienda auxVivienda, Vivienda* listaViviendas, int tamanio, int idVivienda, char auxCalle[25],int auxCantidadDePersonas, int auxCantidadDeHabitaciones, int auxTipoDeVivienda,int auxLegajoCensista);
int encontarId(Vivienda* listaViviendas, int tamanio,int id);
int eliminarVivienda(Vivienda* listaViviendas, int tamanio, int idVivienda);
int listaViviendas(Vivienda* listaViviendas, int len);
int mostrarListaViviendas(Vivienda listaViviendas[], int tamanio);


#endif /* VIVIENDAS_H_ */
