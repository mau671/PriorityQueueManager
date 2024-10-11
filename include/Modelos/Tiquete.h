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
	string horaAtendido;
	int segundosTardados = 0;
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
		segundosTardados = 0;
	}
	// Destructor
	~Tiquete() {}

	void setHoraAtendido(string horaA) {
		horaAtendido = horaA;
		int hA = stoi(to_string(horaA[0]) + to_string(horaA[1]));
		int mA = stoi(to_string(horaA[3]) + to_string(horaA[4]));
		int sA = stoi(to_string(horaA[6]) + to_string(horaA[7]));

		int h = stoi(to_string(hora[0]) + to_string(hora[1]));
		int m = stoi(to_string(hora[3]) + to_string(hora[4]));
		int s = stoi(to_string(hora[6]) + to_string(hora[7]));

		int totalA = hA * 3600 + mA * 60 + sA;//hora atendido
		int totalP = h * 3600 + m * 60 + s;//hora solicitado

		if (totalA > totalP)
			segundosTardados = totalA - totalP;
		else segundosTardados = 0;
	}

	int tiempoTardado() const {
		return segundosTardados;
	}


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