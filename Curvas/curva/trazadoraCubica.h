//
// Created by nico on 14/09/23.
//

#ifndef CURVA_TRAZADORACUBICA_H
#define CURVA_TRAZADORACUBICA_H

#include "polinomio.h"
#include "iostream"
#include "vector"
using namespace std;

vector<polinomio> trazadoraCubicaNatural(vector<double> &Xi, vector<double> &Yi);
vector<polinomio> trazadoraCubicaCondicionada(vector<double> &Xi, vector<double> &Yi, double derivadaXo, double  derivadaXn);


vector<polinomio> trazadoraCubicaNatural(vector<double> &Xi, vector<double> &Yi) {
    vector<double> Hj;

    for (int i = 0; i < Xi.size() - 1; ++i) {
        Hj.emplace_back(Xi[i + 1] - Xi[i]);
    }

    vector<double> Alphaj;

    for (int i = 0; i < Xi.size(); ++i) {
        Alphaj.emplace_back(0);
    }

    for (int i = 1; i < Xi.size() - 1; ++i) {
        Alphaj[i] = (3. * (Yi[i + 1] - Yi[i]) / Hj[i]) - (3. * (Yi[i] - Yi[i - 1]) / Hj[i - 1]);
    }

    vector<double> Lj;
    vector<double> MuJ;
    vector<double> Zj;


    for (int i = 0; i < Xi.size(); ++i) {
        Lj.emplace_back(0);
    }

    for (int i = 0; i < Xi.size(); ++i) {
        MuJ.emplace_back(0);
    }
    for (int i = 0; i < Xi.size(); ++i) {
        Zj.emplace_back(0);
    }



    Lj[0] = 1;
    MuJ[0] = 0;
    Zj[0] = 0;

    for (int i = 1; i < Xi.size() - 1; ++i) {
        Lj[i] = 2. * (Xi[i + 1] - Xi[i - 1]) - Hj[i - 1] * MuJ[i - 1];
        MuJ[i] = Hj[i] / Lj[i];
        Zj[i] = (Alphaj[i] - Hj[i - 1] * Zj[i - 1]) / Lj[i];
    }

    vector<double> Ci;

    for (int i = 0; i < Xi.size(); ++i) {
        Ci.emplace_back(0);
    }

    Lj[Lj.size() - 1] = 1;
    Zj[Zj.size() - 1] = 0;
    Ci[Ci.size() - 1] = 0;

    vector<double> Bi;
    vector<double> Di;


    for (int i = 0; i < Xi.size(); ++i) {
        Bi.emplace_back(0);
    }

    for (int i = 0; i < Xi.size(); ++i) {
        Di.emplace_back(0);
    }

    for (int i = Xi.size() - 2; i > -1; --i) {
        Ci[i] = Zj[i] - MuJ[i] * Ci[i + 1];
        Bi[i] = (Yi[i + 1] - Yi[i]) / Hj[i] - (Hj[i] * (Ci[i + 1] + 2. * Ci[i])) / 3.;
        Di[i] = (Ci[i + 1] - Ci[i]) / (3. * Hj[i]);
    }


    vector<polinomio> resultados;

    for (int i = 0; i < Xi.size()-1; ++i) {
        resultados.emplace_back(0);
    }

    for (int j = 0; j < Xi.size()-1; ++j) {


        vector<polinomio> Polinomios;
        vector<double> coeficiente;

        coeficiente.emplace_back(Yi[j]);
        coeficiente.emplace_back(Bi[j]);
        coeficiente.emplace_back(Ci[j]);
        coeficiente.emplace_back(Di[j]);

        for (double i : coeficiente) {
            polinomio aux(0);
            aux.setCoeficiente(i,0);
            Polinomios.emplace_back(aux);
        }

        for (int i = 0; i < Polinomios.size(); ++i) {
            for (int k = 1; k < i+1; ++k) {
                polinomio aux(Xi[j]);

                Polinomios[i] = aux.multiplicar(Polinomios[i], aux);
            }
            resultados[j].sumar(resultados[j],Polinomios[i]);
        }
    }

    return resultados;
}


vector<polinomio> trazadoraCubicaCondicionada(vector<double> &Xi, vector<double> &Yi, double derivadaXo, double  derivadaXn)
{
    vector<double> Hj;

    for (int i = 0; i < Xi.size() - 1; ++i) {
        Hj.emplace_back(Xi[i + 1] - Xi[i]);
    }

    vector<double> Alphaj;

    for (int i = 0; i < Xi.size(); ++i) {
        Alphaj.emplace_back(0);
    }

    Alphaj[0] = 3 * (Yi[1] - Yi[0]) / Hj[0]  - 3 * derivadaXo;

    Alphaj[Alphaj.size() - 1]  = 3 * derivadaXn - 3 * (Yi[Yi.size() - 1] - Yi[Yi.size() - 2]) / Hj[Hj.size() - 2];

    for (int i = 1; i < Xi.size() - 1; ++i) {
        Alphaj[i] = (3. * (Yi[i + 1] - Yi[i]) / Hj[i]) - (3. * (Yi[i] - Yi[i - 1]) / Hj[i - 1]);
    }

    vector<double> Lj;
    vector<double> MuJ;
    vector<double> Zj;


    for (int i = 0; i < Xi.size(); ++i) {
        Lj.emplace_back(0);
    }

    for (int i = 0; i < Xi.size(); ++i) {
        MuJ.emplace_back(0);
    }
    for (int i = 0; i < Xi.size(); ++i) {
        Zj.emplace_back(0);
    }



    Lj[0] = 2 * Hj[0];
    MuJ[0] = 0.5;
    Zj[0] = Alphaj[0] / Lj[0];

    for (int i = 1; i < Xi.size() - 1; ++i) {
        Lj[i] = 2. * (Xi[i + 1] - Xi[i - 1]) - Hj[i - 1] * MuJ[i - 1];
        MuJ[i] = Hj[i] / Lj[i];
        Zj[i] = (Alphaj[i] - Hj[i - 1] * Zj[i - 1]) / Lj[i];
    }

    vector<double> Ci;

    for (int i = 0; i < Xi.size(); ++i) {
        Ci.emplace_back(0);
    }

    Lj[Lj.size() - 1] = Hj[Hj.size() - 2] * (2 - MuJ[MuJ.size() - 2]);
    Zj[Zj.size() - 1] = ( Alphaj[Alphaj.size() - 1] - Hj[Hj.size() - 2] * Zj[Zj.size()-2] ) / Lj[Lj.size() - 1];
    Ci[Ci.size() - 1] = Zj[Zj.size() - 1];

    vector<double> Bi;
    vector<double> Di;


    for (int i = 0; i < Xi.size(); ++i) {
        Bi.emplace_back(0);
    }

    for (int i = 0; i < Xi.size(); ++i) {
        Di.emplace_back(0);
    }

    for (int i = Xi.size() - 2; i > -1; --i) {
        Ci[i] = Zj[i] - MuJ[i] * Ci[i + 1];
        Bi[i] = (Yi[i + 1] - Yi[i]) / Hj[i] - (Hj[i] * (Ci[i + 1] + 2. * Ci[i])) / 3.;
        Di[i] = (Ci[i + 1] - Ci[i]) / (3. * Hj[i]);
    }


    vector<polinomio> resultados;

    for (int i = 0; i < Xi.size()-1; ++i) {
        resultados.emplace_back(0);
    }

    for (int j = 0; j < Xi.size()-1; ++j) {


        vector<polinomio> Polinomios;
        vector<double> coeficiente;

        coeficiente.emplace_back(Yi[j]);
        coeficiente.emplace_back(Bi[j]);
        coeficiente.emplace_back(Ci[j]);
        coeficiente.emplace_back(Di[j]);

        for (double i : coeficiente) {
            polinomio aux(0);
            aux.setCoeficiente(i,0);
            Polinomios.emplace_back(aux);
        }

        for (int i = 0; i < Polinomios.size(); ++i) {
            for (int k = 1; k < i+1; ++k) {
                polinomio aux(Xi[j]);

                Polinomios[i] = aux.multiplicar(Polinomios[i], aux);
            }
            resultados[j].sumar(resultados[j],Polinomios[i]);
        }
    }

    return resultados;
}


#endif //CURVA_TRAZADORACUBICA_H
