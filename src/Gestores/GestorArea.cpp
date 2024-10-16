/*
 * Archivo: GestorArea.cpp
 * Descripci�n: Declaraciones de funciones para gestionar las �reas del sistema.
 *              Las funcionalidades incluyen agregar, modificar las ventanillas, eliminar �reas y mostrar el men� de �reas.
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

// Funci�n para agregar una nueva �rea
void addArea(List<Area*>* areas) {
    string descripcion = readString("Descripci�n/nombre del �rea: ");

    for (int i = 0; i < areas->getSize(); i++) {
        areas->goToPos(i);
        if (areas->getElement()->getDescripcion() == descripcion) { //se asegura de que el area no exista todav�a
            cout << "Area ya existente." << endl;
            pause();
            return;
        }
    }
    string codigo = readString("C�digo del �rea: ");
    int cantVentanillas = readInt("Cantidad de ventanillas: ");
    Area* nuevaArea = new Area(descripcion, codigo, cantVentanillas);//crear la nueva area con la informacion recibida

    areas->append(nuevaArea);//agregar el area a la lista de areas
    cout << "�rea agregada exitosamente.\n";
    pause();
}

// Funci�n para modificar la cantidad de ventanillas de un �rea existente
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
            cout << "Operaci�n cancelada.\n";
            return;
        }

        int nVentanillas;
        nVentanillas = readInt("Cantidad de ventanillas: ");

        areas->goToPos(selection - 1);
        areas->getElement()->setNventanillas(nVentanillas);//se modifican las ventanas
        
        cout << "Ventanillas modificadas.\n";
    } while (selection < 1 || selection > areas->getSize() + 1);
    
}

// Funci�n para eliminar un �rea y sus ventanillas asociadas
void deleteArea(List<Area*>* areas, List<Servicio*>* servicios) {
    if (areas->getSize() == 0) {
        cout << "No hay �reas para eliminar." << endl;
        pause();
        return;
    }

    Menu menu("== Eliminar �rea ==");
    for (int i = 0; i < areas->getSize(); i++) {
        areas->goToPos(i);
        menu.addOption(areas->getElement()->getDescripcion()); // descripci�n de las �reas
    }
    menu.addOption("Cancelar");

    int selection;
    do {
        menu.display();
        selection = menu.getSelection();

        if (selection == areas->getSize() + 1) {
            cout << "Operaci�n cancelada.\n";
            return;
        }

        if (servicios->getSize() == 0) {
            cout << "Esta �rea no tiene servicios asociados." << endl;
        }
        else {
            cout << "Servicios que se eliminar�n: " << endl;
            for (int i = 0; i < servicios->getSize(); i++) {
				servicios->goToPos(i);
                if (servicios->getElement()->getArea() == areas->getElement()) {
                    cout << servicios->getElement()->getDescripcion() << endl;
                }
            }
            cout << endl;
        }

        bool input = readConfirmation("�Est� seguro de que desea continuar?");
        if (!input) {
            cout << "Operaci�n cancelada.";
            pause();
            return;
        }

        areas->goToPos(selection - 1); // va al �rea seleccionada
        Area* areaSeleccionada = areas->getElement();

        // Eliminar servicios asociados al �rea seleccionada
        for (int i = servicios->getSize() - 1; i >= 0; i--) {
            servicios->goToPos(i);
            if (servicios->getElement()->getArea() == areaSeleccionada) {
                delete servicios->remove(); // Eliminar el servicio asociado al �rea
            }
        }

        // Obt�n los tiquetes asociados al �rea usando el m�todo getTiquetes()
        HeapPriorityQueue<Tiquete*>* tiquetesArea = areaSeleccionada->getTiquetes();

        // Elimina los tiquetes asociados al �rea
        if (tiquetesArea != nullptr) {
            while (!tiquetesArea->isEmpty()) {
                delete tiquetesArea->removeMin();
            }
        }

        delete areas->remove(); // Eliminar el �rea de la lista de �reas
        cout << "�rea eliminada exitosamente.\n";
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
    Menu menu("== Mostrar Informaci�n ==");
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
            cout << "Operaci�n cancelada.\n";
            return;
        }

        areas->goToPos(selection - 1);
        areas->getElement()->consultarInfo();

        pause();
    } while (selection < 1 || selection > areas->getSize() + 1);

}

// Funci�n para mostrar el men� de �reas
void showAreaMenu(List<Area*>* areas, List<Servicio*>* servicios) {
    Menu menu("== Men� de �reas ==");
    menu.addOption("Agregar �rea"); 
    menu.addOption("Modificar Ventanillas");
    menu.addOption("Eliminar �rea");
    menu.addOption("Mostrar Informaci�n");
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
            cout << "Opci�n inv�lida. Intente de nuevo.\n";
        }
    } while (option != 5);
}