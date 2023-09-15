//
// Created by Nico on 05/09/2023.
//

#ifndef ECU_METODO_GAUSSSEIDEL_H
#define ECU_METODO_GAUSSSEIDEL_H

#include "sistEcu.h"
#include "iomanip"

using namespace std;


void algoritmoGaussSeidel(sistEcu sistema, vector<double> &soluciones, double errorPermitido);




void algoritmoGaussSeidel(sistEcu sistema, vector<double> &soluciones, double errorPermitido)
{
    double sum = 0.;
    double errorActual = 10.;
    vector<double> errorA;
    vector<double> anterior;

    for (int i = 0; i < soluciones.size(); ++i) {
        soluciones[i] = 0.;
        anterior.emplace_back(0.);
        errorA.emplace_back(0);
    }

    cout<<setw(15)<<"i"<<" | ";
    for (int i = 0; i < soluciones.size(); ++i) {
        cout<<setw(15)<<"X"<<i<<"| "<<setw(15)<<"E"<<i<<"| ";
    }
    cout<<endl;
    int contador = 0;

    while (errorActual > errorPermitido)
    {

        for (int i = 0; i < sistema.getFilas(); ++i) {

            for (int j = 0; j <sistema.getColumnas(); ++j) {
                if(j != i)
                {
                    sum += sistema.getCoeficiente(i,j) * soluciones[j];
                }
            }

            if(sistema.getCoeficiente(i,i) == 0.)
            {
                throw runtime_error("333");
            }


            soluciones[i] = ( sistema.getTerminoI(i) - sum) ;
            soluciones[i] = soluciones[i] / sistema.getCoeficiente(i,i);

            errorActual = abs(soluciones[i] - anterior[i]);
            errorA[i] = errorActual;
            anterior[i] = soluciones[i];
            sum = 0.;
        }
        cout<<setw(15)<<contador<<" | ";
        for (int i = 0; i < soluciones.size(); ++i) {
            cout<<setw(15)<<soluciones[i]<<" | "<<setw(15)<<errorA[i]<<" | ";
        }
        cout<<endl;
        contador++;
    }

}


#endif //ECU_METODO_GAUSSSEIDEL_H
