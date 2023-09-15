//
// Created by Nico on 07/09/2023.
//

#ifndef CURVA_MINCUADRADO_H
#define CURVA_MINCUADRADO_H

#include <cmath>
#include <vector>
using namespace std;

const double e = 2.71828182845904523536028747135266249775724709369995;

double modeloLineal(double a1, double a0, double x);
double modeloExponencial(double A, double B, double x);
double modeloPotencial(double A, double  B, double x);
double modeloCrecimiento(double A, double b, double x);

void regresionLinealMinCuadrado(vector<double> &Xi, vector<double> &Yi, double &a1, double &a0);
void regresionNoLinealExponencial(vector<double> &Xi, vector<double> &Yi, double &a1, double &a0);
void regresionNoLinealPotencial(vector<double> &Xi, vector<double> &Yi, double &a1, double &a0);
void regresionNoLinealCrecimiento(vector<double> &Xi, vector<double> &Yi, double &a1, double &a0);



double modeloLineal(double a1, double a0, double x)
{
    return a1 * x + a0;
}

double modeloExponencial(double A, double B, double x)
{
    return A * pow(e,B * x);
}

double modeloPotencial(double A, double  B, double x)
{
    return A * pow(x,B);
}

double modeloCrecimiento(double A, double b, double x)
{

    return A * x / (b + x);
}


void regresionLinealMinCuadrado(vector<double> &Xi, vector<double> &Yi, double &a1, double &a0)
{
    int n = Xi.size();

    double Xsum = 0, Ysum = 0;
    double Xprom, Yprom;
    double sumProducto = 0;
    double sumXCuadrado = 0;
    double XsumCuadrado;
    double productoSum;

    for (int i = 0; i < n; ++i) {
        Xsum += Xi[i];
        Ysum += Yi[i];
    }

    Xprom = Xsum / n;
    Yprom = Ysum/ n;
    productoSum = Xsum * Ysum;
    XsumCuadrado = pow(Xsum,2);

    for (int i = 0; i < n; ++i) {
            sumProducto += Xi[i] * Yi[i];
    }

    for (int i = 0; i < n; ++i) {
        sumXCuadrado += pow(Xi[i], 2);
    }

    a1 = ( n * sumProducto - productoSum ) / ( n * sumXCuadrado - XsumCuadrado);
    a0 = Yprom - a1 * Xprom;
}

void regresionNoLinealExponencial(vector<double> &Xi, vector<double> &Yi, double &a1, double &a0)
{
    vector<double> linealYi;
    double A,B;

    for (int i = 0; i < Yi.size(); ++i) {
        linealYi.emplace_back( log(Yi[i]) );
    }

    regresionLinealMinCuadrado(Xi, linealYi, B,A);

    a0 = B;
    a1 = pow(e,A);
}

void regresionNoLinealPotencial(vector<double> &Xi, vector<double> &Yi, double &a1, double &a0)
{
    vector<double> linealXi;
    vector<double> linealYi;

    double A,B;

    for (int i = 0; i < Xi.size(); ++i) {
        linealXi.emplace_back(log10(Xi[i]) );
        linealYi.emplace_back(log10(Yi[i]) );
    }

    regresionLinealMinCuadrado(linealXi,linealYi,B,A);

    a0 = B;
    a1 = pow(10,A);
}

void regresionNoLinealCrecimiento(vector<double> &Xi, vector<double> &Yi, double &a1, double &a0)
{
    vector<double> linealXi;
    vector<double> linealYi;
    double A,B;

    for (int i = 0; i < Xi.size(); ++i) {
        linealXi.emplace_back(1 / Xi[i]);
        linealYi.emplace_back(1 / Yi[i]);
    }

    regresionLinealMinCuadrado(Xi,Yi,B,A);

    a1 = 1 / A;
    a0 = B * a1;


}


#endif //CURVA_MINCUADRADO_H
