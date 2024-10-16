#pragma once

template <typename E>
class PriorityQueue {
private:
	PriorityQueue(const PriorityQueue<E>& other) {}
	void operator =(const PriorityQueue<E>& other) {}

public:
	PriorityQueue() {}
	virtual ~PriorityQueue() {}
	virtual void insert(E element, int priority) = 0;
	virtual E min() = 0;
	virtual E removeMin() = 0;
	virtual void clear() = 0;
	virtual int getSize() = 0;
	virtual bool isEmpty() = 0;
	virtual void print() = 0;
};

