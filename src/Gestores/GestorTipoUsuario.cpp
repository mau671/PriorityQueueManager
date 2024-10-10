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

using std::cout;
using std::endl;
using std::cin;
using std::string;

// Funci�n para agregar un nuevo tipo de usuario
void addUserType(List<TipoUsuario*>* tiposDeUsuarios) {
    string description = readString("Descripción del tipo de usuario: ");
    int prioridad = readInt("Prioridad del tipo de usuario: ");


    tiposDeUsuarios->insert(new TipoUsuario(description, prioridad));
    cout << "Tipo de usuario '" << description << "' con prioridad " << prioridad << " agregado exitosamente.\n";
    pause();
}


// Funci�n para mostrar todos los tipos de usuario y eliminar el seleccionado
void displayAndRemoveUserType(List<TipoUsuario*>* userTypes) {
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

        userTypes->goToPos(selection - 1);
        delete userTypes->getElement(); // Liberar la memoria del objeto eliminado
        cout << "Tipo de usuario eliminado.\n";
        userTypes->remove();

    } while (selection < 1 || selection > userTypes->getSize() + 1);
}


// Funci�n para mostrar el men� de tipos de usuario
void showUserTypeMenu(List<TipoUsuario*>* tiposDeUsuarios) {
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
            addUserType(tiposDeUsuarios);
            break;
        case 2:
            displayAndRemoveUserType(tiposDeUsuarios);  // Pasar la lista de tipos de usuario
            break;
        case 3:
            return;
        }
    } while (option != 3);
}