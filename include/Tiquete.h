/*
 * Archivo: Area.h
 * Descripción:
 *
 * Autor(es): Lun Valverde
 */

#pragma once
#define DEFAULT_MAX 1024

#include <iostream>
#include <stdexcept>
#include "List.h"
#include "ArrayList.h"
#include "OrderedArrayList.h"
#include "Area.h"
#include "Servicio.h"
#include <UserTypeManager.h>

using std::string;

class Tiquete{
private:
	string codigo;
	string hora;
	int prioridad;
	int nTiquetes=100;//??
	Servicio servicio; //agregar clase servicio
	Area area;

public:
	Tiquete() {
	}

	Tiquete(string hora, Servicio servicio) {
		this->servicio = servicio;
		this->hora = hora;
		area = servicio.getArea();
		codigo = area.getCodigo() + std::to_string(nTiquetes);//buscar donde poner un numero global en el proyecto para utilizarlo para los códigos
		//calcular prioridad
	}
	~Tiquete() {
	}

	int getPrioridad() {
		return prioridad;
	}

	Servicio getServicio() {
		return servicio;
	}

	Area getArea() {
		return area;
	}

	string getHora() {
		return hora;
	}

	string getCodigo() {
		return codigo;
	}
};

