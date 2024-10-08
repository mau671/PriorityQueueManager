/*
 * Archivo: Area.h
 * Descripción: Clase que representa las areas donde se atienden los servicios.
 *
 * Autor(es): Lun Valverde c:
 */

#pragma once
#define DEFAULT_MAX 1024

#include <iostream>
#include <stdexcept>
#include <string>
#include "Estructuras/Abstractas/List.h"
#include "Estructuras/Concretas/ArrayList.h"
#include "Estructuras/Concretas/OrderedArrayList.h"
#include "Modelos/Servicio.h"
#include "Modelos/Ventanilla.h"
#include "Modelos/Tiquete.h"

using std::string;

class Area {
private:
	string codigo; //inicio del nombre de las ventanillas
	string descripcion;
	int nVentanillas;
	OrderedArrayList<Tiquete*>* tiquetes = nullptr;
	ArrayList<Ventanilla*>* ventanillas = nullptr;
	ArrayList<Servicio*>* servicios = nullptr;

public:
	Area() {
		
	}

	Area(string descripcion, string codigo, int nVentanillas) {
		if (nVentanillas <= 0) throw runtime_error("La cantidad de ventanillas debe ser mayor que 0");
		this->descripcion = descripcion;
		this->codigo = codigo;
		this->nVentanillas = nVentanillas;

		ventanillas = new ArrayList<Ventanilla*>(nVentanillas);
		for (int i = 0; i <= nVentanillas; i++) {
			ventanillas->append(new Ventanilla(""+codigo+ std::to_string(i+1)));
			}

		tiquetes = new OrderedArrayList<Tiquete*>();
		servicios = new ArrayList<Servicio*>();
	}
	~Area() {
		delete ventanillas;
		delete servicios;
		delete tiquetes;
	} 

	//setters y getters codigo, descripcion y ventanillas
	string getCodigo() {
		return codigo;
	}

	void setCodigo(string codigo) {
		this->codigo = codigo;
	}

	string getDescripcion() {
		return descripcion;
	}

	void setDescripcion(string descripcion) {
		this->descripcion = descripcion;
	}

	int getNventanillas() {
		return nVentanillas;
	}

	void setNventanillas(int nVentanillas) {
		this->nVentanillas = nVentanillas;
		ventanillas->clear();
		for (int i = 0; i <= nVentanillas; i++) {
			ventanillas->append(new Ventanilla("" + codigo + std::to_string(i + 1)));
		}
	}

	void consultarInfo() {
		cout << descripcion + "\nCodigo: " + codigo + "\nnVentanillas: " + std::to_string(nVentanillas) << endl;
		cout << "Ventanillas: ";
		for (int i = 0; i < nVentanillas; i++) {
			ventanillas->goToPos(i);
			cout << ventanillas->getElement()->getDescripcion();
			if (i != nVentanillas - 1) {
				cout << ", ";
			}
		}
		cout << endl;
	}

	//print
	void mostrarVentanillas() {
		ventanillas->print();
	}

	void mostrarTiquetes() {
		tiquetes->print();
	}

	void mostrarServicios() {
		servicios->print();
	}

	//add
	void addTiquete(Tiquete* tiquete) {
		tiquetes->append(tiquete);
	}

	void addServicio(Servicio* servicio) {
		servicios->append(servicio);
	}

	//del
	void delTiquete(Tiquete* tiquete) {
		
	}

	void delServicio(Servicio* servicio) {
		
	}

};

