//
// Created by sofis on 10/16/2023.
//

#ifndef PARCIAL2PROGRAMACIONIII_ARTICULO_H
#define PARCIAL2PROGRAMACIONIII_ARTICULO_H
#include "Lista.h"

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

};


#endif //PARCIAL2PROGRAMACIONIII_ARTICULO_H
