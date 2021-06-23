/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Frecuencias.h
 * Author: albertollamasgonzalez
 *
 * Created on 12 de junio de 2020, 16:24
 */

#ifndef FRECUENCIAS_H
#define FRECUENCIAS_H

class Frecuencias {
public:
    Frecuencias();
    Frecuencias(const Frecuencias& orig);
    ~Frecuencias();
private:
    Entrada* entradas;
    int nEntradas;
};

#endif /* FRECUENCIAS_H */

