/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RedCiudades.cpp
 * Author: albertollamasgonzalez
 * 
 * Created on 12 de junio de 2020, 10:45
 */

#include "/Users/albertollamasgonzalez/Desktop/DGIIM/CUATRIMESTRE 2/MP/netbeans/2017/RedCiudades.h"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

RedCiudades::RedCiudades() {
    info = nullptr;
    distancia = nullptr;
    num_ciudades = 0;
}

void RedCiudades::liberarmemoria() {
    if (info != nullptr) {
        for (int i = 0; i < num_ciudades; i++)
            delete [] info[i].nombre;
        delete [] info;
        info = nullptr;
    }

    if (distancia != nullptr) {
        for (int i = 0; i < num_ciudades; i++)
            delete [] distancia[i];
        delete[]distancia;
        distancia = nullptr;
    }
    num_ciudades = 0;
}

RedCiudades::~RedCiudades() {
    liberarmemoria();
}

void RedCiudades::reservarmemoria(int n) {

    if (n > 0) {
        num_ciudades = n;
        info = new InfoCiudad[n];
        for (int i = 0; i < n; i++) {
            info[i].nombre = 0;
            info[i].poblacion = 0;
        }
        distancia = new double *[n];
        for (int i = 0; i < num_ciudades; i++)
            distancia[i] = new double [n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                distancia[i][j] = 0;
            }
        }
    } else {
        num_ciudades = 0;
        distancia = nullptr;
        info = nullptr;
    }
}

RedCiudades::RedCiudades(const RedCiudades& red){
    reservarmemoria(red.num_ciudades);
    copiar(red);
}

void RedCiudades::copiar(const RedCiudades& otro) {
    num_ciudades=otro.num_ciudades;
    for (int i=0; i < num_ciudades; i++){
        info[i].nombre=new char [strlen(otro.info[i].nombre)+1];
        strcpy(info[i].nombre, otro.info[i].nombre);
        info[i].poblacion=otro.info[i].poblacion;       
    }
    for (int i=0; i < num_ciudades; i++){
        for (int j=0; j < num_ciudades; j++){
            distancia[i][j]=otro.distancia[i][j];
        }
    }
}

RedCiudades& RedCiudades::operator =(const RedCiudades& otro){
    if (this!= &otro){
        liberarmemoria();
        reservarmemoria(otro.num_ciudades);
        copiar(otro);
    }
    return *this;
}
std::ostream& RedCiudades::operator <<(std::ostream& flujo, const RedCiudades& red){
    flujo << red.num_ciudades << std::endl;
    for (int i=0; i < red.num_ciudades; i++){
        flujo << i+1 << " " << red.info[i].nombre << " " << red.info[i].poblacion << std::endl;
    }
    for (int i=0; i < red.num_ciudades; i++){
        for (int j=i+1; j < red.num_ciudades; j++){
            if (red.distancia[i][j] > 0){
                flujo << i+1 << " " << j+1 << " " << red.distancia[i][j] << std::endl;
            }
        }
    }
    return flujo;        
}

std::istream& RedCiudades::operator >> (std::istream& flujo, RedCiudades &red){
    int numeroCiudades, indiceCiudad, poblacion, fila, columna, distancia;
    const int MAX_CHAR=100;
    char nombreCiudad[MAX_CHAR];

    red.liberarmemoria();

    flujo >> numeroCiudades;
    red.reservarmemoria(numeroCiudades);

    for (int i=0; i < red.num_ciudades; i++){
        flujo >> indiceCiudad;
        flujo >> nombreCiudad;
        red.info[indiceCiudad-1].nombre= new char [strlen(nombreCiudad)+1];
        strcpy(red.info[indiceCiudad-1], nombreCiudad);
        flujo >> poblacion;
        red.info[indiceCiudad-1].poblacion = poblacion;
    }

    while (flujo){
            flujo >> fila:
            flujo >> columna;
            flujo >> distancia;

            red.distancia[fila-1][columna-1]=red.distancia[columna-1][fila-1]=distancia;
        
    }

    return flujo;
}

RedCiudades::RedCiudades(const char* fichero){
    LeerRedCiudades(fichero);
}

void RedCiudades::LeerRedCiudades(const char* fichero){
    ifstream entrada;
    string cadena;

    entrada.open(fichero);
    if (fichero){
        getline(entrada, cadena);
        if (cadena!="RED"){
            entrada >> (*this);
        }
        entrada.close();

    }
    else {
        cerr << "\nError leyendo fichero" << endl;
        exit(1);
    }
}

void RedCiudades::EscribirRedCiudades(const char *fichero){
    ofstream salida;
    salida.open(fichero);

    if (salida){
        salida << "RED" << endl;
        salida << (*this);
    } else{
        cerr << "\error en la salida";
        exit(1);
    }

    salida.close();

}

int RedCiudades::CiudadMejorConectada(){
    int bestcity=-1;

    int ciudadActual, ciudadMax=-1;

    for (int i=0; i < num_ciudades; i++){
        ciudadActual=0;
        for (int j=0; j < num_ciudades; j++){
            if (distancia[i][j]>0)
                ciudadActual++;
        }
        if (ciudadActual > ciudadMax){
            bestcity=i;
            ciudadMax=ciudadActual;
        }
    }
    return bestcity;
}

int RedCiudades::mejorEscalaEntre(int i, int j){
    int distanciai, distanciaj;
    int distMin=-1, ciudadIntermedia=-1;

    for (int t=0; t < num_ciudades; t++){
        distanciai=distancia[i-1][t];
        distanciaj=distancia[t][j-1];
        if (distanciai>0 && distanciaj > 0){
            if ((distanciai+distanciaj) < distMin){
                distMin=distanciai+distanciaj;
                ciudadIntermedia=t;
            }

        }
    }
    return ciudadIntermedia+1;
}


