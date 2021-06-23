/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   InfoParada.cpp
 * Author: albertollamasgonzalez
 * 
 * Created on 8 de junio de 2020, 9:57
 */

#include "InfoParada.h"

InfoParada::InfoParada() {
    activa = false;
    indice_parada = 0;
}

InfoParada::InfoParada(bool activa, int indice_parada){
    this->activa=activa;
    this->indice_parada=indice_parada;
}

void InfoParada::operator=(InfoParada parada){
    this->activa=parada.activa;
    this->indice_parada=parada.indice_parada;
}

std::istream& InfoParada::operator>>(std::istream& flujo, InfoParada parada) {
    int el_num_parada;
    char esta_activa_sn;
    
    flujo >> el_num_parada >> esta_activa_sn;
    
    bool esta_activa = ((esta_activa_sn == 'S') ? true : false);
    
    InfoParada parada_leida(esta_activa, el_num_parada);
    
    parada = parada_leida;
    
    return (flujo);
}

