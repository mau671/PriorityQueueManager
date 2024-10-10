/*
 * Archivo: Tiquete.h
 * Descripción: Clase que representa los tiquetes a atender.
 *
 * Autor(es): Lun Valverde, Josué Meza
 */

#pragma once
#define DEFAULT_MAX 1024

#include <iostream>
#include <stdexcept>
#include "Estructuras/Abstractas/List.h"
#include "Estructuras/Concretas/ArrayList.h"
#include "Estructuras/Concretas/OrderedArrayList.h"
#include "Modelos/TipoUsuario.h"
#include "Modelos/Area.h"

using std::string;
using std::to_string;
using std::endl;
using std::cout;
using std::ostream;

class Servicio;

class Tiquete {
private:
	string codigo;
	string hora;
	int prioridad = 0;
	Servicio* servicio = nullptr; //agregar clase servicio
	TipoUsuario* usuario = nullptr;

	// Constructor de copia y asignación como privados
	Tiquete(const Tiquete&) = delete;
	Tiquete& operator=(const Tiquete&) = delete;

public:

	Tiquete() {}

	Tiquete(const string hora, Servicio* servicio, TipoUsuario* usuario, string codigoArea, int consecutivo)
		: hora(hora), servicio(servicio), usuario(usuario) {
		this->codigo = codigoArea + to_string(consecutivo);//buscar donde poner un numero global en el proyecto para utilizarlo para los códigos
		this->prioridad = usuario->getPrioridad() * 10 + servicio->getPrioridad();
	}
	// Destructor
	~Tiquete() {}
	
	int getPrioridad() const {
		return prioridad;
	}

	Servicio* getServicio() {
		return servicio;
	}
	
	string getHora() {
		return hora;
	}
	string getCodigo() {
		return codigo;
	}

	//operadores
	bool operator >(const Tiquete & other) {
		return this->prioridad > other.prioridad;
	};

	bool operator <(const Tiquete & other) {
		return this->prioridad < other.prioridad;
	}
	bool operator ==(const Tiquete& other) {
		return this->prioridad == other.prioridad;
	}

	friend ostream& operator <<(ostream& os, const Tiquete& tiquete) {
		os << tiquete.codigo;
		return os;
	}
};