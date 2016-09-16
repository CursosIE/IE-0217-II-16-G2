#include "Figura.h"
#include "Triangulo.h"
#include "Circulo.h"
#include "Cuadrado.h"

using namespace std;

/**
 * @file main.cpp
 * @author Jose Alberto Barrantes 
 * @date 9 Sep 2016.
 * @brief Main donde se encuentran las pruebas de la clase figura y sus subclases por herencia.
 * 
 * 
 * 
 * 
 */
int main(int argc, char** argv) {
    
    Triangulo* a = new Triangulo("Pato" , "negro"); 
    ~(*a);
   
    !(*a);
    /*Circulo* b = new Circulo();
    Cuadrado* c = new Cuadrado();
    Triangulo* d = new Triangulo();
    Triangulo x;
    ~(*d);
    !(*d);
    ~(*b) ;
    !(*b);
    ~(*c);
    !(*c); */
    
    return 0;
    delete a;
    //delete b;
    //delete c;
    //delete d;
}


