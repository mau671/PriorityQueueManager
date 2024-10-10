/*
 * Archivo: GestorArea.cpp
 * Descripción: 
 *
 * Autor(es): Mauricio Gonzalez, Lun Valverde
 */

#include <iostream>
#include <string>
#include <stdexcept>
#include "UI/Menu.h"
#include "Estructuras/Abstractas/List.h"
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
    string descripcion;
    string codigo;
    int cantVentanillas;

    cout << "Descripción/nombre del área: ";
    std::getline(cin, descripcion);
    cout << "Código del área: ";
    std::getline(cin, codigo);
    cantVentanillas = readInt("Cantidad de ventanillas: ");
    Area* nuevaArea = new Area(descripcion, codigo, cantVentanillas);
    areas->append(nuevaArea);

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

        //agregar confirmacion
        
        int nVentanillas;
        nVentanillas = menu.getSelection();

        areas->goToPos(selection - 1);
        areas->getElement()->setNventanillas(nVentanillas);
        
        cout << "Ventanillas modificadas.\n";
    } while (selection < 1 || selection > areas->getSize() + 1);
    
}

// Función para eliminar un área y sus ventanillas asociadas
void deleteArea(List<Area*>* areas, List<Servicio*>* servicios, MinHeap<Tiquete*>* tiquetes) {
    if (areas->getSize() == 0) {
        cout << "No hay areas para eliminar." << endl;
        pause();
        return;
    }

    Menu menu("== Eliminar area ==");
    for (int i = 0; i < areas->getSize(); i++) {
        areas->goToPos(i);
        menu.addOption(areas->getElement()->getDescripcion()); //descripcion de las areas
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
            cout << "Esta area no tiene servicios asociados." << endl;
        }
        else {
            cout << "Servicios que se eliminaran: " << endl;
            for (int i = 0; i < servicios->getSize(); i++) {
                servicios->goToPos(i);
                cout << i + 1 << " . " << servicios->getElement()->getDescripcion();
            }
            cout << endl;
        }

        bool input = readConfirmation("Esta seguro de que desea continuar?");
        if (input == false) {
            cout << "Operacion cancelada";
            pause();
            return;
        }


        areas->goToPos(selection - 1);//va al area seeccionada
        if (tiquetes->isEmpty()) {
            for (int i = servicios->getSize() - 1; i >= 0; i--) {//va uno por uno en la lista de servicios
                servicios->goToPos(i);
                delete servicios->remove();
            }
        }
        else {
            for (int i = servicios->getSize() - 1; i >= 0; i--) {//va uno por uno en la lista de servicios
                servicios->goToPos(i);
                if (servicios->getElement()->getArea() == areas->getElement()) {//si el area del servicio coincide con el area seleccionada, se elimina
                    for (int e = tiquetes->getSize() - 1; e >= 0; e--) {//cuando se encuentra un area, se busca en la cola los tiquetes con esa area
                        if (tiquetes->get(i)->getServicio() == servicios->getElement()) delete tiquetes->remove(e);//se elimina el tiquete si tiene el servicio
                    }
                    delete servicios->remove();
                }
            }
        }
        delete areas->getElement(); // Liberar la memoria del objeto eliminado
        cout << "Area eliminada exitosamente.\n";
        areas->remove();

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
void showAreaMenu(List<Area*>* areas, List<Servicio*>* servicios, MinHeap<Tiquete*>* tiquetes) {
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
            deleteArea(areas, servicios, tiquetes);
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