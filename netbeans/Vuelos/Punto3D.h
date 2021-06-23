/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Punto3D.h
 * Author: Andrés Cano Utrera <acu@decsai.ugr.es>
 *
 * Created on 4 de junio de 2019, 17:44
 */

#ifndef PUNTO3D_H
#define PUNTO3D_H

class Punto3D {
    double x, y, z;
public:
    Punto3D();
    //Punto3D(const Punto3D& orig);
    //virtual ~Punto3D();
    
    double getX() const {return x;};
    double getY() const {return y;};
    double getZ() const {return z;};
    friend std::istream& operator>>(std::istream& flujo, Punto3D& punto);
    double calcularDistancia(const Punto3D& punto) const;
};

std::istream& operator>>(std::istream& flujo, Punto3D& punto);
std::ostream& operator<<(std::ostream& flujo, const Punto3D& punto);

#endif /* PUNTO3D_H */

