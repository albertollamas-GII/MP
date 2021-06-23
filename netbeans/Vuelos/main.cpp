/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Andrés Cano Utrera <acu@decsai.ugr.es>
 *
 * Created on 4 de junio de 2019, 17:40
 */

#include <iostream>
#include <cstdlib>

#include "Vuelo.h"

using namespace std;



/*
 * 
 */
int main(int argc, char** argv) {
    if(argc<4){
        cout << "Usar de la siguiente forma: programa ficheroVuelo1.txt ficheroVuelo2.txt umbralDistancia" << endl;
        exit(1);
    }
    Vuelo* pMenor;
    Vuelo vuelo1(argv[1]);
    Vuelo vuelo2(argv[2]);
    if(vuelo1>vuelo2){
        pMenor = &vuelo2;
    }
    else{
        pMenor = &vuelo1;
    }
    
    cout << "id del menor vuelo:" << pMenor->getIdVuelo() << endl;
    cout << "Longitud real" << pMenor->calcularLongitudReal();
    cout << "Longitud óptima" << pMenor->calcularLongitudOptima();
    cout << "Información del vuelo: " << endl;
    cout << *pMenor  << endl;
    
    double distanciaTrayectorias = pMenor->calcularDistanciaMediaTrayectorias();
    if(distanciaTrayectorias < atof(argv[3]) ){
        cout << "Distancia media entre trayectoria real y óptima menor al umbral: " <<
                distanciaTrayectorias << endl;
    }
    else{
        cout << "Distancia media entre trayectoria real y óptima mayor o igual al umbral: " <<
                distanciaTrayectorias << endl;
    }
    
    /*cout << "Menor distancia entre trayectorias óptimas de los dos vuelos: "  << 
            vuelo1.getRutaOptima().menorDistancia(vuelo2.getRutaOptima())<< endl;*/
    return 0;
}

