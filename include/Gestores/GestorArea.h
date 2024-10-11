/*
 * Archivo: GestorArea.h
 * Descripción: Declaraciones de funciones para gestionar las áreas del sistema.
 *              Las funcionalidades incluyen agregar, modificar las ventanillas, eliminar áreas y mostrar el menú de áreas.
 *
 * Autor(es): Mauricio Gonzalez
 */

#ifndef GESTORAREA_H
#define GESTORAREA_H

#include <string>
#include "Estructuras/Concretas/ArrayList.h"
#include "Modelos/Area.h"

using std::string;

// Declaraciones de las funciones para la gestión de áreas
void addArea(List<Area*>* areas);
void modifyVentanillas(List<Area*>* areas);
void deleteArea(List<Area*>* areas, List<Servicio*>* servicios);
void showAreaMenu(List<Area*>* areas, List<Servicio*>* servicios);
void displayInfoArea(List<Area*>* areas);


#endif // GESTORAREA_H
