/*
 * Archivo: GestorTipoUsuario.cpp
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
#include "UI/Menu.h"
#include "Estructuras/Concretas/OrderedArrayList.h"
#include "Modelos/TipoUsuario.h"
#include "Utilidades/utils.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;

// Función para agregar un nuevo tipo de usuario
void addUserType(List<TipoUsuario*>* userTypes) {

    string description = readString("Descripción/nombre del tipo de usuario: ");

    int priority = readInt("Prioridad del tipo de usuario: ");

    userTypes->insert(new TipoUsuario(description, priority));
    cout << "Tipo de usuario '" << description << "' con prioridad " << priority << " agregado exitosamente.\n";
    pause();
}


// Función para mostrar todos los tipos de usuario y eliminar el seleccionado
void displayAndRemoveUserType(List<TipoUsuario*>* userTypes) {
    if (userTypes->getSize() == 0) {
        cout << "No hay tipos de usuario para eliminar." << endl;
        pause();
        return;
    }

    Menu menu("== Eliminar tipo de usuario ==");
    for (int i = 0; i < userTypes->getSize(); i++) {
        userTypes->goToPos(i);
        menu.addOption(userTypes->getElement()->getDescripcion()); // Agregar la descripción del tipo de usuario
    }
    menu.addOption("Cancelar");

    int selection;
    do {
        menu.display("Seleccione un tipo de usuario a eliminar: ");
        selection = menu.getSelection();

        if (selection == userTypes->getSize() + 1) {
            cout << "Operación cancelada.\n";
            return;
        }

        bool confirmacion = readConfirmation("¿Está seguro que desea eliminar este tipo de usuario?");
        if (!confirmacion) {
			cout << "Operación cancelada.\n";
			return;
		}

        userTypes->goToPos(selection - 1);
        delete userTypes->getElement(); // Liberar la memoria del objeto eliminado
        cout << "Tipo de usuario eliminado.\n";
        userTypes->remove();
        pause();
    } while (selection < 1 || selection > userTypes->getSize() + 1);
}


// Función para mostrar el menú de tipos de usuario
void showUserTypeMenu(List<TipoUsuario*>* userTypes) {
    Menu menu("== Menú de tipos de usuario ==");
    menu.addOption("Agregar");
    menu.addOption("Eliminar");
    menu.addOption("Regresar");

    int option;
    do {
        menu.display();
        option = menu.getSelection();

        switch (option) {
        case 1:
            addUserType(userTypes);
            break;
        case 2:
            displayAndRemoveUserType(userTypes);  // Pasar la lista de tipos de usuario
            break;
        case 3:
            return;
        default:
            cout << "Opción inválida. Intente de nuevo.\n";
        }
    } while (option != 3);
}

