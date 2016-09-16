

/* 
 * @File:   Triangulo.h
 * @author: jose
 *
 * @date September 6, 2016
 * @param lado1 
 * @param lado2
 * @param lado3
 */

#ifndef TRIANGULO_H
#define TRIANGULO_H
#include "Figura.h"



class Triangulo : public Figura {
public:
    
    
    Triangulo();
    Triangulo(const Triangulo& orig);
   
    Triangulo(std::string , std::string);
    
    void obtenerLados();
    double lado1; 
    double lado2;
    double lado3;
    void Area();
    void Perimetro();
    void * operator ~();
    void * operator !();

    virtual ~Triangulo();
private:

};

#endif /* TRIANGULO_H */

