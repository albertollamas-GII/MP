/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: albertollamasgonzalez
 *
 * Created on 12 de junio de 2020, 10:42
 */

#include <cstdlib>
#include "/Users/albertollamasgonzalez/Desktop/DGIIM/CUATRIMESTRE 2/MP/netbeans/2017/RedCiudades.h"

using namespace std;

/*
 * 
 */
int main(int argc, char* argv[]) {
    RedCiudades red;
    red.LeerRedCiudades(argv[1]);
    int mejorIntermedia=0;
    for (int i=1; i<= red.GetNumCiudades(); i++){
        for (int j=1; j <= red.GetNumCiudades(); j++){
            if (red.getDistancia(i, j)==0 && i!=j){
                mejorIntermedia=red.mejorEscalaEntre(i,j);
                if (mejorIntermedia>=0){
                    cout
                } else{
                    cout
                }
            }
        }
    }
    return 0;
}

