/*
 * Archivo: GestorArea.cpp
 * Descripción: Declaraciones de funciones para gestionar las áreas del sistema.
 *              Las funcionalidades incluyen agregar, modificar las ventanillas, eliminar áreas y mostrar el menú de áreas.
 *
 * Autor(es): Mauricio Gonzalez, Lun Valverde
 */

#include <iostream>
#include <string>
#include <stdexcept>
#include "UI/Menu.h"
#include "Estructuras/Abstractas/List.h"
#include "Estructuras/Concretas/MinHeap.h"
#include "Modelos/Area.h"
#include "Utilidades/utils.h"
#include "Modelos/Servicio.h"
#include "Modelos/Ventanilla.h"
#include "Modelos/Tiquete.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;

// Función para agregar una nueva área
void addArea(List<Area*>* areas) {
    string descripcion = readString("Descripción/nombre del área: ");

    for (int i = 0; i < areas->getSize(); i++) {
        areas->goToPos(i);
        if (areas->getElement()->getDescripcion() == descripcion) { //se asegura de que el area no exista todavía
            cout << "Area ya existente." << endl;
            pause();
            return;
        }
    }
    string codigo = readString("Código del área: ");
    int cantVentanillas = readInt("Cantidad de ventanillas: ");
    Area* nuevaArea = new Area(descripcion, codigo, cantVentanillas);//crear la nueva area con la informacion recibida

    areas->append(nuevaArea);//agregar el area a la lista de areas
    cout << "Área agregada exitosamente.\n";
    pause();
}

// Función para modificar la cantidad de ventanillas de un área existente
void modifyVentanillas(List<Area*>* areas) {
    if (areas->getSize() == 0) {
        cout << "No hay areas para modificar." << endl;
        pause();
        return;
    }
    Menu menu("== Modificar ventanillas ==");
    for (int i = 0; i < areas->getSize(); i++) {//agregar cada area a la lista de opciones
        areas->goToPos(i);
        menu.addOption(areas->getElement()->getDescripcion());
    }
    menu.addOption("Cancelar");

    int selection;
    do {
        menu.display();
        selection = menu.getSelection();

        if (selection == areas->getSize() + 1) {
            cout << "Operación cancelada.\n";
            return;
        }

        int nVentanillas;
        nVentanillas = readInt("Cantidad de ventanillas: ");

        areas->goToPos(selection - 1);
        areas->getElement()->setNventanillas(nVentanillas);//se modifican las ventanas
        
        cout << "Ventanillas modificadas.\n";
    } while (selection < 1 || selection > areas->getSize() + 1);
    
}

// Función para eliminar un área y sus ventanillas asociadas
void deleteArea(List<Area*>* areas, List<Servicio*>* servicios) {
    if (areas->getSize() == 0) {
        cout << "No hay áreas para eliminar." << endl;
        pause();
        return;
    }

    Menu menu("== Eliminar área ==");
    for (int i = 0; i < areas->getSize(); i++) {
        areas->goToPos(i);
        menu.addOption(areas->getElement()->getDescripcion()); // descripción de las áreas
    }
    menu.addOption("Cancelar");

    int selection;
    do {
        menu.display();
        selection = menu.getSelection();

        if (selection == areas->getSize() + 1) {
            cout << "Operación cancelada.\n";
            return;
        }

        if (servicios->getSize() == 0) {
            cout << "Esta área no tiene servicios asociados." << endl;
        }
        else {
            cout << "Servicios que se eliminarán: " << endl;
            for (int i = 0; i < servicios->getSize(); i++) {
				servicios->goToPos(i);
                if (servicios->getElement()->getArea() == areas->getElement()) {
                    cout << servicios->getElement()->getDescripcion() << endl;
                }
            }
            cout << endl;
        }

        bool input = readConfirmation("¿Está seguro de que desea continuar?");
        if (!input) {
            cout << "Operación cancelada.";
            pause();
            return;
        }

        areas->goToPos(selection - 1); // va al área seleccionada
        Area* areaSeleccionada = areas->getElement();

        // Eliminar servicios asociados al área seleccionada
        for (int i = servicios->getSize() - 1; i >= 0; i--) {
            servicios->goToPos(i);
            if (servicios->getElement()->getArea() == areaSeleccionada) {
                delete servicios->remove(); // Eliminar el servicio asociado al área
            }
        }

        // Obtén los tiquetes asociados al área usando el método getTiquetes()
        HeapPriorityQueue<Tiquete*>* tiquetesArea = areaSeleccionada->getTiquetes();

        // Elimina los tiquetes asociados al área
        if (tiquetesArea != nullptr) {
            while (!tiquetesArea->isEmpty()) {
                delete tiquetesArea->removeMin();
            }
        }

        delete areas->remove(); // Eliminar el área de la lista de áreas
        cout << "Área eliminada exitosamente.\n";
        pause();

    } while (selection < 1 || selection > areas->getSize() + 1);
}

//funcion para mostrar la informacion del area
void displayInfoArea(List<Area*>* areas) {
    if (areas->getSize() == 0) {
        cout << "No hay areas disponibles." << endl;
        pause();
        return;
    }
    Menu menu("== Mostrar Información ==");
    for (int i = 0; i < areas->getSize(); i++) {
        areas->goToPos(i);
        menu.addOption(areas->getElement()->getDescripcion());
    }
    menu.addOption("Cancelar");

    int selection;
    do {
        menu.display();
        selection = menu.getSelection();

        if (selection == areas->getSize() + 1) {
            cout << "Operación cancelada.\n";
            return;
        }

        areas->goToPos(selection - 1);
        areas->getElement()->consultarInfo();

        pause();
    } while (selection < 1 || selection > areas->getSize() + 1);

}

// Función para mostrar el menú de áreas
void showAreaMenu(List<Area*>* areas, List<Servicio*>* servicios) {
    Menu menu("== Menú de Áreas ==");
    menu.addOption("Agregar Área"); 
    menu.addOption("Modificar Ventanillas");
    menu.addOption("Eliminar Área");
    menu.addOption("Mostrar Información");
    menu.addOption("Regresar");

    int option;
    do {
        menu.display();
        option = menu.getSelection();

        switch (option) {
        case 1:
            addArea(areas);
            break;
        case 2:
            modifyVentanillas(areas);
            break;
        case 3:
            deleteArea(areas, servicios);
            break;
        case 4:
            displayInfoArea(areas);
            break;
        case 5:
            return;
        default:
            cout << "Opción inválida. Intente de nuevo.\n";
        }
    } while (option != 5);
}