//
// Created by nico on 08/08/23.
//

#include "funcion.h"


const double e = 2.71828182845904523536028747135266249775724709369995;
const int max_iteraciones = 500;


double nth_root(double A, double n, unsigned int lim_iteraciones){
    double epsilon = std::numeric_limits<double>::epsilon();

    if(n < 0){
        throw std::runtime_error("100");
    }
    if(n == 1 || A == 0)
    {
        return A;
    }

    double anterior = 1,
    valor;

    for(int k = 0; k < lim_iteraciones; k++){
        valor = (n - 1) * anterior/n + (A / n)*(1/ potencia(anterior, n-1));

        if(abs(anterior - valor) < epsilon)
        {
            return valor;
        }
        anterior = valor;
    }
    return valor;
}

double potencia(double base, double exp){
    // base cero:
    if(base == 0)
    {
        return 0;
    }
    // exponente cero:
    if(exp == 0)
    {
        return 1;
    }
    // exponente negativo:
    if(exp < 0)
    {
        return 1 / potencia(base, -exp);
    }
    // exponente racional:
    if(exp > 0 && exp < 1)
    {
        return nth_root(base, 1/exp, max_iteraciones);
    }
    // exponente par
    if((int)exp % 2 == 0)
    {
        double mitad = potencia(base, exp/2);
        return mitad * mitad;
    }
    // exponente entero:

    // base uno:
    if(base == 1)
    {
        return 1;
    }

    double res = 1;
    for(int i = 0; i < exp; i++)
    {
        res *= base;
    }
    return res;
}

double funcion(double x) {
    double respuesta;
    /* 1.1= respuesta = pow(e, -x) - x;
     1.2= respuesta = -0.874 * x * x + 1.750 * x + 2.627;
     1.3= respuesta = -23.33 + 79.35 * x - 88.09 * ::pow(x,2) + 41.6 * pow(x,3) - 8.68 * pow(x,4) + 0.658 * pow(x,5);
     1.4= respuesta = ::log(x) - 5;
     1.5=
    respuesta = (1 - 0.6 * x) / x;
    if(x == 0)
    {
        throw std::runtime_error("400");
    }
    */

    /* 2.1 respuesta = pow(e, -x) - x;
    2.2:    respuesta = -0.874 * x * x + 1.750 * x + 2.627;
     2.3: ADFA
         respuesta = -23.33 + 79.35 * x - 88.09 * pow(x,2) + 41.6 * pow(x,3) - 8.68 * pow(x,4) + 0.658 * pow(x,5);

    2.4:
         respuesta = log(x) - 5;

         2.5:

             respuesta = (1 - 0.6 * x) / x;
    if(x == 0)
    {
        throw std::runtime_error("400");
    }

    */

    /*
     3.1    respuesta = pow(e, -x) - x;
    3.2     respuesta = -0.874 * x * x + 1.750 * x + 2.627;
    3.3     respuesta = -23.33 + 79.35 * x - 88.09 * pow(x,2) + 41.6 * pow(x,3) - 8.68 * pow(x,4) + 0.658 * pow(x,5);
3.4

    respuesta = log(x) - 5;
     3.5
         respuesta = (1 - 0.6 * x) / x;
    if(x == 0)
    {
        throw std::runtime_error("400");
    }

     */

    /*
      4.1     respuesta = pow(e, -x) - x;
        4.2     respuesta = -0.874 * x * x + 1.750 * x + 2.627;
        4.3 nglpegoo     respuesta = -23.33 + 79.35 * x - 88.09 * pow(x,2) + 41.6 * pow(x,3) - 8.68 * pow(x,4) + 0.658 * pow(x,5);
    4.4     respuesta = log(x) - 5;
    4.5     respuesta = (1 - 0.6 * x) / x;
    if(x == 0)
    {
        throw std::runtime_error("400");
    }
     */

    respuesta = log(x) * sin(x);

    return respuesta;
}

double guncion(double x)
{
    double respuesta;
    /*
     2.2:     respuesta = sqrt((1.75 * x + 2.627)/0.874);
     2.3 AYUDAAA:
            double a = -23.33 + 79.35 * x - 88.09 * pow(x,2) + 41.6 * pow(x,3) - 8.68 * pow(x,4);
     a = a/(-0.658);
     if(a > 0)
    {
        respuesta = pow(a, 1.0/5);
    }else{
        respuesta = potencia(a, 1.0/5);
    }
    respuesta = respuesta;

     2.4:
         respuesta = x * (5 - log(x) + 1);

         2.5:

    respuesta = 1 + 0.4 * x;
     */

    respuesta = x - ( - 0.874 * x * x + 1.750 * x + 2.627) / ( - 0.874 * 2 * x + 1.750);

    return respuesta;
}

double guncionP(double x)
{
    double respuesta;
    /*
      2.2:     respuesta = 875 * sqrt(1/874)  / sqrt(1750 * x + 2627);
      2.3: AA

          double  a = pow( (-500./329.) * (-217./25. * pow(x,4) + 208./5. * pow(x,3) - 8809./100. * pow(x,2) + 1587./20. * x - 2333./100.), 1./5.);
    respuesta = (-7935. * a + 17618. * x * a - 12480. * pow(x,2) * a + 3472. * pow(x,3) * a)
            /
            ( 4340. * pow(x,4) - 20800. * pow(x,3) +44045. * pow(x,2) + 11665.);
    2.4:
         respuesta = 6 - log(x);

    2.5: quelindo
         respuesta = 0.4;


     */

    respuesta = -875 * sqrt(1 / 874) / sqrt(1750 * x + 2627);

    return respuesta;
}



void mostrarArray(double array[], int size)
{
    for(int i = 0; i < size; i++)
    {
        if(array[i] + array[i+1] != 0)
        {
            cout<<"["<<array[i]<<"] ";
        }
    }
    cout<<endl;
}


void iniciarArray(double array[], int size)
{
    for(int i = 0; i < size; i++)
    {
        array[i] = 0;
    }
}
