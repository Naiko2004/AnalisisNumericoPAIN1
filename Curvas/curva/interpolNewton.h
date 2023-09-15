//
// Created by nico on 13/09/23.
//

#ifndef CURVA_INTERPOLNEWTON_H
#define CURVA_INTERPOLNEWTON_H

#include "iostream"
#include "vector"
#include "polinomio.h"
#include "iomanip"
using namespace std;

polinomio interpolarNewton(vector<double> Xi, vector<double> Yi);
double calcularB(vector<double> &Xi, vector<double> &Yi, int orden, int digitos);



polinomio interpolarNewton(vector<double> Xi, vector<double> Yi)
{
    vector<double> b;
    vector<vector<double>> difDivididas;

    b.emplace_back(Yi[0]); // b0 = f(x0)

    for(int i = 1; i < Xi.size(); i++)
    {
        b.emplace_back(calcularB(Xi,Yi,i,i));
    }



    for (int i = 0; i < Xi.size(); ++i) {
        vector<double> aux;
        for (int j = 0; j < Xi.size(); ++j) {
            aux.emplace_back(calcularB(Xi,Yi,i,j));
        }
        difDivididas.emplace_back(aux);
    }


    cout<<setw(15)<<"X"<<" | "<<setw(15)<<"Y"<<" | ";

    for (int i = 1; i < b.size(); ++i) {
        cout<<setw(15)<<"B"<<i<<" | ";
    }
    cout<<endl;

    for (int i = 0; i < Xi.size(); ++i) {
        cout<<setw(15)<<Xi[i]<<" | "<<setw(15)<<Yi[i]<<" | ";

        for (int j = 1; j < b.size() - i; ++j) {
            //cout<<setw(10)<<calcularB(Xi,Yi,j+1,i)<<" | ";
            //cout<<setw(10)<<"f[X"<<j+1<<";X"<<i<<"]"<<" | ";
            cout<<setw(15)<<difDivididas[j][j+i]<<" | ";
        }
        cout<<endl;
    }

    cout<<endl<<endl;


    for (int i = 0; i < b.size(); ++i) {
        cout<<setw(10)<<"| B"<<i<<" = "<<setw(10)<<b[i]<<" | "<<endl;
    }

    cout<<endl;

    cout<<"f"<<Xi.size()<<"(X) = ";
    for (int i = 0; i < b.size(); ++i) {
        cout<<b[i];
        for (int j = i; j > 0; --j) {
            cout<<" * ( X - "<<Xi[j-1]<<" )";
        }
        if(i != b.size()-1)
        {
            cout<<" + ";
        }
    }
    cout<<endl;


    vector<polinomio> Polinomios;

    for (double i : b) {
        polinomio a(0);
        a.setCoeficiente(i,0);
        Polinomios.emplace_back(a);
    }


    for (int i = 1; i < Polinomios.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            polinomio operando(Xi[j]);

            Polinomios[i] = Polinomios[i].multiplicar(Polinomios[i], operando);
        }
    }


    polinomio resultante( (int)Xi.size());

    for (auto & Polinomio : Polinomios) {
        resultante.sumar(resultante , Polinomio);
    }

    resultante.simplificar();
    cout<<endl<<"f"<<Xi.size()<<"(x) = ";
    resultante.imprimir();

    return resultante;
}


double calcularB(vector<double> &Xi, vector<double> &Yi, int orden, int digitos)
{
    if(digitos == 0 || orden == 0)
    {
        return Yi[digitos];
    }
    if(digitos == 1)
    {
        //cout<<"f[ X"<<orden<<", X"<<orden-1<<"] = "<<(Yi[orden] - Yi[orden - 1])/(Xi[orden] - Xi[orden - 1])<<endl;
        return (Yi[orden] - Yi[orden - 1])/(Xi[orden] - Xi[orden - 1]);
    }else{

        /*cout<<"f[ ";
        for (int i = orden; i > orden-digitos - 1; --i) {

            if(i == orden - digitos)
            {
                cout<<"X"<<i<<" ";
            }else{
                cout<<"X"<<i<<", ";
            }
        }
        cout<<"]";
        cout<<" = "<<a<<endl;*/

        return ( calcularB(Xi, Yi, orden, digitos-1) - calcularB(Xi, Yi, orden-1, digitos-1) ) / (Xi[orden] - Xi[orden - digitos]);

    }

}



#endif //CURVA_INTERPOLNEWTON_H
