/*
 * Archivo: utils.cpp
 * Descripci�n: Este archivo contiene funciones utilitarias generales para el sistema.
 *
 * Autor(es): Mauricio Gonzalez
 */

#include <cstdlib>
#include <iostream>
#include <string>

void clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

bool readConfirmation(const std::string& message) {
	std::string input;

	while (true) {
		std::cout << message << " (s/n): ";
		std::getline(std::cin, input);

		if (input == "s" || input == "S") {
			return true;
		} else if (input == "n" || input == "N") {
			return false;
		}
		std::cout << "Respuesta no v�lida. Intente nuevamente.\n";
	}
}

void pause() {
	std::cout << "Presione Enter para continuar...";
	std::cin.get();
}

int readInt(const std::string& message, const int& max ) {
    std::string input;
    int value;

    while (true) {
        std::cout << message;
        std::getline(std::cin, input);

        try {
            value = std::stoi(input);

            // Si max es mayor a 0, verifica que value sea positivo y que no exceda max
            // Si max es 0, solo verifica que value sea mayor a 0
            if (value > 0 && (max == 0 || value <= max)) {
                break;
            }
            else {
                std::cout << "Valor no v�lido. Intente nuevamente.\n";
            }
        }
        catch (std::invalid_argument&) {
            std::cout << "Valor no v�lido. Intente nuevamente.\n";
        }
    }

    return value;
}
