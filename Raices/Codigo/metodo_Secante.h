//
// Created by nico on 26/08/23.
//

#ifndef EJ1_METODO_SECANTE_H
#define EJ1_METODO_SECANTE_H

#include "iostream"
#include "cmath"
#include "funcion.h"
#include "iomanip"

double secante_encontrarRaiz(double inicio, double limite, double errorPermitido) {
    double Xi = limite;
    double anterior = inicio;
    double raiz = Xi - ( ( funcion(Xi)*( anterior - Xi ) ) / ( funcion(anterior) - funcion(Xi) ) );
    double error = 10;
    int counter = 2;

    cout<<setw(10)<<"i"<<" | "<<setw(10)<<"Xi"<<" | "<<setw(10)<<"f(Xi)"<<" | "<<setw(10)<<"Error abs"<<endl;
    cout<<setw(10)<<"0"<<" | "<<setw(10)<<anterior<<" | "<<setw(10)<<funcion(anterior)<<" | "<<setw(10)<<"-"<<endl;
    cout<<setw(10)<<"1"<<" | "<<setw(10)<<Xi<<" | "<<setw(10)<<funcion(Xi)<<" | "<<setw(10)<<"-"<<endl;



    while (error > errorPermitido) {
        anterior = raiz;
        Xi = Xi - ( ( funcion(Xi)*( anterior - Xi ) ) / ( funcion(anterior) - funcion(Xi) ) );
        raiz = Xi - ( ( funcion(Xi)*( anterior - Xi ) ) / ( funcion(anterior) - funcion(Xi) ) );
        error = abs(anterior - raiz);

        cout<<setw(10)<<counter<<" | "<<setw(10)<<Xi<<" | "<<setw(10)<<funcion(Xi)<<" | "<<setw(10)<<error<<endl;
        counter++;
    }
    cout<<endl;
    return anterior;
}




#endif //EJ1_METODO_SECANTE_H
