/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>

#include "ListaCeldasEnlazadas.h"

using namespace std;

void insertarPrincipioLista(Celda* &lista, double valor) {
    Celda* aux = new Celda;
    aux->dato = valor;
    aux->sig = lista;
    lista = aux;
}

void insertarAlFinalLista(Celda* &lista, double valor){
    Celda *p;
    if(lista == nullptr){
        lista = new Celda;
        p = lista;
        //lista->dato = valor;
        //lista->sig = nullptr;
    }
    else{
        p = lista;
        while(p->sig != nullptr){
            p = p->sig;
        }
        p->sig = new Celda;
        p = p->sig;
        //p->sig->dato = valor;
        //p->sig->sig = nullptr;
    }
    p->sig = nullptr;
    p->dato = valor;
}


void mostrarLista(Celda* lista) {
    Celda* aux = lista;
    while (aux != 0) {
        cout << aux -> dato << " ";
        aux = aux->sig;
    }
    cout << endl;
}

void destruirLista(Celda* &lista) {
    while (lista != 0) {
        Celda* aux = lista;
        lista = aux->sig;
        delete aux;
    }
}

