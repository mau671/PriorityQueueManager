#pragma once
#include <stdexcept>
#include "Estructuras/Abstractas/PriorityQueue.h"
#include "Estructuras/Concretas/MinHeap.h"
#include "Estructuras/Concretas/KVPair.h"


template <typename E>
class HeapPriorityQueue : public PriorityQueue<E> {
private:
	MinHeap<KVPair<int, E>>* pairs;

public:
	HeapPriorityQueue(int max = DEFAULT_MAX) {
		pairs = new MinHeap<KVPair<int, E>>(max);
	}

	~HeapPriorityQueue() {
		delete pairs;
	}

	void insert(E element, int priority) {
		KVPair<int, E> p(priority, element);
		pairs->insert(p);
	}

	E min() {
		KVPair<int, E> p = pairs->first();
		return p.value;
	}

	E removeMin() {
		KVPair<int, E> p = pairs->removeFirst();
		return p.value;
	}

	void clear() {
		pairs->clear();
	}

	int getSize() {
		return pairs->getSize();
	}

	bool isEmpty() {
		return pairs->isEmpty();
	}

	void print() {
		pairs->print();
	}

};

