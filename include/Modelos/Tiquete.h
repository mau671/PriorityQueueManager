/*
 * Archivo: Tiquete.h
 * Descripci�n: Clase que representa los tiquetes a atender.
 *
 * Autor(es): Lun Valverde y Josu� Meza
 */

#pragma once
#define DEFAULT_MAX 1024

#include <iostream>
#include <stdexcept>
#include "Estructuras/Abstractas/List.h"
#include "Estructuras/Concretas/ArrayList.h"
#include "Estructuras/Concretas/OrderedArrayList.h"
#include "TipoUsuario.h"
#include "Area.h"

using std::string;
using std::to_string;

class Area;
class Servicio;

class Tiquete {
private:
	string codigo;
	string hora;
	int prioridad;
	Servicio* servicio; //agregar clase servicio
	TipoUsuario* usuario;

public:
	Tiquete() {
	}

	Tiquete(const string hora, string codigoArea, TipoUsuario* usuario, int consecutivo)
		: hora(hora), servicio(servicio), usuario(usuario) {
		this->codigo = codigoArea + to_string(consecutivo);//buscar donde poner un numero global en el proyecto para utilizarlo para los c�digos
		this->prioridad = usuario->getPrioridad() * 10 + servicio->getPrioridad();
	}
	~Tiquete() {
		delete servicio;
	}

	int getPrioridad() {
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

	};
};