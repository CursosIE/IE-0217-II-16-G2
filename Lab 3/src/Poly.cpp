
/* 
 * @File:   Matrix.cpp
 * @Author: jose
 * 
 * @date September 14, 2016, 2:02 PM
 */
#include "Poly.h"
using namespace std;
/**
 * @brief Me llena el arreglo this->arg con ceros. 
 * Me crea un polinomio vacio de grado 1000.
 */
Poly::Poly() {
    for (int i = 0; i<1000 ; i++) {
        arg[i] = 0;
    }

}
/**
 * @brief Me llena un polinomio con grado ingresado por el usuario en el constructor.
 * @code
 * degree = a+1;
    int add;
    for (int i = 0; i<degree; i++) {
        std::cout << "Ingrese coeficiente : " << i << "  " <<std::endl;
        std::cin >> add;
        arg[i] = add;
    }
 * @endcode
 * @param a Grado a llenar el polinomio.
 */
Poly::Poly(int a) {
    degree = a+1;
    int add;
    for (int i = 0; i<degree; i++) {
        std::cout << "Ingrese coeficiente : " << i << "  " <<std::endl;
        std::cin >> add;
        arg[i] = add;
    }
}
/**
 * @brief Me suma dos polinomios.
 * @code
 *  Poly result;
    for (int i = 0; i<=this->degree; i ++) {
        result.arg[i] += this->arg[i];
    }
    for (int j = 0; j<=other.degree; j++) {
        result.arg[j] += other.arg[j];
    }
 * @endcode
 * 
 * @param other Polinomio a sumar con el primero
 * @return Polinomio de resultado. 
 */
Poly Poly::operator +(const Poly& other) {
    Poly result;
    for (int i = 0; i<=this->degree; i ++) {
        result.arg[i] += this->arg[i];
    }
    for (int j = 0; j<=other.degree; j++) {
        result.arg[j] += other.arg[j];
    }
    result.degree = result.obtenerGrado();
    ~result;
    return result;
}
/**
 * @brief Me imprime un polinomio de algun degree (grado).
 * @code
 *  for (int i=0; i<999; i++)
    {
       if (arg[i] != 0 ) {   
        cout << this->arg[i];
       if (i != 0)
        cout << "x^" << i ;
       
       if (i != this->degree)
        cout << " + ";
       }
    }
 * @endcode
 */
void Poly::operator ~() {
    for (int i=0; i<999; i++)
    {
       if (arg[i] != 0 ) {   
        cout << this->arg[i];
       if (i != 0)
        cout << "x^" << i ;
       
       if (i != this->degree)
        cout << " + ";
       }
    }
    cout << endl;
    
}
/**
 * @brief Me resta dos polinomios
 * @code
 *  Poly result;
    for (int i = 0; i<=this->degree; i ++) {
        result.arg[i] += this->arg[i];
    }
    for (int j = 0; j<=other.degree; j++) {
        result.arg[j] -= other.arg[j];
    }
 * @endcode
 * 
 * @param other Polinimio a restar al primero
 * @return Polinomio respuesta
 */
Poly Poly::operator -(const Poly& other) {
    Poly result;
    for (int i = 0; i<=this->degree; i ++) {
        result.arg[i] += this->arg[i];
    }
    for (int j = 0; j<=other.degree; j++) {
        result.arg[j] -= other.arg[j];
    }
    result.degree = result.obtenerGrado();
    ~result;
    return result;
}
/**
 * @brief Me multiplica dos polinomios
 * @code
 * Poly result;
    for (int i = 0; i<= this->degree; i++)
        for (int j = 0; j<=other.degree; j++) {
            result.arg[i+j] += (this->arg[i] * other.arg[j]); 
        }
 * @endcode
 * @param other Polinomio a multiplicar
 * @return Polinomio respuesta
 */
Poly Poly::operator *(const Poly& other) {
    Poly result;
    for (int i = 0; i<= this->degree; i++)
        for (int j = 0; j<=other.degree; j++) {
            result.arg[i+j] += (this->arg[i] * other.arg[j]); 
        }
    result.degree = result.obtenerGrado();
    ~result;
    return result;
}
/**
 * @brief Me obtiene el grado efectivo de un polinomio. Dato utilizado puramente para impresion.
 * @code
 * int grad = 0;
    for (int i = 0; i<=999; i++) {
        if (this->arg[i]!=0) {
            grad = i; 
        }
    }
    return grad;
 * @endcode
 * @return Entero que muestra el grado efectivo de un polinomio.
 */
int Poly::obtenerGrado() {
    int grad = 0;
    for (int i = 0; i<=999; i++) {
        if (this->arg[i]!=0) {
            grad = i; 
        }
    }
    return grad;
}
/**
 * @brief Me obtiene la derivada de un polinomio.
 * @code 
 * Poly result;
    for (int i = 1; i <= this->degree; i++) {
        result.arg[i-1] = this->arg[i]*i; 
    }
 * @endcode
 * 
 * @return Me devuelve el polinomio derivado de algun polinomio
 */
Poly Poly::operator !() {
    Poly result;
    for (int i = 1; i <= this->degree; i++) {
        result.arg[i-1] = this->arg[i]*i; 
    }
    result.degree = result.obtenerGrado();
    ~result;
    return result;
}

Poly::Poly(const Poly& orig) {
}

Poly::~Poly() {
}

