/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vuelo.h
 * Author: albertollamasgonzalez
 *
 * Created on 3 de junio de 2020, 11:50
 */

#ifndef VUELO_H
#define VUELO_H

#include "Punto3D.h"
#include "Trayectoria.h"
#include <iostream>

class Vuelo {
    private:
        int idVuelo;
        Trayectoria RutaOptima;
        Trayectoria RutaReal;
    public:
        Vuelo();
//        ~Vuelo();
        Vuelo(int ident, const Trayectoria& RuOpt);
        Vuelo (const char* fichero);
};


#endif /* VUELO_H */

