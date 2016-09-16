
/** 
 * @File:   Cuadrado.h
 * @author: jose
 *
 * @date September 6, 2016
 * @param lado guarda el lado de cada cuadrado creado
 * 
 * 
 */
#include "Figura.h"
#ifndef CUADRADO_H
#define CUADRADO_H

class Cuadrado : public Figura {
public:
    Cuadrado();
    Cuadrado(std::string , std::string); 
    Cuadrado(const Cuadrado& orig);
    double lado;
    void Area();
    void Perimetro();
    void * operator ~();
    void * operator !();
    virtual ~Cuadrado();
private:

};

#endif /* CUADRADO_H */

