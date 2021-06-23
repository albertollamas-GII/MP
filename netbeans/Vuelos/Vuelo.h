/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vuelo.h
 * Author: Andrés Cano Utrera <acu@decsai.ugr.es>
 *
 * Created on 4 de junio de 2019, 17:47
 */

#ifndef VUELO_H
#define VUELO_H


#include "Trayectoria.h"

class Vuelo {
    int idVuelo;
    Trayectoria rutaOptima;
    Trayectoria rutaReal;
public:
    Vuelo(); 
    //Vuelo(const Vuelo& orig);
    //virtual ~Vuelo();
    Vuelo(int identificador, const Trayectoria& trayectoria);
    Vuelo& operator+=(const Punto3D& punto);
    
    friend std::ostream& operator<<(std::ostream& flujo, const Vuelo& vuelo);
    
    Vuelo(const char* nombreFichero);
    double calcularLongitudOptima() const; 
    double calcularLongitudReal() const ;
    friend bool operator>(const Vuelo& vuelo1, const Vuelo& vuelo2);
    int getIdVuelo() const {return idVuelo;};
    double calcularDistanciaMediaTrayectorias() const;
    const Trayectoria& getRutaOptima() const {return rutaOptima;};
    const Trayectoria& getRutaReal() const {return rutaOptima;};
private:

};

std::ostream& operator<<(std::ostream& flujo, const Vuelo& vuelo);
bool operator>(const Vuelo& vuelo1, const Vuelo& vuelo2);


#endif /* VUELO_H */

