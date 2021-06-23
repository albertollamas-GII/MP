/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: santi
 *
 * Created on 14 de junio de 2020, 16:39
 */

#include <cstdlib>
#include <iostream>
#include <cassert>
#include <cstring>
#include <fstream>

using namespace std;

struct Hora{
    int hh, mm;
    bool operator==(const Hora& otra){
        return (hh == otra.hh && mm == otra.mm);
}
};

class Turista{
private:
    char* nombre;
    char* id;
    int nacionalidad;
    
    void deallocate(){
        if(nombre != nullptr){
            delete[] nombre;
            nombre = nullptr;
        }
        if(id != nullptr){
            delete[] id;
            id = nullptr;
        }        
        nacionalidad = 0;
    }  
    void allocate(int n){
        assert(n>0);
        nombre = new char[n];
        nombre[n] = '\0';
        id = new char[10];
        nacionalidad = 0;
    }   
    void copiar(const Turista& otra){
        allocate(strlen(otra.nombre));
        strcpy(nombre, otra.nombre);
        strcpy(id, otra.id);
        nacionalidad = otra.nacionalidad;
    }    
    
public:
    
    string getNombre()const{return nombre;}
    string getId()const{return id;}  
    int getNacionalidad()const{return nacionalidad;}
    
    Turista& operator=(const Turista& otra){
        deallocate();
        copiar(otra);
        return *this;
    }    
    bool operator!=(const Turista& otra){
        return id != otra.id;
    }
    bool operator==(const Turista& otra){
        return !(*this != otra);
    }
    
    friend istream& operator>>(istream& is, Turista& otra);     
};

istream& operator>>(istream& is, Turista& otra){
    string s;
    getline(is, s);
    if(!is){
        cerr << "Error de lectura";
        exit(1);
    } 
    
    otra.allocate(s.size() + 1);
    strcpy(otra.nombre,s.c_str());

    getline(is, s);
    if(!is){
        cerr << "Error de lectura";
        exit(1);
    }    
    strcpy(otra.id,s.c_str());
    
    int n; 
    is >> n;
    if(!is){
        cerr << "Error de lectura";
        exit(1);
    }       
    otra.nacionalidad = n;
    
    return is;
} 

class GrupoTuristas{
private:
    Turista* turistas;
    int nturistas;
    Hora hora;
    
    void deallocate(){
        if(turistas != nullptr){
            delete[] turistas;
            turistas = nullptr;
        }
        nturistas = 0;
        hora.hh = hora.mm = 0;
    }   
    void allocate(int n){
        assert(n>0);
        turistas = new Turista[n];
        nturistas = n;
        hora.hh = hora.mm = 0;       
    }
    void copiar(const GrupoTuristas& otra){
        allocate(otra.nturistas);
        for(int i=0; i < nturistas; i++)
            turistas[i] = otra.turistas[i];
        hora = otra.hora;
    }    
    void add(const Turista& turista){
        bool iguales = false;
        for(int i=0; i < nturistas && !iguales; i++)
            iguales = turistas[i] == turista;
        
        if(!iguales){
            GrupoTuristas aux = *this;
            deallocate();
            allocate(aux.nturistas+1);
            
            for(int i=0; i < aux.nturistas; i++)
                turistas[i] = aux.turistas[i];
            turistas[aux.nturistas] = turista;
        }
        
    }
public:
    inline Hora getHora()const{return hora;}
    inline int getNTuristas()const{return nturistas;}
    inline Turista getTurista(int i)const{assert(i>0);return turistas[i];}
    
    GrupoTuristas(){
        turistas = nullptr;
        nturistas = 0;
        hora.hh = hora.mm = 0;
    }
    GrupoTuristas(const GrupoTuristas& otra){
        copiar(otra);
    }
    
    GrupoTuristas& operator=(const GrupoTuristas& otra){
        deallocate();
        copiar(otra);
        return *this;
    }
    GrupoTuristas operator+(const GrupoTuristas& otro){
        if(this != &otro){
            GrupoTuristas aux;
            
            for(int i=0; i < nturistas; i++)
                aux.add(turistas[i]);
            for(int i=0; i < otro.nturistas; i++)C 
                aux.add(otro.turistas[i]);
            
            return aux;
        }
        else
            return *this;
    }
    
    friend istream& operator>>(istream& is, GrupoTuristas& otra);      
};

istream& operator>>(istream& is, GrupoTuristas& otra){
    int n;
    is >> n;    
    if(n < 1 || !is){
        cerr << "Error de lectura";
        exit(1);
    }    
    otra.nturistas = n;   
    
    for(int i=0; i < otra.nturistas; i++)
        is >> otra.turistas[i];   
    
    is >> n;    
    if(n < 0 || n > 24 || !is){
        cerr << "Error de lectura";
        exit(1);
    }    
    otra.hora.hh = n;
    
    is >> n;    
    if(n < 0 || n > 59 || !is){
        cerr << "Error de lectura";
        exit(1);
    }  
    otra.hora.mm = n;   
    
    return is;
}

class ReservasGrupos{
private:
    GrupoTuristas* grupos;
    int ngrupos;
    
    void deallocate(){
        if(grupos != nullptr){
            delete[] grupos;
            grupos = nullptr;
        }
        ngrupos = 0;
    }     
    void allocate(int n){
        assert(n>0);
        grupos = new GrupoTuristas[n];
        ngrupos = n;
    } 
    void copiar(const ReservasGrupos& otra){
        allocate(otra.ngrupos);
        for(int i=0; i < ngrupos; i++)
            grupos[i] = otra.grupos[i];
    }
    void add(const GrupoTuristas& grupo){
        ReservasGrupos aux=*this;
        deallocate();
        allocate(aux.ngrupos+1);
        
        for(int i=0; i < aux.ngrupos; i++)
            grupos[i] = aux.grupos[i];
        grupos[aux.ngrupos] = grupo;
        
    }
    
public:
    ReservasGrupos(){
        grupos = nullptr;
        ngrupos = 0;
    }
    ReservasGrupos(const ReservasGrupos& otra){
        copiar(otra);
    }
    ~ReservasGrupos(){
        deallocate();
    }
    
    bool Cargar(string filename){
        ifstream is(filename);
        bool res = false;
        
        if(is){
            string s;
            getline(is, s);
            if(s == "RESERVASGRUPOS-ALHAMBRA"){
                is >> *this;
                res = true;
            }  
        }
        
        return res;
    }    
    bool Salvar(string filename){
        ofstream os(filename);
        bool res = false;
        
        if(os){
            os << "RESERVASGRUPOS-ALHAMBRA" << endl;
            os << *this;
            res = true;
        }  
        
        return res;        
    }
    void EliminarReserva(const Hora& hora){
        int posicion = -1, k = 0;
        
        for(int i=0; i < ngrupos; i++)
            if(grupos[i].getHora() == hora)
                posicion = i;
        
        if(posicion != -1){
            ReservasGrupos aux = *this;
            deallocate();
            
            for(int i=0; i < aux.ngrupos; i++)
                if(i != posicion)
                    add(aux.grupos[i]);
        }
    }
    
    ReservasGrupos& operator=(const ReservasGrupos& otra){
        if(this != &otra){
            deallocate();
            copiar(otra);
        }
        return *this;
    }
    ReservasGrupos operator+(const ReservasGrupos& otra){
        if(this != &otra){
            ReservasGrupos aux;
            
            for(int i=0; i < ngrupos; i++)
                aux.add(grupos[i]);
            
            for(int i=0; i < otra.ngrupos; i++){
                bool coinciden_horas = false;
                for(int j=0; j < aux.ngrupos && !coinciden_horas; j++)
                    coinciden_horas = otra.grupos[i].getHora() == aux.grupos[i].getHora();
                
                if(coinciden_horas)
                    aux.add(grupos[i]+otra.grupos[i]);
                else
                    aux.add(otra.grupos[i]);    
            }
            
            return aux;
        }
        
        else
            return *this;
    }
    
    friend ostream& operator<<(ostream& os, const ReservasGrupos& otra);
    friend istream& operator>>(istream& is, ReservasGrupos& otra);    
};

ostream& operator<<(ostream& os, const ReservasGrupos& otra){
    os << otra.ngrupos << endl;
    
    for(int i=0; i < otra.ngrupos; i++){
        os << otra.grupos[i].getNTuristas() << endl;
        
        for(int j=0; j < otra.grupos[i].getNTuristas(); j++)
            os << otra.grupos[i].getTurista(j).getNombre() << " " << otra.grupos[i].getTurista(j).getId() << " " << otra.grupos[i].getTurista(j).getNacionalidad() << endl;
        
        os << otra.grupos[i].getHora().hh << " " << otra.grupos[i].getHora().mm << endl;
    }
    
    return os;
}
istream& operator>>(istream& is, ReservasGrupos& otra){
    int n;
    is >> n;    
    if(n < 1 || !is){
        cerr << "Error de lectura";
        exit(1);
    }

    otra.deallocate();
    otra.allocate(n);
   
    for(int i=0; i < otra.ngrupos; i++)
        is >> otra.grupos[i];
    
    return is;    
}
/*
 * 
 */
int main(int argc, char** argv) {
    if(argc != 4){
        cerr << "Número de argumentos invalido";
        return 1;
    }
    
    string in1 = argv[1], in2 = argv[2], out = argv[3];
    ReservasGrupos r1, r2, resultado;
    
    if(!r1.Cargar(in1)){
        cerr << "Error cargando el objeto";
        return 1;
    }
    if(!r2.Cargar(in2)){
        cerr << "Error cargando el objeto";
        return 1;
    }      
    resultado = r1 + r2;
    
    Hora hora;
    for(int i=12; i < 14; i++)
        for(int j=0; j < 60; j++){
            hora.hh = i;
            hora.mm = j;
            if(i == 12 || (i == 13 && j < 31))
                resultado.EliminarReserva(hora);
        }
    
    if(!resultado.Salvar(out)){
        cerr << "Error salvando el objeto";
        return 1;
    }          

        
    return 0;
}

