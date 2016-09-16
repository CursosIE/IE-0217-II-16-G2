

/* 
 * @File:   Triangulo.cpp
 * @author: jose
 * 
 * @date September 6, 2016
 * 
 */

#include "Triangulo.h"

using namespace std;
/**
 * @brief Me crea un triangulo con nombre y color genericos.
 * 
 */
Triangulo::Triangulo() {
    this->nombre = "Moises";
    this->color = "Blanco"; 
    Triangulo::obtenerLados();
    
}
 /**
    * @brief Me crea un triangulo con nombre y color ingresado por el usuario
  * @code
  *  this->nombre = a; 
  *  this->color = b;
  *  Triangulo::obtenerLados();
  * @endcode
    * @param a Nombre del triangulo
    * @param b Color del triangulo
    * 
    */
Triangulo::Triangulo(std::string a, std::string b) {
    this->nombre = a; 
    this->color = b;
    Triangulo::obtenerLados();
    
    
}
/**
    * @brief Obtiene los lado del triangulo (tres lados) y los guarda en los lados de cada triangulo creado (this->lado).
    * 
    * 
    */
void Triangulo::obtenerLados() {
    double l1; 
    double l2;
    double l3;
    std::cout << "Ingrese medida del lado 1:" << std::endl;
    std::cin >> l1;
    std::cout << "Medida lado 2:" << std::endl;
    std::cin >> l2;
    std::cout << "Medida lado 3:" << std::endl;
    cin >> l3;
    this->lado1 = l1; 
    this->lado2 = l2;
    this->lado3 = l3;
    
    
 
     
}
/**
 * @brief Calcula el area del triangulo usando la formula de heron
 * @var P guarda el perimetro del triangulo
 * @var semip Guarda el semiperimetro
 * @var area1 Valor del area calculado con formula de heron.
 * @code
 * double area1 = sqrt(semip*(semip-this->lado1)*(semip-this->lado2)*(semip-this->lado3));
 * @endcode
 */
void Triangulo::Area() {
    
    double p = this->lado1 + this->lado2 + this->lado3 ; 
    double semip = p/2 ; 
    double area1 = sqrt(semip*(semip-this->lado1)*(semip-this->lado2)*(semip-this->lado3));
    if (isnan(area1)) {
        cout << "No se puede calcular el area del triangulo con los valores ingresados utilizando la formula de Heron" << endl;
    }
    this->area = area1;
    
    
}
/**
 * @brief Calcula el perimetro
 * @var per guarda el perimetro del triangulo.
 */
void Triangulo::Perimetro() {
    double per = this->lado1+this->lado2+this->lado3 ;
    this->perimetro = per;
}
/**
 * @brief Muestra los atributos de cada triangulo (nombre, color, lados).
 * @return Informacion
 */
void * Triangulo::operator ~() {
    std::cout << "El nombre del triangulo es: " << this->nombre << std::endl;
    std::cout << "El color de " << this->nombre << " es  " << this->color << std::endl;
    std::cout << "La longitud del los lados son en orden: " << " " << this->lado1 << " " << this->lado2 << " " << this->lado3 << std::endl;
    
}
/**
 * @brief Muestra los resultados de area y perimetro
 * @return Informacion
 */
void * Triangulo::operator !() {
    Triangulo::Area();
    Triangulo::Perimetro();
    std::cout << "El area del triangulo es: " << this->area << std::endl;
    std::cout << "El perimetro es: " << this->perimetro << std::endl;
    
}

Triangulo::Triangulo(const Triangulo& orig) {
}

Triangulo::~Triangulo() {
}

