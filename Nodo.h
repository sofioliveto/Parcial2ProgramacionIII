//
// Created by sofis on 10/18/2023.
//

#ifndef PARCIAL2PROGRAMACIONIII_NODO_H
#define PARCIAL2PROGRAMACIONIII_NODO_H

template<class T>
class Nodo{
private:
    T dato;
    Nodo<T> *siguiente;

public:
    T getDato(){
        return dato;
    }

    void setDato(T d){
        dato = d;
    }

    Nodo<T> *getSiguiente(){
        return siguiente;
    }

    void setSiguiente(Nodo<T> *siguiente){
        this->siguiente = siguiente;
    }


};

#endif //PARCIAL2PROGRAMACIONIII_NODO_H
