#include "ListaConArreglo.h"

template <typename T>

class queue: public ListaConArreglo<T> {
public:
	int front;
	int back;
	queue() {
		front = this->tam;
		back = this->ultimo;
	}
	void enqueue(T in) {
		ListaConArreglo<T>::agregar(in);
		back++;
	} 
	T dequeue() {
		if (this->back != -1) {
		this->back--;
		return ListaConArreglo<T>::eliminar(this->data[this->front]);
		
		}
		else {
			std::cout << "Queue vacio" << std::endl;
		}
	}
	int size() {
		return this->back - this->front;
	}
	bool isEmpty() {
		int j = 1;

		for (int i = this->front; i<this->back; i++){
			if (this->data[j] != 0) {
				j=0;
			}
		}
		if (j==1) {
			return true;
		}
		else {
			return false;
		}
	}
	void nuevo() {
		ListaConArreglo<T>::clear();
	}

	void imp() {
		ListaConArreglo<T>::imprimir();
	}
	void operator=( queue other) {
	this->data = other.data;	
	}
};
