/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   polinomio.h
 * Author: albertollamasgonzalez
 *
 * Created on 1 de junio de 2020, 19:33
 */

#ifndef POLINOMIO_H
#define POLINOMIO_H
#include <assert.h>
#include <iostream>


class Polinomio{
    private:
        float *coeficientes;
        int grado;
        int maximogrado;
        
        void inicializar(); //Evita repeticion de codigo dentro de constructores
        
    public:
//        Polinomio();
        Polinomio(int maxgrado=10);
        ~Polinomio();
        int getGrado() const;
        float getCoeficiente(int indice) const;
        void setCoeficiente (int i, float c);
        void imprimir() const;
        Polinomio operator+(const Polinomio &pol1, const Polinomio &pol1) const;
};


#endif /* POLINOMIO_H */

