/*
 * Archivo: GestorTipoUsuario.h
 * Descripci�n: Este archivo contiene las declaraciones de las funciones para
 *              gestionar tipos de usuario, incluyendo la adici�n, eliminaci�n
 *              y visualizaci�n de los tipos de usuario en una lista.
 *
 * Autor(es): Mauricio Gonzalez
 */

#ifndef GESTORTIPOUSUARIO_H
#define GESTORTIPOUSUARIO_H

#include <string>
#include "Estructuras/Concretas/OrderedArrayList.h"
#include "Modelos/TipoUsuario.h"

using std::string;

// Funciones relacionadas con la gesti�n de tipos de usuario
void addUserType(List<TipoUsuario*>* tiposDeUsuarios);
void displayAndRemoveUserType(List<TipoUsuario*>* tiposDeUsuarios, List<Area*>* areas);
void showUserTypeMenu(List<TipoUsuario*>* userTypes, List<Area*>* areas);

#endif // GESTORTIPOUSUARIO_H
