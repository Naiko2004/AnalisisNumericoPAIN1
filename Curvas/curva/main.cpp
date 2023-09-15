#include <iostream>
#include "minCuadrado.h"
#include "interpolNewton.h"
#include "polinomio.h"
#include "lagrange.h"
#include "trazadoraCubica.h"
using namespace std;

int main() {

    /*
    vector<double> Xi = {1,2,3,4,5,6,7};
    vector<double> Yi = {0.5,2.5,2.,4.,3.5,6.,5.5};
    */

    /*
    vector<double> Xi = {1,2,3,4,5};
    vector<double> Yi = {0.5,1.7,3.4,5.7,8.4};
    */

    /*
    vector<double> Xi = {0,1,2,3,4,5,6,7,8};
    vector<double> Yi = {0,1.7,2.885,3.8,4.5,5.1,5.455,5.855,6.154};
     */

    /*    1.1
    vector<double> Xi = {0,1,2,3};
    vector<double> Yi = {1,2.7182,7.3891,20.0855};
     */

    /* 1.2
    vector<double> Xi = {0.5,1,1.5,2,2.5,3};
    vector<double> Yi = {1,2.119,2.91,3.945,5.72,8.695};
    */

    /* 1.3
    vector<double> Xi = {1,2,3,5,6};
    vector<double> Yi = {4.75,4,5.25,19.75,36};
     */

    /* 1.4 ???????
    vector<double> Xi = {0,10,20,30,40,50,60};
    vector<double> Yi = {50000,35000,31000,20000,19000,12000,11000};
     */

    vector<double> Xi = {1.,2.,3.,4.,5.};
    vector<double> Yi = {0,1,0,1,0};

    vector<double> x = {0,1,2,3};
    vector<double> y = {1,2.7182,7.3891,20.0855};

    double a,b;

    regresionNoLinealPotencial(x,y,a,b);


    cout<<"y = "<<a<<"x^("<<b<<")"<<endl;

    /* Regresion
    double A, B;

    regresionLinealMinCuadrado(Xi,Yi,A,B);

    cout<<"y = "<<A<<"x + "<<B<<endl;

    regresionNoLinealExponencial(Xi, Yi,A,B);

    cout<<"y = "<<A<<"e^("<<B<<"x)"<<endl;

    regresionNoLinealPotencial(Xi,Yi,A,B);

    cout<<"y = "<<A<<"x^("<<B<<")"<<endl;

    regresionNoLinealCrecimiento(Xi,Yi,A,B);

    cout<<"y = "<<A<<"x / ("<<B<<" + x)"<<endl;
    */

    polinomio res = interpolarNewton(Xi,Yi);


    /*vector<polinomio> res;

    res = trazadoraCubicaCondicionada(Xi,Yi,2.431955325,0);

    cout<<endl<<"CONDICIONADO: "<<endl;
    for (int i = 0; i < Xi.size() - 1; ++i) {
        cout<<"Polinomio para el intervalo ["<<Xi[i]<<", "<<Xi[i+1]<<"] :"<<endl;
        res[i].imprimir();
        cout<<endl;
    }

    res = trazadoraCubicaNatural(Xi,Yi);


    cout<<endl<<"NATURAL: "<<endl;
    for (int i = 0; i < Xi.size() - 1; ++i) {
        cout<<"Polinomio para el intervalo ["<<Xi[i]<<", "<<Xi[i+1]<<"] :"<<endl;
        res[i].imprimir();
        cout<<endl;
    }
*/


    /*
    polinomio res = polinomiosLagrange(Xi,Yi);



    for (int i = 0; i < Xi.size(); ++i) {
        cout<<res.evaluar(Xi[i])<<endl;
    }
     */

    return 0;
}

