//
// Created by Nico on 07/09/2023.
//

#ifndef ECU_METODO_LU_H
#define ECU_METODO_LU_H

#include "metodo_EliminacionGaussiana.h"
#include "sistEcu.h"
using namespace std;


void LUdescomponer(sistEcu sistema, sistEcu &U, sistEcu &L);


vector<double> getY(sistEcu L, sistEcu &sistema);
vector<double> getX(sistEcu U);



void LUdescomponer(sistEcu sistema, sistEcu &U, sistEcu &L){

    vector<double> multiplos;


    for(int i = 0; i < sistema.getFilas(); i++)
    {
        for(int j = i+1; j < sistema.getFilas(); j++)
        {
            double multiplo = -1 * sistema.getCoeficiente(j,i) / sistema.getCoeficiente(i,i);
            multiplos.emplace_back(-1 * multiplo);

            sistema.setTerminoI(j,sistema.getTerminoI(j) + sistema.getTerminoI(i) * multiplo);
            sistema.setCoe(j,i,0.);


            for(int k = i + 1; k < sistema.getColumnas(); k++)
            {
                sistema.setCoe(j,k, sistema.getCoeficiente(j,k) + sistema.getCoeficiente(i,k) * multiplo);
            }
        }
    }


    for (int i = 0; i < sistema.getFilas(); ++i) {
        for (int j = 0; j < sistema.getColumnas(); ++j) {
            U.setCoe(i,j,sistema.getCoeficiente(i,j));
        }
    }

    int contador = 0;

    for (int i = 0; i < sistema.getFilas(); ++i) {
        for (int j = 0; j < sistema.getColumnas(); ++j) {

            if(i == j)
            {
                L.setCoe(i,j,1);
            }else if(j > i)
            {
                L.setCoe(i,j,0);
            }else{
                L.setCoe(i,j,multiplos[contador]);
                contador++;
            }

        }
    }


}


vector<double> getY(sistEcu L, sistEcu &sistema)
{
    vector<double> Y;
    double sum;

    for (int i = 0; i < L.getFilas(); ++i) {
        Y.emplace_back(0.);
    }

    for(int i = 0; i < L.getFilas(); i++)
    {
        sum = 0;

        for (int j = 0; j < i; ++j) {
            if(L.getCoeficiente(i,j) != 0.){
                sum += L.getCoeficiente(i,j) * Y[j];
            }
        }
        
        Y[i] = sistema.getTerminoI(i) - sum;
    }
    return Y;
}

vector<double> getX(sistEcu U)
{
    vector<double> x;
    double sum;


    for (int i = 0; i < U.getFilas(); ++i) {
        x.emplace_back(0.);
    }


    for(int i = U.getFilas()-1; i > -1; i--)
    {

        sum = 0.;
        for(int j = i + 1; j < U.getColumnas(); j++)
        {
            if(!(U.getCoeficiente(i,j) == 0. || x[j] == 0))
            {
                sum += U.getCoeficiente(i,j) * x[j];
            }
        }

        if(U.getCoeficiente(i,i) == 0){
            throw runtime_error("333");
        }else{
            x[i] = (U.getTerminoI(i) - sum) / U.getCoeficiente(i,i);
        }

    }

    return x;
}

#endif //ECU_METODO_LU_H
