/*
 * Archivo: GestorEstadistica.cpp
 * Descripci�n: Implementaci�n de funciones para consultar estad�sticas del sistema.
 *
 * Autor(es): Josue Meza
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
    int TiempoEspera;
    for (int i = 0; i < areas->getSize(); i++) {
        TiempoEspera = 0;
        areas->goToPos(i);
        Area* area = areas->getElement();
        int totalTiquetesAtendidos = area->getTiquetesDispensados();
        if (totalTiquetesAtendidos == 0) {
            cout << "�rea: " << area->getDescripcion() << " - No se han atendido tiquetes.\n";
            continue;
        }
        else {
            for (int i = 0; i < area->getTiquetes()->getSize(); i++) {
                area->getVentanillas()->goToPos(i);
                TiempoEspera+= area->getVentanillas()->getElement()->getTiquete()->tiempoTardado();
            }
            double tiempoPromedioEspera = TiempoEspera / totalTiquetesAtendidos;
            cout << "�rea: " << area->getDescripcion() << " - Tiempo promedio de espera: " << tiempoPromedioEspera << " minutos.\n";
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
void TiquetesPorVentanilla(List<Ventanilla*>* ventanillas) {
    cout << "\n== Cantidad de tiquetes atendidos por ventanilla ==" << endl;
    for (int i = 0; i < ventanillas->getSize(); i++) {
        ventanillas->goToPos(i);
        Ventanilla* ventanilla = ventanillas->getElement();
        cout << "Ventanilla: " << ventanilla->getDescripcion() << " - Tiquetes atendidos: " << ventanilla->getTiquetesAtendidos() << endl;
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

//Creo que hay que hacer GestorEstad�sticas.h con esto.

void generarEstadisticas(List<Area*>* areas, List<Ventanilla*>* ventanillas, List<Servicio*>* servicios, List<TipoUsuario*>* tiposUsuario) {
    cout << "=== Generaci�n de Estad�sticas del Sistema ===\n" << endl;

    TiempoPromedioEspera(areas);
    TiquetesPorArea(areas);
    TiquetesPorVentanilla(ventanillas);
    TiquetesPorServicio(servicios);
    TiquetesPorUsuario(tiposUsuario);

    cout << "\n=== Fin de las Estad�sticas ===\n";
    pause();
}