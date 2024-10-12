/*
 * Archivo: GestorServicio.cpp
 * Descripción: Declaraciones de funciones para gestionar los servicios del sistema.
 *              Las funcionalidades incluyen agregar, eliminar y mostrar el menú de servicios.
 *
 * Autor(es): Lun Valverde, Mauricio González
 */

#include <iostream>
#include <string>
#include <stdexcept>
#include "UI/Menu.h"
#include "Estructuras/Concretas/ArrayList.h"
#include "Estructuras/Abstractas/List.h"
#include "Estructuras/Concretas/MinHeap.h"
#include "Modelos/Area.h"
#include "Utilidades/utils.h"
#include "Modelos/Servicio.h"
#include "Modelos/Ventanilla.h"
#include "Modelos/Tiquete.h"

using std::string;
using std::cout;
using std::endl;
using std::cin;

//funcion que agrega un area
void addServicio(List<Servicio*>* servicios, List<Area*>* areas) {
    if (areas->getSize() == 0) {//se asegura de que haya al menos un area de la cual esocger
        cout << "No hay areas disponibles" << endl;
        pause();
        return;
    }
    Menu menu("Áreas disponibles");
    for (int i = 0; i < areas->getSize(); i++) {
        areas->goToPos(i);
        menu.addOption(areas->getElement()->getDescripcion()); //descripcion de las areas
    }
    menu.addOption("Cancelar");
    int selection;
    do {
        menu.display("Seleccione un área: ");//seleccion de area
        selection = menu.getSelection();

        if (selection == areas->getSize() + 1) {
            cout << "Operación cancelada.\n";
            return;
        }
        areas->goToPos(selection - 1);
        string descripcion = readString("Descripción/nombre del servicio: ");

        for (int i = 0; i < servicios->getSize(); i++) {//va por la lista de servicios para asegurarse de que no exista aún.
            servicios->goToPos(i);
            if (servicios->getElement()->getDescripcion() == descripcion) {
                cout << "Servicio ya existente." << endl;
                pause();
                return;
            }
        }
        int prioridad = readInt("Prioridad del servicio: ");
        Servicio* servicio = new Servicio(descripcion, prioridad, areas->getElement());//se crea el nuevo servicio
        servicios->append(servicio);//se agrega a la lista de servicios

        cout << "Servicio agregado exitosamente." << endl;
        pause();
   
    } while (selection < 1 || selection > servicios->getSize() + 1);
}

//elimina un servicio
void delServicio(List<Servicio*>* servicios) {
    if (servicios->getSize() == 0) {
        cout << "No hay servicios disponibles." << endl;
        pause();
        return;
    }

    Menu menu("== Eliminar servicio ==");
    for (int i = 0; i < servicios->getSize(); i++) {
        servicios->goToPos(i);
        menu.addOption(servicios->getElement()->getDescripcion()); // nombre de los servicios
    }
    menu.addOption("Cancelar");

    int selection;
    do {
        menu.display("Seleccione un servicio a eliminar: ");
        selection = menu.getSelection();

        if (selection == servicios->getSize() + 1) {
            cout << "Operación cancelada.\n";
            return;
        }

        bool confirmacion = readConfirmation("¿Está seguro que desea eliminar este servicio?");
        if (!confirmacion) {
            cout << "Operación cancelada.\n";
            return;
        }

        // Obtiene el servicio seleccionado
        servicios->goToPos(selection - 1);
        Servicio* servicioSeleccionado = servicios->getElement();

        // Obtiene el área asociada al servicio
        Area* areaAsociada = servicioSeleccionado->getArea();

        if (areaAsociada != nullptr) {
            
            int tiquetesEliminados = areaAsociada->limpiarTiquetes();
            cout << "Tiquetes eliminados: " << tiquetesEliminados << endl;
        }

        // Elimina el servicio
        delete servicios->remove(); // Liberar la memoria del objeto servicio eliminado
        cout << "Servicio eliminado." << endl;
        pause();

    } while (selection < 1 || selection > servicios->getSize() + 1);
}


//reordena los servicios en la lista
void reordenarServicios(List<Servicio*>* servicios, List<Area*>* areas) {
    if (servicios->getSize() == 0) {
        cout << "No hay servicios para reordenar." << endl;
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
        menu.display("Seleccione el servicio a reordenar: ");
        selection = menu.getSelection();

        if (selection == servicios->getSize() + 1) {
            cout << "Operación cancelada.\n";
            return;
        }

        // Solicitar la posicion de destino
        int newPos = readInt("Ingrese la nueva posición del servicio: ", servicios->getSize());

        // Reordenar el servicio
        servicios->swap(selection - 1, newPos - 1);

        //Area* area = servicios->goToPos(selection - 1)->getArea();

        cout << "Servicio reordenado exitosamente.\n";
        pause();

    } while (selection < 1 || selection > servicios->getSize() + 1);
}

//muestra la informacion de los servicios
void displayInfoServicios(List<Servicio*>* servicios) {
    if (servicios->getSize() == 0) {
        cout << "No hay servicios." << endl;
        pause();
        return;
    }
    Menu menu("== Consultar informacion de servicios ==");
    for (int i = 0; i < servicios->getSize(); i++) {
        servicios->goToPos(i);
        menu.addOption(servicios->getElement()->getDescripcion());
    }
    menu.addOption("Cancelar");

    int selection;
    do {
        menu.display("Seleccione un servicio: ");
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

//muestra el menú para servicios
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
            reordenarServicios(servicios, areas);
            break;
        case 4:
            displayInfoServicios(servicios);
            break;
        case 5:
            return;
        }
    } while (option != 5);

}