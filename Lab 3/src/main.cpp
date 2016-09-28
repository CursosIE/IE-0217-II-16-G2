
#include <cstdlib>
#include "Fraccion.h"
#include "Matrix.h"
#include "Calculadora.h"
#include "Poly.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Matrix a;
    Matrix b;
    Calculadora<Matrix> calc1;
    Calculadora<Fraccion> calc2;
    calc1.add(a,b);
    
    
  
    return 0;
}

