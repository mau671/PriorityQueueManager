/*
 * Archivo: tiquete.h
 * Descripci�n: Este archivo contiene la implementaci�n de las funciones para la creaci�n y gesti�n de tiquetes.
 *
 * Autor(es): Josu� Meza
 */

#ifndef GESTORTIQUETE_H
#define GESTORTIQUETE_H

#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <sstream>
#include "Modelos/Tiquete.h"
#include "UI/Menu.h"
#include "Utilidades/utils.h"
#include "Modelos/TipoUsuario.h"

using std::string;

//Hora actual en formato HH:MM:SS
string obtenerHoraActual();
// Crear un nuevo tiquete
void addTiquete(List<TipoUsuario*>* usuarios, List<Servicio*>* servicios, int* consecutivoGlobal);


#endif