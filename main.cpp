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
#include "string.h"
#define inventario "InventariadoFisico.csv"
using namespace std;

//variables globales
int totalArticulos;
int dep;

//funciones
void stock (string nombreArticulo, ArbolBinario<Articulo> depositos[]){
    Articulo buscar (nombreArticulo); //creo un articulo con un nombre ya que en la busqueda se comparan articulos, no nombres
    cout << "Nombre articulo: " << nombreArticulo << endl;
    try{
        depositos[0].search(buscar).getStock();
    } catch (int exception) {
        if (exception==404){
            cout << "El articulo no se encontro en la base de datos" << endl;
        } else {
            cout << "Ocurrio un error" << endl;
        }
        return;
    }
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

void stockDep (string nombreArticulo, int numdep, ArbolBinario<Articulo> depositos[]){
    Articulo buscar (nombreArticulo); //creo un articulo con un nombre ya que en la busqueda se comparan articulos, no nombres
    cout << "Nombre articulo: " << nombreArticulo << endl;
    try { //La funcion search va a tirar 404 si el articulo no esta en el arbol esto quiere decir que el stock en ese deposito del articulo es 0
        depositos[numdep - 1].search(buscar).getDeposito();
    } catch (int exception){
        if (exception==404){ //Manejamos la excepcion para que en vez de fallar diga que hay 0 en stock
            cout << "Stock en el deposito " << numdep << " : " << 0 << endl;
            return;
        } else{
            cout << "Ocurrio un error" << endl;
        }
    }
    cout << "Stock en el deposito " << numdep << " : " << depositos[numdep - 1].search(buscar).getDeposito() << endl; //Si no tira el error es porq el articulo si tiene stock en ese deposito, asi que lo leemos normal
}

void lectura(ArbolBinario<Articulo>* depositos, int *cantArticulosDif){
    int contArticulos=0;
    ifstream archivo("InventariadoFisico.csv");
    string cabezaGrupo, linea;

    getline(archivo,linea);

    //Leemos todas las lineas
    while (getline(archivo, linea)) {

        contArticulos++;

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
    *cantArticulosDif=contArticulos;

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

int main(int argc, char* argv[]) {
    dep=getDep();
    int *cantArticulosDif=new int ();
    cout<<"Depositos: "<<dep<<endl;

    ArbolBinario<Articulo>* depositos = new ArbolBinario<Articulo>[dep];     //Creamos un arreglo de tipo arbol de tipo articulo con cantidad de depositos como tamaño

    lectura(depositos, cantArticulosDif);

    for (int i = 0; i < argc; i++) {

        if (strcmp(argv[i], "-total_art_dif") == 0) {
            cout << "La cantidad de articulos diferentes es de: " << *cantArticulosDif << endl;
            break;
        }

        if (strcmp(argv[i], "-total_art") == 0) {
            cout << "La cantidad total de articulos es: " << totalArticulos << endl;
        }

        if (strcmp(argv[i], "-max_stock") == 0) {
            int n=stoi(argv[i+1]);
            max_stock(n,depositos);
        }

        if (strcmp(argv[i], "-min_stock") == 0) {
            int n=stoi(argv[i+1]);
            if(argc=i+1){
                min_stock(n,depositos);
            }else{
                int numdep=stoi(argv[i+2]);
                if (numdep<0 || numdep>dep){
                    cout << "El numero de deposito no existe" << endl;
                    return 0;
                }
                min_stock(n,numdep,depositos);
            }
        }

        if (strcmp(argv[i], "-stock") == 0) {
            if(argc==i+3){
                stock(argv[i+1],depositos);
            }else{
                int numdep=stoi(argv[i+2]);
                if (numdep<0 || numdep>dep){
                    cout << "El numero de deposito no existe" << endl;
                    return 0;
                }
                stockDep(argv[i+1],numdep,depositos);
            }
        }
    }

    /*
    for (int j = 0; j < dep; ++j) {
        cout << "Deposito " << j+1 << endl;
        depositos[j].print();

    //PRUEBA DE FUNCIONES
    cout << "Articulos con minimo de 5 en stock" << endl;
    depositos[0].min_stock(20);

    string nombreArticulo="VASSER DUCHA CON BRAZO Y ROSETA K90.1001";
    stock (nombreArticulo, 5, depositos);

    max_stock(800, depositos);

    stock("hola",depositos); */
}
