//
// Created by nico on 21/08/23.
//

#include "metodo_PuntoFijo.h"
#include "iomanip"

double puntoFijo_raiz(double inicio, double limite, double errorPermitido)
{
    double valorMax, valuar = inicio;

    valorMax = inicio;
    while(valuar <= limite)
    {
        if(valorMax < guncion(valuar))
        {
            valorMax = valuar;
        }
        valuar += 0.01;
    }

    /*
    cout<<valorMax<<endl;
    cout<<guncionP(valorMax)<<endl;
    cout<<guncion(valorMax)<<endl;
    cout<<funcion(valorMax)<<endl;
    */

    /*if(abs(guncionP(valorMax)) >= 1)
    {
        throw runtime_error("600");
    }*/

    double Xi = inicio;
    double anterior = 0;
    double raiz = guncion(Xi);
    double error = 10;

    int contador = 1;
    cout<<setw(10)<<"i"<<" | "<<setw(10)<<"Xi"<<" | "<<setw(10)<<"g(Xi)"<<" | "<<setw(10)<<"Error abs"<<endl;
    cout<<setw(10)<<"0"<<" | "<<setw(10)<<Xi<<" | "<<setw(10)<<raiz<<" | "<<setw(10)<<" - "<<endl;

    while(error > errorPermitido)
    {


        anterior = raiz;
        Xi = guncion(Xi);
        raiz = guncion(Xi);
        error = abs(anterior - raiz);

        cout<<setw(10)<<contador<<" | "<<setw(10)<<Xi<<" | "<<setw(10)<<raiz<<" | "<<setw(10)<<error<<endl;

        contador++;
    }

    cout<<endl;

    return anterior;
}

