/*
 * Archivo: GestorTiquete.cpp
 * Descripci�n: Este archivo contiene la implementaci�n de las funciones para la creaci�n y gesti�n de tiquetes.
 *
 * Autor(es): Josu� Meza
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

using std::string;
using std::cout;
using std::time;
using std::localtime;
using std::tm;
using std::stringstream;
using std::setw;
using std::setfill;


int consecutivoGlobal = 100;

//Hora actual en formato HH:MM:SS
string obtenerHoraActual() {
    time_t t = time(nullptr);
    tm now;
    localtime_s(&now, &t);  // Usar localtime_s en lugar de localtime
    stringstream ss;
    ss << setw(2) << setfill('0') << now.tm_hour << ":"
        << setw(2) << setfill('0') << now.tm_min << ":"
        << setw(2) << setfill('0') << now.tm_sec;
    return ss.str();
}


// Crear un nuevo tiquete
void addTiquete(MinHeap<Tiquete*>* tiquetes, List<TipoUsuario*>* usuarios, List<Servicio*>* servicios) {
    // Tipos de usuario
    if (usuarios->getSize() == 0) {
        cout << "No hay tipos de usuarios disponibles para crear un tiquete." << endl;
        return;
    }
    if (servicios->getSize() == 0) {
        cout << "No hay servicios disponibles para crear un tiquete." << endl;
        return;
    }
    Menu menuUsuarios("== Seleccione su tipo de usuario ==");
    for (int i = 0; i < usuarios->getSize(); i++) {
        usuarios->goToPos(i);
        menuUsuarios.addOption(usuarios->getElement()->getDescripcion());
    }
    menuUsuarios.display();
    int seleccionUsuario = menuUsuarios.getSelection() - 1;  // Restar 1 para obtener el �ndice
    usuarios->goToPos(seleccionUsuario);
    TipoUsuario* usuarioSeleccionado = usuarios->getElement();

    // Mostrar servicios disponibles
    Menu menuServicios("== Seleccione el servicio que desea solicitar ==");
    for (int i = 0; i < servicios->getSize(); i++) {
        servicios->goToPos(i);
        menuServicios.addOption(servicios->getElement()->getDescripcion());
    }
    menuServicios.display();
    int seleccionServicio = menuServicios.getSelection() - 1;  // Restar 1 para obtener el �ndice
    servicios->goToPos(seleccionServicio);
    Servicio* servicioSeleccionado = servicios->getElement();

    // Crear un nuevo tiquete con la informaci�n seleccionada
    //const string hora, Servicio* servicio, TipoUsuario* usuario,     string codigoArea, int consecutivo
    string horaSolicitud = obtenerHoraActual();
    string codigoArea = servicioSeleccionado->getArea()->getCodigo();
    Tiquete* nuevoTiquete = new Tiquete(horaSolicitud, servicioSeleccionado, usuarioSeleccionado, codigoArea, consecutivoGlobal);
    servicioSeleccionado->getArea()->addTiquete(nuevoTiquete);//agregar el tiquete a la lista del area
    // Aumentar el consecutivo global
    consecutivoGlobal++;

    // Agregar el tiquete a la lista
    tiquetes->insert(nuevoTiquete);

    // Mostrar el c�digo y los detalles del tiquete generado
    cout << "Tiquete generado exitosamente.\n";
    cout << "C�digo: " << nuevoTiquete->getCodigo() << "\n";
    cout << "Hora: " << nuevoTiquete->getHora() << "\n";
    cout << "Prioridad: " << nuevoTiquete->getPrioridad() << "\n";
    pause();
}
