/*
 * Archivo: GestorEstadistica.cpp
 * Descripción: Implementación de funciones para consultar estadísticas del sistema.
 *
 * Autor(es): [Tu nombre]
 */

#include <iostream>
#include <string>
#include "Estructuras/Concretas/ArrayList.h"
#include "Modelos/Area.h"
#include "Modelos/Ventanilla.h"
#include "Modelos/Servicio.h"
#include "Modelos/Tiquete.h"
#include "Modelos/TipoUsuario.h"
#include "Utilidades/utils.h"

using std::cout;
using std::endl;
using std::string;

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
        servicios->append(servicio);

        cout << "Servicio agregado exitosamente.\n";
        pause();

    } while (selection < 1 || selection > servicios->getSize() + 1);
}

void showServicioMenu(List<Servicio*>* servicios, List<Area*>* areas, MinHeap<Tiquete*>* tiquetes) {
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
            delServicio(servicios, tiquetes);
            break;
        case 3:
            reordenarServicios(servicios, areas);
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