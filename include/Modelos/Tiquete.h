/*
 * Archivo: Tiquete.h
 * Descripción: Clase que representa los tiquetes a atender.
 *
 * Autor(es): Lun Valverde
 */

#pragma once
#define DEFAULT_MAX 1024

#include <iostream>
#include <stdexcept>
#include "Estructuras/Abstractas/List.h"
#include "Estructuras/Concretas/ArrayList.h"
#include "Estructuras/Concretas/OrderedArrayList.h"
#include "Modelos/Area.h"
#include "Modelos/Servicio.h"

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

