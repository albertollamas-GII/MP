/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Trayectoria.h
 * Author: albertollamasgonzalez
 *
 * Created on 3 de junio de 2020, 11:50
 */

#ifndef TRAYECTORIA_H
#define TRAYECTORIA_H

#include "Punto3D.h"

class Trayectoria
{
private:
    Punto3D *puntos;
    int numeropuntos;
    void liberarmemoria();
    void reservarmemoria(int numeropuntos);
    void copiar(const Trayectoria &otro);

public:
    Trayectoria();
    ~Trayectoria();
    Trayectoria(const Trayectoria &orig);
    const Punto3D &operator[](int index) const;
    Punto3D &operator[](int index);
    Trayectoria(int numpuntos, const Punto3D arrayobjetos[]);
    Trayectoria &operator=(const Trayectoria &copia);
    Trayectoria &Trayectoria::operator+=(const Punto3D &punto);
};
std::ostream &operator<<(std::ostream &flujo, const Trayectoria &trayectoria);

#endif /* TRAYECTORIA_H */
