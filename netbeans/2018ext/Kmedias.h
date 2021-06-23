/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Kmedias.h
 * Author: albertollamasgonzalez
 *
 * Created on 13 de junio de 2020, 11:13
 */

#ifndef KMEDIAS_H
#define KMEDIAS_H

#include "/Users/albertollamasgonzalez/Desktop/DGIIM/CUATRIMESTRE 2/MP/netbeans/2018ext/Punto.h"
#include "/Users/albertollamasgonzalez/Desktop/DGIIM/CUATRIMESTRE 2/MP/netbeans/2018ext/VectorPuntos.h"
#include "/Users/albertollamasgonzalez/Desktop/DGIIM/CUATRIMESTRE 2/MP/netbeans/2018ext/Cluster.h"

class Kmedias {
public:
    Kmedias();
    Kmedias(const Kmedias& orig);
    virtual ~Kmedias();
    void clearandSetK(int n);
    std::ostream& operator << (std::ostream& flujo, const Kmedias& kmedia);
private:
    int K;
    Cluster *clusters;
    void inicializar();
    void reservarmemoria(int n);
    void liberarmemoria();
};

#endif /* KMEDIAS_H */

