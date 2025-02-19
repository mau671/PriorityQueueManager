/*
 * Archivo: GestorEstadistica.cpp
 * Descripci�n: Implementaci�n de funciones para consultar estad�sticas del sistema.
 *
 * Autor(es): Josue Meza, Lun Valverde, Mauricio Gonzalez
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

// Funci�n para calcular tiempo promedio de espera por cada �rea
void TiempoPromedioEspera(List<Area*>* areas) {
    cout << "== Tiempo promedio de espera por �rea ==" << endl;

    for (int i = 0; i < areas->getSize(); i++) {
        areas->goToPos(i);
        Area* area = areas->getElement();

        if (area->getTiquetesAtendidos() == 0  || area->obtenerTiempoPromedioEspera() == 0) {
            cout << "�rea: " << area->getDescripcion() << " - No se han atendido tiquetes.\n";
        }
        else {
            double tiempoPromedioEspera = area->obtenerTiempoPromedioEspera();
            cout << "�rea: " << area->getDescripcion() << " - Tiempo promedio de espera: " << tiempoPromedioEspera << " segundos.\n";
        }
    }

}

// Funci�n para mostrar la cantidad de tiquetes dispensados por cada �rea
void TiquetesPorArea(List<Area*>* areas) {
    cout << "\n== Cantidad de tiquetes dispensados por �rea ==" << endl;
    for (int i = 0; i < areas->getSize(); i++) {
        areas->goToPos(i);
        Area* area = areas->getElement();
        cout << "�rea: " << area->getDescripcion() << " - Tiquetes dispensados: " << area->getTiquetesDispensados() << endl;
    }
}

// Funci�n para mostrar la cantidad de tiquetes atendidos por ventanilla
void TiquetesPorVentanilla(List<Area*>* areas) {
    List<Ventanilla*>* ventanillas;
    cout << "\n== Cantidad de tiquetes atendidos por ventanilla ==" << endl;
    for (int i = 0; areas->getSize() > i; i++) {
        areas->goToPos(i);
        ventanillas = areas->getElement()->getVentanillas();
        for (int i = 0; i < ventanillas->getSize(); i++) {
            ventanillas->goToPos(i);
            Ventanilla* ventanilla = ventanillas->getElement();
            cout << "Ventanilla: " << ventanillas->getElement()->getDescripcion() << " - Tiquetes atendidos: " << ventanilla->getTiquetesAtendidos() << endl;
        }
    }
}

// Funci�n para mostrar la cantidad de tiquetes solicitados por servicio
void TiquetesPorServicio(List<Servicio*>* servicios) {
    cout << "\n== Cantidad de tiquetes solicitados por servicio ==" << endl;
    for (int i = 0; i < servicios->getSize(); i++) {
        servicios->goToPos(i);
        Servicio* servicio = servicios->getElement();
        cout << "Servicio: " << servicio->getDescripcion() << " - Tiquetes solicitados: " << servicio->getTiquetesSolicitados() << endl;
    }
}

// Funci�n para mostrar la cantidad de tiquetes emitidos por tipo de usuario
void TiquetesPorUsuario(List<TipoUsuario*>* tiposUsuario) {
    cout << "\n== Cantidad de tiquetes emitidos por tipo de usuario ==" << endl;
    for (int i = 0; i < tiposUsuario->getSize(); i++) {
        tiposUsuario->goToPos(i);
        TipoUsuario* tipoUsuario = tiposUsuario->getElement();
        cout << "Tipo de Usuario: " << tipoUsuario->getDescripcion() << " - Tiquetes emitidos: " << tipoUsuario->getTiquetesSolicitados() << endl;
    }
}

void limpiarSistema(List<Area*>* areas, List<Servicio*>* servicios, List<TipoUsuario*>* tiposDeUsuarios, int* consecutivoGlobal) {

    int tiquetesEliminados = 0;

    // Limpiar colas de tiquetes de cada area
    for (int i = 0; i < areas->getSize(); i++) {
        areas->goToPos(i);
        Area* area = areas->getElement();
        tiquetesEliminados += area->limpiarTiquetes();
        area->setTiquetesDispensados(0);
        area->setTiquetesAtendidos(0);
        area->setTiempoTotalEspera(0);

        // Limpiar tiquetes de cada ventanilla
        ArrayList<Ventanilla*>* ventanillas = area->getVentanillas();
        for (int i = 0; i < ventanillas->getSize(); i++) {
			ventanillas->goToPos(i);
			Ventanilla* ventanilla = ventanillas->getElement();
			ventanilla->setTiquetesAtendidos(0);
		}

    }

    // Limpiar tiquetes de cada servicio
    for (int i = 0; i < servicios->getSize(); i++) {
        servicios->goToPos(i);
        Servicio* servicio = servicios->getElement();
        servicio->setTiquetesSolicitados(0);
    }

    // Limpiar tiquetes de cada tipo de usuario
    for (int i = 0; i < tiposDeUsuarios->getSize(); i++) {
        tiposDeUsuarios->goToPos(i);
        TipoUsuario* tipoUsuario = tiposDeUsuarios->getElement();
        tipoUsuario->setTiquetesSolicitados(0);
    }

    // Reiniciar el consecutivo global a 100
    *consecutivoGlobal = 100;

    // Mostrar un resumen de las colas limpiadas
    if (tiquetesEliminados > 0) {
        cout << "Se han eliminado " << tiquetesEliminados << " tiquetes." << endl;
    }
    else {
        cout << "No hay tiquetes para eliminar." << endl;
    }
    cout << "Se han reiniciado las estad�sticas de tiquetes solicitados y el consecutivo global ha sido reiniciado a 100." << endl;
    pause();
}


void generarEstadisticas(List<TipoUsuario*>* tiposUsuario, List<Area*>* areas, List<Servicio*>* servicios) {
    clearConsole();
    cout << "=== Generaci�n de Estad�sticas del Sistema ===\n" << endl;
    if (areas->getSize() == 0) {
        cout << "No hay areas disponibles" << endl;
        pause();
        return;
    }
    TiempoPromedioEspera(areas);
    TiquetesPorArea(areas);
    TiquetesPorVentanilla(areas);
    if (servicios->getSize() == 0) {
        cout << "No hay servicios disponibles" << endl;
        pause();
        return;
    }
    TiquetesPorServicio(servicios);
    if (tiposUsuario->getSize() == 0) {
        cout << "No hay usuarios disponibles" << endl;
        pause();
        return;
    }
    TiquetesPorUsuario(tiposUsuario);

    cout << "\n=== Fin de las Estad�sticas ===\n";
    pause();
}