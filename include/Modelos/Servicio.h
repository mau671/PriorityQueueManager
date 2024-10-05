/*
 * Archivo: Servicio.h
 * Descripción:
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
	}
	~Servicio() {
	}

    void changetDescripcion(string descripcion) {
        this->descripcion = descripcion;
    }

    string getDescripcion() {
        return descripcion;
    }

    void changePrioridad(int prioridad) {
        this->prioridad = prioridad;
    }

    int getPrioridad() const {
        return prioridad;
    }

    void changeArea(Area area) {
        this->area = area;
    }

    Area getArea() const {
        return area;
    }
	

};

