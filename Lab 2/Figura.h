/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Figura.h
 * Author: jose
 *
 * Created on September 6, 2016, 2:29 PM
 */

#ifndef FIGURA_H
#define FIGURA_H
#include <iostream>
#include <string.h>
#include <cmath>

class Figura {
public:
    Figura();
    Figura(const Figura& orig);
    virtual ~Figura();
    std::string nombre; 
    std::string color; 
    double area;
    double perimetro;
    
    virtual void Area() = 0;
    virtual void Perimetro() = 0;
private:

};

#endif /* FIGURA_H */

