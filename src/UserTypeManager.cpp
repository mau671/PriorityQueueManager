/*
 * Archivo: UserTypeManager.cpp
 * Descripción: Este archivo contiene la implementación de funciones para gestionar
 *              los tipos de usuario en el sistema. Las funcionalidades incluyen agregar
 *              nuevos tipos de usuario, eliminar tipos de menor prioridad, y mostrar un menú
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

// Función para agregar un nuevo tipo de usuario
void addUserType(List<KVPair<int, string>>* userTypes, const string& description, int priority) {
    if (priority < 1) {
        cout << "Prioridad inválida. Debe ser un número positivo.\n";
        return;
    }
    userTypes->insert(KVPair<int, string>(priority, description));
    cout << "Tipo de usuario '" << description << "' con prioridad " << priority << " agregado exitosamente.\n";
    cout << "Presione Enter para continuar...";
    cin.get();
}

// Función para mostrar todos los tipos de usuario y eliminar el seleccionado
void displayAndRemoveUserType(List<KVPair<int, string>>* userTypes) {
    if (userTypes->getSize() == 0) {
        cout << "No hay tipos de usuario para eliminar." << endl;
        pause();
        return;
    }

    Menu menu("== Eliminar tipo de usuario ==");
    for (int i = 0; i < userTypes->getSize(); i++) {
        userTypes->goToPos(i);
        menu.addOption(userTypes->getElement().value); // Agregar la descripción del tipo de usuario
    }
    menu.addOption("Cancelar");

    int selection;
    do {
        menu.display();
        selection = menu.getSelection();

        if (selection == userTypes->getSize() + 1) {
            cout << "Operación cancelada.\n";
            return;
        }

        userTypes->goToPos(selection - 1);
        cout << "Tipo de usuario eliminado.\n";
        userTypes->remove();
    } while (selection < 1 || selection > userTypes->getSize() + 1);
}

// Función para mostrar el menú de tipos de usuario
void showUserTypeMenu(List<KVPair<int, string>>* userTypes) {
    Menu menu("== Menú de tipos de usuario ==");
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
            cout << "Descripción: ";
            std::getline(cin, description);
            priority = readInt("Prioridad: ");
            addUserType(userTypes, description, priority);
            break;
        }
        case 2:
            displayAndRemoveUserType(userTypes);  // Pasar la lista de tipos de usuario
            break;
        case 3:
            cout << "Saliendo del menú de tipos de usuario.\n";
            break;
        default:
            cout << "Opción inválida. Intente de nuevo.\n";
        }
    } while (option != 3);
}