/*
 * Archivo: OrderedArrayList.h
 * Descripci�n: Este archivo contiene la implementaci�n de la clase OrderedArrayList,
 *              que es una lista ordenada basada en un ArrayList. Proporciona m�todos
 *              para insertar, eliminar y acceder a elementos, asegurando que los
 *              elementos se mantengan en orden. Utiliza una instancia interna de ArrayList
 *              para el almacenamiento de datos.
 *
 * Autor(es): Profesor Mauricio Aviles Cisneros
 */

#pragma once
#include "Estructuras/Concretas/ArrayList.h"

template <typename E>
class OrderedArrayList : public List<E> {
private:
    ArrayList<E>* data;

public:
    OrderedArrayList(int max = DEFAULT_MAX) {
        data = new ArrayList<E>(max);
    }
    ~OrderedArrayList() {
        delete data;
    }

    // Inserta un elemento en la posici�n correcta para mantener el orden
    void insert(E element) {
        data->goToStart();
        while (!data->atEnd() && element >= data->getElement())
            data->next();
        data->insert(element);
    }

    // Agrega un elemento, lo inserta en orden
    void append(E element) {
        insert(element);
    }

    // Establece un nuevo valor en la posici�n actual
    void set(E element) {
        data->set(element);
    }

    // Elimina el elemento en la posici�n actual
    E remove() {
        return data->remove();
    }

    // Retorna el elemento en la posici�n actual
    E getElement() {
        return data->getElement();
    }

    // Limpia la lista
    void clear() {
        data->clear();
    }

    // M�todos de navegaci�n y manipulaci�n de la lista
    void goToStart() {
        data->goToStart();
    }
    void goToEnd() {
        data->goToEnd();
    }
    void goToPos(int pos) {
        data->goToPos(pos);
    }
    void next() {
        data->next();
    }
    void previous() {
        data->previous();
    }

    bool atStart() {
        return data->atStart();
    }
    bool atEnd() {
        return data->atEnd();
    }

    int getPos() {
        return data->getPos();
    }

    int getSize() {
        return data->getSize();
    }

    // M�todos de b�squeda
    int indexOf(E element, int start = 0) {
        return data->indexOf(element);
    }

    bool contains(E element) {
        return data->contains(element);
    }

    void swap(int i, int j) {
		data->swap(i, j);
	}

    // Imprime la lista
    void print() {
        data->print();
    }
};
