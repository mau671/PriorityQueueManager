/*
 * Archivo: ArrayList.h
 * Descripción: Implementación de una lista dinámica genérica basada en arreglos. Incluye métodos para
 *              insertar, agregar, eliminar, y gestionar elementos, así como funciones para expandir
 *              dinámicamente el tamaño del arreglo cuando es necesario.
 *
 * Autor(es): Profesor Mauricio Aviles Cisneros
 */

#pragma once

#define DEFAULT_MAX 1024

#include <stdexcept>
#include <iostream>
#include "Estructuras/Abstractas/List.h"

using std::runtime_error;
using std::cout;
using std::endl;

template <typename E>
class ArrayList : public List<E> {
protected:
	E* elements;
	int max;
	int size;
	int pos;

private:
	void expand() {
		E* newElements = new E[max * 2];
		for (int i = 0; i < size; i++)
			newElements[i] = elements[i];
		delete[] elements;
		elements = newElements;
		max *= 2;
	}

public:
	ArrayList(int max = DEFAULT_MAX) {
		if (max < 1)
			throw runtime_error("Invalid max size.");
		elements = new E[max];
		this->max = max;
		size = 0;
		pos = 0;
	}
	~ArrayList() {
		delete[] elements;
	}
	void insert(E element) {
		if (size == max)
			expand();
		for (int i = size; i > pos; i--)
			elements[i] = elements[i - 1];
		elements[pos] = element;
		size++;
	}
	void append(E element) {
		if (size == max)
			expand();
		elements[size] = element;
		size++;
	}
	void set(E element) {
		if (size == 0)
			throw runtime_error("List is empty.");
		if (pos == size)
			throw runtime_error("No current element.");
		elements[pos] = element;
	}
	E remove() {
		if (size == 0)
			throw runtime_error("List is empty.");
		if (pos == size)
			throw runtime_error("No current element.");
		E result = elements[pos];
		for (int i = pos + 1; i < size; i++)
			elements[i - 1] = elements[i];
		size--;
		return result;
	}
	E getElement() {
		if (size == 0)
			throw runtime_error("List is empty.");
		if (pos == size)
			throw runtime_error("No current element.");
		return elements[pos];
	}
	void clear() {
		size = pos = 0;
	}
	void goToStart() {
		pos = 0;
	}
	void goToEnd() {
		pos = size;
	}
	void goToPos(int pos) {
		if (pos < 0 || pos > size)
			throw runtime_error("Index out of bounds.");
		this->pos = pos;
	}
	void next() {
		if (pos < size)
			pos++;
	}
	void previous() {
		if (pos > 0)
			pos--;
	}
	bool atStart() {
		return pos == 0;
	}
	bool atEnd() {
		return pos == size;
	}
	int getPos() {
		return pos;
	}
	int getSize() {
		return size;
	}

	int indexOf(E element, int start = 0) {
		if (start < 0 || start >= size)
			throw runtime_error("Index out of bounds.");
		for (int i = start; i < size; i++)
			if (elements[i] == element)
				return i;
		return -1;
	}

	bool contains(E element) {
		return indexOf(element, 0) != -1;
	}

	void print() {
		cout << "[ ";
		for (int i = 0; i < size; i++) {
			if (i == pos)
				cout << "*";
			cout << elements[i];

			if (i < size - 1)
				cout << ", ";
			else 
				cout << " ";
		}
		if (pos == size)
			cout << "*";
		cout << "]" << endl;
	}
};

