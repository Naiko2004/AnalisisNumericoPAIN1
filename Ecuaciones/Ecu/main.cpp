#include <iostream>
#include "sistEcu.h"
#include "metodo_GaussSeidel.h"
#include "metodo_EliminacionGaussiana.h"
#include "metodo_LU.h"
using namespace std;

int main() {

    /*
     * 1.1:
    double TI[3] = {7.85,19.3,71.4};
    vector<vector<double>> MC = {

            {3,-0.1,-0.2},
            {0.1,7,-0.3},
            {0.3,-0.2,10}
    };
    */

    /*
     * 1.2:
    double TI[3] = {24.5,-9.,-50.};
    vector<vector<double>> MC = {

            {10.,-3.,6.},
            {1.,8.,-2.},
            {-2.,4.,-9.}
    };
    */

    /*
     * 1.3:
    double TI[3] = {-51.,61.,8.};
    vector<vector<double>> MC = {

            {1.,7.,-3.},
            {4.,-4.,9.},
            {12.,-1.,3.}
    };
    */

    /*
     * 1.4
    double TI[3] = {60.,-2.,44.};
    vector<vector<double>> MC = {

            {-6.,0.,12.},
            {4.,-1.,-1.},
            {6.,8.,0.}
    };
    */

    /*
     * 1.5
    double TI[3] = {25.,3.,36.};
    vector<vector<double>> MC = {

            {5.,4.,0.},
            {4.,-3.,7.},
            {0.,12.,2.}
    };
     */


    /*2.4 PROBLEMAS
    double TI[3] = {60.,-2.,44.};
    vector<vector<double>> MC = {

            {-6.,0.,12.},
            {4.,-1.,-1.},
            {6.,8.,0.}
    };

     */

    /*
     *  prueba estabilidad
     *
     *     double TI[2] = {10.,10.4};
    vector<vector<double>> MC = {

            {1.,2.},
            {1.1,2.},
    };

    vector<double> sol = {1,1};

    sistEcu a(2,2);
    sistEcu b(2,2);


    a.setTerminosI(2, TI);
    a.setMatrizCoe(MC);


    b.setTerminosI(2, TI);
    b.setMatrizCoe(MC);

     *
     *
     */

    int fila = 3;

    double TI[3] = {7.85,19.3,71.4};
    vector<vector<double>> MC = {

            {3,-0.1,-0.2},
            {0.1,7,-0.3},
            {0.3,-0.2,10}
    };

    vector<double> sol = {1,1,1};

    sistEcu a(fila,fila);
    sistEcu b(fila,fila);



    a.setTerminosI(fila, TI);
    a.setMatrizCoe(MC);


    b.setTerminosI(fila, TI);
    b.setMatrizCoe(MC);

    cout<<"Condicion del sistema: "<<b.getCondicion()<<endl;

    cout<<"Sistema orignal: "<<endl;
    b.imprimir();
    cout<<endl;

   cout << endl << "Sistema reorganizado: " << endl;
    b.acomodarDiagonal();
    a.acomodarDiagonal();
    b.imprimir();


    sistEcu L(fila,fila),
            U(fila,fila);


    LUdescomponer(a,U,L);

    cout<<endl<<"L: "<<endl;
    L.imprimir();
    cout<<endl<<"U: "<<endl;
    U.imprimir();

    cout<<endl<<"Y: "<<endl;
    vector<double> Y = getY(L, b);

    for (int i = 0; i < Y.size(); ++i) {
        cout<<"| Y"<<i<<"= "<<Y[i]<<" |"<<endl;
    }

    U.setTerminosI(Y);

    cout<<endl<<"U: "<<endl;
    U.imprimir();

    sol = getX(U);

    cout<<endl<<"Soluciones: "<<endl;
    for(int i = 0; i < fila; i++)
    {
        cout<<"X"<<i<<" = "<<sol[i]<<endl;
    }
    cout<<endl<<"Valuacion: "<<endl;
    for(int i = 0; i < fila; i++)
    {
        cout<<b.getRes(i,sol)<<" : "<<b.getTerminoI(i)<<endl;
    }


/*1
    cout<<endl<<"Triangularizar: "<<endl;
    triangular(a);
    a.imprimir();

    sustitucionAtras(a,sol);


    cout<<endl<<"Soluciones: "<<endl;
    for(int i = 0; i < fila; i++)
    {
        cout<<"X"<<i<<" = "<<sol[i]<<endl;
    }
    cout<<endl<<"Valuacion: "<<endl;
    for(int i = 0; i < fila; i++)
    {
        cout<<b.getRes(i,sol)<<" : "<<b.getTerminoI(i)<<endl;
    }
*/

    // 2. algoritmoGaussSeidel(a,sol,0.001);


    /*
    cout<<endl<<"Tabla Gauss Seidel: "<<endl<<endl;
    algoritmoGaussSeidel(a,sol,0.0001);
    cout<<endl;
    cout<<endl<<"Soluciones: "<<endl;
    for(int i = 0; i < fila; i++)
    {
        cout<<"X"<<i<<" = "<<sol[i]<<endl;
    }
    cout<<endl<<"Valuacion: "<<endl;
    for(int i = 0; i < fila; i++)
    {
        cout<<b.getRes(i,sol)<<" : "<<b.getTerminoI(i)<<endl;
    }
*/
    return 0;

}
