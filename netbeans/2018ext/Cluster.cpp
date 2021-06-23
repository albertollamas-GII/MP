/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cluster.cpp
 * Author: albertollamasgonzalez
 * 
 * Created on 13 de junio de 2020, 11:13
 */

#include "/Users/albertollamasgonzalez/Desktop/DGIIM/CUATRIMESTRE 2/MP/netbeans/2018ext/Cluster.h"
#include <iostream>

using namespace std;

Cluster::Cluster() {
}

Cluster::Cluster(const Cluster& orig) {
}

Cluster::~Cluster() {
}

ostream& Cluster::operator << (ostream& flujo, const Cluster& cluster){
    flujo << centroide << endl;
    flujo << puntos << endl; 
}


