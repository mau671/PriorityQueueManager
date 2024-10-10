/*
 * Archivo: main.cpp
 * Descripción: Este archivo contiene la implementación del menú principal y varios submenús
 *              de un sistema interactivo en consola. Los menús incluyen opciones para consultar
 *              el estado de colas, gestionar tiquetes, atender clientes, realizar tareas administrativas,
 *              y consultar estadísticas del sistema. Cada submenú permite navegar por opciones
 *              específicas según la funcionalidad seleccionada.
 *
 * Autor(es): Mauricio Gonzalez, Lun Valverde
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


using std::cout;
using std::endl;

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

void showAtenderMenu(List<Area*>* areas) {
	std::cout << "Atender.\n";

    if (areas->getSize() == 0) {
        cout << "No hay areas disponibles" << endl;
        return;
    }
    Menu menu("Seleccione el area donde desea atender: ");
    for (int i = 0; i < areas->getSize(); i++) {
        areas->goToPos(i);
        menu.addOption(areas->getElement()->getDescripcion()); //descripcion de las areas
    }
    int selection;
    do {
        menu.display();
        selection = menu.getSelection();
        areas->goToPos(selection - 1);
        ArrayList<Ventanilla*>* ventanillas = areas->getElement()->getVentanillas();

        if (areas->getElement()->getSizeTiquetes() == 0) {
            cout << "No hay tiquetes pendientes en esta area" << endl;
            return;
        }
        
        Menu MenuVentanillas("Seleccione la ventanilla: ");
        for (int i = 0; i < ventanillas->getSize(); i++) {
            ventanillas->goToPos(i);
            MenuVentanillas.addOption(ventanillas->getElement()->getDescripcion()); //descripcion de las areas
        }
        int iventanilla;
        do {
            MenuVentanillas.display();
            cout << "Cantidad de tiquetes pendientes: " << ventanillas->getSize() << endl;
            iventanilla = MenuVentanillas.getSelection();//indice de la ventanilla
            ventanillas->goToPos(iventanilla);
            areas->getElement()->atenderTiquete(ventanillas->getElement()->getDescripcion());

            cout << "Se ha atendido el tiquete " << ventanillas->getElement()->getDescripcion()<< " exitosamente." << endl;
        } while (iventanilla<1 || iventanilla> areas->getSize() + 1);
    } while (selection < 1 || selection > areas->getSize() + 1);
}

void limpiarColasYEstadisticas(List<Area*>* areas, List<Servicio*>* servicios, List<TipoUsuario*>* tiposDeUsuarios) {

    int tiquetesEliminados = 0;

    // Limpiar colas de tiquetes de cada area
    for (int i = 0; i < areas->getSize(); i++) {
        areas->goToPos(i);
        Area* area = areas->getElement();
        tiquetesEliminados += area->limpiarTiquetes();
        area->setTiquetesDispensados(0);
    }

    // Limpiar tiquetes de cada servicio
    for (int i = 0; i < servicios->getSize(); i++) {
        servicios->goToPos(i);
        Servicio* servicio = servicios->getElement();
        servicio->setTiquetesSolicitados(0);
    }

    // Limpiar tiquetes de cada tipo de usuario
    for (int i = 0; i < tiposDeUsuarios->getSize(); i++) {
        tiposDeUsuarios->goToPos(i);
        TipoUsuario* tipoUsuario = tiposDeUsuarios->getElement();
        tipoUsuario->setTiquetesSolicitados(0);
    }

    // Mostrar un resumen de las colas limpiadas
    if (tiquetesEliminados > 0) {
        cout << "Se han eliminado " << tiquetesEliminados << " tiquetes de las colas." << endl;
    } else {
        cout << "No hay tiquetes para eliminar." << endl;
    }
    cout << "Se han reiniciado las estadísticas de tiquetes solicitados." << endl;
    pause();
}

void showAdminMenu(List<TipoUsuario*>* tiposDeUsuarios, List<Area*>* areas, List<Servicio*>* servicios, MinHeap<Tiquete*>* tiquetes) {
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
            showUserTypeMenu(tiposDeUsuarios); // Pasar la lista de tipos de usuario
            break;
        case 2:
            showAreaMenu(areas, servicios, tiquetes);
            break;
        case 3:
            showServicioMenu(servicios, areas,tiquetes);
            break;
        case 4:
            limpiarColasYEstadisticas(areas, servicios, tiposDeUsuarios);
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
            showAtenderMenu(areas);
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