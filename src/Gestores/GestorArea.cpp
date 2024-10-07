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

// Función para agregar una nueva área

void addArea(List<Area*>* areas) {
    string descripcion;
    string codigo;
    int cantVentanillas;

    cout << "Descripción/nombre del área: ";
    std::getline(cin, descripcion);
    cout << "Código del área: ";
    std::getline(cin, codigo);
    cout << "Cantidad de ventanillas: ";
    cin >> cantVentanillas;

    Area* nuevaArea = new Area(descripcion, codigo, cantVentanillas);
    areas->append(nuevaArea);

    cout << "Área agregada exitosamente.\n";
    areas->print();
    pause();
}

// Función para modificar la cantidad de ventanillas de un área existente
void modifyAreaVentanillas(List<Area*>* areas) {
    /*
    string codigo;
    cout << "Código del área a modificar: ";
    std::getline(cin, codigo);
    
    Area* area = buscarAreaPorCodigo(areas, codigo);
    if (area == nullptr) {
        cout << "Área no encontrada.\n";
        return;
    }
    
    int cantidadVentanillasActual = area->getNventanillas();
    cout << "Cantidad actual de ventanillas: " << cantidadVentanillasActual << "\n";
    int nuevaCantidad = readInt("Nueva cantidad de ventanillas: ");

    area->modificarVentanillas(nuevaCantidad);
    cout << "Cantidad de ventanillas modificada exitosamente.\n";
    */
}

// Función para eliminar un área y sus ventanillas asociadas
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
            cout << "Operación cancelada.\n";
            return;
        }

        areas->goToPos(selection - 1);
        delete areas->getElement(); // Liberar la memoria del objeto eliminado
        cout << "Tipo de usuario eliminado.\n";
        areas->remove();
    } while (selection < 1 || selection > areas->getSize() + 1);
    
    

    // Eliminar el área de la lista y liberar la memoria
    
   
}

// Función para mostrar el menú de áreas
void showAreaMenu(List<Area*>* areas) {
    Menu menu("== Menú de Áreas ==");
    menu.addOption("Agregar Área"); 
    menu.addOption("Modificar Ventanillas");
    menu.addOption("Eliminar Área");
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
            cout << "Regresando al menú de administración...\n";
            break;
        default:
            cout << "Opción inválida. Intente de nuevo.\n";
        }
    } while (option != 4);
}