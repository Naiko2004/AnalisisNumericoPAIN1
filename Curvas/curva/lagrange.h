//
// Created by nico on 13/09/23.
//

#ifndef CURVA_LAGRANGE_H
#define CURVA_LAGRANGE_H

#include "vector"
#include "iostream"
#include "polinomio.h"

polinomio polinomiosLagrange(vector<double> Xi, vector<double> Yi);








polinomio polinomiosLagrange(vector<double> Xi, vector<double> Yi)
{
    vector<polinomio> Lagrange;
    polinomio base(0);
    base.setCoeficiente(1,0);
    double divisor = 1;

    for (int i = 0; i < Xi.size(); ++i) {
        Lagrange.emplace_back(base);

        for (int j = 0; j < Xi.size(); ++j) {
            if(j != i)
            {
                polinomio aux(Xi[j]);
                Lagrange[i] = base.multiplicar(Lagrange[i],aux);
                divisor *= (Xi[i] - Xi[j]);
            }
        }
        Lagrange[i].dividirCoeficientes(divisor);
        cout<<"L"<<i<<"(x) = ";
        Lagrange[i].imprimir();
        divisor = 1;
    }
    cout<<endl;

    cout<<"f"<<Xi.size()<<"(X) = ";
    for (int i = 0; i < Lagrange.size(); ++i) {
        cout<<"L"<<i<<"(x) * "<<Yi[i];
        if(i != Lagrange.size()-1)
        {
            cout<<" + ";
        }
    }
    cout<<endl;

    polinomio resultante( (int)Xi.size() );

    for (int i = 0; i < Lagrange.size(); ++i) {
        polinomio aux(0);
        aux.setCoeficiente(Yi[i],0);
        aux = aux.multiplicar(aux, Lagrange[i]);

        resultante.sumar(resultante, aux);
    }

    resultante.simplificar();
    cout<<"f"<<Xi.size()<<"(X) = ";
    resultante.imprimir();

    return resultante;

}


#endif //CURVA_LAGRANGE_H
