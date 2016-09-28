/* 
 * @File:   Triangulo.cpp
 * @author: jose
 * 
 * @date September 6, 2016
 * 
 */
#include "Fraccion.h"


/**
 * @brief Me crea un objeto tipo fraccion.
 * Me crea una fraccion con los numeros ingresados por el usuario
 * 
 * @param D Es un puntero de tipo int de tamaño dos para guardar el denominador y el numerador.
 * 
 */
Fraccion::Fraccion() {
    frac = new int(2);
    int in;
    std::cout << "Ingrese el numerador: " << std::endl;
    std::cin >> in;
    frac[1] = in;
    std::cout << "Ingrese el denominador: " << std::endl;
    std::cin >> in;
    frac[2] = in;
}
/**
 * @brief Me crea un objeto tipo fraccion.
 * Constructor en el cual el usuario ingresa el numerador y denominador de manera directa.
 * @param a Numerador de la fraccion
 * @param b Denominador de la fraccion
 */
Fraccion::Fraccion(int a, int b) {
    frac = new int(2);
    frac[1] = a; 
    frac[2] = b;
    
}
/**
 * @brief Se suma ambas fracciones.
 * @param other La otra fraccion a sumarse con la primera.
 */
Fraccion Fraccion::operator +(const Fraccion& other) {
    Fraccion result(0,0);
    result.frac[1] = other.frac[2]*this->frac[1] + this->frac[2]*other.frac[1]; 
    result.frac[2] = this->frac[2]*other.frac[2];
    return result;
    ~result;
    return result;
    
}
 /**
  * @brief Me resta ambas fracciones.
  * @param other La otra fraccion a restarse con la primera.
  */
Fraccion Fraccion::operator -(const Fraccion& other) {
    Fraccion result(0,0);
    result.frac[1] = other.frac[2]*this->frac[1] - this->frac[2]*other.frac[1]; 
    result.frac[2] = this->frac[2]*other.frac[2];
    ~result;
    return result;
 }
/**
 * @brief Me multiplica ambas fracciones
 * @param other La otra fraccion a multiplicarse con la primera
 */
Fraccion Fraccion::operator *(const Fraccion& other) {
    Fraccion result(0,0);
    result.frac[1] = other.frac[1]*this->frac[1];
    result.frac[2] = other.frac[2]*this->frac[2];
    ~result;
    return result;
 }
 /**
  * @brief Me divide ambas fracciones
  * @param other La otra fraccion a dividirse con la primera
  */
Fraccion Fraccion::operator /(const Fraccion& other) {
    Fraccion result(0,0);
    result.frac[1] = this->frac[1]*other.frac[2];
    result.frac[2] = this->frac[2]*other.frac[1];
    ~result;
    return result;
    
 }
 /**
  * @brief Sobrecarga que muestra la fraccion deseada.
  */
 void Fraccion::operator ~() {
     std::cout << this->frac[1] << "/" << this->frac[2];
     
 }

     
 
Fraccion::Fraccion(const Fraccion& orig) {
}

Fraccion::~Fraccion() {
    delete this->frac;
    
}

