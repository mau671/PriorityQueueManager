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

// Bibliotecas estándar
#include <iostream>

// UI
#include "UI/Menu.h"

// Gestores
#include "Gestores/GestorArea.h"
//#include "Gestores/GestorTiquete.h"
#include "Gestores/GestorTipoUsuario.h"
#include "Gestores/GestorServicio.h"

// Modelos
#include "Modelos/TipoUsuario.h"
#include "Modelos/Area.h"

// Estructuras de datos
#include "Estructuras/Concretas/OrderedArrayList.h"

// Utilidades
#include "Utilidades/utils.h"


 // Inicializa la lista de tipos de usuario como una lista de punteros
void inicializateDataUsuario(List<TipoUsuario*>*& userTypes) {
    userTypes = new OrderedArrayList<TipoUsuario*>();
}

void initializeDataArea(List<Area*>*& areas) {
    areas = new ArrayList<Area*>;
}

void showQueueStatusMenu() {
	std::cout << "== Estado de las colas ==\n";
    //Areas, cantidad de ventanillas por area, mostar ventanillas y su ultimo tiquete atendido, codigo de cada tiquete
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
            //std::cout << "Seleccionar tipo de cliente y servicio.\n\n";
            // Implementar lógica aquí
            
            
            pause();
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

void showAdminMenu(List<TipoUsuario*>* userTypes, List<Area*>* areas, OrderedArrayList<Servicio*>* servicios ) {
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
            pause();
            break;
        case 2:
            std::cout << "Áreas seleccionada.\n";
            showAreaMenu(areas, servicios);
            pause();
            break;
        case 3:
            std::cout << "Servicios disponibles seleccionada.\n";
            showServicioMenu(servicios, areas);
            pause();
            break;
        case 4:
            std::cout << "Limpiar colas y estadísticas seleccionada.\n";
            // Implementar lógica aquí
            pause();
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
    inicializateDataUsuario(userTypes);
    List<Area*>* areas;
    initializeDataArea(areas);
    OrderedArrayList<Servicio*>* servicios = new OrderedArrayList<Servicio*>();

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
            std::cout << "Estado de las colas seleccionada.\n\n";
            showQueueStatusMenu();
            pause();
            break;
        case 2:
            std::cout << "Tiquetes seleccionada.\n\n";
            showTiquetesMenu();
            pause();
            break;
        case 3:
            std::cout << "Atender seleccionada.\n\n";
            showAtenderMenu();
            pause();
            break;
        case 4:
            showAdminMenu(userTypes, areas, servicios);// Pasar la lista de tipos de usuario
            break;
        case 5:
            std::cout << "Estadísticas del sistema seleccionada.\n\n";
            showSystemStatsMenu();
            pause();
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
    delete areas;
    delete servicios;
    return 0;
}