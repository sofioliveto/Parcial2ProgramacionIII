//
// Created by sofis on 10/16/2023.
//

#ifndef PARCIAL2PROGRAMACIONIII_NODOARBOL_H
#define PARCIAL2PROGRAMACIONIII_NODOARBOL_H

#include <iostream>

using namespace std;

template<class T>
class NodoArbol {
private:
    T data;
    NodoArbol *left, *right;

public:
    NodoArbol() {
        left = nullptr;
        right = nullptr;
    }

    NodoArbol(T d) {
        data = d;
        right = nullptr;
        left = nullptr;
    }

    T getData() const {
        return data;
    }

    void setData(T d) {
        this->data = d;
    }

    NodoArbol *getRight() const {
        return right;
    }

    void setRight(NodoArbol *r) {
        this->right = r;
    }

    NodoArbol *getLeft() const {
        return left;
    }

    void setLeft(NodoArbol *l) {
        this->left = l;
    }

    void print(bool esDerecho, string identacion) {
        if (right != NULL) {
            right->print(true, identacion + (esDerecho ? "     " : "|    "));
        }
        cout << identacion;
        if (esDerecho) {
            cout << " /";
        } else {
            cout << " \\";
        }
        cout << "-- ";
        cout << data << endl;
        if (left != NULL) {
            left->print(false, identacion + (esDerecho ? "|    " : "     "));
        }
    }


};

#endif //PARCIAL2PROGRAMACIONIII_NODOARBOL_H

