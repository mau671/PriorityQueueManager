/*
 * Archivo: UserTypeManager.h
 * Descripci�n: Este archivo contiene las declaraciones de las funciones para
 *              gestionar tipos de usuario, incluyendo la adici�n, eliminaci�n
 *              y visualizaci�n de los tipos de usuario en una lista.
 *              Las funciones operan sobre una lista de pares clave-valor
 *              donde la clave es la prioridad del tipo de usuario y el valor
 *              es la descripci�n del tipo.
 *
 * Autor(es): Mauricio Gonzalez
 */

#ifndef USERTYPEMANAGER_H
#define USERTYPEMANAGER_H

#include <string>
#include "OrderedArrayList.h"
#include "KVPair.h"

using std::string;

// Funciones relacionadas con la gesti�n de tipos de usuario
void addUserType(List<KVPair<int, string>>* userTypes, const string& description, int priority);
void displayAndRemoveUserType(List<KVPair<int, string>>* userTypes);
void showUserTypeMenu(List<KVPair<int, string>>* userTypes);

#endif // USERTYPEMANAGER_H
