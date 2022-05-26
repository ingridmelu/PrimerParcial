/*
 * censistas.h
 *
 *  Created on: 26 may 2022
 *      Author: Familia
 */

#ifndef CENSISTAS_H_
#define CENSISTAS_H_

struct
{
	int legajoCensista;
	char nombre[25];
	int edad;
	char telefono[20];
}typedef Censista;
/// @fn int cargarCensistas(eCensista*)
/// @brief carga los censistas hardcodeados
///
/// @param lista
/// @return
int mostrarListaCensista(Censista* listaCensista, int numero);


#endif /* CENSISTAS_H_ */
