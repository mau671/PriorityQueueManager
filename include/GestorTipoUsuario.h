/*
 * Archivo: GestorTipoUsuario.h
 * Descripción: Este archivo contiene las declaraciones de las funciones para
 *              gestionar tipos de usuario, incluyendo la adición, eliminación
 *              y visualización de los tipos de usuario en una lista.
 *
 * Autor(es): Mauricio Gonzalez
 */

#ifndef GESTORTIPOUSUARIO_H
#define GESTORTIPOUSUARIO_H

#include <string>
#include "Estructuras/Concretas/OrderedArrayList.h"
#include "TipoUsuario.h"

using std::string;

// Funciones relacionadas con la gestión de tipos de usuario
void addUserType(List<TipoUsuario*>* userTypes, const string& description, int priority);
void displayAndRemoveUserType(List<TipoUsuario*>* userTypes);
void showUserTypeMenu(List<TipoUsuario*>* userTypes);

#endif // GESTORTIPOUSUARIO_H
