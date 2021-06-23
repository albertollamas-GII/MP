/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RedMetro.cpp
 * Author: albertollamasgonzalez
 * 
 * Created on 8 de junio de 2020, 9:57
 */

#include "RedMetro.h"
#include <iostream>
#include <ifstream>
#include <cmath>

using namespace std;

RedMetro::RedMetro() {
    num_lineas = 0;
    if (lineas != nullptr)
        lineas = nullptr;
}

RedMetro::~RedMetro() {
    liberarmemoria();
}

void RedMetro::liberarmemoria() {
    if (lineas != nullptr) {
        delete[] lineas;
        lineas = nullptr;
    }
    num_lineas = 0;
}

void RedMetro::copiar(const RedMetro& red) {
    this->num_lineas = red.num_lineas;
    for (int i = 1; i <= red.num_lineas; i++)
        this->lineas[i] = red.lineas[i];
}

void RedMetro::reservarmemoria(int num_lineas) {
    if (num_lineas > 0) {
        this->lineas = new Linea[num_lineas];
        this->num_lineas = num_lineas;
    } else {
        lineas = nullptr;
        num_lineas = 0;
    }
}

RedMetro::RedMetro(const RedMetro& red) {
    reservarmemoria(red.num_lineas);
    copiar(red);
}

void RedMetro::operator=(const RedMetro& orig) {
    if (this != &orig) {
        liberarmemoria();
        reservarmemoria(orig.GetNumLineas());
        copiar(orig);
    }
    return *this;
}

std::ostream& RedMetro::operator<<(std::ostream& flujo, const RedMetro& red) {
    flujo << red.GetNumLineas() << endl;
    for (int i = 1; i <= red.GetNumLineas(); i++)
        flujo << red[i] << endl;
    return flujo;
}

std::istream& RedMetro::operator>>(std::istream& flujo, RedMetro& red) {
    int nume_lineas = 0;
    int num_parada = 0;
    flujo >> nume_lineas;
    std::assert(nume_lineas >= 0);

    RedMetro nueva;

    for (int i = 1; i <= nume_lineas; i++) {
        Linea linea_nueva;
        flujo >> linea_nueva;

        red += linea_nueva;
    }

    return flujo;
}

RedMetro::RedMetro(const char *fichero) {
    ifstream fi(fichero);

    const int MAX_CADENA = 100;
    char cadena[MAX_CADENA];
    fi.getline(cadena, MAX_CADENA); // Lectura palabra mágica 
    if (!strcmp(cadena, "METRO")) {
        fi >> (*this); // Operador >> de la clase RedMetro
    }// if (!strcmp(cadena, "METRO"))

    fi.close();
}

double RedMetro::ValorCalidad() const {
    int cont_paradas_total = 0;
    int cont_paradas_no_activas_total = 0;
    for (int l = 0; l < num_lineas; l++) {
        Linea la_linea = lineas[l]; // Nota 1: Asignación entre objetos de clase Linea 
        int paradas_linea = la_linea.GetNumParadas();
        // Contar paradas no activas de la linea
        int cont_paradas_no_activas = 0;
        for (int p = 1; p <= paradas_linea; p++) {
            if (!(la_linea[p].EstaActiva())) // Nota 2: Operator [] de "Linea" 
                cont_paradas_no_activas++;
        }
        // Acumular contadores
        cont_paradas_total += paradas_linea;
        cont_paradas_no_activas_total += cont_paradas_no_activas;
    }
    // Calcular valor de calidad
    int cont_paradas = cont_paradas_total - cont_paradas_no_activas_total;
    double valor = 0.7 * cont_paradas + 0.3 * num_lineas;
    return (valor);
}

bool RedMetro::operator==(const RedMetro& otra) {
    double valor_otra = otra.ValorCalidad();
    double valor_this = this->ValorCalidad();

    return (isEqual(valor_this, valor_otra));
}

bool RedMetro::isEqual(double d1, double d2, double epsilon = 0.00000000001) {
    return fabs(d1 - d2) < epsilon;
}

bool RedMetro::operator!=(const RedMetro & otra) {
    return (!(*this == otra));
}

bool RedMetro::operator>(const RedMetro & otra) {
    return (ValorCalidad() > otra.ValorCalidad());
}

int RedMetro::GetNumTotalParadas()const {
    int total = 0;
    for (int i = 1; i <= num_lineas; i++) {
        for (int j = 1; j <= (*this)[i].GetNumParadas(); j++) {
        }
    }
    return total;
}

int RedMetro::MejorConectada() const {
    // Calcular contadores
    int num_total_paradas = GetNumTotalParadas();
    int * lineas_pasan = new int [num_total_paradas];

    for (int p = 0; p < num_total_paradas; p++)
        lineas_pasan[p] = 0;

    for (int l = 0; l < num_lineas; l++) {
        Linea la_linea = lineas[l]; // acceso al array de objetos Linea 
        int paradas_linea = la_linea.GetNumParadas();
        for (int p = 1; p <= paradas_linea; p++) {
            int indice_parada = (la_linea[p]).GetIndice(); // Operator [] sobre Linea 
            lineas_pasan[indice_parada - 1]++;
        }
    }
    // Cálculo del máximo
    int num_paradas_mejor_conectada = lineas_pasan[0];
    int indice_mejor_conectada = 1;
    for (int p = 2; p <= num_total_paradas; p++) {
        if (lineas_pasan[p - 1] > num_paradas_mejor_conectada) {
            num_paradas_mejor_conectada = lineas_pasan[p - 1];
            indice_mejor_conectada = p;
        }
    } // for p
    delete [] lineas_pasan;

    return (indice_mejor_conectada);
}



