#pragma once
#include "ArrayList.h"

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
	void insert(E element) {
		data->goToStart();
		while (!data->atEnd() && element >= data->getElement())
			data->next();
		data->insert(element);
	}
	void append(E element) {
		insert(element);
	}
	void set(E element) {
		data->set(element);
	}
	E remove() {
		return data->remove();
	}
	E getElement() {
		return data->getElement();
	}
	void clear() {
		data->clear();
	}
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

	int indexOf(E element, int start = 0) {
		return data->indexOf(element);
	}

	bool contains(E element) {
		return data->contains(element);
	}

	void print() {
		data->print();
	}
};

