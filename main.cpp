//
// Created by sofis on 10/16/2023.
//
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "ArbolBinario.h"
#include "Articulo.h"
#include "Lista.h"
#define inventario "cmake-build-debug/InventariadoFisico2.csv"
using namespace std;

//variables globales
int totalArticulos;
int dep;

void total_art (){
    cout << "La cantidad total de articulos es: " << totalArticulos << endl;
}

void stock (string nombreArticulo, ArbolBinario<Articulo> depositos[]){
    Articulo buscar (nombreArticulo); //creo un articulo con un nombre ya que en la busqueda se comparan articulos, no nombres
    cout << "Nombre articulo: " << nombreArticulo << endl;
    cout << "Stock total: " << depositos[0].search(buscar).getStock() << endl;
}

void min_stock (int n, ArbolBinario<Articulo> depositos[]){
    cout << "Articulos con " << n << " unidades en stock o menos" << endl;
    depositos[0].min_stock(n);
}

void max_stock (int n, ArbolBinario<Articulo> depositos[]){
    cout << "Articulos con " << n << " unidades en stock o mas" << endl;
    depositos[0].max_stock(n);
}

void min_stock (int n, int deposito, ArbolBinario<Articulo> depositos[]){
    cout << "Articulos con " << n << " unidades en stock o menos en el deposito " << deposito << endl;
    depositos[deposito-1].min_stock(n);
}

void stock (string nombreArticulo, int numdep, ArbolBinario<Articulo> depositos[]){
    Articulo buscar (nombreArticulo); //creo un articulo con un nombre ya que en la busqueda se comparan articulos, no nombres
    cout << "Nombre articulo: " << nombreArticulo << endl;
    try { //La funcion search va a tirar 404 si el articulo no esta en el arbol esto quiere decir que el stock en ese deposito del articulo es 0
        depositos[numdep - 1].search(buscar).getDeposito();
    } catch (int exception){
        if (exception==404){ //Manejamos la excepcion para que en vez de fallar diga que hay 0 en stock
            cout << "Stock en el deposito " << numdep << " : " << 0 << endl;
            return;
        }
    }
    cout << "Stock en el deposito " << numdep << " : " << depositos[numdep - 1].search(buscar).getDeposito() << endl; //Si no tira el error es porq el articulo si tiene stock en ese deposito, asi que lo leemos normal
}

void lectura(ArbolBinario<Articulo>* depositos){

    int cantArticulosDif=0;

    ifstream archivo(inventario);
    string cabezaGrupo, linea;

    getline(archivo,linea);

    //Leemos todas las lineas
    while (getline(archivo, linea)) {

        cantArticulosDif++;

        stringstream stream(linea);   //convertimos la cadena a stream

        string grupo, grupoguardar, codigoBarras, articulo, stockDeposito;

        int stockTotal=0;

        getline(stream, grupo, ',');   //Leemos grupo
        if (!grupo.empty()) {            //si el grupo es vacio entonces el grupo es el primer elemento de la lista
            cabezaGrupo = grupo;
            grupoguardar = cabezaGrupo;
        } else {
            grupoguardar = cabezaGrupo;
        }

        getline(stream, codigoBarras, ',');     //Leemos codigo de barras

        if(codigoBarras.front()=='"'){
            string codigoBarrasSdaParte;
            getline(stream, codigoBarrasSdaParte, ',');
            codigoBarras+=','+codigoBarrasSdaParte;
            codigoBarras.erase(0,1);   //Elimino primeras comillas
            codigoBarras.pop_back();           //Elimino ultimas comillas
        }

        getline(stream, articulo, ',');         //Leemos nombre del articulo

        Articulo articulox(grupoguardar,codigoBarras,articulo);

        Lista<int> stockDep;

        for (int j = 0; j < dep; ++j) {
            int num;
            getline(stream, stockDeposito, ',');
            if (!stockDeposito.empty()) {      //Si NO esta vacio, se suma al stock total.
                num = stoi(stockDeposito);
                stockDep.insertarUltimo(num);
            } else {
                stockDep.insertarUltimo(0);
            }
        }

        stockTotal=stockDep.sumarLista();

        for (int j =0; j < dep; j++) {
            int num;
            num=stockDep.getDato(j);
            if (j==0){ //Hacemos que en el arbol del deposito 1 se guarden todos los articulos a pesar de que el deposito sea 0,
                articulox.setDeposito(num); //esto es para facilitar algunas funciones
                articulox.setStock(stockTotal);
                depositos[j].put(articulox);
            }
            else {
                if(num!=0){
                    articulox.setDeposito(num);
                    articulox.setStock(stockTotal);
                    depositos[j].put(articulox);
                }
            }
        }

        totalArticulos+=stockTotal;
    }

    archivo.close();

}

int getDep() {
    ifstream archivo(inventario);    //definimos el archivo que vamor a abrir (dandole el nombre)
    string linea;

    getline(archivo, linea);    //leemos la primer linea para descartarla pues es el encabezado
    int i = linea.length(), depCalc, cont = 0;

    for (int j = 0; j < i; ++j) {
        if (linea[j] == ',') {
            cont++;
        }
    }
    depCalc = cont - 2;     //Le restamos las comas que correspones a los datos q no son depositos
    archivo.close();
    return depCalc;
}

int main() {
    dep=getDep();
    cout<<"Depositos: "<<dep<<endl;

    ArbolBinario<Articulo>* depositos = new ArbolBinario<Articulo>[dep];     //Creamos un arreglo de tipo arbol de tipo articulo con cantidad de depositos como tamaño

    lectura(depositos);

    /*
    cout<<"Cantidad de argumentos: "<<argc<<endl;

    for (int i = 0; i < argc; ++i) {
        cout<<"Argumento "<<i<<": "<<argv[i]<<endl;

        if(strcmp(argv[i],"-total_art_dif")==0){
            //
            break;
        }
    }

    for (int j = 0; j < dep; ++j) {
        cout << "Deposito " << j+1 << endl;
        depositos[j].print();
    }
      total_art();
    cout << "Articulos con minimo de 5 en stock" << endl;
    depositos[0].min_stock(20);

    string nombreArticulo="VASSER DUCHA CON BRAZO Y ROSETA K90.1001";
    stock (nombreArticulo, 5, depositos);
     */

}
