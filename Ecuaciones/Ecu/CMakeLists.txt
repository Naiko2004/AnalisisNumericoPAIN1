cmake_minimum_required(VERSION 3.26)
project(Ecu)

set(CMAKE_CXX_STANDARD 17)

add_executable(Ecu main.cpp
        sistEcu.cpp
        sistEcu.h
        metodo_EliminacionGaussiana.h
        metodo_GaussSeidel.h
        metodo_LU.h)
