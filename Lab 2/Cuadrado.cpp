

/* 
 * @File:   Cuadrado.cpp
 * @author: jose
 * 
 * @date September 6, 2016
 * 
 */

#include "Cuadrado.h"
/**
 * @brief Me crea un cuadrado con un lado ingresado por el usuario.
 * El constructor me genera un nombre y color genericos dado que en este caso no se le especifico algun nombre o color
 * @param l variable temporal para guardar el lado.
 */
Cuadrado::Cuadrado() {
    this->color = "Blanco";
    this->nombre = "Salomon :D";
    double l;
    std::cout << "Ingrese el largo de lado del cuadrado:" << std::endl;
    std::cin >> l;
    this->lado = l;
}
/**
 * @brief Genera un cuadrado con nombre y color ingresado por el usuario con una longitud del lado ingresado por el usuario.
 * 
 * @param a Guarda el nombre temporalmente 
 * @param b Guarda el color temporalmente
 * @code
 *  this->color = b; 
 *  this->nombre = a;
 * @endcode
 */
Cuadrado::Cuadrado(std::string a, std::string b) {
    this->color = b; 
    this->nombre = a;
    double l;
    std::cout << "Ingrese el largo de lado del cuadrado:" << std::endl;
    std::cin >> l;
    this->lado = l;
}

Cuadrado::Cuadrado(const Cuadrado& orig) {
}

/**
 * @brief Funcion para calcular el area del cuadrado
 * @code
 * double area = this->lado * this->lado ; 
 * @endcode
 * @param area Variable temporal del metodo para el area del cuadrado
 */
void Cuadrado::Area() {
    double area = this->lado * this->lado ; 
    this->area = area; 
}

/**
 *@brief Funcion para calcular el perimetro del cuadrado
 * @param Per guarda el resultado del calculo del perimetro.
 * 
 */
void Cuadrado::Perimetro() {
    double Per = this->lado * 4;
    this->perimetro = Per;
}
/**
 * @brief Muestra las propiedades del cuadrado
 * @return No retorna nada ademas de imprimir la informacion
 */
void * Cuadrado::operator ~() {
    std::cout << "El nombre del cuadrado es:" << this->nombre << std::endl;
    std::cout << "El color de " << this->nombre << "es  " << this->color << std::endl;
    std::cout << "La longitud del lado es: " << this->lado << std::endl;
    
}
/**
 * @brief Muestra el resultado del calculo de area y perimetro.
 * @return No retorna nada ademas de imprimir la informacion.
 */
void * Cuadrado::operator !() {
    Cuadrado::Area();
    Cuadrado::Perimetro();
    std::cout << "El area del cuadrado es: " << this->area << std::endl;
    std::cout << "El perimetro es: " << this->perimetro << std::endl;
    
}

Cuadrado::~Cuadrado() {
}

