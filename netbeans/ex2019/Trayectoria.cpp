/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Punto3D.h"
#include "Trayectoria.h"
#include <iostream>

using namespace std;

// 1
Trayectoria::Trayectoria(){
    if (puntos!=nullptr)
        puntos=nullptr;
    numeropuntos=0;
}

Trayectoria::~Trayectoria(){
    liberarmemoria();
}
void Trayectoria::liberarmemoria(){
    if(puntos!=nullptr){
        delete[] puntos;
        puntos=nullptr;
        numeropuntos=0;
    }
}

void Trayectoria::reservarmemoria(int numeropuntos){//
    if (numeropuntos > 0){
        puntos = new Punto3D[numeropuntos];
        this->numeropuntos=numeropuntos;
    } else {
        puntos=nullptr;
        this->numeropuntos=0;
    }
}

void Trayectoria::copiar(const Trayectoria& otro){ //1.2
    this->numeropuntos=otro.numeropuntos;
    for (int i=0; i < otro.numeropuntos;i++)
        this->puntos[i]=otro.puntos[i];
}

Trayectoria& Trayectoria::operator=(const Trayectoria &orig){ //1.2
    if (this != orig){
        liberarmemoria();
        reservarmemoria(orig.numeropuntos);
        copiar(orig);
    }
    return *this;
}

Trayectoria::Trayectoria(const Trayectoria& orig){ //1.2
    reservarmemoria(orig.numeropuntos);
    copiar(orig);
}

Trayectoria::Trayectoria(int numpuntos, const Punto3D arrayobjetos[]){
    reservarmemoria(numpuntos);
    for (int i=0; i < numpuntos; i++)
        puntos[i]=arrayobjetos[i];
}

//2
const Punto3D& Trayectoria::operator[](int index) const { // EXAMEN 2.1 (se supone implementado)
    return puntos[index];
}

Punto3D& Trayectoria::operator[](int index) {  // EXAMEN 2.1 (se supone implementado)
    return puntos[index];
}

//es parecido a hacer funcion add. Podria haber hecho funcion privada redimensionar
Trayectoria& Trayectoria::operator += (const Punto3D& punto){
    Punto3D* arrayauxiliar;
    arrayauxiliar=new Punto3D [numeropuntos +1];
    for (int i=0; i < numeropuntos; i++)
        arrayauxiliar[i]=puntos[i];
    arrayauxiliar[numeropuntos]=punto;
    liberarmemoria();
    puntos=arrayauxiliar;
    numeropuntos++;
    return *this;
}

std::ostream& Trayectoria::operator<< (std::ostream& flujo, const Trayectoria& trayectoria){
    flujo << trayectoria.getNumeroPuntos() << endl;
    for (int i = 0; i < trayectoria.getNumeroPuntos(); i++) {
        flujo << trayectoria[i] << std::endl; 
    }
    return flujo;
}

