/*
 * Archivo: UserTypeManager.h
 * Descripción: Este archivo contiene las declaraciones de las funciones para
 *              gestionar tipos de usuario, incluyendo la adición, eliminación
 *              y visualización de los tipos de usuario en una lista.
 *              Las funciones operan sobre una lista de pares clave-valor
 *              donde la clave es la prioridad del tipo de usuario y el valor
 *              es la descripción del tipo.
 *
 * Autor(es): Mauricio Gonzalez
 */

#ifndef USERTYPEMANAGER_H
#define USERTYPEMANAGER_H

#include <string>
#include "OrderedArrayList.h"
#include "KVPair.h"

using std::string;

// Funciones relacionadas con la gestión de tipos de usuario
void addUserType(List<KVPair<int, string>>* userTypes, const string& description, int priority);
void displayAndRemoveUserType(List<KVPair<int, string>>* userTypes);
void showUserTypeMenu(List<KVPair<int, string>>* userTypes);

#endif // USERTYPEMANAGER_H
