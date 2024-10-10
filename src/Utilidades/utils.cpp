/*
 * Archivo: utils.cpp
 * Descripción: Este archivo contiene funciones utilitarias generales para el sistema.
 *
 * Autor(es): Mauricio Gonzalez
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <sstream>


using std::string;
using std::stringstream;
using std::setw;
using std::setfill;


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
                std::cout << "Valor no válido. Intente nuevamente.\n";
            }
        }
        catch (std::invalid_argument&) {
            std::cout << "Valor no válido. Intente nuevamente.\n";
        }
    }

    return value;
}

//Hora actual en formato HH:MM:SS
string obtenerHoraActual() {
    time_t t = time(nullptr);
    tm now;
    localtime_s(&now, &t);  // Usar localtime_s en lugar de localtime
    stringstream ss;
    ss << setw(2) << setfill('0') << now.tm_hour << ":"
        << setw(2) << setfill('0') << now.tm_min << ":"
        << setw(2) << setfill('0') << now.tm_sec;
    return ss.str();
}