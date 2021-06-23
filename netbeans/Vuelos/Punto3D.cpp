/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Punto3D.cpp
 * Author: Andrés Cano Utrera <acu@decsai.ugr.es>
 * 
 * Created on 4 de junio de 2019, 17:44
 */

#include <iostream>
#include <cmath>

#include "Punto3D.h"

Punto3D::Punto3D() : x(0), y(0), z(0) { // EXAMEN 1.1 No es necesaria su implementación, aunque es recomendable  
}

/*Punto3D::~Punto3D() { // EXAMEN 1.1 No es necesario su implementación
}*/

/*Punto3D::Punto3D(const Punto3D& orig) { // EXAMEN 1.2 No es necesario su implementación
 * 
 *  EXAMEN 1.2 No es necesario tampoco el operador de asignación
}*/

std::ostream& operator<<(std::ostream& flujo, const Punto3D& punto) { // EXAMEN 2.2 (Se supone implementado)
    flujo << punto.getX() << " " << punto.getY() << " " << punto.getZ();
    return flujo;
}

std::istream& operator>>(std::istream& flujo, Punto3D& punto) { // EXAMEN 3 (Se supone implementado)
    flujo >> punto.x >> punto.y >> punto.z;
    return flujo;
}

double Punto3D::calcularDistancia(const Punto3D& punto) const { // EXAMEN 4.1
    return sqrt(pow(this->getX() - punto.getX(), 2) +
            pow(this->getY() - punto.getY(), 2) +
            pow(this->getZ() - punto.getZ(), 2));
}
