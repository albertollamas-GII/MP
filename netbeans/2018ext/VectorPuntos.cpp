/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   VectorPuntos.cpp
 * Author: albertollamasgonzalez
 * 
 * Created on 13 de junio de 2020, 11:12
 */

#include <cassert>
#include "VectorPuntos.h"
#include "/Users/albertollamasgonzalez/Desktop/DGIIM/CUATRIMESTRE 2/MP/netbeans/2018ext/Punto.h"

using namespace std;

VectorPuntos::VectorPuntos() {
    inicializar();
}

void VectorPuntos::inicializar(){
    reservarmemoria(10);
    nPuntos=0;
}

void VectorPuntos::reservarmemoria(int n){
    if (n>0){
        this->punto=new Punto [n];
        this->reservados=n;
    } else {
        punto=nullptr;
        reservados=0;
    }
}

void VectorPuntos::liberarmemoria(){
    if (punto!=nullptr){
        delete[] punto;
        punto=nullptr;
        reservados=0;
        nPuntos=0;
    }
}

void VectorPuntos::copiar(const VectorPuntos& otro){
    this->nPuntos=otro.nPuntos;
    this->reservados=otro.reservados;
    for (int i=0; i < otro.nPuntos; i++)
        this->punto[i]=otro.punto[i];
}


VectorPuntos::VectorPuntos(const VectorPuntos& orig) {
    reservarmemoria(orig.reservados);
    copiar(orig);
}

VectorPuntos::~VectorPuntos() {
    liberarmemoria();
}

VectorPuntos& VectorPuntos::operator=(const VectorPuntos& otro){
    if (this != otro){
        liberarmemoria();
        reservarmemoria(otro.reservados);
        copiar(otro);
    }
    return *this;
}

void VectorPuntos::addPunto(const Punto& punto){
    if (nPuntos==this->reservados){
        redimensionar(this->reservados);
    }
    nPuntos++;
    punto[nPuntos-1]=punto;
}
void VectorPuntos::redimensionar(int n){
    int reservados=n+this->reservados;
    if (reservados>0){
        Punto *nuevoPunto;
        nuevoPunto = new Punto [reservados];
        for (int i=0; i < reservados && i < this->reservados; i++)
            nuevoPunto[i]=this->punto[i];
        delete[] puntos;
        puntos=nullptr;
        punto=nuevoPunto;
        this->reservados=reservados;
    }
}

Punto& VectorPuntos::operator[](int i){
    assert(i >= 0 && i < nPuntos);
    return punto[i];
}

const Punto& VectorPuntos::operator[] const (int i){
    assert(i >= 0 && i < nPuntos);
    return punto[i];
}





