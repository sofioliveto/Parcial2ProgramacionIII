//
// Created by sofis on 10/16/2023.
//

#include "Articulo.h"

void Articulo::setgrupo(int _grupo) {
    grupo = _grupo;
}

void Articulo::setcodigoDeBarras(char *_codigoDeBarras) {
    codigoDeBarras[40]=_codigoDeBarras[40];
}

void Articulo::setarticulo(char *_articulo) {
    articulo[100]=_articulo[100];
}

void Articulo::setdeposito1(int _deposito1) {
    deposito1=_deposito1;
}

void Articulo::setdeposito2(int _deposito2) {
    deposito2=_deposito2;
}

void Articulo::setdeposito3(int _deposito3) {
    deposito3=_deposito3;
}

void Articulo::setdeposito4(int _deposito4) {
    deposito4=_deposito4;
}

void Articulo::setdeposito5(int _deposito5) {
    deposito5=_deposito5;
}

void Articulo::setnumeroArticulo(int _numeroArticulo) {
    numeroArticulo=_numeroArticulo;
}


int Articulo::getgrupo() {
    return grupo;
}

char Articulo::getcodigoDeBarras() {
    return codigoDeBarras[40];
}

char Articulo::getarticulo() {
    return articulo[100];
}

int Articulo::getdeposito1() {
    return deposito1;
}

int Articulo::getdeposito2() {
    return deposito2;
}

int Articulo::getdeposito3() {
    return deposito3;
}

int Articulo::getdeposito4() {
    return deposito4;
}

int Articulo::getdeposito5() {
    return deposito5;
}

int Articulo::getnumeroArticulo() {
    return numeroArticulo;
}
