#include "Menu.h"
#include "utils.h"
#include <iostream>
#include <limits>
#include <sstream>

using std::cout;
using std::cin;
using std::string;

Menu::Menu(const string& title) : title(title) {}

void Menu::addOption(const string& option) {
    options.append(option); // Almacenar opciones usando ArrayList
}

void Menu::display() {
    clearConsole(); // Limpiar la consola
    cout << title << "\n";
    for (int i = 0; i < options.getSize(); i++) {
        options.goToPos(i); // Mover el cursor a la posici�n actual
        cout << i + 1 << ". " << options.getElement() << "\n"; // Mostrar opci�n
    }
    cout << "Seleccione una opci�n: ";
}

int Menu::getSelection() {
    string input;
    int selection = 0;

    while (true) {
        getline(cin, input); // Obtener la entrada del usuario

        std::stringstream ss(input);
        if (ss >> selection && selection >= 1 && selection <= options.getSize()) {
            break; // Opci�n v�lida, salir del bucle
        }

        cout << "Selecci�n no v�lida. Intente nuevamente: "; // Mensaje de error
    }

    return selection; // Retornar la selecci�n v�lida
}
