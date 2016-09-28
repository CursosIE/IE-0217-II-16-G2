/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Matrix.h
 * Author: jose
 *
 * Created on September 14, 2016, 2:02 PM
 */

#ifndef MATRIX_H
#define MATRIX_H
#include<iostream>
#include<cstdlib>
#include<stdexcept>
class Matrix {
public:
    Matrix();
    Matrix(int , int ,int );
    Matrix(const Matrix& orig);
    virtual ~Matrix();
    Matrix(int , int);
    Matrix operator+(const Matrix &other); 
    Matrix operator*(const Matrix& other);
    Matrix operator-(const Matrix& other);
    Matrix operator/(const Matrix& other);
    void operator~();
private:
    int columnas;
    int filas1;
    double** mat; 
};

#endif /* MATRIX_H */

