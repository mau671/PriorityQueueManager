/*
 * Archivo: UserTypeManager.cpp
 * Descripci�n: Este archivo contiene la implementaci�n de funciones para gestionar
 *              los tipos de usuario en el sistema. Las funcionalidades incluyen agregar
 *              nuevos tipos de usuario, eliminar tipos de menor prioridad, y mostrar un men�
 *              interactivo para gestionar los tipos de usuario.
 *              Se utiliza una lista ordenada para almacenar los tipos de usuario.
 *
 * Autor(es): Mauricio Gonzalez
 */

#include <iostream>
#include <string>
#include <stdexcept>
#include "Menu.h"
#include "OrderedArrayList.h"
#include "KVPair.h"
#include "utils.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;

// Funci�n para agregar un nuevo tipo de usuario
void addUserType(List<KVPair<int, string>>* userTypes, const string& description, int priority) {
    if (priority < 1) {
        cout << "Prioridad inv�lida. Debe ser un n�mero positivo.\n";
        return;
    }
    userTypes->insert(KVPair<int, string>(priority, description));
    cout << "Tipo de usuario '" << description << "' con prioridad " << priority << " agregado exitosamente.\n";
    cout << "Presione Enter para continuar...";
    cin.get();
}

// Funci�n para mostrar todos los tipos de usuario y eliminar el de menor prioridad
void displayAndRemoveUserType(List<KVPair<int, string>>* userTypes) {
    if (userTypes->getSize() == 0) {
        cout << "No hay tipos de usuario para eliminar." << endl;
        pause();
        return;
    }

    Menu menu("== Eliminar tipo de usuario ==");
    for (int i = 0; i < userTypes->getSize(); i++) {
        userTypes->goToPos(i);
        menu.addOption(userTypes->getElement().value); // Agregar la descripci�n del tipo de usuario
    }
    menu.addOption("Cancelar");

    int selection;
    do {
        menu.display();
        selection = menu.getSelection();

        if (selection == userTypes->getSize() + 1) {
            cout << "Operaci�n cancelada.\n";
            return;
        }

        userTypes->goToPos(selection - 1);
        cout << "Tipo de usuario eliminado.\n";
        userTypes->remove();
    } while (selection < 1 || selection > userTypes->getSize() + 1);
}

// Funci�n para mostrar el men� de tipos de usuario
void showUserTypeMenu(List<KVPair<int, string>>* userTypes) {
    Menu menu("== Men� de tipos de usuario ==");
    menu.addOption("Agregar");
    menu.addOption("Eliminar");
    menu.addOption("Regresar");

    int option;
    do {
        menu.display();
        option = menu.getSelection();

        switch (option) {
        case 1: {
            string description;
            int priority;
            cout << "Descripci�n: ";
            std::getline(cin, description);
            priority = readInt("Prioridad: ");
            addUserType(userTypes, description, priority);
            break;
        }
        case 2:
            displayAndRemoveUserType(userTypes);  // Pasar la lista de tipos de usuario
            break;
        case 3:
            cout << "Saliendo del men� de tipos de usuario.\n";
            break;
        default:
            cout << "Opci�n inv�lida. Intente de nuevo.\n";
        }
    } while (option != 3);
}