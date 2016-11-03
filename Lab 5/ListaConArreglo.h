
#ifndef LISTACONARREGLO_H
#define LISTACONARREGLO_H
#include <iostream>
#include "Lista.h"


template <typename T>

class ListaConArreglo : public Lista<T> {
public:
    ListaConArreglo(){
    data = 0;
    tam = 0;
    ultimo = -1;
    }
    
    ListaConArreglo(int N) {
    this->data = new T[N];
    tam = N;
    ultimo = tam - 1;
    }
    ListaConArreglo(const ListaConArreglo& orig) {

    }
    ~ListaConArreglo() {

    }


    void agregar(T e) {
        if (data == 0) {
        data = new T[1];
        tam = 1;
        ultimo = 0;
        data[0] = e;
    } else {
        if (ultimo == tam - 1) {
            T* temp = new T[tam * 2];
            for (int i = 0; i < tam; i++) {
                temp[i] = data[i];
            }
            ultimo++;
            tam++;
            temp[ultimo] = e;
            delete data; // ojo con lss deletes
            data = temp;
        } else {
            ultimo++;
            tam++;
            data[ultimo] = e;
        }
    }
    }
  
    T eliminar(T e) {
        int k = buscar(e);
	T* temp = new T[1];
	temp[0] = data[0];

        eliminarK(k);
	return temp[0];

    }
    void eliminarK(int k) {
         for (int i = k; i < tam - 1; i++) {
        data[i] = data[i + 1];
    }
        tam--;
        ultimo--;
    }

    int buscar(T e) {
        for (int i = 0; i < tam; i++) {
        if (data[i] == e) {
            return i;
       }

    }
    return -1;
    } 

    T siguienteK(int k) {
        if (k + 1 < tam) {
        return data[k + 1];
    } else {
       // return -1;
    }

    }
    T anteriorK(int k) {
        if (k - 1 >= 0) {
        return data[k - 1];
    } else {
        //return -1;
    }
    }

    T recuperar(int k) {
        return data[k];
    }

    void imprimir() {
        for (int i = 0; i < tam; i++) {
        std::cout << data[i] << "\t";
    }
    std::cout << std::endl;
    }

    void clear() {
    	data = 0;
	tam = 0;
	ultimo = -1;
    }
    int tam;
    int ultimo;
    T* data;
private:
    
     //almacenar los elementos
};

#endif /* LISTACONARREGLO_H */

