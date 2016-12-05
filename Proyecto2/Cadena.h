/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cadena.h
 * Author: jose
 *
 * Created on November 19, 2016, 9:37 PM
 */

#ifndef CADENA_H
#define CADENA_H
#include <string>
#include <iostream>
#include <time.h>
class Cadena {
public:
    Cadena();
    int longitud;
    std::string ADN;
    Cadena(int);
    Cadena(std::string);
    Cadena(const Cadena& orig);
    virtual ~Cadena();
    void findPVM(int);
    double** PVM;
    double** MP = 0x0;
    Cadena& operator+=( Cadena other);
    void add( Cadena& other);
    void imprimir();
    std::string motif();
    double ** matrizPesos();
    std::string cadenaComun();
    std::string cadenaDegenerada();
    
private:
    static const std::string letras[4];

};


#endif /* CADENA_H */

