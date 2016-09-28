
#ifndef FRACCION_H
#define FRACCION_H
#include<iostream>
#include<cstdlib>
class Fraccion {
public:
    Fraccion();
    Fraccion(int , int);
    int *frac;
    Fraccion(const Fraccion& orig);
    Fraccion operator+(const Fraccion& other);
    Fraccion operator-(const Fraccion& other);
    Fraccion operator*(const Fraccion& other);
    Fraccion operator/(const Fraccion& other);
    void operator~();
    
    virtual ~Fraccion();
private:

};

#endif /* FRACCION_H */

