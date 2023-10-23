//
// Created by sofis on 10/16/2023.
//

#include "Articulo.h"
#include <iostream>

void Articulo::setGrupo(string _grupo) {
    grupo = _grupo;
}

void Articulo::setCodigoDeBarras(string _codigoDeBarras) {
    codigoDeBarras=_codigoDeBarras;
}

void Articulo::setArticulo(string _articulo) {
    articulo=_articulo;
}


string Articulo::getGrupo() {
    return grupo;
}

string Articulo::getCodigoDeBarras() {
    return codigoDeBarras;
}

string Articulo::getArticulo() {
    return articulo;
}

void Articulo::setStock(int _stock) {
    stock= _stock;
}

int Articulo::getStock() {
    return stock;
}

int Articulo::getDeposito(){
    return deposito;
}

void Articulo::setDeposito(int _deposito) {
    deposito=_deposito;
}


