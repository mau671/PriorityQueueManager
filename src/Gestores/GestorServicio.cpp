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

void delServicio(List<Servicio*>* servicios, MinHeap<Tiquete*>* tiquetes) {
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
        for (int e = tiquetes->getSize() - 1; e >= 0; e--) {//se busca en la cola los tiquetes, los que tengan el area del servicio
            if (tiquetes->get(e)->getServicio() == servicios->getElement()) delete tiquetes->remove(e);//se elimina el tiquete si tiene el servicio
        }
        delete servicios->remove(); // Liberar la memoria del objeto eliminado
        cout << "Servicio eliminado eliminado.\n";
        pause();
    } while (selection < 1 || selection > servicios->getSize() + 1);
}

void reordenarServicios(List<Servicio*>* servicios, List<Area*>* areas) {
    if (servicios->getSize() == 0) {
        cout << "No hay servicios para reordenarr." << endl;
        pause();
        return;
    }
    Menu menu("== Reordenar servicios ==");
    for (int i = 0; i < servicios->getSize(); i++) {
        servicios->goToPos(i);
        menu.addOption(servicios->getElement()->getDescripcion()); //descripcion de las areas
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

        /* 
        * 
        * 
        *  reordenamiento aqui
        * 
        * 
        */

        //cout << "Prioridad modificada exitosamente.\n";
        pause();

    } while (selection < 1 || selection > servicios->getSize() + 1);
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