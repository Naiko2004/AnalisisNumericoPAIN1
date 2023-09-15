//
// Created by nico on 08/08/23.
//

#include "metodo_Biseccion.h"
#include "iomanip"

void barrido(double paso, double inicio, double limite, double intervalos[], int size)
{
    bool raiz = false;
    double valuar = inicio;
    double a,b;
    int contador = 0;

    cout<<setw(10)<<"Xi"<< " | "<<setw(10)<<"F(Xi)"<<" | "<<setw(10)<<"Signo"<<endl;

    while (valuar <= limite)
    {
        a = funcion(valuar);
        valuar += paso;
        b = funcion(valuar);


        // Construccion tabla:
        if(a*b < 0)
        {
            cout<<setw(10)<<a<<" | "<<setw(10)<<b<<" | "<<setw(10) <<"-";
        }else{
            cout<<setw(10)<<a<<" | "<<setw(10)<<b<<" | "<<setw(10) << "+";
        }
        cout<<endl;


        if(a*b < 0)
        {
            intervalos[contador] = valuar - paso;
            contador++;

            if(contador >= size)
            {
                throw std::runtime_error("500");
            }

            intervalos[contador] = valuar;
            contador++;

            if(contador >= size)
            {
                throw std::runtime_error("500");
            }
            raiz = true;
        }

    }

    if(!raiz)
    {
        throw std::runtime_error("501");
    }
}

double encontrarRaiz(double a, double b, double ErrorPermitido)
{
    double c;
    double anterior = 0;
    double error = 0;


    cout<<setw(10)<<"a"<<" | "<<setw(10)<<"b"<<" | "<<setw(10)<<"c"<<" | "<<setw(10)<<"f(a)"<<" | "<<setw(10)
    <<"f(c)"<<" | "<<setw(10)<<"Signo"<<" | "<<setw(10)<<"Error abs"<<endl;
    do {
        c = (a+b)/2;

        // Construccion tabla

        if(funcion(a)* funcion(c) < 0)
        {
            cout<<setw(10)<<a<<" | "<<setw(10)<<b<<" | "<<setw(10)<<c<<" | "<<setw(10)<<funcion(a)<<" | "<<setw(10)
                <<funcion(c)<<" | "<<setw(10)<<"-"<<" | "<<setw(10)<<error<<endl;
        }else{
            cout<<setw(10)<<a<<" | "<<setw(10)<<b<<" | "<<setw(10)<<c<<" | "<<setw(10)<<funcion(a)<<" | "<<setw(10)
                <<funcion(c)<<" | "<<setw(10)<<"+"<<" | "<<setw(10)<<error<<endl;
        }



        if(funcion(a)* funcion(c) < 0)
        {
            b = c;

        }else{
            a = c;
        }
        error = abs(c - anterior);
        anterior = c;
    } while (error > ErrorPermitido);
    cout<<endl;
    return c;
}

