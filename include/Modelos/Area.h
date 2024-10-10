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
#include "Estructuras/Abstractas/PriorityQueue.h"
#include "Estructuras/Concretas/HeapPriorityQueue.h"
#include "Estructuras/Concretas/OrderedArrayList.h"
#include "Modelos/Servicio.h"
#include "Modelos/Tiquete.h"
#include "Modelos/Ventanilla.h"

using std::string;
using std::to_string;
using std::endl;
using std::cout;

class Area {
private:
	string codigo; //inicio del nombre de las ventanillas
	string descripcion;
	int nVentanillas = 0;
	MinHeap<Tiquete*>* tiquetes = nullptr;
	ArrayList<Ventanilla*>* ventanillas = nullptr;
	int tiquetesDispensados = 0;

	// Constructor de copia y asignación privados
	Area(const Area&) = delete;
	Area& operator=(const Area&) = delete;

public:
	Area() {}

	Area(string descripcion, string codigo, int nVentanillas) {
		if (nVentanillas <= 0) throw runtime_error("La cantidad de ventanillas debe ser mayor que 0");
		this->descripcion = descripcion;
		this->codigo = codigo;
		this->nVentanillas = nVentanillas;

		ventanillas = new ArrayList<Ventanilla*>(nVentanillas);
		for (int i = 0; i <= nVentanillas; i++) {
			ventanillas->append(new Ventanilla(""+codigo+ std::to_string(i+1)));
			}

		tiquetes = new MinHeap<Tiquete*>();
	}

	~Area() {
		while (ventanillas->getSize() != 0) {
			delete ventanillas->remove();
		}
		delete ventanillas;
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

	int getNventanillas() const {
		return nVentanillas;
	}

	void setNventanillas(int nVentanillas) {
		this->nVentanillas = nVentanillas;
		ventanillas->clear();
		for (int i = 0; i <= nVentanillas; i++) {
			ventanillas->append(new Ventanilla("" + codigo + std::to_string(i + 1)));
		}
	}

	ArrayList<Ventanilla*>* getVentanillas() {
		return ventanillas;
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

	MinHeap<Tiquete*>* getTiquetes() {
		return tiquetes;
	}

	ArrayList<Ventanilla*>* getVentanillas() {
		return ventanillas;
	}

	void mostrarTiquetes() {
		tiquetes->print();
	}

	//add
	void addTiquete(Tiquete* tiquete) {
		tiquetes->insert(tiquete);
		tiquetesDispensados++;
	}

	int getTiquetesDispensados() {
		return tiquetesDispensados;
	}

	void setTiquetesDispensados(int tiquetesDispensados) {
		this->tiquetesDispensados = tiquetesDispensados;
	}

	int limpiarTiquetes() {
		int tiquetesEliminados = tiquetes->getSize();
		tiquetes->clear();
		return tiquetesEliminados;
	}

	int getSizeTiquetes() {
		return tiquetes->getSize();
	}


	void atenderTiquete(string nVentanilla) {
		if (tiquetes->isEmpty()) throw runtime_error("No hay tiquetes para atender");
		for (int i = 0; i < ventanillas->getSize(); i++) {
			ventanillas->goToPos(i);
			if (ventanillas->getElement()->getDescripcion() == nVentanilla) {
				ventanillas->getElement()->setTiquete(tiquetes->removeFirst());
				return;
			}
		}
		return;


	}

	friend ostream& operator<<(ostream& os, const Area& area) {
		os << "Area: " << area.descripcion << "\nCodigo: " << area.codigo << "\nNumero de ventanillas: " << area.nVentanillas << "\nVentanillas: ";
		for (int i = 0; i < area.nVentanillas; i++) {
			area.ventanillas->goToPos(i);
			os << area.ventanillas->getElement()->getDescripcion();
			if (i != area.nVentanillas - 1) {
				os << ", ";
			}
		}
		os << endl;
		return os;
	}
};

