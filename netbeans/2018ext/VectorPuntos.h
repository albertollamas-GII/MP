/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   VectorPuntos.h
 * Author: albertollamasgonzalez
 *
 * Created on 13 de junio de 2020, 11:12
 */

#ifndef VECTORPUNTOS_H
#define VECTORPUNTOS_H

#include "/Users/albertollamasgonzalez/Desktop/DGIIM/CUATRIMESTRE 2/MP/netbeans/2018ext/Punto.h"


class VectorPuntos {
public:
    VectorPuntos();
    VectorPuntos(const VectorPuntos& orig);
    virtual ~VectorPuntos();
    VectorPuntos& operator=(const VectorPuntos& otro);
    Punto& operator[] (int i); //lvalue
    const Punto& operator[] (int i) const; //rvalue
    void addPunto(const Punto& punto);
private:
    Punto *punto;
    int nPuntos;
    int reservados;
    void inicializar();
    void reservarmemoria(int n);
    void liberarmemoria();
    void copiar(const VectorPuntos& otro);
};

#endif /* VECTORPUNTOS_H */

