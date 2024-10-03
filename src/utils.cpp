/*
 * Archivo: utils.cpp
 * Descripción: Este archivo contiene funciones utilitarias generales para el sistema.
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
		std::cout << "Respuesta no válida. Intente nuevamente.\n";
	}
}

void pause() {
	std::cout << "Presione Enter para continuar...";
	std::cin.get();
}

int readInt(const std::string& message) {
	std::string input;
	int value;

	while (true) {
		std::cout << message;
		std::getline(std::cin, input);

		try {
			value = std::stoi(input);
			break;
		} catch (std::invalid_argument&) {
			std::cout << "Valor no válido. Intente nuevamente.\n";
		}
	}

	return value;
}