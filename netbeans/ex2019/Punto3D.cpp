/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Punto3D.h"
#include <iostream>

using namespace std;

//1
Punto3D::Punto3D()
{
    x = 0;
    y = 0;
    z = 0;
}
std::ostream &operator<<(std::ostream &flujo, const Punto3D &punto)
{ // EXAMEN 2.2 (Se supone implementado)
    flujo << punto.getX() << " " << punto.getY() << " " << punto.getZ();
    return flujo;
}