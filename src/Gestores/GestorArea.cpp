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

using std::cout;
using std::endl;
using std::cin;
using std::string;

// Función para agregar una nueva área
void addArea(List<Area*>* areas) {
    string descripcion;
    string codigo;
    int cantidadVentanillas;

    cout << "Descripción del área: ";
    std::getline(cin, descripcion);
    cout << "Código del área: ";
    std::getline(cin, codigo);
    cantidadVentanillas = readInt("Cantidad de ventanillas: ");

    Area* nuevaArea = new Area(descripcion, codigo, cantidadVentanillas);
    areas->append(nuevaArea);

    cout << "Área agregada exitosamente.\n";
}

// Función para modificar la cantidad de ventanillas de un área existente
void modifyAreaVentanillas(List<Area*>* areas) {
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
}

// Función para eliminar un área y sus ventanillas asociadas
void deleteArea(List<Area*>* areas) {
    string codigo;
    cout << "Código del área a eliminar: ";
    std::getline(cin, codigo);

    Area* area = buscarAreaPorCodigo(areas, codigo);
    if (area == nullptr) {
        cout << "Área no encontrada.\n";
        return;
    }

    cout << "Servicios relacionados a este área:\n";
    area->mostrarServicios();  // Mostrar servicios que serían eliminados

    if (!readConfirmation("¿Desea continuar y eliminar el área? (s/n)")) {
        cout << "Operación cancelada.\n";
        return;
    }

    // Eliminar el área de la lista y liberar la memoria
    for (int i = 0; i < areas->getSize(); i++) {
        areas->goToPos(i);
        if (areas->getElement()->getCodigo() == codigo) {
            delete areas->getElement();
            areas->remove();
            cout << "Área eliminada exitosamente.\n";
            return;
        }
    }
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

// Función auxiliar para buscar un área por su código
Area* buscarAreaPorCodigo(List<Area*>* areas, const string& codigo) {
    for (int i = 0; i < areas->getSize(); i++) {
        areas->goToPos(i);
        if (areas->getElement()->getCodigo() == codigo) {
            return areas->getElement();
        }
    }
    return nullptr;
}
