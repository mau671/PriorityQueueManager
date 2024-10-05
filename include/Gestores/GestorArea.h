/*
 * Archivo: GestorArea.h
 * Descripci�n: Declaraciones de funciones para gestionar las �reas del sistema.
 *              Las funcionalidades incluyen agregar, modificar, eliminar �reas y mostrar el men� de �reas.
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
void modifyAreaVentanillas(List<Area*>* areas);
void deleteArea(List<Area*>* areas);
void showAreaMenu(List<Area*>* areas);
Area* buscarAreaPorCodigo(List<Area*>* areas, const string& codigo);

#endif // GESTORAREA_H
