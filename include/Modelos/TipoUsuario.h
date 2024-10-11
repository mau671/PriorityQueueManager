/*
 * Archivo: TipoUsuario.h
 * Descripción: Clase que representa un tipo de usuario con prioridad y descripción.
 *
 * Autor(es): Mauricio Gonzalez
 */

#pragma once
#define DEFAULT_MAX 1024

#include <iostream>
#include <stdexcept>

using std::string;
using std::ostream;

class TipoUsuario {
private:
    TipoUsuario(const TipoUsuario&) = delete;
    TipoUsuario& operator=(const TipoUsuario&) = delete;

    string descripcion;
    int prioridad;

    int tiquetesSolicitados = 0;


public:
    // Constructor por defecto
    TipoUsuario() : descripcion(""), prioridad(0) {}

    // Constructor con parámetros
    TipoUsuario(string descripcion, int prioridad) {
        this->descripcion = descripcion;
        this->prioridad = prioridad;
    }

    // Destructor
    ~TipoUsuario() {}

    // Setters y getters
    void setDescripcion(string descripcion) {
        this->descripcion = descripcion;
    }

    string getDescripcion() const {
        return descripcion;
    }

    void setPrioridad(int prioridad) {
        this->prioridad = prioridad;
    }

    int getPrioridad() const {
        return prioridad;
    }

    int getTiquetesSolicitados() const {
		return tiquetesSolicitados;
	}

    void aumentarTiquetesSolicitados() {
		tiquetesSolicitados++;
	}

    void setTiquetesSolicitados(int tiquetesSolicitados) {
        this->tiquetesSolicitados = tiquetesSolicitados;
    }

    // Sobrecarga de operadores de comparación
    bool operator<(const TipoUsuario& otro) const {
        return this->prioridad < otro.prioridad;
    }

    bool operator>(const TipoUsuario& otro) const {
        return this->prioridad > otro.prioridad;
    }

    bool operator==(const TipoUsuario& otro) const {
        return this->prioridad == otro.prioridad;
    }

    bool operator!=(const TipoUsuario& otro) const {
        return !(*this == otro);
    }

    // Sobrecarga del operador de inserción para imprimir (cout)
    friend ostream& operator<<(ostream& os, const TipoUsuario& tipoUsuario) {
        os << "Descripcion: " << tipoUsuario.descripcion << ", Prioridad: " << tipoUsuario.prioridad;
        return os;
    }
};