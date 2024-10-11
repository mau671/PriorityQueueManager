/*
 * Archivo: GestorArea.h
 * Descripci�n: Declaraciones de funciones para gestionar las �reas del sistema.
 *              Las funcionalidades incluyen agregar, modificar las ventanillas, eliminar �reas y mostrar el men� de �reas.
 *
 * Autor(es): Mauricio Gonzalez
 */

#ifndef GESTORAREA_H
#define GESTORAREA_H

#include <string>
#include "Estructuras/Concretas/ArrayList.h"
#include "Modelos/Area.h"

using std::string;

// Declaraciones de las funciones para la gesti�n de �reas
void addArea(List<Area*>* areas);
void modifyVentanillas(List<Area*>* areas);
void deleteArea(List<Area*>* areas, List<Servicio*>* servicios);
void showAreaMenu(List<Area*>* areas, List<Servicio*>* servicios);
void displayInfoArea(List<Area*>* areas);


#endif // GESTORAREA_H
