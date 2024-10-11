/*
 * Archivo: GestorTiquete.cpp
 * Descripción: Este archivo contiene la implementación de las funciones para la creación y gestión de tiquetes.
 *
 * Autor(es): Josué Meza
 */

#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <sstream>
#include "Modelos/Tiquete.h"
#include "UI/Menu.h"
#include "Utilidades/utils.h"
#include "Modelos/TipoUsuario.h"
#include "Modelos/Servicio.h"
#include "Modelos/Area.h"

using std::string;
using std::cout;
using std::time;
using std::localtime;
using std::tm;
using std::stringstream;
using std::setw;
using std::setfill;

// Crear un nuevo tiquete
void addTiquete(List<TipoUsuario*>* usuarios, List<Servicio*>* servicios, int* consecutivoGlobal) {
    // Tipos de usuario
    if (usuarios->getSize() == 0) {
        cout << "No hay tipos de usuarios disponibles para crear un tiquete." << endl;
        pause();
        return;
    }
    if (servicios->getSize() == 0) {
        cout << "No hay servicios disponibles para crear un tiquete." << endl;
        pause();
        return;
    }

    // Menú de tipos de usuario
    while (true) {
        Menu menuUsuarios("== Tipos de usuario ==");
        for (int i = 0; i < usuarios->getSize(); i++) {
            usuarios->goToPos(i);
            menuUsuarios.addOption(usuarios->getElement()->getDescripcion());
        }
        menuUsuarios.addOption("Regresar");
        menuUsuarios.display("Seleccione el tipo de usuario: ");
        int seleccionUsuario = menuUsuarios.getSelection() - 1;  // Restar 1 para obtener el índice
        if (seleccionUsuario == usuarios->getSize()) {
            // Si se selecciona "Regresar", volver al menú anterior
            return;
        }

        usuarios->goToPos(seleccionUsuario);
        TipoUsuario* usuarioSeleccionado = usuarios->getElement();

        // Menú de servicios disponibles
        while (true) {
            Menu menuServicios("== Servicios disponibles ==");
            for (int i = 0; i < servicios->getSize(); i++) {
                servicios->goToPos(i);
                menuServicios.addOption(servicios->getElement()->getDescripcion());
            }
            menuServicios.addOption("Regresar");
            menuServicios.display("Seleccione el servicio: ");
            int seleccionServicio = menuServicios.getSelection() - 1;  // Restar 1 para obtener el índice
            if (seleccionServicio == servicios->getSize()) {
                // Si se selecciona "Regresar", volver al menú anterior (tipos de usuario)
                break;
            }

            servicios->goToPos(seleccionServicio);
            Servicio* servicioSeleccionado = servicios->getElement();

            // Crear un nuevo tiquete con la información seleccionada
            string horaSolicitud = obtenerHoraActual();
            string codigoArea = servicioSeleccionado->getArea()->getCodigo();
            Tiquete* nuevoTiquete = new Tiquete(horaSolicitud, servicioSeleccionado, usuarioSeleccionado, codigoArea, *consecutivoGlobal);
            servicioSeleccionado->getArea()->addTiquete(nuevoTiquete); // Agregar el tiquete a la lista del área

            // Aumentar el consecutivo global
            (*consecutivoGlobal)++;

            // Aumentar los contadores de estadísticas
            servicioSeleccionado->aumentarTiquetesSolicitados();
            usuarioSeleccionado->aumentarTiquetesSolicitados();

            // Mostrar el código y los detalles del tiquete generado
            cout << "Tiquete generado exitosamente.\n";
            cout << "Código: " << nuevoTiquete->getCodigo() << "\n";
            cout << "Hora: " << nuevoTiquete->getHora() << "\n";
            cout << "Prioridad: " << nuevoTiquete->getPrioridad() << "\n";
            pause();
            return;  // Finaliza la función después de generar el tiquete
        }
    }
}

