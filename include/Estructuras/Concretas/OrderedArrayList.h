/*
 * Archivo: OrderedArrayList.h
 * Descripción: Este archivo contiene la implementación de la clase OrderedArrayList,
 *              que es una lista ordenada basada en un ArrayList. Proporciona métodos
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

    // Inserta un elemento en la posición correcta para mantener el orden
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

    // Establece un nuevo valor en la posición actual
    void set(E element) {
        data->set(element);
    }

    // Elimina el elemento en la posición actual
    E remove() {
        return data->remove();
    }

    // Retorna el elemento en la posición actual
    E getElement() {
        return data->getElement();
    }

    // Limpia la lista
    void clear() {
        data->clear();
    }

    // Métodos de navegación y manipulación de la lista
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

    // Métodos de búsqueda
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
