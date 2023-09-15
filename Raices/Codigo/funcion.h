//
// Created by nico on 08/08/23.
//

#ifndef EJ1_FUNCION_H
#define EJ1_FUNCION_H
#include "complex.h"
#include "iostream"
#include "limits"
#include "cmath"

using namespace std;

double funcion(double x);
double guncion(double x);
double guncionP(double x);
complex compleja(float x, float y);


inline double fabs(double a);
double potencia(double base, double exp);
double nth_root(double A, int n, unsigned int lim_iteraciones);

void mostrarArray(double array[], int size);

void iniciarArray(double array[], int size);




#endif //EJ1_FUNCION_H
