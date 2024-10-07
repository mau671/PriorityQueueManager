/*
 * Archivo: Servicio.h
 * Descripción: Clase que representa los servicios que se pueden realizar.
 *
 * Autor(es): Lun Valverde
 */

#pragma once
#define DEFAULT_MAX 1024

#include <iostream>
#include <stdexcept>
#include "Modelos/Area.h"

using std::string;

class Servicio {
private:
	string descripcion;
	int prioridad;
    Area* area;

public:

	Servicio(string descripcion, int prioridad, Area* area) {
		this->descripcion = descripcion;
		this->prioridad = prioridad;
	}
	~Servicio() {
	}

    void changeDescripcion(string descripcion) {
        this->descripcion = descripcion;
    }

    string getDescripcion() {
        return descripcion;
    }

    int getPrioridad() {
        return prioridad;
    }
    Area* getArea() {
        return area;
    }
};

