#ifndef LISTA_H
#define LISTA_H

template <typename data>

class Lista { //lista de doubles
public:
    Lista() {
    }
    Lista(const Lista& orig) {

    }
    virtual ~Lista() {

    }

    virtual void agregar(data e) = 0;
    virtual data eliminar(data e) = 0;
    virtual void eliminarK(int k) = 0;

    virtual int buscar(data e) = 0;

    virtual data siguienteK(int k) = 0;
    virtual data anteriorK(int k) = 0;

    virtual data recuperar(int k) = 0;
    virtual void imprimir() = 0;
private:

};

#endif /* LISTA_H */

