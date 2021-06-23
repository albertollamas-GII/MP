/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Kmedias.cpp
 * Author: albertollamasgonzalez
 * 
 * Created on 13 de junio de 2020, 11:13
 */

#include "/Users/albertollamasgonzalez/Desktop/DGIIM/CUATRIMESTRE 2/MP/netbeans/2018ext/Kmedias.h"
#include "/Users/albertollamasgonzalez/Desktop/DGIIM/CUATRIMESTRE 2/MP/netbeans/2018ext/Punto.h"
#include "/Users/albertollamasgonzalez/Desktop/DGIIM/CUATRIMESTRE 2/MP/netbeans/2018ext/VectorPuntos.h"
#include "/Users/albertollamasgonzalez/Desktop/DGIIM/CUATRIMESTRE 2/MP/netbeans/2018ext/Cluster.h"


Kmedias::Kmedias() {
    inicializar();
}

void Kmedias::inicializar(){
    reservarmemoria(2);
}
void Kmedias::reservarmemoria(int n){
    if (n > 0){
        this->K=n;
        clusters=new Cluster[n];
    } else {
        K=0;
        clusters=nullptr;
    }
}

Kmedias::Kmedias(const Kmedias& orig) {
}

Kmedias::~Kmedias() {
    liberarmemoria();
}

void Kmedias::liberarmemoria(){
    if (clusters!=nullptr){
        delete[] clusters;
        clusters=nullptrs;
        K=0;
    }
}

void Kmedias::clearandSetK(int n){
    if (n > 0 && n!=this->K){
        liberarmemoria();
        reservarmemoria(n);
    }
}

std::ostream& Kmedias::operator<< (std::ostream& flujo, const Kmedias& kmedia){
    flujo << kmedia.K << std::endl;
    for (int i)
}

