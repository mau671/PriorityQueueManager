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

using std::cout;
using std::endl;
using std::cin;
using std::string;

// Funci�n para agregar una nueva �rea
void addArea(List<Area*>* areas) {
    string descripcion;
    string codigo;
    int cantidadVentanillas;

    cout << "Descripci�n del �rea: ";
    std::getline(cin, descripcion);
    cout << "C�digo del �rea: ";
    std::getline(cin, codigo);
    cantidadVentanillas = readInt("Cantidad de ventanillas: ");

    Area* nuevaArea = new Area(descripcion, codigo, cantidadVentanillas);
    areas->append(nuevaArea);

    cout << "�rea agregada exitosamente.\n";
}

// Funci�n para modificar la cantidad de ventanillas de un �rea existente
void modifyAreaVentanillas(List<Area*>* areas) {
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
}

// Funci�n para eliminar un �rea y sus ventanillas asociadas
void deleteArea(List<Area*>* areas) {
    string codigo;
    cout << "C�digo del �rea a eliminar: ";
    std::getline(cin, codigo);

    Area* area = buscarAreaPorCodigo(areas, codigo);
    if (area == nullptr) {
        cout << "�rea no encontrada.\n";
        return;
    }

    cout << "Servicios relacionados a este �rea:\n";
    area->mostrarServicios();  // Mostrar servicios que ser�an eliminados

    if (!readConfirmation("�Desea continuar y eliminar el �rea? (s/n)")) {
        cout << "Operaci�n cancelada.\n";
        return;
    }

    // Eliminar el �rea de la lista y liberar la memoria
    for (int i = 0; i < areas->getSize(); i++) {
        areas->goToPos(i);
        if (areas->getElement()->getCodigo() == codigo) {
            delete areas->getElement();
            areas->remove();
            cout << "�rea eliminada exitosamente.\n";
            return;
        }
    }
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

// Funci�n auxiliar para buscar un �rea por su c�digo
Area* buscarAreaPorCodigo(List<Area*>* areas, const string& codigo) {
    for (int i = 0; i < areas->getSize(); i++) {
        areas->goToPos(i);
        if (areas->getElement()->getCodigo() == codigo) {
            return areas->getElement();
        }
    }
    return nullptr;
}
