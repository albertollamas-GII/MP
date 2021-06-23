/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Linea.cpp
 * Author: albertollamasgonzalez
 * 
 * Created on 8 de junio de 2020, 9:57
 */

#include "Linea.h"
#include <iostream>
#include <cassert>

using namespace std;

//Suponemos constructores implementados.

Linea::Linea(int num_paradas) {
    assert(num_paradas >= 0);
    if (num_paradas == 0) {
        this->num_paradas = 0;
        paradas = 0;
    } else {
        ReservaMemoria(num_paradas);
    }
}

Linea::~Linea() {
    LiberaMemoria();
}

Linea::Linea(const Linea &linea) {
    paradas = 0;
    num_paradas = 0;
    *this = linea;
}

int Linea::GetNumParadas()const {
    return num_paradas;
}

bool Linea::EstaVacia() const {
    return paradas == 0;
}

bool Linea::IndiceValido(int i) const {
    return (i >= 0 && i < num_paradas);
}

void Linea::LiberaMemoria() {
    if (!EstaVacia()) {
        delete [] paradas;
        paradas = 0;
    }
}

void Linea::ReservaMemoria(int tam) {
    assert(tam > 0);
    paradas = new InfoParada[tam];
    num_paradas = tam;
}

void Linea::CopiaParadas(const Linea & linea) {
    for (int i = 1; i <= linea.num_paradas; i++) {
        (*this)[i] = linea[i];
    }
}

Linea& Linea::operator=(const Linea & linea) {
    if (&linea != this) {
        //No compruebo paradas != 0 ya que lo compruebo dentro LiberaMemoria();
        ReservaMemoria(linea.num_paradas);
        CopiaParadas(linea);
    }
    return * this;
}

InfoParada& Linea::operator[](int i) {
    IndiceValido(i);
    return paradas[i - 1];
}

InfoParada Linea::operator[](int i) const {
    IndiceValido(i);
    return paradas[i - 1];
}

Linea & Linea::operator+=(const InfoParada & parada) {
    Linea nueva(num_paradas + 1);
    nueva.CopiaParadas(*this);
    nueva[num_paradas + 1] = parada;
    LiberaMemoria();
    *this = nueva;
    return *this;
}

std::ostream& Linea::operator<<(std::ostream & flujo, const Linea & linea) {
    flujo << "Número de paradas: " << linea.GetNumParadas() << std::endl;
    for (int i = 1; i <= linea.GetNumParadas(); i++) flujo << "\tParada " << i << ": " << linea[i] << endl;
    return flujo;
}

int Linea::GetNumParadasActivas()const {
    int paradas_activas = 0;
    for (int i = 1; i <= num_paradas; i++) {
        if ((*this)[i].EstaActiva())
            paradas_activas++;
    }
    return paradas_activas;
}

std::istream& Linea::operator >>(std::istream& flujo, Linea& linea){
    linea.LiberaMemoria();
    
    int nume_paradas;
    flujo >> nume_paradas;
    
    for (int i=1; i <= nume_paradas;i++){
        InfoParada paradaNueva;
        flujo>> paradaNueva;
        
        linea+=paradaNueva;
    }
    return flujo;
}



