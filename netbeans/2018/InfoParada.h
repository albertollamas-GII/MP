/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   InfoParada.h
 * Author: albertollamasgonzalez
 *
 * Created on 8 de junio de 2020, 9:57
 */

#ifndef INFOPARADA_H
#define INFOPARADA_H

class InfoParada {
public:
    InfoParada();
    InfoParada(bool activa, int indice_parada);
    void operator=(InfoParada parada);
    inline int GetIndice() const {return indice_parada;};
    bool EstaActiva() const {return activa;};
    std::istream& operator >> (std::istream& flujo, InfoParada parada);
private:
    bool activa;
    int indice_parada;

};

#endif /* INFOPARADA_H */

