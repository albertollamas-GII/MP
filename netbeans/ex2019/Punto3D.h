/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Punto3D.h
 * Author: albertollamasgonzalez
 *
 * Created on 3 de junio de 2020, 11:50
 */

#ifndef PUNTO3D_H
#define PUNTO3D_H

class Punto3D
{
private:
    double x, y, z;

public:
    Punto3D();
    double getX() const { return x; };
    double getY() const { return y; };
    double getZ() const { return z; };
    friend std::istream &operator<<(std::istream &flujo, const Punto3D &punto);
};

#endif /* PUNTO3D_H */
