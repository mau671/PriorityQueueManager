/*
 * Archivo: GestorArea.h
 * Descripción: 
 *
 * Autor(es): Lun Valverde Villalobos
 */

#ifndef GESTORSERVICIO_H
#define GESTORSERVICIO_H

#include <iostream>
#include "Estructuras/Concretas/ArrayList.h"
#include "Estructuras/Concretas/OrderedArrayList.h"
#include "Modelos/Servicio.h"

using std::string;

void addServicio(ArrayList<Servicio*>* servicios, List<Area*>* areas);
void delServicio(ArrayList<Servicio*>* servicios);
void reordenarServicios(ArrayList<Servicio*>* servicios, List<Area*>* areas);
void displayInfoServicios(ArrayList<Servicio*>* servicios);
void showServicioMenu(ArrayList<Servicio*>* servicios, List<Area*>* areas);


#endif