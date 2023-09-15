//
// Created by Nico on 31/08/2023.
//

#ifndef ECU_METODO_ELIMINACIONGAUSSIANA_H
#define ECU_METODO_ELIMINACIONGAUSSIANA_H

#include "sistEcu.h"

using namespace std;

void triangular(sistEcu &sistema);
void sustitucionAtras(sistEcu sistema, vector<double> &soluciones);



void triangular(sistEcu &sistema)
{
    for(int i = 0; i < sistema.getFilas(); i++)
    {
        for(int j = i+1; j < sistema.getFilas(); j++)
        {
            sistema.anularFila(j, i, i);

        }
    }
}

void sustitucionAtras(sistEcu sistema, vector<double> &soluciones)
{
    int size = sistema.getFilas();

    double sum = 0.;

    for(int i = size - 1; i > -1; i--)
    {
        for(int j = i + 1; j < size; j++)
        {
            sum += sistema.getCoeficiente(i,j) * soluciones[j];
        }
        if(sistema.getTerminoI(i) == 0)
        {
            soluciones[i] = 0.;
        }else if(sistema.getCoeficiente(i,i) == 0){
            throw runtime_error("333");
        }else{
            soluciones[i] = ( sistema.getTerminoI(i) - sum)/ sistema.getCoeficiente(i,i);
        }

        sum = 0.;
    }

}


#endif //ECU_METODO_ELIMINACIONGAUSSIANA_H
