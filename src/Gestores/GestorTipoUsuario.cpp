/*
 * Archivo: GestorTipoUsuario.cpp
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
#include "UI/Menu.h"
#include "Estructuras/Concretas/OrderedArrayList.h"
#include "Modelos/TipoUsuario.h"
#include "Utilidades/utils.h"
#include "Modelos/Area.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;

// Funci�n para agregar un nuevo tipo de usuario
void addUserType(List<TipoUsuario*>* tiposDeUsuarios) {
    string description = readString("Descripción del tipo de usuario: ");

    // Validar que no exista un tipo de usuario con la misma descripcion
    for (int i = 0; i < tiposDeUsuarios->getSize(); i++) {
        tiposDeUsuarios->goToPos(i);
        if (tiposDeUsuarios->getElement()->getDescripcion() == description) {
            cout << "Tipo de usuario ya existente." << endl;
            pause();
            return;
        }
    }
    int prioridad = readInt("Prioridad del tipo de usuario: ");

    tiposDeUsuarios->insert(new TipoUsuario(description, prioridad));
    cout << "Tipo de usuario '" << description << "' con prioridad " << prioridad << " agregado exitosamente.\n";
    pause();
}


// Funci�n para mostrar todos los tipos de usuario y eliminar el seleccionado
void displayAndRemoveUserType(List<TipoUsuario*>* userTypes, List<Area*>* areas) {
    if (userTypes->getSize() == 0) {
        cout << "No hay tipos de usuario para eliminar." << endl;
        pause();
        return;
    }

    Menu menu("== Eliminar tipo de usuario ==");
    for (int i = 0; i < userTypes->getSize(); i++) {
        userTypes->goToPos(i);
        menu.addOption(userTypes->getElement()->getDescripcion()); // Agregar la descripci�n del tipo de usuario
    }
    menu.addOption("Cancelar");

    int selection;
    do {
        menu.display("Seleccione un tipo de usuario: "); //
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

        // Eliminar todos los tiquetes de todas las areas
        int tiquetesEliminados = 0;
        for (int i = 0; i < areas->getSize(); i++) {
			areas->goToPos(i);
			Area* area = areas->getElement();
            tiquetesEliminados += area->limpiarTiquetes();
		}

        userTypes->goToPos(selection - 1);
        delete userTypes->remove(); // Liberar la memoria del objeto eliminado
        cout << "Tipo de usuario eliminado.\n";
        cout << "Se han eliminado " << tiquetesEliminados << " tiquetes de las colas.\n";

    } while (selection < 1 || selection > userTypes->getSize() + 1);
}


// Funci�n para mostrar el men� de tipos de usuario
void showUserTypeMenu(List<TipoUsuario*>* tiposDeUsuarios, List<Area*>* areas) {
    Menu menu("== Menú de tipos de usuario ==");
    menu.addOption("Agregar");
    menu.addOption("Eliminar");
    menu.addOption("Listar");
    menu.addOption("Regresar");

    int option;
    do {
        menu.display();
        option = menu.getSelection();

        switch (option) {
        case 1: 
            addUserType(tiposDeUsuarios);
            break;
        case 2:
            displayAndRemoveUserType(tiposDeUsuarios, areas);  // Pasar la lista de tipos de usuario
            break;
        case 3:
            if (tiposDeUsuarios->getSize() == 0) {
				cout << "No hay tipos de usuario disponibles." << endl;
				pause();
				break;
			}
            cout << "== Tipos de usuario ==" << endl;
			for (int i = 0; i < tiposDeUsuarios->getSize(); i++) {
				tiposDeUsuarios->goToPos(i);
				cout << i + 1 << ". " << tiposDeUsuarios->getElement()->getDescripcion() << " - Prioridad: " << tiposDeUsuarios->getElement()->getPrioridad() << endl;
			}
			pause();
			break;
        case 4:
            return;
        }
    } while (option != 4);
}