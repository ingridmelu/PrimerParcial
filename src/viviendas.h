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
/**
 * @brief Inicializa el arrays
 *
 * @pre
 * @post
 * @param listaViviendas
 * @param tamanio
 * @return
 */
int inicializarListaViviendas(Vivienda* listaViviendas, int tamanio);
/**
 * @brief inicializa la lista de arrays
 *
 * @pre
 * @post
 * @param auxVivienda
 * @param listaViviendas
 * @param tamanio
 * @param idVivienda
 * @param auxCalle
 * @param auxCantidadDePersonas
 * @param auxCantidadDeHabitaciones
 * @param auxTipoDeVivienda
 * @param auxLegajoCensista
 * @return
 */
int cargarListasViviendas(Vivienda auxVivienda, Vivienda* listaViviendas, int tamanio, int idVivienda, char auxCalle[25],int auxCantidadDePersonas, int auxCantidadDeHabitaciones, int auxTipoDeVivienda,int auxLegajoCensista);
/**
 * @brief carga la lista de viviendas
 *
 * @pre
 * @post
 * @param listaViviendas
 * @param tamanio
 * @param id
 * @return
 */
int encontarId(Vivienda* listaViviendas, int tamanio,int id);
/**
 * @brief busca el Id y si lo encuentra lo retorna
 *
 * @pre
 * @post
 * @param listaViviendas
 * @param tamanio
 * @param idVivienda
 * @return retorna la posicion del id que encontro
 */
int eliminarVivienda(Vivienda* listaViviendas, int tamanio, int idVivienda);
/**
 * @brief elimina la vivienda
 *
 * @pre
 * @post
 * @param listaViviendas
 * @param len
 * @return 0 si funciono, -1 si no funciono
 */
int listaViviendas(Vivienda* listaViviendas, int len);
/**
 * @brief muestra las viviendas por pantalla
 *
 * @pre
 * @post
 * @param listaViviendas
 * @param tamanio
 * @return
 */
int mostrarListaViviendas(Vivienda listaViviendas[], int tamanio);


#endif /* VIVIENDAS_H_ */
