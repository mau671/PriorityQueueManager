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

void addServicio(OrderedArrayList<Servicio*>* servicios, List<Area*>* areas);
void delServicio(OrderedArrayList<Servicio*>* servicios);
void reordenarServicios(OrderedArrayList<Servicio*>* servicios, List<Area*>* areas);
void displayInfoServicios(OrderedArrayList<Servicio*>* servicios);
void showServicioMenu(OrderedArrayList<Servicio*>* servicios, List<Area*>* areas);


#endif