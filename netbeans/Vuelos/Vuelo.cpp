/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vuelo.cpp
 * Author: Andrés Cano Utrera <acu@decsai.ugr.es>
 * 
 * Created on 4 de junio de 2019, 17:47
 */

#include <fstream>
#include <limits>

#include "Vuelo.h"

Vuelo::Vuelo() : idVuelo(-1) { // EXAMEN 1.1
}

/*Vuelo::~Vuelo() { // EXAMEN 1.1. No es necesario
}*/

/*Vuelo::Vuelo(const Vuelo& orig) { // EXAMEN 1.2 No es necesario
}
 
 EXAMEN 1.2 No es necesario tampoco el operador de asignación
 
 */


Vuelo::Vuelo(int identificador, const Trayectoria& trayectoria) { // EXAMEN 1.3
    idVuelo = identificador;
    rutaOptima = trayectoria;
}

Vuelo& Vuelo::operator+=(const Punto3D& punto){ // EXAMEN 2.1
    if(rutaReal.getNumeroPuntos()==0){
        rutaReal+=rutaOptima[0];  // o bien rutaReal+=rutaOptima.get(0); 
    }
    rutaReal+=punto;
    
    return *this;
}

std::ostream& operator<<(std::ostream& flujo, const Vuelo& vuelo){ // EXAMEN 2.2
    flujo << vuelo.idVuelo << std::endl;
    flujo << vuelo.rutaOptima << std::endl;
    flujo << vuelo.rutaReal << std::endl;

    return flujo;
}

Vuelo::Vuelo(const char* nombreFichero){ // EXAMEN 3
    std::ifstream flujo;
    std::string cadena;
    
    idVuelo=-1;
    flujo.open(nombreFichero);
    if(flujo){
        flujo >> cadena;
        if(cadena=="FICHEROVUELO"){
            flujo >> idVuelo;
            flujo >> rutaOptima;
            flujo >> rutaReal;
        }
        flujo.close();
    }
}

double Vuelo::calcularLongitudOptima() const{ // EXAMEN 4.1
    return rutaOptima.calcularLongitud();
}

double Vuelo::calcularLongitudReal() const { // EXAMEN 4.1
    return rutaReal.calcularLongitud();
}

double Vuelo::calcularDistanciaMediaTrayectorias() const{ // EXAMEN 4.2
    double distanciaMedia=0.0;
    double distanciaMin, d;
    
    for(int i=0; i<rutaReal.getNumeroPuntos(); i++){
        distanciaMin= rutaReal[i].calcularDistancia(rutaOptima[0]); // o bien std::numeric_limits<double>::max();
        for(int j=1; j<rutaOptima.getNumeroPuntos(); j++){
            d = rutaReal[i].calcularDistancia(rutaOptima[j]);
            if(d < distanciaMin){
                distanciaMedia += distanciaMin;
            }
        }
        distanciaMin += d;
    }
    return distanciaMedia / rutaReal.getNumeroPuntos();
}

bool operator>(const Vuelo& vuelo1, const Vuelo& vuelo2){  // EXAMEN 4.3
    if(vuelo1.rutaReal.calcularLongitud() > vuelo2.rutaReal.calcularLongitud())
        return true;
    else
        return false;
}

