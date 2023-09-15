//
// Created by nico on 13/09/23.
//

#ifndef CURVA_POLINOMIO_H
#define CURVA_POLINOMIO_H
#include "vector"
#include "iostream"
using namespace std;

class polinomio {
private:
    int grado;
    vector<double> coeficientes;
public:
    polinomio();
    polinomio(int g);
    polinomio(double Xi);
    polinomio(vector<double> coe);

    void setCoeficiente(double valor, int pos);
    double getCoeficiente(int pos);
    int getGrado();
    void setGrado(int g);

    void sumar(polinomio &base, polinomio &opera);
    void restar(polinomio &base, polinomio &opera);
    polinomio multiplicar(polinomio &base, polinomio &opera);
    void dividirCoeficientes(double divisor);

    double evaluar(double x);

    void simplificar();
    void imprimir();
};

polinomio::polinomio() {
    grado = 0;
}

polinomio::polinomio(double Xi) {
    grado = 1;
    coeficientes.emplace_back(-1. * Xi);
    coeficientes.emplace_back(1);
}

void polinomio::imprimir() {
    for (int i = 0; i < grado + 1; ++i) {
        if(i > 0)
        {
            cout<<"x^"<<i<<" * ";
        }
        cout<<coeficientes[i];
        if(i != grado)
        {
            cout<<" + ";
        }
    }
    cout<<endl;
}

polinomio::polinomio(vector<double> coe) {
    grado = coe.size() - 1;
    coeficientes = coe;
}

void polinomio::sumar(polinomio &base, polinomio &opera) {
    int gradoMayor;

    if(base.getGrado() > opera.getGrado())
    {
        gradoMayor = base.getGrado();
    }else{
        gradoMayor = opera.getGrado();
    }

    for (int i = 0; i < gradoMayor + 1; ++i) {
        if(base.getGrado() < i)
        {
            base.coeficientes.emplace_back(opera.getCoeficiente(i));
            base.setGrado(opera.grado);
        }else if(opera.getGrado() < i){
            return;
        }else{
            base.setCoeficiente(  base.getCoeficiente(i) + opera.getCoeficiente(i)
                                  ,i);
        }
    }

}

int polinomio::getGrado() {
    return grado;
}

void polinomio::setCoeficiente(double valor, int pos) {
    coeficientes[pos] = valor;
}

double polinomio::getCoeficiente(int pos) {
    return coeficientes[pos];
}

void polinomio::setGrado(int g) {
    grado = g;
}

void polinomio::restar(polinomio &base, polinomio &opera) {
    int gradoMayor;

    if(base.getGrado() > opera.getGrado())
    {
        gradoMayor = base.getGrado();
    }else{
        gradoMayor = opera.getGrado();
    }

    for (int i = 0; i < gradoMayor + 1; ++i) {
        if(base.getGrado() < i)
        {
            base.setCoeficiente(-1. * opera.getCoeficiente(i), i);
            base.setGrado(opera.getGrado());
        }else if(opera.getGrado() < i){
            return;
        }else{
            base.setCoeficiente(  base.getCoeficiente(i) - opera.getCoeficiente(i)
                    ,i);
        }
    }
}

polinomio polinomio::multiplicar(polinomio &base, polinomio &opera) {
    int grad = base.getGrado() + opera.getGrado();
    polinomio resultante(grad);

    for (int i = 0; i < base.getGrado() + 1; ++i) {
        for (int j = 0; j < opera.getGrado() + 1; ++j) {
            resultante.coeficientes[i + j] += base.getCoeficiente(i) * opera.getCoeficiente(j);
        }
    }

    return resultante;
}

polinomio::polinomio(int g) {
    grado = g;
    for (int i = 0; i < g+1; ++i) {
        coeficientes.emplace_back(0);
    }
}

void polinomio::simplificar() {
    for (int i = grado; i > -1; --i) {
        if(coeficientes[i] == 0)
        {
            coeficientes.erase(coeficientes.begin() + i);
            grado--;
        }else{
            return;
        }
    }
}

double polinomio::evaluar(double x) {
    double res = 0;
    for (int i = 0; i < coeficientes.size(); ++i) {
        if(i == 0)
        {
            res += coeficientes[i];
        }else{
            res += coeficientes[i] * pow(x,i);
        }
    }
    return res;
}

void polinomio::dividirCoeficientes(double divisor) {
    for (double & coeficiente : coeficientes) {
        coeficiente = coeficiente / divisor;
    }
}


#endif //CURVA_POLINOMIO_H
