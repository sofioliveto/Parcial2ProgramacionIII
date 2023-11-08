#include "NodoArbol.h"
#include <iostream>
#include "Articulo.h"
using namespace std;

template <class T> class ArbolBinario {
private:
    T search(T dato, NodoArbol<T> *r);
    NodoArbol<T> *put(T dato, NodoArbol<T> *r);
    NodoArbol<T> *remove(T dato, NodoArbol<T> *r);
    NodoArbol<T> *findMaxandRemove(NodoArbol<T> *r, bool *found);
    void preorder(NodoArbol<T> *r);
    void inorder (NodoArbol<T> *r);
    void postorder (NodoArbol<T> *r);
    int contarPorNivel (int nivel, int nivelActual, NodoArbol<T> *r);

protected:
    NodoArbol<T> *root;

public:
    ArbolBinario();

    void put(T dato);

    T search(T dato);

    void remove(T dato);

    void preorder();

    void inorder();

    void postorder();

    ~ArbolBinario();

    bool esVacio();

    void print();

    void encontrado(bool found, T num);

    int contarPorNivel (int nivel);

    void espejar (NodoArbol<T> *nodo);

    NodoArbol<T> *getRoot();

    void contarNodos(); //Cuenta cantidad de nodos que hay en todo el arbol. Cantidad total de articulos diferentes

    int stockArticulo (string nombreArticulo);

    void prueba(NodoArbol<T> *r);

};

/**
 * Constructor del Arbol
 * @tparam K Clave por la cual va a ordenar el árbol
 * @tparam T Valor guardado por el árbol
 */
template <class T> ArbolBinario<T>::ArbolBinario() {
    root= nullptr;
}

/**
 * Destructor del Arbol
 */
template <class T> ArbolBinario<T>::~ArbolBinario() {}

/**
 * Busca un dato en el árbol. Si no esta el dato en el árbol
 * tira una excepción
 * @param clave Valor a buscar
 * @return el valor buscado
 */
template <class T> T ArbolBinario<T>::search(T dato) {
    return search(dato,root);
}

template <class T> T ArbolBinario<T>::search(T dato, NodoArbol<T> *r) {
    if (r == nullptr) {
        encontrado(false, dato);
        throw 404;
    }

    if (r->getData() == dato) {     //Si el dato esta, devuelve el dato;
        encontrado(true, dato);
        return r->getData();
    }

    if (r->getData() > dato) {      //Si el dato que buscamos es menor al de la raiz, invocamos recursivamente a la misma funcion pero dirigiendola al nodo de la izquierda que es el que guarda los menores
        return search(dato, r->getLeft());
    } else {
        return search(dato, r->getRight());    //Lo mismo que antes solo que con los mayores es para la derecha
    }
}
/**
 * Agrega un dato al árbol
 * @param clave Clave para agregar el dato
 * @param dato Dato a agregar
 */
template <class T> void ArbolBinario<T>::put(T dato) {
    root= put(dato,root);
}

template <class T>
NodoArbol<T>* ArbolBinario<T>::put(T dato, NodoArbol<T>* r) {
    if (r == nullptr) {
        return new NodoArbol<T>(dato);
    }

    if (dato == r->getData()) {
        throw 200; // Puedes manejar esta excepción de la forma que desees
    }

    if (dato < r->getData()) {
        r->setLeft(put(dato, r->getLeft()));
    } else {
        r->setRight(put(dato, r->getRight()));
    }

    return r;
}


/**
 * Elimina un dato del árbol
 * @param clave Clave para identificar el nodo a borrar
 */
template <class T> void ArbolBinario<T>::remove(T dato) {
    root= remove(dato,root);
}

template <class T> NodoArbol<T> *ArbolBinario<T>::remove(T dato, NodoArbol<T> *r) {
    NodoArbol<T> *aux;

    if(r== nullptr){
        throw 404;
    }
    if (r->getData()==dato){
        delete r;
        return nullptr;
    } else {
        if(r->getLeft()!=nullptr && r->getRight()== nullptr){
            aux=r->getLeft();
            delete r;
            return aux;
        } else {
            if(r->getLeft()==nullptr && r->getRight()!= nullptr){
                aux=r->getRight();
                delete r;
                return aux;
            } else {
                if(r->getLeft()!=nullptr && r->getRight()!= nullptr){
                    if(r->getLeft()->getRight()!= nullptr){
                        // ACA BUSCAMOS EL VALOR MAXIMO
                        bool found;
                        aux= ArbolBinario::findMaxandRemove(r->getLeft(), &found);
                        aux->setRight(r->getRight());
                        aux->setLeft(r->getLeft());
                    } else {
                        aux=r->getLeft();
                        r->getLeft()->setRight(r->getRight());
                    }
                    delete r;
                    return aux;
                }
                else {
                    if(r->getData()>dato){
                        r->setLeft(remove(dato, r->getLeft()));
                    }
                    else {
                        r->setRight(remove(dato, r->getRight()));
                    }
                }
            }
        }
    }
}

template <class T> NodoArbol<T> *findMaxandRemove(NodoArbol<T> *r, bool *found){
    NodoArbol<T> ret;
    *found=false;

    if (r->getRight()== nullptr){
        *found= true;
        return r;
    }
    ret= findMaxandRemove(r->getRight(), found);
    if(*found){
        r->getRight(nullptr);
        *found= false;
    }
}

/**
 * Informa si un árbol esta vacío
 * @return
 */
template <class T> bool ArbolBinario<T>::esVacio() {
    return root == nullptr; //es lo mismo que decir si root es nulo return true y si no return false
}

/**
 * Recorre un árbol en preorden
 */
template <class T> void ArbolBinario<T>::preorder() {
    preorder(root);
}

template <class T> void ArbolBinario<T>::preorder(NodoArbol<T> *r) { //raiz-izquierda-derecha
    if (r== nullptr){
        return;
    }
    cout << r->getData() << endl;
    preorder(r->getLeft());
    preorder(r->getRight());
}

/**
 * Recorre un árbol en orden
 */
template <class T> void ArbolBinario<T>::inorder() {
    inorder(root);
}

template <class T> void ArbolBinario<T>::inorder(NodoArbol<T> *r) { //izquierda-raiz-derecha
    if (r== nullptr){
        return;
    }
    inorder(r->getLeft());
    cout << r->getData() << endl;
    inorder(r->getRight());
}

/**
 * Recorre un árbol en postorden
 */
template <class T> void ArbolBinario<T>::postorder() {
    postorder(root);
}

template <class T> void ArbolBinario<T>::postorder(NodoArbol<T> *r) {
    if (r== nullptr){
        return;
    }
    postorder(r->getLeft());
    postorder(r->getRight());
    cout << r->getData() << endl;
}

/**
 * Muestra un árbol por consola
 */
template <class T> void ArbolBinario<T>::print() {
    if (root != NULL) {
        root->print(false, "");
    }
}

template<class T> void ArbolBinario<T>::encontrado(bool found, T numero) {
    /*if (found) {
        cout << "El valor se encontro" << endl;
    } else {
        cout << "El valor NO se encontro" << endl;
    }*/
}

//Devuelve el número de nódos del nivel iésimo de un árbol binario.
template<class T> int ArbolBinario<T>:: contarPorNivel(int nivel, int nivelActual, NodoArbol<T> *r) {
    if (nivel == nivelActual) {
        if (r != nullptr) {
            return 1;
        } else {
            return 0;
        }
    } else {
        if (nivelActual > nivel) {
            return 0;
        } else if (r == nullptr) {
            return 0;
        }
    }

    return contarPorNivel(nivel, nivelActual+1, r->getLeft()) + contarPorNivel(nivel, nivelActual+1, r->getRight());
}

template<class T> int ArbolBinario<T>::contarPorNivel(int nivel) {
    return contarPorNivel(nivel, 0, this->root);
}

template<class T> void ArbolBinario<T>::espejar(NodoArbol<T> *nodo) {

    if (nodo == nullptr){
        return;
    } else {
        espejar(nodo->getLeft());
        espejar(nodo->getRight());

        //intercambio punteros
        NodoArbol<T> *aux = nodo->getLeft();
        nodo->setLeft(nodo->getRight());
        nodo->setRight(aux);
    }
}

template <class T> NodoArbol<T> *ArbolBinario<T>::getRoot() {
    return root;
}

template <class T> int contarNodos(NodoArbol<T> *nodo) { //Esta funcion sirve para contar los nodos en total del arbol
    if (nodo == nullptr) {
        return 0;
    }

    return 1 + contarNodos(nodo->getLeft()) + contarNodos(nodo->getRight());
}

template <class T> void ArbolBinario<T>::contarNodos() { // Esta funcion devulve la cantidad de nodos en total del arbol
    int cantidadNodos = contarNodos(root);
}

template <class T> void ArbolBinario<T>::prueba(NodoArbol<T> *r) {
    string nombre= r->getData()->getArticulo();
    cout << nombre << endl;
    r->getLeft();
    string nombre1= r->getData()->getArticulo();
    cout << nombre1 << endl;
}