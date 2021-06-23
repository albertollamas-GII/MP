/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Punto.cpp
 * Author: albertollamasgonzalez
 * 
 * Created on 13 de junio de 2020, 11:12
 */

#include "Punto.h"

Punto::Punto() {
    x=0;
    y=0;
}

Punto& Punto::operator=(const Punto& punto){
    if (this!=&punto)
        setXY(p.getX(), p.getY());
    return *this;
}


