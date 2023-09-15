//
// Created by Nico on 31/08/2023.
//

#ifndef ECU_SISTECU_H
#define ECU_SISTECU_H

#include "vector"
#include "iostream"
#include "cmath"

using namespace std;

class sistEcu {
private:
    int filas;
    int columnas;

    vector<double> terminosI;
    vector<vector<double>> matrizCoe;

    sistEcu makeM(sistEcu &base, int i, int j);
    void setFila(int f);
    void setColumna(int c);

public:
    sistEcu(int fil = 0, int col = 0);
    sistEcu(sistEcu &sistema);

    void setTerminosI(int size, double array[]);
    void setTerminosI(vector<double> nuevosTerminosI);
    void setTerminoI(int pos, double valor);
    void setMatrizCoe(vector<vector <double>> matriz);
    void setCoe(int fila, int col, double  valor);


    double getTerminoI(int pos);
    double getCoeficiente(int fil, int col);
    double getRes(int posFil, vector<double> soluciones);
    int getFilas();
    int getColumnas();

    sistEcu getInverso();
    sistEcu getAdjunto();
    double getDet();
    double getNorma();
    int getCondicion();

    void imprimir();

    void sumarFila(int filaBase, int filaOpera, double multiplo);
    void anularFila(int filaBase, int filaOpera, int colNula);
    void cambiarFila(int filaBase, int filaOpera);
    void trasponer();
    void multiplicarFilaPorCte(int filaBase, double multiplo);


    void acomodarDiagonal();

};


#endif //ECU_SISTECU_H
