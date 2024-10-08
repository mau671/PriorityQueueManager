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


using std::string;
using std::runtime_error;

class Tiquete;
class Servicio;

class Ventanilla {
private:
	bool ocupada;
	string descripcion;
	Tiquete* tiquete = nullptr;

public:
	Ventanilla(string descripcion) {
		this->descripcion = descripcion;
		ocupada = true;
	}

	~Ventanilla() {
		delete tiquete;
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

	void setTiquete(Tiquete* tiquete) {
		if (this->tiquete != nullptr) {
			delete this->tiquete;
		}
		this->tiquete = tiquete;
		ocupada = true;
	}

	Tiquete* getTiquete() {
		if (ocupada == true) {
			return tiquete;
		}
		throw runtime_error("La ventanilla no está atendiendo a ningún tiquete.");
	}

};

