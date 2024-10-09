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

void addServicio(List<Servicio*>* servicios, List<Area*>* areas);
void delServicio(List<Servicio*>* servicios);
void reordenarServicios(List<Servicio*>* servicios, List<Area*>* areas);
void displayInfoServicios(List<Servicio*>* servicios);
void showServicioMenu(List<Servicio*>* servicios, List<Area*>* areas);


#endif