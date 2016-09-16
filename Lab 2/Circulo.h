
#include "Figura.h"
#ifndef CIRCULO_H
#define CIRCULO_H

class Circulo : public Figura{
public:
    Circulo();
    Circulo(std::string , std::string);
    Circulo(const Circulo& orig);
    void Perimetro();
    void Area();
    double radio; 
    void * operator ~();
    void * operator !();
    virtual ~Circulo();
private:

};

#endif /* CIRCULO_H */

