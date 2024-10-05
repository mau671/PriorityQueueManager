/*
 * Archivo: main.cpp
 * Descripción: Este archivo contiene la implementación del menú principal y varios submenús
 *              de un sistema interactivo en consola. Los menús incluyen opciones para consultar
 *              el estado de colas, gestionar tiquetes, atender clientes, realizar tareas administrativas,
 *              y consultar estadísticas del sistema. Cada submenú permite navegar por opciones
 *              específicas según la funcionalidad seleccionada.
 *
 * Autor(es): Mauricio Gonzalez
 */

#include <iostream>
#include "Menu.h"
#include "UserTypeManager.h"
#include "TipoUsuario.h"
#include "OrderedArrayList.h"
#include "utils.h"

 // Inicializa la lista de tipos de usuario como una lista de punteros
void inicializateData(List<TipoUsuario*>*& userTypes) {
    userTypes = new OrderedArrayList<TipoUsuario*>();
}

void showQueueStatusMenu() {
	std::cout << "== Estado de las colas ==\n";
}

// Función para mostrar el submenú de tiquetes
void showTiquetesMenu() {
    Menu ticketMenu("== Menú de Tiquetes ==");
    ticketMenu.addOption("Seleccionar tipo de cliente y servicio");
    ticketMenu.addOption("Regresar");

    while (true) {
        ticketMenu.display();
        int choice = ticketMenu.getSelection();
        switch (choice) {
        case 1:
            std::cout << "Seleccionar tipo de cliente y servicio.\n";
            // Implementar lógica aquí
            break;
        case 2:
            return; // Salir de la función y destruir automáticamente ticketMenu
        }
    }
}

void showAtenderMenu() {
	std::cout << "Atender.\n";
	// Implementar lógica aquí
}

void showAdminMenu(List<TipoUsuario*>* userTypes) {
    Menu adminMenu("== Menú de Administración ==");
    adminMenu.addOption("Tipos de usuario");
    adminMenu.addOption("Áreas");
    adminMenu.addOption("Servicios disponibles");
    adminMenu.addOption("Limpiar colas y estadísticas");
    adminMenu.addOption("Regresar");

    while (true) {
        adminMenu.display();
        int choice = adminMenu.getSelection();
        switch (choice) {
        case 1:
            std::cout << "Tipos de usuario seleccionada.\n";
            showUserTypeMenu(userTypes); // Pasar la lista de tipos de usuario
            break;
        case 2:
            std::cout << "Áreas seleccionada.\n";
            // Implementar lógica aquí
            break;
        case 3:
            std::cout << "Servicios disponibles seleccionada.\n";
            // Implementar lógica aquí
            break;
        case 4:
            std::cout << "Limpiar colas y estadísticas seleccionada.\n";
            // Implementar lógica aquí
            break;
        case 5:
            return; // Salir de la función y destruir automáticamente adminMenu
        }
    }
}

void showSystemStatsMenu() {
	std::cout << "Estadísticas del sistema.\n";
	// Implementar lógica aquí
}

int main() {
    setlocale(LC_ALL, "spanish");

    // Inicializar la lista de tipos de usuario
    List<TipoUsuario*>* userTypes;
    inicializateData(userTypes);

    Menu mainMenu("== Menú Principal ==");
    mainMenu.addOption("Estado de las colas");
    mainMenu.addOption("Tiquetes");
    mainMenu.addOption("Atender");
    mainMenu.addOption("Administración");
    mainMenu.addOption("Estadísticas del sistema");
    mainMenu.addOption("Debug");
    mainMenu.addOption("Salir");

    while (true) {
        mainMenu.display();
        int choice = mainMenu.getSelection();
        switch (choice) {
        case 1:
            std::cout << "Estado de las colas seleccionada.\n";
            showQueueStatusMenu();
            break;
        case 2:
            std::cout << "Tiquetes seleccionada.\n";
            showTiquetesMenu();
            break;
        case 3:
            std::cout << "Atender seleccionada.\n";
            showAtenderMenu();
            break;
        case 4:
            std::cout << "Administración seleccionada.\n";
            showAdminMenu(userTypes);  // Pasar la lista de tipos de usuario
            break;
        case 5:
            std::cout << "Estadísticas del sistema seleccionada.\n";
            showSystemStatsMenu();
            break;
        case 6:
            // Hacer print de cada tipo de usuario en la lista
            for (int i = 0; i < userTypes->getSize(); i++) {
                userTypes->goToPos(i);
                std::cout << *(userTypes->getElement()) << std::endl; // Imprimir el objeto usando sobrecarga de <<
            }
            pause();
            break;
        case 7:
            std::cout << "Saliendo del programa...\n";
            // Liberar la memoria de todos los punteros en la lista
            for (int i = 0; i < userTypes->getSize(); i++) {
                userTypes->goToPos(i);
                delete userTypes->getElement(); // Eliminar el objeto apuntado
            }
            delete userTypes;  // Limpiar la lista al salir
            return 0;
        }
    }

    return 0;
}