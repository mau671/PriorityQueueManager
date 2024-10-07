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
	Area area;

public:
    Servicio() {
    }

	Servicio(string descripcion, int prioridad, Area area) {
		this->area = area;
		this->descripcion = descripcion;
		this->prioridad = prioridad;

        area.addSercivio(this);
	}
	~Servicio() {
	}

    void changetDescripcion(string descripcion) {
        this->descripcion = descripcion;
    }

    string getDescripcion() {
        return descripcion;
    }

    int getPrioridad() const {
        return prioridad;
    }

    Area getArea() const {
        return area;
    }
	

};

