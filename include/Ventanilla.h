/*
 * Archivo: Ventanilla.h
 * Descripción: 
 *
 * Autor(es): Lun Valverde
 */

#pragma once
#define DEFAULT_MAX 1024

#include <iostream>
#include <stdexcept>
#include "Area.h"
#include "Tiquete.h"

using std::string;
using std::runtime_error;

class Ventanilla {
protected:
	bool ocupada;
	Area area;
	Tiquete tiquete; //tiquete que esta atendiendo actualmente

public:
	Ventanilla() {
	}

	Ventanilla(Area area) {
		this->area = area;
	}

	~Ventanilla() {
	}

	void setEstado(bool estado) {
		ocupada = estado;
	}

	Area getArea() {
		return area;
	}

	bool isOcupada() {
		return ocupada;
	}

	Tiquete getTiquete() {
		if (ocupada = true) {
			return tiquete;
		}
		throw runtime_error("La ventanilla no está atendiendo a ningún tiquete.");
	}

};

