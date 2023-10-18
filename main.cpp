//
// Created by sofis on 10/16/2023.
//
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <stdexcept>
#include "ArbolBinario.h"
#include "Articulo.h"
#include "Lista.h"
#define inventario "InventarioFisico.csv"
using namespace std;


int main() {
    // Lista<ArbolBinario<Articulo>> grupos;
    ArbolBinario<Articulo> amoblamientos;
    ArbolBinario<Articulo> anafesOrmay;
    ArbolBinario<Articulo> campanasFranke;
    ArbolBinario<Articulo> campanasTST;
    ArbolBinario<Articulo> fixSystem;
    ArbolBinario<Articulo> griferiasVarias;
    ArbolBinario<Articulo> hornosOrmay;
    ArbolBinario<Articulo> mueblesAccesorios;
    ArbolBinario<Articulo> piletasCeramica;
    ArbolBinario<Articulo> piletasDaccord;
    ArbolBinario<Articulo> piletasFerrum;
    ArbolBinario<Articulo> piletasJohnson;
    ArbolBinario<Articulo> piletasMiPileta;
    ArbolBinario<Articulo> piletasPringles;
    ArbolBinario<Articulo> piletasVidrioColori;
    ArbolBinario<Articulo> termotanquesOrmay;
    ArbolBinario<Articulo> turboar;
    ifstream archivo(inventario);    //definimos el archivo que vamor a abrir (dandole el nombre)
    string linea;                     //para ir guardando cada linea e ir parseando

    string nombresGrupos[18] = {"amoblamientos", "anafesOrmay", "campanasFranke", "campanasTST", "fixSystem",
                                "griferiasVarias", "hornosOrmay", "mueblesAccesorios",
                                "piletasCeramicas", "piletasDaccord", "piletasFerrum", "piletasJohnson",
                                "piletasMiPileta", "piletasPringles", "piletasVidrioColori", "termotanquesOrmay",
                                "turboar"};

    char delimitador = ',';

    getline(archivo, linea);    //leemos la primer linea para descartarla pues es el encabezado

    string cabezaGrupo;
    //Leemos todas las lineas
    while (getline(archivo, linea)) {
        stringstream stream(linea);   //convertimos la cadena a stream
        string grupo, grupoguardar, codigoBarras, articulo, depositox;

        getline(stream, grupo, delimitador);   //Leemos grupo

        if (!grupo.empty()) {            //si el grupo es vacio entonces el grupo es el primer elemento de la lista
            cabezaGrupo = grupo;
            grupoguardar = cabezaGrupo;
        } else {
            grupoguardar = cabezaGrupo;
        }

        /*
    int i=0;
    switch(i) {
        case 0: {
            Articulo articulo1;
            articulo1.setarticulo(articulo);
            articulo1.setcodigoDeBarras(codigoBarras);
            articulo1.setgrupo(grupo);
            char caracter;
            int cantDepositos=0;
            while (stream.get(caracter)) {
                Lista<int> depositos;
                if(caracter!='\n') {
                    int num;
                    getline(stream, depositox, delimitador);
                    if (depositox.empty()) {
                        depositos.insertarUltimo(0);
                    }else {
                        num = stoi(depositox);
                        depositos.insertarUltimo(num);
                    }
                }
                cantDepositos++;
            }
            amoblamientos.put(articulo1);
            break;
        }
        case 1: {
            Articulo articulo2;
            articulo2.setarticulo(articulo);
            articulo2.setcodigoDeBarras(codigoBarras);
            articulo2.setgrupo(grupo);
        }
        i++;
    }*/

        getline(stream, codigoBarras, delimitador);     //Leemos codigo de barras

        getline(stream, articulo, delimitador);         //Leemos nombre del articulo

        Lista<int> depositos;
        char caracter;
        int cantDepositos = 0;
        while (stream.get(caracter)) {
            if (caracter != '\n') {
                int num;
                getline(stream, depositox, delimitador);
                if (depositox.empty()) {
                    depositos.insertarUltimo(0);
                } else {
                    num = stoi(depositox);
                    depositos.insertarUltimo(num);
                }
                cantDepositos++;
            }
        }
        //articulo(codigoBarras, articulo);

        //imprimimos PRUEBA

        cout << "====================" << endl;
        cout << "grupo: " << grupoguardar<< endl;
        cout << "Codigo de barras: " << codigoBarras << endl;
        cout << "Articulo: " << articulo << endl;
        for (int i = 0; i < cantDepositos; i++) {
            cout << "Deposito " << i + 1 << " :" << depositos.getDato(i) << endl;
        }
    }
    archivo.close();



    /*
    char articulo[40];
    fflush(stdin);
    cout<<"Ingresar nombre del articulo"<<endl;
    cin.getline(articulo, 40, '\n');
    cout<<articulo;
    */


    //grupos.insertarPrimero(amoblamientos.put(codigoBarras));

}