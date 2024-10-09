/*
 * Archivo: GestorServicio.cpp
 * Descripción:
 *
 * Autor(es): Lun Valverde
 */

#include <iostream>
#include <string>
#include <stdexcept>
#include "UI/Menu.h"
#include "Estructuras/Concretas/ArrayList.h"
#include "Estructuras/Abstractas/List.h"
#include "Modelos/Area.h"
#include "Utilidades/utils.h"
#include "Modelos/Servicio.h"
#include "Modelos/Ventanilla.h"
#include "Modelos/Tiquete.h"

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::to_string;
using std::stringstream;


void addServicio(List<Servicio*>* servicios, List<Area*>* areas) {
    string descripcion;
    int prioridad;
    Area* area = nullptr;

    if (areas->getSize() == 0) {
        cout << "No hay areas disponibles" << endl;
        pause();
        return;
    }
    Menu menu("Seleccione el area: ");
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
        Area* area = areas->getElement();
        cout << "Descripción/nombre del servicio: ";
        std::getline(cin, descripcion);
        cout << "Prioridad del servicio: ";
        cin >> prioridad;
        if (prioridad < 0) {
            cout << "Prioridad inválida. Debe ser un número positivo.\n";
            return;
        }
        Servicio* servicio = new Servicio(descripcion, prioridad, area);
        servicios->insert(servicio);

        cout << "Servicio agregado exitosamente.\n";
        pause();
   
    } while (selection < 1 || selection > servicios->getSize() + 1);
}

void delServicio(List<Servicio*>* servicios) {
    if (servicios->getSize() == 0) {
        cout << "No hay servicios disponibles." << endl;
        pause();
        return;
    }
    Menu menu("== Eliminar servicio ==");
    
    for (int i = 0; i < servicios->getSize(); i++) {
        servicios->goToPos(i);
        menu.addOption(servicios->getElement()->getDescripcion());
    }
    menu.addOption("Cancelar");

    int selection;
    do {
        menu.display();
        selection = menu.getSelection();

        if (selection == servicios->getSize() + 1) {
            cout << "Operación cancelada.\n";
            return;
        }

        servicios->goToPos(selection - 1);
        delete servicios->getElement(); // Liberar la memoria del objeto eliminado
        cout << "Servicio eliminado eliminado.\n";
        servicios->remove();
        pause();
    } while (selection < 1 || selection > servicios->getSize() + 1);
}

void reordenarServicios(List<Servicio*>* servicios) {
    if (servicios->getSize() == 0) {
        cout << "No hay servicios para reordenar." << endl;
        pause();
        return;
    }

    // Mostrar el orden actual de los servicios
    cout << "Orden actual:\n";
    for (int i = 0; i < servicios->getSize(); i++) {
        servicios->goToPos(i);
        cout << i + 1 << ". " << servicios->getElement()->getDescripcion() << endl;
    }

    // Solicitar el nuevo orden al usuario
    cout << "Ingrese el nuevo orden (separado por comas, por ejemplo: 3,1,2): ";
    string nuevoOrden;
    cin.ignore();  // Limpiar cualquier entrada previa en el buffer
    std::getline(cin, nuevoOrden);

    // Procesar el input y convertirlo en una lista de índices (sin usar std::getline con delimitador)
    int numServicios = servicios->getSize();
    int* nuevoOrdenIndices = new int[numServicios];  // Crear un array para almacenar los nuevos índices
    int count = 0;
    size_t start = 0;
    size_t end = nuevoOrden.find(',');

    while (end != string::npos) {
        // Convertir el substring entre comas a entero
        int index = std::stoi(nuevoOrden.substr(start, end - start)) - 1;
        if (index >= 0 && index < numServicios) {
            nuevoOrdenIndices[count++] = index;
        }
        else {
            cout << "Índice fuera de rango. Operación cancelada.\n";
            delete[] nuevoOrdenIndices;  // Liberar memoria
            pause();
            return;
        }
        // Mover al siguiente token
        start = end + 1;
        end = nuevoOrden.find(',', start);
    }

    // Procesar el último token
    int index = std::stoi(nuevoOrden.substr(start)) - 1;
    if (index >= 0 && index < numServicios) {
        nuevoOrdenIndices[count++] = index;
    }
    else {
        cout << "Índice fuera de rango. Operación cancelada.\n";
        delete[] nuevoOrdenIndices;  // Liberar memoria
        pause();
        return;
    }

    // Verificación de la cantidad de elementos
    if (count != numServicios) {
        cout << "El número de elementos ingresados no coincide con la cantidad de servicios. Operación cancelada.\n";
        delete[] nuevoOrdenIndices;  // Liberar memoria
        pause();
        return;
    }

    // Crear un nuevo ArrayList temporal para almacenar los servicios en el nuevo orden
    ArrayList<Servicio*>* nuevoOrdenServicios = new ArrayList<Servicio*>(numServicios);
    for (int i = 0; i < numServicios; i++) {
        servicios->goToPos(nuevoOrdenIndices[i]);
        nuevoOrdenServicios->append(servicios->getElement());
    }

    // Limpiar la lista original y reasignar el nuevo orden desde el ArrayList temporal
    servicios->clear();
    for (int i = 0; i < nuevoOrdenServicios->getSize(); i++) {
        nuevoOrdenServicios->goToPos(i);
        servicios->append(nuevoOrdenServicios->getElement());
    }

    // Liberar la memoria del array de índices y el ArrayList temporal
    delete[] nuevoOrdenIndices;
    delete nuevoOrdenServicios;

    cout << "Servicios reordenados exitosamente.\n";
    pause();
}


void displayInfoServicios(List<Servicio*>* servicios) {
    if (servicios->getSize() == 0) {
        cout << "No hay servicios para reordenarr." << endl;
        pause();
        return;
    }
    Menu menu("== Consultar informacion servicios ==");
    for (int i = 0; i < servicios->getSize(); i++) {
        servicios->goToPos(i);
        menu.addOption(servicios->getElement()->getDescripcion());
    }
    menu.addOption("Cancelar");

    int selection;
    do {
        menu.display();
        selection = menu.getSelection();

        if (selection == servicios->getSize() + 1) {
            cout << "Operación cancelada.\n";
            return;
        }

        servicios->goToPos(selection - 1);
        cout << servicios->getElement()->getDescripcion() << " Prioridad: " << servicios->getElement()->getPrioridad() << " Area: " << servicios->getElement()->getArea()->getDescripcion()<<endl;
        pause();

    } while (selection < 1 || selection > servicios->getSize() + 1);
}

void showServicioMenu(List<Servicio*>* servicios, List<Area*>* areas) {
    Menu menu("== Menú de servicios ==");
    menu.addOption("Agregar");
    menu.addOption("Eliminar");
    menu.addOption("Reordenar");
    menu.addOption("Mostrar informacion");
    menu.addOption("Regresar");

    int option;
    do {
        menu.display();
        option = menu.getSelection();

        switch (option) {
        case 1:
            addServicio(servicios, areas);
            break;
        case 2:
            delServicio(servicios);
            break;
        case 3:
            reordenarServicios(servicios);
            break;
        case 4:
            displayInfoServicios(servicios);
            break;
        case 5:
            return;
        default:
            cout << "Opción inválida. Intente de nuevo.\n";
        }
    } while (option != 5);

}