//
// Created by sofis on 10/16/2023.
//

#include "Articulo.h"
#include <iostream>

void Articulo::setgrupo(string _grupo) {
    grupo = _grupo;
}

void Articulo::setcodigoDeBarras(string _codigoDeBarras) {
    codigoDeBarras=_codigoDeBarras;
}

void Articulo::setarticulo(string _articulo) {
    articulo=_articulo;
}

void Articulo::setnumeroArticulo(int _numeroArticulo) {
    numeroArticulo=_numeroArticulo;
}


string Articulo::getgrupo() {
    return grupo;
}

string Articulo::getcodigoDeBarras() {
    return codigoDeBarras;
}

string Articulo::getarticulo() {
    return articulo;
}
int Articulo::getnumeroArticulo() {
    return numeroArticulo;
}
