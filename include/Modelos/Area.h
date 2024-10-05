/*
 * Archivo: Area.h
 * Descripción: 
 *
 * Autor(es): Lun Valverde c:
 */

#pragma once
#define DEFAULT_MAX 1024

#include <iostream>
#include <stdexcept>
#include "Estructuras/Abstractas/List.h"
#include "Estructuras/Concretas/ArrayList.h"
#include "Estructuras/Concretas/OrderedArrayList.h"
#include "Modelos/Tiquete.h"
#include "Modelos/Ventanilla.h"

using std::string;

class Area {
private:
	string codigo; //letra de inicio para el nombre de las ventanillas
	string descripcion;
	OrderedArrayList<Tiquete>* tiquetes = nullptr;
	ArrayList<Ventanilla>* ventanillas = nullptr;
	ArrayList<Servicio>* servicios = nullptr;

public:
	Area() {

	}

	Area(string descripcion, char codigo, int NVentanillas) {
		ventanillas = new ArrayList<Ventanilla>(NVentanillas);
		tiquetes = new OrderedArrayList<Tiquete>(1);//necesaroio??
		servicios = new ArrayList<Servicio>(1);
		this->descripcion = descripcion;
		this->codigo = codigo;
	}
	~Area() {
		delete ventanillas;
		delete servicios;
		delete tiquetes;
	} 

	//geters
	string getCodigo() {
		return codigo;
	}

	string getDescripvion() {
		return descripcion;
	}

	int getNventanillas() {
		return ventanillas->getSize();
	}

	void mostrarTiquetes() {
		tiquetes->print();
	}

	void mostrarVentanillas() {
		ventanillas->print();
	}

	void mostrarServicios() {
		servicios->print();
	}

	//add
	void addTiquete(Tiquete tiquete) {
		tiquetes->append(tiquete);
	}

	void addServicio(Servicio servicio) {
		servicios->append(servicio);
	}

	void addVentanillas(int nVentanillas) {
		//
	}

	//del
	/*
	void addTiquete(Tiquete tiquete) {
		tiquetes->append(tiquete);
	}

	void addServicio(Servicio servicio) {
		servicios->append(servicio);
	}

	void addVentanillas(int nVentanillas) {
		//
	}
	*/

};

