cmake_minimum_required(VERSION 3.26)
project(Parcial2ProgramacionIII)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Parcial2ProgramacionIII
        main.cpp
        Articulo.cpp
        Articulo.h
        NodoArbol.h
        ArbolBinario.h
        Lista.h
)
