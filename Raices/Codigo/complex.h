//
// Created by nico on 26/08/23.
//

#ifndef EJ1_COMPLEX_H
#define EJ1_COMPLEX_H

#include "iostream"
#include "math.h"

class complex {
private:
    float x;
    float y;
public:
    complex();
    complex(float _x, float _y);

    float getY();
    float getX();

    void mostrar();


    complex sumar(complex z1, complex z2);
    complex restar(complex z1, complex z2);
    complex multiplicar(complex z1, complex z2);
    complex cociente(complex z1, complex z2);
    complex potencia(complex z1, int n);

};


#endif //EJ1_COMPLEX_H
