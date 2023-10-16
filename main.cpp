//
// Created by sofis on 10/16/2023.
//
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "ArbolBinario.h"
#include "Articulo.h"
#define inventario "Inventariado.csv"
using namespace std;


int main(){
    ArbolBinario<Articulo> amoblamientos;
    ifstream archivo (inventario);    //definimos el archivo que vamor a abrir (dandole el nombre)
    string linea;                     //para ir guardando cada linea e ir parseando

    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo." << endl;
        return 1;
    }

    char delimitador=',';

    getline(archivo,linea);    //leemos la primer linea para descartarla pues es el encabezado

    //Leemos todas las lineas
    while(getline(archivo, linea)){

        stringstream stream(linea);   //convertimos la cadena a stream

        string grupo, codigoBarras, articulo, cantDeposito1, cantDeposito2, cantDeposito3, cantDeposito4, cantDeposito5;

        getline(stream, grupo, delimitador);
        getline(stream, codigoBarras, delimitador);
        getline(stream, articulo, delimitador);
        getline(stream, cantDeposito1, delimitador);
        getline(stream, cantDeposito2, delimitador);
        getline(stream, cantDeposito3, delimitador);
        getline(stream, cantDeposito4, delimitador);
        getline(stream, cantDeposito5, delimitador);

        //imprimimos PRUEBA

        cout<<"===================="<<endl;
        cout<<"grupo: "<<grupo<<endl;
        cout<<"Codigo de barras: "<<codigoBarras<<endl;
        cout<<"Articulo: "<<articulo<<endl;
        cout<<"Deposito 1: "<<cantDeposito1<<endl;
        cout<<"Deposito 2: "<<cantDeposito2<<endl;
        cout<<"Deposito 3: "<<cantDeposito3<<endl;
        cout<<"Deposito 4: "<<cantDeposito4<<endl;
        cout<<"Deposito 5: "<<cantDeposito5<<endl;

    }

archivo.close();

    /*
    char articulo[40];
    fflush(stdin);
    cout<<"Ingresar nombre del articulo"<<endl;
    cin.getline(articulo, 40, '\n');
    cout<<articulo;
    */

}