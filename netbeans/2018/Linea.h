/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Linea.h
 * Author: albertollamasgonzalez
 *
 * Created on 8 de junio de 2020, 9:57
 */

#ifndef LINEA_H
#define LINEA_H
#include "InfoParada.h"

class Linea {
public:
    Linea(int num_paradas);
    ~Linea();
    Linea(const Linea &linea);
    Linea& operator=(const Linea & linea);
    InfoParada& operator[](int i);
    bool IndiceValido(int i) const;
    inline int GetNumParadas() const {return num_paradas;};
    bool EstaVacia() const {return paradas==0;};
    Linea& operator+=(const InfoParada& parada);
    std::ostream& operator<<(std::ostream & flujo, const Linea & linea);
    std::istream& operator >> (std::istream& flujo,  Linea& linea);
    int GetNumParadasActivas() const;
    
private:
    int num_paradas;
    InfoParada* paradas;
    void LiberaMemoria();
    void ReservaMemoria(int tam);
    void CopiaParadas( const Linea& linea);
};

#endif /* LINEA_H */

