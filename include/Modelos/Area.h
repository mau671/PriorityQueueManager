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
#include "Estructuras/Concretas/MinHeap.h"
#include "Modelos/Servicio.h"
#include "Modelos/Tiquete.h"
#include "Modelos/Ventanilla.h"
#include "Utilidades/utils.h"

using std::string;
using std::to_string;
using std::endl;
using std::cout;

class Tiquete;

class Area {
private:
	string codigo; //inicio del nombre de las ventanillas
	string descripcion;
	int nVentanillas = 0;
	MinHeap<Tiquete*>* tiquetes = nullptr;
	ArrayList<Ventanilla*>* ventanillas = nullptr;
	int tiquetesDispensados = 0;
	int tiquetesAtendidos = 0;
	int tiempoTotalEspera = 0;

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
		for (int i = 0; i < nVentanillas; i++) {
			ventanillas->append(new Ventanilla(""+codigo+ std::to_string(i+1)));
			}

		tiquetes = new MinHeap<Tiquete*>();
	}

	~Area() {
		// Limpiar ventanillas
		while (ventanillas->getSize() != 0) {
			Ventanilla* ventanilla = ventanillas->remove();
			ventanilla->liberar();  // Libera el tiquete en la ventanilla
			delete ventanilla;  // Elimina la ventanilla
		}
		delete ventanillas;

		// Limpiar tiquetes
		delete tiquetes;
	}

	//setters y getters codigo, descripcion y ventanillas
	string getCodigo() {
		return codigo;
	}

	string getDescripcion() {
		return descripcion;
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

	//devuelve la informacion relacionada a el area
	void consultarInfo() {
		cout << descripcion + "\nCodigo: " + codigo + "\nnVentanillas: " + std::to_string(ventanillas->getSize()) /*std::to_string(nVentanillas) */ << endl;
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

	void mostrarTiquetes() {
		tiquetes->print();
	}

	//add
	void addTiquete(Tiquete* tiquete) {
		tiquetes->insert(tiquete);
		tiquetesDispensados++;
	}
	
	int getSizeTiquetes() {
		return tiquetes->getSize();
	}

	int getTiquetesDispensados() const {
		return tiquetesDispensados;
	}

	void setTiquetesDispensados(int tiquetesDispensados) {
		this->tiquetesDispensados = tiquetesDispensados;
	}

	int limpiarTiquetes() {
		int tiquetesEliminados = 0;
		for (int i = tiquetes->getSize()-1; i >= 0; i--) {
			delete tiquetes->remove(i);
			tiquetesEliminados++;
		}
		return tiquetesEliminados;
	}

	
	Tiquete* atenderTiquete(string nVentanilla) {
		string hora = obtenerHoraActual();
		if (tiquetes->isEmpty()) throw runtime_error("No hay tiquetes para atender");

		for (int i = 0; i < ventanillas->getSize(); i++) {
			ventanillas->goToPos(i);
			if (ventanillas->getElement()->getDescripcion() == nVentanilla) {
				Tiquete* tiquete = tiquetes->removeFirst();
				ventanillas->getElement()->setTiquete(tiquete, hora);
				tiquete->setHoraAtendido(hora);

				// Sumar el tiempo de espera del tiquete al tiempo total de espera del área
				tiempoTotalEspera += tiquete->tiempoTardado();
				tiquetesAtendidos++;
				return tiquete;
			}
		}
		throw runtime_error("No se encontró la ventanilla");
	}

	double obtenerTiempoPromedioEspera() const {
		if (tiquetesDispensados == 0) return 0;
		return static_cast<double>(tiempoTotalEspera) / tiquetesDispensados;
	}

	int getTiquetesAtendidos() const {
		return tiquetesAtendidos;
	}

	void setTiquetesAtendidos(int tiquetesAtendidos) {
		this->tiquetesAtendidos = tiquetesAtendidos;
	}

	void setTiempoTotalEspera(int tiempoTotalEspera) {
		this->tiempoTotalEspera = tiempoTotalEspera;
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

