/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Punto3D.h"
#include "Trayectoria.h"
#include "Vuelo.h"
#include <iostream>

using namespace std;

Vuelo::Vuelo()
{
    idVuelo = -1;
    //    RutaOptima();  No es necesario ni ponerlo porque se llama solo al crearlo
    //    RutaReal();
}
//Vuelo::~Vuelo(){      No hay que hacerlo en Vuelo, se ha hecho en Trayectoria
//
//}

//1
Vuelo::Vuelo(int ident, const Trayectoria &RuOpt)
{
    idVuelo = ident;
    RutaOptima = RuOpt;
}

Vuelo &Vuelo::operator+=(const Punto3D &punto)
{
    if (RutaReal.getNumeroPuntos == 0)
        rutaReal += RutaOptima[0]; // o .get(0)
    rutaReal += punto;
    return *this;
}

std::ostream &Vuelo::operator<<(ostream &flujo, const Vuelo &vuelo)
{
    flujo << vuelo.idVuelo << endl;
    flujo << vuelo.RutaOptima << endl;
    flujo << vuelo.RutaReal << endl;

    return flujo;
}

Vuelo::Vuelo(const char *fichero)
{
    std::ifstream entrada;
    std::string cadena;
    entrada.open(fichero);
    idVuelo=-1;
    if (entrada)
    {
        entrada >> cadena;
        if (cadena=="FICHEROVUELO"){
            entrada >> idVuelo;
            entrada >> RutaOptima;
            entrada >> RutaReal;
        }
        flujo.close();
    } else {
        cerr << "\nERROR" << endl;
        exit(1);
    }
}