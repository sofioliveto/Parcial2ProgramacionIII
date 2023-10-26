//
// Created by sofis on 10/16/2023.
//
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "ArbolBinario.h"
#include "Articulo.h"
#define inventario "InventariadoFisico2.csv"
using namespace std;


int main() {
    ifstream archivo(inventario);    //definimos el archivo que vamor a abrir (dandole el nombre)
    string linea;

    char delimitador = ',';

    getline(archivo, linea);    //leemos la primer linea para descartarla pues es el encabezado
    int i = linea.length(), dep, cont = 0;

    for (int j = 0; j < i; ++j) {
        if (linea[j] == ',') {
            cont++;
        }
    }
    dep = cont - 2;     //Le restamos las comas que correspones a los datos q no son depositos

    ArbolBinario<Articulo> depositos[dep];     //Creamos un arreglo de tipo arbol de tipo articulo con cantidad de depositos como tamaño

    cout << "Numero de depositos es: " << dep << endl;

    //Leemos todas las lineas
    string cabezaGrupo;
    while (getline(archivo, linea)) {
        stringstream stream(linea);   //convertimos la cadena a stream
        string grupo, grupoguardar, codigoBarras, articulo, stockDeposito;
        int stockTotal=0;

        getline(stream, grupo, delimitador);   //Leemos grupo
        if (!grupo.empty()) {            //si el grupo es vacio entonces el grupo es el primer elemento de la lista
            cabezaGrupo = grupo;
            grupoguardar = cabezaGrupo;
        } else {
            grupoguardar = cabezaGrupo;
        }

        getline(stream, codigoBarras, delimitador);     //Leemos codigo de barras
        if(codigoBarras.front()=='"'){
            string codigoBarrasSdaParte;
            getline(stream, codigoBarrasSdaParte, delimitador);
            codigoBarras+=','+codigoBarrasSdaParte;
            codigoBarras.erase(0,1);   //Elimino primeras comillas
            codigoBarras.pop_back();           //Elimino ultimas comillas
        }

        getline(stream, articulo, delimitador);         //Leemos nombre del articulo

        Articulo articulox(grupoguardar,codigoBarras,articulo);

        for (int j = 0; j < dep; ++j) {
            int num=0;
            getline(stream, stockDeposito, delimitador);
            if (!stockDeposito.empty()) {      //Si NO esta vacio, se suma al stock total.
                num = stoi(stockDeposito);
                stockTotal=stockTotal+num;
                articulox.setDeposito(num);
            } else {
                articulox.setDeposito(0);
            }
            depositos[j].put(articulox);
        }

        articulox.setStock(stockTotal);
    }

    for (int j = 0; j < dep; ++j) {
        cout << "Deposito " << j+1 << endl;
        depositos[j].print();
    }

    /*
    Articulo buscar ("AMLM-AM-U61-B");
    depositos[0].search(buscar).printArticulo();

    //depositos[0].inorder();
     */

    archivo.close();


}
