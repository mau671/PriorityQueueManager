﻿/*
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
#include "Gestores/GestorTiquete.h"
#include "Gestores/GestorTipoUsuario.h"
#include "Gestores/GestorServicio.h"

// Modelos
#include "Modelos/TipoUsuario.h"
#include "Modelos/Area.h"
#include "Modelos/Servicio.h"
#include "Modelos/Tiquete.h"

// Estructuras de datos
#include "Estructuras/Concretas/OrderedArrayList.h"

// Utilidades
#include "Utilidades/utils.h"


void showQueueStatusMenu() {
	std::cout << "== Estado de las colas ==\n";
    //Areas, cantidad de ventanillas por area, mostar ventanillas y su ultimo tiquete atendido, codigo de cada tiquete
}

// Función para mostrar el submenú de tiquetes

void showTiquetesMenu(MinHeap<Tiquete*>* tiquetes, List<TipoUsuario*>* usuarios, List<Servicio*>* servicios) {
    Menu ticketMenu("== Menú de Tiquetes ==");
    ticketMenu.addOption("Seleccionar tipo de cliente y servicio");
    ticketMenu.addOption("Regresar");

    while (true) {
        ticketMenu.display();
        int choice = ticketMenu.getSelection();
        switch (choice) {
        case 1:
            addTiquete(tiquetes, usuarios, servicios);
            break;
        case 2:
            return; // Salir de la función y destruir automáticamente ticketMenu
        }
    }
}

void showAtenderMenu() {
	std::cout << "Atender.\n";
    Menu adminMenu("Area donde se atiende el tiquete");
    adminMenu.addOption("Tipos de usuario");
    adminMenu.addOption("Áreas");
    adminMenu.addOption("Servicios disponibles");
    adminMenu.addOption("Limpiar colas y estadísticas");
    adminMenu.addOption("Regresar");

    while (true) {
        adminMenu.display();
        int choice = adminMenu.getSelection();

    }
}

void showAdminMenu(List<TipoUsuario*>* userTypes, List<Area*>* areas, List<Servicio*>* servicios, MinHeap<Tiquete*>* tiquetes) {
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
            showAreaMenu(areas, servicios, tiquetes);
            break;
        case 3:
            std::cout << "Servicios disponibles seleccionada.\n";
            showServicioMenu(servicios, areas,tiquetes);
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
    List<TipoUsuario*>* tiposDeUsuarios = new OrderedArrayList<TipoUsuario*>();  // Crear OrderedArrayList para tipos de usuario
    List<Area*>* areas = new ArrayList<Area*>();                          // Crear ArrayList para áreas
    List<Servicio*>* servicios = new ArrayList<Servicio*>();
    MinHeap<Tiquete*>* tiquetes = new MinHeap<Tiquete*>(100); // Crear MinHeap para tiquetes

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
            showTiquetesMenu(tiquetes, tiposDeUsuarios, servicios);
            pause();
            break;
        case 3:
            std::cout << "Atender seleccionada.\n\n";
            showAtenderMenu();
            pause();
            break;
        case 4:
            showAdminMenu(tiposDeUsuarios, areas, servicios, tiquetes);// Pasar la lista de tipos de usuario
            break;
        case 5:
            std::cout << "Estadísticas del sistema seleccionada.\n\n";
            showSystemStatsMenu();
            pause();
            break;
        case 6:
            // Hacer print de cada tipo de usuario en la lista

            cout << "Tipos de usuario:\n";
            for (int i = 0; i < tiposDeUsuarios->getSize(); i++) {
                tiposDeUsuarios->goToPos(i);
                std::cout << *(tiposDeUsuarios->getElement()) << std::endl; // Imprimir el objeto usando sobrecarga de <<
            }

            cout << "Areas:\n";
            // imprimir areas
            for (int i = 0; i < areas->getSize(); i++) {
				areas->goToPos(i);
				std::cout << *(areas->getElement()) << std::endl; // Imprimir el objeto usando sobrecarga de <<
			}

            cout << "Servicios:\n";

            // imprimir servicios
            for (int i = 0; i < servicios->getSize(); i++) {
                servicios->goToPos(i);
                std::cout << *(servicios->getElement()) << std::endl; // Imprimir el objeto usando sobrecarga de <<
            }

            pause();
            break;
        case 7:
            std::cout << "Saliendo del programa...\n";
            // Liberar la memoria de todos los punteros en la lista
            for (int i = 0; i < tiposDeUsuarios->getSize(); i++) {
                tiposDeUsuarios->goToPos(i);
                delete tiposDeUsuarios->getElement(); // Eliminar el objeto apuntado
            }
            delete tiposDeUsuarios;  // Limpiar la lista al salir
            delete areas;
            delete servicios;
            delete tiquetes;
            return 0;
        }
    }
    return 0;
}