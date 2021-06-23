/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RedMetro.h
 * Author: albertollamasgonzalez
 *
 * Created on 8 de junio de 2020, 9:57
 */

#ifndef REDMETRO_H
#define REDMETRO_H

#include "InfoParada.h"
#include "Linea.h"

class RedMetro {
public:
    RedMetro();
    ~RedMetro();
    RedMetro(const RedMetro& red);
    RedMetro(const char *fichero);
    void operator=(const RedMetro& red);
    bool operator== (const RedMetro& otra);
    bool operator!=(const RedMetro & otra);
    bool operator>(const RedMetro & otra);
    int MejorConectada() const;
    int GetNumTotalParadas() const;
    double ValorCalidad() const;
    bool EstaVacia() const {return lineas==0;};
    inline int GetNumLineas() {return num_lineas;};
private:
    int num_lineas;
    Linea* lineas;
    void reservarmemoria(int num_lineas);
    void liberarmemoria();
    void copiar(const RedMetro& red);
    bool isEqual (double d1, double d2, double epsilon = 0.00000000001);
};

friend std::istream& Linea::operator >> (std::istream& flujo,  Linea& linea);
friend std::istream& InfoParada::operator >> (std::istream& flujo, InfoParada& parada);

#endif /* REDMETRO_H */

