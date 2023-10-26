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
    int deposito;
    int stock;
public:
    void setGrupo(string _grupo);

    void setCodigoDeBarras(string _codigoDeBarras);

    void setArticulo(string _articulo);

    void setNumeroArticulo(int _numeroArticulo);

    void setStock(int _stock);

    void setDeposito(int _deposito);

    string getGrupo();

    string getCodigoDeBarras();

    string getArticulo();

    int getNumeroArticulo();

    int getStock();

    int getDeposito();

    void printArticulo();



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

    friend ostream& operator << (ostream& os, Articulo objeto){
        os << "Grupo: " << objeto.grupo << endl << "Codigo de barras: " << objeto.codigoDeBarras << endl << "Nombre articulo: " << objeto.articulo << endl << "Stock en deposito: " << objeto.deposito << endl << "Stock total: " << objeto.stock << endl;
        return os;
    }

    Articulo(){}

    Articulo(string _grupo, string _codigo, string _articulo){
        grupo=_grupo;
        codigoDeBarras=_codigo;
        articulo=_articulo;
        stock=0;
    }

    Articulo(string _codigo){
        codigoDeBarras=_codigo;
    }

};


#endif //PARCIAL2PROGRAMACIONIII_ARTICULO_H
