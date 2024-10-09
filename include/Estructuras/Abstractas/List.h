/*
 * Archivo: List.h
 * Descripci�n: Definici�n de una clase abstracta gen�rica para listas. Incluye las firmas de m�todos
 *              esenciales para manipulaci�n de listas, como insertar, agregar, eliminar, y gestionar
 *              elementos, adem�s de metodos adicionales como b�squeda y verificaci�n de contenido.
 *
 * Autor(es): Profesor Mauricio Aviles Cisneros
 */

#pragma once

template <typename E>
class List {
private:
	List(const List<E>& other) {}
	void operator =(const List<E>& other) {}

public:
	List() {}
	virtual ~List() {}
	virtual void insert(E element) = 0;
	virtual void append(E element) = 0;
	virtual void set(E element) = 0;
	virtual E remove() = 0;
	virtual E getElement() = 0;
	virtual void clear() = 0;
	virtual void goToStart() = 0;
	virtual void goToEnd() = 0;
	virtual void goToPos(int pos) = 0;
	virtual void next() = 0;
	virtual void previous() = 0;
	virtual bool atStart() = 0;
	virtual bool atEnd() = 0;
	virtual int getPos() = 0;
	virtual int getSize() = 0;
	virtual void print() = 0;

	// metodos adicionales
	virtual void swap(int i, int j) = 0;
	virtual int indexOf(E element, int start = 0) = 0;
	virtual bool contains(E element) = 0;
};

