#include <iostream>
#include "complex.h"
#include <string.h>
#include "funcion.h"
#include "metodo_Biseccion.h"
#include "metodo_PuntoFijo.h"
#include "metodo_NewtonRapshon.h"
#include "metodo_Secante.h"
using namespace std;
int main() {

    double intervalos[40];
    double paso = 0.1,
    inicio = 0,
    limite = 20;

    int contador,
    size;

    size = sizeof(intervalos) / sizeof(intervalos[0]);

    iniciarArray(intervalos, size);

    cout<<"Tabla del barrido del metodo de Biseccion: "<<endl;
    try{
        barrido(paso, inicio, limite, intervalos, size);
    }
    catch (const exception &e)
    {
        char *error = new char;
        *error = '5';
        error++;
        *error = '0';
        error++;
        *error = '1';
        error--;
        error--;
        if(strcmp(e.what(), error) == 0)
        {
            cout<<"La funcion no tiene raices desde "<<inicio<<" hasta "<<limite<<endl;
            delete error;
            return 0;
        }

        *error = '4';
        error++;
        *error = '0';
        error++;
        *error = '0';
        error--;
        error--;

        if(strcmp(e.what(),error) == 0)
        {
            cout<<"division por 0"<<endl;
            delete error;
            return 0;
        }

        delete error;
    }

    cout<<endl<<"Intervalos: "<<endl;
    mostrarArray(intervalos, size);
    cout<<endl;
    contador = 1;
    int numRaiz = 1;

    cout<<endl<<"Raices: "<<endl;
    while(intervalos[contador] != 0 || contador == 1)
    {
        //1
        cout<<endl<<"Raiz numero "<<numRaiz<<" Biseccion: "<<endl<<endl;
        cout<<encontrarRaiz(intervalos[contador-1], intervalos[contador], 0.0001)<<endl;
        //2
        cout<<endl<<"Raiz numero "<<numRaiz<<" Punto fijo: "<<endl<<endl;
        cout<<puntoFijo_raiz(intervalos[contador-1], intervalos[contador], 0.0001)<<endl;
        //3
        cout<<endl<<"Raiz numero "<<numRaiz<<" Newton-Rapshon: "<<endl<<endl;
        cout<<newtonRapshon_encontrarRaiz(intervalos[contador-1], intervalos[contador], 0.0001)<<endl;
        //4
        cout<<endl<<"Raiz numero "<<numRaiz<<" Secante: "<<endl<<endl;
        cout<<secante_encontrarRaiz(intervalos[contador-1], intervalos[contador], 0.0001)<<endl;

        numRaiz++;
        contador += 2;
    }









    return 0;
}
