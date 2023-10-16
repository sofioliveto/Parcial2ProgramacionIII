//
// Created by sofis on 10/16/2023.
//

#ifndef PARCIAL2PROGRAMACIONIII_ARTICULO_H
#define PARCIAL2PROGRAMACIONIII_ARTICULO_H


class Articulo {
private:
    int grupo;
    char codigoDeBarras[40];
    char articulo[100];
    int deposito1;
    int deposito2;
    int deposito3;
    int deposito4;
    int deposito5;
    int numeroArticulo;
public:
    void setgrupo(int _grupo);

    void setcodigoDeBarras(char _codigoDeBarras[40]);

    void setarticulo(char _articulo[100]);

    void setdeposito1(int _deposito1);

    void setdeposito2(int _deposito2);

    void setdeposito3(int _deposito3);

    void setdeposito4(int _deposito4);

    void setdeposito5(int _deposito5);

    void setnumeroArticulo(int _numeroArticulo);

    int getgrupo();

    char getcodigoDeBarras();

    char getarticulo();

    int getdeposito1();

    int getdeposito2();

    int getdeposito3();

    int getdeposito4();

    int getdeposito5();

    int getnumeroArticulo();

};


#endif //PARCIAL2PROGRAMACIONIII_ARTICULO_H
