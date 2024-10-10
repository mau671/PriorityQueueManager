/*
*
* Archivo:Servicio.h
* Descripci?n : Clase que representa los servicios que se pueden realizar.
*
* Autor(es) : Lun Valverde
*/

#pragma once
#define DEFAULT_MAX 1024

#include <iostream>
#include <stdexcept>

class Area;

using std::string;

class Servicio {
private:
    string descripcion;
    int prioridad;
    Area* area = nullptr;
    int tiquetesSolicitados = 0;

public:

    Servicio(string descripcion, int prioridad, Area* area) {
        this->descripcion = descripcion;
        this->prioridad = prioridad;
        this->area = area;
    }
    ~Servicio() {
    }

    void changeDescripcion(string descripcion) {
        this->descripcion = descripcion;
    }

    string getDescripcion() {
        return descripcion;
    }

    int getPrioridad() const {
        return prioridad;
    }
    Area* getArea() {
        return area;
    }

    void setArea(Area* area) {
		this->area = area;
	}

    int getTiquetesSolicitados() {
		return tiquetesSolicitados;
	}

    void aumentarTiquetesSolicitados() {
        tiquetesSolicitados++;
    }

    void setTiquetesSolicitados(int tiquetesSolicitados) {
		this->tiquetesSolicitados = tiquetesSolicitados;
	}

    bool operator<(const Servicio& otro) const {
		return this->prioridad < otro.prioridad;
	}

	bool operator>(const Servicio& otro) const {
		return this->prioridad > otro.prioridad;
	}

	bool operator==(const Servicio& otro) const {
		return this->prioridad == otro.prioridad;
	}

	bool operator!=(const Servicio& otro) const {
		return this->prioridad != otro.prioridad;
	}

	bool operator<=(const Servicio& otro) const {
		return this->prioridad <= otro.prioridad;
	}

	bool operator>=(const Servicio& otro) const {
		return this->prioridad >= otro.prioridad;
	}

    friend std::ostream& operator<<(std::ostream& os, const Servicio& servicio) {
		os << "Descripción: " << servicio.descripcion << std::endl;
		os << "Prioridad: " << servicio.prioridad << std::endl;
		return os;
	}
};

