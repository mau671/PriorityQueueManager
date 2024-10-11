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
#include "Modelos/TipoUsuario.h"

using std::string;

// Funciones relacionadas con la gestión de tipos de usuario
void addUserType(List<TipoUsuario*>* tiposDeUsuarios);
void displayAndRemoveUserType(List<TipoUsuario*>* tiposDeUsuarios, List<Area*>* areas);
void showUserTypeMenu(List<TipoUsuario*>* userTypes, List<Area*>* areas);

#endif // GESTORTIPOUSUARIO_H
