

/* 
 * @File:   Circulo.cpp
 * @author: jose
 * 
 * @date September 6, 2016
 * 
 */
#include "Circulo.h"

const double PI  =3.141592653589793238463;
/**
 * @brief Me crea un circulo de radio ingresado por el usuario
 * @param rad Valor del radio ingresado por el usuario
 */
Circulo::Circulo() {
    double rad;
    this->color = "Blanco";
    this->nombre = "Marco Polo";
    std::cout << "Ingrese el radio del circulo:" << std::endl;
    std::cin >> rad;
    this->radio = rad;
}
/**
 * @brief Me crea una circulo con nombre y color ingresado por el usuario
 * @code 
 *  this->color = b;
 *  this->nombre = a;
 * @param a nomre del circulo
 * @param b Color del circulo.
 */
Circulo::Circulo(std::string a , std::string b) {
    double rad;
    this->color = b;
    this->nombre = a;
    std::cout << "Ingrese el radio del circulo:" << std::endl;
    std::cin >> rad;
    this->radio = rad;
}

Circulo::Circulo(const Circulo& orig) {
}
/**
 * @brief Calcula el perimetro de un circulo
 * @param Per perimetro del circulo
 */
void Circulo::Perimetro() {
    double Per = 2*PI*this->radio;
    this->perimetro = Per;
    
}
/**
 * @brief Muestra los atributos de cada circulo
 * @return Informacion de los atributos
 */
void * Circulo::operator ~() {
     
    
    std::cout << "El nombre del circulo es: " << this->nombre << std::endl;
    std::cout << "El color de " << this->nombre << " es " << this->color << std::endl;
    std::cout << "El largo del radio de este es: " << this->radio << std::endl;
}
/**
 * @brief Informacion del calculo del area y perimetro del circulo
 * @return Informacion de los calculos
 */

void * Circulo::operator !() {
    Circulo::Area();
    Circulo::Perimetro();
    std::cout << "El area del circulo es: " << this->area << std::endl;
    std::cout << "El perimetro del circulo es: " << this->perimetro << std::endl;
}
/**
 * @brief Calcula el area del circulo
 * @param area Guarda el resultado del area del circulo
 */
void Circulo::Area() {
    double area = PI * (this->radio*this->radio);
    this->area = area;
}

Circulo::~Circulo() {
}

