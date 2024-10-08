/*
 * Archivo: GestorArea.cpp
 * Descripci�n: 
 *
 * Autor(es): Mauricio Gonzalez, Lun Valverde
 */

#include <iostream>
#include <string>
#include <stdexcept>
#include "UI/Menu.h"
#include "Estructuras/Concretas/ArrayList.h"
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
    string descripcion;
    string codigo;
    int cantVentanillas;

    cout << "Descripci�n/nombre del �rea: ";
    std::getline(cin, descripcion);
    cout << "C�digo del �rea: ";
    std::getline(cin, codigo);
    cout << "Cantidad de ventanillas: ";
    cin >> cantVentanillas;

    Area* nuevaArea = new Area(descripcion, codigo, cantVentanillas);
    areas->append(nuevaArea);

    cout << "�rea agregada exitosamente.\n";
    areas->print();
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
        
        int nVentanillas;
        nVentanillas = menu.getSelection();

        areas->goToPos(selection - 1);
        areas->getElement()->setNventanillas(nVentanillas);
        
        cout << "Ventanillas modificadas.\n";
        areas->remove();
    } while (selection < 1 || selection > areas->getSize() + 1);
    
}

// Funci�n para eliminar un �rea y sus ventanillas asociadas
void deleteArea(List<Area*>* areas) {
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
            cout << "Operaci�n cancelada.\n";
            return;
        }

        areas->goToPos(selection - 1);
        delete areas->getElement(); // Liberar la memoria del objeto eliminado
        cout << "Tipo de usuario eliminado.\n";
        areas->remove();
    } while (selection < 1 || selection > areas->getSize() + 1);
    
    

    // Eliminar el �rea de la lista y liberar la memoria
    
   
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
void showAreaMenu(List<Area*>* areas) {
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
            deleteArea(areas);
            break;
        case 4:
            displayInfoArea(areas);
            break;
        case 5:
            cout << "Regresando al men� de administraci�n...\n";
            break;
        default:
            cout << "Opci�n inv�lida. Intente de nuevo.\n";
        }
    } while (option != 5);
}