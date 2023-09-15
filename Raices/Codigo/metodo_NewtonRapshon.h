//
// Created by nico on 26/08/23.
//

#ifndef EJ1_METODO_NEWTONRAPSHON_H
#define EJ1_METODO_NEWTONRAPSHON_H

#include <iostream>
#include <cmath>
#include "funcion.h"
#include "iomanip"

const double e = 2.71828182845904523536028747135266249775724709369995;

using namespace std;

double funcionD(double x){
    double respuesta;
    /*
     3.1      respuesta = -1 * pow(e,-x) - 1;
     3.2
    respuesta = -0.874 * 2 * x + 1.750;
     3.3     respuesta = 79.35 - 176.18 *  pow(x,1) + 124.8 * pow(x,2) - 34.72 * pow(x,3) + 3.29 * pow(x,4);
    3.4
    respuesta = 1 / x;
     3.5
         respuesta = -1 * pow(x, -2);
    if(x == 0)
    {
        throw std::runtime_error("400");
    }
     */


    respuesta = sin(x) / x + log(x) * cos(x);

    return respuesta;
}



double newtonRapshon_encontrarRaiz(double inicio, double limite, double errorPermitido) {
    double Xi = inicio;
    double anterior = 0;
    double raiz = Xi - (funcion(Xi) / funcionD(Xi));
    double error = 10;

    int counter = 1;

    cout<<setw(10)<<"i"<<" | "<<setw(10)<<"Xi"<<" | "<<setw(10)<<"f(Xi)"<<" | "<<setw(10)<<"f'(Xi)"
            <<" | "<<setw(10)<<"Error abs"<<endl;

    cout<<setw(10)<<"0"<<" | "<<setw(10)<<Xi<<" | "<<setw(10)<<funcion(Xi)<<" | "<<setw(10)<<funcionD(Xi)
        <<" | "<<setw(10)<<"-"<<endl;

    while (error > errorPermitido) {
        anterior = raiz;
        Xi = Xi - (funcion(Xi) / funcionD(Xi));
        raiz = Xi - (funcion(Xi) / funcionD(Xi));
        error = abs(anterior - raiz);

        cout<<setw(10)<<counter<<" | "<<setw(10)<<Xi<<" | "<<setw(10)<<funcion(Xi)<<" | "<<setw(10)<<funcionD(Xi)
            <<" | "<<setw(10)<<error<<endl;
        counter++;
    }

    cout<<endl;
    return anterior;
}




#endif //EJ1_METODO_NEWTONRAPSHON_H
