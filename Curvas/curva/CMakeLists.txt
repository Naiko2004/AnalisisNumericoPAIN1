cmake_minimum_required(VERSION 3.26)
project(curva)

set(CMAKE_CXX_STANDARD 17)

add_executable(curva main.cpp
        funcion.h
        minCuadrado.h
        interpolNewton.h
        polinomio.h
        lagrange.h
        trazadoraCubica.h)
