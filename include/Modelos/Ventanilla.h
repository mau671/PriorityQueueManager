/*
 * Archivo: Ventanilla.h
 * Descripción: Clas que representa las ventanillas donde se atienden los tiquetes
 *
 * Autor(es): Lun Valverde
 */

#pragma once
#define DEFAULT_MAX 1024

#include <iostream>
#include <stdexcept>
#include "Modelos/Area.h"
#include "Modelos/Tiquete.h"

using std::string;
using std::runtime_error;

class Ventanilla {
private:
	bool ocupada;
	string descripcion;
	Tiquete tiquete; //tiquete que esta atendiendo actualmente

public:
	Ventanilla(string descripcion) {
		this->descripcion = descripcion;
	}

	~Ventanilla() {
	}

	void setEstado(bool estado) {
		ocupada = estado;
	}

	void setDescripcion(string descripcion) {
		this->descripcion = descripcion;
	}

	string getDescripcion() {
		return descripcion;
	}

	bool isOcupada() {
		return ocupada;
	}

	void setTiquete(Tiquete tiquete) {
		this->tiquete = tiquete;
	}

	Tiquete getTiquete() {
		if (ocupada = true) {
			return tiquete;
		}
		throw runtime_error("La ventanilla no está atendiendo a ningún tiquete.");
	}

};

