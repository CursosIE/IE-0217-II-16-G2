/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Poly.h
 * Author: jose
 *
 * Created on September 19, 2016, 2:04 PM
 */
#include<iostream>
#ifndef POLY_H
#define POLY_H

class Poly {
public:
    Poly();
    Poly(int);
    Poly(const Poly& orig);
    virtual ~Poly();
    Poly operator+(const Poly& other);
    Poly operator-(const Poly& other);
    Poly operator*(const Poly& other);
    Poly operator!();
    void operator~();
    int obtenerGrado();
private:
    
    int arg[1000];
    int degree;
};

#endif /* POLY_H */

