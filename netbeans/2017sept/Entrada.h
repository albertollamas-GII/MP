/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Entrada.h
 * Author: albertollamasgonzalez
 *
 * Created on 12 de junio de 2020, 16:24
 */

#ifndef ENTRADA_H
#define ENTRADA_H

class Entrada {
public:
    Entrada();
    Entrada(const Entrada& orig);
    ~Entrada();
    int getFrecuencia() const;
    void setFrecuencia(int frecuencia;);
private:
    char* palabra;
    int frecuencia;
};

#endif /* ENTRADA_H */

