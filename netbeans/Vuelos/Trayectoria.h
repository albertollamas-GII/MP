/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Trayectoria.h
 * Author: Andrés Cano Utrera <acu@decsai.ugr.es>
 *
 * Created on 4 de junio de 2019, 17:47
 */

#ifndef TRAYECTORIA_H
#define TRAYECTORIA_H

#include "Punto3D.h"

class Trayectoria {
    Punto3D *puntos;
    int numeroPuntos;
public:
    Trayectoria();
    Trayectoria(const Trayectoria& orig);
    virtual ~Trayectoria();
    Trayectoria& operator=(const Trayectoria& orig);
    Trayectoria(const Punto3D arrayPuntos[], int nPuntos);
    Trayectoria& operator+=(const Punto3D& punto);
    int getNumeroPuntos() const {return numeroPuntos;}; // EXAMEN 2.1 (se supone implementado)
    Punto3D get(int index) const {return puntos[index];};
    friend std::istream& operator>>(std::istream& flujo, Trayectoria& trayectoria);
    double calcularLongitud() const;
    double menorDistancia(const Trayectoria& otro) const;
    const Punto3D& operator[](int index) const;
    Punto3D& operator[](int index);

private:
    void liberarMemoria(); 
    void reservarMemoria(int n); 
    void copiar(const Trayectoria& otro);
};

std::ostream& operator<<(std::ostream& flujo, const Trayectoria& trayectoria);
std::istream& operator>>(std::istream& flujo, Trayectoria& trayectoria);
double menorDistancia(const Punto3D& punto1, const Punto3D& punto2, 
        const Punto3D& punto3, const Punto3D& punto4);



#endif /* TRAYECTORIA_H */

