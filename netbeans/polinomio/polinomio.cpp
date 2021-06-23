/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "polinomio.h"
#include <iostream>
#include <cassert>
#include <ostream>
using namespace std;

void Polinomio::inicializar() {
    grado = 0;
    coeficientes = new float [maximogrado + 1];
    for (int i = 0; i <= maximogrado; i++)
        coeficientes[i] = 0.0;
}
//Polinomio::Polinomio(){
//    maximogrado=10;
//    inicializar();
////    grado=0;
////    coeficientes = new float [maximogrado +1];
////    
////    for (int i=0; i <= maximogrado; i++)
////        coeficientes[i]=0;        
//}

Polinomio::Polinomio(int maxgrado) {
    assert(maxgrado >= 0);
    maximogrado = maxgrado;
    inicializar();
}

float Polinomio::getCoeficiente(int indice) const {
    float salida = 0.0;
    if (indice >= 0 && indice <= grado)
        salida = coeficientes[indice];
    return salida;
}

int Polinomio::getGrado() const {
    return grado;
}

void Polinomio::setCoeficiente(int i, float c) {

    if (i >= 0) { // Si el índice del coeficiente es válido 
        if (i > maximogrado) { // Si necesitamos más espacio
            float *aux = new float[i + 1]; // Reservamos nueva memoria
            for (int j = 0; j <= grado; ++j) // Copiamos coeficientes a nueva memoria
                aux[j] = coeficientes[j];
            delete[] coeficientes; // Liberamos memoria antigua coeficientes=aux; // Reasignamos puntero de coeficientes for(int j=grado+1;j<=i;++j) //Hacemos 0 el resto de nuevos coeficientes
            coeficientes = aux; // Reasignamos puntero de coeficientes 
            for (int j = grado + 1; j <= i; ++j) //Hacemos 0 el resto de nuevos coeficientes
                coeficientes[j] = 0.0;
            maximogrado = i; // Asignamos el nuevo número máximo grado del polinomio
        }
        coeficientes[i] = c; // Asignamos el nuevo coeficiente
        // actualizamos el grado
        if (c != 0.0 && i > grado)//Si coeficiente!=0 e índice coeficiente>antiguo grado
            grado = i; // lo actualizamos al valor i
        else if (c == 0.0 && i == grado)//Si coeficiente==0.0 e índice coeficiente==grado
            while (coeficientes[grado] == 0.0 && grado > 0)//Actualizamos grado con el grado--; //primer término cuyo coeficiente no sea cero
                grado--;
    }
}

void Polinomio::imprimir() const {
    std::cout << getCoeficiente(getGrado()); // Imprimimos término de grado mayor 
    if (getGrado() > 1)
        std::cout << "x^" << getGrado();
    else if (getGrado() == 1)
        cout << "x";
    for (int i = getGrado() - 1; i >= 0; --i) {
        if (getCoeficiente(i) != 0.0) {
            if (getCoeficiente(i) > 0.0) // imprimir coeficiente positivo
                cout << " + " << getCoeficiente(i);
            else // imprimir coeficiente negativo
                cout << " - " << -getCoeficiente(i);
            if (i > 1)
                cout << "x^" << i;
            else if (i == 1)
                cout << "x";
        }
    }

}
Polinomio::~Polinomio(){
    delete[] coeficientes;
}
Polinomio Polinomio::operator+(const Polinomio &pol1, const Polinomio &pol2) const{
    int gmax=(this-> pol1.getGrado() > pol2.getGrado()) ? (pol1.getGrado()):(pol2.getGrado());
    int gmin=(this-> getGrado() < pol2.getGrado()) ? (this -> getGrado()): (pol2.getGrado());
    
    Polinomio resultado(gmax);
    
    for (int i=0; i <= gmax; ++i){
        resultado.setCoeficiente(i, this->getCoeficiente(i)+pol2.getCoeficiente(i));       
    }
//    for (int i=gmin+1; i<=gmax; ++i)
//        resultado.setCoeficiente(i,(this->getGrado()<pol2.getGrado())?pol2.getCoeficiente(i):this->getCoeficiente(i));
    return resultado;
}






