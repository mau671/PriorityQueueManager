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
