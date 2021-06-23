/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cluster.h
 * Author: albertollamasgonzalez
 *
 * Created on 13 de junio de 2020, 11:13
 */

#ifndef CLUSTER_H
#define CLUSTER_H

#include "/Users/albertollamasgonzalez/Desktop/DGIIM/CUATRIMESTRE 2/MP/netbeans/2018ext/Punto.h"
#include "/Users/albertollamasgonzalez/Desktop/DGIIM/CUATRIMESTRE 2/MP/netbeans/2018ext/VectorPuntos.h"

class Cluster {
public:
    Cluster();
    std::ostream& operator << (std::ostream& flujo, const Cluster& cluster);
    
private:
    Punto centroide;
    VectorPuntos puntos;
};

#endif /* CLUSTER_H */

