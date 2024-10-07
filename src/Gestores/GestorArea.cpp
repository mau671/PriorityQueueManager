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
void modifyAreaVentanillas(List<Area*>* areas) {
    /*
    string codigo;
    cout << "C�digo del �rea a modificar: ";
    std::getline(cin, codigo);
    
    Area* area = buscarAreaPorCodigo(areas, codigo);
    if (area == nullptr) {
        cout << "�rea no encontrada.\n";
        return;
    }
    
    int cantidadVentanillasActual = area->getNventanillas();
    cout << "Cantidad actual de ventanillas: " << cantidadVentanillasActual << "\n";
    int nuevaCantidad = readInt("Nueva cantidad de ventanillas: ");

    area->modificarVentanillas(nuevaCantidad);
    cout << "Cantidad de ventanillas modificada exitosamente.\n";
    */
}

// Funci�n para eliminar un �rea y sus ventanillas asociadas
void deleteArea(List<Area*>* areas) {
    if (areas->getSize() == 0) {
        cout << "No hay areas para eliminar." << endl;
        pause();
        return;
    }

    Menu menu("== Eliminar tipo de usuario ==");
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

// Funci�n para mostrar el men� de �reas
void showAreaMenu(List<Area*>* areas) {
    Menu menu("== Men� de �reas ==");
    menu.addOption("Agregar �rea"); 
    menu.addOption("Modificar Ventanillas");
    menu.addOption("Eliminar �rea");
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
            modifyAreaVentanillas(areas);
            break;
        case 3:
            deleteArea(areas);
            break;
        case 4:
            cout << "Regresando al men� de administraci�n...\n";
            break;
        default:
            cout << "Opci�n inv�lida. Intente de nuevo.\n";
        }
    } while (option != 4);
}