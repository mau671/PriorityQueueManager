/*
 * Archivo: Menu.cpp
 * Descripción: Este archivo contiene la implementación de la clase Menu,
 *              que permite gestionar menús interactivos en consola.
 *              Las funcionalidades incluyen agregar opciones al menú,
 *              mostrar el menú en pantalla, y capturar la selección del usuario.
 *              La clase utiliza estructuras de datos para almacenar y acceder a las opciones.
 *
 * Autor(es): Mauricio Gonzalez
 */

#include <iostream>
#include <limits>
#include <sstream>
#include "UI/Menu.h"
#include "Utilidades/utils.h"

using std::cout;
using std::cin;
using std::string;

Menu::Menu(const string& title) : title(title) {}

void Menu::addOption(const string& option) {
    options.append(option); // Almacenar opciones usando ArrayList
}

void Menu::display(const string& message) {
    clearConsole(); // Limpiar la consola
    cout << title << "\n";
    for (int i = 0; i < options.getSize(); i++) {
        options.goToPos(i); // Mover el cursor a la posición actual
        cout << i + 1 << ". " << options.getElement() << "\n"; // Mostrar opción
    }
    cout << message; // Mostrar mensaje de selección
}

int Menu::getSelection() {
    string input;
    int selection = 0;

    while (true) {
        getline(cin, input); // Obtener la entrada del usuario

        std::stringstream ss(input);
        if (ss >> selection && selection >= 1 && selection <= options.getSize()) {
            break; // Opción válida, salir del bucle
        }

        cout << "Selección no válida. Intente nuevamente: "; // Mensaje de error
    }

    return selection; // Retornar la selección válida
}
