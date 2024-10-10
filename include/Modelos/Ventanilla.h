/*
 * Archivo: Ventanilla.h
 * Descripción: Clase que representa las ventanillas donde se atienden los tiquetes.
 *
 * Autor(es): Lun Valverde
 */

#pragma once
#define DEFAULT_MAX 1024

#include <iostream>
#include <string>
#include <stdexcept>
#include "Modelos/Tiquete.h"

using std::string;
using std::runtime_error;

class Servicio;
class Tiquete;

class Ventanilla {
private:
	bool ocupada;
	string descripcion;
	Tiquete* tiquete;
	int tiquetesAtendidos = 0;

	// Constructor de copia y asignación como privados
	Ventanilla(const Ventanilla&) = delete;
	Ventanilla& operator=(const Ventanilla&) = delete;

public:
	Ventanilla(string descripcion) {
		this->descripcion = descripcion;
		ocupada = true;
		tiquete = nullptr;
	}

	~Ventanilla() {
		if (tiquete != nullptr) {
			delete tiquete;
		}
	}

	void setDescripcion(string descripcion) {
		this->descripcion = descripcion;
	}

	string getDescripcion() {
		return descripcion;
	}

	bool isOcupada() const {
		return ocupada;
	}

	void setTiquete(Tiquete* tiquete, string hora) {
		if (this->tiquete != nullptr) {
			delete this->tiquete;
		}
		this->tiquete = tiquete;
		ocupada = true;
		tiquetesAtendidos++;
	}

	Tiquete* getTiquete() {
		if (ocupada == true) {
			return tiquete;
		}
		throw runtime_error("La ventanilla no está atendiendo a ningún tiquete.");
	}

	int getTiquetesAtendidos() {
		return tiquetesAtendidos;
	}

	void liberar() {
		delete tiquete;
		tiquete = nullptr;
		ocupada = false;
	}

	bool operator==(const Ventanilla& otro) const {
		return this->descripcion == otro.descripcion;
	}

	bool operator!=(const Ventanilla& otro) const {
		return !(*this == otro);
	}
};

