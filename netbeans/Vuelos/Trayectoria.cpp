/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Trayectoria.cpp
 * Author: Andrés Cano Utrera <acu@decsai.ugr.es>
 * 
 * Created on 4 de junio de 2019, 17:47
 */

#include <iostream>
#include <limits>

#include "Punto3D.h"
#include "Trayectoria.h"

Trayectoria::Trayectoria() { // EXAMEN 1.1
    numeroPuntos = 0;
    puntos = nullptr;
}

Trayectoria::~Trayectoria() { // EXAMEN 1.1
    liberarMemoria();
}

void Trayectoria::liberarMemoria() { // EXAMEN 1.1
    if (puntos) {
        delete[] puntos;
        puntos = nullptr;
        numeroPuntos = 0;
    }
}

Trayectoria& Trayectoria::operator=(const Trayectoria& orig) { // EXAMEN 1.2
    if (this != &orig) {
        liberarMemoria();
        reservarMemoria(orig.numeroPuntos);
        copiar(orig);
    }
    return *this;
}

void Trayectoria::reservarMemoria(int n) { // EXAMEN 1.2
    if (n > 0) {
        puntos = new Punto3D[n];
        numeroPuntos = n;
    } else {
        puntos = nullptr;
        numeroPuntos = 0;
    }
}

void Trayectoria::copiar(const Trayectoria& otro) { // EXAMEN  1.2
    numeroPuntos = otro.numeroPuntos;
    for (int i = 0; i < otro.numeroPuntos; i++) {
        puntos[i] = otro.puntos[i];
    }
}

Trayectoria::Trayectoria(const Trayectoria& orig) { // EXAMEN  1.2
    reservarMemoria(orig.numeroPuntos);
    copiar(orig);
}

Trayectoria::Trayectoria(const Punto3D arrayPuntos[], int nPuntos) { // EXAMEN  1.3
    reservarMemoria(nPuntos);
    for (int i = 0; i < nPuntos; i++) {
        puntos[i] = arrayPuntos[i];
    }
}

Trayectoria& Trayectoria::operator+=(const Punto3D& punto) { // EXAMEN 2.1
    Punto3D* arrayAuxiliar;
    arrayAuxiliar = new Punto3D[numeroPuntos + 1];
    for (int i = 0; i < numeroPuntos; i++) {
        arrayAuxiliar[i] = puntos[i];
    }
    arrayAuxiliar[numeroPuntos] = punto;
    liberarMemoria();
    puntos = arrayAuxiliar;
    numeroPuntos++;
    return *this;
}

const Punto3D& Trayectoria::operator[](int index) const { // EXAMEN 2.1 (se supone implementado)
    return puntos[index];
}

Punto3D& Trayectoria::operator[](int index) {  // EXAMEN 2.1 (se supflone implementado)
    return puntos[index];
}

std::ostream& operator<<(std::ostream& flujo, const Trayectoria& trayectoria) { // EXAMEN 2.2
    flujo << trayectoria.getNumeroPuntos() << std::endl;
    for (int i = 0; i < trayectoria.getNumeroPuntos(); i++) {
        flujo << trayectoria[i] << std::endl; // o bien: flujo << trayectoria.get(i) << std::endl;
    }
    return flujo;
}

std::istream& operator>>(std::istream& flujo, Trayectoria& trayectoria) { // EXAMEN 3 (Se supone implementado)
    int numeroPuntos;
    Punto3D punto;

    trayectoria.liberarMemoria();
    flujo >> numeroPuntos;
    trayectoria.reservarMemoria(numeroPuntos);
    for (int i = 0; i < numeroPuntos; i++) {
        flujo >> punto;
        trayectoria[i] = punto; // o bien: trayectoria[i].puntos = punto; // o bien si no se hace reservarMemoria(): trayectoria+=punto; 
    }
    return flujo;
}

double Trayectoria::calcularLongitud() const { // EXAMEN 4.1
    double distancia=0.0;

    for (int i = 0; i < (numeroPuntos - 1); i++) {
        distancia += puntos[i].calcularDistancia(puntos[i + 1]);
    }
    return distancia;
}

double Trayectoria::menorDistancia(const Trayectoria& otro) const { // EXAMEN 4.2 (Eliminado del examen)
    double minDistancia = std::numeric_limits<double>::max();
    double distancia;

    for (int i = 0; i < (numeroPuntos - 1); i++) {
        for(int j=0; i < (otro.numeroPuntos -1); j++){
            distancia = ::menorDistancia(this->puntos[i], this->puntos[i+1],
                    otro.puntos[j],otro.puntos[j+1]);
            if(distancia<minDistancia){
                minDistancia = distancia;
            }
        }
    }
    return minDistancia;
}

double menorDistancia(const Punto3D& punto1, const Punto3D& punto2, // EXAMEN 4.2 (Se supone implementado) (Eliminado del examen)
        const Punto3D& punto3, const Punto3D& punto4){
    return 0;
}