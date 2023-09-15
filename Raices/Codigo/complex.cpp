//
// Created by nico on 26/08/23.
//

#include "complex.h"

complex::complex() {
    x = 0;
    y = 0;
}

complex::complex(float _x, float _y) {
    x = _x;
    y = _y;
}

float complex::getY() {
    return y;
}

float complex::getX() {
    return x;
}

complex complex::sumar(complex z1, complex z2) {
    return complex(z1.getX() + z2.getX(), z1.getY() + z2.getY());
}

void complex::mostrar() {
    std::cout<<x<<" + i "<<y<<std::endl;
}

complex complex::restar(complex z1, complex z2) {
    return complex(z1.getX() - z2.getX(), z1.getY() - z2.getY());
}

complex complex::multiplicar(complex z1, complex z2) {
    return complex(z1.getX() * z2.getX() - z1.getY() * z2.getY(), z1.getX() * z2.getY() + z1.getY() * z2.getX());
}

complex complex::cociente(complex z1, complex z2) {
    return complex( (z1.getX() * z2.getX() + z1.getY() * z2.getY() ) / (pow(z2.getX(), 2) + pow(z2.getY(), 2)), (-1 * z1.getX() * z2.getY() + z1.getY() * z2.getX()) / (pow(z2.getX(), 2) + pow(z2.getY(), 2)) );
}

complex complex::potencia(complex z1, int n) {
    if(n == 0)
    {
        return complex(1,0);
    }else{
        return multiplicar(z1, potencia(z1, n - 1));
    }
}
