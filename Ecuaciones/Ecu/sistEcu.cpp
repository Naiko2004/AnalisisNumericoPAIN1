//
// Created by Nico on 31/08/2023.
//

#include "sistEcu.h"

sistEcu::sistEcu(int fil, int col) {
    filas = fil;
    columnas = col;
    vector<double> filaTemp;


    for(int i = 0; i < filas; i++){
        terminosI.emplace_back(0);
    }

    for(int j = 0; j < columnas; j++)
    {
        filaTemp.emplace_back(0);
    }

    for(int j = 0; j < filas; j++) {
        matrizCoe.emplace_back(filaTemp);
    }

}

void sistEcu::setTerminosI(int size, double *array) {
    if(size != filas)
    {
        throw runtime_error("500");
    }

    for(int i = 0; i < filas; i++){
        terminosI[i] = array[i];
    }
}

void sistEcu::setMatrizCoe(vector<vector<double>> matriz) {
    if(matriz.size() != matrizCoe.size())
    {
        throw runtime_error("500");
    }

    for(int i = 0; i < filas; i++)
    {
        for(int j = 0; j < columnas; j++)
        {
            matrizCoe[i][j] = matriz[i][j];
        }
    }


}

double sistEcu::getTerminoI(int pos) {
    return terminosI[pos];
}

double sistEcu::getRes(int posFil, vector<double> soluciones) {

    double resultado = 0.;

    for(int i = 0; i < columnas; i++)
    {
        resultado += matrizCoe[posFil][i]  * soluciones[i];
    }

    return resultado;
}

void sistEcu::imprimir(){

    for(int i=0; i < filas; i++)
    {
        for(int j = 0; j < columnas; j++)
        {
            cout<<matrizCoe[i][j]<<"* X"<<j;
            if(j != columnas - 1)
            {
                cout<<" + ";
            }
        }
        cout<<" = "<<terminosI[i]<<endl;
    }



}

void sistEcu::sumarFila(int filaBase, int filaOpera, double multiplo) {

    terminosI[filaBase] += terminosI[filaOpera] * multiplo;
    for(int i = 0; i < columnas; i++)
    {
        matrizCoe[filaBase][i] += matrizCoe[filaOpera][i] * multiplo;
    }
}

void sistEcu::anularFila(int filaBase, int filaOpera, int colNula) {
    if(colNula < 0 || colNula >= columnas)
    {
        throw runtime_error("600");
    }

    double multiplo = -1. * matrizCoe[filaBase][colNula] / matrizCoe[filaOpera][colNula];


    terminosI[filaBase] += terminosI[filaOpera] * multiplo;
    matrizCoe[filaBase][colNula] = 0;

    for(int i = colNula + 1; i < columnas; i++)
    {
        matrizCoe[filaBase][i] += matrizCoe[filaOpera][i] * multiplo;
    }
}

int sistEcu::getColumnas() {
    return columnas;
}

int sistEcu::getFilas() {
    return filas;
}

double sistEcu::getCoeficiente(int fil, int col) {
    return matrizCoe[fil][col];
}

void sistEcu::acomodarDiagonal() {

    if (filas != columnas)
    {
        throw runtime_error("600");
    }

    vector<double> diagonal, aux;

    for(int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; ++j) {
            if(i == j)
            {
                diagonal.emplace_back(matrizCoe[i][j]);
            }
        }
    }

   // matriz[fila][columna]

    for (int i = columnas - 1; i > -1; --i) {
        for (int j = 0; j < filas; ++j) {
            if(matrizCoe[j][i] >= diagonal[i])
            {
                cambiarFila(i,j);
                diagonal[i] = matrizCoe[j][i];
                break;
            }
        }
    }

}

void sistEcu::cambiarFila(int filaBase, int filaOpera) {

    vector<double> aux;
    double TI;

    for(int i = 0; i < filas; i++)
    {
        if(i == filaBase)
        {
            aux = matrizCoe[i];
            TI = terminosI[i];
        }
    }

    matrizCoe[filaBase] = matrizCoe[filaOpera];
    terminosI[filaBase] = terminosI[filaOpera];
    matrizCoe[filaOpera] = aux;
    terminosI[filaOpera] = TI;

}

sistEcu::sistEcu(sistEcu &sistema) {
    filas = sistema.filas;
    columnas = sistema.columnas;

    terminosI = sistema.terminosI;
    matrizCoe = sistema.matrizCoe;
}

void sistEcu::setCoe(int fila, int col, double valor) {
    matrizCoe[fila][col] = valor;
}

void sistEcu::setTerminosI(vector<double> nuevosTerminosI) {

    if(filas != nuevosTerminosI.size()){
        throw runtime_error("600");
    }

    terminosI = nuevosTerminosI;
}

void sistEcu::setTerminoI(int pos, double valor) {
    terminosI[pos] = valor;

}

int sistEcu::getCondicion() {
    double condicion;
    sistEcu Inverso = getInverso();

    condicion = getNorma();
    condicion *= Inverso.getNorma();
    int contador = 0;

    while(condicion / 10 > 1)
    {
        contador++;
        condicion /= 10;
    }

    return contador;
}

sistEcu sistEcu::getInverso() {

    // Calculo determinante

    if(getDet() == 0)
    {
        throw runtime_error("333");
    }

    // Calculo adjunto

    sistEcu Adjunto = getAdjunto();

    // Calculo inverso

    Adjunto.trasponer();
    for (int i = 0; i < Adjunto.getFilas(); ++i) {
        Adjunto.multiplicarFilaPorCte(i,1. / getDet());
    }

    return Adjunto;
}

sistEcu sistEcu::makeM(sistEcu &base, int i, int j) {
    sistEcu M(base);

    M.matrizCoe.erase(M.matrizCoe.begin() + i );
    M.setFila(M.getFilas()-1);

    for (int k = 0; k < M.getFilas(); ++k) {
        M.matrizCoe[k].erase(M.matrizCoe[k].begin() + j);
    }
    M.setColumna(M.getColumnas() - 1);

    return M;
}

void sistEcu::setFila(int f) {
    filas = f;
}

void sistEcu::setColumna(int c) {
    columnas = c;
}

double sistEcu::getDet() {
    double determinante = 0;

    if(columnas == 1 && filas == 1)
    {
        return matrizCoe[0][0];
    }
    if(columnas == 2 && filas == 2)
    {
        determinante = (matrizCoe[0][0] * matrizCoe[1][1] - matrizCoe[1][0] * matrizCoe[0][1]);
        return determinante;
    }

    int i = 0;
    for (int j = 0; j < columnas; ++j) {
        sistEcu M = makeM(*this, i, j);

        determinante += (matrizCoe[i][j] * (pow(-1,i+j+2)) * M.getDet());
    }
    return determinante;
}

sistEcu sistEcu::getAdjunto() {

    sistEcu Adjunto(filas,columnas);

    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            double valor;
            sistEcu M = makeM(*this, i, j);

            valor = pow(-1,i+j) * M.getDet();
            Adjunto.setCoe(i,j,valor);
        }
    }

    return Adjunto;
}

void sistEcu::trasponer() {
    sistEcu A(columnas,filas);

    for (int i = 0; i < columnas; ++i) {
        for (int j = 0; j < filas; ++j) {
            A.setCoe(i,j,
                     matrizCoe[j][i]);
        }
    }

    matrizCoe = A.matrizCoe;
    filas = A.getFilas();
    columnas = A.getColumnas();
}

void sistEcu::multiplicarFilaPorCte(int filaBase, double multiplo) {
    for (int i = 0; i < columnas; ++i) {
        matrizCoe[filaBase][i] = matrizCoe[filaBase][i] * multiplo;
    }
}

double sistEcu::getNorma() {
    double norma = 0;
    double max = 0;

    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            norma += abs(matrizCoe[j][i]);
        }

        if(norma > max)
        {
            max = norma;
        }
        norma = 0;
    }

    return max;
}


