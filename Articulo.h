//
// Created by sofis on 10/16/2023.
//

#ifndef PARCIAL2PROGRAMACIONIII_ARTICULO_H
#define PARCIAL2PROGRAMACIONIII_ARTICULO_H
#include "Lista.h"

#include <iostream>
#include "Lista.h"
using namespace std;

class Articulo {
private:
    string grupo;
    string codigoDeBarras;
    string articulo;
    Lista<int> depositos;
    int numeroArticulo;
public:
    void setgrupo(string _grupo);

    void setcodigoDeBarras(string _codigoDeBarras);

    void setarticulo(string _articulo);

    void setnumeroArticulo(int _numeroArticulo);

    string getgrupo();

    string getcodigoDeBarras();

    string getarticulo();

    int getnumeroArticulo();

    bool operator == (const Articulo& otra) const {
        return (codigoDeBarras == otra.codigoDeBarras);
    }

    bool operator > (const Articulo& otra) const {
        return codigoDeBarras>otra.codigoDeBarras;
    }

    bool operator < (const Articulo& otra) const {
        return codigoDeBarras<otra.codigoDeBarras;
    }

    bool operator != (const Articulo& otra) const {
        return codigoDeBarras != otra.codigoDeBarras;
    }

    friend ostream& operator << (ostream& os, Articulo& objeto){
        os << "Grupo: " << objeto.grupo << endl << "Codigo de barras: " << objeto.codigoDeBarras << endl << "Nombre articulo: " << objeto.articulo << endl << "Depositos: " << objeto.depositos.print() << endl;
        return os;
    }

    Articulo(){}

    Articulo(string _grupo, string _codigo, string _articulo, Lista<int> _depositos){
        grupo=_grupo;
        codigoDeBarras=_codigo;
        articulo=_articulo;
        depositos=_depositos;
    }

};


#endif //PARCIAL2PROGRAMACIONIII_ARTICULO_H
