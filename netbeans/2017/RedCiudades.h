/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RedCiudades.h
 * Author: albertollamasgonzalez
 *
 * Created on 12 de junio de 2020, 10:45
 */

#ifndef REDCIUDADES_H
#define REDCIUDADES_H


struct InfoCiudad{
    char* nombre;
    int poblacion;
};

class RedCiudades {
public:
    RedCiudades();
    ~RedCiudades();
    RedCiudades(const RedCiudades& red);
    RedCiudades(const char* fichero);
    void LeerRedCiudades(const char* fichero);
    void EscribirRedCiudades(const char *fichero);
    int CiudadMejorConectada() const;
    int mejorEscalaEntre(int i, int j);
    RedCiudades& operator= (const RedCiudades& otro);
    std::ostream& operator<< (std::ostream& flujo, const RedCiudades& red);
    std::istream& operator >> (std::istream& flujo, RedCiudades& red);
    bool EstaVacia() const {return num_ciudades==0;};
    int GetNumCiudades() const {return num_ciudades;};
    double getDistancia(int i, int j) const {return distancia[i-1][j-1];};
    char NombreCiudad(int i) const {return info[i].nombre;};
    int PoblacionCiudad(int i) const {return info[i].poblacion;};
    
    
    
private:
    int num_ciudades; //NUmero de ciudades
    InfoCiudad *info;
    double ** distancia;
    void liberarmemoria();
    void reservarmemoria(int n); //solo n porque la matriz es simetrica
    void copiar (const RedCiudades &otro);
};

#endif /* REDCIUDADES_H */

