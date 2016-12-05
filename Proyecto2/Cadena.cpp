/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cadena.cpp
 * Author: jose
 * 
 * Created on November 19, 2016, 9:37 PM
 */

#include "Cadena.h"

Cadena::Cadena() {
   
}

Cadena::Cadena(int size) {
    MP = new double*[size];
    for (int i=0; i < size ; i++) {
        MP[i] = new double[4];
        for (int j=0; j < 4 ; j++) {
             MP[i][j] = 0;
        }
    }
    longitud = size;
    
}

Cadena::Cadena(std::string in) {
    int i;
    longitud = in.length();
    ADN = in;
    MP = new double*[in.length()];
    for (int i=0; i < in.length() ; i++) {
        MP[i] = new double[4];
        for (int j=0; j < 4 ; j++) {
             MP[i][j] = 0;
        }
    }
    
    for (i=0 ; i<in.length() ; i++) {
        if (in[i]=='T') {
            MP[i][3] = 1;     
        }
        if (in[i]=='C') {
            MP[i][1] = 1;
        }
        if (in[i]=='A') {
            MP[i][0] = 1;
        }
        if (in[i]=='G') {
            MP[i][2] = 1;
        }
        
    }
    
}

Cadena::Cadena(const Cadena& orig) {
}

Cadena::~Cadena() {
    delete this->PVM;
    
    //delete this->MP;
  
   
}

void Cadena::add( Cadena& other) {
    for(int w = 0; w <this->longitud-1  ; w++ ){
        for(int z =0 ; z<4 ; z++) {
            this->MP[w][z] += other.MP[w][z];
        }
   }
}

Cadena& Cadena::operator +=(Cadena other) {
    for(int w = 0; w <this->longitud  ; w++ ){
        for(int z =0 ; z<4 ; z++) {
            this->MP[w][z] += other.MP[w][z];
            std::cout << MP[w][z] << std::endl;
        }
   }
}

void Cadena::imprimir() {
    std::cout << ADN << std::endl;
}

void Cadena::findPVM(int amount) {
    PVM = new double*[this->longitud];
    for(int w = 0; w <this->longitud  ; w++ ){
        PVM[w] = new double[4];
        for(int z =0 ; z<4; z++) {
            this->PVM[w][z] = this->MP[w][z]/amount ;
        }
    }
    
}



std::string Cadena::motif() {
    std::string motif;
    std::string patterns[100];
    double temp = 0.35;
    int i = 0;
    bool hayComun = false;
    std::string letraComun;
    int F = 0;
    for(int w = 0; w <this->longitud  ; w++ ){
        for(int z =0 ; z<4 ; z++) {
            if(PVM[w][z] > temp) {
                letraComun = this->letras[z];
                    if(PVM[w][z]>temp)
                        temp=PVM[w][z];
                
                hayComun = true;   
            }  else {
                
            }
        }   
        if(hayComun) {
            motif += letraComun;
            temp = 0.35;
            hayComun = false;
            patterns[F] = motif;
            F++;
        }
        else {
            motif.clear();
        }
    }
    int where;
    int size;
    for(int k = 0 ; k < 100 ; k++) {
        if(patterns[k].length() >= size) {
            size = patterns[k].length();
            where = k;
        }
    }
    std::cout << patterns[where] << std::endl;
    return patterns[where];
}

std::string Cadena::cadenaComun() {
    std::string motif;
    std::string patterns[100];
    double temp = 0;
    int i = 0;
    bool hayComun = false;
    std::string letraComun;
    int F = 0;
    for(int w = 0; w <this->longitud-1 ; w++ ){
        for(int z =0 ; z<4 ; z++) {
            if(PVM[w][z] >= temp) {
                letraComun = this->letras[z];
                    if(PVM[w][z]>temp)
                        temp=PVM[w][z];
                
                hayComun = true;   
            }  else {
                
            }
        }   
        if(hayComun) {
            motif += letraComun;
            temp = 0;
            patterns[F] = motif;
            F++;
        }
        else {
            motif.clear();
        }
    }
    int where;
    int size;
    for(int k = 0 ; k < 100 ; k++) {
        if(patterns[k].length() >= size) {
            size = patterns[k].length();
            where = k;
        }
    }
    std::cout << patterns[where] << std::endl;
    return patterns[where];
}

double** Cadena::matrizPesos() {
    return this->PVM;
}

std::string Cadena::cadenaDegenerada() {
    std::string motif;
    std::string patterns[100];
    double temp = 0.5;
    int i = 0;
    bool hayComun = true;
    std::string letraComun;
    int F = 0;
    for(int w = 0; w <this->longitud-1 ; w++ ){
        for(int z =0 ; z<4 ; z++) {
            if(PVM[w][z] > temp) {
                letraComun = this->letras[z];
                    if(PVM[w][z]>temp)
                        temp=PVM[w][z];
                
                hayComun = true;   
            }   else { 
                if(PVM[w][0] == PVM[w][2]) {
                    letraComun = "R";
                    hayComun = true;
                    
                }
                if(PVM[w][2]==PVM[w][1] ) {
                    letraComun = "S";
                    hayComun = true;
                }
                if(PVM[w][0]==PVM[w][1]) {
                    letraComun = "M";
                }
                if(PVM[w][0]==PVM[w][1]==PVM[w][3]) {
                    letraComun = "H";
                }
                if(PVM[w][2]==PVM[w][1]==PVM[w][3]) {
                    letraComun = "B";
                }
                if(PVM[w][0]==PVM[w][1]==PVM[w][2]) {
                    letraComun = "V";
                }
                if(PVM[w][0]==PVM[w][2]==PVM[w][3]) {
                    letraComun = "D";
                }
                if(PVM[w][0]==PVM[w][2]==PVM[w][3]==PVM[w][1]) {
                    letraComun = "N";
                }
                
            }
        }   
        if(hayComun) {
            motif += letraComun;
            temp = 0;
            patterns[F] = motif;
            F++;
        }
        else {
            motif.clear();
        }
    }
    int where;
    int size;
    for(int k = 0 ; k < 100 ; k++) {
        if(patterns[k].length() >= size) {
            size = patterns[k].length();
            where = k;
        }
    }
    std::cout << patterns[where] << std::endl;
    return patterns[where];
}