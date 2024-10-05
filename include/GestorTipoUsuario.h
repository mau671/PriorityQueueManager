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
#include "TipoUsuario.h"

using std::string;

// Funciones relacionadas con la gesti�n de tipos de usuario
void addUserType(List<TipoUsuario*>* userTypes, const string& description, int priority);
void displayAndRemoveUserType(List<TipoUsuario*>* userTypes);
void showUserTypeMenu(List<TipoUsuario*>* userTypes);

#endif // GESTORTIPOUSUARIO_H
