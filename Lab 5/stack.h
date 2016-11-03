#include "ListaConArreglo.h"

template <typename T>

class stack: public ListaConArreglo<T> {
public:
	stack() {

	}
	void pop() {
		ListaConArreglo<T>::eliminar(this->data[this->ultimo]);
	}
	void push(T a) {
		ListaConArreglo<T>::agregar(a);
	}
	void imp() {
		ListaConArreglo<T>::imprimir();
	}
	bool isEmpty() {
		if (this->tam == 0) {
			return true;
		}
		return false;
	}
	int size() {
		return this->tam;
	}
	void clean() {
		for (int i = 0; i < this->tam ; i++) {
		this->data[i] = 0;
	}
	}
	void nuevo() {
		//stack::ListaConArreglo();
	}
	T top() {
		return this->data[this->ultimo];
	} 
};
