/*
 * Archivo: Tiquete.h
 * Descripción: Clase que representa los tiquetes a atender.
 *
 * Autor(es): Lun Valverde y Josué Meza
 */

#pragma once
#define DEFAULT_MAX 1024

#include <iostream>
#include <stdexcept>
#include "Estructuras/Abstractas/List.h"
#include "Estructuras/Concretas/ArrayList.h"
#include "Estructuras/Concretas/OrderedArrayList.h"
#include "Modelos/Area.h"
#include "Modelos/Servicio.h"
#include "Modelos/TipoUsuario.h"

using std::string;

class Tiquete {
private:
	string codigo;
	string hora;
	int prioridad;
	Servicio* servicio; //agregar clase servicio
	//Area* area;
	TipoUsuario* usuario;

public:
	Tiquete() {
	}

	Tiquete(const string hora, Servicio* servicio, TipoUsuario* usuario, int consecutivo)
		: hora(hora), servicio(servicio)/*, usuario(usuario) */ {
		//this->area = servicio->getArea();
		this->codigo = servicio->getArea()->getCodigo() + std::to_string(consecutivo);//buscar donde poner un numero global en el proyecto para utilizarlo para los códigos
		this->prioridad = usuario->getPrioridad() * 10 + servicio->getPrioridad();
	}
	~Tiquete() {
		delete servicio;
		//delete area;
	}

	int getPrioridad() {
		return prioridad;
	}

	Servicio* getServicio() {
		return servicio;
	}
	/*

	Area* getArea() {
		return area;
	}
	*/
	string getHora() {
		return hora;
	}
	string getCodigo() {
		return codigo;

	};
};